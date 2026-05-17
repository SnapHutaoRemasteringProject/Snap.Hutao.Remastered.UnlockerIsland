# CLAUDE.md — Snap.Hutao.Remastered.UnlockerIsland

## Architecture: IFunction refactoring

Hooks.cpp 已按功能拆分为独立的 IFunction 实现。每个 FunctionType 对应一个类。

### 目录结构

- `function/IFunction.h` — 基类接口（Initialize / OnUpdate / GetHookFunction / IsEnabled / SetEnabled / GetFunctionType）
- `function/FunctionType.h` — 功能枚举
- `function/HooksShared.h` — 所有 IFunction 共享的全局变量声明（函数指针、原始钩子 trampoline、状态标志）
- `function/FovOverride.h/.cpp` — FOV_OVERRIDE
- `function/DisablePlayerPerspective.h/.cpp` — DISABLE_PLAYER_PERSPECTIVE
- `function/DisableFog.h/.cpp` — DISABLE_FOG
- `function/EnableSetFps.h/.cpp` — ENABLE_SET_FPS
- `function/RemoveTeamProgress.h/.cpp` — REMOVE_TEAM_PROGRESS
- `function/HideQuestBanner.h/.cpp` — HIDE_QUEST_BANNER
- `function/DisableCameraMove.h/.cpp` — DISABLE_CAMERA_MOVE
- `function/DisableDamageText.h/.cpp` — DISABLE_DAMAGE_TEXT
- `function/TouchMode.h/.cpp` — TOUCH_MODE
- `function/ResinItem.h/.cpp` — RESIN_ITEM
- `function/DisplayPaimon.h/.cpp` — DISPLAY_PAIMON
- `function/HidePlayerInfo.h/.cpp` — HIDE_PLAYER_INFO
- `function/HideGrass.h/.cpp` — HIDE_GRASS
- `function/GamepadHotSwitchFunc.h/.cpp` — GAMEPAD_HOT_SWITCH
- `function/InLevelClockPageSpeedUp.h/.cpp` — IN_LEVEL_CLOCK_PAGE_SPEED_UP
- `function/CombineHotkey.h/.cpp` — COMBINE_HOTKEY
- `function/WeakMapCheck.h/.cpp` — WEAK_MAP_CHECK

### 核心流程

- `hook/Hooks.cpp` — 主分发入口，保留：移除旧代码后的精简版本
  - `MasterHookSetFov`：SetFov 钩子，每帧调用 `DispatchUpdate()` 后执行 FOV 覆写
  - `DispatchUpdate()`：resist 检查 → MacroDetector 初始化 → 500ms 限频 CacheResistState → 遍历所有注册 IFunction 的 OnUpdate()
  - `HookGameUpdate`：resist 检查 + Task::Tick
  - `HookSetUID`：捕获 UID
  - `SetupHooks()`：创建所有 IFunction 实例 → 调用 Initialize() → 设置主钩子
- 每个 IFunction::Initialize() 负责解析自身偏移 + 创建 MinHook 钩子
- 每个 IFunction::OnUpdate() 处理帧更新逻辑（从 DispatchUpdate 调用）

### 偏移表

- `Constants.h` — 声明 `extern HookFunctionOffsets g_ChinaOffsets / g_OverseaOffsets`
- `Constants.cpp` — 定义两个硬编码偏移表
- 钩子函数通过 `g_pEnv->Offsets`（运行时提供）或上述全局偏移表获取地址

### 工具函数

- `utils/UnityUtils.h/.cpp` — `FindGameObject(const char* name)`：通过路径名查找 Unity GameObject
- `Cache.h/.cpp` — 仅保留 resist 状态缓存（`CacheResistState`、`CheckResistInBeyd`、`g_cachedIsResisted`），移除了所有 GameObject getter

### 关键数据流

- `g_pEnv`（HookEnvironment）通过共享内存传递配置/标志
- 共享全局变量（`findString`、`findGameObject`、`setActive` 等）定义在 Hooks.cpp，声明在 HooksShared.h
- 原始钩子 trampoline（`originalSetFov` 等）作为全局变量供各个 IFunction 使用

### 编译说明

- 所有新增 .h/.cpp 已在 vcxproj 和 vcxproj.filters 中注册
- 依赖：MinHook、Windows SDK、C++20
