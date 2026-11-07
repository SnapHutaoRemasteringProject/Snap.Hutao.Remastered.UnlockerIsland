# 凯瑟琳重定向 —— 版本适配指南

> 面向"游戏版本更新后怎么把特征码换掉"的操作手册。以 7.1 为已验证基线、7.0 为反面案例。
> 相关代码：`src/Snap.Hutao.Remastered.UnlockerIsland/function/CatherineRedirect.*`、
> `hook/Hooks.cpp::ResolveCatherineOffsetsFromPatterns`、`Constants.cpp` 末尾四条特征码。

---

## 0. 一句话结论

特征码**只跨服务器（国服/国际服）通用，不跨游戏版本**。
换版本（例如 7.2）时按本文流程重新生成 `Constants.cpp` 末尾四条即可，其余代码不用动：

1. 在两个 IDB 里定位四个函数的新 RVA；
2. 跑 `scripts/gen-signatures-from-ida.ps1` 重新生成并自动校验唯一性；
3. 编译 + 看调试输出确认四个偏移不再是 0。

---

## 1. 四个目标函数（7.2 已适配 / 7.1 历史数据）

| 常量 | 目标函数 | 作用 | 7.2 国服 | 7.2 国际服 | 7.1 国服 |
|---|---|---|---|---|---|
| `CatherineEntryPattern` | 7.2 `BNHCLKOHEFI::CEOFJIJACFL` = 7.1 `BJLLHHFDAEM::JEFBGNIMIHF(self)` | **重定向源**：游戏的"每日委托"入口 | `0xB930600` | `0xB96CD50` | `0xE43A810` |
| `CatherineOpenDialogPattern` | 7.2 `PBICDDIHDAP::NHPNFNOFKDE` = 7.1 `BLMOGIINPEM::LNJINJKFFHK(self, idx)` | **开窗逻辑**：唯一创建委托奖励确认弹窗的函数 | `0x101AAC80` | `0x101B5EB0` | `0x117BBF80` |
| `CatherineDialogCtorPattern` (+`...Oversea`) | 7.2 `PBICDDIHDAP::.ctor` = 7.1 `BLMOGIINPEM::.ctor` | 用来抓对话框系统类单例 | `0x101B0C60` | `0x0B473E90` | `0x117C1480` |
| `ExplorationEntryPattern` (+`...Oversea`) | 7.2 `OADFBEEGOFD::CLPNNADPKHP` = 7.1 `HGPJJCNAHLB::BKJHPFINMPE(action, idText)` | 偶数次调用目标（UIFactory 开页面） | `0x10EF9190` | `0x10F081E0` | `0xA653DA0` |

> 7.2 的类型名整体换了：入口 `BJLLHHFDAEM→BNHCLKOHEFI`、对话框系统类 `BLMOGIINPEM→PBICDDIHDAP`、
> UIFactory `HGPJJCNAHLB→OADFBEEGOFD`（与 `CraftEntryPartnerPattern` 落在同一个类里，可交叉验证）。
> 四个函数的**签名（参数形状）不变**，所以挂载逻辑无需改动。
>
> ⚠️ `CatherineDialogCtor` 与 `ExplorationEntry` 这两个函数的国服/国际服**编译结果不一样**
> （静态字段初始化的代码生成不同：国服 `mov rax,[static]; mov rcx,[rax]; mov rax,[rcx+0x30]`，
> 国际服 `mov rax,[rax+0x90]; cmp [rax],0; mfence`），一条字节特征码无法同时命中两边，
> 所以各留了一条 `...Oversea`，运行时两条都扫、命中即停。

### 运行期拓扑

```
游戏点"每日委托"
      │
      ▼
[CatherineEntryPattern]  →  hook 入口函数
      │  计数器 +1
      ├─ 奇数次 → [CatherineOpenDialogPattern] 调 LNJINJKFFHK(system, 0)  → 委托奖励确认弹窗
      └─ 偶数次 → [ExplorationEntryPattern]    调 UIFactory::BKJHPFINMPE     → 探索页
                    失败(实例没就绪 / 抛异常 / 千星奇域受限) → 回落到原始逻辑

[CatherineDialogCtorPattern] 只负责在单例构造时抓住 system 指针（不 hook 入口）
[CatherineOpenDialogPattern] 只用于取地址直接调用，不再下 hook（idx 固定 0）
```

