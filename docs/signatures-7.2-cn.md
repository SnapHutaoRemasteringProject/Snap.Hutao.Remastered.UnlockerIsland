# 7.2 国服特征码核验

本次交付是 `Constants.cpp` 中的字节特征码更新，运行时仍扫描游戏模块。
核验时记录的 RVA 只用于确认目标身份，没有改成硬编码函数地址表。

样本：用户指定的 `YuanShen.exe`，450,927,000 字节。
SHA-256：`8b014f64b5dc12fbc476e0c362b053abfdd7a1378cd282e4ad81057621dbd6b5`。
核验范围为该份 7.2 国服文件；没有验证国际服或游戏内实际运行。

## 特征码修改

完整的新字节串保存在
`src/Snap.Hutao.Remastered.UnlockerIsland/Constants.cpp`，以下列出每项修改的依据。

| 特征码 | 旧规则的问题 | 新规则 |
| --- | --- | --- |
| SwitchInputDeviceToTouchScreenPattern | 两个同构实现，旧规则先命中重复簇 | 初始化守卫的 RIP 位移保留最高字节 `F5`，区分重复簇的 `F8` |
| SwitchInputDeviceToKeyboardPattern | 同上 | 同一组已确认输入函数，使用相同的 `F5` 约束 |
| SwitchInputDeviceToJoypadPattern | 同上 | 同一组已确认输入函数，使用相同的 `F5` 约束 |
| ShowOneDamageTextExPattern | 首轮 `CF` → `CB` 替换误认了向量运算函数，用户实测无效 | 已撤销该替换，恢复原签名；真正粒子伤害显示入口尚未确认，此项未完成适配 |
| CheckCanEnterPattern | 旧规则同时命中另一个无关函数 | 延长函数骨架，保留 `48 8B 81 A0 A3 00 00` 和 `8B 90 84 02 00 00` 等本版字段约束 |
| OpenTeamPattern | 原规则零命中；首轮替换又误认了另一个带进度流程的入口 | 真正队伍入口仍使用 `B9 0C 00 00 00`；匹配本版 `0F 84` 初始化长跳转和 `84 C0 75` 返回分支，并核对进度入口对 CheckCanEnter 的调用 |
| CatherineEntryPattern | 原规则固定了旧 RIP/调用位移及 `9C` 字段范围 | 保留函数骨架，对这些位移完整通配 |
| CatherineOpenDialogPattern | 原来的 `66 C7` 连续两个字节写入已拆开 | 匹配新版两个 `C6 87 ... 01` 写入及后续调用骨架 |
| CatherineDialogCtorPattern | 字段重排使第一项存储从 disp32 编码变为 disp8 | 匹配新版 `48 89 46 ??` 及后续初始化骨架；与同类方法中索引字段读写交叉核对 |
| ExplorationEntryPattern | 原规则残留旧 RIP/调用位移高字节 | 保留参数 `7`、控制流及写入骨架，完整通配位移 |
| FastSkipTalkPattern | 仅识别函数头，不能保证补丁位置仍正确 | 直接匹配冷却比较 `0F 2E 87 ?? ?? ?? ??` 及六字节跳转 `0F 86 ?? ?? ?? ??` 的上下文 |

输入切换的规则有意保留该版本的区分字节，不能称为跨版本通用签名。
特别是 `je rel32` 与 `je rel8` 的编码长度不同，填充 `??` 不能表达可变长度。

### 2026-11-04：队伍进度条补充核验

首轮 OpenTeam 签名虽然唯一命中 `0x8AAD510`，但它属于另一条计时操作链，
并非玩家打开队伍配置时使用的入口。此前将 `0x0C` → `0x10F4` 解释为版本变化不成立。
用户实测表现为开关开启后仍显示进度条，队伍页面可以正常打开。

修正后的签名唯一命中 `0x10A89B00`。它取得页面实例，尾调用 `0x8A575C0`；
后者调用当前 CheckCanEnter（`0x8A562C0`）并创建页面的过渡流程。
页面的后续流程也调用同一 CheckCanEnter，结束后以 false 调用既有的直接开页函数
OpenTeamAdvanced（`0x10A83800`）。因此保留 CheckCanEnter 与 OpenTeamAdvanced 的签名，
只修正 OpenTeam 入口签名。

审计脚本增加“队伍入口 → 进度入口 → 当前 CheckCanEnter”的关系验证，
以便拒绝首轮那个“唯一命中但功能不对”的签名。这些地址只记录核验依据，运行时仍扫描特征码。
修正已完成离线关系验证，游戏内复测仍需使用新编译的 DLL。

## 签名消费者

FastSkipTalk 新签名从比较指令开始，消费者取签名内紧随其后的 JBE（`+7`），
不再从函数头固定加 `0x37E`。原位置在本版落入另一条指令中间。
实际被替换的原始六字节是 `0F 86 A2 00 00 00`。

树脂列表的调用点签名仍唯一命中，但目标函数内部字段操作数发生变化。
字段来自 `48 8B 8B 28 02 00 00`，读取前核验该指令和随后的 `48 85 C9`。
这是对特征码消费者的修正，没有写死函数 RVA。

ClosePage 的虚表位移仍由签名中的 `41 FF 90 disp32` 读取，核验值为 `0x338`。

## 验证

后续更正：以下首轮“全部有命中”的统计不能视为功能身份验证。
ShowOneDamageTextEx 的 CB 候选已被参数及调用关系排除，恢复原规则后仍待适配。
三个输入切换签名也已恢复原写法：仅凭多命中不足以添加 F5 位移约束。
运行时只读检查未检出目标类/方法名称，未取得可确认的新伤害数字签名。

41 条现有签名全部有命中，其中 40 条唯一命中。
`GetNamePattern` 保留两处匹配：两者具有相同的名字读取和字符串转换路径，
差异为日志源代码行号，原扫描规则继续选择较早的一处。
审计工具默认将多命中视为失败，需要显式允许这一项。

```powershell
python scripts/audit-signatures.py 'C:\Program Files\Genshin Impact\Genshin Impact Game\YuanShen.exe' --allow-multiple GetNamePattern --output signatures-7.2-cn.json
```

工具只读取 PE 文件，扫描全部带读取/执行权限的已初始化节，核验队伍调用关系及上述派生值。
字节命中与唯一性不等于游戏内功能验收；本次完成了离线核验和 Release x64 编译。

## dumper 参考项目

`Il2cppRuntimeDumper/rva_finder.py` 的 `F_SIG["il2cpp_object_new"]` 原来写死
`F6 81 C9 00 00 00`。本版对应 `F6 81 CA 00 00 00`，因此按指南把这一结构字段位移
改为 `F6 81 ?? ?? ?? ??`，保留其余函数骨架。
该后备签名在样本 `.text` 中唯一命中。没有据此覆盖 dumper 的旧生成 RVA/key 文件。
