param(
    [ValidateSet("SlnxToSln", "SlnToSlnx")]
    [string]$Direction = "SlnxToSln",

    [string]$SlnxPath,

    [string]$SlnPath,

    [switch]$DryRun
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# This script intentionally supports only the repository's current SLNX subset:
# Solution -> Configurations/Platform + self-closing C++ Project Path/Id nodes.
# Microsoft documents the broader serializer and XSD in vs-solutionpersistence,
# but unsupported SLNX elements are rejected here to avoid lossy future-format parsing.

$scriptRoot = if (-not [string]::IsNullOrWhiteSpace($PSScriptRoot)) {
    $PSScriptRoot
}
else {
    Split-Path -Parent $PSCommandPath
}

if ([string]::IsNullOrWhiteSpace($SlnxPath)) {
    $SlnxPath = Join-Path $scriptRoot "..\src\Snap.Hutao.Remastered.UnlockerIsland.slnx"
}

if ([string]::IsNullOrWhiteSpace($SlnPath)) {
    $SlnPath = Join-Path $scriptRoot "..\src\Snap.Hutao.Remastered.UnlockerIsland.sln"
}

$cppProjectTypeGuid = "8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942"
$visualStudioVersion = "17.12.35521.163"
$minimumVisualStudioVersion = "10.0.40219.1"
$buildTypes = @("Debug", "Release")
$slnPlatforms = @("x64", "x86")
$projectPlatformBySlnPlatform = @{
    x64 = "x64"
    x86 = "Win32"
}

function Resolve-InputPath([string]$path) {
    if ([System.IO.Path]::IsPathRooted($path)) {
        return [System.IO.Path]::GetFullPath($path)
    }

    return [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $path))
}

function Assert-NoNamespace([xml]$xml, [string]$path) {
    if (-not [string]::IsNullOrEmpty($xml.DocumentElement.NamespaceURI)) {
        throw "$path uses XML namespaces; this script only accepts the current namespace-free SLNX subset."
    }
}

function Assert-Attributes($node, [string[]]$allowed, [string]$where) {
    foreach ($attribute in $node.Attributes) {
        if ($allowed -notcontains $attribute.Name) {
            throw "$where contains unsupported attribute '$($attribute.Name)'. Refusing to guess future SLNX format changes."
        }
    }
}

function Assert-NoChildElements($node, [string]$where) {
    foreach ($child in $node.ChildNodes) {
        if ($child.NodeType -eq [System.Xml.XmlNodeType]::Element) {
            throw "$where contains unsupported child element '$($child.Name)'."
        }
    }
}

function Normalize-Guid([string]$value, [string]$where) {
    try {
        return ([System.Guid]::Parse($value)).ToString("D")
    }
    catch {
        throw "$where has invalid GUID '$value'."
    }
}

function Get-ProjectName([string]$projectPath) {
    return [System.IO.Path]::GetFileNameWithoutExtension($projectPath.Replace('/', [System.IO.Path]::DirectorySeparatorChar))
}