四个偏移都存在 `HookFunctionOffsets`（`CatherineEntry` / `CatherineOpenDialog` /
`CatherineDialogCtor` / `ExplorationEntry`），`ProvideOffsets = TRUE` 时可由外部 Provider 直供，
否则由 `Hooks.cpp` 用特征码扫描补全（只补 0 值字段）。

---

## 2. 为什么换版本必须重新生成

7.0 → 7.1 实测（三个 IDB 交叉验证）：

* 7.1 的四条特征码在 7.0 里**全部 0 命中**；
* 7.0 的对应函数**前 20 字节内编码就变了**（不只是立即数），所以不存在"短一点就能跨版本"的特征码；
* 混淆名跨版本也会换（`JEFBGNIMIHF` 在 7.0 里不存在），只在同版本的不同服务器间一致。

> 顺带一个坑：把特征码截短到 12~16 字节虽然能"命中"，但命中的是**别的函数**
> （7.1 国服/国际服/7.0 都如此），所以绝不能靠截短提高兼容性。

---

## 3. 适配 7.2 的完整流程

### 3.1 准备

1. IDA 分别打开**同一版本**的 `YuanShen.exe.i64` 和 `GenshinImpact.exe.i64`；
2. 两边都装好 `ida-pro-mcp`，记下端口（默认国服 `13338`、国际服 `13337`，脚本参数可改）；
3. 准备好该版本的 `dump.cs`（Il2CppDumper 产物，用来按类型/名字定位）。

### 3.2 定位四个函数的新 RVA

#### (a) 先找上下文类（提供线索，不直接 hook）

dump 里搜 `MonoTakeDailyConfirmDialog`，找到"字段类型是它"的那个类——那就是弹窗的 UI context
（7.1 = `PBCLJOMDMNF`，7.0 = `EKEPEBIHEOJ`，字段偏移两版都是 **0x220**）。

```powershell
Select-String -Path "D:\dump\full dump 7.2.cs" -Pattern "MonoTakeDailyConfirmDialog" -SimpleMatch |
  Select-Object -First 5 | ForEach-Object { "L$($_.LineNumber): $($_.Line.Trim())" }
```

#### (b) `OpenDialog`（`LNJINJKFFHK` 等价函数）

在 dump 里它是**上下文类所属"对话框系统类"的一个 `public Boolean X(System.Int32)`**。

1. 最省事：先用上一版（7.1）的 `CatherineOpenDialogPattern` 在 7.2 IDB 里搜一次，
   大概率 0 命中，但也可能仍命中（若该函数代码没变）；
2. 没命中就用**结构特征**在 IDA 里找（用 `py_eval` 扫 opcode 骨架，见 §5）：
   * 序言 `56 57 48 83 EC ?? 89 D7 48 89 CE`
   * 紧跟两次 `cmp cs:byte_X, 0` + `jcc`
   * `89 BE <disp32>`（把 idx 存进 `this+0x164`-ish）
   * 后面是一串 `mov byte/dword ptr [rdi+imm], imm` 的字段初始化，再 `call <UI 总管 open>`
3. 找到后用 dump 反查该 RVA 属于哪个类 → 该类就是"对话框系统类"（7.1 = `BLMOGIINPEM`）。

#### (c) `Ctor`（系统类构造函数）

就是 (b) 里那个类的 `.ctor`。在 dump 里按类名找：

```powershell
# 7.1: BLMOGIINPEM$$.ctor   7.0: HIHABKBFJPO::.ctor
Select-String -Path "D:\dump\full dump 7.2.cs" -Pattern "public Void \.ctor\(\)" -Context 1,0 |
  Where-Object { $_.Context.PreContext[0] -match "0x" } | Select-Object -First 5
```
或直接在 IDA 里 `lookup_funcs "<类名>$$.ctor"`。

