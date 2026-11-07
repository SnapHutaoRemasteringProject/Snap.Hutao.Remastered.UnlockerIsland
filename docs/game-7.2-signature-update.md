# 7.2 特征码适配记录

> 适用版本：**国服** `YuanShen.exe` 7.2（`D:\Genshin Impact Game\YuanShen.exe`）
> 与**国际服** `GenshinImpact.exe` 7.2（`D:\OS Genshin\GenshinImpact.exe`），2026-11-07。
> 7.2 的 AOT 代码整体重编译过一次：类型名全换（`BJLLHHFDAEM→BNHCLKOHEFI` 等）、
> 字段偏移与栈帧大小全变，但**函数形状（参数/返回值）没变**，所以 `IFunction` 层不用动。

## 1. 结论

`Constants.cpp` 里 41 条特征码在两个客户端上都能命中正确的函数
（4 条是"多处命中、取最低地址"，与 7.1 行为一致）。其中 9 条因为 7.2 有实质变化而重写：

| 常量 | 7.1 | 7.2 | 改动原因 |
|---|---|---|---|
| `SetupQuestBannerPattern` | `0x11D456C0` | `0x0F039540` | `movaps [rsp+..],xmmN` 的 ModRM 改成通配，避免国服/国际服寄存器分配差异 |
| `ShowOneDamageTextExPattern` | — | `0x13F4ECD0` | 7.2 的 xmm 保存序列变成 `44 0F 29 .. / 0F 29 ..` 共 10 条，整段按 ModRM 通配 |
| `DisplayEffectPattern` | `0x09A92620` | `0x08D7AE60` | 同上，`0F 29 B4 24` → `0F 29 ?? 24` |
| `CheckCanEnterPattern` | `0x0C8FE360` | `0x08A562C0` | 栈帧 `0x80` 变了；尾部补一条 `mov` 才保持唯一（原版在 7.2 会命中 2 处） |
| `OpenTeamPattern` | `0x08F45C70` | `0x10A89B00` | 分支从 `74 ??` 变成 `0F 84 rel32` |
| `CatherineEntryPattern` | `0x0E43A810` | `0x0B930600` | 字段偏移（`0x9D50`→…）、跳转距离全变 |
| `CatherineOpenDialogPattern` | `0x117BBF80` | `0x101AAC80` | 实例字段 `0x164`→`0x188` |
| `CatherineDialogCtorPattern` | `0x117C1480` | `0x101B0C60` | 单例字段全变 |
| `ExplorationEntryPattern` | `0x0A653DA0` | `0x10EF9190` | 立即数（页面 id `7`→…）、栈偏移全变 |

四个凯瑟琳函数的 7.2 类型名：

| 常量 | 7.1 类型 | 7.2 类型 |
|---|---|---|
| `CatherineEntryPattern` | `BJLLHHFDAEM` | `BNHCLKOHEFI` |
| `CatherineOpenDialogPattern` / `CatherineDialogCtorPattern` | `BLMOGIINPEM` | `PBICDDIHDAP` |
| `ExplorationEntryPattern` | `HGPJJCNAHLB`（UIFactory） | `OADFBEEGOFD`（同类，与 `CraftEntryPartnerPattern` 同一类型，可交叉验证） |

`OpenTeamPattern` 的 7.2 目标 `KEBLPHHECCI::GHJKOEGEIAA` 与
`OpenTeamPageAccordinglyPattern` 的 `KEBLPHHECCI::GNBJNKMCFIH` 同属一个类型，
和 7.1 的 `JKKBGKIAFCO` 结构一致 —— 这是确认"抓对了函数"的强证据。

## 2. 校验方法（可复跑）

工具在 `scripts/`（纯离线，不需要 IDA 就能跑）：

```powershell
# 逐条特征码：7.2 命中地址 + 命中到哪个 il2cpp 方法
python scripts\verify_patterns.py

# 同时对比 7.1（需要先按 §3 导出过 7.1 段）
python scripts\verify_patterns.py --with71

# 某地址的签名生成 / 反汇编 / 方法名查询
python scripts\gen_sig.py 0x101AAC80
python scripts\disasm.py 72 0x101AAC80 60
python scripts\lookup.py 72 0x101AAC80
```