function Convert-SlnxPathToSlnPath([string]$projectPath) {
    if ([System.IO.Path]::IsPathRooted($projectPath) -or $projectPath -match '^[a-zA-Z][a-zA-Z0-9+.-]*:') {
        throw "Project path '$projectPath' is not a relative repository path."
    }

    if ($projectPath.Contains('\')) {
        throw "Project path '$projectPath' uses backslashes. This script requires SLNX forward slashes."
    }

    if ($projectPath -match '(^|/)\.\.(/|$)') {
        throw "Project path '$projectPath' climbs out of the solution directory."
    }

    return $projectPath.Replace('/', '\')
}

function Convert-SlnPathToSlnxPath([string]$projectPath) {
    if ([System.IO.Path]::IsPathRooted($projectPath) -or $projectPath -match '^[a-zA-Z][a-zA-Z0-9+.-]*:') {
        throw "Project path '$projectPath' is not a relative repository path."
    }

    if ($projectPath.Contains('/')) {
        throw "Project path '$projectPath' uses forward slashes. This script requires SLN backslashes."
    }

    if ($projectPath -match '(^|\\)\.\.(\\|$)') {
        throw "Project path '$projectPath' climbs out of the solution directory."
    }

    return $projectPath.Replace('\', '/')
}

function Read-StrictSlnx([string]$path) {
    $xml = [xml]::new()
    $xml.PreserveWhitespace = $true
    $xml.Load($path)

    Assert-NoNamespace $xml $path
    if ($xml.DocumentElement.LocalName -ne "Solution") {
        throw "$path root element must be Solution."
    }

    Assert-Attributes $xml.DocumentElement @("Description", "Version") "Solution"
    foreach ($child in $xml.DocumentElement.ChildNodes) {
        if ($child.NodeType -ne [System.Xml.XmlNodeType]::Element) {
            continue
        }

        if ($child.LocalName -notin @("Configurations", "Project")) {
            throw "Solution contains unsupported element '$($child.LocalName)'. This script only accepts Configurations and Project."
        }
    }

    $configurationNodes = @($xml.DocumentElement.ChildNodes | Where-Object { $_.NodeType -eq [System.Xml.XmlNodeType]::Element -and $_.LocalName -eq "Configurations" })
    if ($configurationNodes.Count -ne 1) {
        throw "Solution must contain exactly one Configurations element."
    }

    $platforms = New-Object System.Collections.Generic.List[string]
    Assert-Attributes $configurationNodes[0] @() "Configurations"
    foreach ($configurationChild in $configurationNodes[0].ChildNodes) {
        if ($configurationChild.NodeType -ne [System.Xml.XmlNodeType]::Element) {
            continue
        }

        if ($configurationChild.LocalName -ne "Platform") {
            throw "Configurations contains unsupported element '$($configurationChild.LocalName)'."
        }

        Assert-Attributes $configurationChild @("Name") "Configurations/Platform"
        Assert-NoChildElements $configurationChild "Configurations/Platform"
        $name = $configurationChild.GetAttribute("Name")
        if ([string]::IsNullOrWhiteSpace($name)) {
            throw "Configurations/Platform requires non-empty Name."
        }

        $platforms.Add($name)
    }

    if (@($platforms).Count -ne 2 -or ($platforms -contains "x64") -eq $false -or ($platforms -contains "x86") -eq $false) {
        throw "This repository expects exactly SLNX platforms x64 and x86."
    }

    $projects = New-Object System.Collections.Generic.List[object]
    foreach ($project in @($xml.DocumentElement.ChildNodes | Where-Object { $_.NodeType -eq [System.Xml.XmlNodeType]::Element -and $_.LocalName -eq "Project" })) {
        Assert-Attributes $project @("Path", "Id") "Project"
        Assert-NoChildElements $project "Project"

        $pathValue = $project.GetAttribute("Path")
        $idValue = $project.GetAttribute("Id")
        if ([string]::IsNullOrWhiteSpace($pathValue)) {
            throw "Project requires non-empty Path."
        }

        if ([string]::IsNullOrWhiteSpace($idValue)) {
            throw "Project '$pathValue' requires Id. This is the repository's VS2026 SLNX subset."
        }

        if (-not $pathValue.EndsWith(".vcxproj", [System.StringComparison]::OrdinalIgnoreCase)) {
            throw "Project '$pathValue' is not a .vcxproj; this script only handles C++ projects."
        }

        $projects.Add([pscustomobject]@{
            Name = Get-ProjectName $pathValue
            SlnxPath = $pathValue
            SlnPath = Convert-SlnxPathToSlnPath $pathValue
            Id = Normalize-Guid $idValue "Project '$pathValue'"
        })
    }

    if ($projects.Count -eq 0) {
        throw "SLNX contains no projects."
    }

    return [pscustomobject]@{
        Platforms = @($platforms.ToArray())
        Projects = @($projects.ToArray())
    }
}

function Read-StrictSln([string]$path) {
    $lines = [System.IO.File]::ReadAllLines($path)
    if ($lines.Count -lt 12) {
        throw "$path is too short to be a supported Visual Studio solution."
    }

    $index = 0
    if ($lines[$index] -eq "") {
        $index++
    }

    if ($lines[$index++] -ne "Microsoft Visual Studio Solution File, Format Version 12.00") {
        throw "$path has unsupported solution format header."
    }

    if ($lines[$index++] -ne "# Visual Studio Version 17") {
        throw "$path must be a Visual Studio Version 17 solution."
    }

    if ($lines[$index++] -ne "VisualStudioVersion = $visualStudioVersion") {
        throw "$path has unexpected VisualStudioVersion."
    }

    if ($lines[$index++] -ne "MinimumVisualStudioVersion = $minimumVisualStudioVersion") {
        throw "$path has unexpected MinimumVisualStudioVersion."
    }

    $projects = New-Object System.Collections.Generic.List[object]
    while ($index -lt $lines.Count -and $lines[$index].StartsWith("Project(")) {
        $line = $lines[$index++]
        $match = [regex]::Match($line, '^Project\("\{(?<type>[0-9A-Fa-f-]+)\}"\) = "(?<name>[^"]+)", "(?<path>[^"]+)", "\{(?<id>[0-9A-Fa-f-]+)\}"$')
        if (-not $match.Success) {
            throw "Unsupported Project line: $line"
        }

        if ($match.Groups["type"].Value.ToUpperInvariant() -ne $cppProjectTypeGuid) {
            throw "Project '$($match.Groups["name"].Value)' has unsupported project type '$($match.Groups["type"].Value)'."
        }

        if ($index -ge $lines.Count -or $lines[$index++] -ne "EndProject") {
            throw "Project '$($match.Groups["name"].Value)' contains unsupported sections."
        }

        $projectPath = $match.Groups["path"].Value
        $projects.Add([pscustomobject]@{
            Name = $match.Groups["name"].Value
            SlnPath = $projectPath
            SlnxPath = Convert-SlnPathToSlnxPath $projectPath
            Id = Normalize-Guid $match.Groups["id"].Value "Project '$projectPath'"
        })
    }

    if ($projects.Count -eq 0) {
        throw "SLN contains no projects."
    }

    if ($index -ge $lines.Count -or $lines[$index++] -ne "Global") {
        throw "Expected Global section after projects."
    }

    $expectedGlobal = Build-SlnGlobalLines $projects
    $actualGlobal = @($lines[$index..($lines.Count - 1)])
    $expectedWithoutProjects = @($expectedGlobal[0..($expectedGlobal.Count - 1)])
    if (($actualGlobal -join "`n") -ne ($expectedWithoutProjects -join "`n")) {
        throw "$path has unsupported Global sections or project configuration mappings. Refusing lossy conversion."
    }

    return [pscustomobject]@{
        Platforms = @("x64", "x86")
        Projects = @($projects.ToArray())
    }
}

function Build-SlnGlobalLines($projects) {
    $lines = New-Object System.Collections.Generic.List[string]
    $lines.Add("`tGlobalSection(SolutionConfigurationPlatforms) = preSolution")
    foreach ($configuration in $buildTypes) {
        foreach ($platform in $slnPlatforms) {
            $lines.Add("`t`t$configuration|$platform = $configuration|$platform")
        }
    }
    $lines.Add("`tEndGlobalSection")
    $lines.Add("`tGlobalSection(ProjectConfigurationPlatforms) = postSolution")
    foreach ($project in $projects) {
        $guid = $project.Id.ToUpperInvariant()
        foreach ($configuration in $buildTypes) {
            foreach ($platform in $slnPlatforms) {
                $projectPlatform = $projectPlatformBySlnPlatform[$platform]
                $lines.Add("`t`t{$guid}.$configuration|$platform.ActiveCfg = $configuration|$projectPlatform")
                $lines.Add("`t`t{$guid}.$configuration|$platform.Build.0 = $configuration|$projectPlatform")
            }
        }
    }
    $lines.Add("`tEndGlobalSection")
    $lines.Add("`tGlobalSection(SolutionProperties) = preSolution")
    $lines.Add("`t`tHideSolutionNode = FALSE")
    $lines.Add("`tEndGlobalSection")
    $lines.Add("EndGlobal")
    return @($lines)
}

function Build-SlnText($model) {
    $lines = New-Object System.Collections.Generic.List[string]
    $lines.Add("")
    $lines.Add("Microsoft Visual Studio Solution File, Format Version 12.00")
    $lines.Add("# Visual Studio Version 17")
    $lines.Add("VisualStudioVersion = $visualStudioVersion")
    $lines.Add("MinimumVisualStudioVersion = $minimumVisualStudioVersion")
    foreach ($project in $model.Projects) {
        $guid = $project.Id.ToUpperInvariant()
        $lines.Add("Project(`"{${cppProjectTypeGuid}}`") = `"$($project.Name)`", `"$($project.SlnPath)`", `"{$guid}`"")
        $lines.Add("EndProject")
    }
    $lines.Add("Global")
    foreach ($line in (Build-SlnGlobalLines $model.Projects)) {
        $lines.Add($line)
    }
    return ($lines -join "`r`n") + "`r`n"
}

function Build-SlnxText($model) {
    $lines = New-Object System.Collections.Generic.List[string]
    $lines.Add("<Solution>")
    $lines.Add("  <Configurations>")
    foreach ($platform in @("x64", "x86")) {
        $lines.Add("    <Platform Name=`"$platform`" />")
    }
    $lines.Add("  </Configurations>")
    foreach ($project in $model.Projects) {
        $lines.Add("  <Project Path=`"$($project.SlnxPath)`" Id=`"$($project.Id)`" />")
    }
    $lines.Add("</Solution>")
    return ($lines -join "`r`n") + "`r`n"
}

function Write-IfChanged([string]$path, [string]$content, [switch]$DryRun) {
    $oldContent = if (Test-Path -LiteralPath $path) {
        [System.IO.File]::ReadAllText($path)
    }
    else {
        $null
    }

    if ($DryRun) {
        if ($oldContent -eq $content) {
            Write-Host "[dry-run] unchanged: $path"
        }
        else {
            Write-Host "[dry-run] would update: $path"
        }

        Write-Host "[dry-run] canonical output begin"
        [Console]::Out.Write($content)
        Write-Host "[dry-run] canonical output end"
        return
    }

    if ($oldContent -eq $content) {
        Write-Host "[sync] unchanged: $path"
        return
    }

    [System.IO.File]::WriteAllText($path, $content, [System.Text.UTF8Encoding]::new($false))
    Write-Host "[sync] updated: $path"
}

$resolvedSlnxPath = Resolve-InputPath $SlnxPath
$resolvedSlnPath = Resolve-InputPath $SlnPath

if ($Direction -eq "SlnxToSln") {
    $model = Read-StrictSlnx $resolvedSlnxPath
    $content = Build-SlnText $model
    Write-IfChanged $resolvedSlnPath $content -DryRun:$DryRun
}
else {
    $model = Read-StrictSln $resolvedSlnPath
    $content = Build-SlnxText $model
    Write-IfChanged $resolvedSlnxPath $content -DryRun:$DryRun
}