#### (d) `Entry`（重定向源）

dump 里是**无参实例方法** `private Void X()`，函数体形如：

```
object_new(<HHDNOGHMIOC 等价类>) → ctor(ctx, id, 9, 1, 0.0, 0) → UI总管.开页(uiMgr, ctx, 1, 0)
```

7.1 = `0xE43A810`（size `0x230`），7.0 = `0x12BC93F0`（size 同为 `0x230`，size 相同是个好线索）。

#### (e) `Exploration`（UIFactory）

dump 里是**静态方法** `private static Boolean X(System.Action, System.String)`，
所在类就是以前文档里说的 `JKKBGKIAFCO`/UIFactory。7.1 = `0xA653DA0`（size `0x1D0`），7.0 = `0xE644F30`。

### 3.3 生成特征码

```powershell
powershell -ExecutionPolicy Bypass -File scripts\gen-signatures-from-ida.ps1 `
  -EntryCn 0x??????  -EntryOs 0x??????  `
  -OpenCn  0x??????  -OpenOs  0x??????  `
  -CtorCn  0x??????  -CtorOs  0x??????  `
  -ExpCn   0x??????  -ExpOs   0x??????  `
  -UpdateConstants
```

脚本做的事：

1. 从两个 IDB 各取同一函数前 240 字节；
2. **逐字节对比**，不相同的字节写成 `??`（这些就是两服之间的字段偏移 / metadata-usage 偏移 / RIP 位移 / 跳转位移）；
3. 自动截到"两边编码仍对齐"的前缀（遇到指令长度分叉就停，避免把后面的字节全废掉）；
4. 在两个 IDB 里**各做一次全镜像搜索**，要求各命中 1 处，否则红色标出，需要人工截短；
5. 打印可直接粘贴的 `std::string ...Pattern = "...";`，加 `-UpdateConstants` 会直接写回 `Constants.cpp`。

### 3.4 编译 + 验证

```powershell
# Release x64 编译
$vs = & "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe" -latest -property installationPath
& (Join-Path $vs "MSBuild\Current\Bin\MSBuild.exe") `
    "src\Snap.Hutao.Remastered.UnlockerIsland\Snap.Hutao.Remastered.UnlockerIsland.vcxproj" `
    /p:Configuration=Release /p:Platform=x64 /m