- `pe_scan.py` 直接解析 PE（不依赖 IDA），把 RVA 与 DLL 里的
  `GetFunctionAddress()` 对齐；`??`/`?` 都当通配。
- 命中点是否"对"的判据：地址必须是 7.2 `script.json` 里的方法入口，
  且方法签名与 7.1 同名功能一致（例如 `bool(self,int32)` 仍是
  `bool(self,int32)`），`System.Action` 之类的参数形状也一致。

## 3. 重新导出 7.1 段（只有想对比 7.1 时才需要）

7.1 的 exe 已被 7.2 覆盖，只能从 13338 端口那个 IDB 里掏：

```powershell
python scripts\ida_mcp.py 13338 --info
# 然后在 IDA 里执行 scripts\ida_scripts\dump_text71.py / dump_segments71.py
# 产物：D:\dump\CNREL7.1\text71.bin（.text）、seg11.bin（il2cpp 代码段）、il2cpp71.bin
```

跑完 `--with71` 后这些 bin 可以删（约 370 MB）。

## 4. 双服务器（国服 / 国际服）验证

13339 端口是国际服 7.2 的 IDB（`D:\OS Genshin\GenshinImpact.exe`），
用 `scripts\ida_scripts\dump_os72.py` 导出 `D:\dump\OSREL7.2\{text,il2cpp_code}.bin` 后，
`scripts\crossverify.py` 会逐条比对两条服务器的命中点：

```powershell
python scripts\crossverify.py            # 39 条单特征码 + 2 对双服务器特征码
python scripts\crossverify.py --with71   # 附带 7.1 命中情况
```

结果：**41 条全部对齐**。判定方法是把两边命中点各自反汇编 60 条指令，
比 "指令形状"（助记符 + 操作数类型 + 寄存器），两边前缀一致才认为是同一个函数：

- 39 条单特征码：国服/国际服命中同一个函数（多数直接 60/60 全等）；
- `CatherineDialogCtor` / `ExplorationEntry`：**两个客户端的代码生成不同**，
  一条特征码无法同时命中，各补了一条 `...Oversea`：

| 常量 | 国服 7.2 | 国际服 7.2 |
|---|---|---|
| `CatherineDialogCtorPattern` / `...Oversea` | `0x101B0C60` | `0x0B473E90` |
| `ExplorationEntryPattern` / `...Oversea` | `0x10EF9190` | `0x10F081E0` |

  两条互不命中（已验证），`Hooks.cpp::ResolveCatherineOffsetsFromPatterns`
  按 "先本国、再另一条" 的顺序扫，命中即停，所以不依赖 `IsOversea` 标志。

## 5. 已知限制

* 双服务器都验证的是 **7.2**；7.1 已被游戏更新淘汰，不再向后兼容
  （`ShowOneDamageText` / `OpenTeam` / 四条凯瑟琳特征码在 7.1 里不会再命中）。
* `SwitchInputDeviceTo{Touch,Joypad,Keyboard}` 与 `GetName` 在两边各有 2 处命中，
  `Scanner::Scan` 取最低地址，和 7.1 的既有行为一致，未改动。
* 纯字节特征码的固有约束：一旦国服/国际服某条指令的**编码长度**不同，
  后面的字节就整体错位，特征码只能截断在错位点之前
  （`CatherineDialogCtor` 就只剩 77 字节可共用，因此才走双特征码方案）。

## 6. 验收清单

- [x] `python scripts\verify_patterns.py` → 0 条无命中（国服）
- [x] `python scripts\crossverify.py` → 0 problem（国服 + 国际服）
- [x] Release x64 编译通过（`Snap.Hutao.Remastered.UnlockerIsland.dll`）
- [ ] 进游戏实测：每日委托重定向、队伍页、伤害数字、雾/视角/输入切换等
      （需要 `Test.exe` 注入：`TargetDllName` 已指向主 DLL，`DebugMode = TRUE`，
      控制台会打印完整偏移表；确认四个凯瑟琳偏移不再是 0）
