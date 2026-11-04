"""Check Constants.cpp signatures against a PE64 file without launching the game.

python scripts/audit-signatures.py path/to/YuanShen.exe --allow-multiple GetNamePattern
Add --output report.json to retain the binary hash, matches and derived offsets.
Byte matches establish location/uniqueness; function identity still needs review.
"""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path


class Image:
    def __init__(self, path):
        self.data = path.read_bytes()
        if self.data[:2] != b'MZ':
            raise ValueError('Input is not a PE file')
        pe = struct.unpack_from('<I', self.data, 0x3C)[0]
        if self.data[pe:pe + 4] != b'PE\0\0':
            raise ValueError('Invalid PE signature')
        machine, count = struct.unpack_from('<HH', self.data, pe + 4)
        optional_size = struct.unpack_from('<H', self.data, pe + 20)[0]
        magic = struct.unpack_from('<H', self.data, pe + 24)[0]
        if machine != 0x8664 or magic != 0x20B:
            raise ValueError('Expected an x64 PE32+ image')
        self.imagebase = struct.unpack_from('<Q', self.data, pe + 48)[0]
        self.sections = []
        for index in range(count):
            off = pe + 24 + optional_size + index * 40
            name, virtual_size, rva, size, raw = struct.unpack_from('<8sIIII', self.data, off)
            flags = struct.unpack_from('<I', self.data, off + 36)[0]
            if raw + size > len(self.data):
                raise ValueError('Section exceeds input file')
            self.sections.append(dict(name=name.rstrip(b'\0').decode('ascii'),
                                      rva=rva, size=min(size, virtual_size), raw=raw,
                                      readable=bool(flags & 0x60000000),
                                      executable=bool(flags & 0x20000000)))

    def read(self, rva, size):
        for section in self.sections:
            offset = rva - section['rva']
            if 0 <= offset and offset + size <= section['size']:
                raw = section['raw'] + offset
                return self.data[raw:raw + size]
        raise ValueError(f'Unmapped RVA {rva:#x} (size {size})')

    def scan(self, pattern):
        parts = []
        for token in pattern.split():
            if token in ('?', '??'):
                parts.append(b'.')
            elif re.fullmatch('[0-9a-fA-F]{2}', token):
                parts.append(b'\\x%02x' % int(token, 16))
            else:
                raise ValueError(f'Invalid pattern token: {token}')
        if not parts:
            raise ValueError('Empty pattern')
        rx = re.compile(b''.join(parts), re.S)
        matches = []
        for section in self.sections:
            if section['readable']:
                block = self.data[section['raw']:section['raw'] + section['size']]
                matches.extend(dict(rva=section['rva'] + match.start(), section=section['name'])
                               for match in rx.finditer(block))
        return matches


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('binary', type=Path)
    parser.add_argument('--constants', type=Path,
                        default=Path(__file__).resolve().parents[1] /
                        'src/Snap.Hutao.Remastered.UnlockerIsland/Constants.cpp')
    parser.add_argument('--allow-multiple', nargs='*', default=[])
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    image = Image(args.binary)
    source = args.constants.read_text(encoding='utf-8-sig')
    patterns = dict(re.findall(r'^std::string\s+(\w+Pattern)\s*=\s*"([^"]+)";', source, re.M))
    if not patterns:
        parser.error('No signatures found in Constants.cpp')
    unknown = set(args.allow_multiple) - patterns.keys()
    if unknown:
        parser.error(f'Unknown --allow-multiple names: {sorted(unknown)}')
    rows = []
    failed = False
    for name, pattern in patterns.items():
        matches = image.scan(pattern)
        allowed = len(matches) > 1 and name in args.allow_multiple
        status = 'unique' if len(matches) == 1 else ('multiple-allowed' if allowed else 'FAILED')
        row = dict(name=name, pattern=pattern, status=status, count=len(matches), matches=matches)
        failed |= status == 'FAILED'
        rows.append(row)
        print(f'{status:16} {name:46} {len(matches):3} ' +
              ', '.join(f"0x{m['rva']:X}@{m['section']}" for m in matches[:8]))

    by_name = {row['name']: row for row in rows}
    derived = {}

    def unique(name):
        matches = by_name[name]['matches']
        if len(matches) != 1:
            raise ValueError(f'{name} is not unique')
        return matches[0]['rva']

    try:
        # An earlier OpenTeam signature uniquely matched an unrelated timed
        # action. Require the actual entry -> progress setup -> CheckCanEnter
        # relationship as well as uniqueness. All addresses come from scanning.
        team = unique('OpenTeamPattern')
        body = image.read(team, 0x100)
        marker = b'\x48\x89\xC1\x48\x83\xC4\x28\xE9'
        tail = body.find(marker)
        if tail < 0:
            raise ValueError('OpenTeam lacks the page-instance tail call to progress setup')
        jump = team + tail + len(marker) - 1
        progress = jump + 5 + struct.unpack('<i', image.read(jump + 1, 4))[0]
        progress_body = image.read(progress, 0x200)
        check_enter = unique('CheckCanEnterPattern')
        calls = [progress + offset + 5 + struct.unpack_from('<i', progress_body, offset + 1)[0]
                 for offset in range(len(progress_body) - 4) if progress_body[offset] == 0xE8]
        if check_enter not in calls:
            raise ValueError('OpenTeam progress setup does not call the scanned CheckCanEnter')
        derived['OpenTeam'] = team
        derived['OpenTeamProgressEntry'] = progress
        derived['OpenTeamChecksCanEnter'] = True
        comparison = unique('FastSkipTalkPattern')
        if image.read(comparison, 3) != b'\x0F\x2E\x87' or image.read(comparison + 7, 2) != b'\x0F\x86':
            raise ValueError('FastSkipTalk does not identify UCOMISS + six-byte JBE')
        derived['FastSkipTalk'] = comparison + 7
        derived['FastSkipTalkOriginalBytes'] = image.read(comparison + 7, 6).hex(' ')
        caller = unique('ClosePageCallerPattern')
        if image.read(caller + 0x27, 3) != b'\x41\xFF\x90':
            raise ValueError('ClosePage field no longer follows CALL [R8+disp32]')
        derived['ClosePage'] = struct.unpack('<I', image.read(caller + 0x2A, 4))[0]
        call = unique('SetupResinListPattern')
        if image.read(call, 1) != b'\xE8':
            raise ValueError('SetupResinList pattern does not start with CALL')
        target = call + 5 + struct.unpack('<i', image.read(call + 1, 4))[0]
        if image.read(target + 0x24, 3) != b'\x48\x8B\x8B' or image.read(target + 0x2B, 3) != b'\x48\x85\xC9':
            raise ValueError('ResinList field instruction changed')
        derived['SetupResinList'] = target
        derived['ResinList'] = struct.unpack('<I', image.read(target + 0x27, 4))[0]
        if not derived['ResinList']:
            raise ValueError('ResinList field offset is zero')
    except (KeyError, ValueError) as error:
        derived['error'] = str(error)
        failed = True
    for name, value in derived.items():
        print(f'{name}: {hex(value) if isinstance(value, int) else value}')
    report = dict(binary=str(args.binary.resolve()),
                  sha256=hashlib.sha256(image.data).hexdigest(),
                  imagebase=image.imagebase, signatures=rows, derived=derived, ok=not failed)
    if args.output:
        args.output.write_text(json.dumps(report, indent=2), encoding='utf-8')
    return int(failed)


if __name__ == '__main__':
    raise SystemExit(main())