```

验收清单：

| 项 | 期望 |
|---|---|
| 调试输出（`DebugMode = TRUE`） | `CatherineEntry` / `CatherineOpenDialog` / `CatherineDialogCtor` / `ExplorationEntry` 四个值 = 新 RVA，不再是 0 |
| 日志 | 没有 `CatherineRedirect: signature miss ...` |
| 游戏内 | 点"每日委托"入口：第 1 次弹委托奖励确认窗；第 2 次走 UIFactory 页面；第 3 次又是确认窗 |

---

## 4. 排错表

| 现象 | 原因 / 处理 |
|---|---|
| `signature miss (entry=0x00000000 ...)` 四个全 0 | 特征码过期（版本变了）→ 按本文重新生成 |
| 只有一个字段是 0 | 只有那条特征码没命中 → 单独重生成那一条；注意 `Ctor` 只有 75 字节，最容易因对齐分叉变短 |
| 命中 2 处以上（脚本标红） | 前缀不够独特 → 加大 `-MaxLength`；若已到对齐上限，说明该函数在本版和别的函数开头雷同，改用**更长的对齐前缀 + 手工补一段唯一 opcode** |
| 命中了但游戏里点入口没反应 | 检查命中的是不是**别的同类函数**：把它和 dump 里的方法签名/所属类对一遍（曾出现过把 `TryParse` 兄弟函数当成目标的情况） |
| 奇数次正常、偶数次崩 | `ExplorationEntry` 命中了 UIFactory 里的兄弟包装函数（同一类里多个 `Boolean(Action,String)`）；确认 RVA 与 dump 一致 |
| 国际服 0 命中、国服正常 | 脚本是否用**同一版本**的国际服 IDB？跨版本 IDB 会差很多 |
| `LNJINJKFFHK` 返回 false | 该函数两条路径都 `return 0`，返回值为 0 是正常现象；"成功"只看有没有抛异常 |

---

## 5. 备用手段：opcode 骨架（跨版本找函数 / 单服生成特征码）

当"上一版特征码"完全失效、又需要快速在 7.2 里定位同一个函数时，可以用 **opcode 骨架**：
把所有**立即数/位移**字段的字节全部通配，只保留 opcode/modrm/sib，这样得到的特征码
**构造上跨服务器、且常常跨版本**（7.1 的 Entry/Exploration 骨架在 7.0 里各命中 1 处）。

在 IDA 的 MCP 里跑（`py_eval`）：

```python
import ida_ua, ida_bytes
ea, maxlen = 0xE43A810, 130      # 换成上一版该函数的 RVA
out, pos, insn = [], 0, ida_ua.insn_t()
while pos < maxlen:
    if not ida_ua.decode_insn(insn, ea + pos):
        break
    wild_from = None
    for op in insn.ops:
        if op.type == 0:
            continue
        if op.type in (ida_ua.o_mem, ida_ua.o_imm, ida_ua.o_displ, ida_ua.o_near, ida_ua.o_far, ida_ua.o_phrase):
            if op.offb > 0 and (wild_from is None or op.offb < wild_from):
                wild_from = op.offb
    b = ida_bytes.get_bytes(ea + pos, insn.size)
    out += ['??' if (wild_from is not None and k >= wild_from) else '%02X' % b[k] for k in range(insn.size)]
    pos += insn.size
print(' '.join(out))
```

拿这个骨架在新版 IDB 里 `ida_search.find_binary` 搜，命中后用 dump 反查函数名/类名确认。
骨架比"两服对拍"宽松，命中后**务必**再在两个 IDB 里各验证一次唯一性。

---

## 6. 附录 A：版本数据存档

| 版本 | Entry | OpenDialog | Ctor | Exploration | 备注 |
|---|---|---|---|---|---|
| 7.1 国服 | `0xE43A810` | `0x117BBF80` | `0x117C1480` | `0xA653DA0` | **当前项目基线（已实测）** |
| 7.1 国际服 | `0xE416490` | `0x1178C430` | `0x11793A00` | `0xA66DB90` | 同上 |
| 7.0 国服 | `0x12BC93F0` | `0x7B57A00` | `0x7B5DF30` | `0xE644F30` | 仅留档，**不**做兼容 |
| 7.1 context 类 | `PBCLJOMDMNF`（ctor `0xD237C10`，字段 `MonoTakeDailyConfirmDialog` @0x220） |||||
| 7.0 context 类 | `EKEPEBIHEOJ`（ctor `0xCA75250`，同字段 @0x220） |||||

## 7. 附录 B：踩坑清单

1. **混淆名只在同版本跨服务器一致**，跨版本会换 → 不要指望用名字搜函数。
2. **短特征码会命中错函数**（12~16 字节在任何版本都能命中别的函数）→ 唯一性必须在完整镜像里验证。
3. **两服指令长度可能不同**（例：国服 `48 8B 51 08` vs 国际服 `48 8B 11`）→ 对拍时只能取"仍对齐的前缀"。
4. **同一类里有多个同签名函数**（`Boolean(Action,String)` 的 TryParse 包装）→ 一定要用 dump 的 RVA 反查确认。
5. **`Ctor` 前缀有多个同类构造函数**（都是 `56 57 53 48 83 EC 20 48 89 CE ...`）→ 7.1 的 75 字节已经是最短可用长度，别再截。
6. `LNJINJKFFHK` 的返回值恒为 0，**不能**当成功判据；代码里用"有没有抛异常"判断。
7. `LNJINJKFFHK` 的 `idx` 固定传 0 即可（原先靠 hook 抓自然调用记录的 idx 逻辑已删除）。
