# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

# Snap.Hutao.Remastered.UnlockerIsland

Genshin Impact (YuanShen.exe 国服 / GenshinImpact.exe 外服) 客户端 hook 项目。主 DLL 通过 MinHook 拦截游戏函数实现功能开关；另有独立的 Dumper 研究 DLL 和 Test 注入工具。

## 工程结构（src/ 下三个工程）

- `Snap.Hutao.Remastered.UnlockerIsland/` — 主功能 DLL（`ConfigurationType = DynamicLibrary`）。游戏功能全部在这里。
- `Dumper/` — 独立的单文件研究 DLL（`Dumper/dllmain.cpp`）。自带 `GameOffsets` 硬编码偏移、`AddLog`/`DumpStack`，日志写到 `E:\GameDumps\*.log` 和控制台。**不读取 HookEnvironment，独立于 IFunction 架构**。用于调试/导出 GameObject 等。
- `Snap.Hutao.Remastered.UnlockerIsland.Test/` — **注入工具 EXE，不是单元测试**。挂起启动游戏（路径硬编码在 `FindGameExecutable()`）→ 创建共享内存 HookEnvironment → 注入 `TargetDllName`（当前是 `Dumper.dll`）→ 恢复游戏。`ConfigureEnvironment()` 设置所有功能开关和 offsets。改 `TargetDllName` 可切换注入哪个 DLL。

## Build

MSBuild 直接可编译（本仓库用 C++20 + Windows SDK + MinHook，MinHook 通过 vcpkg manifest 模式 + `vcpkg-ports/minhook` overlay port 提供）。

```powershell
$vs = & "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe" -version "[17.0,18.0)" -latest -property installationPath
$msbuild = Join-Path $vs "MSBuild\Current\Bin\MSBuild.exe"
# 整个 solution
& $msbuild "src\Snap.Hutao.Remastered.UnlockerIsland.sln" /p:Configuration=Release /p:Platform=x64 /m
# 单个工程（如 Dumper）
& $msbuild "src\Dumper\Dumper.vcxproj" /p:Configuration=Release /p:Platform=x64 /m
```

- 两个 solution 并存：`.slnx`（新版 VS）与 `.sln`（VS2022），用 `scripts/sync-solution-files.ps1` 互相同步；改工程/配置后要跑同步脚本。
- 切平台工具集 v143/v145：`scripts/set-platform-toolset.ps1 -Toolset v143|v145 [-DryRun]`。

## 主 DLL 架构

### 共享内存 ABI（最重要约束）

配置/开关完全通过共享内存传入：`dllmain.cpp` 的 `InitializeHookEnvironment()` 打开文件映射 `L"4F3E8543-40F7-4808-82DC-21E48A6037A7"`，映射为 `HookEnvironment` 结构（`HookEnvironment.h`），内含全部功能 BOOL 开关 + `HookFunctionOffsets Offsets`。

**ABI 约束：`HookEnvironment` / `HookFunctionOffsets` 的布局经共享内存给外部 Provider（本仓库外的宿主程序）。禁止给这两个结构加字段**，否则外部 Provider 端不兼容。若新功能必须由外部开关控制，需同步更新外部 Provider 和 Test 的 `ConfigureEnvironment()`，并谨慎处理。`IslandState` 枚举是 DLL 回写给宿主的启动状态（Started/Error/Stopped）。

### IFunction 架构

`hook/Hooks.cpp` 按功能拆分：每个 `FunctionType` 对应 `function/` 下一个 `IFunction` 子类（`Initialize` / `OnUpdate` / `GetHookFunction` / `IsEnabled` / `SetEnabled` / `GetFunctionType`）。

- `SetupHooks()`：选择偏移来源（`g_pEnv->ProvideOffsets` 为真用运行时提供的 `g_pEnv->Offsets`，否则用硬编码表）→ 创建所有 IFunction 实例 → 逐个 `Initialize()`（解析自身偏移 + `MH_CreateHook`）→ 挂主钩子（SetFov / SetUID / GameUpdate）。
- `MasterHookSetFov`：每帧先 `DispatchUpdate()` 再执行 FOV 覆写，是主分发生。
- `DispatchUpdate()`：`CheckResistInBeyd()` → 2000ms 限频 `CacheResistState()` → 遍历所有启用 IFunction 的 `OnUpdate()`。
- 共享全局变量（`findString`、`findGameObject`、`setActive` 等函数指针 + `originalSetFov` 等 trampoline）**定义在 Hooks.cpp，声明在 `function/HooksShared.h`**。新增 hook 的 trampoline 要在这里声明 + 在 Hooks.cpp 定义。

### 偏移

- 结构定义在 `HookFunctionOffsets.h`。
- 硬编码国服/外服两张偏移表 `g_ChinaOffsets` / `g_OverseaOffsets` 在 `Constants.cpp`。`GetFunctionAddress(offset)`（`utils/MemoryUtils.cpp`）= `g_hModule + offset`，模块名优先 YuanShen.exe 再 GenshinImpact.exe。
- **`Constants.cpp` 里的 pattern 字符串（`*Pattern`）是死代码**：当前没有任何特征码扫描器使用它们，偏移全部是硬编码 RVA。别花时间找扫描逻辑。
- 游戏更新（如 7.0 适配）时只需更新两张偏移表；国服/外服偏移不同。

### 千星奇域 resist 检测

`Cache.cpp`：找到 UID GameObject 的 Text 组件，文本含 `GUID` 判定为"千星奇域"场景 → `CheckResistInBeyd()` 为真，多数功能被禁用；UID 命中 `BeyondWhiteList`（`Constants.cpp`）则豁免并改文字颜色。每帧在 `DispatchUpdate` / `HookGameUpdate` 里查 `g_cachedIsResisted`。

## 新增一个功能（checklist）

1. `HookFunctionOffsets.h` 加偏移字段 + `Constants.cpp` 两张表赋值（或依赖 `ProvideOffsets`）。
2. `function/Xxx.h/.cpp` 实现 `IFunction`：`Initialize()` 里 `GetFunctionAddress(offset)` + `MH_CreateHook`；若需要原始 trampoline，在 `HooksShared.h` 声明、`Hooks.cpp` 定义。
3. `function/FunctionType.h` 加枚举值。
4. `SetupHooks()` 里 `new Xxx()` 注册。
5. 如需外部开关：改 `HookEnvironment.h`（**注意 ABI 约束**，同步外部 Provider + Test）。
6. 新 .h/.cpp 注册进 `.vcxproj` 和 `.vcxproj.filters`，改完跑 solution 同步脚本。

## Debug

- `env.DebugMode = TRUE` 时 DLL 开控制台，打印全部 HookEnvironment 字段 + 完整偏移表（`dllmain.cpp` WorkerThread）。
- `Logger.h` 的 `Log(...)` 全部受 `DebugMode` 门控。
- Dumper 用 `AddLog`（自己的日志系统），与主 DLL 的 `Log` 无关。
