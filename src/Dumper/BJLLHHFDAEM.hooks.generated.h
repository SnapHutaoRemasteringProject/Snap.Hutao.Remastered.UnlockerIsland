// ==========================================================================
// 由 tools/jkkbgkiafco_hook_gen.py 自动生成 —— 请勿手改
// BJLLHHFDAEM 全量钩子安装入口：每个方法一个 detour，参数/返回值/ref-out 全部打日志。
// ==========================================================================
#pragma once

#include <cstdint>

// base = 主模块基址（il2cpp code 在 exe 里，RVA 相对主模块）。
//
// 顺序很重要：**先 Register 再 InitHookLog 再 Install**。
//   Register 只登记描述表（方法名 / RVA / 参数表），signatures.txt、filter.txt、
//   stats.txt 都依赖它；InitHookLog 会据此写签名表并读过滤表。
void RegisterBJLLHHFDAEMHooks();

// 按登记表逐个 MH_CreateHook + MH_EnableHook，返回成功条数。
int InstallBJLLHHFDAEMHooks(uint64_t base);
int BJLLHHFDAEMHookCount();
void RemoveBJLLHHFDAEMHooks();
