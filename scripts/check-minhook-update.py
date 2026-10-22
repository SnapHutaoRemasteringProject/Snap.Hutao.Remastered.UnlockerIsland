#!/usr/bin/env python3
"""Check upstream MinHook stable tags and update the local vcpkg overlay port."""

from __future__ import annotations

import json
import os
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MANIFEST = ROOT / "vcpkg-ports" / "minhook" / "vcpkg.json"
PORTFILE = ROOT / "vcpkg-ports" / "minhook" / "portfile.cmake"
UPSTREAM = "https://github.com/TsudaKageyu/minhook.git"
TAG_PATTERN = re.compile(r"refs/tags/v(\d+)\.(\d+)\.(\d+)(\^\{\})?")
REF_PATTERN = re.compile(r'(?m)^(\s*REF\s+")([0-9a-fA-F]{40})("\s*)$')


def stable_tags(ls_remote: str) -> dict[tuple[int, int, int], str]:
    """Resolve stable vX.Y.Z tags, preferring peeled commits for annotated tags."""
    versions: dict[tuple[int, int, int], str] = {}
    peeled: set[tuple[int, int, int]] = set()
    for line in ls_remote.splitlines():
        parts = line.split()
        if len(parts) != 2:
            continue
        sha, ref = parts
        match = TAG_PATTERN.fullmatch(ref)
        if not match or not re.fullmatch(r"[0-9a-fA-F]{40}", sha):
            continue
        version = tuple(int(part) for part in match.group(1, 2, 3))
        is_peeled = bool(match.group(4))
        if version not in versions or (is_peeled and version not in peeled):
            versions[version] = sha.lower()
        if is_peeled:
            peeled.add(version)
    return versions


def check_updates() -> None:
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8-sig"))
    if manifest.get("name") != "minhook":
        raise ValueError("Expected the minhook vcpkg overlay manifest")
    current = manifest.get("version", "")
    if not re.fullmatch(r"\d+\.\d+\.\d+", current):
        raise ValueError(f"Unsupported current MinHook version: {current!r}")
    current_version = tuple(int(part) for part in current.split("."))

    portfile = PORTFILE.read_text(encoding="utf-8")
    if len(REF_PATTERN.findall(portfile)) != 1:
        raise ValueError("Expected exactly one pinned 40-digit REF in the MinHook portfile")

    result = subprocess.run(
        ["git", "ls-remote", "--tags", UPSTREAM],
        check=True,
        capture_output=True,
        text=True,
        timeout=120,
    )
    versions = stable_tags(result.stdout)
    if not versions:
        raise RuntimeError("No valid MinHook stable tags found; refusing to modify the port")

    latest_version = max(versions)
    latest = ".".join(map(str, latest_version))
    print(f"MinHook overlay version: {current}; latest stable upstream tag: v{latest}")
    update_available = latest_version > current_version
    if update_available:
        manifest["version"] = latest
        updated_portfile, count = REF_PATTERN.subn(
            lambda match: f"{match.group(1)}{versions[latest_version]}{match.group(3)}",
            portfile,
        )
        if count != 1:
            raise RuntimeError("Could not replace the pinned MinHook Git commit")
        MANIFEST.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
        PORTFILE.write_text(updated_portfile, encoding="utf-8")
        print(f"Prepared MinHook v{latest} update at {versions[latest_version]}")
    else:
        print("MinHook is already at the latest stable release; no changes required")

    output = os.environ.get("GITHUB_OUTPUT")
    if output:
        with open(output, "a", encoding="utf-8") as output_file:
            output_file.write(f"update_available={str(update_available).lower()}\n")
            output_file.write(f"version={latest}\n")


if __name__ == "__main__":
    check_updates()
