param(
    [Parameter(Mandatory = $true)]
    [ValidateSet("v143", "v145")]
    [string]$Toolset,

    [string]$Root,

    [switch]$DryRun
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

if ([string]::IsNullOrWhiteSpace($Root)) {
    $scriptRoot = if (-not [string]::IsNullOrWhiteSpace($PSScriptRoot)) {
        $PSScriptRoot
    }
    else {
        Split-Path -Parent $PSCommandPath
    }

    $Root = (Resolve-Path (Join-Path $scriptRoot "..")).Path
}
else {
    $Root = (Resolve-Path $Root).Path
}

$projectVersionByToolset = @{
    v143 = "16.0"
    v145 = "18.0"
}

$excludePatterns = @(
    "\\.git\\",
    "\\build\\",
    "\\packages\\",
    "\\vcpkg_installed\\"
)

function Should-ProcessFile([string]$fullPath) {
    foreach ($pattern in $excludePatterns) {
        if ($fullPath -match $pattern) {
            return $false
        }
    }

    return $true
}

function Get-RelativePath([string]$basePath, [string]$targetPath) {
    $baseFullPath = [System.IO.Path]::GetFullPath($basePath)
    if (-not $baseFullPath.EndsWith([System.IO.Path]::DirectorySeparatorChar)) {
        $baseFullPath += [System.IO.Path]::DirectorySeparatorChar
    }

    $targetFullPath = [System.IO.Path]::GetFullPath($targetPath)
    $baseUri = [System.Uri]::new($baseFullPath)
    $targetUri = [System.Uri]::new($targetFullPath)
    $relativeUri = $baseUri.MakeRelativeUri($targetUri)

    return [System.Uri]::UnescapeDataString($relativeUri.ToString()).Replace('/', [System.IO.Path]::DirectorySeparatorChar)
}

$vcxprojFiles = Get-ChildItem -Path $Root -Recurse -Filter *.vcxproj -File |
    Where-Object { Should-ProcessFile $_.FullName }

if (-not $vcxprojFiles) {
    Write-Host "[toolset] no .vcxproj files found under $Root"
    exit 0
}

$targetProjectVersion = $projectVersionByToolset[$Toolset]
$totalFiles = 0
$changedFiles = 0
$changedNodes = 0

foreach ($file in $vcxprojFiles) {
    $totalFiles++
    $content = [System.IO.File]::ReadAllText($file.FullName)
    $fileChangedNodes = 0

    $newContent = [regex]::Replace(
        $content,
        '<VCProjectVersion>\s*([^<\s]+)\s*</VCProjectVersion>',
        {
            param($m)
            $oldVersion = $m.Groups[1].Value
            if ($oldVersion -ne $targetProjectVersion) {
                $script:fileChangedNodes++
            }

            return "<VCProjectVersion>$targetProjectVersion</VCProjectVersion>"
        }
    )

    $newContent = [regex]::Replace(
        $newContent,
        '<PlatformToolset>\s*([^<\s]+)\s*</PlatformToolset>',
        {
            param($m)
            $oldToolset = $m.Groups[1].Value
            if ($oldToolset -ne $Toolset) {
                $script:fileChangedNodes++
            }

            return "<PlatformToolset>$Toolset</PlatformToolset>"
        }
    )

    if ($fileChangedNodes -gt 0) {
        $changedFiles++
        $changedNodes += $fileChangedNodes
        $relative = Get-RelativePath $Root $file.FullName

        if ($DryRun) {
            Write-Host "[dry-run] $relative : $fileChangedNodes node(s) -> $Toolset / VCProjectVersion $targetProjectVersion"
        }
        else {
            [System.IO.File]::WriteAllText($file.FullName, $newContent, [System.Text.UTF8Encoding]::new($false))
            Write-Host "[updated] $relative : $fileChangedNodes node(s) -> $Toolset / VCProjectVersion $targetProjectVersion"
        }
    }
}

if ($DryRun) {
    Write-Host "[summary] scanned=$totalFiles would_change_files=$changedFiles would_change_nodes=$changedNodes target=$Toolset project_version=$targetProjectVersion"
}
else {
    Write-Host "[summary] scanned=$totalFiles changed_files=$changedFiles changed_nodes=$changedNodes target=$Toolset project_version=$targetProjectVersion"
}
