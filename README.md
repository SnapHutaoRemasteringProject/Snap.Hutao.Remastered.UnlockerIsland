# Snap.Hutao.Remastered.UnlockIsland

## Visual Studio project files

This repository keeps both solution formats:

- `src/Snap.Hutao.Remastered.UnlockerIsland.slnx` for newer Visual Studio versions.
- `src/Snap.Hutao.Remastered.UnlockerIsland.sln` for Visual Studio 2022.

Use the scripts from the repository root.

### Switch platform toolset

Switch all `.vcxproj` files between VS2022 `v143` and newer `v145`:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\set-platform-toolset.ps1 -Toolset v143
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\set-platform-toolset.ps1 -Toolset v145
```

Preview changes without writing files:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\set-platform-toolset.ps1 -Toolset v143 -DryRun
```

### Sync `.slnx` and `.sln`

Regenerate the VS2022 `.sln` from the `.slnx`:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\sync-solution-files.ps1 -Direction SlnxToSln
```

Regenerate the `.slnx` from the VS2022 `.sln`:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\sync-solution-files.ps1 -Direction SlnToSlnx
```

Dry-run prints the canonical output that would be written:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\sync-solution-files.ps1 -Direction SlnxToSln -DryRun
```

The sync script intentionally accepts only this repository's current `.slnx` subset: `Solution`, `Configurations/Platform`, and C++ `Project` entries with `Path` and `Id`. If Visual Studio writes new elements or attributes, the script fails instead of guessing a lossy conversion.

### Build with VS2022

Build through the `.sln`, not by calling `.vcxproj` directly:

```powershell
$vs = & "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe" -version "[17.0,18.0)" -latest -property installationPath
$msbuild = Join-Path $vs "MSBuild\Current\Bin\MSBuild.exe"
& $msbuild "src\Snap.Hutao.Remastered.UnlockerIsland.sln" /t:Snap_Hutao_Remastered_UnlockerIsland /p:Configuration=Release /p:Platform=x64 /m
```

### vcpkg dependencies

MinHook is restored through vcpkg manifest mode with a local overlay port:

- `vcpkg.json`
- `vcpkg-configuration.json`
- `vcpkg-ports/minhook`

The overlay port tracks upstream `TsudaKageyu/minhook` at `v1.3.4` and replaces the older checked-in `libMinHook.x64.lib` binaries.

### Semiannual MinHook vcpkg overlay update checks

The [MinHook overlay port](vcpkg-ports/minhook) is updated by the
[Check MinHook vcpkg Overlay workflow](.github/workflows/check-minhook-update.yml).
It runs every January 1 and July 1 (UTC) and supports manual runs.

The check compares the version in `vcpkg-ports/minhook/vcpkg.json` against
upstream **stable Git tags**. On a newer tag it updates both the vcpkg port version
and the pinned commit SHA in `portfile.cmake`, then proposes a PR for review.
The workflow does **not** automatically merge dependency updates.

This uses a dedicated check because Dependabot's vcpkg support updates
`builtin-baseline` for registry ports, not pinned Git commits in local overlay
portfiles. GitHub Actions must be allowed to create pull requests in the
repository settings for automatic PR creation to work.
