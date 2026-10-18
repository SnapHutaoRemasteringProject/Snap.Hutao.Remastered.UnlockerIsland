// ==========================================================================
// 由 tools/jkkbgkiafco_hook_gen.py 自动生成 —— 请勿手改
// EKHBADNLJKF：517 个方法的 detour + 描述表 + 安装表。
// ==========================================================================
#include "EKHBADNLJKF.hooks.generated.h"
#include "EKHBADNLJKF.types.generated.h"

namespace jk {
namespace ekhbadnljkf_detail {

using namespace jk;

// ---------------------------------------------------------------- #000
// public Void EBHEAKIGGLJ(UnityEngine.UI.Toggle DHAPJPMGKCM) { }
// RVA 0x0ea64b30
static const ParamDesc kP000[] = {
    { "DHAPJPMGKCM", "Toggle", 0 },
};
static const FnDesc kD000 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(UnityEngine.UI.Toggle DHAPJPMGKCM) { }", "Void", 0x0ea64b30u, 1, 0, kP000
};
using H000 = HookSlot<void(__fastcall*)(void*, void*), 0, true>;

// ---------------------------------------------------------------- #001
// public virtual Void OnJoypadUIModuleDeSelectIndex(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }
// RVA 0x0ea64c20
static const ParamDesc kP001[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "Int32", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "ILLHJJAJOKF", "GCLHPKAEIPN", 0 },
};
static const FnDesc kD001 = {
    "OnJoypadUIModuleDeSelectIndex", "public virtual Void OnJoypadUIModuleDeSelectIndex(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }", "Void", 0x0ea64c20u, 4, 0, kP001
};
using H001 = HookSlot<void(__fastcall*)(void*, void*, int32_t, void*, T_GCLHPKAEIPN), 1, true>;

// ---------------------------------------------------------------- #002
// public Void JPMMIOACMPK(System.Boolean FKJFLKANHNP) { }
// RVA 0x0ea64c80
static const ParamDesc kP002[] = {
    { "FKJFLKANHNP", "Boolean", 0 },
};
static const FnDesc kD002 = {
    "JPMMIOACMPK", "public Void JPMMIOACMPK(System.Boolean FKJFLKANHNP) { }", "Void", 0x0ea64c80u, 1, 0, kP002
};
using H002 = HookSlot<void(__fastcall*)(void*, bool), 2, true>;

// ---------------------------------------------------------------- #003
// public Sprite MDGCLLFHLKN(System.String BHOAHJNPMGN) { }
// RVA 0x0ea64c90
static const ParamDesc kP003[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD003 = {
    "MDGCLLFHLKN", "public Sprite MDGCLLFHLKN(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea64c90u, 1, 1, kP003
};
using H003 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 3, true>;

// ---------------------------------------------------------------- #004
// public Coroutine NJNJDOAFCIP(System.Single POPLJPHBGOB, System.Action FKGGKMAKEPN) { }
// RVA 0x0ea64d50
static const ParamDesc kP004[] = {
    { "POPLJPHBGOB", "Single", 0 },
    { "FKGGKMAKEPN", "Action", 0 },
};
static const FnDesc kD004 = {
    "NJNJDOAFCIP", "public Coroutine NJNJDOAFCIP(System.Single POPLJPHBGOB, System.Action FKGGKMAKEPN) { }", "Coroutine", 0x0ea64d50u, 2, 1, kP004
};
using H004 = HookSlot<void*(__fastcall*)(void*, float, void*), 4, true>;

// ---------------------------------------------------------------- #005
// protected virtual Void NKMIFPGJDEE() { }
// RVA 0x0ea652d0
static const FnDesc kD005 = {
    "NKMIFPGJDEE", "protected virtual Void NKMIFPGJDEE() { }", "Void", 0x0ea652d0u, 0, 0, nullptr
};
using H005 = HookSlot<void(__fastcall*)(void*), 5, true>;

// ---------------------------------------------------------------- #006
// protected Void GAMGBDMLPHG(KHEIDDJMEML LMILCIBLNDB) { }
// RVA 0x0ea654c0
static const ParamDesc kP006[] = {
    { "LMILCIBLNDB", "KHEIDDJMEML", 0 },
};
static const FnDesc kD006 = {
    "GAMGBDMLPHG", "protected Void GAMGBDMLPHG(KHEIDDJMEML LMILCIBLNDB) { }", "Void", 0x0ea654c0u, 1, 0, kP006
};
using H006 = HookSlot<void(__fastcall*)(void*, void*), 6, true>;

// ---------------------------------------------------------------- #007
// public Void CEKPGKHLJGK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea656d0
static const ParamDesc kP007[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD007 = {
    "CEKPGKHLJGK", "public Void CEKPGKHLJGK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea656d0u, 2, 0, kP007
};
using H007 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 7, true>;

// ---------------------------------------------------------------- #008
// public Sprite BGNMKNGADHN(System.String BHOAHJNPMGN) { }
// RVA 0x0ea65770
static const ParamDesc kP008[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD008 = {
    "BGNMKNGADHN", "public Sprite BGNMKNGADHN(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea65770u, 1, 1, kP008
};
using H008 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 8, true>;

// ---------------------------------------------------------------- #009
// public Sprite COOEICPMBLE(System.String BHOAHJNPMGN) { }
// RVA 0x0ea65830
static const ParamDesc kP009[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD009 = {
    "COOEICPMBLE", "public Sprite COOEICPMBLE(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea65830u, 1, 1, kP009
};
using H009 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 9, true>;

// ---------------------------------------------------------------- #010
// private Void LJNNBGJFHFN() { }
// RVA 0x0ea658f0
static const FnDesc kD010 = {
    "LJNNBGJFHFN", "private Void LJNNBGJFHFN() { }", "Void", 0x0ea658f0u, 0, 0, nullptr
};
using H010 = HookSlot<void(__fastcall*)(void*), 10, true>;

// ---------------------------------------------------------------- #011
// public virtual Void ANHJBPALHFF(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }
// RVA 0x0ea659a0
static const ParamDesc kP011[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "GCHAFILKIPB", "LACPHBBPHGE", 0 },
};
static const FnDesc kD011 = {
    "ANHJBPALHFF", "public virtual Void ANHJBPALHFF(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }", "Void", 0x0ea659a0u, 4, 0, kP011
};
using H011 = HookSlot<void(__fastcall*)(void*, void*, const T_AAOHKJCCPDL*, void*, T_LACPHBBPHGE), 11, true>;

// ---------------------------------------------------------------- #012
// public Void DHNDGMEPCID(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea65a10
static const ParamDesc kP012[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD012 = {
    "DHNDGMEPCID", "public Void DHNDGMEPCID(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea65a10u, 2, 0, kP012
};
using H012 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 12, true>;

// ---------------------------------------------------------------- #013
// public AsyncJob LHDMKHKOCED(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea65ab0
static const ParamDesc kP013[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD013 = {
    "LHDMKHKOCED", "public AsyncJob LHDMKHKOCED(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea65ab0u, 2, 3, kP013
};
using H013 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 13, true>;

// ---------------------------------------------------------------- #014
// public AsyncJob EFINOJGCHPI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea65bb0
static const ParamDesc kP014[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD014 = {
    "EFINOJGCHPI", "public AsyncJob EFINOJGCHPI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea65bb0u, 2, 3, kP014
};
using H014 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 14, true>;

// ---------------------------------------------------------------- #015
// public Void EEODNFGFIPA(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }
// RVA 0x0ea65cb0
static const ParamDesc kP015[] = {
    { "LAINJKDPDBF", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD015 = {
    "EEODNFGFIPA", "public Void EEODNFGFIPA(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }", "Void", 0x0ea65cb0u, 1, 0, kP015
};
using H015 = HookSlot<void(__fastcall*)(void*, void*), 15, true>;

// ---------------------------------------------------------------- #016
// public virtual Void OnJoypadUIModuleLostFocus(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }
// RVA 0x0ea65d90
static const ParamDesc kP016[] = {
    { "LAINJKDPDBF", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD016 = {
    "OnJoypadUIModuleLostFocus", "public virtual Void OnJoypadUIModuleLostFocus(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }", "Void", 0x0ea65d90u, 1, 0, kP016
};
using H016 = HookSlot<void(__fastcall*)(void*, void*), 16, true>;

// ---------------------------------------------------------------- #017
// private Void JKBMOFOAFKO() { }
// RVA 0x0ea65de0
static const FnDesc kD017 = {
    "JKBMOFOAFKO", "private Void JKBMOFOAFKO() { }", "Void", 0x0ea65de0u, 0, 0, nullptr
};
using H017 = HookSlot<void(__fastcall*)(void*), 17, true>;

// ---------------------------------------------------------------- #018
// public Void AGIDIKOOBLF(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }
// RVA 0x0ea65e90
static const ParamDesc kP018[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "Int32", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "ILLHJJAJOKF", "GCLHPKAEIPN", 0 },
};
static const FnDesc kD018 = {
    "AGIDIKOOBLF", "public Void AGIDIKOOBLF(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }", "Void", 0x0ea65e90u, 4, 0, kP018
};
using H018 = HookSlot<void(__fastcall*)(void*, void*, int32_t, void*, T_GCLHPKAEIPN), 18, true>;

// ---------------------------------------------------------------- #019
// public Void LMDHPJDPAKO(System.Boolean BOBIFHFAKBG) { }
// RVA 0x0ea65fc0
static const ParamDesc kP019[] = {
    { "BOBIFHFAKBG", "Boolean", 0 },
};
static const FnDesc kD019 = {
    "LMDHPJDPAKO", "public Void LMDHPJDPAKO(System.Boolean BOBIFHFAKBG) { }", "Void", 0x0ea65fc0u, 1, 0, kP019
};
using H019 = HookSlot<void(__fastcall*)(void*, bool), 19, true>;

// ---------------------------------------------------------------- #020
// public Void KLEPHDBGOAC(UnityEngine.GameObject CNDIOPHHOIL) { }
// RVA 0x0ea665c0
static const ParamDesc kP020[] = {
    { "CNDIOPHHOIL", "GameObject", 0 },
};
static const FnDesc kD020 = {
    "KLEPHDBGOAC", "public Void KLEPHDBGOAC(UnityEngine.GameObject CNDIOPHHOIL) { }", "Void", 0x0ea665c0u, 1, 0, kP020
};
using H020 = HookSlot<void(__fastcall*)(void*, void*), 20, true>;

// ---------------------------------------------------------------- #021
// public Boolean ENJIMEALJJH(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA, System.Collections.Generic.List<UnityEngine.GameObject> JFLDNBINFOI) { }
// RVA 0x0ea666e0
static const ParamDesc kP021[] = {
    { "DAONBKOKGEA", "ListNavigatePointerActionConfig", 0 },
    { "JFLDNBINFOI", "List<GameObject>", 0 },
};
static const FnDesc kD021 = {
    "ENJIMEALJJH", "public Boolean ENJIMEALJJH(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA, System.Collections.Generic.List<UnityEngine.GameObject> JFLDNBINFOI) { }", "Boolean", 0x0ea666e0u, 2, 1, kP021
};
using H021 = HookSlot<bool(__fastcall*)(void*, void*, void*), 21, true>;

// ---------------------------------------------------------------- #022
// public virtual Boolean HKECGGEFKMF() { }
// RVA 0x0ea66760
static const FnDesc kD022 = {
    "HKECGGEFKMF", "public virtual Boolean HKECGGEFKMF() { }", "Boolean", 0x0ea66760u, 0, 1, nullptr
};
using H022 = HookSlot<bool(__fastcall*)(void*), 22, true>;

// ---------------------------------------------------------------- #023
// public Void ONGGGOPCFLL(MoleMole.MonoKeyboardUIModule KEDNOJKFEHO) { }
// RVA 0x0ea667c0
static const ParamDesc kP023[] = {
    { "KEDNOJKFEHO", "MonoKeyboardUIModule", 0 },
};
static const FnDesc kD023 = {
    "ONGGGOPCFLL", "public Void ONGGGOPCFLL(MoleMole.MonoKeyboardUIModule KEDNOJKFEHO) { }", "Void", 0x0ea667c0u, 1, 0, kP023
};
using H023 = HookSlot<void(__fastcall*)(void*, void*), 23, true>;

// ---------------------------------------------------------------- #024
// public Void GNPKPFFLKPI(GEGODFHFBIG BOEIJOIFDHH) { }
// RVA 0x0ea669d0
static const ParamDesc kP024[] = {
    { "BOEIJOIFDHH", "GEGODFHFBIG", 0 },
};
static const FnDesc kD024 = {
    "GNPKPFFLKPI", "public Void GNPKPFFLKPI(GEGODFHFBIG BOEIJOIFDHH) { }", "Void", 0x0ea669d0u, 1, 0, kP024
};
using H024 = HookSlot<void(__fastcall*)(void*, T_GEGODFHFBIG), 24, true>;

// ---------------------------------------------------------------- #025
// protected virtual Void PostClose() { }
// RVA 0x0ea66a20
static const FnDesc kD025 = {
    "PostClose", "protected virtual Void PostClose() { }", "Void", 0x0ea66a20u, 0, 0, nullptr
};
using H025 = HookSlot<void(__fastcall*)(void*), 25, true>;

// ---------------------------------------------------------------- #026
// private Void BGMJAMHDPBO() { }
// RVA 0x0ea66b90
static const FnDesc kD026 = {
    "BGMJAMHDPBO", "private Void BGMJAMHDPBO() { }", "Void", 0x0ea66b90u, 0, 0, nullptr
};
using H026 = HookSlot<void(__fastcall*)(void*), 26, true>;

// ---------------------------------------------------------------- #027
// protected virtual Void BindRedPoints() { }
// RVA 0x0ea34370
static const FnDesc kD027 = {
    "BindRedPoints", "protected virtual Void BindRedPoints() { }", "Void", 0x0ea34370u, 0, 0, nullptr
};
using H027 = HookSlot<void(__fastcall*)(void*), 27, true>;

// ---------------------------------------------------------------- #028
// public Void NOOKJPMKGCD(MoleMole.MonoJoypadUIModule KEDNOJKFEHO) { }
// RVA 0x0ea66ce0
static const ParamDesc kP028[] = {
    { "KEDNOJKFEHO", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD028 = {
    "NOOKJPMKGCD", "public Void NOOKJPMKGCD(MoleMole.MonoJoypadUIModule KEDNOJKFEHO) { }", "Void", 0x0ea66ce0u, 1, 0, kP028
};
using H028 = HookSlot<void(__fastcall*)(void*, void*), 28, true>;

// ---------------------------------------------------------------- #029
// public virtual CBEDPEAMKMK PMDDNHGLNEB() { }
// RVA 0x0ea66fb0
static const FnDesc kD029 = {
    "PMDDNHGLNEB", "public virtual CBEDPEAMKMK PMDDNHGLNEB() { }", "CBEDPEAMKMK", 0x0ea66fb0u, 0, 1, nullptr
};
using H029 = HookSlot<T_CBEDPEAMKMK(__fastcall*)(void*), 29, true>;

// ---------------------------------------------------------------- #030
// public AsyncJob CEKPGKHLJGK(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea670b0
static const ParamDesc kP030[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD030 = {
    "CEKPGKHLJGK", "public AsyncJob CEKPGKHLJGK(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea670b0u, 2, 3, kP030
};
using H030 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 30, true>;

// ---------------------------------------------------------------- #031
// public virtual Void JDMPLLDEJKC(System.Boolean OFLDKJOBFDL) { }
// RVA 0x0ea67170
static const ParamDesc kP031[] = {
    { "OFLDKJOBFDL", "Boolean", 0 },
};
static const FnDesc kD031 = {
    "JDMPLLDEJKC", "public virtual Void JDMPLLDEJKC(System.Boolean OFLDKJOBFDL) { }", "Void", 0x0ea67170u, 1, 0, kP031
};
using H031 = HookSlot<void(__fastcall*)(void*, bool), 31, true>;

// ---------------------------------------------------------------- #032
// public Void EJAIALJKJKC(MoleMole.MonoJoypadUIModule FDCGGLIOMBM) { }
// RVA 0x0ea67280
static const ParamDesc kP032[] = {
    { "FDCGGLIOMBM", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD032 = {
    "EJAIALJKJKC", "public Void EJAIALJKJKC(MoleMole.MonoJoypadUIModule FDCGGLIOMBM) { }", "Void", 0x0ea67280u, 1, 0, kP032
};
using H032 = HookSlot<void(__fastcall*)(void*, void*), 32, true>;

// ---------------------------------------------------------------- #033
// public Void HCGDKPJIIIO(MMBJIJOADOD AFECEFAFIHH, MoleMole.BaseContextComponent AGNPEANOGNA) { }
// RVA 0x0ea674a0
static const ParamDesc kP033[] = {
    { "AFECEFAFIHH", "MMBJIJOADOD", 0 },
    { "AGNPEANOGNA", "BaseContextComponent", 0 },
};
static const FnDesc kD033 = {
    "HCGDKPJIIIO", "public Void HCGDKPJIIIO(MMBJIJOADOD AFECEFAFIHH, MoleMole.BaseContextComponent AGNPEANOGNA) { }", "Void", 0x0ea674a0u, 2, 0, kP033
};
using H033 = HookSlot<void(__fastcall*)(void*, T_MMBJIJOADOD, void*), 33, true>;

// ---------------------------------------------------------------- #034
// private Void NJLFCMNGBPD() { }
// RVA 0x0ea676b0
static const FnDesc kD034 = {
    "NJLFCMNGBPD", "private Void NJLFCMNGBPD() { }", "Void", 0x0ea676b0u, 0, 0, nullptr
};
using H034 = HookSlot<void(__fastcall*)(void*), 34, true>;

// ---------------------------------------------------------------- #035
// private Void FNEDGOJNGKL() { }
// RVA 0x0ea67740
static const FnDesc kD035 = {
    "FNEDGOJNGKL", "private Void FNEDGOJNGKL() { }", "Void", 0x0ea67740u, 0, 0, nullptr
};
using H035 = HookSlot<void(__fastcall*)(void*), 35, true>;

// ---------------------------------------------------------------- #036
// public Sprite LJLLAACANNK(System.String BHOAHJNPMGN) { }
// RVA 0x0ea67950
static const ParamDesc kP036[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD036 = {
    "LJLLAACANNK", "public Sprite LJLLAACANNK(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea67950u, 1, 1, kP036
};
using H036 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 36, true>;

// ---------------------------------------------------------------- #037
// public AsyncJob AONHPIIDKME(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea67a10
static const ParamDesc kP037[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD037 = {
    "AONHPIIDKME", "public AsyncJob AONHPIIDKME(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea67a10u, 2, 3, kP037
};
using H037 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 37, true>;

// ---------------------------------------------------------------- #038
// private Void AEMFFPNDCPI(UnityEngine.UI.Toggle KENEAKCAJHI, UnityEngine.Events.UnityAction<System.Boolean> DJIDIEIFPJP, System.Boolean AMKIDFFHNBE) { }
// RVA 0x0ea67b10
static const ParamDesc kP038[] = {
    { "KENEAKCAJHI", "Toggle", 0 },
    { "DJIDIEIFPJP", "UnityAction<Boolean>", 0 },
    { "AMKIDFFHNBE", "Boolean", 0 },
};
static const FnDesc kD038 = {
    "AEMFFPNDCPI", "private Void AEMFFPNDCPI(UnityEngine.UI.Toggle KENEAKCAJHI, UnityEngine.Events.UnityAction<System.Boolean> DJIDIEIFPJP, System.Boolean AMKIDFFHNBE) { }", "Void", 0x0ea67b10u, 3, 0, kP038
};
using H038 = HookSlot<void(__fastcall*)(void*, void*, void*, bool), 38, true>;

// ---------------------------------------------------------------- #039
// public UInt64 PJFEJDHEHGB(System.UInt32 MOAODENKMOD) { }
// RVA 0x0ea67b20
static const ParamDesc kP039[] = {
    { "MOAODENKMOD", "UInt32", 0 },
};
static const FnDesc kD039 = {
    "PJFEJDHEHGB", "public UInt64 PJFEJDHEHGB(System.UInt32 MOAODENKMOD) { }", "UInt64", 0x0ea67b20u, 1, 1, kP039
};
using H039 = HookSlot<uint64_t(__fastcall*)(void*, uint32_t), 39, true>;

// ---------------------------------------------------------------- #040
// public List<GEAACDEJICP> LGNHNMGLKCK() { }
// RVA 0x0ea67b80
static const FnDesc kD040 = {
    "LGNHNMGLKCK", "public List<GEAACDEJICP> LGNHNMGLKCK() { }", "List<GEAACDEJICP>", 0x0ea67b80u, 0, 1, nullptr
};
using H040 = HookSlot<void*(__fastcall*)(void*), 40, true>;

// ---------------------------------------------------------------- #041
// public virtual Void ClearView() { }
// RVA 0x0ea29c20
static const FnDesc kD041 = {
    "ClearView", "public virtual Void ClearView() { }", "Void", 0x0ea29c20u, 0, 0, nullptr
};
using H041 = HookSlot<void(__fastcall*)(void*), 41, true>;

// ---------------------------------------------------------------- #042
// public DNILGNNMKBF PGDEJPBKNFA(MBGAPCMOGML IHDEBEJGPKA, EKAEMFGFEMJ KGMHNNABIDH) { }
// RVA 0x0ea67b90
static const ParamDesc kP042[] = {
    { "IHDEBEJGPKA", "MBGAPCMOGML", 0 },
    { "KGMHNNABIDH", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD042 = {
    "PGDEJPBKNFA", "public DNILGNNMKBF PGDEJPBKNFA(MBGAPCMOGML IHDEBEJGPKA, EKAEMFGFEMJ KGMHNNABIDH) { }", "DNILGNNMKBF", 0x0ea67b90u, 2, 1, kP042
};
using H042 = HookSlot<void*(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 42, true>;

// ---------------------------------------------------------------- #043
// protected Void FFBLPIBPHFK(MoleMole.MonoUIContainer DMNMHJLDNLA, DAIDPONIGDD ILHMOGEEHIC) { }
// RVA 0x0ea680e0
static const ParamDesc kP043[] = {
    { "DMNMHJLDNLA", "MonoUIContainer", 0 },
    { "ILHMOGEEHIC", "DAIDPONIGDD", 0 },
};
static const FnDesc kD043 = {
    "FFBLPIBPHFK", "protected Void FFBLPIBPHFK(MoleMole.MonoUIContainer DMNMHJLDNLA, DAIDPONIGDD ILHMOGEEHIC) { }", "Void", 0x0ea680e0u, 2, 0, kP043
};
using H043 = HookSlot<void(__fastcall*)(void*, void*, T_DAIDPONIGDD), 43, true>;

// ---------------------------------------------------------------- #044
// private Void HNCPGFMJGLF(UnityEngine.Coroutine EOHAPDJAFEN) { }
// RVA 0x0ea64dd0
static const ParamDesc kP044[] = {
    { "EOHAPDJAFEN", "Coroutine", 0 },
};
static const FnDesc kD044 = {
    "HNCPGFMJGLF", "private Void HNCPGFMJGLF(UnityEngine.Coroutine EOHAPDJAFEN) { }", "Void", 0x0ea64dd0u, 1, 0, kP044
};
using H044 = HookSlot<void(__fastcall*)(void*, void*), 44, true>;

// ---------------------------------------------------------------- #045
// public AsyncJob LILNKGHNCCC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea68220
static const ParamDesc kP045[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD045 = {
    "LILNKGHNCCC", "public AsyncJob LILNKGHNCCC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea68220u, 2, 3, kP045
};
using H045 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 45, true>;

// ---------------------------------------------------------------- #046
// protected Void FFBLPIBPHFK(MoleMole.MonoUIContainer DMNMHJLDNLA, MMBJIJOADOD HJIJDFNCJOO) { }
// RVA 0x0ea68320
static const ParamDesc kP046[] = {
    { "DMNMHJLDNLA", "MonoUIContainer", 0 },
    { "HJIJDFNCJOO", "MMBJIJOADOD", 0 },
};
static const FnDesc kD046 = {
    "FFBLPIBPHFK", "protected Void FFBLPIBPHFK(MoleMole.MonoUIContainer DMNMHJLDNLA, MMBJIJOADOD HJIJDFNCJOO) { }", "Void", 0x0ea68320u, 2, 0, kP046
};
using H046 = HookSlot<void(__fastcall*)(void*, void*, T_MMBJIJOADOD), 46, true>;

// ---------------------------------------------------------------- #047
// public Sprite ELMDMBFGPGP(System.String BHOAHJNPMGN) { }
// RVA 0x0ea68430
static const ParamDesc kP047[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD047 = {
    "ELMDMBFGPGP", "public Sprite ELMDMBFGPGP(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea68430u, 1, 1, kP047
};
using H047 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 47, true>;

// ---------------------------------------------------------------- #048
// public Void LBENNIIAJOB(NIKOKDFLGOP NBFCCABCOAL, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea68490
static const ParamDesc kP048[] = {
    { "NBFCCABCOAL", "NIKOKDFLGOP", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD048 = {
    "LBENNIIAJOB", "public Void LBENNIIAJOB(NIKOKDFLGOP NBFCCABCOAL, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea68490u, 2, 0, kP048
};
using H048 = HookSlot<void(__fastcall*)(void*, T_NIKOKDFLGOP, void*), 48, true>;

// ---------------------------------------------------------------- #049
// public Void JNOMIKBCGMB(System.UInt64 ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea68580
static const ParamDesc kP049[] = {
    { "ADEGLFPIMIA", "UInt64", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD049 = {
    "JNOMIKBCGMB", "public Void JNOMIKBCGMB(System.UInt64 ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea68580u, 2, 0, kP049
};
using H049 = HookSlot<void(__fastcall*)(void*, uint64_t, void*), 49, true>;

// ---------------------------------------------------------------- #050
// public Sprite EPFEHJCACML(System.String BHOAHJNPMGN) { }
// RVA 0x0ea68620
static const ParamDesc kP050[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD050 = {
    "EPFEHJCACML", "public Sprite EPFEHJCACML(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea68620u, 1, 1, kP050
};
using H050 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 50, true>;

// ---------------------------------------------------------------- #051
// public AsyncJob LGCBADLPMMN(System.Boolean FBPFBFPHEIN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea686e0
static const ParamDesc kP051[] = {
    { "FBPFBFPHEIN", "Boolean", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD051 = {
    "LGCBADLPMMN", "public AsyncJob LGCBADLPMMN(System.Boolean FBPFBFPHEIN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea686e0u, 2, 3, kP051
};
using H051 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, bool, void*), 51, true>;

// ---------------------------------------------------------------- #052
// public Void HONCEJPKJJD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea687c0
static const ParamDesc kP052[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD052 = {
    "HONCEJPKJJD", "public Void HONCEJPKJJD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea687c0u, 2, 0, kP052
};
using H052 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 52, true>;

// ---------------------------------------------------------------- #053
// protected Void BIIIKOCKGHF() { }
// RVA 0x0ea68890
static const FnDesc kD053 = {
    "BIIIKOCKGHF", "protected Void BIIIKOCKGHF() { }", "Void", 0x0ea68890u, 0, 0, nullptr
};
using H053 = HookSlot<void(__fastcall*)(void*), 53, true>;

// ---------------------------------------------------------------- #054
// private Void PDOOKCJEJGA(UnityEngine.UI.Toggle DHAPJPMGKCM, UnityEngine.Events.UnityAction<System.Boolean> PFFENFNPNFM, System.Boolean CEIBCOIPEPO) { }
// RVA 0x0ea68900
static const ParamDesc kP054[] = {
    { "DHAPJPMGKCM", "Toggle", 0 },
    { "PFFENFNPNFM", "UnityAction<Boolean>", 0 },
    { "CEIBCOIPEPO", "Boolean", 0 },
};
static const FnDesc kD054 = {
    "PDOOKCJEJGA", "private Void PDOOKCJEJGA(UnityEngine.UI.Toggle DHAPJPMGKCM, UnityEngine.Events.UnityAction<System.Boolean> PFFENFNPNFM, System.Boolean CEIBCOIPEPO) { }", "Void", 0x0ea68900u, 3, 0, kP054
};
using H054 = HookSlot<void(__fastcall*)(void*, void*, void*, bool), 54, true>;

// ---------------------------------------------------------------- #055
// public UInt32 GPBLOLENNLI(System.Single EFPDLJAKNBO, System.Action PFFENFNPNFM) { }
// RVA 0x0ea68b40
static const ParamDesc kP055[] = {
    { "EFPDLJAKNBO", "Single", 0 },
    { "PFFENFNPNFM", "Action", 0 },
};
static const FnDesc kD055 = {
    "GPBLOLENNLI", "public UInt32 GPBLOLENNLI(System.Single EFPDLJAKNBO, System.Action PFFENFNPNFM) { }", "UInt32", 0x0ea68b40u, 2, 1, kP055
};
using H055 = HookSlot<uint32_t(__fastcall*)(void*, float, void*), 55, true>;

// ---------------------------------------------------------------- #056
// public Boolean NCBGIAMNFEF() { }
// RVA 0x0ea68c10
static const FnDesc kD056 = {
    "NCBGIAMNFEF", "public Boolean NCBGIAMNFEF() { }", "Boolean", 0x0ea68c10u, 0, 1, nullptr
};
using H056 = HookSlot<bool(__fastcall*)(void*), 56, true>;

// ---------------------------------------------------------------- #057
// protected virtual Void OnDestroyFinal() { }
// RVA 0x0ea68c20
static const FnDesc kD057 = {
    "OnDestroyFinal", "protected virtual Void OnDestroyFinal() { }", "Void", 0x0ea68c20u, 0, 0, nullptr
};
using H057 = HookSlot<void(__fastcall*)(void*), 57, true>;

// ---------------------------------------------------------------- #058
// public virtual Boolean GDICDPDAHIE() { }
// RVA 0x0ea68c60
static const FnDesc kD058 = {
    "GDICDPDAHIE", "public virtual Boolean GDICDPDAHIE() { }", "Boolean", 0x0ea68c60u, 0, 1, nullptr
};
using H058 = HookSlot<bool(__fastcall*)(void*), 58, true>;

// ---------------------------------------------------------------- #059
// protected virtual Void OnDisable() { }
// RVA 0x0ea26980
static const FnDesc kD059 = {
    "OnDisable", "protected virtual Void OnDisable() { }", "Void", 0x0ea26980u, 0, 0, nullptr
};
using H059 = HookSlot<void(__fastcall*)(void*), 59, true>;

// ---------------------------------------------------------------- #060
// public AsyncJob ANAJEBEBADE(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea68c70
static const ParamDesc kP060[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD060 = {
    "ANAJEBEBADE", "public AsyncJob ANAJEBEBADE(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea68c70u, 2, 3, kP060
};
using H060 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 60, true>;

// ---------------------------------------------------------------- #061
// protected virtual Void PostSetupView() { }
// RVA 0x0ea68d70
static const FnDesc kD061 = {
    "PostSetupView", "protected virtual Void PostSetupView() { }", "Void", 0x0ea68d70u, 0, 0, nullptr
};
using H061 = HookSlot<void(__fastcall*)(void*), 61, true>;

// ---------------------------------------------------------------- #062
// public Boolean MGMPFLEMIAE() { }
// RVA 0x0ea68e70
static const FnDesc kD062 = {
    "MGMPFLEMIAE", "public Boolean MGMPFLEMIAE() { }", "Boolean", 0x0ea68e70u, 0, 1, nullptr
};
using H062 = HookSlot<bool(__fastcall*)(void*), 62, true>;

// ---------------------------------------------------------------- #063
// public Coroutine IBLBCEJKOJG(System.Collections.IEnumerator DPMPIEGENFA) { }
// RVA 0x0ea68e80
static const ParamDesc kP063[] = {
    { "DPMPIEGENFA", "IEnumerator", 0 },
};
static const FnDesc kD063 = {
    "IBLBCEJKOJG", "public Coroutine IBLBCEJKOJG(System.Collections.IEnumerator DPMPIEGENFA) { }", "Coroutine", 0x0ea68e80u, 1, 1, kP063
};
using H063 = HookSlot<void*(__fastcall*)(void*, void*), 63, true>;

// ---------------------------------------------------------------- #064
// public Void CAINHIHFKMC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea68f00
static const ParamDesc kP064[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD064 = {
    "CAINHIHFKMC", "public Void CAINHIHFKMC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea68f00u, 3, 0, kP064
};
using H064 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 64, true>;

// ---------------------------------------------------------------- #065
// public AsyncJob JDJFCKEGBPK(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN, System.Boolean IMIOCPNAPLO) { }
// RVA 0x0ea68fe0
static const ParamDesc kP065[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
    { "IMIOCPNAPLO", "Boolean", 0 },
};
static const FnDesc kD065 = {
    "JDJFCKEGBPK", "public AsyncJob JDJFCKEGBPK(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN, System.Boolean IMIOCPNAPLO) { }", "AsyncJob", 0x0ea68fe0u, 3, 3, kP065
};
using H065 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*, bool), 65, true>;

// ---------------------------------------------------------------- #066
// protected virtual Void GDKKHMIBMJK(System.Collections.Generic.Queue<MoleMole.Notify> ICNIPOHJCOA) { }
// RVA 0x0ea69070
static const ParamDesc kP066[] = {
    { "ICNIPOHJCOA", "Queue<Notify>", 0 },
};
static const FnDesc kD066 = {
    "GDKKHMIBMJK", "protected virtual Void GDKKHMIBMJK(System.Collections.Generic.Queue<MoleMole.Notify> ICNIPOHJCOA) { }", "Void", 0x0ea69070u, 1, 0, kP066
};
using H066 = HookSlot<void(__fastcall*)(void*, void*), 66, true>;

// ---------------------------------------------------------------- #067
// private Void BEMPCAKNGAC(UnityEngine.UI.Dropdown OLDPJNLLICA, UnityEngine.Events.UnityAction<System.Int32> PFFENFNPNFM) { }
// RVA 0x0ea692f0
static const ParamDesc kP067[] = {
    { "OLDPJNLLICA", "Dropdown", 0 },
    { "PFFENFNPNFM", "UnityAction<Int32>", 0 },
};
static const FnDesc kD067 = {
    "BEMPCAKNGAC", "private Void BEMPCAKNGAC(UnityEngine.UI.Dropdown OLDPJNLLICA, UnityEngine.Events.UnityAction<System.Int32> PFFENFNPNFM) { }", "Void", 0x0ea692f0u, 2, 0, kP067
};
using H067 = HookSlot<void(__fastcall*)(void*, void*, void*), 67, true>;

// ---------------------------------------------------------------- #068
// public Void EEJOCKLBHFH(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea69550
static const ParamDesc kP068[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD068 = {
    "EEJOCKLBHFH", "public Void EEJOCKLBHFH(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea69550u, 2, 0, kP068
};
using H068 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 68, true>;

// ---------------------------------------------------------------- #069
// public Void PLDEMCEJOHL(UnityEngine.GameObject OKBEGKGBOFG, MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ LLCJKAGCJAA) { }
// RVA 0x0ea69620
static const ParamDesc kP069[] = {
    { "OKBEGKGBOFG", "GameObject", 0 },
    { "DMCKBLLEFOD", "MBGAPCMOGML", 0 },
    { "LLCJKAGCJAA", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD069 = {
    "PLDEMCEJOHL", "public Void PLDEMCEJOHL(UnityEngine.GameObject OKBEGKGBOFG, MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ LLCJKAGCJAA) { }", "Void", 0x0ea69620u, 3, 0, kP069
};
using H069 = HookSlot<void(__fastcall*)(void*, void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 69, true>;

// ---------------------------------------------------------------- #070
// public Void GJPBAOGADDJ(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea69aa0
static const ParamDesc kP070[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD070 = {
    "GJPBAOGADDJ", "public Void GJPBAOGADDJ(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea69aa0u, 2, 0, kP070
};
using H070 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 70, true>;

// ---------------------------------------------------------------- #071
// public AsyncJob BGNNGJMHGEC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea69b80
static const ParamDesc kP071[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD071 = {
    "BGNNGJMHGEC", "public AsyncJob BGNNGJMHGEC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea69b80u, 2, 3, kP071
};
using H071 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 71, true>;

// ---------------------------------------------------------------- #072
// public Sprite OMLLIJMEHDM(System.String BHOAHJNPMGN) { }
// RVA 0x0ea69c80
static const ParamDesc kP072[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD072 = {
    "OMLLIJMEHDM", "public Sprite OMLLIJMEHDM(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea69c80u, 1, 1, kP072
};
using H072 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 72, true>;

// ---------------------------------------------------------------- #073
// public Void NLIGHOFAMGN(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea69ce0
static const ParamDesc kP073[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD073 = {
    "NLIGHOFAMGN", "public Void NLIGHOFAMGN(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea69ce0u, 3, 0, kP073
};
using H073 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 73, true>;

// ---------------------------------------------------------------- #074
// private EIDAIBHGFDD[] LFMJCCBGGLJ(EIDAIBHGFDD[] CNFEDDOIDLN) { }
// RVA 0x0ea69dc0
static const ParamDesc kP074[] = {
    { "CNFEDDOIDLN", "EIDAIBHGFDD[]", 0 },
};
static const FnDesc kD074 = {
    "LFMJCCBGGLJ", "private EIDAIBHGFDD[] LFMJCCBGGLJ(EIDAIBHGFDD[] CNFEDDOIDLN) { }", "EIDAIBHGFDD[]", 0x0ea69dc0u, 1, 1, kP074
};
using H074 = HookSlot<void*(__fastcall*)(void*, void*), 74, true>;

// ---------------------------------------------------------------- #075
// private Void GALLFNJODCC(LNJGBKDGMJB OKCKDILGOGJ) { }
// RVA 0x0ea69fc0
static const ParamDesc kP075[] = {
    { "OKCKDILGOGJ", "LNJGBKDGMJB", 0 },
};
static const FnDesc kD075 = {
    "GALLFNJODCC", "private Void GALLFNJODCC(LNJGBKDGMJB OKCKDILGOGJ) { }", "Void", 0x0ea69fc0u, 1, 0, kP075
};
using H075 = HookSlot<void(__fastcall*)(void*, T_LNJGBKDGMJB), 75, true>;

// ---------------------------------------------------------------- #076
// public Void FPLAKMAPFPE(UnityEngine.Coroutine EOHAPDJAFEN) { }
// RVA 0x0ea6a0e0
static const ParamDesc kP076[] = {
    { "EOHAPDJAFEN", "Coroutine", 0 },
};
static const FnDesc kD076 = {
    "FPLAKMAPFPE", "public Void FPLAKMAPFPE(UnityEngine.Coroutine EOHAPDJAFEN) { }", "Void", 0x0ea6a0e0u, 1, 0, kP076
};
using H076 = HookSlot<void(__fastcall*)(void*, void*), 76, true>;

// ---------------------------------------------------------------- #077
// public Boolean NCFOMECCGLI(MoleMole.Notify JPGCMPKAJGE) { }
// RVA 0x0ea6a170
static const ParamDesc kP077[] = {
    { "JPGCMPKAJGE", "", 0 },
};
static const FnDesc kD077 = {
    "NCFOMECCGLI", "public Boolean NCFOMECCGLI(MoleMole.Notify JPGCMPKAJGE) { }", "Boolean", 0x0ea6a170u, 1, 1, kP077
};
using H077 = HookSlot<bool(__fastcall*)(void*, const T_MoleMole_Notify*), 77, true>;

// ---------------------------------------------------------------- #078
// private Void PDJECLHNDCA() { }
// RVA 0x0ea6a230
static const FnDesc kD078 = {
    "PDJECLHNDCA", "private Void PDJECLHNDCA() { }", "Void", 0x0ea6a230u, 0, 0, nullptr
};
using H078 = HookSlot<void(__fastcall*)(void*), 78, true>;

// ---------------------------------------------------------------- #079
// private Void BPLLMJFACBL(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea6a470
static const ParamDesc kP079[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD079 = {
    "BPLLMJFACBL", "private Void BPLLMJFACBL(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea6a470u, 2, 0, kP079
};
using H079 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 79, true>;

// ---------------------------------------------------------------- #080
// private Void ABOBLCMGCJD(MoleMole.Notify CNMPOFACGDF, System.Boolean PHBLEHILFOA, System.Boolean FOPIJBLODLO) { }
// RVA 0x0ea6a780
static const ParamDesc kP080[] = {
    { "CNMPOFACGDF", "", 0 },
    { "PHBLEHILFOA", "Boolean", 0 },
    { "FOPIJBLODLO", "Boolean", 0 },
};
static const FnDesc kD080 = {
    "ABOBLCMGCJD", "private Void ABOBLCMGCJD(MoleMole.Notify CNMPOFACGDF, System.Boolean PHBLEHILFOA, System.Boolean FOPIJBLODLO) { }", "Void", 0x0ea6a780u, 3, 0, kP080
};
using H080 = HookSlot<void(__fastcall*)(void*, const T_MoleMole_Notify*, bool, bool), 80, true>;

// ---------------------------------------------------------------- #081
// public Void GPEJOGILFMH(System.String ENFMEBMIALK) { }
// RVA 0x0ea6aa80
static const ParamDesc kP081[] = {
    { "ENFMEBMIALK", "String", 0 },
};
static const FnDesc kD081 = {
    "GPEJOGILFMH", "public Void GPEJOGILFMH(System.String ENFMEBMIALK) { }", "Void", 0x0ea6aa80u, 1, 0, kP081
};
using H081 = HookSlot<void(__fastcall*)(void*, Il2CppString*), 81, true>;

// ---------------------------------------------------------------- #082
// public Sprite DHIOJJGKNBL(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6ab30
static const ParamDesc kP082[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD082 = {
    "DHIOJJGKNBL", "public Sprite DHIOJJGKNBL(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6ab30u, 1, 1, kP082
};
using H082 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 82, true>;

// ---------------------------------------------------------------- #083
// protected Void FFBLPIBPHFK(MoleMole.MonoControlElement NFOEGFAMDAL, DAIDPONIGDD ILHMOGEEHIC) { }
// RVA 0x0ea27910
static const ParamDesc kP083[] = {
    { "NFOEGFAMDAL", "MonoControlElement", 0 },
    { "ILHMOGEEHIC", "DAIDPONIGDD", 0 },
};
static const FnDesc kD083 = {
    "FFBLPIBPHFK", "protected Void FFBLPIBPHFK(MoleMole.MonoControlElement NFOEGFAMDAL, DAIDPONIGDD ILHMOGEEHIC) { }", "Void", 0x0ea27910u, 2, 0, kP083
};
using H083 = HookSlot<void(__fastcall*)(void*, void*, T_DAIDPONIGDD), 83, true>;

// ---------------------------------------------------------------- #084
// public Void FNMGJIBFNDJ(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6ab90
static const ParamDesc kP084[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD084 = {
    "FNMGJIBFNDJ", "public Void FNMGJIBFNDJ(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6ab90u, 2, 0, kP084
};
using H084 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 84, true>;

// ---------------------------------------------------------------- #085
// public Boolean IHDACBLPHKH() { }
// RVA 0x0ea67050
static const FnDesc kD085 = {
    "IHDACBLPHKH", "public Boolean IHDACBLPHKH() { }", "Boolean", 0x0ea67050u, 0, 1, nullptr
};
using H085 = HookSlot<bool(__fastcall*)(void*), 85, true>;

// ---------------------------------------------------------------- #086
// protected virtual Boolean DAPLOCGJHFA() { }
// RVA 0x0ea6ac30
static const FnDesc kD086 = {
    "DAPLOCGJHFA", "protected virtual Boolean DAPLOCGJHFA() { }", "Boolean", 0x0ea6ac30u, 0, 1, nullptr
};
using H086 = HookSlot<bool(__fastcall*)(void*), 86, true>;

// ---------------------------------------------------------------- #087
// public Void EKNJNOAFCCN(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6ac40
static const ParamDesc kP087[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD087 = {
    "EKNJNOAFCCN", "public Void EKNJNOAFCCN(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6ac40u, 2, 0, kP087
};
using H087 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 87, true>;

// ---------------------------------------------------------------- #088
// public Sprite AMGLLFMIMFD(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6ad10
static const ParamDesc kP088[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD088 = {
    "AMGLLFMIMFD", "public Sprite AMGLLFMIMFD(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6ad10u, 1, 1, kP088
};
using H088 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 88, true>;

// ---------------------------------------------------------------- #089
// public Void GLKEHAOGOJA(BHIDJOHFING BBDFLHEKIEC, System.Boolean KPOLBFMOEAA, System.Nullable<EKAEMFGFEMJ> GCFDMPNHAAC) { }
// RVA 0x0ea6ada0
static const ParamDesc kP089[] = {
    { "BBDFLHEKIEC", "BHIDJOHFING", 0 },
    { "KPOLBFMOEAA", "Boolean", 0 },
    { "GCFDMPNHAAC", "Nullable<EKAEMFGFEMJ>", 0 },
};
static const FnDesc kD089 = {
    "GLKEHAOGOJA", "public Void GLKEHAOGOJA(BHIDJOHFING BBDFLHEKIEC, System.Boolean KPOLBFMOEAA, System.Nullable<EKAEMFGFEMJ> GCFDMPNHAAC) { }", "Void", 0x0ea6ada0u, 3, 0, kP089
};
using H089 = HookSlot<void(__fastcall*)(void*, void*, bool, void*), 89, true>;

// ---------------------------------------------------------------- #090
// public Void GKGFAEHBDDG(UnityEngine.GameObject LNLECKPEBBO, System.Boolean KPOLBFMOEAA, System.Nullable<EKAEMFGFEMJ> GCFDMPNHAAC) { }
// RVA 0x0ea6b070
static const ParamDesc kP090[] = {
    { "LNLECKPEBBO", "GameObject", 0 },
    { "KPOLBFMOEAA", "Boolean", 0 },
    { "GCFDMPNHAAC", "Nullable<EKAEMFGFEMJ>", 0 },
};
static const FnDesc kD090 = {
    "GKGFAEHBDDG", "public Void GKGFAEHBDDG(UnityEngine.GameObject LNLECKPEBBO, System.Boolean KPOLBFMOEAA, System.Nullable<EKAEMFGFEMJ> GCFDMPNHAAC) { }", "Void", 0x0ea6b070u, 3, 0, kP090
};
using H090 = HookSlot<void(__fastcall*)(void*, void*, bool, void*), 90, true>;

// ---------------------------------------------------------------- #091
// public Void FHFCJKJMLFG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6b280
static const ParamDesc kP091[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD091 = {
    "FHFCJKJMLFG", "public Void FHFCJKJMLFG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6b280u, 2, 0, kP091
};
using H091 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 91, true>;

// ---------------------------------------------------------------- #092
// public virtual Void OnJoypadUIModuleSelectIndex(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }
// RVA 0x0ea6b350
static const ParamDesc kP092[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "Int32", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "ILLHJJAJOKF", "GCLHPKAEIPN", 0 },
};
static const FnDesc kD092 = {
    "OnJoypadUIModuleSelectIndex", "public virtual Void OnJoypadUIModuleSelectIndex(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }", "Void", 0x0ea6b350u, 4, 0, kP092
};
using H092 = HookSlot<void(__fastcall*)(void*, void*, int32_t, void*, T_GCLHPKAEIPN), 92, true>;

// ---------------------------------------------------------------- #093
// protected Void JLGIICCNNCB() { }
// RVA 0x0ea6b3b0
static const FnDesc kD093 = {
    "JLGIICCNNCB", "protected Void JLGIICCNNCB() { }", "Void", 0x0ea6b3b0u, 0, 0, nullptr
};
using H093 = HookSlot<void(__fastcall*)(void*), 93, true>;

// ---------------------------------------------------------------- #094
// public Void CAJMHNNFLEN(MoleMole.MonoJoypadUIModule FDCGGLIOMBM) { }
// RVA 0x0ea67330
static const ParamDesc kP094[] = {
    { "FDCGGLIOMBM", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD094 = {
    "CAJMHNNFLEN", "public Void CAJMHNNFLEN(MoleMole.MonoJoypadUIModule FDCGGLIOMBM) { }", "Void", 0x0ea67330u, 1, 0, kP094
};
using H094 = HookSlot<void(__fastcall*)(void*, void*), 94, true>;

// ---------------------------------------------------------------- #095
// public Sprite ODEOFFNDMBD(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6b5b0
static const ParamDesc kP095[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD095 = {
    "ODEOFFNDMBD", "public Sprite ODEOFFNDMBD(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6b5b0u, 1, 1, kP095
};
using H095 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 95, true>;

// ---------------------------------------------------------------- #096
// protected Void LNLMAHBGCED(KHEIDDJMEML LMILCIBLNDB) { }
// RVA 0x0ea6b670
static const ParamDesc kP096[] = {
    { "LMILCIBLNDB", "KHEIDDJMEML", 0 },
};
static const FnDesc kD096 = {
    "LNLMAHBGCED", "protected Void LNLMAHBGCED(KHEIDDJMEML LMILCIBLNDB) { }", "Void", 0x0ea6b670u, 1, 0, kP096
};
using H096 = HookSlot<void(__fastcall*)(void*, void*), 96, true>;

// ---------------------------------------------------------------- #097
// public virtual Void BAHPNONFAND() { }
// RVA 0x0ea6b710
static const FnDesc kD097 = {
    "BAHPNONFAND", "public virtual Void BAHPNONFAND() { }", "Void", 0x0ea6b710u, 0, 0, nullptr
};
using H097 = HookSlot<void(__fastcall*)(void*), 97, true>;

// ---------------------------------------------------------------- #098
// public Void EDANFBDGDHM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6b940
static const ParamDesc kP098[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD098 = {
    "EDANFBDGDHM", "public Void EDANFBDGDHM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6b940u, 2, 0, kP098
};
using H098 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 98, true>;

// ---------------------------------------------------------------- #099
// public Sprite HGCHMGCFIFK(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6b9a0
static const ParamDesc kP099[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD099 = {
    "HGCHMGCFIFK", "public Sprite HGCHMGCFIFK(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6b9a0u, 1, 1, kP099
};
using H099 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 99, true>;

// ---------------------------------------------------------------- #100
// public Void NAKEOCCBCCI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6ba60
static const ParamDesc kP100[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD100 = {
    "NAKEOCCBCCI", "public Void NAKEOCCBCCI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6ba60u, 2, 0, kP100
};
using H100 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 100, true>;

// ---------------------------------------------------------------- #101
// public Sprite ONDPJPIHIKD(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6bb30
static const ParamDesc kP101[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD101 = {
    "ONDPJPIHIKD", "public Sprite ONDPJPIHIKD(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6bb30u, 1, 1, kP101
};
using H101 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 101, true>;

// ---------------------------------------------------------------- #102
// public Void CLEJEMDFCGO(MoleMole.MonoJoypadNavRegionBase OPPHKACDBBN) { }
// RVA 0x0ea6bbc0
static const ParamDesc kP102[] = {
    { "OPPHKACDBBN", "MonoJoypadNavRegionBase", 0 },
};
static const FnDesc kD102 = {
    "CLEJEMDFCGO", "public Void CLEJEMDFCGO(MoleMole.MonoJoypadNavRegionBase OPPHKACDBBN) { }", "Void", 0x0ea6bbc0u, 1, 0, kP102
};
using H102 = HookSlot<void(__fastcall*)(void*, void*), 102, true>;

// ---------------------------------------------------------------- #103
// private Boolean PJMNOMPGAMF() { }
// RVA 0x0ea6a9d0
static const FnDesc kD103 = {
    "PJMNOMPGAMF", "private Boolean PJMNOMPGAMF() { }", "Boolean", 0x0ea6a9d0u, 0, 1, nullptr
};
using H103 = HookSlot<bool(__fastcall*)(void*), 103, true>;

// ---------------------------------------------------------------- #104
// public Void DLMKHAPIDLG(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea6bca0
static const ParamDesc kP104[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD104 = {
    "DLMKHAPIDLG", "public Void DLMKHAPIDLG(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea6bca0u, 2, 0, kP104
};
using H104 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 104, true>;

// ---------------------------------------------------------------- #105
// private BIKEJEKGCHG PHAAAKGEFDA(EKHBADNLJKF CDKOJMEODLF) { }
// RVA 0x0ea6bdb0
static const ParamDesc kP105[] = {
    { "CDKOJMEODLF", "EKHBADNLJKF", 0 },
};
static const FnDesc kD105 = {
    "PHAAAKGEFDA", "private BIKEJEKGCHG PHAAAKGEFDA(EKHBADNLJKF CDKOJMEODLF) { }", "BIKEJEKGCHG", 0x0ea6bdb0u, 1, 1, kP105
};
using H105 = HookSlot<T_BIKEJEKGCHG(__fastcall*)(void*, void*), 105, true>;

// ---------------------------------------------------------------- #106
// protected virtual Void NFNIKCJGDMJ() { }
// RVA 0x0ea6bf40
static const FnDesc kD106 = {
    "NFNIKCJGDMJ", "protected virtual Void NFNIKCJGDMJ() { }", "Void", 0x0ea6bf40u, 0, 0, nullptr
};
using H106 = HookSlot<void(__fastcall*)(void*), 106, true>;

// ---------------------------------------------------------------- #107
// public Boolean DFEIKLHJCHB() { }
// RVA 0x0ea67270
static const FnDesc kD107 = {
    "DFEIKLHJCHB", "public Boolean DFEIKLHJCHB() { }", "Boolean", 0x0ea67270u, 0, 1, nullptr
};
using H107 = HookSlot<bool(__fastcall*)(void*), 107, true>;

// ---------------------------------------------------------------- #108
// public virtual Void CLDADKLLLKC() { }
// RVA 0x0ea6bf80
static const FnDesc kD108 = {
    "CLDADKLLLKC", "public virtual Void CLDADKLLLKC() { }", "Void", 0x0ea6bf80u, 0, 0, nullptr
};
using H108 = HookSlot<void(__fastcall*)(void*), 108, true>;

// ---------------------------------------------------------------- #109
// public GEGODFHFBIG AKOIBJADPEM() { }
// RVA 0x0ea6bfc0
static const FnDesc kD109 = {
    "AKOIBJADPEM", "public GEGODFHFBIG AKOIBJADPEM() { }", "GEGODFHFBIG", 0x0ea6bfc0u, 0, 1, nullptr
};
using H109 = HookSlot<T_GEGODFHFBIG(__fastcall*)(void*), 109, true>;

// ---------------------------------------------------------------- #110
// public Void BGMCJMKELHG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6bfd0
static const ParamDesc kP110[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD110 = {
    "BGMCJMKELHG", "public Void BGMCJMKELHG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6bfd0u, 2, 0, kP110
};
using H110 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 110, true>;

// ---------------------------------------------------------------- #111
// public Sprite LHGJFNEHDME(NIKOKDFLGOP NBFCCABCOAL) { }
// RVA 0x0ea6c030
static const ParamDesc kP111[] = {
    { "NBFCCABCOAL", "NIKOKDFLGOP", 0 },
};
static const FnDesc kD111 = {
    "LHGJFNEHDME", "public Sprite LHGJFNEHDME(NIKOKDFLGOP NBFCCABCOAL) { }", "Sprite", 0x0ea6c030u, 1, 1, kP111
};
using H111 = HookSlot<void*(__fastcall*)(void*, T_NIKOKDFLGOP), 111, true>;

// ---------------------------------------------------------------- #112
// public Void AOEDDDADBBE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6c100
static const ParamDesc kP112[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD112 = {
    "AOEDDDADBBE", "public Void AOEDDDADBBE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6c100u, 2, 0, kP112
};
using H112 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 112, true>;

// ---------------------------------------------------------------- #113
// public Sprite IBDPGBLLLGI(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6c1a0
static const ParamDesc kP113[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD113 = {
    "IBDPGBLLLGI", "public Sprite IBDPGBLLLGI(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6c1a0u, 1, 1, kP113
};
using H113 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 113, true>;

// ---------------------------------------------------------------- #114
// public Void PFKLJJENPGB(UnityEngine.Transform GCOLEFDNHNO, UnityEngine.EventSystems.EventTriggerType JDHMCFLELMB, System.Action<UnityEngine.EventSystems.BaseEventData> FKGGKMAKEPN, System.Boolean JAPHHBPJFLB) { }
// RVA 0x0ea6c230
static const ParamDesc kP114[] = {
    { "GCOLEFDNHNO", "Transform", 0 },
    { "JDHMCFLELMB", "EventTriggerType", 0 },
    { "FKGGKMAKEPN", "Action<BaseEventData>", 0 },
    { "JAPHHBPJFLB", "Boolean", 0 },
};
static const FnDesc kD114 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(UnityEngine.Transform GCOLEFDNHNO, UnityEngine.EventSystems.EventTriggerType JDHMCFLELMB, System.Action<UnityEngine.EventSystems.BaseEventData> FKGGKMAKEPN, System.Boolean JAPHHBPJFLB) { }", "Void", 0x0ea6c230u, 4, 0, kP114
};
using H114 = HookSlot<void(__fastcall*)(void*, void*, T_UnityEngine_EventSystems_EventTriggerType, void*, bool), 114, true>;

// ---------------------------------------------------------------- #115
// public Void BMCMDMEKOCA(System.String MEIDPKIFMJH, System.String FMECADKPMIP, DDFAHHEEPOM MPFFKAAMAKP, System.Nullable<DLPEPIGFIKJ> AHGGLCJKIIH, System.Action<UnityEngine.Sprite> AOGOPNDNAHI) { }
// RVA 0x0ea6c5a0
static const ParamDesc kP115[] = {
    { "MEIDPKIFMJH", "String", 0 },
    { "FMECADKPMIP", "String", 0 },
    { "MPFFKAAMAKP", "DDFAHHEEPOM", 0 },
    { "AHGGLCJKIIH", "Nullable<DLPEPIGFIKJ>", 0 },
    { "AOGOPNDNAHI", "Action<Sprite>", 0 },
};
static const FnDesc kD115 = {
    "BMCMDMEKOCA", "public Void BMCMDMEKOCA(System.String MEIDPKIFMJH, System.String FMECADKPMIP, DDFAHHEEPOM MPFFKAAMAKP, System.Nullable<DLPEPIGFIKJ> AHGGLCJKIIH, System.Action<UnityEngine.Sprite> AOGOPNDNAHI) { }", "Void", 0x0ea6c5a0u, 5, 0, kP115
};
using H115 = HookSlot<void(__fastcall*)(void*, Il2CppString*, Il2CppString*, T_DDFAHHEEPOM, void*, void*), 115, true>;

// ---------------------------------------------------------------- #116
// protected Void KJBECFIJEOL(BIKEJEKGCHG FKJFLKANHNP) { }
// RVA 0x0ea6c7c0
static const ParamDesc kP116[] = {
    { "FKJFLKANHNP", "", 0 },
};
static const FnDesc kD116 = {
    "KJBECFIJEOL", "protected Void KJBECFIJEOL(BIKEJEKGCHG FKJFLKANHNP) { }", "Void", 0x0ea6c7c0u, 1, 0, kP116
};
using H116 = HookSlot<void(__fastcall*)(void*, T_BIKEJEKGCHG), 116, true>;

// ---------------------------------------------------------------- #117
// public Single DPPPAEMNICG(EIDAIBHGFDD PBCFJMEEDMG, System.Boolean ELCOFJLOFDH) { }
// RVA 0x0ea6c7d0
static const ParamDesc kP117[] = {
    { "PBCFJMEEDMG", "", 0 },
    { "ELCOFJLOFDH", "Boolean", 0 },
};
static const FnDesc kD117 = {
    "DPPPAEMNICG", "public Single DPPPAEMNICG(EIDAIBHGFDD PBCFJMEEDMG, System.Boolean ELCOFJLOFDH) { }", "Single", 0x0ea6c7d0u, 2, 1, kP117
};
using H117 = HookSlot<float(__fastcall*)(void*, const T_EIDAIBHGFDD*, bool), 117, true>;

// ---------------------------------------------------------------- #118
// public Void PFKLJJENPGB(UnityEngine.UI.Button DBICHEBDBPA, UnityEngine.Events.UnityAction FKGGKMAKEPN) { }
// RVA 0x0ea33bb0
static const ParamDesc kP118[] = {
    { "DBICHEBDBPA", "Button", 0 },
    { "FKGGKMAKEPN", "UnityAction", 0 },
};
static const FnDesc kD118 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(UnityEngine.UI.Button DBICHEBDBPA, UnityEngine.Events.UnityAction FKGGKMAKEPN) { }", "Void", 0x0ea33bb0u, 2, 0, kP118
};
using H118 = HookSlot<void(__fastcall*)(void*, void*, void*), 118, true>;

// ---------------------------------------------------------------- #119
// public IEnumerator EPDOLANAGIA(System.Single EFPDLJAKNBO) { }
// RVA 0x0ea6c920
static const ParamDesc kP119[] = {
    { "EFPDLJAKNBO", "Single", 0 },
};
static const FnDesc kD119 = {
    "EPDOLANAGIA", "public IEnumerator EPDOLANAGIA(System.Single EFPDLJAKNBO) { }", "IEnumerator", 0x0ea6c920u, 1, 1, kP119
};
using H119 = HookSlot<void*(__fastcall*)(void*, float), 119, true>;

// ---------------------------------------------------------------- #120
// public Void FONHJILPKHG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6c9c0
static const ParamDesc kP120[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD120 = {
    "FONHJILPKHG", "public Void FONHJILPKHG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6c9c0u, 2, 0, kP120
};
using H120 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 120, true>;

// ---------------------------------------------------------------- #121
// public AsyncJob DHNDGMEPCID(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6ca90
static const ParamDesc kP121[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD121 = {
    "DHNDGMEPCID", "public AsyncJob DHNDGMEPCID(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6ca90u, 2, 3, kP121
};
using H121 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 121, true>;

// ---------------------------------------------------------------- #122
// public Sprite KEKANEOELLC(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6cb50
static const ParamDesc kP122[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD122 = {
    "KEKANEOELLC", "public Sprite KEKANEOELLC(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6cb50u, 1, 1, kP122
};
using H122 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 122, true>;

// ---------------------------------------------------------------- #123
// public Void OGDFKGMNMGJ(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea6cc10
static const ParamDesc kP123[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD123 = {
    "OGDFKGMNMGJ", "public Void OGDFKGMNMGJ(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea6cc10u, 3, 0, kP123
};
using H123 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 123, true>;

// ---------------------------------------------------------------- #124
// public Void ALPNDENNMEL(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA) { }
// RVA 0x0ea6ccf0
static const ParamDesc kP124[] = {
    { "DAONBKOKGEA", "ListNavigatePointerActionConfig", 0 },
};
static const FnDesc kD124 = {
    "ALPNDENNMEL", "public Void ALPNDENNMEL(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA) { }", "Void", 0x0ea6ccf0u, 1, 0, kP124
};
using H124 = HookSlot<void(__fastcall*)(void*, void*), 124, true>;

// ---------------------------------------------------------------- #125
// public AsyncJob LHFLEIILGDO(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6cd60
static const ParamDesc kP125[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD125 = {
    "LHFLEIILGDO", "public AsyncJob LHFLEIILGDO(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6cd60u, 2, 3, kP125
};
using H125 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 125, true>;

// ---------------------------------------------------------------- #126
// public AsyncJob HONCEJPKJJD(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6ce20
static const ParamDesc kP126[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD126 = {
    "HONCEJPKJJD", "public AsyncJob HONCEJPKJJD(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6ce20u, 2, 3, kP126
};
using H126 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 126, true>;

// ---------------------------------------------------------------- #127
// protected virtual Void OnContextCloseFinal() { }
// RVA 0x0ea34130
static const FnDesc kD127 = {
    "OnContextCloseFinal", "protected virtual Void OnContextCloseFinal() { }", "Void", 0x0ea34130u, 0, 0, nullptr
};
using H127 = HookSlot<void(__fastcall*)(void*), 127, true>;

// ---------------------------------------------------------------- #128
// public Sprite MAFEDLDAKJB(OMHKNJLAFDO IOIDEPIBFJJ) { }
// RVA 0x0ea6cf20
static const ParamDesc kP128[] = {
    { "IOIDEPIBFJJ", "OMHKNJLAFDO", 0 },
};
static const FnDesc kD128 = {
    "MAFEDLDAKJB", "public Sprite MAFEDLDAKJB(OMHKNJLAFDO IOIDEPIBFJJ) { }", "Sprite", 0x0ea6cf20u, 1, 1, kP128
};
using H128 = HookSlot<void*(__fastcall*)(void*, T_OMHKNJLAFDO), 128, true>;

// ---------------------------------------------------------------- #129
// protected virtual Void NCFHJHHPJAK(UnityEngine.GameObject GNEDAIHCOJB) { }
// RVA 0x0ea6cf80
static const ParamDesc kP129[] = {
    { "GNEDAIHCOJB", "GameObject", 0 },
};
static const FnDesc kD129 = {
    "NCFHJHHPJAK", "protected virtual Void NCFHJHHPJAK(UnityEngine.GameObject GNEDAIHCOJB) { }", "Void", 0x0ea6cf80u, 1, 0, kP129
};
using H129 = HookSlot<void(__fastcall*)(void*, void*), 129, true>;

// ---------------------------------------------------------------- #130
// public AsyncJob AOEDDDADBBE(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6d090
static const ParamDesc kP130[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD130 = {
    "AOEDDDADBBE", "public AsyncJob AOEDDDADBBE(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6d090u, 2, 3, kP130
};
using H130 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 130, true>;

// ---------------------------------------------------------------- #131
// public static Void MBNLEMAMGBG(EKHBADNLJKF KKENALCFNLM, MoleMole.BaseContextComponent HNDCBBFHLMD) { }
// RVA 0x0ea6d150
static const ParamDesc kP131[] = {
    { "KKENALCFNLM", "EKHBADNLJKF", 0 },
    { "HNDCBBFHLMD", "BaseContextComponent", 0 },
};
static const FnDesc kD131 = {
    "MBNLEMAMGBG", "public static Void MBNLEMAMGBG(EKHBADNLJKF KKENALCFNLM, MoleMole.BaseContextComponent HNDCBBFHLMD) { }", "Void", 0x0ea6d150u, 2, 0, kP131
};
using H131 = HookSlot<void(__fastcall*)(void*, void*), 131>;

// ---------------------------------------------------------------- #132
// public Void BOKJELAOJGD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6d620
static const ParamDesc kP132[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD132 = {
    "BOKJELAOJGD", "public Void BOKJELAOJGD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6d620u, 2, 0, kP132
};
using H132 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 132, true>;

// ---------------------------------------------------------------- #133
// public Void DOLIGGCLNDH(System.Int32 JIJAGOPMIJJ, MoleMole.BaseContextComponent AGNPEANOGNA) { }
// RVA 0x0ea6d6f0
static const ParamDesc kP133[] = {
    { "JIJAGOPMIJJ", "Int32", 0 },
    { "AGNPEANOGNA", "BaseContextComponent", 0 },
};
static const FnDesc kD133 = {
    "DOLIGGCLNDH", "public Void DOLIGGCLNDH(System.Int32 JIJAGOPMIJJ, MoleMole.BaseContextComponent AGNPEANOGNA) { }", "Void", 0x0ea6d6f0u, 2, 0, kP133
};
using H133 = HookSlot<void(__fastcall*)(void*, int32_t, void*), 133, true>;

// ---------------------------------------------------------------- #134
// public Sprite PDEOOHENKID(System.Boolean FBPFBFPHEIN) { }
// RVA 0x0ea6daa0
static const ParamDesc kP134[] = {
    { "FBPFBFPHEIN", "Boolean", 0 },
};
static const FnDesc kD134 = {
    "PDEOOHENKID", "public Sprite PDEOOHENKID(System.Boolean FBPFBFPHEIN) { }", "Sprite", 0x0ea6daa0u, 1, 1, kP134
};
using H134 = HookSlot<void*(__fastcall*)(void*, bool), 134, true>;

// ---------------------------------------------------------------- #135
// public AsyncJob BHEECOEEHOB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6db40
static const ParamDesc kP135[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD135 = {
    "BHEECOEEHOB", "public AsyncJob BHEECOEEHOB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6db40u, 2, 3, kP135
};
using H135 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 135, true>;

// ---------------------------------------------------------------- #136
// private Void LFDAEEBBNDG(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea6dc00
static const ParamDesc kP136[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD136 = {
    "LFDAEEBBNDG", "private Void LFDAEEBBNDG(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea6dc00u, 2, 0, kP136
};
using H136 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 136, true>;

// ---------------------------------------------------------------- #137
// public AsyncJob CJOAECFBIHP(MBEGFPNIONG GMKLFOIOFCO, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6dda0
static const ParamDesc kP137[] = {
    { "GMKLFOIOFCO", "MBEGFPNIONG", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD137 = {
    "CJOAECFBIHP", "public AsyncJob CJOAECFBIHP(MBEGFPNIONG GMKLFOIOFCO, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6dda0u, 2, 3, kP137
};
using H137 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, void*, void*), 137, true>;

// ---------------------------------------------------------------- #138
// public Void PFKLJJENPGB(MoleMole.Mono2DSlider AENDAFJDEAA, UnityEngine.Events.UnityAction<UnityEngine.Vector2> FKGGKMAKEPN) { }
// RVA 0x0ea6de20
static const ParamDesc kP138[] = {
    { "AENDAFJDEAA", "Mono2DSlider", 0 },
    { "FKGGKMAKEPN", "UnityAction<Vector2>", 0 },
};
static const FnDesc kD138 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(MoleMole.Mono2DSlider AENDAFJDEAA, UnityEngine.Events.UnityAction<UnityEngine.Vector2> FKGGKMAKEPN) { }", "Void", 0x0ea6de20u, 2, 0, kP138
};
using H138 = HookSlot<void(__fastcall*)(void*, void*, void*), 138, true>;

// ---------------------------------------------------------------- #139
// public Sprite IONCGNKFEKG(System.UInt64 ADEGLFPIMIA) { }
// RVA 0x0ea6e0c0
static const ParamDesc kP139[] = {
    { "ADEGLFPIMIA", "UInt64", 0 },
};
static const FnDesc kD139 = {
    "IONCGNKFEKG", "public Sprite IONCGNKFEKG(System.UInt64 ADEGLFPIMIA) { }", "Sprite", 0x0ea6e0c0u, 1, 1, kP139
};
using H139 = HookSlot<void*(__fastcall*)(void*, uint64_t), 139, true>;

// ---------------------------------------------------------------- #140
// public Void DNDHKNGMEBE(System.UInt64 ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea33670
static const ParamDesc kP140[] = {
    { "ADEGLFPIMIA", "UInt64", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD140 = {
    "DNDHKNGMEBE", "public Void DNDHKNGMEBE(System.UInt64 ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea33670u, 2, 0, kP140
};
using H140 = HookSlot<void(__fastcall*)(void*, uint64_t, void*), 140, true>;

// ---------------------------------------------------------------- #141
// public Void GPDIFACOJMK(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }
// RVA 0x0ea6e120
static const ParamDesc kP141[] = {
    { "LAINJKDPDBF", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD141 = {
    "GPDIFACOJMK", "public Void GPDIFACOJMK(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }", "Void", 0x0ea6e120u, 1, 0, kP141
};
using H141 = HookSlot<void(__fastcall*)(void*, void*), 141, true>;

// ---------------------------------------------------------------- #142
// public virtual Boolean MFDFHMNPOBM() { }
// RVA 0x0ea6e200
static const FnDesc kD142 = {
    "MFDFHMNPOBM", "public virtual Boolean MFDFHMNPOBM() { }", "Boolean", 0x0ea6e200u, 0, 1, nullptr
};
using H142 = HookSlot<bool(__fastcall*)(void*), 142, true>;

// ---------------------------------------------------------------- #143
// public Sprite NIJGEJFIMOG(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6e210
static const ParamDesc kP143[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD143 = {
    "NIJGEJFIMOG", "public Sprite NIJGEJFIMOG(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6e210u, 1, 1, kP143
};
using H143 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 143, true>;

// ---------------------------------------------------------------- #144
// public Void NCJDIEEEMJL(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA, UnityEngine.GameObject FJHCGNPIBDO, AKKGBKCGGNB ILHMOGEEHIC, System.Action EBJNFCKOCNH) { }
// RVA 0x0ea6e2d0
static const ParamDesc kP144[] = {
    { "DAONBKOKGEA", "ListNavigatePointerActionConfig", 0 },
    { "FJHCGNPIBDO", "GameObject", 0 },
    { "ILHMOGEEHIC", "AKKGBKCGGNB", 0 },
    { "EBJNFCKOCNH", "Action", 0 },
};
static const FnDesc kD144 = {
    "NCJDIEEEMJL", "public Void NCJDIEEEMJL(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA, UnityEngine.GameObject FJHCGNPIBDO, AKKGBKCGGNB ILHMOGEEHIC, System.Action EBJNFCKOCNH) { }", "Void", 0x0ea6e2d0u, 4, 0, kP144
};
using H144 = HookSlot<void(__fastcall*)(void*, void*, void*, T_AKKGBKCGGNB, void*), 144, true>;

// ---------------------------------------------------------------- #145
// public virtual Void OnDisconnect() { }
// RVA 0x0ea6e3b0
static const FnDesc kD145 = {
    "OnDisconnect", "public virtual Void OnDisconnect() { }", "Void", 0x0ea6e3b0u, 0, 0, nullptr
};
using H145 = HookSlot<void(__fastcall*)(void*), 145, true>;

// ---------------------------------------------------------------- #146
// public AsyncJob AKFFNIKOFAE(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6e3f0
static const ParamDesc kP146[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD146 = {
    "AKFFNIKOFAE", "public AsyncJob AKFFNIKOFAE(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6e3f0u, 2, 3, kP146
};
using H146 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 146, true>;

// ---------------------------------------------------------------- #147
// public virtual Boolean CLPNFEMGEME() { }
// RVA 0x0ea6e4f0
static const FnDesc kD147 = {
    "CLPNFEMGEME", "public virtual Boolean CLPNFEMGEME() { }", "Boolean", 0x0ea6e4f0u, 0, 1, nullptr
};
using H147 = HookSlot<bool(__fastcall*)(void*), 147, true>;

// ---------------------------------------------------------------- #148
// public Void FJDMJPJKJLF(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6e5c0
static const ParamDesc kP148[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD148 = {
    "FJDMJPJKJLF", "public Void FJDMJPJKJLF(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6e5c0u, 2, 0, kP148
};
using H148 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 148, true>;

// ---------------------------------------------------------------- #149
// public Void IHALELPCCMC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6e660
static const ParamDesc kP149[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD149 = {
    "IHALELPCCMC", "public Void IHALELPCCMC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6e660u, 2, 0, kP149
};
using H149 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 149, true>;

// ---------------------------------------------------------------- #150
// public Void EGGGGMHGHFG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea6e730
static const ParamDesc kP150[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD150 = {
    "EGGGGMHGHFG", "public Void EGGGGMHGHFG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea6e730u, 3, 0, kP150
};
using H150 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 150, true>;

// ---------------------------------------------------------------- #151
// public Sprite IBDKPFJAODE(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6e810
static const ParamDesc kP151[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD151 = {
    "IBDKPFJAODE", "public Sprite IBDKPFJAODE(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6e810u, 1, 1, kP151
};
using H151 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 151, true>;

// ---------------------------------------------------------------- #152
// protected Void JLMILMGBENH(System.String CHPMFAGOHPJ, System.Boolean OHEAKIDEKOG) { }
// RVA 0x0ea6e8d0
static const ParamDesc kP152[] = {
    { "CHPMFAGOHPJ", "String", 0 },
    { "OHEAKIDEKOG", "Boolean", 0 },
};
static const FnDesc kD152 = {
    "JLMILMGBENH", "protected Void JLMILMGBENH(System.String CHPMFAGOHPJ, System.Boolean OHEAKIDEKOG) { }", "Void", 0x0ea6e8d0u, 2, 0, kP152
};
using H152 = HookSlot<void(__fastcall*)(void*, Il2CppString*, bool), 152, true>;

// ---------------------------------------------------------------- #153
// public EIDAIBHGFDD[] LMLFHENMAON() { }
// RVA 0x0ea6eab0
static const FnDesc kD153 = {
    "LMLFHENMAON", "public EIDAIBHGFDD[] LMLFHENMAON() { }", "EIDAIBHGFDD[]", 0x0ea6eab0u, 0, 1, nullptr
};
using H153 = HookSlot<void*(__fastcall*)(void*), 153, true>;

// ---------------------------------------------------------------- #154
// public Boolean MBAPIEENJFA(EIDAIBHGFDD PBCFJMEEDMG) { }
// RVA 0x0ea6eb50
static const ParamDesc kP154[] = {
    { "PBCFJMEEDMG", "", 0 },
};
static const FnDesc kD154 = {
    "MBAPIEENJFA", "public Boolean MBAPIEENJFA(EIDAIBHGFDD PBCFJMEEDMG) { }", "Boolean", 0x0ea6eb50u, 1, 1, kP154
};
using H154 = HookSlot<bool(__fastcall*)(void*, const T_EIDAIBHGFDD*), 154, true>;

// ---------------------------------------------------------------- #155
// public virtual Void EFINHKNJJIH() { }
// RVA 0x0ea6ec40
static const FnDesc kD155 = {
    "EFINHKNJJIH", "public virtual Void EFINHKNJJIH() { }", "Void", 0x0ea6ec40u, 0, 0, nullptr
};
using H155 = HookSlot<void(__fastcall*)(void*), 155, true>;

// ---------------------------------------------------------------- #156
// public Void DGHJMHACCKO(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6ef80
static const ParamDesc kP156[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD156 = {
    "DGHJMHACCKO", "public Void DGHJMHACCKO(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6ef80u, 2, 0, kP156
};
using H156 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 156, true>;

// ---------------------------------------------------------------- #157
// public Void CJGIGLIGEED(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6f030
static const ParamDesc kP157[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD157 = {
    "CJGIGLIGEED", "public Void CJGIGLIGEED(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6f030u, 2, 0, kP157
};
using H157 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 157, true>;

// ---------------------------------------------------------------- #158
// private Void BNBBHKJPFCP() { }
// RVA 0x0ea6f100
static const FnDesc kD158 = {
    "BNBBHKJPFCP", "private Void BNBBHKJPFCP() { }", "Void", 0x0ea6f100u, 0, 0, nullptr
};
using H158 = HookSlot<void(__fastcall*)(void*), 158, true>;

// ---------------------------------------------------------------- #159
// public Void LJBCKLBHHAL(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6f4e0
static const ParamDesc kP159[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD159 = {
    "LJBCKLBHHAL", "public Void LJBCKLBHHAL(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6f4e0u, 2, 0, kP159
};
using H159 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 159, true>;

// ---------------------------------------------------------------- #160
// protected Single BEAEDIKLBPC() { }
// RVA 0x0ea65450
static const FnDesc kD160 = {
    "BEAEDIKLBPC", "protected Single BEAEDIKLBPC() { }", "Single", 0x0ea65450u, 0, 1, nullptr
};
using H160 = HookSlot<float(__fastcall*)(void*), 160, true>;

// ---------------------------------------------------------------- #161
// private Void OMDJGLMPEFM() { }
// RVA 0x0ea6b8c0
static const FnDesc kD161 = {
    "OMDJGLMPEFM", "private Void OMDJGLMPEFM() { }", "Void", 0x0ea6b8c0u, 0, 0, nullptr
};
using H161 = HookSlot<void(__fastcall*)(void*), 161, true>;

// ---------------------------------------------------------------- #162
// private BIKEJEKGCHG PHAAAKGEFDA(MoleMole.BaseContextComponent AEBGMHDPLFC) { }
// RVA 0x0ea6f5b0
static const ParamDesc kP162[] = {
    { "AEBGMHDPLFC", "BaseContextComponent", 0 },
};
static const FnDesc kD162 = {
    "PHAAAKGEFDA", "private BIKEJEKGCHG PHAAAKGEFDA(MoleMole.BaseContextComponent AEBGMHDPLFC) { }", "BIKEJEKGCHG", 0x0ea6f5b0u, 1, 1, kP162
};
using H162 = HookSlot<T_BIKEJEKGCHG(__fastcall*)(void*, void*), 162, true>;

// ---------------------------------------------------------------- #163
// public MonoJoypadUIModule CMBKKPLJOJO(System.String CAFIOOBGHIN) { }
// RVA 0x0ea6f740
static const ParamDesc kP163[] = {
    { "CAFIOOBGHIN", "String", 0 },
};
static const FnDesc kD163 = {
    "CMBKKPLJOJO", "public MonoJoypadUIModule CMBKKPLJOJO(System.String CAFIOOBGHIN) { }", "MonoJoypadUIModule", 0x0ea6f740u, 1, 1, kP163
};
using H163 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 163, true>;

// ---------------------------------------------------------------- #164
// public AsyncJob FNMGJIBFNDJ(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6f8e0
static const ParamDesc kP164[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD164 = {
    "FNMGJIBFNDJ", "public AsyncJob FNMGJIBFNDJ(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6f8e0u, 2, 3, kP164
};
using H164 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 164, true>;

// ---------------------------------------------------------------- #165
// public Void JMEFEEAKKCP(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea6f9a0
static const ParamDesc kP165[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD165 = {
    "JMEFEEAKKCP", "public Void JMEFEEAKKCP(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea6f9a0u, 2, 0, kP165
};
using H165 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 165, true>;

// ---------------------------------------------------------------- #166
// public virtual Boolean ANKOGBANBLC() { }
// RVA 0x0ea6fa70
static const FnDesc kD166 = {
    "ANKOGBANBLC", "public virtual Boolean ANKOGBANBLC() { }", "Boolean", 0x0ea6fa70u, 0, 1, nullptr
};
using H166 = HookSlot<bool(__fastcall*)(void*), 166, true>;

// ---------------------------------------------------------------- #167
// public virtual JOCMONMOJJD[] BIABDHJPGHE() { }
// RVA 0x0ea6fa80
static const FnDesc kD167 = {
    "BIABDHJPGHE", "public virtual JOCMONMOJJD[] BIABDHJPGHE() { }", "JOCMONMOJJD[]", 0x0ea6fa80u, 0, 1, nullptr
};
using H167 = HookSlot<void*(__fastcall*)(void*), 167, true>;

// ---------------------------------------------------------------- #168
// private Dictionary<Int32, ValueTuple<GameObject, Boolean, Boolean>> FGALNHFNMIF() { }
// RVA 0x0ea6faf0
static const FnDesc kD168 = {
    "FGALNHFNMIF", "private Dictionary<Int32, ValueTuple<GameObject, Boolean, Boolean>> FGALNHFNMIF() { }", "Dictionary<Int32, ValueTuple<GameObject, Boolean, Boolean>>", 0x0ea6faf0u, 0, 1, nullptr
};
using H168 = HookSlot<void*(__fastcall*)(void*), 168, true>;

// ---------------------------------------------------------------- #169
// public Void PCFPMDDAOAO(BJNGDBNCFPA GCHAFILKIPB) { }
// RVA 0x0ea6fbe0
static const ParamDesc kP169[] = {
    { "GCHAFILKIPB", "BJNGDBNCFPA", 0 },
};
static const FnDesc kD169 = {
    "PCFPMDDAOAO", "public Void PCFPMDDAOAO(BJNGDBNCFPA GCHAFILKIPB) { }", "Void", 0x0ea6fbe0u, 1, 0, kP169
};
using H169 = HookSlot<void(__fastcall*)(void*, T_BJNGDBNCFPA), 169, true>;

// ---------------------------------------------------------------- #170
// public Sprite LCIPCAMCNBL(System.String BHOAHJNPMGN) { }
// RVA 0x0ea6fdd0
static const ParamDesc kP170[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD170 = {
    "LCIPCAMCNBL", "public Sprite LCIPCAMCNBL(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea6fdd0u, 1, 1, kP170
};
using H170 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 170, true>;

// ---------------------------------------------------------------- #171
// protected Void MBNLEMAMGBG(MoleMole.BaseContextComponent IDDOJOJFBGF) { }
// RVA 0x0ea6d1b0
static const ParamDesc kP171[] = {
    { "IDDOJOJFBGF", "BaseContextComponent", 0 },
};
static const FnDesc kD171 = {
    "MBNLEMAMGBG", "protected Void MBNLEMAMGBG(MoleMole.BaseContextComponent IDDOJOJFBGF) { }", "Void", 0x0ea6d1b0u, 1, 0, kP171
};
using H171 = HookSlot<void(__fastcall*)(void*, void*), 171, true>;

// ---------------------------------------------------------------- #172
// public AsyncJob DAAEAHFOGGI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6fe60
static const ParamDesc kP172[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD172 = {
    "DAAEAHFOGGI", "public AsyncJob DAAEAHFOGGI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6fe60u, 2, 3, kP172
};
using H172 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 172, true>;

// ---------------------------------------------------------------- #173
// public AsyncJob EEJOCKLBHFH(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea6ff60
static const ParamDesc kP173[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD173 = {
    "EEJOCKLBHFH", "public AsyncJob EEJOCKLBHFH(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea6ff60u, 2, 3, kP173
};
using H173 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 173, true>;

// ---------------------------------------------------------------- #174
// public Boolean BPFLDFIJLPF() { }
// RVA 0x0ea70060
static const FnDesc kD174 = {
    "BPFLDFIJLPF", "public Boolean BPFLDFIJLPF() { }", "Boolean", 0x0ea70060u, 0, 1, nullptr
};
using H174 = HookSlot<bool(__fastcall*)(void*), 174, true>;

// ---------------------------------------------------------------- #175
// public Sprite BIIFNIJAKMP(System.String BHOAHJNPMGN) { }
// RVA 0x0ea700e0
static const ParamDesc kP175[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD175 = {
    "BIIFNIJAKMP", "public Sprite BIIFNIJAKMP(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea700e0u, 1, 1, kP175
};
using H175 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 175, true>;

// ---------------------------------------------------------------- #176
// public Void PFKLJJENPGB(MoleMole.MonoRightClickButton DBICHEBDBPA, UnityEngine.Events.UnityAction FKGGKMAKEPN, UnityEngine.Events.UnityAction CHMHHOOFNLH) { }
// RVA 0x0ea701a0
static const ParamDesc kP176[] = {
    { "DBICHEBDBPA", "MonoRightClickButton", 0 },
    { "FKGGKMAKEPN", "UnityAction", 0 },
    { "CHMHHOOFNLH", "UnityAction", 0 },
};
static const FnDesc kD176 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(MoleMole.MonoRightClickButton DBICHEBDBPA, UnityEngine.Events.UnityAction FKGGKMAKEPN, UnityEngine.Events.UnityAction CHMHHOOFNLH) { }", "Void", 0x0ea701a0u, 3, 0, kP176
};
using H176 = HookSlot<void(__fastcall*)(void*, void*, void*, void*), 176, true>;

// ---------------------------------------------------------------- #177
// protected Void FPFIMCDJIDJ(UnityEngine.GameObject FKJFLKANHNP) { }
// RVA 0x0ea70ac0
static const ParamDesc kP177[] = {
    { "FKJFLKANHNP", "GameObject", 0 },
};
static const FnDesc kD177 = {
    "FPFIMCDJIDJ", "protected Void FPFIMCDJIDJ(UnityEngine.GameObject FKJFLKANHNP) { }", "Void", 0x0ea70ac0u, 1, 0, kP177
};
using H177 = HookSlot<void(__fastcall*)(void*, void*), 177, true>;

// ---------------------------------------------------------------- #178
// public Void KJANFOLAKBN(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea70ad0
static const ParamDesc kP178[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD178 = {
    "KJANFOLAKBN", "public Void KJANFOLAKBN(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea70ad0u, 2, 0, kP178
};
using H178 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 178, true>;

// ---------------------------------------------------------------- #179
// public virtual Void LFACJGOMLJD(System.String[] BCCLKDGMAHC, System.String[] BAJKBGJOBJC, FDIKBDFDDEA[] DJEEELMEFCL) { }
// RVA 0x0ea70b70
static const ParamDesc kP179[] = {
    { "BCCLKDGMAHC", "String[]", 0 },
    { "BAJKBGJOBJC", "String[]", 0 },
    { "DJEEELMEFCL", "FDIKBDFDDEA[]", 0 },
};
static const FnDesc kD179 = {
    "LFACJGOMLJD", "public virtual Void LFACJGOMLJD(System.String[] BCCLKDGMAHC, System.String[] BAJKBGJOBJC, FDIKBDFDDEA[] DJEEELMEFCL) { }", "Void", 0x0ea70b70u, 3, 0, kP179
};
using H179 = HookSlot<void(__fastcall*)(void*, void*, void*, void*), 179, true>;

// ---------------------------------------------------------------- #180
// public Boolean DLMMOPEFBOL() { }
// RVA 0x0ea71050
static const FnDesc kD180 = {
    "DLMMOPEFBOL", "public Boolean DLMMOPEFBOL() { }", "Boolean", 0x0ea71050u, 0, 1, nullptr
};
using H180 = HookSlot<bool(__fastcall*)(void*), 180, true>;

// ---------------------------------------------------------------- #181
// public Sprite CEPJNGKHFGK(System.String NJIBPHJKOAD) { }
// RVA 0x0ea71060
static const ParamDesc kP181[] = {
    { "NJIBPHJKOAD", "String", 0 },
};
static const FnDesc kD181 = {
    "CEPJNGKHFGK", "public Sprite CEPJNGKHFGK(System.String NJIBPHJKOAD) { }", "Sprite", 0x0ea71060u, 1, 1, kP181
};
using H181 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 181, true>;

// ---------------------------------------------------------------- #182
// public Sprite LAPNEGKDLKI(System.String BHOAHJNPMGN) { }
// RVA 0x0ea71120
static const ParamDesc kP182[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD182 = {
    "LAPNEGKDLKI", "public Sprite LAPNEGKDLKI(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea71120u, 1, 1, kP182
};
using H182 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 182, true>;

// ---------------------------------------------------------------- #183
// public Sprite EENOLAMPFKF(System.String BHOAHJNPMGN) { }
// RVA 0x0ea711e0
static const ParamDesc kP183[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD183 = {
    "EENOLAMPFKF", "public Sprite EENOLAMPFKF(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea711e0u, 1, 1, kP183
};
using H183 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 183, true>;

// ---------------------------------------------------------------- #184
// public Void HHIFHIGAMOJ(UnityEngine.Transform GCOLEFDNHNO) { }
// RVA 0x0ea71270
static const ParamDesc kP184[] = {
    { "GCOLEFDNHNO", "Transform", 0 },
};
static const FnDesc kD184 = {
    "HHIFHIGAMOJ", "public Void HHIFHIGAMOJ(UnityEngine.Transform GCOLEFDNHNO) { }", "Void", 0x0ea71270u, 1, 0, kP184
};
using H184 = HookSlot<void(__fastcall*)(void*, void*), 184, true>;

// ---------------------------------------------------------------- #185
// protected Void NHPCKJJMHCJ() { }
// RVA 0x0ea71340
static const FnDesc kD185 = {
    "NHPCKJJMHCJ", "protected Void NHPCKJJMHCJ() { }", "Void", 0x0ea71340u, 0, 0, nullptr
};
using H185 = HookSlot<void(__fastcall*)(void*), 185, true>;

// ---------------------------------------------------------------- #186
// public Void DNDHKNGMEBE(System.String ENFMEBMIALK, System.String ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea71460
static const ParamDesc kP186[] = {
    { "ENFMEBMIALK", "String", 0 },
    { "ADEGLFPIMIA", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD186 = {
    "DNDHKNGMEBE", "public Void DNDHKNGMEBE(System.String ENFMEBMIALK, System.String ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea71460u, 3, 0, kP186
};
using H186 = HookSlot<void(__fastcall*)(void*, Il2CppString*, Il2CppString*, void*), 186, true>;

// ---------------------------------------------------------------- #187
// public String PHIEHDJFINJ() { }
// RVA 0x0ea714d0
static const FnDesc kD187 = {
    "PHIEHDJFINJ", "public String PHIEHDJFINJ() { }", "String", 0x0ea714d0u, 0, 1, nullptr
};
using H187 = HookSlot<Il2CppString*(__fastcall*)(void*), 187, true>;

// ---------------------------------------------------------------- #188
// public Void JBOCMCOBHFM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea71530
static const ParamDesc kP188[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD188 = {
    "JBOCMCOBHFM", "public Void JBOCMCOBHFM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea71530u, 2, 0, kP188
};
using H188 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 188, true>;

// ---------------------------------------------------------------- #189
// protected Int32 GOKHGILDLCE() { }
// RVA 0x0ea71600
static const FnDesc kD189 = {
    "GOKHGILDLCE", "protected Int32 GOKHGILDLCE() { }", "Int32", 0x0ea71600u, 0, 1, nullptr
};
using H189 = HookSlot<int32_t(__fastcall*)(void*), 189, true>;

// ---------------------------------------------------------------- #190
// public Void JNOMIKBCGMB(System.String ENFMEBMIALK, System.String ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea71610
static const ParamDesc kP190[] = {
    { "ENFMEBMIALK", "String", 0 },
    { "ADEGLFPIMIA", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD190 = {
    "JNOMIKBCGMB", "public Void JNOMIKBCGMB(System.String ENFMEBMIALK, System.String ADEGLFPIMIA, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea71610u, 3, 0, kP190
};
using H190 = HookSlot<void(__fastcall*)(void*, Il2CppString*, Il2CppString*, void*), 190, true>;

// ---------------------------------------------------------------- #191
// public Sprite NLCHDBPFOKN(System.String NPCGBCDNLKD) { }
// RVA 0x0ea716b0
static const ParamDesc kP191[] = {
    { "NPCGBCDNLKD", "String", 0 },
};
static const FnDesc kD191 = {
    "NLCHDBPFOKN", "public Sprite NLCHDBPFOKN(System.String NPCGBCDNLKD) { }", "Sprite", 0x0ea716b0u, 1, 1, kP191
};
using H191 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 191, true>;

// ---------------------------------------------------------------- #192
// private Void JOBKKKCKCFC() { }
// RVA 0x0ea71770
static const FnDesc kD192 = {
    "JOBKKKCKCFC", "private Void JOBKKKCKCFC() { }", "Void", 0x0ea71770u, 0, 0, nullptr
};
using H192 = HookSlot<void(__fastcall*)(void*), 192, true>;

// ---------------------------------------------------------------- #193
// protected virtual Void PMFGAGDCFFI() { }
// RVA 0x0ea71910
static const FnDesc kD193 = {
    "PMFGAGDCFFI", "protected virtual Void PMFGAGDCFFI() { }", "Void", 0x0ea71910u, 0, 0, nullptr
};
using H193 = HookSlot<void(__fastcall*)(void*), 193, true>;

// ---------------------------------------------------------------- #194
// public Boolean DEJAODKLDME() { }
// RVA 0x0ea71b20
static const FnDesc kD194 = {
    "DEJAODKLDME", "public Boolean DEJAODKLDME() { }", "Boolean", 0x0ea71b20u, 0, 1, nullptr
};
using H194 = HookSlot<bool(__fastcall*)(void*), 194, true>;

// ---------------------------------------------------------------- #195
// public Void JIPCMFKIIPG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea71b80
static const ParamDesc kP195[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD195 = {
    "JIPCMFKIIPG", "public Void JIPCMFKIIPG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea71b80u, 2, 0, kP195
};
using H195 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 195, true>;

// ---------------------------------------------------------------- #196
// protected Boolean DOMMJBGMBIL(EIDAIBHGFDD AAIGAMFPMGG) { }
// RVA 0x0ea71c50
static const ParamDesc kP196[] = {
    { "AAIGAMFPMGG", "", 0 },
};
static const FnDesc kD196 = {
    "DOMMJBGMBIL", "protected Boolean DOMMJBGMBIL(EIDAIBHGFDD AAIGAMFPMGG) { }", "Boolean", 0x0ea71c50u, 1, 1, kP196
};
using H196 = HookSlot<bool(__fastcall*)(void*, const T_EIDAIBHGFDD*), 196, true>;

// ---------------------------------------------------------------- #197
// public Coroutine ELGEDBGLOJK(System.Int32 JJJBPHLLFGA, System.Action FKGGKMAKEPN) { }
// RVA 0x0ea71e70
static const ParamDesc kP197[] = {
    { "JJJBPHLLFGA", "Int32", 0 },
    { "FKGGKMAKEPN", "Action", 0 },
};
static const FnDesc kD197 = {
    "ELGEDBGLOJK", "public Coroutine ELGEDBGLOJK(System.Int32 JJJBPHLLFGA, System.Action FKGGKMAKEPN) { }", "Coroutine", 0x0ea71e70u, 2, 1, kP197
};
using H197 = HookSlot<void*(__fastcall*)(void*, int32_t, void*), 197, true>;

// ---------------------------------------------------------------- #198
// protected virtual Void AOJOAADBNCP(CBEDPEAMKMK FKJFLKANHNP) { }
// RVA 0x0ea71ef0
static const ParamDesc kP198[] = {
    { "FKJFLKANHNP", "CBEDPEAMKMK", 0 },
};
static const FnDesc kD198 = {
    "AOJOAADBNCP", "protected virtual Void AOJOAADBNCP(CBEDPEAMKMK FKJFLKANHNP) { }", "Void", 0x0ea71ef0u, 1, 0, kP198
};
using H198 = HookSlot<void(__fastcall*)(void*, T_CBEDPEAMKMK), 198, true>;

// ---------------------------------------------------------------- #199
// protected Boolean KMBMCMBMAPA() { }
// RVA 0x0ea71f00
static const FnDesc kD199 = {
    "KMBMCMBMAPA", "protected Boolean KMBMCMBMAPA() { }", "Boolean", 0x0ea71f00u, 0, 1, nullptr
};
using H199 = HookSlot<bool(__fastcall*)(void*), 199, true>;

// ---------------------------------------------------------------- #200
// public Void FMCFNNPEHLE(GFJCNBMJPCH EANLLEAPANL, MoleMole.BaseContextComponent AGNPEANOGNA) { }
// RVA 0x0ea71f10
static const ParamDesc kP200[] = {
    { "EANLLEAPANL", "GFJCNBMJPCH", 0 },
    { "AGNPEANOGNA", "BaseContextComponent", 0 },
};
static const FnDesc kD200 = {
    "FMCFNNPEHLE", "public Void FMCFNNPEHLE(GFJCNBMJPCH EANLLEAPANL, MoleMole.BaseContextComponent AGNPEANOGNA) { }", "Void", 0x0ea71f10u, 2, 0, kP200
};
using H200 = HookSlot<void(__fastcall*)(void*, T_GFJCNBMJPCH, void*), 200, true>;

// ---------------------------------------------------------------- #201
// public Sprite CJLLPJPHGMP(System.UInt32 FOBDDCEFMIB) { }
// RVA 0x0ea722b0
static const ParamDesc kP201[] = {
    { "FOBDDCEFMIB", "UInt32", 0 },
};
static const FnDesc kD201 = {
    "CJLLPJPHGMP", "public Sprite CJLLPJPHGMP(System.UInt32 FOBDDCEFMIB) { }", "Sprite", 0x0ea722b0u, 1, 1, kP201
};
using H201 = HookSlot<void*(__fastcall*)(void*, uint32_t), 201, true>;

// ---------------------------------------------------------------- #202
// public Void EICIFOKBCIM(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }
// RVA 0x0ea72490
static const ParamDesc kP202[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "GCHAFILKIPB", "LACPHBBPHGE", 0 },
};
static const FnDesc kD202 = {
    "EICIFOKBCIM", "public Void EICIFOKBCIM(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }", "Void", 0x0ea72490u, 4, 0, kP202
};
using H202 = HookSlot<void(__fastcall*)(void*, void*, const T_AAOHKJCCPDL*, void*, T_LACPHBBPHGE), 202, true>;

// ---------------------------------------------------------------- #203
// public Void PFKLJJENPGB(UnityEngine.UI.Slider ICFGJMCEMMB, UnityEngine.Events.UnityAction<System.Single> FKGGKMAKEPN) { }
// RVA 0x0ea72600
static const ParamDesc kP203[] = {
    { "ICFGJMCEMMB", "Slider", 0 },
    { "FKGGKMAKEPN", "UnityAction<Single>", 0 },
};
static const FnDesc kD203 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(UnityEngine.UI.Slider ICFGJMCEMMB, UnityEngine.Events.UnityAction<System.Single> FKGGKMAKEPN) { }", "Void", 0x0ea72600u, 2, 0, kP203
};
using H203 = HookSlot<void(__fastcall*)(void*, void*, void*), 203, true>;

// ---------------------------------------------------------------- #204
// protected virtual Void CENIMPBONKB() { }
// RVA 0x0ea72980
static const FnDesc kD204 = {
    "CENIMPBONKB", "protected virtual Void CENIMPBONKB() { }", "Void", 0x0ea72980u, 0, 0, nullptr
};
using H204 = HookSlot<void(__fastcall*)(void*), 204, true>;

// ---------------------------------------------------------------- #205
// public virtual Void DIIBEOBJGLG() { }
// RVA 0x0ea729c0
static const FnDesc kD205 = {
    "DIIBEOBJGLG", "public virtual Void DIIBEOBJGLG() { }", "Void", 0x0ea729c0u, 0, 0, nullptr
};
using H205 = HookSlot<void(__fastcall*)(void*), 205, true>;

// ---------------------------------------------------------------- #206
// protected Boolean EIKABICOBPO() { }
// RVA 0x0ea72e40
static const FnDesc kD206 = {
    "EIKABICOBPO", "protected Boolean EIKABICOBPO() { }", "Boolean", 0x0ea72e40u, 0, 1, nullptr
};
using H206 = HookSlot<bool(__fastcall*)(void*), 206, true>;

// ---------------------------------------------------------------- #207
// private Boolean PDNKNNIDOCH(PGKFPMENDPA DIFFHADFKEA) { }
// RVA 0x0ea72e50
static const ParamDesc kP207[] = {
    { "DIFFHADFKEA", "PGKFPMENDPA", 0 },
};
static const FnDesc kD207 = {
    "PDNKNNIDOCH", "private Boolean PDNKNNIDOCH(PGKFPMENDPA DIFFHADFKEA) { }", "Boolean", 0x0ea72e50u, 1, 1, kP207
};
using H207 = HookSlot<bool(__fastcall*)(void*, void*), 207, true>;

// ---------------------------------------------------------------- #208
// public Void KLHEHAPIONI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea72fd0
static const ParamDesc kP208[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD208 = {
    "KLHEHAPIONI", "public Void KLHEHAPIONI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea72fd0u, 2, 0, kP208
};
using H208 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 208, true>;

// ---------------------------------------------------------------- #209
// public Void PKIEBOPPFCP() { }
// RVA 0x0ea73030
static const FnDesc kD209 = {
    "PKIEBOPPFCP", "public Void PKIEBOPPFCP() { }", "Void", 0x0ea73030u, 0, 0, nullptr
};
using H209 = HookSlot<void(__fastcall*)(void*), 209, true>;

// ---------------------------------------------------------------- #210
// public Sprite HNGKFCIPBKM(NHGHLAINJJB GMOMPNHBPOI) { }
// RVA 0x0ea730e0
static const ParamDesc kP210[] = {
    { "GMOMPNHBPOI", "NHGHLAINJJB", 0 },
};
static const FnDesc kD210 = {
    "HNGKFCIPBKM", "public Sprite HNGKFCIPBKM(NHGHLAINJJB GMOMPNHBPOI) { }", "Sprite", 0x0ea730e0u, 1, 1, kP210
};
using H210 = HookSlot<void*(__fastcall*)(void*, T_NHGHLAINJJB), 210, true>;

// ---------------------------------------------------------------- #211
// public Sprite EFINECBHCNM(System.String BHOAHJNPMGN) { }
// RVA 0x0ea73190
static const ParamDesc kP211[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD211 = {
    "EFINECBHCNM", "public Sprite EFINECBHCNM(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea73190u, 1, 1, kP211
};
using H211 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 211, true>;

// ---------------------------------------------------------------- #212
// public Void EBHEAKIGGLJ(UnityEngine.UI.InputField KPDDCDPOKHM) { }
// RVA 0x0ea73250
static const ParamDesc kP212[] = {
    { "KPDDCDPOKHM", "InputField", 0 },
};
static const FnDesc kD212 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(UnityEngine.UI.InputField KPDDCDPOKHM) { }", "Void", 0x0ea73250u, 1, 0, kP212
};
using H212 = HookSlot<void(__fastcall*)(void*, void*), 212, true>;

// ---------------------------------------------------------------- #213
// public virtual Boolean HandleInputActionEvent(EIDAIBHGFDD PBCFJMEEDMG) { }
// RVA 0x0ea73340
static const ParamDesc kP213[] = {
    { "PBCFJMEEDMG", "", 0 },
};
static const FnDesc kD213 = {
    "HandleInputActionEvent", "public virtual Boolean HandleInputActionEvent(EIDAIBHGFDD PBCFJMEEDMG) { }", "Boolean", 0x0ea73340u, 1, 1, kP213
};
using H213 = HookSlot<bool(__fastcall*)(void*, const T_EIDAIBHGFDD*), 213, true>;

// ---------------------------------------------------------------- #214
// public Void KEJKNCAJMBL(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea73c00
static const ParamDesc kP214[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD214 = {
    "KEJKNCAJMBL", "public Void KEJKNCAJMBL(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea73c00u, 2, 0, kP214
};
using H214 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 214, true>;

// ---------------------------------------------------------------- #215
// public Void EBHEAKIGGLJ(MoleMole.MonoRightClickButton DBICHEBDBPA) { }
// RVA 0x0ea73ce0
static const ParamDesc kP215[] = {
    { "DBICHEBDBPA", "MonoRightClickButton", 0 },
};
static const FnDesc kD215 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(MoleMole.MonoRightClickButton DBICHEBDBPA) { }", "Void", 0x0ea73ce0u, 1, 0, kP215
};
using H215 = HookSlot<void(__fastcall*)(void*, void*), 215, true>;

// ---------------------------------------------------------------- #216
// private Void LFLNBEHDENN() { }
// RVA 0x0ea73e50
static const FnDesc kD216 = {
    "LFLNBEHDENN", "private Void LFLNBEHDENN() { }", "Void", 0x0ea73e50u, 0, 0, nullptr
};
using H216 = HookSlot<void(__fastcall*)(void*), 216, true>;

// ---------------------------------------------------------------- #217
// private Void EBGNLMALDJM(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ HCFLIFHMCPH) { }
// RVA 0x0ea73f90
static const ParamDesc kP217[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "HCFLIFHMCPH", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD217 = {
    "EBGNLMALDJM", "private Void EBGNLMALDJM(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ HCFLIFHMCPH) { }", "Void", 0x0ea73f90u, 2, 0, kP217
};
using H217 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 217, true>;

// ---------------------------------------------------------------- #218
// public Sprite KIPJAIMJHKM(System.String BHOAHJNPMGN) { }
// RVA 0x0ea74060
static const ParamDesc kP218[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD218 = {
    "KIPJAIMJHKM", "public Sprite KIPJAIMJHKM(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea74060u, 1, 1, kP218
};
using H218 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 218, true>;

// ---------------------------------------------------------------- #219
// public Void EAMJPGDIKJG() { }
// RVA 0x0ea74120
static const FnDesc kD219 = {
    "EAMJPGDIKJG", "public Void EAMJPGDIKJG() { }", "Void", 0x0ea74120u, 0, 0, nullptr
};
using H219 = HookSlot<void(__fastcall*)(void*), 219, true>;

// ---------------------------------------------------------------- #220
// public Void LateTick() { }
// RVA 0x0ea74440
static const FnDesc kD220 = {
    "LateTick", "public Void LateTick() { }", "Void", 0x0ea74440u, 0, 0, nullptr
};
using H220 = HookSlot<void(__fastcall*)(void*), 220, true>;

// ---------------------------------------------------------------- #221
// public Sprite BAPHKMPBKOM(System.String BHOAHJNPMGN) { }
// RVA 0x0ea74510
static const ParamDesc kP221[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD221 = {
    "BAPHKMPBKOM", "public Sprite BAPHKMPBKOM(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea74510u, 1, 1, kP221
};
using H221 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 221, true>;

// ---------------------------------------------------------------- #222
// public Void JAOJOIDNGBP(OMHKNJLAFDO IOIDEPIBFJJ, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea745a0
static const ParamDesc kP222[] = {
    { "IOIDEPIBFJJ", "OMHKNJLAFDO", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD222 = {
    "JAOJOIDNGBP", "public Void JAOJOIDNGBP(OMHKNJLAFDO IOIDEPIBFJJ, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea745a0u, 2, 0, kP222
};
using H222 = HookSlot<void(__fastcall*)(void*, T_OMHKNJLAFDO, void*), 222, true>;

// ---------------------------------------------------------------- #223
// public Boolean ABLFHLGBIAM(MoleMole.MonoJoypadUIModule EKKJGFECKHO, LHJHCLDJMNI NCBHJPCFFAE, AAOHKJCCPDL JNHIKAPIIJH, NPMJBCIDIED AJGLMCNAFDG, AAOHKJCCPDL LGDNCBOKFGB, out AAOHKJCCPDL DNGNLPGENMB) { }
// RVA 0x0ea74600
static const ParamDesc kP223[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "NCBHJPCFFAE", "LHJHCLDJMNI", 0 },
    { "JNHIKAPIIJH", "", 0 },
    { "AJGLMCNAFDG", "NPMJBCIDIED", 0 },
    { "LGDNCBOKFGB", "", 0 },
    { "DNGNLPGENMB", "AAOHKJCCPDL", 1 },
};
static const FnDesc kD223 = {
    "ABLFHLGBIAM", "public Boolean ABLFHLGBIAM(MoleMole.MonoJoypadUIModule EKKJGFECKHO, LHJHCLDJMNI NCBHJPCFFAE, AAOHKJCCPDL JNHIKAPIIJH, NPMJBCIDIED AJGLMCNAFDG, AAOHKJCCPDL LGDNCBOKFGB, out AAOHKJCCPDL DNGNLPGENMB) { }", "Boolean", 0x0ea74600u, 6, 1, kP223
};
using H223 = HookSlot<bool(__fastcall*)(void*, void*, void*, const T_AAOHKJCCPDL*, T_NPMJBCIDIED, const T_AAOHKJCCPDL*, OutRef<T_AAOHKJCCPDL>), 223, true>;

// ---------------------------------------------------------------- #224
// public virtual Void CEIOCOBHLKL() { }
// RVA 0x0ea74830
static const FnDesc kD224 = {
    "CEIOCOBHLKL", "public virtual Void CEIOCOBHLKL() { }", "Void", 0x0ea74830u, 0, 0, nullptr
};
using H224 = HookSlot<void(__fastcall*)(void*), 224, true>;

// ---------------------------------------------------------------- #225
// private Void HGLLAEFJNKE() { }
// RVA 0x0ea74990
static const FnDesc kD225 = {
    "HGLLAEFJNKE", "private Void HGLLAEFJNKE() { }", "Void", 0x0ea74990u, 0, 0, nullptr
};
using H225 = HookSlot<void(__fastcall*)(void*), 225, true>;

// ---------------------------------------------------------------- #226
// public Sprite ICBPBJFABPK(System.String BHOAHJNPMGN) { }
// RVA 0x0ea75170
static const ParamDesc kP226[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD226 = {
    "ICBPBJFABPK", "public Sprite ICBPBJFABPK(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea75170u, 1, 1, kP226
};
using H226 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 226, true>;

// ---------------------------------------------------------------- #227
// public virtual Void ONDACHNHJJF() { }
// RVA 0x0ea75230
static const FnDesc kD227 = {
    "ONDACHNHJJF", "public virtual Void ONDACHNHJJF() { }", "Void", 0x0ea75230u, 0, 0, nullptr
};
using H227 = HookSlot<void(__fastcall*)(void*), 227, true>;

// ---------------------------------------------------------------- #228
// private Void GKGFAEHBDDG(System.Boolean KPOLBFMOEAA) { }
// RVA 0x0ea75d90
static const ParamDesc kP228[] = {
    { "KPOLBFMOEAA", "Boolean", 0 },
};
static const FnDesc kD228 = {
    "GKGFAEHBDDG", "private Void GKGFAEHBDDG(System.Boolean KPOLBFMOEAA) { }", "Void", 0x0ea75d90u, 1, 0, kP228
};
using H228 = HookSlot<void(__fastcall*)(void*, bool), 228, true>;

// ---------------------------------------------------------------- #229
// public Void EBHEAKIGGLJ(UnityEngine.Transform GCOLEFDNHNO) { }
// RVA 0x0ea75fb0
static const ParamDesc kP229[] = {
    { "GCOLEFDNHNO", "Transform", 0 },
};
static const FnDesc kD229 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(UnityEngine.Transform GCOLEFDNHNO) { }", "Void", 0x0ea75fb0u, 1, 0, kP229
};
using H229 = HookSlot<void(__fastcall*)(void*, void*), 229, true>;

// ---------------------------------------------------------------- #230
// public virtual Void AGFGAEFONNM() { }
// RVA 0x0ea761c0
static const FnDesc kD230 = {
    "AGFGAEFONNM", "public virtual Void AGFGAEFONNM() { }", "Void", 0x0ea761c0u, 0, 0, nullptr
};
using H230 = HookSlot<void(__fastcall*)(void*), 230, true>;

// ---------------------------------------------------------------- #231
// public AsyncJob NAKEOCCBCCI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea762f0
static const ParamDesc kP231[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD231 = {
    "NAKEOCCBCCI", "public AsyncJob NAKEOCCBCCI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea762f0u, 2, 3, kP231
};
using H231 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 231, true>;

// ---------------------------------------------------------------- #232
// public Void AONHPIIDKME(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea763f0
static const ParamDesc kP232[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD232 = {
    "AONHPIIDKME", "public Void AONHPIIDKME(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea763f0u, 2, 0, kP232
};
using H232 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 232, true>;

// ---------------------------------------------------------------- #233
// protected virtual Void IHKHKDDMGMB() { }
// RVA 0x0ea764c0
static const FnDesc kD233 = {
    "IHKHKDDMGMB", "protected virtual Void IHKHKDDMGMB() { }", "Void", 0x0ea764c0u, 0, 0, nullptr
};
using H233 = HookSlot<void(__fastcall*)(void*), 233, true>;

// ---------------------------------------------------------------- #234
// public AsyncJob DNDHKNGMEBE(System.UInt64 ADEGLFPIMIA, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea76540
static const ParamDesc kP234[] = {
    { "ADEGLFPIMIA", "UInt64", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD234 = {
    "DNDHKNGMEBE", "public AsyncJob DNDHKNGMEBE(System.UInt64 ADEGLFPIMIA, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea76540u, 2, 3, kP234
};
using H234 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, uint64_t, void*), 234, true>;

// ---------------------------------------------------------------- #235
// protected Void LBCBAEJGGKN(System.Boolean FKJFLKANHNP) { }
// RVA 0x0ea765c0
static const ParamDesc kP235[] = {
    { "FKJFLKANHNP", "Boolean", 0 },
};
static const FnDesc kD235 = {
    "LBCBAEJGGKN", "protected Void LBCBAEJGGKN(System.Boolean FKJFLKANHNP) { }", "Void", 0x0ea765c0u, 1, 0, kP235
};
using H235 = HookSlot<void(__fastcall*)(void*, bool), 235, true>;

// ---------------------------------------------------------------- #236
// protected Void DIGEJNPBBDP() { }
// RVA 0x0ea765d0
static const FnDesc kD236 = {
    "DIGEJNPBBDP", "protected Void DIGEJNPBBDP() { }", "Void", 0x0ea765d0u, 0, 0, nullptr
};
using H236 = HookSlot<void(__fastcall*)(void*), 236, true>;

// ---------------------------------------------------------------- #237
// private Void BEEGKNJEAJM() { }
// RVA 0x0ea74b20
static const FnDesc kD237 = {
    "BEEGKNJEAJM", "private Void BEEGKNJEAJM() { }", "Void", 0x0ea74b20u, 0, 0, nullptr
};
using H237 = HookSlot<void(__fastcall*)(void*), 237, true>;

// ---------------------------------------------------------------- #238
// public Void LGCBADLPMMN(System.Boolean FBPFBFPHEIN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea76720
static const ParamDesc kP238[] = {
    { "FBPFBFPHEIN", "Boolean", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD238 = {
    "LGCBADLPMMN", "public Void LGCBADLPMMN(System.Boolean FBPFBFPHEIN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea76720u, 2, 0, kP238
};
using H238 = HookSlot<void(__fastcall*)(void*, bool, void*), 238, true>;

// ---------------------------------------------------------------- #239
// public Void HAODHNOENBD(BHIDJOHFING BBDFLHEKIEC, System.Boolean KPOLBFMOEAA, System.Nullable<EKAEMFGFEMJ> GCFDMPNHAAC) { }
// RVA 0x0ea767d0
static const ParamDesc kP239[] = {
    { "BBDFLHEKIEC", "BHIDJOHFING", 0 },
    { "KPOLBFMOEAA", "Boolean", 0 },
    { "GCFDMPNHAAC", "Nullable<EKAEMFGFEMJ>", 0 },
};
static const FnDesc kD239 = {
    "HAODHNOENBD", "public Void HAODHNOENBD(BHIDJOHFING BBDFLHEKIEC, System.Boolean KPOLBFMOEAA, System.Nullable<EKAEMFGFEMJ> GCFDMPNHAAC) { }", "Void", 0x0ea767d0u, 3, 0, kP239
};
using H239 = HookSlot<void(__fastcall*)(void*, void*, bool, void*), 239, true>;

// ---------------------------------------------------------------- #240
// public Void BGNNGJMHGEC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea76970
static const ParamDesc kP240[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD240 = {
    "BGNNGJMHGEC", "public Void BGNNGJMHGEC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea76970u, 2, 0, kP240
};
using H240 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 240, true>;

// ---------------------------------------------------------------- #241
// public Boolean AIEFAOLHJBC() { }
// RVA 0x0ea76a40
static const FnDesc kD241 = {
    "AIEFAOLHJBC", "public Boolean AIEFAOLHJBC() { }", "Boolean", 0x0ea76a40u, 0, 1, nullptr
};
using H241 = HookSlot<bool(__fastcall*)(void*), 241, true>;

// ---------------------------------------------------------------- #242
// private Void CFHJONMJFDI() { }
// RVA 0x0ea74930
static const FnDesc kD242 = {
    "CFHJONMJFDI", "private Void CFHJONMJFDI() { }", "Void", 0x0ea74930u, 0, 0, nullptr
};
using H242 = HookSlot<void(__fastcall*)(void*), 242, true>;

// ---------------------------------------------------------------- #243
// public AsyncJob LMEEKJDJPLL(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea76a50
static const ParamDesc kP243[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD243 = {
    "LMEEKJDJPLL", "public AsyncJob LMEEKJDJPLL(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea76a50u, 2, 3, kP243
};
using H243 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 243, true>;

// ---------------------------------------------------------------- #244
// public Void KEGHFBHIGEH() { }
// RVA 0x0ea76b50
static const FnDesc kD244 = {
    "KEGHFBHIGEH", "public Void KEGHFBHIGEH() { }", "Void", 0x0ea76b50u, 0, 0, nullptr
};
using H244 = HookSlot<void(__fastcall*)(void*), 244, true>;

// ---------------------------------------------------------------- #245
// public Sprite FFKLEIJDIGD(System.String BHOAHJNPMGN) { }
// RVA 0x0ea76d50
static const ParamDesc kP245[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD245 = {
    "FFKLEIJDIGD", "public Sprite FFKLEIJDIGD(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea76d50u, 1, 1, kP245
};
using H245 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 245, true>;

// ---------------------------------------------------------------- #246
// public Sprite MEOGOCFMDFO(System.String BHOAHJNPMGN) { }
// RVA 0x0ea76e10
static const ParamDesc kP246[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD246 = {
    "MEOGOCFMDFO", "public Sprite MEOGOCFMDFO(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea76e10u, 1, 1, kP246
};
using H246 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 246, true>;

// ---------------------------------------------------------------- #247
// public Void LDCEKLIJFKA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea76ea0
static const ParamDesc kP247[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD247 = {
    "LDCEKLIJFKA", "public Void LDCEKLIJFKA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea76ea0u, 3, 0, kP247
};
using H247 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 247, true>;

// ---------------------------------------------------------------- #248
// protected Boolean AKMIBKPHNLE(MoleMole.MonoControlElement NFOEGFAMDAL, DAIDPONIGDD ILHMOGEEHIC) { }
// RVA 0x0ea76f80
static const ParamDesc kP248[] = {
    { "NFOEGFAMDAL", "MonoControlElement", 0 },
    { "ILHMOGEEHIC", "DAIDPONIGDD", 0 },
};
static const FnDesc kD248 = {
    "AKMIBKPHNLE", "protected Boolean AKMIBKPHNLE(MoleMole.MonoControlElement NFOEGFAMDAL, DAIDPONIGDD ILHMOGEEHIC) { }", "Boolean", 0x0ea76f80u, 2, 1, kP248
};
using H248 = HookSlot<bool(__fastcall*)(void*, void*, T_DAIDPONIGDD), 248, true>;

// ---------------------------------------------------------------- #249
// public Sprite BFHDECIPFEI(System.String BHOAHJNPMGN) { }
// RVA 0x0ea77260
static const ParamDesc kP249[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD249 = {
    "BFHDECIPFEI", "public Sprite BFHDECIPFEI(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea77260u, 1, 1, kP249
};
using H249 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 249, true>;

// ---------------------------------------------------------------- #250
// public Void AMELIOEJKPK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean IMIOCPNAPLO) { }
// RVA 0x0ea772f0
static const ParamDesc kP250[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "IMIOCPNAPLO", "Boolean", 0 },
};
static const FnDesc kD250 = {
    "AMELIOEJKPK", "public Void AMELIOEJKPK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean IMIOCPNAPLO) { }", "Void", 0x0ea772f0u, 3, 0, kP250
};
using H250 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 250, true>;

// ---------------------------------------------------------------- #251
// private Void PIGMPOPGPOA() { }
// RVA 0x0ea77360
static const FnDesc kD251 = {
    "PIGMPOPGPOA", "private Void PIGMPOPGPOA() { }", "Void", 0x0ea77360u, 0, 0, nullptr
};
using H251 = HookSlot<void(__fastcall*)(void*), 251, true>;

// ---------------------------------------------------------------- #252
// public Void CCGKOHALCHM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea77760
static const ParamDesc kP252[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD252 = {
    "CCGKOHALCHM", "public Void CCGKOHALCHM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea77760u, 2, 0, kP252
};
using H252 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 252, true>;

// ---------------------------------------------------------------- #253
// public Sprite AGCGGMNGKLJ(System.String BHOAHJNPMGN) { }
// RVA 0x0ea771d0
static const ParamDesc kP253[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD253 = {
    "AGCGGMNGKLJ", "public Sprite AGCGGMNGKLJ(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea771d0u, 1, 1, kP253
};
using H253 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 253, true>;

// ---------------------------------------------------------------- #254
// public virtual Boolean EDBGEPEHDBL() { }
// RVA 0x0ea77830
static const FnDesc kD254 = {
    "EDBGEPEHDBL", "public virtual Boolean EDBGEPEHDBL() { }", "Boolean", 0x0ea77830u, 0, 1, nullptr
};
using H254 = HookSlot<bool(__fastcall*)(void*), 254, true>;

// ---------------------------------------------------------------- #255
// protected Void EOFBLKPIIJA(System.Int32 FKJFLKANHNP) { }
// RVA 0x0ea77840
static const ParamDesc kP255[] = {
    { "FKJFLKANHNP", "Int32", 0 },
};
static const FnDesc kD255 = {
    "EOFBLKPIIJA", "protected Void EOFBLKPIIJA(System.Int32 FKJFLKANHNP) { }", "Void", 0x0ea77840u, 1, 0, kP255
};
using H255 = HookSlot<void(__fastcall*)(void*, int32_t), 255, true>;

// ---------------------------------------------------------------- #256
// public virtual Void OnJoypadUIModuleFocus(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }
// RVA 0x0ea77b40
static const ParamDesc kP256[] = {
    { "LAINJKDPDBF", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD256 = {
    "OnJoypadUIModuleFocus", "public virtual Void OnJoypadUIModuleFocus(MoleMole.MonoJoypadUIModule LAINJKDPDBF) { }", "Void", 0x0ea77b40u, 1, 0, kP256
};
using H256 = HookSlot<void(__fastcall*)(void*, void*), 256, true>;

// ---------------------------------------------------------------- #257
// public Void BAPLIAJAHHG(System.String ENFMEBMIALK, BHIDJOHFING OBIBFIFNCLL) { }
// RVA 0x0ea77b90
static const ParamDesc kP257[] = {
    { "ENFMEBMIALK", "String", 0 },
    { "OBIBFIFNCLL", "BHIDJOHFING", 0 },
};
static const FnDesc kD257 = {
    "BAPLIAJAHHG", "public Void BAPLIAJAHHG(System.String ENFMEBMIALK, BHIDJOHFING OBIBFIFNCLL) { }", "Void", 0x0ea77b90u, 2, 0, kP257
};
using H257 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 257, true>;

// ---------------------------------------------------------------- #258
// public Void DHMAHDLCPDK(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea77c70
static const ParamDesc kP258[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD258 = {
    "DHMAHDLCPDK", "public Void DHMAHDLCPDK(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea77c70u, 2, 0, kP258
};
using H258 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 258, true>;

// ---------------------------------------------------------------- #259
// protected Void KPCBGLKOLDJ() { }
// RVA 0x0ea77ff0
static const FnDesc kD259 = {
    "KPCBGLKOLDJ", "protected Void KPCBGLKOLDJ() { }", "Void", 0x0ea77ff0u, 0, 0, nullptr
};
using H259 = HookSlot<void(__fastcall*)(void*), 259, true>;

// ---------------------------------------------------------------- #260
// public Void IPIGDAJKLED(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea780c0
static const ParamDesc kP260[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD260 = {
    "IPIGDAJKLED", "public Void IPIGDAJKLED(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea780c0u, 2, 0, kP260
};
using H260 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 260, true>;

// ---------------------------------------------------------------- #261
// public Void EKAADFCOPBI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea78160
static const ParamDesc kP261[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD261 = {
    "EKAADFCOPBI", "public Void EKAADFCOPBI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea78160u, 2, 0, kP261
};
using H261 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 261, true>;

// ---------------------------------------------------------------- #262
// public Void HBLHMHDHMGG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea78240
static const ParamDesc kP262[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD262 = {
    "HBLHMHDHMGG", "public Void HBLHMHDHMGG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea78240u, 2, 0, kP262
};
using H262 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 262, true>;

// ---------------------------------------------------------------- #263
// public GameObject KJOMHGIALGJ() { }
// RVA 0x0ea78310
static const FnDesc kD263 = {
    "KJOMHGIALGJ", "public GameObject KJOMHGIALGJ() { }", "GameObject", 0x0ea78310u, 0, 1, nullptr
};
using H263 = HookSlot<void*(__fastcall*)(void*), 263, true>;

// ---------------------------------------------------------------- #264
// public AsyncJob CAINHIHFKMC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea78320
static const ParamDesc kP264[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD264 = {
    "CAINHIHFKMC", "public AsyncJob CAINHIHFKMC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea78320u, 2, 3, kP264
};
using H264 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 264, true>;

// ---------------------------------------------------------------- #265
// public virtual Void JKKAKNEBBGG() { }
// RVA 0x0ea78420
static const FnDesc kD265 = {
    "JKKAKNEBBGG", "public virtual Void JKKAKNEBBGG() { }", "Void", 0x0ea78420u, 0, 0, nullptr
};
using H265 = HookSlot<void(__fastcall*)(void*), 265, true>;

// ---------------------------------------------------------------- #266
// private Void BMAAPLIOFAO() { }
// RVA 0x0ea78460
static const FnDesc kD266 = {
    "BMAAPLIOFAO", "private Void BMAAPLIOFAO() { }", "Void", 0x0ea78460u, 0, 0, nullptr
};
using H266 = HookSlot<void(__fastcall*)(void*), 266, true>;

// ---------------------------------------------------------------- #267
// public Void OEDDHIEHOJF() { }
// RVA 0x0ea78520
static const FnDesc kD267 = {
    "OEDDHIEHOJF", "public Void OEDDHIEHOJF() { }", "Void", 0x0ea78520u, 0, 0, nullptr
};
using H267 = HookSlot<void(__fastcall*)(void*), 267, true>;

// ---------------------------------------------------------------- #268
// public Void AKFFNIKOFAE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea78640
static const ParamDesc kP268[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD268 = {
    "AKFFNIKOFAE", "public Void AKFFNIKOFAE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea78640u, 2, 0, kP268
};
using H268 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 268, true>;

// ---------------------------------------------------------------- #269
// public Boolean LMIGHFJDDLK() { }
// RVA 0x0ea78710
static const FnDesc kD269 = {
    "LMIGHFJDDLK", "public Boolean LMIGHFJDDLK() { }", "Boolean", 0x0ea78710u, 0, 1, nullptr
};
using H269 = HookSlot<bool(__fastcall*)(void*), 269, true>;

// ---------------------------------------------------------------- #270
// private Void OPJLBJOMLLF() { }
// RVA 0x0ea75aa0
static const FnDesc kD270 = {
    "OPJLBJOMLLF", "private Void OPJLBJOMLLF() { }", "Void", 0x0ea75aa0u, 0, 0, nullptr
};
using H270 = HookSlot<void(__fastcall*)(void*), 270, true>;

// ---------------------------------------------------------------- #271
// private Boolean HOOFBMBJEJF(EIDAIBHGFDD AAIGAMFPMGG) { }
// RVA 0x0ea78770
static const ParamDesc kP271[] = {
    { "AAIGAMFPMGG", "", 0 },
};
static const FnDesc kD271 = {
    "HOOFBMBJEJF", "private Boolean HOOFBMBJEJF(EIDAIBHGFDD AAIGAMFPMGG) { }", "Boolean", 0x0ea78770u, 1, 1, kP271
};
using H271 = HookSlot<bool(__fastcall*)(void*, const T_EIDAIBHGFDD*), 271, true>;

// ---------------------------------------------------------------- #272
// public AsyncJob LJBCKLBHHAL(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea78970
static const ParamDesc kP272[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD272 = {
    "LJBCKLBHHAL", "public AsyncJob LJBCKLBHHAL(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea78970u, 2, 3, kP272
};
using H272 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 272, true>;

// ---------------------------------------------------------------- #273
// protected Boolean NAGNAAKANHC(MoleMole.Notify CNMPOFACGDF) { }
// RVA 0x0ea78a70
static const ParamDesc kP273[] = {
    { "CNMPOFACGDF", "", 0 },
};
static const FnDesc kD273 = {
    "NAGNAAKANHC", "protected Boolean NAGNAAKANHC(MoleMole.Notify CNMPOFACGDF) { }", "Boolean", 0x0ea78a70u, 1, 1, kP273
};
using H273 = HookSlot<bool(__fastcall*)(void*, const T_MoleMole_Notify*), 273, true>;

// ---------------------------------------------------------------- #274
// public Void FAHHLJOFGOI(System.Boolean JOHFELEJADF) { }
// RVA 0x0ea78d20
static const ParamDesc kP274[] = {
    { "JOHFELEJADF", "Boolean", 0 },
};
static const FnDesc kD274 = {
    "FAHHLJOFGOI", "public Void FAHHLJOFGOI(System.Boolean JOHFELEJADF) { }", "Void", 0x0ea78d20u, 1, 0, kP274
};
using H274 = HookSlot<void(__fastcall*)(void*, bool), 274, true>;

// ---------------------------------------------------------------- #275
// public Sprite OILLMLJHJMH(System.String BHOAHJNPMGN) { }
// RVA 0x0ea78fa0
static const ParamDesc kP275[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD275 = {
    "OILLMLJHJMH", "public Sprite OILLMLJHJMH(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea78fa0u, 1, 1, kP275
};
using H275 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 275, true>;

// ---------------------------------------------------------------- #276
// public Sprite HMFICOFGIAM(System.String BHOAHJNPMGN) { }
// RVA 0x0ea79060
static const ParamDesc kP276[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD276 = {
    "HMFICOFGIAM", "public Sprite HMFICOFGIAM(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea79060u, 1, 1, kP276
};
using H276 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 276, true>;

// ---------------------------------------------------------------- #277
// private Boolean BINBPDMAPNO(UnityEngine.Events.UnityEventBase PFFENFNPNFM) { }
// RVA 0x0ea707a0
static const ParamDesc kP277[] = {
    { "PFFENFNPNFM", "UnityEventBase", 0 },
};
static const FnDesc kD277 = {
    "BINBPDMAPNO", "private Boolean BINBPDMAPNO(UnityEngine.Events.UnityEventBase PFFENFNPNFM) { }", "Boolean", 0x0ea707a0u, 1, 1, kP277
};
using H277 = HookSlot<bool(__fastcall*)(void*, void*), 277, true>;

// ---------------------------------------------------------------- #278
// public Void IIPJBCELNMB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea79120
static const ParamDesc kP278[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD278 = {
    "IIPJBCELNMB", "public Void IIPJBCELNMB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea79120u, 2, 0, kP278
};
using H278 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 278, true>;

// ---------------------------------------------------------------- #279
// private Void MFMEEDIBCMK() { }
// RVA 0x0ea791c0
static const FnDesc kD279 = {
    "MFMEEDIBCMK", "private Void MFMEEDIBCMK() { }", "Void", 0x0ea791c0u, 0, 0, nullptr
};
using H279 = HookSlot<void(__fastcall*)(void*), 279, true>;

// ---------------------------------------------------------------- #280
// public Void LHFLEIILGDO(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea792e0
static const ParamDesc kP280[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD280 = {
    "LHFLEIILGDO", "public Void LHFLEIILGDO(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea792e0u, 2, 0, kP280
};
using H280 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 280, true>;

// ---------------------------------------------------------------- #281
// public AsyncJob EDANFBDGDHM(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea79380
static const ParamDesc kP281[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD281 = {
    "EDANFBDGDHM", "public AsyncJob EDANFBDGDHM(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea79380u, 2, 3, kP281
};
using H281 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 281, true>;

// ---------------------------------------------------------------- #282
// public Void EKEDONCLLPF(MoleMole.MonoUIContainer DMNMHJLDNLA) { }
// RVA 0x0ea79400
static const ParamDesc kP282[] = {
    { "DMNMHJLDNLA", "MonoUIContainer", 0 },
};
static const FnDesc kD282 = {
    "EKEDONCLLPF", "public Void EKEDONCLLPF(MoleMole.MonoUIContainer DMNMHJLDNLA) { }", "Void", 0x0ea79400u, 1, 0, kP282
};
using H282 = HookSlot<void(__fastcall*)(void*, void*), 282, true>;

// ---------------------------------------------------------------- #283
// public Void PDHFPKJDDJD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea795d0
static const ParamDesc kP283[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD283 = {
    "PDHFPKJDDJD", "public Void PDHFPKJDDJD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea795d0u, 2, 0, kP283
};
using H283 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 283, true>;

// ---------------------------------------------------------------- #284
// private EIDAIBHGFDD[] JPDOFMGKMMA(System.Int32 BNKMHOBGJOE, System.Nullable<EKAEMFGFEMJ> MOLHIMPEPOL) { }
// RVA 0x0ea778c0
static const ParamDesc kP284[] = {
    { "BNKMHOBGJOE", "Int32", 0 },
    { "MOLHIMPEPOL", "Nullable<EKAEMFGFEMJ>", 0 },
};
static const FnDesc kD284 = {
    "JPDOFMGKMMA", "private EIDAIBHGFDD[] JPDOFMGKMMA(System.Int32 BNKMHOBGJOE, System.Nullable<EKAEMFGFEMJ> MOLHIMPEPOL) { }", "EIDAIBHGFDD[]", 0x0ea778c0u, 2, 1, kP284
};
using H284 = HookSlot<void*(__fastcall*)(void*, int32_t, void*), 284, true>;

// ---------------------------------------------------------------- #285
// protected virtual Void DLLHMNOPPOJ(UnityEngine.GameObject LIGJDLDGGIO) { }
// RVA 0x0ea796a0
static const ParamDesc kP285[] = {
    { "LIGJDLDGGIO", "GameObject", 0 },
};
static const FnDesc kD285 = {
    "DLLHMNOPPOJ", "protected virtual Void DLLHMNOPPOJ(UnityEngine.GameObject LIGJDLDGGIO) { }", "Void", 0x0ea796a0u, 1, 0, kP285
};
using H285 = HookSlot<void(__fastcall*)(void*, void*), 285, true>;

// ---------------------------------------------------------------- #286
// private Void DCAHBFJEEMC() { }
// RVA 0x0ea78580
static const FnDesc kD286 = {
    "DCAHBFJEEMC", "private Void DCAHBFJEEMC() { }", "Void", 0x0ea78580u, 0, 0, nullptr
};
using H286 = HookSlot<void(__fastcall*)(void*), 286, true>;

// ---------------------------------------------------------------- #287
// public AsyncJob JIPCMFKIIPG(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea79cf0
static const ParamDesc kP287[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD287 = {
    "JIPCMFKIIPG", "public AsyncJob JIPCMFKIIPG(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea79cf0u, 2, 3, kP287
};
using H287 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 287, true>;

// ---------------------------------------------------------------- #288
// public AsyncJob CJOAECFBIHP(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea79df0
static const ParamDesc kP288[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD288 = {
    "CJOAECFBIHP", "public AsyncJob CJOAECFBIHP(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea79df0u, 2, 3, kP288
};
using H288 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 288, true>;

// ---------------------------------------------------------------- #289
// public Void PALGNLMDLLA(MoleMole.MonoControlElement NFOEGFAMDAL, DAIDPONIGDD ILHMOGEEHIC) { }
// RVA 0x0ea79eb0
static const ParamDesc kP289[] = {
    { "NFOEGFAMDAL", "MonoControlElement", 0 },
    { "ILHMOGEEHIC", "DAIDPONIGDD", 0 },
};
static const FnDesc kD289 = {
    "PALGNLMDLLA", "public Void PALGNLMDLLA(MoleMole.MonoControlElement NFOEGFAMDAL, DAIDPONIGDD ILHMOGEEHIC) { }", "Void", 0x0ea79eb0u, 2, 0, kP289
};
using H289 = HookSlot<void(__fastcall*)(void*, void*, T_DAIDPONIGDD), 289, true>;

// ---------------------------------------------------------------- #290
// public Boolean GKICFOCHODL(PGKFPMENDPA DIFFHADFKEA) { }
// RVA 0x0ea78ca0
static const ParamDesc kP290[] = {
    { "DIFFHADFKEA", "PGKFPMENDPA", 0 },
};
static const FnDesc kD290 = {
    "GKICFOCHODL", "public Boolean GKICFOCHODL(PGKFPMENDPA DIFFHADFKEA) { }", "Boolean", 0x0ea78ca0u, 1, 1, kP290
};
using H290 = HookSlot<bool(__fastcall*)(void*, void*), 290, true>;

// ---------------------------------------------------------------- #291
// public Boolean LEOAJBAICDD() { }
// RVA 0x0ea79f10
static const FnDesc kD291 = {
    "LEOAJBAICDD", "public Boolean LEOAJBAICDD() { }", "Boolean", 0x0ea79f10u, 0, 1, nullptr
};
using H291 = HookSlot<bool(__fastcall*)(void*), 291, true>;

// ---------------------------------------------------------------- #292
// public Void DOHMEPFDKBD(System.Boolean KPOLBFMOEAA) { }
// RVA 0x0ea79f20
static const ParamDesc kP292[] = {
    { "KPOLBFMOEAA", "Boolean", 0 },
};
static const FnDesc kD292 = {
    "DOHMEPFDKBD", "public Void DOHMEPFDKBD(System.Boolean KPOLBFMOEAA) { }", "Void", 0x0ea79f20u, 1, 0, kP292
};
using H292 = HookSlot<void(__fastcall*)(void*, bool), 292, true>;

// ---------------------------------------------------------------- #293
// public Sprite BDLHBKKJCLA(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7a330
static const ParamDesc kP293[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD293 = {
    "BDLHBKKJCLA", "public Sprite BDLHBKKJCLA(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7a330u, 1, 1, kP293
};
using H293 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 293, true>;

// ---------------------------------------------------------------- #294
// private BIKEJEKGCHG OIGBMLBFJMF(System.Type KENEAKCAJHI, System.Type HOGDBDEOPKM) { }
// RVA 0x0ea7a3f0
static const ParamDesc kP294[] = {
    { "KENEAKCAJHI", "Type", 0 },
    { "HOGDBDEOPKM", "Type", 0 },
};
static const FnDesc kD294 = {
    "OIGBMLBFJMF", "private BIKEJEKGCHG OIGBMLBFJMF(System.Type KENEAKCAJHI, System.Type HOGDBDEOPKM) { }", "BIKEJEKGCHG", 0x0ea7a3f0u, 2, 1, kP294
};
using H294 = HookSlot<T_BIKEJEKGCHG(__fastcall*)(void*, void*, void*), 294, true>;

// ---------------------------------------------------------------- #295
// protected Void DGCFNBENALF() { }
// RVA 0x0ea755b0
static const FnDesc kD295 = {
    "DGCFNBENALF", "protected Void DGCFNBENALF() { }", "Void", 0x0ea755b0u, 0, 0, nullptr
};
using H295 = HookSlot<void(__fastcall*)(void*), 295, true>;

// ---------------------------------------------------------------- #296
// public Void PFKLJJENPGB(MoleMole.MonoInputFieldExtention CDPMHHADOKK, System.Action FKGGKMAKEPN) { }
// RVA 0x0ea7a480
static const ParamDesc kP296[] = {
    { "CDPMHHADOKK", "MonoInputFieldExtention", 0 },
    { "FKGGKMAKEPN", "Action", 0 },
};
static const FnDesc kD296 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(MoleMole.MonoInputFieldExtention CDPMHHADOKK, System.Action FKGGKMAKEPN) { }", "Void", 0x0ea7a480u, 2, 0, kP296
};
using H296 = HookSlot<void(__fastcall*)(void*, void*, void*), 296, true>;

// ---------------------------------------------------------------- #297
// private Void NBHCBKDCFMK(KHBBEEOAPLC NKMFCEGILNB) { }
// RVA 0x0ea72c20
static const ParamDesc kP297[] = {
    { "NKMFCEGILNB", "KHBBEEOAPLC", 0 },
};
static const FnDesc kD297 = {
    "NBHCBKDCFMK", "private Void NBHCBKDCFMK(KHBBEEOAPLC NKMFCEGILNB) { }", "Void", 0x0ea72c20u, 1, 0, kP297
};
using H297 = HookSlot<void(__fastcall*)(void*, T_KHBBEEOAPLC), 297, true>;

// ---------------------------------------------------------------- #298
// public Void LGKEFMOILGK(UnityEngine.Transform GCOLEFDNHNO, System.UInt32 DPDAAMKMBHK, INKHFOHNGOF EANLLEAPANL, System.UInt32 OAEKBHJHIJJ) { }
// RVA 0x0ea7a570
static const ParamDesc kP298[] = {
    { "GCOLEFDNHNO", "Transform", 0 },
    { "DPDAAMKMBHK", "UInt32", 0 },
    { "EANLLEAPANL", "INKHFOHNGOF", 0 },
    { "OAEKBHJHIJJ", "UInt32", 0 },
};
static const FnDesc kD298 = {
    "LGKEFMOILGK", "public Void LGKEFMOILGK(UnityEngine.Transform GCOLEFDNHNO, System.UInt32 DPDAAMKMBHK, INKHFOHNGOF EANLLEAPANL, System.UInt32 OAEKBHJHIJJ) { }", "Void", 0x0ea7a570u, 4, 0, kP298
};
using H298 = HookSlot<void(__fastcall*)(void*, void*, uint32_t, T_INKHFOHNGOF, uint32_t), 298, true>;

// ---------------------------------------------------------------- #299
// public Void ODCAEOBMAJC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7a670
static const ParamDesc kP299[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD299 = {
    "ODCAEOBMAJC", "public Void ODCAEOBMAJC(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7a670u, 2, 0, kP299
};
using H299 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 299, true>;

// ---------------------------------------------------------------- #300
// public Sprite GDHBJHNCAEJ(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7a710
static const ParamDesc kP300[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD300 = {
    "GDHBJHNCAEJ", "public Sprite GDHBJHNCAEJ(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7a710u, 1, 1, kP300
};
using H300 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 300, true>;

// ---------------------------------------------------------------- #301
// public Void NLILPPDKFIF(MoleMole.MonoUIContainer DMNMHJLDNLA, UnityEngine.Events.UnityAction FKGGKMAKEPN) { }
// RVA 0x0ea7a7d0
static const ParamDesc kP301[] = {
    { "DMNMHJLDNLA", "MonoUIContainer", 0 },
    { "FKGGKMAKEPN", "UnityAction", 0 },
};
static const FnDesc kD301 = {
    "NLILPPDKFIF", "public Void NLILPPDKFIF(MoleMole.MonoUIContainer DMNMHJLDNLA, UnityEngine.Events.UnityAction FKGGKMAKEPN) { }", "Void", 0x0ea7a7d0u, 2, 0, kP301
};
using H301 = HookSlot<void(__fastcall*)(void*, void*, void*), 301, true>;

// ---------------------------------------------------------------- #302
// public AsyncJob BOKJELAOJGD(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7a8c0
static const ParamDesc kP302[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD302 = {
    "BOKJELAOJGD", "public AsyncJob BOKJELAOJGD(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7a8c0u, 2, 3, kP302
};
using H302 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 302, true>;

// ---------------------------------------------------------------- #303
// public Sprite HKDJFMPEDHK(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7a9c0
static const ParamDesc kP303[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD303 = {
    "HKDJFMPEDHK", "public Sprite HKDJFMPEDHK(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7a9c0u, 1, 1, kP303
};
using H303 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 303, true>;

// ---------------------------------------------------------------- #304
// public AsyncJob FNMKALPJNMB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7aa50
static const ParamDesc kP304[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD304 = {
    "FNMKALPJNMB", "public AsyncJob FNMKALPJNMB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7aa50u, 2, 3, kP304
};
using H304 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 304, true>;

// ---------------------------------------------------------------- #305
// public Boolean GOOIIJLHJPK() { }
// RVA 0x0ea7ab10
static const FnDesc kD305 = {
    "GOOIIJLHJPK", "public Boolean GOOIIJLHJPK() { }", "Boolean", 0x0ea7ab10u, 0, 1, nullptr
};
using H305 = HookSlot<bool(__fastcall*)(void*), 305, true>;

// ---------------------------------------------------------------- #306
// public Boolean JKAEDEDEGGI() { }
// RVA 0x0ea7ab70
static const FnDesc kD306 = {
    "JKAEDEDEGGI", "public Boolean JKAEDEDEGGI() { }", "Boolean", 0x0ea7ab70u, 0, 1, nullptr
};
using H306 = HookSlot<bool(__fastcall*)(void*), 306, true>;

// ---------------------------------------------------------------- #307
// public Boolean NLGDDFLMJLJ() { }
// RVA 0x0ea7abc0
static const FnDesc kD307 = {
    "NLGDDFLMJLJ", "public Boolean NLGDDFLMJLJ() { }", "Boolean", 0x0ea7abc0u, 0, 1, nullptr
};
using H307 = HookSlot<bool(__fastcall*)(void*), 307, true>;

// ---------------------------------------------------------------- #308
// public AsyncJob JDJFCKEGBPK(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7abd0
static const ParamDesc kP308[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD308 = {
    "JDJFCKEGBPK", "public AsyncJob JDJFCKEGBPK(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7abd0u, 2, 3, kP308
};
using H308 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 308, true>;

// ---------------------------------------------------------------- #309
// public AsyncJob FJDMJPJKJLF(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7ac90
static const ParamDesc kP309[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD309 = {
    "FJDMJPJKJLF", "public AsyncJob FJDMJPJKJLF(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7ac90u, 2, 3, kP309
};
using H309 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 309, true>;

// ---------------------------------------------------------------- #310
// protected virtual Void BindViewCallbacks() { }
// RVA 0x0ea7ad50
static const FnDesc kD310 = {
    "BindViewCallbacks", "protected virtual Void BindViewCallbacks() { }", "Void", 0x0ea7ad50u, 0, 0, nullptr
};
using H310 = HookSlot<void(__fastcall*)(void*), 310, true>;

// ---------------------------------------------------------------- #311
// private Boolean KHIHHICDLFC(PGKFPMENDPA DEALNIJJNGJ) { }
// RVA 0x0ea7ad90
static const ParamDesc kP311[] = {
    { "DEALNIJJNGJ", "PGKFPMENDPA", 0 },
};
static const FnDesc kD311 = {
    "KHIHHICDLFC", "private Boolean KHIHHICDLFC(PGKFPMENDPA DEALNIJJNGJ) { }", "Boolean", 0x0ea7ad90u, 1, 1, kP311
};
using H311 = HookSlot<bool(__fastcall*)(void*, void*), 311, true>;

// ---------------------------------------------------------------- #312
// public Void PFKLJJENPGB(MoleMole.MonoMultipleClickButton DBICHEBDBPA, UnityEngine.Events.UnityAction FJGHHEMOCCD, UnityEngine.Events.UnityAction NPNPHIMIOPE) { }
// RVA 0x0ea7aff0
static const ParamDesc kP312[] = {
    { "DBICHEBDBPA", "MonoMultipleClickButton", 0 },
    { "FJGHHEMOCCD", "UnityAction", 0 },
    { "NPNPHIMIOPE", "UnityAction", 0 },
};
static const FnDesc kD312 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(MoleMole.MonoMultipleClickButton DBICHEBDBPA, UnityEngine.Events.UnityAction FJGHHEMOCCD, UnityEngine.Events.UnityAction NPNPHIMIOPE) { }", "Void", 0x0ea7aff0u, 3, 0, kP312
};
using H312 = HookSlot<void(__fastcall*)(void*, void*, void*, void*), 312, true>;

// ---------------------------------------------------------------- #313
// protected Void EAAHOIDMFGI(System.Boolean FKJFLKANHNP) { }
// RVA 0x0ea7b5e0
static const ParamDesc kP313[] = {
    { "FKJFLKANHNP", "Boolean", 0 },
};
static const FnDesc kD313 = {
    "EAAHOIDMFGI", "protected Void EAAHOIDMFGI(System.Boolean FKJFLKANHNP) { }", "Void", 0x0ea7b5e0u, 1, 0, kP313
};
using H313 = HookSlot<void(__fastcall*)(void*, bool), 313, true>;

// ---------------------------------------------------------------- #314
// public BIKEJEKGCHG KAGOKBJLCNO() { }
// RVA 0x0ea7b5f0
static const FnDesc kD314 = {
    "KAGOKBJLCNO", "public BIKEJEKGCHG KAGOKBJLCNO() { }", "BIKEJEKGCHG", 0x0ea7b5f0u, 0, 1, nullptr
};
using H314 = HookSlot<T_BIKEJEKGCHG(__fastcall*)(void*), 314, true>;

// ---------------------------------------------------------------- #315
// public Sprite JMPNHDHDGIC(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7b600
static const ParamDesc kP315[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD315 = {
    "JMPNHDHDGIC", "public Sprite JMPNHDHDGIC(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7b600u, 1, 1, kP315
};
using H315 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 315, true>;

// ---------------------------------------------------------------- #316
// public Void LOGDPKODEIE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7b6c0
static const ParamDesc kP316[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD316 = {
    "LOGDPKODEIE", "public Void LOGDPKODEIE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7b6c0u, 2, 0, kP316
};
using H316 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 316, true>;

// ---------------------------------------------------------------- #317
// public Void EPPIMGOLDEO(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7b790
static const ParamDesc kP317[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD317 = {
    "EPPIMGOLDEO", "public Void EPPIMGOLDEO(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7b790u, 2, 0, kP317
};
using H317 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 317, true>;

// ---------------------------------------------------------------- #318
// protected virtual Void BDIJJDIHMEG() { }
// RVA 0x0ea7b860
static const FnDesc kD318 = {
    "BDIJJDIHMEG", "protected virtual Void BDIJJDIHMEG() { }", "Void", 0x0ea7b860u, 0, 0, nullptr
};
using H318 = HookSlot<void(__fastcall*)(void*), 318, true>;

// ---------------------------------------------------------------- #319
// public Sprite NNEOLJHINPF(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7bb00
static const ParamDesc kP319[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD319 = {
    "NNEOLJHINPF", "public Sprite NNEOLJHINPF(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7bb00u, 1, 1, kP319
};
using H319 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 319, true>;

// ---------------------------------------------------------------- #320
// private Void HBLBNMGDIAH() { }
// RVA 0x0ea75d30
static const FnDesc kD320 = {
    "HBLBNMGDIAH", "private Void HBLBNMGDIAH() { }", "Void", 0x0ea75d30u, 0, 0, nullptr
};
using H320 = HookSlot<void(__fastcall*)(void*), 320, true>;

// ---------------------------------------------------------------- #321
// public Void HHDNNLLEKHG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7bbc0
static const ParamDesc kP321[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD321 = {
    "HHDNNLLEKHG", "public Void HHDNNLLEKHG(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7bbc0u, 2, 0, kP321
};
using H321 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 321, true>;

// ---------------------------------------------------------------- #322
// public Boolean HLDOMEGMLOL(System.Collections.Generic.List<UnityEngine.GameObject> JFLDNBINFOI) { }
// RVA 0x0ea7bca0
static const ParamDesc kP322[] = {
    { "JFLDNBINFOI", "List<GameObject>", 0 },
};
static const FnDesc kD322 = {
    "HLDOMEGMLOL", "public Boolean HLDOMEGMLOL(System.Collections.Generic.List<UnityEngine.GameObject> JFLDNBINFOI) { }", "Boolean", 0x0ea7bca0u, 1, 1, kP322
};
using H322 = HookSlot<bool(__fastcall*)(void*, void*), 322, true>;

// ---------------------------------------------------------------- #323
// public Void LMEEKJDJPLL(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7bd10
static const ParamDesc kP323[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD323 = {
    "LMEEKJDJPLL", "public Void LMEEKJDJPLL(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7bd10u, 2, 0, kP323
};
using H323 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 323, true>;

// ---------------------------------------------------------------- #324
// public Void DAAEAHFOGGI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7bde0
static const ParamDesc kP324[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD324 = {
    "DAAEAHFOGGI", "public Void DAAEAHFOGGI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7bde0u, 2, 0, kP324
};
using H324 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 324, true>;

// ---------------------------------------------------------------- #325
// private Void ENGEMGNECIB() { }
// RVA 0x0ea75cc0
static const FnDesc kD325 = {
    "ENGEMGNECIB", "private Void ENGEMGNECIB() { }", "Void", 0x0ea75cc0u, 0, 0, nullptr
};
using H325 = HookSlot<void(__fastcall*)(void*), 325, true>;

// ---------------------------------------------------------------- #326
// protected Void AJJDMJKCGAG() { }
// RVA 0x0ea7bec0
static const FnDesc kD326 = {
    "AJJDMJKCGAG", "protected Void AJJDMJKCGAG() { }", "Void", 0x0ea7bec0u, 0, 0, nullptr
};
using H326 = HookSlot<void(__fastcall*)(void*), 326, true>;

// ---------------------------------------------------------------- #327
// private Void FLLGOANEIAD() { }
// RVA 0x0ea75530
static const FnDesc kD327 = {
    "FLLGOANEIAD", "private Void FLLGOANEIAD() { }", "Void", 0x0ea75530u, 0, 0, nullptr
};
using H327 = HookSlot<void(__fastcall*)(void*), 327, true>;

// ---------------------------------------------------------------- #328
// public Boolean LJPJBLJIPPP() { }
// RVA 0x0ea7bfc0
static const FnDesc kD328 = {
    "LJPJBLJIPPP", "public Boolean LJPJBLJIPPP() { }", "Boolean", 0x0ea7bfc0u, 0, 1, nullptr
};
using H328 = HookSlot<bool(__fastcall*)(void*), 328, true>;

// ---------------------------------------------------------------- #329
// public Void BNDOOMBNBIP(MoleMole.MonoJoypadNavRegionBase OPPHKACDBBN) { }
// RVA 0x0ea7bfd0
static const ParamDesc kP329[] = {
    { "OPPHKACDBBN", "MonoJoypadNavRegionBase", 0 },
};
static const FnDesc kD329 = {
    "BNDOOMBNBIP", "public Void BNDOOMBNBIP(MoleMole.MonoJoypadNavRegionBase OPPHKACDBBN) { }", "Void", 0x0ea7bfd0u, 1, 0, kP329
};
using H329 = HookSlot<void(__fastcall*)(void*, void*), 329, true>;

// ---------------------------------------------------------------- #330
// public UInt64 PJFEJDHEHGB(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7c0b0
static const ParamDesc kP330[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD330 = {
    "PJFEJDHEHGB", "public UInt64 PJFEJDHEHGB(System.String BHOAHJNPMGN) { }", "UInt64", 0x0ea7c0b0u, 1, 1, kP330
};
using H330 = HookSlot<uint64_t(__fastcall*)(void*, Il2CppString*), 330, true>;

// ---------------------------------------------------------------- #331
// private Void KLDCNBGECEI() { }
// RVA 0x0ea7c110
static const FnDesc kD331 = {
    "KLDCNBGECEI", "private Void KLDCNBGECEI() { }", "Void", 0x0ea7c110u, 0, 0, nullptr
};
using H331 = HookSlot<void(__fastcall*)(void*), 331, true>;

// ---------------------------------------------------------------- #332
// public Void NPEJDLMNHNM(GFJCNBMJPCH EANLLEAPANL, MoleMole.BaseContextComponent AGNPEANOGNA) { }
// RVA 0x0ea7c420
static const ParamDesc kP332[] = {
    { "EANLLEAPANL", "GFJCNBMJPCH", 0 },
    { "AGNPEANOGNA", "BaseContextComponent", 0 },
};
static const FnDesc kD332 = {
    "NPEJDLMNHNM", "public Void NPEJDLMNHNM(GFJCNBMJPCH EANLLEAPANL, MoleMole.BaseContextComponent AGNPEANOGNA) { }", "Void", 0x0ea7c420u, 2, 0, kP332
};
using H332 = HookSlot<void(__fastcall*)(void*, T_GFJCNBMJPCH, void*), 332, true>;

// ---------------------------------------------------------------- #333
// public Void KNANCFALNJO(System.Boolean FKJFLKANHNP) { }
// RVA 0x0ea7c630
static const ParamDesc kP333[] = {
    { "FKJFLKANHNP", "Boolean", 0 },
};
static const FnDesc kD333 = {
    "KNANCFALNJO", "public Void KNANCFALNJO(System.Boolean FKJFLKANHNP) { }", "Void", 0x0ea7c630u, 1, 0, kP333
};
using H333 = HookSlot<void(__fastcall*)(void*, bool), 333, true>;

// ---------------------------------------------------------------- #334
// protected Void IFOKMKCHLKC() { }
// RVA 0x0ea74f60
static const FnDesc kD334 = {
    "IFOKMKCHLKC", "protected Void IFOKMKCHLKC() { }", "Void", 0x0ea74f60u, 0, 0, nullptr
};
using H334 = HookSlot<void(__fastcall*)(void*), 334, true>;

// ---------------------------------------------------------------- #335
// public Boolean HMCGDEDODCM(System.String ENFMEBMIALK, JPDDCDNAEHO PFFENFNPNFM, System.Object OCGMJJKALAI) { }
// RVA 0x0ea7c640
static const ParamDesc kP335[] = {
    { "ENFMEBMIALK", "String", 0 },
    { "PFFENFNPNFM", "JPDDCDNAEHO", 0 },
    { "OCGMJJKALAI", "Object", 0 },
};
static const FnDesc kD335 = {
    "HMCGDEDODCM", "public Boolean HMCGDEDODCM(System.String ENFMEBMIALK, JPDDCDNAEHO PFFENFNPNFM, System.Object OCGMJJKALAI) { }", "Boolean", 0x0ea7c640u, 3, 1, kP335
};
using H335 = HookSlot<bool(__fastcall*)(void*, Il2CppString*, T_JPDDCDNAEHO, void*), 335, true>;

// ---------------------------------------------------------------- #336
// public AsyncJob LBENNIIAJOB(NIKOKDFLGOP NBFCCABCOAL, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7c870
static const ParamDesc kP336[] = {
    { "NBFCCABCOAL", "NIKOKDFLGOP", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD336 = {
    "LBENNIIAJOB", "public AsyncJob LBENNIIAJOB(NIKOKDFLGOP NBFCCABCOAL, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7c870u, 2, 3, kP336
};
using H336 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, T_NIKOKDFLGOP, void*), 336, true>;

// ---------------------------------------------------------------- #337
// public Sprite OMMDNEGDJHF(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7c8f0
static const ParamDesc kP337[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD337 = {
    "OMMDNEGDJHF", "public Sprite OMMDNEGDJHF(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7c8f0u, 1, 1, kP337
};
using H337 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 337, true>;

// ---------------------------------------------------------------- #338
// private IEnumerator HPOJMEPCOHD(System.String MEIDPKIFMJH, System.String FMECADKPMIP, UnityEngine.UI.Image KJLMLPBGCBK, DDFAHHEEPOM MPFFKAAMAKP, System.Action<UnityEngine.Sprite> FKGGKMAKEPN) { }
// RVA 0x0ea7c980
static const ParamDesc kP338[] = {
    { "MEIDPKIFMJH", "String", 0 },
    { "FMECADKPMIP", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "MPFFKAAMAKP", "DDFAHHEEPOM", 0 },
    { "FKGGKMAKEPN", "Action<Sprite>", 0 },
};
static const FnDesc kD338 = {
    "HPOJMEPCOHD", "private IEnumerator HPOJMEPCOHD(System.String MEIDPKIFMJH, System.String FMECADKPMIP, UnityEngine.UI.Image KJLMLPBGCBK, DDFAHHEEPOM MPFFKAAMAKP, System.Action<UnityEngine.Sprite> FKGGKMAKEPN) { }", "IEnumerator", 0x0ea7c980u, 5, 1, kP338
};
using H338 = HookSlot<void*(__fastcall*)(void*, Il2CppString*, Il2CppString*, void*, T_DDFAHHEEPOM, void*), 338, true>;

// ---------------------------------------------------------------- #339
// public AsyncJob DNDHKNGMEBE(System.String ENFMEBMIALK, System.String ADEGLFPIMIA, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7ca60
static const ParamDesc kP339[] = {
    { "ENFMEBMIALK", "String", 0 },
    { "ADEGLFPIMIA", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD339 = {
    "DNDHKNGMEBE", "public AsyncJob DNDHKNGMEBE(System.String ENFMEBMIALK, System.String ADEGLFPIMIA, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7ca60u, 3, 3, kP339
};
using H339 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, Il2CppString*, void*), 339, true>;

// ---------------------------------------------------------------- #340
// public virtual Void ADNFMJHPIHN() { }
// RVA 0x0ea7caf0
static const FnDesc kD340 = {
    "ADNFMJHPIHN", "public virtual Void ADNFMJHPIHN() { }", "Void", 0x0ea7caf0u, 0, 0, nullptr
};
using H340 = HookSlot<void(__fastcall*)(void*), 340, true>;

// ---------------------------------------------------------------- #341
// public AsyncJob BJJKMFGGGJF(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7cb70
static const ParamDesc kP341[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD341 = {
    "BJJKMFGGGJF", "public AsyncJob BJJKMFGGGJF(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7cb70u, 2, 3, kP341
};
using H341 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 341, true>;

// ---------------------------------------------------------------- #342
// public AsyncJob EKAADFCOPBI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7cc70
static const ParamDesc kP342[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD342 = {
    "EKAADFCOPBI", "public AsyncJob EKAADFCOPBI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7cc70u, 2, 3, kP342
};
using H342 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 342, true>;

// ---------------------------------------------------------------- #343
// protected Void LPNEMNODLMC() { }
// RVA 0x0ea735e0
static const FnDesc kD343 = {
    "LPNEMNODLMC", "protected Void LPNEMNODLMC() { }", "Void", 0x0ea735e0u, 0, 0, nullptr
};
using H343 = HookSlot<void(__fastcall*)(void*), 343, true>;

// ---------------------------------------------------------------- #344
// public Sprite CJLLPJPHGMP(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7cd70
static const ParamDesc kP344[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD344 = {
    "CJLLPJPHGMP", "public Sprite CJLLPJPHGMP(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7cd70u, 1, 1, kP344
};
using H344 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 344, true>;

// ---------------------------------------------------------------- #345
// public Boolean IHFBHADBNFL(EIDAIBHGFDD PBCFJMEEDMG, System.Boolean ELCOFJLOFDH) { }
// RVA 0x0ea7ce30
static const ParamDesc kP345[] = {
    { "PBCFJMEEDMG", "", 0 },
    { "ELCOFJLOFDH", "Boolean", 0 },
};
static const FnDesc kD345 = {
    "IHFBHADBNFL", "public Boolean IHFBHADBNFL(EIDAIBHGFDD PBCFJMEEDMG, System.Boolean ELCOFJLOFDH) { }", "Boolean", 0x0ea7ce30u, 2, 1, kP345
};
using H345 = HookSlot<bool(__fastcall*)(void*, const T_EIDAIBHGFDD*, bool), 345, true>;

// ---------------------------------------------------------------- #346
// public AsyncJob DGHJMHACCKO(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7d8c0
static const ParamDesc kP346[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD346 = {
    "DGHJMHACCKO", "public AsyncJob DGHJMHACCKO(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7d8c0u, 2, 3, kP346
};
using H346 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 346, true>;

// ---------------------------------------------------------------- #347
// public Boolean NKIEJIEICIE() { }
// RVA 0x0ea7d990
static const FnDesc kD347 = {
    "NKIEJIEICIE", "public Boolean NKIEJIEICIE() { }", "Boolean", 0x0ea7d990u, 0, 1, nullptr
};
using H347 = HookSlot<bool(__fastcall*)(void*), 347, true>;

// ---------------------------------------------------------------- #348
// public Void BMCMDMEKOCA(System.String MEIDPKIFMJH, System.String FMECADKPMIP, UnityEngine.UI.Image KJLMLPBGCBK, DDFAHHEEPOM MPFFKAAMAKP, System.Action<UnityEngine.Sprite> FKGGKMAKEPN, System.Nullable<DLPEPIGFIKJ> AHGGLCJKIIH) { }
// RVA 0x0ea7d9a0
static const ParamDesc kP348[] = {
    { "MEIDPKIFMJH", "String", 0 },
    { "FMECADKPMIP", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "MPFFKAAMAKP", "DDFAHHEEPOM", 0 },
    { "FKGGKMAKEPN", "Action<Sprite>", 0 },
    { "AHGGLCJKIIH", "Nullable<DLPEPIGFIKJ>", 0 },
};
static const FnDesc kD348 = {
    "BMCMDMEKOCA", "public Void BMCMDMEKOCA(System.String MEIDPKIFMJH, System.String FMECADKPMIP, UnityEngine.UI.Image KJLMLPBGCBK, DDFAHHEEPOM MPFFKAAMAKP, System.Action<UnityEngine.Sprite> FKGGKMAKEPN, System.Nullable<DLPEPIGFIKJ> AHGGLCJKIIH) { }", "Void", 0x0ea7d9a0u, 6, 0, kP348
};
using H348 = HookSlot<void(__fastcall*)(void*, Il2CppString*, Il2CppString*, void*, T_DDFAHHEEPOM, void*, void*), 348, true>;

// ---------------------------------------------------------------- #349
// private Void MBDGELKMFAD(System.Boolean FKJFLKANHNP) { }
// RVA 0x0ea7e050
static const ParamDesc kP349[] = {
    { "FKJFLKANHNP", "Boolean", 0 },
};
static const FnDesc kD349 = {
    "MBDGELKMFAD", "private Void MBDGELKMFAD(System.Boolean FKJFLKANHNP) { }", "Void", 0x0ea7e050u, 1, 0, kP349
};
using H349 = HookSlot<void(__fastcall*)(void*, bool), 349, true>;

// ---------------------------------------------------------------- #350
// private Void GLEKOAMFING() { }
// RVA 0x0ea79a30
static const FnDesc kD350 = {
    "GLEKOAMFING", "private Void GLEKOAMFING() { }", "Void", 0x0ea79a30u, 0, 0, nullptr
};
using H350 = HookSlot<void(__fastcall*)(void*), 350, true>;

// ---------------------------------------------------------------- #351
// public Void PFKLJJENPGB(UnityEngine.UI.Toggle DHAPJPMGKCM, UnityEngine.Events.UnityAction<System.Boolean> FKGGKMAKEPN) { }
// RVA 0x0ea7e1b0
static const ParamDesc kP351[] = {
    { "DHAPJPMGKCM", "Toggle", 0 },
    { "FKGGKMAKEPN", "UnityAction<Boolean>", 0 },
};
static const FnDesc kD351 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(UnityEngine.UI.Toggle DHAPJPMGKCM, UnityEngine.Events.UnityAction<System.Boolean> FKGGKMAKEPN) { }", "Void", 0x0ea7e1b0u, 2, 0, kP351
};
using H351 = HookSlot<void(__fastcall*)(void*, void*, void*), 351, true>;

// ---------------------------------------------------------------- #352
// public Void LBBCMEBKEEE() { }
// RVA 0x0ea7e550
static const FnDesc kD352 = {
    "LBBCMEBKEEE", "public Void LBBCMEBKEEE() { }", "Void", 0x0ea7e550u, 0, 0, nullptr
};
using H352 = HookSlot<void(__fastcall*)(void*), 352, true>;

// ---------------------------------------------------------------- #353
// public virtual Void ADNBFKJHLJO() { }
// RVA 0x0ea7e5c0
static const FnDesc kD353 = {
    "ADNBFKJHLJO", "public virtual Void ADNBFKJHLJO() { }", "Void", 0x0ea7e5c0u, 0, 0, nullptr
};
using H353 = HookSlot<void(__fastcall*)(void*), 353, true>;

// ---------------------------------------------------------------- #354
// private Void PILHINKEAMH() { }
// RVA 0x0ea7e600
static const FnDesc kD354 = {
    "PILHINKEAMH", "private Void PILHINKEAMH() { }", "Void", 0x0ea7e600u, 0, 0, nullptr
};
using H354 = HookSlot<void(__fastcall*)(void*), 354, true>;

// ---------------------------------------------------------------- #355
// private Void LGGKMMEGDAH() { }
// RVA 0x0ea7e910
static const FnDesc kD355 = {
    "LGGKMMEGDAH", "private Void LGGKMMEGDAH() { }", "Void", 0x0ea7e910u, 0, 0, nullptr
};
using H355 = HookSlot<void(__fastcall*)(void*), 355, true>;

// ---------------------------------------------------------------- #356
// public Boolean LKGFAKFIOJO(PGKFPMENDPA DEALNIJJNGJ, out System.Boolean IFJIEAMJMPI) { }
// RVA 0x0ea7e9d0
static const ParamDesc kP356[] = {
    { "DEALNIJJNGJ", "PGKFPMENDPA", 0 },
    { "IFJIEAMJMPI", "Boolean", 1 },
};
static const FnDesc kD356 = {
    "LKGFAKFIOJO", "public Boolean LKGFAKFIOJO(PGKFPMENDPA DEALNIJJNGJ, out System.Boolean IFJIEAMJMPI) { }", "Boolean", 0x0ea7e9d0u, 2, 1, kP356
};
using H356 = HookSlot<bool(__fastcall*)(void*, void*, OutRef<bool>), 356, true>;

// ---------------------------------------------------------------- #357
// public Void KMFANICNAJD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7eb60
static const ParamDesc kP357[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD357 = {
    "KMFANICNAJD", "public Void KMFANICNAJD(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7eb60u, 2, 0, kP357
};
using H357 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 357, true>;

// ---------------------------------------------------------------- #358
// public Sprite NAKJHDMAHMF(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7ec00
static const ParamDesc kP358[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD358 = {
    "NAKJHDMAHMF", "public Sprite NAKJHDMAHMF(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7ec00u, 1, 1, kP358
};
using H358 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 358, true>;

// ---------------------------------------------------------------- #359
// public Sprite NMLJMKJODAB(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7ec90
static const ParamDesc kP359[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD359 = {
    "NMLJMKJODAB", "public Sprite NMLJMKJODAB(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7ec90u, 1, 1, kP359
};
using H359 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 359, true>;

// ---------------------------------------------------------------- #360
// public Void PFKLJJENPGB(UnityEngine.Events.UnityEvent AFECEFAFIHH, UnityEngine.Events.UnityAction FKGGKMAKEPN) { }
// RVA 0x0ea7ed50
static const ParamDesc kP360[] = {
    { "AFECEFAFIHH", "UnityEvent", 0 },
    { "FKGGKMAKEPN", "UnityAction", 0 },
};
static const FnDesc kD360 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(UnityEngine.Events.UnityEvent AFECEFAFIHH, UnityEngine.Events.UnityAction FKGGKMAKEPN) { }", "Void", 0x0ea7ed50u, 2, 0, kP360
};
using H360 = HookSlot<void(__fastcall*)(void*, void*, void*), 360, true>;

// ---------------------------------------------------------------- #361
// public Void JDJFCKEGBPK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7f060
static const ParamDesc kP361[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD361 = {
    "JDJFCKEGBPK", "public Void JDJFCKEGBPK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7f060u, 2, 0, kP361
};
using H361 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 361, true>;

// ---------------------------------------------------------------- #362
// public AsyncJob ODCAEOBMAJC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7f100
static const ParamDesc kP362[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD362 = {
    "ODCAEOBMAJC", "public AsyncJob ODCAEOBMAJC(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7f100u, 2, 3, kP362
};
using H362 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 362, true>;

// ---------------------------------------------------------------- #363
// public Void AFMDNOABONA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7f1c0
static const ParamDesc kP363[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD363 = {
    "AFMDNOABONA", "public Void AFMDNOABONA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7f1c0u, 2, 0, kP363
};
using H363 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 363, true>;

// ---------------------------------------------------------------- #364
// public Boolean KBNFMCJNAPM() { }
// RVA 0x0ea7f220
static const FnDesc kD364 = {
    "KBNFMCJNAPM", "public Boolean KBNFMCJNAPM() { }", "Boolean", 0x0ea7f220u, 0, 1, nullptr
};
using H364 = HookSlot<bool(__fastcall*)(void*), 364, true>;

// ---------------------------------------------------------------- #365
// private Void PHDLJFLLJCN() { }
// RVA 0x0ea75860
static const FnDesc kD365 = {
    "PHDLJFLLJCN", "private Void PHDLJFLLJCN() { }", "Void", 0x0ea75860u, 0, 0, nullptr
};
using H365 = HookSlot<void(__fastcall*)(void*), 365, true>;

// ---------------------------------------------------------------- #366
// private Void HJANGJEGMJO(System.Boolean GEHEGIFGFJM, System.Boolean EKJPFHNKDEB) { }
// RVA 0x0ea7c170
static const ParamDesc kP366[] = {
    { "GEHEGIFGFJM", "Boolean", 0 },
    { "EKJPFHNKDEB", "Boolean", 0 },
};
static const FnDesc kD366 = {
    "HJANGJEGMJO", "private Void HJANGJEGMJO(System.Boolean GEHEGIFGFJM, System.Boolean EKJPFHNKDEB) { }", "Void", 0x0ea7c170u, 2, 0, kP366
};
using H366 = HookSlot<void(__fastcall*)(void*, bool, bool), 366, true>;

// ---------------------------------------------------------------- #367
// public Sprite ODAGKOBCFGB(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7f390
static const ParamDesc kP367[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD367 = {
    "ODAGKOBCFGB", "public Sprite ODAGKOBCFGB(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7f390u, 1, 1, kP367
};
using H367 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 367, true>;

// ---------------------------------------------------------------- #368
// public Void BJJKMFGGGJF(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7f450
static const ParamDesc kP368[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD368 = {
    "BJJKMFGGGJF", "public Void BJJKMFGGGJF(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7f450u, 2, 0, kP368
};
using H368 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 368, true>;

// ---------------------------------------------------------------- #369
// public static Void FFBLPIBPHFK(EKHBADNLJKF CDKOJMEODLF, MoleMole.MonoControlElement NFOEGFAMDAL, MMBJIJOADOD HJIJDFNCJOO) { }
// RVA 0x0ea7f520
static const ParamDesc kP369[] = {
    { "CDKOJMEODLF", "EKHBADNLJKF", 0 },
    { "NFOEGFAMDAL", "MonoControlElement", 0 },
    { "HJIJDFNCJOO", "MMBJIJOADOD", 0 },
};
static const FnDesc kD369 = {
    "FFBLPIBPHFK", "public static Void FFBLPIBPHFK(EKHBADNLJKF CDKOJMEODLF, MoleMole.MonoControlElement NFOEGFAMDAL, MMBJIJOADOD HJIJDFNCJOO) { }", "Void", 0x0ea7f520u, 3, 0, kP369
};
using H369 = HookSlot<void(__fastcall*)(void*, void*, T_MMBJIJOADOD), 369>;

// ---------------------------------------------------------------- #370
// public Sprite FJNFMBOADKH(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7f690
static const ParamDesc kP370[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD370 = {
    "FJNFMBOADKH", "public Sprite FJNFMBOADKH(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7f690u, 1, 1, kP370
};
using H370 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 370, true>;

// ---------------------------------------------------------------- #371
// public Void AFMDNOABONA(System.UInt32 FOBDDCEFMIB, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7f720
static const ParamDesc kP371[] = {
    { "FOBDDCEFMIB", "UInt32", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD371 = {
    "AFMDNOABONA", "public Void AFMDNOABONA(System.UInt32 FOBDDCEFMIB, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7f720u, 2, 0, kP371
};
using H371 = HookSlot<void(__fastcall*)(void*, uint32_t, void*), 371, true>;

// ---------------------------------------------------------------- #372
// protected virtual Void OnEnable() { }
// RVA 0x0ea7f8a0
static const FnDesc kD372 = {
    "OnEnable", "protected virtual Void OnEnable() { }", "Void", 0x0ea7f8a0u, 0, 0, nullptr
};
using H372 = HookSlot<void(__fastcall*)(void*), 372, true>;

// ---------------------------------------------------------------- #373
// public Sprite LFLJILOCBAB(System.String NJIBPHJKOAD) { }
// RVA 0x0ea7f8e0
static const ParamDesc kP373[] = {
    { "NJIBPHJKOAD", "String", 0 },
};
static const FnDesc kD373 = {
    "LFLJILOCBAB", "public Sprite LFLJILOCBAB(System.String NJIBPHJKOAD) { }", "Sprite", 0x0ea7f8e0u, 1, 1, kP373
};
using H373 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 373, true>;

// ---------------------------------------------------------------- #374
// protected virtual Void PJJKADPDLGH() { }
// RVA 0x0ea7f9a0
static const FnDesc kD374 = {
    "PJJKADPDLGH", "protected virtual Void PJJKADPDLGH() { }", "Void", 0x0ea7f9a0u, 0, 0, nullptr
};
using H374 = HookSlot<void(__fastcall*)(void*), 374, true>;

// ---------------------------------------------------------------- #375
// public Void EFJDLGNOBKA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea7fad0
static const ParamDesc kP375[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD375 = {
    "EFJDLGNOBKA", "public Void EFJDLGNOBKA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea7fad0u, 2, 0, kP375
};
using H375 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 375, true>;

// ---------------------------------------------------------------- #376
// public Boolean AAKKKKNENPB() { }
// RVA 0x0ea7fba0
static const FnDesc kD376 = {
    "AAKKKKNENPB", "public Boolean AAKKKKNENPB() { }", "Boolean", 0x0ea7fba0u, 0, 1, nullptr
};
using H376 = HookSlot<bool(__fastcall*)(void*), 376, true>;

// ---------------------------------------------------------------- #377
// public Void JFAGADPLPDF(MoleMole.MonoKeyboardUIModule FDCGGLIOMBM) { }
// RVA 0x0ea7fbb0
static const ParamDesc kP377[] = {
    { "FDCGGLIOMBM", "MonoKeyboardUIModule", 0 },
};
static const FnDesc kD377 = {
    "JFAGADPLPDF", "public Void JFAGADPLPDF(MoleMole.MonoKeyboardUIModule FDCGGLIOMBM) { }", "Void", 0x0ea7fbb0u, 1, 0, kP377
};
using H377 = HookSlot<void(__fastcall*)(void*, void*), 377, true>;

// ---------------------------------------------------------------- #378
// public virtual Void EADLPLIPINA() { }
// RVA 0x0ea7fc50
static const FnDesc kD378 = {
    "EADLPLIPINA", "public virtual Void EADLPLIPINA() { }", "Void", 0x0ea7fc50u, 0, 0, nullptr
};
using H378 = HookSlot<void(__fastcall*)(void*), 378, true>;

// ---------------------------------------------------------------- #379
// public AsyncJob ODHIHLBGJAB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea7fd50
static const ParamDesc kP379[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD379 = {
    "ODHIHLBGJAB", "public AsyncJob ODHIHLBGJAB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea7fd50u, 2, 3, kP379
};
using H379 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 379, true>;

// ---------------------------------------------------------------- #380
// public Coroutine BMONGPMFLMF(System.Single POPLJPHBGOB, System.Action FKGGKMAKEPN) { }
// RVA 0x0ea7fe50
static const ParamDesc kP380[] = {
    { "POPLJPHBGOB", "Single", 0 },
    { "FKGGKMAKEPN", "Action", 0 },
};
static const FnDesc kD380 = {
    "BMONGPMFLMF", "public Coroutine BMONGPMFLMF(System.Single POPLJPHBGOB, System.Action FKGGKMAKEPN) { }", "Coroutine", 0x0ea7fe50u, 2, 1, kP380
};
using H380 = HookSlot<void*(__fastcall*)(void*, float, void*), 380, true>;

// ---------------------------------------------------------------- #381
// public Void FNMKALPJNMB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea7fed0
static const ParamDesc kP381[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD381 = {
    "FNMKALPJNMB", "public Void FNMKALPJNMB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea7fed0u, 3, 0, kP381
};
using H381 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 381, true>;

// ---------------------------------------------------------------- #382
// public virtual Void LateUpdateView() { }
// RVA 0x0ea7ff80
static const FnDesc kD382 = {
    "LateUpdateView", "public virtual Void LateUpdateView() { }", "Void", 0x0ea7ff80u, 0, 0, nullptr
};
using H382 = HookSlot<void(__fastcall*)(void*), 382, true>;

// ---------------------------------------------------------------- #383
// public Sprite PCBMIHOOKJL(System.String BHOAHJNPMGN) { }
// RVA 0x0ea7ffc0
static const ParamDesc kP383[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD383 = {
    "PCBMIHOOKJL", "public Sprite PCBMIHOOKJL(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea7ffc0u, 1, 1, kP383
};
using H383 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 383, true>;

// ---------------------------------------------------------------- #384
// private Void NNCMKCEFIND(UnityEngine.GameObject ADPMFBNNGOL, System.Boolean BCFEPDHPOOC) { }
// RVA 0x0ea7e820
static const ParamDesc kP384[] = {
    { "ADPMFBNNGOL", "GameObject", 0 },
    { "BCFEPDHPOOC", "Boolean", 0 },
};
static const FnDesc kD384 = {
    "NNCMKCEFIND", "private Void NNCMKCEFIND(UnityEngine.GameObject ADPMFBNNGOL, System.Boolean BCFEPDHPOOC) { }", "Void", 0x0ea7e820u, 2, 0, kP384
};
using H384 = HookSlot<void(__fastcall*)(void*, void*, bool), 384, true>;

// ---------------------------------------------------------------- #385
// public AsyncJob BGMCJMKELHG(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea80080
static const ParamDesc kP385[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD385 = {
    "BGMCJMKELHG", "public AsyncJob BGMCJMKELHG(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea80080u, 2, 3, kP385
};
using H385 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 385, true>;

// ---------------------------------------------------------------- #386
// private Void KLLOJDCCACI() { }
// RVA 0x0ea7f280
static const FnDesc kD386 = {
    "KLLOJDCCACI", "private Void KLLOJDCCACI() { }", "Void", 0x0ea7f280u, 0, 0, nullptr
};
using H386 = HookSlot<void(__fastcall*)(void*), 386, true>;

// ---------------------------------------------------------------- #387
// public AsyncJob JAOJOIDNGBP(OMHKNJLAFDO IOIDEPIBFJJ, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea80100
static const ParamDesc kP387[] = {
    { "IOIDEPIBFJJ", "OMHKNJLAFDO", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD387 = {
    "JAOJOIDNGBP", "public AsyncJob JAOJOIDNGBP(OMHKNJLAFDO IOIDEPIBFJJ, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea80100u, 2, 3, kP387
};
using H387 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, T_OMHKNJLAFDO, void*), 387, true>;

// ---------------------------------------------------------------- #388
// public Void MOMCJPOOPFO(UnityEngine.GameObject LNLECKPEBBO, System.Boolean KPOLBFMOEAA) { }
// RVA 0x0ea80180
static const ParamDesc kP388[] = {
    { "LNLECKPEBBO", "GameObject", 0 },
    { "KPOLBFMOEAA", "Boolean", 0 },
};
static const FnDesc kD388 = {
    "MOMCJPOOPFO", "public Void MOMCJPOOPFO(UnityEngine.GameObject LNLECKPEBBO, System.Boolean KPOLBFMOEAA) { }", "Void", 0x0ea80180u, 2, 0, kP388
};
using H388 = HookSlot<void(__fastcall*)(void*, void*, bool), 388, true>;

// ---------------------------------------------------------------- #389
// public Void BBIHMPHOOFG(System.UInt32 HGKLAKAICFF) { }
// RVA 0x0ea80220
static const ParamDesc kP389[] = {
    { "HGKLAKAICFF", "UInt32", 0 },
};
static const FnDesc kD389 = {
    "BBIHMPHOOFG", "public Void BBIHMPHOOFG(System.UInt32 HGKLAKAICFF) { }", "Void", 0x0ea80220u, 1, 0, kP389
};
using H389 = HookSlot<void(__fastcall*)(void*, uint32_t), 389, true>;

// ---------------------------------------------------------------- #390
// public Void EBHEAKIGGLJ(UnityEngine.UI.Button DBICHEBDBPA) { }
// RVA 0x0ea794e0
static const ParamDesc kP390[] = {
    { "DBICHEBDBPA", "Button", 0 },
};
static const FnDesc kD390 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(UnityEngine.UI.Button DBICHEBDBPA) { }", "Void", 0x0ea794e0u, 1, 0, kP390
};
using H390 = HookSlot<void(__fastcall*)(void*, void*), 390, true>;

// ---------------------------------------------------------------- #391
// protected Void BFIPNKEANPD(System.Boolean GEHEGIFGFJM, System.Boolean EKJPFHNKDEB, System.Single POPLJPHBGOB) { }
// RVA 0x0ea802c0
static const ParamDesc kP391[] = {
    { "GEHEGIFGFJM", "Boolean", 0 },
    { "EKJPFHNKDEB", "Boolean", 0 },
    { "POPLJPHBGOB", "Single", 0 },
};
static const FnDesc kD391 = {
    "BFIPNKEANPD", "protected Void BFIPNKEANPD(System.Boolean GEHEGIFGFJM, System.Boolean EKJPFHNKDEB, System.Single POPLJPHBGOB) { }", "Void", 0x0ea802c0u, 3, 0, kP391
};
using H391 = HookSlot<void(__fastcall*)(void*, bool, bool, float), 391, true>;

// ---------------------------------------------------------------- #392
// private Void BCGDLDNNCEM(PDKLFELFBKF ODOJEHLPEDC) { }
// RVA 0x0ea80550
static const ParamDesc kP392[] = {
    { "ODOJEHLPEDC", "PDKLFELFBKF", 0 },
};
static const FnDesc kD392 = {
    "BCGDLDNNCEM", "private Void BCGDLDNNCEM(PDKLFELFBKF ODOJEHLPEDC) { }", "Void", 0x0ea80550u, 1, 0, kP392
};
using H392 = HookSlot<void(__fastcall*)(void*, T_PDKLFELFBKF), 392, true>;

// ---------------------------------------------------------------- #393
// protected Void FBGIOAHKOIF(System.Boolean KPOLBFMOEAA) { }
// RVA 0x0ea80800
static const ParamDesc kP393[] = {
    { "KPOLBFMOEAA", "Boolean", 0 },
};
static const FnDesc kD393 = {
    "FBGIOAHKOIF", "protected Void FBGIOAHKOIF(System.Boolean KPOLBFMOEAA) { }", "Void", 0x0ea80800u, 1, 0, kP393
};
using H393 = HookSlot<void(__fastcall*)(void*, bool), 393, true>;

// ---------------------------------------------------------------- #394
// public virtual Void KNNHDJDEIOK(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea808a0
static const ParamDesc kP394[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD394 = {
    "KNNHDJDEIOK", "public virtual Void KNNHDJDEIOK(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea808a0u, 2, 0, kP394
};
using H394 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 394, true>;

// ---------------------------------------------------------------- #395
// public Sprite CCHLFGNKLLC(System.String BHOAHJNPMGN) { }
// RVA 0x0ea808f0
static const ParamDesc kP395[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD395 = {
    "CCHLFGNKLLC", "public Sprite CCHLFGNKLLC(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea808f0u, 1, 1, kP395
};
using H395 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 395, true>;

// ---------------------------------------------------------------- #396
// public Void LHDMKHKOCED(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea809b0
static const ParamDesc kP396[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD396 = {
    "LHDMKHKOCED", "public Void LHDMKHKOCED(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea809b0u, 2, 0, kP396
};
using H396 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 396, true>;

// ---------------------------------------------------------------- #397
// public Void EBHEAKIGGLJ(UnityEngine.UI.Slider ICFGJMCEMMB) { }
// RVA 0x0ea80a80
static const ParamDesc kP397[] = {
    { "ICFGJMCEMMB", "Slider", 0 },
};
static const FnDesc kD397 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(UnityEngine.UI.Slider ICFGJMCEMMB) { }", "Void", 0x0ea80a80u, 1, 0, kP397
};
using H397 = HookSlot<void(__fastcall*)(void*, void*), 397, true>;

// ---------------------------------------------------------------- #398
// public Coroutine BLGGJJIMFBD(System.Action FKGGKMAKEPN) { }
// RVA 0x0ea80b70
static const ParamDesc kP398[] = {
    { "FKGGKMAKEPN", "Action", 0 },
};
static const FnDesc kD398 = {
    "BLGGJJIMFBD", "public Coroutine BLGGJJIMFBD(System.Action FKGGKMAKEPN) { }", "Coroutine", 0x0ea80b70u, 1, 1, kP398
};
using H398 = HookSlot<void*(__fastcall*)(void*, void*), 398, true>;

// ---------------------------------------------------------------- #399
// protected virtual Void OBHOKEBFFLB() { }
// RVA 0x0ea80bf0
static const FnDesc kD399 = {
    "OBHOKEBFFLB", "protected virtual Void OBHOKEBFFLB() { }", "Void", 0x0ea80bf0u, 0, 0, nullptr
};
using H399 = HookSlot<void(__fastcall*)(void*), 399, true>;

// ---------------------------------------------------------------- #400
// public Void JDJFCKEGBPK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean IMIOCPNAPLO) { }
// RVA 0x0ea80da0
static const ParamDesc kP400[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "IMIOCPNAPLO", "Boolean", 0 },
};
static const FnDesc kD400 = {
    "JDJFCKEGBPK", "public Void JDJFCKEGBPK(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean IMIOCPNAPLO) { }", "Void", 0x0ea80da0u, 3, 0, kP400
};
using H400 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 400, true>;

// ---------------------------------------------------------------- #401
// private Void CMOJKMBLHLL(System.Boolean OIFNKINJJEP) { }
// RVA 0x0ea759c0
static const ParamDesc kP401[] = {
    { "OIFNKINJJEP", "Boolean", 0 },
};
static const FnDesc kD401 = {
    "CMOJKMBLHLL", "private Void CMOJKMBLHLL(System.Boolean OIFNKINJJEP) { }", "Void", 0x0ea759c0u, 1, 0, kP401
};
using H401 = HookSlot<void(__fastcall*)(void*, bool), 401, true>;

// ---------------------------------------------------------------- #402
// public Void EBHEAKIGGLJ(MoleMole.MonoInputFieldExtention CDPMHHADOKK) { }
// RVA 0x0ea80e10
static const ParamDesc kP402[] = {
    { "CDPMHHADOKK", "MonoInputFieldExtention", 0 },
};
static const FnDesc kD402 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(MoleMole.MonoInputFieldExtention CDPMHHADOKK) { }", "Void", 0x0ea80e10u, 1, 0, kP402
};
using H402 = HookSlot<void(__fastcall*)(void*, void*), 402, true>;

// ---------------------------------------------------------------- #403
// public Boolean MCHIOCPBDHO() { }
// RVA 0x0ea80e70
static const FnDesc kD403 = {
    "MCHIOCPBDHO", "public Boolean MCHIOCPBDHO() { }", "Boolean", 0x0ea80e70u, 0, 1, nullptr
};
using H403 = HookSlot<bool(__fastcall*)(void*), 403, true>;

// ---------------------------------------------------------------- #404
// public Void BAKEDLAHJKD(UnityEngine.UI.Toggle DHAPJPMGKCM, UnityEngine.Events.UnityAction<System.Boolean> FKGGKMAKEPN, System.Boolean CEIBCOIPEPO) { }
// RVA 0x0ea80e80
static const ParamDesc kP404[] = {
    { "DHAPJPMGKCM", "Toggle", 0 },
    { "FKGGKMAKEPN", "UnityAction<Boolean>", 0 },
    { "CEIBCOIPEPO", "Boolean", 0 },
};
static const FnDesc kD404 = {
    "BAKEDLAHJKD", "public Void BAKEDLAHJKD(UnityEngine.UI.Toggle DHAPJPMGKCM, UnityEngine.Events.UnityAction<System.Boolean> FKGGKMAKEPN, System.Boolean CEIBCOIPEPO) { }", "Void", 0x0ea80e80u, 3, 0, kP404
};
using H404 = HookSlot<void(__fastcall*)(void*, void*, void*, bool), 404, true>;

// ---------------------------------------------------------------- #405
// public Void COCHIOKPOFM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea81270
static const ParamDesc kP405[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD405 = {
    "COCHIOKPOFM", "public Void COCHIOKPOFM(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea81270u, 2, 0, kP405
};
using H405 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 405, true>;

// ---------------------------------------------------------------- #406
// public Void PFKLJJENPGB(UnityEngine.UI.Dropdown OLDPJNLLICA, UnityEngine.Events.UnityAction<System.Int32> FKGGKMAKEPN) { }
// RVA 0x0ea81340
static const ParamDesc kP406[] = {
    { "OLDPJNLLICA", "Dropdown", 0 },
    { "FKGGKMAKEPN", "UnityAction<Int32>", 0 },
};
static const FnDesc kD406 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(UnityEngine.UI.Dropdown OLDPJNLLICA, UnityEngine.Events.UnityAction<System.Int32> FKGGKMAKEPN) { }", "Void", 0x0ea81340u, 2, 0, kP406
};
using H406 = HookSlot<void(__fastcall*)(void*, void*, void*), 406, true>;

// ---------------------------------------------------------------- #407
// public Sprite GACOOFMBMAG(System.String BHOAHJNPMGN) { }
// RVA 0x0ea81660
static const ParamDesc kP407[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD407 = {
    "GACOOFMBMAG", "public Sprite GACOOFMBMAG(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea81660u, 1, 1, kP407
};
using H407 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 407, true>;

// ---------------------------------------------------------------- #408
// private Void JGPCIDMKDPA() { }
// RVA 0x0ea7e140
static const FnDesc kD408 = {
    "JGPCIDMKDPA", "private Void JGPCIDMKDPA() { }", "Void", 0x0ea7e140u, 0, 0, nullptr
};
using H408 = HookSlot<void(__fastcall*)(void*), 408, true>;

// ---------------------------------------------------------------- #409
// protected Boolean NIEHKHDHMIN() { }
// RVA 0x0ea766c0
static const FnDesc kD409 = {
    "NIEHKHDHMIN", "protected Boolean NIEHKHDHMIN() { }", "Boolean", 0x0ea766c0u, 0, 1, nullptr
};
using H409 = HookSlot<bool(__fastcall*)(void*), 409, true>;

// ---------------------------------------------------------------- #410
// public AsyncJob LICHCMFHONC(NHGHLAINJJB GMOMPNHBPOI, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea816f0
static const ParamDesc kP410[] = {
    { "GMOMPNHBPOI", "NHGHLAINJJB", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD410 = {
    "LICHCMFHONC", "public AsyncJob LICHCMFHONC(NHGHLAINJJB GMOMPNHBPOI, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea816f0u, 2, 3, kP410
};
using H410 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, T_NHGHLAINJJB, void*), 410, true>;

// ---------------------------------------------------------------- #411
// public AsyncJob CCGKOHALCHM(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea817e0
static const ParamDesc kP411[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD411 = {
    "CCGKOHALCHM", "public AsyncJob CCGKOHALCHM(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea817e0u, 2, 3, kP411
};
using H411 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 411, true>;

// ---------------------------------------------------------------- #412
// public Void OCAAJODIKCJ(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea818e0
static const ParamDesc kP412[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD412 = {
    "OCAAJODIKCJ", "public Void OCAAJODIKCJ(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea818e0u, 2, 0, kP412
};
using H412 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 412, true>;

// ---------------------------------------------------------------- #413
// public virtual Void HOOBPLMFLOC(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }
// RVA 0x0ea81990
static const ParamDesc kP413[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "GCHAFILKIPB", "LACPHBBPHGE", 0 },
};
static const FnDesc kD413 = {
    "HOOBPLMFLOC", "public virtual Void HOOBPLMFLOC(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }", "Void", 0x0ea81990u, 4, 0, kP413
};
using H413 = HookSlot<void(__fastcall*)(void*, void*, const T_AAOHKJCCPDL*, void*, T_LACPHBBPHGE), 413, true>;

// ---------------------------------------------------------------- #414
// public Sprite MOKEPJDLCNJ(System.String BHOAHJNPMGN) { }
// RVA 0x0ea81a00
static const ParamDesc kP414[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD414 = {
    "MOKEPJDLCNJ", "public Sprite MOKEPJDLCNJ(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea81a00u, 1, 1, kP414
};
using H414 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 414, true>;

// ---------------------------------------------------------------- #415
// public Void OFLFCFPMLPP() { }
// RVA 0x0ea81ac0
static const FnDesc kD415 = {
    "OFLFCFPMLPP", "public Void OFLFCFPMLPP() { }", "Void", 0x0ea81ac0u, 0, 0, nullptr
};
using H415 = HookSlot<void(__fastcall*)(void*), 415, true>;

// ---------------------------------------------------------------- #416
// public AsyncJob HBLHMHDHMGG(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea81bc0
static const ParamDesc kP416[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD416 = {
    "HBLHMHDHMGG", "public AsyncJob HBLHMHDHMGG(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea81bc0u, 2, 3, kP416
};
using H416 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 416, true>;

// ---------------------------------------------------------------- #417
// public Boolean OAAKOMKKEIA(System.String ENFMEBMIALK) { }
// RVA 0x0ea81cc0
static const ParamDesc kP417[] = {
    { "ENFMEBMIALK", "String", 0 },
};
static const FnDesc kD417 = {
    "OAAKOMKKEIA", "public Boolean OAAKOMKKEIA(System.String ENFMEBMIALK) { }", "Boolean", 0x0ea81cc0u, 1, 1, kP417
};
using H417 = HookSlot<bool(__fastcall*)(void*, Il2CppString*), 417, true>;

// ---------------------------------------------------------------- #418
// public Void OMJPKFMMLEO(BHIDJOHFING OBIBFIFNCLL) { }
// RVA 0x0ea81ec0
static const ParamDesc kP418[] = {
    { "OBIBFIFNCLL", "BHIDJOHFING", 0 },
};
static const FnDesc kD418 = {
    "OMJPKFMMLEO", "public Void OMJPKFMMLEO(BHIDJOHFING OBIBFIFNCLL) { }", "Void", 0x0ea81ec0u, 1, 0, kP418
};
using H418 = HookSlot<void(__fastcall*)(void*, void*), 418, true>;

// ---------------------------------------------------------------- #419
// public virtual Void SetupView() { }
// RVA 0x0ea81f70
static const FnDesc kD419 = {
    "SetupView", "public virtual Void SetupView() { }", "Void", 0x0ea81f70u, 0, 0, nullptr
};
using H419 = HookSlot<void(__fastcall*)(void*), 419, true>;

// ---------------------------------------------------------------- #420
// public Void EFINOJGCHPI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea81fb0
static const ParamDesc kP420[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD420 = {
    "EFINOJGCHPI", "public Void EFINOJGCHPI(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea81fb0u, 2, 0, kP420
};
using H420 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 420, true>;

// ---------------------------------------------------------------- #421
// public Sprite IMHAHBIDNDB(System.String BHOAHJNPMGN) { }
// RVA 0x0ea82080
static const ParamDesc kP421[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD421 = {
    "IMHAHBIDNDB", "public Sprite IMHAHBIDNDB(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea82080u, 1, 1, kP421
};
using H421 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 421, true>;

// ---------------------------------------------------------------- #422
// private Void MAHFMFNFLBK() { }
// RVA 0x0ea7e760
static const FnDesc kD422 = {
    "MAHFMFNFLBK", "private Void MAHFMFNFLBK() { }", "Void", 0x0ea7e760u, 0, 0, nullptr
};
using H422 = HookSlot<void(__fastcall*)(void*), 422, true>;

// ---------------------------------------------------------------- #423
// protected Void FFBLPIBPHFK(MoleMole.MonoControlElement NFOEGFAMDAL, MMBJIJOADOD HJIJDFNCJOO) { }
// RVA 0x0ea7f580
static const ParamDesc kP423[] = {
    { "NFOEGFAMDAL", "MonoControlElement", 0 },
    { "HJIJDFNCJOO", "MMBJIJOADOD", 0 },
};
static const FnDesc kD423 = {
    "FFBLPIBPHFK", "protected Void FFBLPIBPHFK(MoleMole.MonoControlElement NFOEGFAMDAL, MMBJIJOADOD HJIJDFNCJOO) { }", "Void", 0x0ea7f580u, 2, 0, kP423
};
using H423 = HookSlot<void(__fastcall*)(void*, void*, T_MMBJIJOADOD), 423, true>;

// ---------------------------------------------------------------- #424
// public Void BNPMAEOANEC() { }
// RVA 0x0ea82140
static const FnDesc kD424 = {
    "BNPMAEOANEC", "public Void BNPMAEOANEC() { }", "Void", 0x0ea82140u, 0, 0, nullptr
};
using H424 = HookSlot<void(__fastcall*)(void*), 424, true>;

// ---------------------------------------------------------------- #425
// public AsyncJob AAHENGMCCNA(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea82190
static const ParamDesc kP425[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD425 = {
    "AAHENGMCCNA", "public AsyncJob AAHENGMCCNA(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea82190u, 2, 3, kP425
};
using H425 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 425, true>;

// ---------------------------------------------------------------- #426
// public Void EBHEAKIGGLJ(MoleMole.Mono2DSlider AENDAFJDEAA) { }
// RVA 0x0ea82290
static const ParamDesc kP426[] = {
    { "AENDAFJDEAA", "Mono2DSlider", 0 },
};
static const FnDesc kD426 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(MoleMole.Mono2DSlider AENDAFJDEAA) { }", "Void", 0x0ea82290u, 1, 0, kP426
};
using H426 = HookSlot<void(__fastcall*)(void*, void*), 426, true>;

// ---------------------------------------------------------------- #427
// public Void MLMEMAAGAND(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }
// RVA 0x0ea82380
static const ParamDesc kP427[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "GCHAFILKIPB", "LACPHBBPHGE", 0 },
};
static const FnDesc kD427 = {
    "MLMEMAAGAND", "public Void MLMEMAAGAND(MoleMole.MonoJoypadUIModule EKKJGFECKHO, AAOHKJCCPDL EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, LACPHBBPHGE GCHAFILKIPB) { }", "Void", 0x0ea82380u, 4, 0, kP427
};
using H427 = HookSlot<void(__fastcall*)(void*, void*, const T_AAOHKJCCPDL*, void*, T_LACPHBBPHGE), 427, true>;

// ---------------------------------------------------------------- #428
// public Sprite NMAGOKADDEA(System.String BHOAHJNPMGN) { }
// RVA 0x0ea824f0
static const ParamDesc kP428[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD428 = {
    "NMAGOKADDEA", "public Sprite NMAGOKADDEA(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea824f0u, 1, 1, kP428
};
using H428 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 428, true>;

// ---------------------------------------------------------------- #429
// public Sprite GMDPMBFOCPG(System.String BHOAHJNPMGN) { }
// RVA 0x0ea82580
static const ParamDesc kP429[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD429 = {
    "GMDPMBFOCPG", "public Sprite GMDPMBFOCPG(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea82580u, 1, 1, kP429
};
using H429 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 429, true>;

// ---------------------------------------------------------------- #430
// public AsyncJob IIPJBCELNMB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea82640
static const ParamDesc kP430[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD430 = {
    "IIPJBCELNMB", "public AsyncJob IIPJBCELNMB(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea82640u, 2, 3, kP430
};
using H430 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 430, true>;

// ---------------------------------------------------------------- #431
// public Sprite IONCGNKFEKG(System.String ENFMEBMIALK, System.String ADEGLFPIMIA) { }
// RVA 0x0ea82700
static const ParamDesc kP431[] = {
    { "ENFMEBMIALK", "String", 0 },
    { "ADEGLFPIMIA", "String", 0 },
};
static const FnDesc kD431 = {
    "IONCGNKFEKG", "public Sprite IONCGNKFEKG(System.String ENFMEBMIALK, System.String ADEGLFPIMIA) { }", "Sprite", 0x0ea82700u, 2, 1, kP431
};
using H431 = HookSlot<void*(__fastcall*)(void*, Il2CppString*, Il2CppString*), 431, true>;

// ---------------------------------------------------------------- #432
// private Void ILDILEBNPJM() { }
// RVA 0x0ea754e0
static const FnDesc kD432 = {
    "ILDILEBNPJM", "private Void ILDILEBNPJM() { }", "Void", 0x0ea754e0u, 0, 0, nullptr
};
using H432 = HookSlot<void(__fastcall*)(void*), 432, true>;

// ---------------------------------------------------------------- #433
// public Sprite PPJLLHLGAHC(System.String BHOAHJNPMGN) { }
// RVA 0x0ea827a0
static const ParamDesc kP433[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD433 = {
    "PPJLLHLGAHC", "public Sprite PPJLLHLGAHC(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea827a0u, 1, 1, kP433
};
using H433 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 433, true>;

// ---------------------------------------------------------------- #434
// public virtual Void UpdateView() { }
// RVA 0x0ea82860
static const FnDesc kD434 = {
    "UpdateView", "public virtual Void UpdateView() { }", "Void", 0x0ea82860u, 0, 0, nullptr
};
using H434 = HookSlot<void(__fastcall*)(void*), 434, true>;

// ---------------------------------------------------------------- #435
// public virtual Boolean OOGMCAKFPLO(PGKFPMENDPA DIFFHADFKEA) { }
// RVA 0x0ea828a0
static const ParamDesc kP435[] = {
    { "DIFFHADFKEA", "PGKFPMENDPA", 0 },
};
static const FnDesc kD435 = {
    "OOGMCAKFPLO", "public virtual Boolean OOGMCAKFPLO(PGKFPMENDPA DIFFHADFKEA) { }", "Boolean", 0x0ea828a0u, 1, 1, kP435
};
using H435 = HookSlot<bool(__fastcall*)(void*, void*), 435, true>;

// ---------------------------------------------------------------- #436
// public Void PFKLJJENPGB(MoleMole.UIDButton DBICHEBDBPA, UnityEngine.Events.UnityAction<System.UInt32> FKGGKMAKEPN) { }
// RVA 0x0ea828f0
static const ParamDesc kP436[] = {
    { "DBICHEBDBPA", "UIDButton", 0 },
    { "FKGGKMAKEPN", "UnityAction<UInt32>", 0 },
};
static const FnDesc kD436 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(MoleMole.UIDButton DBICHEBDBPA, UnityEngine.Events.UnityAction<System.UInt32> FKGGKMAKEPN) { }", "Void", 0x0ea828f0u, 2, 0, kP436
};
using H436 = HookSlot<void(__fastcall*)(void*, void*, void*), 436, true>;

// ---------------------------------------------------------------- #437
// protected virtual Void EDKJHIIHLEE() { }
// RVA 0x0ea82c90
static const FnDesc kD437 = {
    "EDKJHIIHLEE", "protected virtual Void EDKJHIIHLEE() { }", "Void", 0x0ea82c90u, 0, 0, nullptr
};
using H437 = HookSlot<void(__fastcall*)(void*), 437, true>;

// ---------------------------------------------------------------- #438
// protected Void ALBMMHDAFMF(GEGODFHFBIG FKJFLKANHNP) { }
// RVA 0x0ea82e60
static const ParamDesc kP438[] = {
    { "FKJFLKANHNP", "GEGODFHFBIG", 0 },
};
static const FnDesc kD438 = {
    "ALBMMHDAFMF", "protected Void ALBMMHDAFMF(GEGODFHFBIG FKJFLKANHNP) { }", "Void", 0x0ea82e60u, 1, 0, kP438
};
using H438 = HookSlot<void(__fastcall*)(void*, T_GEGODFHFBIG), 438, true>;

// ---------------------------------------------------------------- #439
// private Void IDAGMPJCMCG() { }
// RVA 0x0ea82e70
static const FnDesc kD439 = {
    "IDAGMPJCMCG", "private Void IDAGMPJCMCG() { }", "Void", 0x0ea82e70u, 0, 0, nullptr
};
using H439 = HookSlot<void(__fastcall*)(void*), 439, true>;

// ---------------------------------------------------------------- #440
// public Void EBHEAKIGGLJ(MoleMole.MonoMultipleClickButton DBICHEBDBPA) { }
// RVA 0x0ea82fb0
static const ParamDesc kP440[] = {
    { "DBICHEBDBPA", "MonoMultipleClickButton", 0 },
};
static const FnDesc kD440 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(MoleMole.MonoMultipleClickButton DBICHEBDBPA) { }", "Void", 0x0ea82fb0u, 1, 0, kP440
};
using H440 = HookSlot<void(__fastcall*)(void*, void*), 440, true>;

// ---------------------------------------------------------------- #441
// public AsyncJob CJGIGLIGEED(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea830a0
static const ParamDesc kP441[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD441 = {
    "CJGIGLIGEED", "public AsyncJob CJGIGLIGEED(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea830a0u, 2, 3, kP441
};
using H441 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 441, true>;

// ---------------------------------------------------------------- #442
// protected virtual Void FOMJPJDKAJB() { }
// RVA 0x0ea831a0
static const FnDesc kD442 = {
    "FOMJPJDKAJB", "protected virtual Void FOMJPJDKAJB() { }", "Void", 0x0ea831a0u, 0, 0, nullptr
};
using H442 = HookSlot<void(__fastcall*)(void*), 442, true>;

// ---------------------------------------------------------------- #443
// public Void BHEECOEEHOB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea83870
static const ParamDesc kP443[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD443 = {
    "BHEECOEEHOB", "public Void BHEECOEEHOB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea83870u, 2, 0, kP443
};
using H443 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 443, true>;

// ---------------------------------------------------------------- #444
// public AsyncJob KMFANICNAJD(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea83920
static const ParamDesc kP444[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD444 = {
    "KMFANICNAJD", "public AsyncJob KMFANICNAJD(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea83920u, 2, 3, kP444
};
using H444 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 444, true>;

// ---------------------------------------------------------------- #445
// public Void CLMDGEEGPFP(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }
// RVA 0x0ea839e0
static const ParamDesc kP445[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "EDJGMOGMCIE", "Int32", 0 },
    { "KBKPGJGONJD", "Transform", 0 },
    { "ILLHJJAJOKF", "GCLHPKAEIPN", 0 },
};
static const FnDesc kD445 = {
    "CLMDGEEGPFP", "public Void CLMDGEEGPFP(MoleMole.MonoJoypadUIModule EKKJGFECKHO, System.Int32 EDJGMOGMCIE, UnityEngine.Transform KBKPGJGONJD, GCLHPKAEIPN ILLHJJAJOKF) { }", "Void", 0x0ea839e0u, 4, 0, kP445
};
using H445 = HookSlot<void(__fastcall*)(void*, void*, int32_t, void*, T_GCLHPKAEIPN), 445, true>;

// ---------------------------------------------------------------- #446
// public AsyncJob JMEFEEAKKCP(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea83b10
static const ParamDesc kP446[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD446 = {
    "JMEFEEAKKCP", "public AsyncJob JMEFEEAKKCP(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea83b10u, 2, 3, kP446
};
using H446 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 446, true>;

// ---------------------------------------------------------------- #447
// public virtual Boolean EGCEGKIHJJE(MoleMole.MonoJoypadUIModule EKKJGFECKHO, LHJHCLDJMNI NCBHJPCFFAE, AAOHKJCCPDL JNHIKAPIIJH, NPMJBCIDIED AJGLMCNAFDG, AAOHKJCCPDL LGDNCBOKFGB, out AAOHKJCCPDL DNGNLPGENMB) { }
// RVA 0x0ea83c10
static const ParamDesc kP447[] = {
    { "EKKJGFECKHO", "MonoJoypadUIModule", 0 },
    { "NCBHJPCFFAE", "LHJHCLDJMNI", 0 },
    { "JNHIKAPIIJH", "", 0 },
    { "AJGLMCNAFDG", "NPMJBCIDIED", 0 },
    { "LGDNCBOKFGB", "", 0 },
    { "DNGNLPGENMB", "AAOHKJCCPDL", 1 },
};
static const FnDesc kD447 = {
    "EGCEGKIHJJE", "public virtual Boolean EGCEGKIHJJE(MoleMole.MonoJoypadUIModule EKKJGFECKHO, LHJHCLDJMNI NCBHJPCFFAE, AAOHKJCCPDL JNHIKAPIIJH, NPMJBCIDIED AJGLMCNAFDG, AAOHKJCCPDL LGDNCBOKFGB, out AAOHKJCCPDL DNGNLPGENMB) { }", "Boolean", 0x0ea83c10u, 6, 1, kP447
};
using H447 = HookSlot<bool(__fastcall*)(void*, void*, void*, const T_AAOHKJCCPDL*, T_NPMJBCIDIED, const T_AAOHKJCCPDL*, OutRef<T_AAOHKJCCPDL>), 447, true>;

// ---------------------------------------------------------------- #448
// public Boolean HEODDEDKGCK() { }
// RVA 0x0ea75520
static const FnDesc kD448 = {
    "HEODDEDKGCK", "public Boolean HEODDEDKGCK() { }", "Boolean", 0x0ea75520u, 0, 1, nullptr
};
using H448 = HookSlot<bool(__fastcall*)(void*), 448, true>;

// ---------------------------------------------------------------- #449
// public List<MonoJoypadUIModule> EGOEBMLPDMI() { }
// RVA 0x0ea83cd0
static const FnDesc kD449 = {
    "EGOEBMLPDMI", "public List<MonoJoypadUIModule> EGOEBMLPDMI() { }", "List<MonoJoypadUIModule>", 0x0ea83cd0u, 0, 1, nullptr
};
using H449 = HookSlot<void*(__fastcall*)(void*), 449, true>;

// ---------------------------------------------------------------- #450
// public Sprite COEPHLFMDAG(System.String BHOAHJNPMGN) { }
// RVA 0x0ea83ce0
static const ParamDesc kP450[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD450 = {
    "COEPHLFMDAG", "public Sprite COEPHLFMDAG(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea83ce0u, 1, 1, kP450
};
using H450 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 450, true>;

// ---------------------------------------------------------------- #451
// public Void NLILPPDKFIF(MoleMole.MonoUIContainer DMNMHJLDNLA, UnityEngine.Events.UnityAction<System.UInt32> FKGGKMAKEPN) { }
// RVA 0x0ea83da0
static const ParamDesc kP451[] = {
    { "DMNMHJLDNLA", "MonoUIContainer", 0 },
    { "FKGGKMAKEPN", "UnityAction<UInt32>", 0 },
};
static const FnDesc kD451 = {
    "NLILPPDKFIF", "public Void NLILPPDKFIF(MoleMole.MonoUIContainer DMNMHJLDNLA, UnityEngine.Events.UnityAction<System.UInt32> FKGGKMAKEPN) { }", "Void", 0x0ea83da0u, 2, 0, kP451
};
using H451 = HookSlot<void(__fastcall*)(void*, void*, void*), 451, true>;

// ---------------------------------------------------------------- #452
// public virtual Boolean DIKKLNECBKJ() { }
// RVA 0x0ea83e20
static const FnDesc kD452 = {
    "DIKKLNECBKJ", "public virtual Boolean DIKKLNECBKJ() { }", "Boolean", 0x0ea83e20u, 0, 1, nullptr
};
using H452 = HookSlot<bool(__fastcall*)(void*), 452, true>;

// ---------------------------------------------------------------- #453
// public UInt32 NINCGFCDCCP() { }
// RVA 0x0ea71dc0
static const FnDesc kD453 = {
    "NINCGFCDCCP", "public UInt32 NINCGFCDCCP() { }", "UInt32", 0x0ea71dc0u, 0, 1, nullptr
};
using H453 = HookSlot<uint32_t(__fastcall*)(void*), 453, true>;

// ---------------------------------------------------------------- #454
// public Void BHEKLHCLEEC(PDKLFELFBKF HEEEMIMEMIH) { }
// RVA 0x0ea72d90
static const ParamDesc kP454[] = {
    { "HEEEMIMEMIH", "PDKLFELFBKF", 0 },
};
static const FnDesc kD454 = {
    "BHEKLHCLEEC", "public Void BHEKLHCLEEC(PDKLFELFBKF HEEEMIMEMIH) { }", "Void", 0x0ea72d90u, 1, 0, kP454
};
using H454 = HookSlot<void(__fastcall*)(void*, T_PDKLFELFBKF), 454, true>;

// ---------------------------------------------------------------- #455
// public Void EBHEAKIGGLJ(UnityEngine.UI.Dropdown OLDPJNLLICA) { }
// RVA 0x0ea83e80
static const ParamDesc kP455[] = {
    { "OLDPJNLLICA", "Dropdown", 0 },
};
static const FnDesc kD455 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(UnityEngine.UI.Dropdown OLDPJNLLICA) { }", "Void", 0x0ea83e80u, 1, 0, kP455
};
using H455 = HookSlot<void(__fastcall*)(void*, void*), 455, true>;

// ---------------------------------------------------------------- #456
// public Void CCNGCEDIBME(MoleMole.MonoControlElement NFOEGFAMDAL, UnityEngine.KeyCode JKMMHLDOJHH) { }
// RVA 0x0ea83f70
static const ParamDesc kP456[] = {
    { "NFOEGFAMDAL", "MonoControlElement", 0 },
    { "JKMMHLDOJHH", "KeyCode", 0 },
};
static const FnDesc kD456 = {
    "CCNGCEDIBME", "public Void CCNGCEDIBME(MoleMole.MonoControlElement NFOEGFAMDAL, UnityEngine.KeyCode JKMMHLDOJHH) { }", "Void", 0x0ea83f70u, 2, 0, kP456
};
using H456 = HookSlot<void(__fastcall*)(void*, void*, T_UnityEngine_KeyCode), 456, true>;

// ---------------------------------------------------------------- #457
// public Void LANDCNMJMKI() { }
// RVA 0x0ea842f0
static const FnDesc kD457 = {
    "LANDCNMJMKI", "public Void LANDCNMJMKI() { }", "Void", 0x0ea842f0u, 0, 0, nullptr
};
using H457 = HookSlot<void(__fastcall*)(void*), 457, true>;

// ---------------------------------------------------------------- #458
// private Void HOFIIOFKEOM(System.String MEIDPKIFMJH, System.String FMECADKPMIP, UnityEngine.UI.Image KJLMLPBGCBK, DDFAHHEEPOM MPFFKAAMAKP, System.Action<UnityEngine.Sprite> FKGGKMAKEPN, System.Nullable<DLPEPIGFIKJ> AHGGLCJKIIH) { }
// RVA 0x0ea7de00
static const ParamDesc kP458[] = {
    { "MEIDPKIFMJH", "String", 0 },
    { "FMECADKPMIP", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "MPFFKAAMAKP", "DDFAHHEEPOM", 0 },
    { "FKGGKMAKEPN", "Action<Sprite>", 0 },
    { "AHGGLCJKIIH", "Nullable<DLPEPIGFIKJ>", 0 },
};
static const FnDesc kD458 = {
    "HOFIIOFKEOM", "private Void HOFIIOFKEOM(System.String MEIDPKIFMJH, System.String FMECADKPMIP, UnityEngine.UI.Image KJLMLPBGCBK, DDFAHHEEPOM MPFFKAAMAKP, System.Action<UnityEngine.Sprite> FKGGKMAKEPN, System.Nullable<DLPEPIGFIKJ> AHGGLCJKIIH) { }", "Void", 0x0ea7de00u, 6, 0, kP458
};
using H458 = HookSlot<void(__fastcall*)(void*, Il2CppString*, Il2CppString*, void*, T_DDFAHHEEPOM, void*, void*), 458, true>;

// ---------------------------------------------------------------- #459
// public Sprite PNEELGBDPBA(System.String NJIBPHJKOAD) { }
// RVA 0x0ea84350
static const ParamDesc kP459[] = {
    { "NJIBPHJKOAD", "String", 0 },
};
static const FnDesc kD459 = {
    "PNEELGBDPBA", "public Sprite PNEELGBDPBA(System.String NJIBPHJKOAD) { }", "Sprite", 0x0ea84350u, 1, 1, kP459
};
using H459 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 459, true>;

// ---------------------------------------------------------------- #460
// public Void EBHEAKIGGLJ(UnityEngine.Events.UnityEventBase AFECEFAFIHH) { }
// RVA 0x0ea84410
static const ParamDesc kP460[] = {
    { "AFECEFAFIHH", "UnityEventBase", 0 },
};
static const FnDesc kD460 = {
    "EBHEAKIGGLJ", "public Void EBHEAKIGGLJ(UnityEngine.Events.UnityEventBase AFECEFAFIHH) { }", "Void", 0x0ea84410u, 1, 0, kP460
};
using H460 = HookSlot<void(__fastcall*)(void*, void*), 460, true>;

// ---------------------------------------------------------------- #461
// public Void GOFHEPGAHME(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA, UnityEngine.GameObject FJHCGNPIBDO, AKKGBKCGGNB ILHMOGEEHIC) { }
// RVA 0x0ea844d0
static const ParamDesc kP461[] = {
    { "DAONBKOKGEA", "ListNavigatePointerActionConfig", 0 },
    { "FJHCGNPIBDO", "GameObject", 0 },
    { "ILHMOGEEHIC", "AKKGBKCGGNB", 0 },
};
static const FnDesc kD461 = {
    "GOFHEPGAHME", "public Void GOFHEPGAHME(MoleMole.ListNavigatePointerActionConfig DAONBKOKGEA, UnityEngine.GameObject FJHCGNPIBDO, AKKGBKCGGNB ILHMOGEEHIC) { }", "Void", 0x0ea844d0u, 3, 0, kP461
};
using H461 = HookSlot<void(__fastcall*)(void*, void*, void*, T_AKKGBKCGGNB), 461, true>;

// ---------------------------------------------------------------- #462
// public Sprite FEJHIIKPJGA(System.String BHOAHJNPMGN) { }
// RVA 0x0ea845b0
static const ParamDesc kP462[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD462 = {
    "FEJHIIKPJGA", "public Sprite FEJHIIKPJGA(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea845b0u, 1, 1, kP462
};
using H462 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 462, true>;

// ---------------------------------------------------------------- #463
// public Sprite PFBCDFNEHNB(System.String BHOAHJNPMGN) { }
// RVA 0x0ea84640
static const ParamDesc kP463[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD463 = {
    "PFBCDFNEHNB", "public Sprite PFBCDFNEHNB(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea84640u, 1, 1, kP463
};
using H463 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 463, true>;

// ---------------------------------------------------------------- #464
// private Boolean DDGAIMKKMCO(EIDAIBHGFDD PBCFJMEEDMG) { }
// RVA 0x0ea84700
static const ParamDesc kP464[] = {
    { "PBCFJMEEDMG", "", 0 },
};
static const FnDesc kD464 = {
    "DDGAIMKKMCO", "private Boolean DDGAIMKKMCO(EIDAIBHGFDD PBCFJMEEDMG) { }", "Boolean", 0x0ea84700u, 1, 1, kP464
};
using H464 = HookSlot<bool(__fastcall*)(void*, const T_EIDAIBHGFDD*), 464, true>;

// ---------------------------------------------------------------- #465
// public AsyncJob OGDFKGMNMGJ(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea848a0
static const ParamDesc kP465[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD465 = {
    "OGDFKGMNMGJ", "public AsyncJob OGDFKGMNMGJ(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea848a0u, 2, 3, kP465
};
using H465 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 465, true>;

// ---------------------------------------------------------------- #466
// public AsyncJob KJANFOLAKBN(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea849a0
static const ParamDesc kP466[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD466 = {
    "KJANFOLAKBN", "public AsyncJob KJANFOLAKBN(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea849a0u, 2, 3, kP466
};
using H466 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 466, true>;

// ---------------------------------------------------------------- #467
// private Void IEEDEMIGOHF() { }
// RVA 0x0ea7f300
static const FnDesc kD467 = {
    "IEEDEMIGOHF", "private Void IEEDEMIGOHF() { }", "Void", 0x0ea7f300u, 0, 0, nullptr
};
using H467 = HookSlot<void(__fastcall*)(void*), 467, true>;

// ---------------------------------------------------------------- #468
// private Void DHODOECLAPB(UnityEngine.GameObject ADPMFBNNGOL, System.Boolean BCFEPDHPOOC) { }
// RVA 0x0ea7e060
static const ParamDesc kP468[] = {
    { "ADPMFBNNGOL", "GameObject", 0 },
    { "BCFEPDHPOOC", "Boolean", 0 },
};
static const FnDesc kD468 = {
    "DHODOECLAPB", "private Void DHODOECLAPB(UnityEngine.GameObject ADPMFBNNGOL, System.Boolean BCFEPDHPOOC) { }", "Void", 0x0ea7e060u, 2, 0, kP468
};
using H468 = HookSlot<void(__fastcall*)(void*, void*, bool), 468, true>;

// ---------------------------------------------------------------- #469
// public Void ANAJEBEBADE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea84a60
static const ParamDesc kP469[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD469 = {
    "ANAJEBEBADE", "public Void ANAJEBEBADE(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea84a60u, 2, 0, kP469
};
using H469 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 469, true>;

// ---------------------------------------------------------------- #470
// private Void AKNHMOLAEIP(UnityEngine.UI.Button DBICHEBDBPA, UnityEngine.Events.UnityAction PFFENFNPNFM) { }
// RVA 0x0ea70890
static const ParamDesc kP470[] = {
    { "DBICHEBDBPA", "Button", 0 },
    { "PFFENFNPNFM", "UnityAction", 0 },
};
static const FnDesc kD470 = {
    "AKNHMOLAEIP", "private Void AKNHMOLAEIP(UnityEngine.UI.Button DBICHEBDBPA, UnityEngine.Events.UnityAction PFFENFNPNFM) { }", "Void", 0x0ea70890u, 2, 0, kP470
};
using H470 = HookSlot<void(__fastcall*)(void*, void*, void*), 470, true>;

// ---------------------------------------------------------------- #471
// public Sprite OENAPPMEIOF(System.String BHOAHJNPMGN) { }
// RVA 0x0ea84b30
static const ParamDesc kP471[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD471 = {
    "OENAPPMEIOF", "public Sprite OENAPPMEIOF(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea84b30u, 1, 1, kP471
};
using H471 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 471, true>;

// ---------------------------------------------------------------- #472
// public Sprite FGBPLDOHEGC(System.String BHOAHJNPMGN) { }
// RVA 0x0ea84bf0
static const ParamDesc kP472[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD472 = {
    "FGBPLDOHEGC", "public Sprite FGBPLDOHEGC(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea84bf0u, 1, 1, kP472
};
using H472 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 472, true>;

// ---------------------------------------------------------------- #473
// private Void IAHJODJCHPL(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea79250
static const ParamDesc kP473[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD473 = {
    "IAHJODJCHPL", "private Void IAHJODJCHPL(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea79250u, 2, 0, kP473
};
using H473 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 473, true>;

// ---------------------------------------------------------------- #474
// public Sprite BMLICBPPOCD(System.String BHOAHJNPMGN) { }
// RVA 0x0ea84cb0
static const ParamDesc kP474[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD474 = {
    "BMLICBPPOCD", "public Sprite BMLICBPPOCD(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea84cb0u, 1, 1, kP474
};
using H474 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 474, true>;

// ---------------------------------------------------------------- #475
// protected Void JOODFBPJCHE() { }
// RVA 0x0ea84d70
static const FnDesc kD475 = {
    "JOODFBPJCHE", "protected Void JOODFBPJCHE() { }", "Void", 0x0ea84d70u, 0, 0, nullptr
};
using H475 = HookSlot<void(__fastcall*)(void*), 475, true>;

// ---------------------------------------------------------------- #476
// public Void Tick() { }
// RVA 0x0ea84f50
static const FnDesc kD476 = {
    "Tick", "public Void Tick() { }", "Void", 0x0ea84f50u, 0, 0, nullptr
};
using H476 = HookSlot<void(__fastcall*)(void*), 476, true>;

// ---------------------------------------------------------------- #477
// public virtual Void NGNDBIPOOOE(MoleMole.MonoJoypadNavRegionBase OPPHKACDBBN) { }
// RVA 0x0ea85030
static const ParamDesc kP477[] = {
    { "OPPHKACDBBN", "MonoJoypadNavRegionBase", 0 },
};
static const FnDesc kD477 = {
    "NGNDBIPOOOE", "public virtual Void NGNDBIPOOOE(MoleMole.MonoJoypadNavRegionBase OPPHKACDBBN) { }", "Void", 0x0ea85030u, 1, 0, kP477
};
using H477 = HookSlot<void(__fastcall*)(void*, void*), 477, true>;

// ---------------------------------------------------------------- #478
// private Boolean AIKOJNHHHAC(UnityEngine.GameObject LIGJDLDGGIO) { }
// RVA 0x0ea79930
static const ParamDesc kP478[] = {
    { "LIGJDLDGGIO", "GameObject", 0 },
};
static const FnDesc kD478 = {
    "AIKOJNHHHAC", "private Boolean AIKOJNHHHAC(UnityEngine.GameObject LIGJDLDGGIO) { }", "Boolean", 0x0ea79930u, 1, 1, kP478
};
using H478 = HookSlot<bool(__fastcall*)(void*, void*), 478, true>;

// ---------------------------------------------------------------- #479
// public Void GJMGJNIGLOM(MMBJIJOADOD AFECEFAFIHH, MoleMole.BaseContextComponent AGNPEANOGNA) { }
// RVA 0x0ea85080
static const ParamDesc kP479[] = {
    { "AFECEFAFIHH", "MMBJIJOADOD", 0 },
    { "AGNPEANOGNA", "BaseContextComponent", 0 },
};
static const FnDesc kD479 = {
    "GJMGJNIGLOM", "public Void GJMGJNIGLOM(MMBJIJOADOD AFECEFAFIHH, MoleMole.BaseContextComponent AGNPEANOGNA) { }", "Void", 0x0ea85080u, 2, 0, kP479
};
using H479 = HookSlot<void(__fastcall*)(void*, T_MMBJIJOADOD, void*), 479, true>;

// ---------------------------------------------------------------- #480
// public Sprite PLAFIPPBBLL(System.String BHOAHJNPMGN) { }
// RVA 0x0ea85430
static const ParamDesc kP480[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD480 = {
    "PLAFIPPBBLL", "public Sprite PLAFIPPBBLL(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea85430u, 1, 1, kP480
};
using H480 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 480, true>;

// ---------------------------------------------------------------- #481
// public virtual Boolean OnNotify(MoleMole.Notify JPGCMPKAJGE) { }
// RVA 0x0ea854f0
static const ParamDesc kP481[] = {
    { "JPGCMPKAJGE", "", 0 },
};
static const FnDesc kD481 = {
    "OnNotify", "public virtual Boolean OnNotify(MoleMole.Notify JPGCMPKAJGE) { }", "Boolean", 0x0ea854f0u, 1, 1, kP481
};
using H481 = HookSlot<bool(__fastcall*)(void*, const T_MoleMole_Notify*), 481, true>;

// ---------------------------------------------------------------- #482
// public virtual Void LMPBIDGNCBN(MoleMole.MonoJoypadNavRegionBase KDIHEPBLNFC) { }
// RVA 0x0ea85550
static const ParamDesc kP482[] = {
    { "KDIHEPBLNFC", "MonoJoypadNavRegionBase", 0 },
};
static const FnDesc kD482 = {
    "LMPBIDGNCBN", "public virtual Void LMPBIDGNCBN(MoleMole.MonoJoypadNavRegionBase KDIHEPBLNFC) { }", "Void", 0x0ea85550u, 1, 0, kP482
};
using H482 = HookSlot<void(__fastcall*)(void*, void*), 482, true>;

// ---------------------------------------------------------------- #483
// public Sprite ONDPJPIHIKD(MBEGFPNIONG GMKLFOIOFCO) { }
// RVA 0x0ea855a0
static const ParamDesc kP483[] = {
    { "GMKLFOIOFCO", "MBEGFPNIONG", 0 },
};
static const FnDesc kD483 = {
    "ONDPJPIHIKD", "public Sprite ONDPJPIHIKD(MBEGFPNIONG GMKLFOIOFCO) { }", "Sprite", 0x0ea855a0u, 1, 1, kP483
};
using H483 = HookSlot<void*(__fastcall*)(void*, void*), 483, true>;

// ---------------------------------------------------------------- #484
// public Void ODHIHLBGJAB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea85600
static const ParamDesc kP484[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD484 = {
    "ODHIHLBGJAB", "public Void ODHIHLBGJAB(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea85600u, 3, 0, kP484
};
using H484 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 484, true>;

// ---------------------------------------------------------------- #485
// public Sprite IBPJNKIFMAG(System.String BHOAHJNPMGN) { }
// RVA 0x0ea856d0
static const ParamDesc kP485[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD485 = {
    "IBPJNKIFMAG", "public Sprite IBPJNKIFMAG(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea856d0u, 1, 1, kP485
};
using H485 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 485, true>;

// ---------------------------------------------------------------- #486
// public Sprite AADIFMDMPEF(System.UInt32 FOBDDCEFMIB) { }
// RVA 0x0ea85760
static const ParamDesc kP486[] = {
    { "FOBDDCEFMIB", "UInt32", 0 },
};
static const FnDesc kD486 = {
    "AADIFMDMPEF", "public Sprite AADIFMDMPEF(System.UInt32 FOBDDCEFMIB) { }", "Sprite", 0x0ea85760u, 1, 1, kP486
};
using H486 = HookSlot<void*(__fastcall*)(void*, uint32_t), 486, true>;

// ---------------------------------------------------------------- #487
// public Void KIBFAHDCNNA(MoleMole.MonoJoypadUIModule KEDNOJKFEHO) { }
// RVA 0x0ea85940
static const ParamDesc kP487[] = {
    { "KEDNOJKFEHO", "MonoJoypadUIModule", 0 },
};
static const FnDesc kD487 = {
    "KIBFAHDCNNA", "public Void KIBFAHDCNNA(MoleMole.MonoJoypadUIModule KEDNOJKFEHO) { }", "Void", 0x0ea85940u, 1, 0, kP487
};
using H487 = HookSlot<void(__fastcall*)(void*, void*), 487, true>;

// ---------------------------------------------------------------- #488
// public virtual Void NEADGACPIAO() { }
// RVA 0x0ea85ba0
static const FnDesc kD488 = {
    "NEADGACPIAO", "public virtual Void NEADGACPIAO() { }", "Void", 0x0ea85ba0u, 0, 0, nullptr
};
using H488 = HookSlot<void(__fastcall*)(void*), 488, true>;

// ---------------------------------------------------------------- #489
// protected virtual Boolean JHOHHCDHJHN(MoleMole.Notify JPGCMPKAJGE, System.Boolean PHBLEHILFOA) { }
// RVA 0x0ea85c40
static const ParamDesc kP489[] = {
    { "JPGCMPKAJGE", "", 0 },
    { "PHBLEHILFOA", "Boolean", 0 },
};
static const FnDesc kD489 = {
    "JHOHHCDHJHN", "protected virtual Boolean JHOHHCDHJHN(MoleMole.Notify JPGCMPKAJGE, System.Boolean PHBLEHILFOA) { }", "Boolean", 0x0ea85c40u, 2, 1, kP489
};
using H489 = HookSlot<bool(__fastcall*)(void*, const T_MoleMole_Notify*, bool), 489, true>;

// ---------------------------------------------------------------- #490
// public AsyncJob KLHEHAPIONI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea85ca0
static const ParamDesc kP490[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD490 = {
    "KLHEHAPIONI", "public AsyncJob KLHEHAPIONI(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea85ca0u, 2, 3, kP490
};
using H490 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 490, true>;

// ---------------------------------------------------------------- #491
// public Void LICHCMFHONC(NHGHLAINJJB GMOMPNHBPOI, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea85d20
static const ParamDesc kP491[] = {
    { "GMOMPNHBPOI", "NHGHLAINJJB", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD491 = {
    "LICHCMFHONC", "public Void LICHCMFHONC(NHGHLAINJJB GMOMPNHBPOI, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea85d20u, 2, 0, kP491
};
using H491 = HookSlot<void(__fastcall*)(void*, T_NHGHLAINJJB, void*), 491, true>;

// ---------------------------------------------------------------- #492
// public Boolean HNAPEBDELCO(MoleMole.Notify CNMPOFACGDF, System.Boolean PHBLEHILFOA, System.Boolean FOPIJBLODLO) { }
// RVA 0x0ea85de0
static const ParamDesc kP492[] = {
    { "CNMPOFACGDF", "", 0 },
    { "PHBLEHILFOA", "Boolean", 0 },
    { "FOPIJBLODLO", "Boolean", 0 },
};
static const FnDesc kD492 = {
    "HNAPEBDELCO", "public Boolean HNAPEBDELCO(MoleMole.Notify CNMPOFACGDF, System.Boolean PHBLEHILFOA, System.Boolean FOPIJBLODLO) { }", "Boolean", 0x0ea85de0u, 3, 1, kP492
};
using H492 = HookSlot<bool(__fastcall*)(void*, const T_MoleMole_Notify*, bool, bool), 492, true>;

// ---------------------------------------------------------------- #493
// private Void LMBGOPPBJIC(MoleMole.Notify CNMPOFACGDF) { }
// RVA 0x0ea85fd0
static const ParamDesc kP493[] = {
    { "CNMPOFACGDF", "", 0 },
};
static const FnDesc kD493 = {
    "LMBGOPPBJIC", "private Void LMBGOPPBJIC(MoleMole.Notify CNMPOFACGDF) { }", "Void", 0x0ea85fd0u, 1, 0, kP493
};
using H493 = HookSlot<void(__fastcall*)(void*, const T_MoleMole_Notify*), 493, true>;

// ---------------------------------------------------------------- #494
// public Void IMMFPPLGPAJ(System.Int32 JIJAGOPMIJJ, MoleMole.BaseContextComponent AGNPEANOGNA) { }
// RVA 0x0ea862d0
static const ParamDesc kP494[] = {
    { "JIJAGOPMIJJ", "Int32", 0 },
    { "AGNPEANOGNA", "BaseContextComponent", 0 },
};
static const FnDesc kD494 = {
    "IMMFPPLGPAJ", "public Void IMMFPPLGPAJ(System.Int32 JIJAGOPMIJJ, MoleMole.BaseContextComponent AGNPEANOGNA) { }", "Void", 0x0ea862d0u, 2, 0, kP494
};
using H494 = HookSlot<void(__fastcall*)(void*, int32_t, void*), 494, true>;

// ---------------------------------------------------------------- #495
// public Void HHIFHIGAMOJ(UnityEngine.GameObject LNLECKPEBBO) { }
// RVA 0x0ea864e0
static const ParamDesc kP495[] = {
    { "LNLECKPEBBO", "GameObject", 0 },
};
static const FnDesc kD495 = {
    "HHIFHIGAMOJ", "public Void HHIFHIGAMOJ(UnityEngine.GameObject LNLECKPEBBO) { }", "Void", 0x0ea864e0u, 1, 0, kP495
};
using H495 = HookSlot<void(__fastcall*)(void*, void*), 495, true>;

// ---------------------------------------------------------------- #496
// public Void PFKLJJENPGB(UnityEngine.UI.InputField CDPMHHADOKK, UnityEngine.Events.UnityAction<System.String> FKGGKMAKEPN) { }
// RVA 0x0ea86590
static const ParamDesc kP496[] = {
    { "CDPMHHADOKK", "InputField", 0 },
    { "FKGGKMAKEPN", "UnityAction<String>", 0 },
};
static const FnDesc kD496 = {
    "PFKLJJENPGB", "public Void PFKLJJENPGB(UnityEngine.UI.InputField CDPMHHADOKK, UnityEngine.Events.UnityAction<System.String> FKGGKMAKEPN) { }", "Void", 0x0ea86590u, 2, 0, kP496
};
using H496 = HookSlot<void(__fastcall*)(void*, void*, void*), 496, true>;

// ---------------------------------------------------------------- #497
// private Void OMMJENGNNJF() { }
// RVA 0x0ea868c0
static const FnDesc kD497 = {
    "OMMJENGNNJF", "private Void OMMJENGNNJF() { }", "Void", 0x0ea868c0u, 0, 0, nullptr
};
using H497 = HookSlot<void(__fastcall*)(void*), 497, true>;

// ---------------------------------------------------------------- #498
// private Boolean LCPKMMECOLI(MoleMole.Notify JPGCMPKAJGE) { }
// RVA 0x0ea86980
static const ParamDesc kP498[] = {
    { "JPGCMPKAJGE", "", 0 },
};
static const FnDesc kD498 = {
    "LCPKMMECOLI", "private Boolean LCPKMMECOLI(MoleMole.Notify JPGCMPKAJGE) { }", "Boolean", 0x0ea86980u, 1, 1, kP498
};
using H498 = HookSlot<bool(__fastcall*)(void*, const T_MoleMole_Notify*), 498, true>;

// ---------------------------------------------------------------- #499
// protected Void JEFLJIEMOEE() { }
// RVA 0x0ea72ba0
static const FnDesc kD499 = {
    "JEFLJIEMOEE", "protected Void JEFLJIEMOEE() { }", "Void", 0x0ea72ba0u, 0, 0, nullptr
};
using H499 = HookSlot<void(__fastcall*)(void*), 499, true>;

// ---------------------------------------------------------------- #500
// public Void CJOAECFBIHP(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }
// RVA 0x0ea86bd0
static const ParamDesc kP500[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
    { "HMPLLFGIPHK", "Boolean", 0 },
};
static const FnDesc kD500 = {
    "CJOAECFBIHP", "public Void CJOAECFBIHP(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK, System.Boolean HMPLLFGIPHK) { }", "Void", 0x0ea86bd0u, 3, 0, kP500
};
using H500 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*, bool), 500, true>;

// ---------------------------------------------------------------- #501
// protected Void DNEDIPHBMPN(System.UInt16 NPOGHFEGKCD) { }
// RVA 0x0ea86c70
static const ParamDesc kP501[] = {
    { "NPOGHFEGKCD", "UInt16", 0 },
};
static const FnDesc kD501 = {
    "DNEDIPHBMPN", "protected Void DNEDIPHBMPN(System.UInt16 NPOGHFEGKCD) { }", "Void", 0x0ea86c70u, 1, 0, kP501
};
using H501 = HookSlot<void(__fastcall*)(void*, uint16_t), 501, true>;

// ---------------------------------------------------------------- #502
// public MOOOFFOHING LJLGECAOCBJ() { }
// RVA 0x0ea86cd0
static const FnDesc kD502 = {
    "LJLGECAOCBJ", "public MOOOFFOHING LJLGECAOCBJ() { }", "MOOOFFOHING", 0x0ea86cd0u, 0, 1, nullptr
};
using H502 = HookSlot<void*(__fastcall*)(void*), 502, true>;

// ---------------------------------------------------------------- #503
// public Void AAHENGMCCNA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }
// RVA 0x0ea86ce0
static const ParamDesc kP503[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "KJLMLPBGCBK", "Image", 0 },
};
static const FnDesc kD503 = {
    "AAHENGMCCNA", "public Void AAHENGMCCNA(System.String BHOAHJNPMGN, UnityEngine.UI.Image KJLMLPBGCBK) { }", "Void", 0x0ea86ce0u, 2, 0, kP503
};
using H503 = HookSlot<void(__fastcall*)(void*, Il2CppString*, void*), 503, true>;

// ---------------------------------------------------------------- #504
// protected Void FFJGIIPGILB(System.String CAFIOOBGHIN, System.Boolean OHEAKIDEKOG) { }
// RVA 0x0ea86db0
static const ParamDesc kP504[] = {
    { "CAFIOOBGHIN", "String", 0 },
    { "OHEAKIDEKOG", "Boolean", 0 },
};
static const FnDesc kD504 = {
    "FFJGIIPGILB", "protected Void FFJGIIPGILB(System.String CAFIOOBGHIN, System.Boolean OHEAKIDEKOG) { }", "Void", 0x0ea86db0u, 2, 0, kP504
};
using H504 = HookSlot<void(__fastcall*)(void*, Il2CppString*, bool), 504, true>;

// ---------------------------------------------------------------- #505
// public Boolean PHNGKBLGPDM() { }
// RVA 0x0ea86f20
static const FnDesc kD505 = {
    "PHNGKBLGPDM", "public Boolean PHNGKBLGPDM() { }", "Boolean", 0x0ea86f20u, 0, 1, nullptr
};
using H505 = HookSlot<bool(__fastcall*)(void*), 505, true>;

// ---------------------------------------------------------------- #506
// public AsyncJob EPPIMGOLDEO(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea86f30
static const ParamDesc kP506[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD506 = {
    "EPPIMGOLDEO", "public AsyncJob EPPIMGOLDEO(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea86f30u, 2, 3, kP506
};
using H506 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 506, true>;

// ---------------------------------------------------------------- #507
// protected Boolean IGPECNINCHO() { }
// RVA 0x0ea87030
static const FnDesc kD507 = {
    "IGPECNINCHO", "protected Boolean IGPECNINCHO() { }", "Boolean", 0x0ea87030u, 0, 1, nullptr
};
using H507 = HookSlot<bool(__fastcall*)(void*), 507, true>;

// ---------------------------------------------------------------- #508
// private Void GMEOJOCNIBD(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }
// RVA 0x0ea87090
static const ParamDesc kP508[] = {
    { "LJMOKCMMEOJ", "MBGAPCMOGML", 0 },
    { "ECBJJIGPNMM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD508 = {
    "GMEOJOCNIBD", "private Void GMEOJOCNIBD(MBGAPCMOGML LJMOKCMMEOJ, EKAEMFGFEMJ ECBJJIGPNMM) { }", "Void", 0x0ea87090u, 2, 0, kP508
};
using H508 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 508, true>;

// ---------------------------------------------------------------- #509
// public Sprite ODFJBGADFDE(System.String BHOAHJNPMGN) { }
// RVA 0x0ea87410
static const ParamDesc kP509[] = {
    { "BHOAHJNPMGN", "String", 0 },
};
static const FnDesc kD509 = {
    "ODFJBGADFDE", "public Sprite ODFJBGADFDE(System.String BHOAHJNPMGN) { }", "Sprite", 0x0ea87410u, 1, 1, kP509
};
using H509 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 509, true>;

// ---------------------------------------------------------------- #510
// public Sprite NMAGOKADDEA(System.String BHOAHJNPMGN, System.Boolean IMIOCPNAPLO) { }
// RVA 0x0ea874d0
static const ParamDesc kP510[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "IMIOCPNAPLO", "Boolean", 0 },
};
static const FnDesc kD510 = {
    "NMAGOKADDEA", "public Sprite NMAGOKADDEA(System.String BHOAHJNPMGN, System.Boolean IMIOCPNAPLO) { }", "Sprite", 0x0ea874d0u, 2, 1, kP510
};
using H510 = HookSlot<void*(__fastcall*)(void*, Il2CppString*, bool), 510, true>;

// ---------------------------------------------------------------- #511
// private Void HPLMFDPLOEI(MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ LLCJKAGCJAA) { }
// RVA 0x0ea87530
static const ParamDesc kP511[] = {
    { "DMCKBLLEFOD", "MBGAPCMOGML", 0 },
    { "LLCJKAGCJAA", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD511 = {
    "HPLMFDPLOEI", "private Void HPLMFDPLOEI(MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ LLCJKAGCJAA) { }", "Void", 0x0ea87530u, 2, 0, kP511
};
using H511 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 511, true>;

// ---------------------------------------------------------------- #512
// public AsyncJob IPIGDAJKLED(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }
// RVA 0x0ea876f0
static const ParamDesc kP512[] = {
    { "BHOAHJNPMGN", "String", 0 },
    { "PEFMHNLKDAN", "Action<Sprite>", 0 },
};
static const FnDesc kD512 = {
    "IPIGDAJKLED", "public AsyncJob IPIGDAJKLED(System.String BHOAHJNPMGN, System.Action<UnityEngine.Sprite> PEFMHNLKDAN) { }", "AsyncJob", 0x0ea876f0u, 2, 3, kP512
};
using H512 = HookSlot<T_MoleMole_AsyncJob(__fastcall*)(void*, Il2CppString*, void*), 512, true>;

// ---------------------------------------------------------------- #513
// public virtual Void FDLNBCEHHDI(MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ LLCJKAGCJAA) { }
// RVA 0x0ea877b0
static const ParamDesc kP513[] = {
    { "DMCKBLLEFOD", "MBGAPCMOGML", 0 },
    { "LLCJKAGCJAA", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD513 = {
    "FDLNBCEHHDI", "public virtual Void FDLNBCEHHDI(MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ LLCJKAGCJAA) { }", "Void", 0x0ea877b0u, 2, 0, kP513
};
using H513 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 513, true>;

// ---------------------------------------------------------------- #514
// public Sprite KCEEOKLCDMH(System.String NJIBPHJKOAD) { }
// RVA 0x0ea87800
static const ParamDesc kP514[] = {
    { "NJIBPHJKOAD", "String", 0 },
};
static const FnDesc kD514 = {
    "KCEEOKLCDMH", "public Sprite KCEEOKLCDMH(System.String NJIBPHJKOAD) { }", "Sprite", 0x0ea87800u, 1, 1, kP514
};
using H514 = HookSlot<void*(__fastcall*)(void*, Il2CppString*), 514, true>;

// ---------------------------------------------------------------- #515
// private Void PNOOHLDAONN() { }
// RVA 0x0ea835f0
static const FnDesc kD515 = {
    "PNOOHLDAONN", "private Void PNOOHLDAONN() { }", "Void", 0x0ea835f0u, 0, 0, nullptr
};
using H515 = HookSlot<void(__fastcall*)(void*), 515, true>;

// ---------------------------------------------------------------- #516
// private Void DJNFCKMHPAE(MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ BOGKDFHHBAM) { }
// RVA 0x0ea87620
static const ParamDesc kP516[] = {
    { "DMCKBLLEFOD", "MBGAPCMOGML", 0 },
    { "BOGKDFHHBAM", "EKAEMFGFEMJ", 0 },
};
static const FnDesc kD516 = {
    "DJNFCKMHPAE", "private Void DJNFCKMHPAE(MBGAPCMOGML DMCKBLLEFOD, EKAEMFGFEMJ BOGKDFHHBAM) { }", "Void", 0x0ea87620u, 2, 0, kP516
};
using H516 = HookSlot<void(__fastcall*)(void*, T_MBGAPCMOGML, T_EKAEMFGFEMJ), 516, true>;

// ---- 安装表 ----
static const HookDef kHooks[] = {
    { 0x0ea64b30u, (void*)(&H000::detour), (void**)(&H000::orig), &kD000 },
    { 0x0ea64c20u, (void*)(&H001::detour), (void**)(&H001::orig), &kD001 },
    { 0x0ea64c80u, (void*)(&H002::detour), (void**)(&H002::orig), &kD002 },
    { 0x0ea64c90u, (void*)(&H003::detour), (void**)(&H003::orig), &kD003 },
    { 0x0ea64d50u, (void*)(&H004::detour), (void**)(&H004::orig), &kD004 },
    { 0x0ea652d0u, (void*)(&H005::detour), (void**)(&H005::orig), &kD005 },
    { 0x0ea654c0u, (void*)(&H006::detour), (void**)(&H006::orig), &kD006 },
    { 0x0ea656d0u, (void*)(&H007::detour), (void**)(&H007::orig), &kD007 },
    { 0x0ea65770u, (void*)(&H008::detour), (void**)(&H008::orig), &kD008 },
    { 0x0ea65830u, (void*)(&H009::detour), (void**)(&H009::orig), &kD009 },
    { 0x0ea658f0u, (void*)(&H010::detour), (void**)(&H010::orig), &kD010 },
    { 0x0ea659a0u, (void*)(&H011::detour), (void**)(&H011::orig), &kD011 },
    { 0x0ea65a10u, (void*)(&H012::detour), (void**)(&H012::orig), &kD012 },
    { 0x0ea65ab0u, (void*)(&H013::detour), (void**)(&H013::orig), &kD013 },
    { 0x0ea65bb0u, (void*)(&H014::detour), (void**)(&H014::orig), &kD014 },
    { 0x0ea65cb0u, (void*)(&H015::detour), (void**)(&H015::orig), &kD015 },
    { 0x0ea65d90u, (void*)(&H016::detour), (void**)(&H016::orig), &kD016 },
    { 0x0ea65de0u, (void*)(&H017::detour), (void**)(&H017::orig), &kD017 },
    { 0x0ea65e90u, (void*)(&H018::detour), (void**)(&H018::orig), &kD018 },
    { 0x0ea65fc0u, (void*)(&H019::detour), (void**)(&H019::orig), &kD019 },
    { 0x0ea665c0u, (void*)(&H020::detour), (void**)(&H020::orig), &kD020 },
    { 0x0ea666e0u, (void*)(&H021::detour), (void**)(&H021::orig), &kD021 },
    { 0x0ea66760u, (void*)(&H022::detour), (void**)(&H022::orig), &kD022 },
    { 0x0ea667c0u, (void*)(&H023::detour), (void**)(&H023::orig), &kD023 },
    { 0x0ea669d0u, (void*)(&H024::detour), (void**)(&H024::orig), &kD024 },
    { 0x0ea66a20u, (void*)(&H025::detour), (void**)(&H025::orig), &kD025 },
    { 0x0ea66b90u, (void*)(&H026::detour), (void**)(&H026::orig), &kD026 },
    { 0x0ea34370u, (void*)(&H027::detour), (void**)(&H027::orig), &kD027 },
    { 0x0ea66ce0u, (void*)(&H028::detour), (void**)(&H028::orig), &kD028 },
    { 0x0ea66fb0u, (void*)(&H029::detour), (void**)(&H029::orig), &kD029 },
    { 0x0ea670b0u, (void*)(&H030::detour), (void**)(&H030::orig), &kD030 },
    { 0x0ea67170u, (void*)(&H031::detour), (void**)(&H031::orig), &kD031 },
    { 0x0ea67280u, (void*)(&H032::detour), (void**)(&H032::orig), &kD032 },
    { 0x0ea674a0u, (void*)(&H033::detour), (void**)(&H033::orig), &kD033 },
    { 0x0ea676b0u, (void*)(&H034::detour), (void**)(&H034::orig), &kD034 },
    { 0x0ea67740u, (void*)(&H035::detour), (void**)(&H035::orig), &kD035 },
    { 0x0ea67950u, (void*)(&H036::detour), (void**)(&H036::orig), &kD036 },
    { 0x0ea67a10u, (void*)(&H037::detour), (void**)(&H037::orig), &kD037 },
    { 0x0ea67b10u, (void*)(&H038::detour), (void**)(&H038::orig), &kD038 },
    { 0x0ea67b20u, (void*)(&H039::detour), (void**)(&H039::orig), &kD039 },
    { 0x0ea67b80u, (void*)(&H040::detour), (void**)(&H040::orig), &kD040 },
    { 0x0ea29c20u, (void*)(&H041::detour), (void**)(&H041::orig), &kD041 },
    { 0x0ea67b90u, (void*)(&H042::detour), (void**)(&H042::orig), &kD042 },
    { 0x0ea680e0u, (void*)(&H043::detour), (void**)(&H043::orig), &kD043 },
    { 0x0ea64dd0u, (void*)(&H044::detour), (void**)(&H044::orig), &kD044 },
    { 0x0ea68220u, (void*)(&H045::detour), (void**)(&H045::orig), &kD045 },
    { 0x0ea68320u, (void*)(&H046::detour), (void**)(&H046::orig), &kD046 },
    { 0x0ea68430u, (void*)(&H047::detour), (void**)(&H047::orig), &kD047 },
    { 0x0ea68490u, (void*)(&H048::detour), (void**)(&H048::orig), &kD048 },
    { 0x0ea68580u, (void*)(&H049::detour), (void**)(&H049::orig), &kD049 },
    { 0x0ea68620u, (void*)(&H050::detour), (void**)(&H050::orig), &kD050 },
    { 0x0ea686e0u, (void*)(&H051::detour), (void**)(&H051::orig), &kD051 },
    { 0x0ea687c0u, (void*)(&H052::detour), (void**)(&H052::orig), &kD052 },
    { 0x0ea68890u, (void*)(&H053::detour), (void**)(&H053::orig), &kD053 },
    { 0x0ea68900u, (void*)(&H054::detour), (void**)(&H054::orig), &kD054 },
    { 0x0ea68b40u, (void*)(&H055::detour), (void**)(&H055::orig), &kD055 },
    { 0x0ea68c10u, (void*)(&H056::detour), (void**)(&H056::orig), &kD056 },
    { 0x0ea68c20u, (void*)(&H057::detour), (void**)(&H057::orig), &kD057 },
    { 0x0ea68c60u, (void*)(&H058::detour), (void**)(&H058::orig), &kD058 },
    { 0x0ea26980u, (void*)(&H059::detour), (void**)(&H059::orig), &kD059 },
    { 0x0ea68c70u, (void*)(&H060::detour), (void**)(&H060::orig), &kD060 },
    { 0x0ea68d70u, (void*)(&H061::detour), (void**)(&H061::orig), &kD061 },
    { 0x0ea68e70u, (void*)(&H062::detour), (void**)(&H062::orig), &kD062 },
    { 0x0ea68e80u, (void*)(&H063::detour), (void**)(&H063::orig), &kD063 },
    { 0x0ea68f00u, (void*)(&H064::detour), (void**)(&H064::orig), &kD064 },
    { 0x0ea68fe0u, (void*)(&H065::detour), (void**)(&H065::orig), &kD065 },
    { 0x0ea69070u, (void*)(&H066::detour), (void**)(&H066::orig), &kD066 },
    { 0x0ea692f0u, (void*)(&H067::detour), (void**)(&H067::orig), &kD067 },
    { 0x0ea69550u, (void*)(&H068::detour), (void**)(&H068::orig), &kD068 },
    { 0x0ea69620u, (void*)(&H069::detour), (void**)(&H069::orig), &kD069 },
    { 0x0ea69aa0u, (void*)(&H070::detour), (void**)(&H070::orig), &kD070 },
    { 0x0ea69b80u, (void*)(&H071::detour), (void**)(&H071::orig), &kD071 },
    { 0x0ea69c80u, (void*)(&H072::detour), (void**)(&H072::orig), &kD072 },
    { 0x0ea69ce0u, (void*)(&H073::detour), (void**)(&H073::orig), &kD073 },
    { 0x0ea69dc0u, (void*)(&H074::detour), (void**)(&H074::orig), &kD074 },
    { 0x0ea69fc0u, (void*)(&H075::detour), (void**)(&H075::orig), &kD075 },
    { 0x0ea6a0e0u, (void*)(&H076::detour), (void**)(&H076::orig), &kD076 },
    { 0x0ea6a170u, (void*)(&H077::detour), (void**)(&H077::orig), &kD077 },
    { 0x0ea6a230u, (void*)(&H078::detour), (void**)(&H078::orig), &kD078 },
    { 0x0ea6a470u, (void*)(&H079::detour), (void**)(&H079::orig), &kD079 },
    { 0x0ea6a780u, (void*)(&H080::detour), (void**)(&H080::orig), &kD080 },
    { 0x0ea6aa80u, (void*)(&H081::detour), (void**)(&H081::orig), &kD081 },
    { 0x0ea6ab30u, (void*)(&H082::detour), (void**)(&H082::orig), &kD082 },
    { 0x0ea27910u, (void*)(&H083::detour), (void**)(&H083::orig), &kD083 },
    { 0x0ea6ab90u, (void*)(&H084::detour), (void**)(&H084::orig), &kD084 },
    { 0x0ea67050u, (void*)(&H085::detour), (void**)(&H085::orig), &kD085 },
    { 0x0ea6ac30u, (void*)(&H086::detour), (void**)(&H086::orig), &kD086 },
    { 0x0ea6ac40u, (void*)(&H087::detour), (void**)(&H087::orig), &kD087 },
    { 0x0ea6ad10u, (void*)(&H088::detour), (void**)(&H088::orig), &kD088 },
    { 0x0ea6ada0u, (void*)(&H089::detour), (void**)(&H089::orig), &kD089 },
    { 0x0ea6b070u, (void*)(&H090::detour), (void**)(&H090::orig), &kD090 },
    { 0x0ea6b280u, (void*)(&H091::detour), (void**)(&H091::orig), &kD091 },
    { 0x0ea6b350u, (void*)(&H092::detour), (void**)(&H092::orig), &kD092 },
    { 0x0ea6b3b0u, (void*)(&H093::detour), (void**)(&H093::orig), &kD093 },
    { 0x0ea67330u, (void*)(&H094::detour), (void**)(&H094::orig), &kD094 },
    { 0x0ea6b5b0u, (void*)(&H095::detour), (void**)(&H095::orig), &kD095 },
    { 0x0ea6b670u, (void*)(&H096::detour), (void**)(&H096::orig), &kD096 },
    { 0x0ea6b710u, (void*)(&H097::detour), (void**)(&H097::orig), &kD097 },
    { 0x0ea6b940u, (void*)(&H098::detour), (void**)(&H098::orig), &kD098 },
    { 0x0ea6b9a0u, (void*)(&H099::detour), (void**)(&H099::orig), &kD099 },
    { 0x0ea6ba60u, (void*)(&H100::detour), (void**)(&H100::orig), &kD100 },
    { 0x0ea6bb30u, (void*)(&H101::detour), (void**)(&H101::orig), &kD101 },
    { 0x0ea6bbc0u, (void*)(&H102::detour), (void**)(&H102::orig), &kD102 },
    { 0x0ea6a9d0u, (void*)(&H103::detour), (void**)(&H103::orig), &kD103 },
    { 0x0ea6bca0u, (void*)(&H104::detour), (void**)(&H104::orig), &kD104 },
    { 0x0ea6bdb0u, (void*)(&H105::detour), (void**)(&H105::orig), &kD105 },
    { 0x0ea6bf40u, (void*)(&H106::detour), (void**)(&H106::orig), &kD106 },
    { 0x0ea67270u, (void*)(&H107::detour), (void**)(&H107::orig), &kD107 },
    { 0x0ea6bf80u, (void*)(&H108::detour), (void**)(&H108::orig), &kD108 },
    { 0x0ea6bfc0u, (void*)(&H109::detour), (void**)(&H109::orig), &kD109 },
    { 0x0ea6bfd0u, (void*)(&H110::detour), (void**)(&H110::orig), &kD110 },
    { 0x0ea6c030u, (void*)(&H111::detour), (void**)(&H111::orig), &kD111 },
    { 0x0ea6c100u, (void*)(&H112::detour), (void**)(&H112::orig), &kD112 },
    { 0x0ea6c1a0u, (void*)(&H113::detour), (void**)(&H113::orig), &kD113 },
    { 0x0ea6c230u, (void*)(&H114::detour), (void**)(&H114::orig), &kD114 },
    { 0x0ea6c5a0u, (void*)(&H115::detour), (void**)(&H115::orig), &kD115 },
    { 0x0ea6c7c0u, (void*)(&H116::detour), (void**)(&H116::orig), &kD116 },
    { 0x0ea6c7d0u, (void*)(&H117::detour), (void**)(&H117::orig), &kD117 },
    { 0x0ea33bb0u, (void*)(&H118::detour), (void**)(&H118::orig), &kD118 },
    { 0x0ea6c920u, (void*)(&H119::detour), (void**)(&H119::orig), &kD119 },
    { 0x0ea6c9c0u, (void*)(&H120::detour), (void**)(&H120::orig), &kD120 },
    { 0x0ea6ca90u, (void*)(&H121::detour), (void**)(&H121::orig), &kD121 },
    { 0x0ea6cb50u, (void*)(&H122::detour), (void**)(&H122::orig), &kD122 },
    { 0x0ea6cc10u, (void*)(&H123::detour), (void**)(&H123::orig), &kD123 },
    { 0x0ea6ccf0u, (void*)(&H124::detour), (void**)(&H124::orig), &kD124 },
    { 0x0ea6cd60u, (void*)(&H125::detour), (void**)(&H125::orig), &kD125 },
    { 0x0ea6ce20u, (void*)(&H126::detour), (void**)(&H126::orig), &kD126 },
    { 0x0ea34130u, (void*)(&H127::detour), (void**)(&H127::orig), &kD127 },
    { 0x0ea6cf20u, (void*)(&H128::detour), (void**)(&H128::orig), &kD128 },
    { 0x0ea6cf80u, (void*)(&H129::detour), (void**)(&H129::orig), &kD129 },
    { 0x0ea6d090u, (void*)(&H130::detour), (void**)(&H130::orig), &kD130 },
    { 0x0ea6d150u, (void*)(&H131::detour), (void**)(&H131::orig), &kD131 },
    { 0x0ea6d620u, (void*)(&H132::detour), (void**)(&H132::orig), &kD132 },
    { 0x0ea6d6f0u, (void*)(&H133::detour), (void**)(&H133::orig), &kD133 },
    { 0x0ea6daa0u, (void*)(&H134::detour), (void**)(&H134::orig), &kD134 },
    { 0x0ea6db40u, (void*)(&H135::detour), (void**)(&H135::orig), &kD135 },
    { 0x0ea6dc00u, (void*)(&H136::detour), (void**)(&H136::orig), &kD136 },
    { 0x0ea6dda0u, (void*)(&H137::detour), (void**)(&H137::orig), &kD137 },
    { 0x0ea6de20u, (void*)(&H138::detour), (void**)(&H138::orig), &kD138 },
    { 0x0ea6e0c0u, (void*)(&H139::detour), (void**)(&H139::orig), &kD139 },
    { 0x0ea33670u, (void*)(&H140::detour), (void**)(&H140::orig), &kD140 },
    { 0x0ea6e120u, (void*)(&H141::detour), (void**)(&H141::orig), &kD141 },
    { 0x0ea6e200u, (void*)(&H142::detour), (void**)(&H142::orig), &kD142 },
    { 0x0ea6e210u, (void*)(&H143::detour), (void**)(&H143::orig), &kD143 },
    { 0x0ea6e2d0u, (void*)(&H144::detour), (void**)(&H144::orig), &kD144 },
    { 0x0ea6e3b0u, (void*)(&H145::detour), (void**)(&H145::orig), &kD145 },
    { 0x0ea6e3f0u, (void*)(&H146::detour), (void**)(&H146::orig), &kD146 },
    { 0x0ea6e4f0u, (void*)(&H147::detour), (void**)(&H147::orig), &kD147 },
    { 0x0ea6e5c0u, (void*)(&H148::detour), (void**)(&H148::orig), &kD148 },
    { 0x0ea6e660u, (void*)(&H149::detour), (void**)(&H149::orig), &kD149 },
    { 0x0ea6e730u, (void*)(&H150::detour), (void**)(&H150::orig), &kD150 },
    { 0x0ea6e810u, (void*)(&H151::detour), (void**)(&H151::orig), &kD151 },
    { 0x0ea6e8d0u, (void*)(&H152::detour), (void**)(&H152::orig), &kD152 },
    { 0x0ea6eab0u, (void*)(&H153::detour), (void**)(&H153::orig), &kD153 },
    { 0x0ea6eb50u, (void*)(&H154::detour), (void**)(&H154::orig), &kD154 },
    { 0x0ea6ec40u, (void*)(&H155::detour), (void**)(&H155::orig), &kD155 },
    { 0x0ea6ef80u, (void*)(&H156::detour), (void**)(&H156::orig), &kD156 },
    { 0x0ea6f030u, (void*)(&H157::detour), (void**)(&H157::orig), &kD157 },
    { 0x0ea6f100u, (void*)(&H158::detour), (void**)(&H158::orig), &kD158 },
    { 0x0ea6f4e0u, (void*)(&H159::detour), (void**)(&H159::orig), &kD159 },
    { 0x0ea65450u, (void*)(&H160::detour), (void**)(&H160::orig), &kD160 },
    { 0x0ea6b8c0u, (void*)(&H161::detour), (void**)(&H161::orig), &kD161 },
    { 0x0ea6f5b0u, (void*)(&H162::detour), (void**)(&H162::orig), &kD162 },
    { 0x0ea6f740u, (void*)(&H163::detour), (void**)(&H163::orig), &kD163 },
    { 0x0ea6f8e0u, (void*)(&H164::detour), (void**)(&H164::orig), &kD164 },
    { 0x0ea6f9a0u, (void*)(&H165::detour), (void**)(&H165::orig), &kD165 },
    { 0x0ea6fa70u, (void*)(&H166::detour), (void**)(&H166::orig), &kD166 },
    { 0x0ea6fa80u, (void*)(&H167::detour), (void**)(&H167::orig), &kD167 },
    { 0x0ea6faf0u, (void*)(&H168::detour), (void**)(&H168::orig), &kD168 },
    { 0x0ea6fbe0u, (void*)(&H169::detour), (void**)(&H169::orig), &kD169 },
    { 0x0ea6fdd0u, (void*)(&H170::detour), (void**)(&H170::orig), &kD170 },
    { 0x0ea6d1b0u, (void*)(&H171::detour), (void**)(&H171::orig), &kD171 },
    { 0x0ea6fe60u, (void*)(&H172::detour), (void**)(&H172::orig), &kD172 },
    { 0x0ea6ff60u, (void*)(&H173::detour), (void**)(&H173::orig), &kD173 },
    { 0x0ea70060u, (void*)(&H174::detour), (void**)(&H174::orig), &kD174 },
    { 0x0ea700e0u, (void*)(&H175::detour), (void**)(&H175::orig), &kD175 },
    { 0x0ea701a0u, (void*)(&H176::detour), (void**)(&H176::orig), &kD176 },
    { 0x0ea70ac0u, (void*)(&H177::detour), (void**)(&H177::orig), &kD177 },
    { 0x0ea70ad0u, (void*)(&H178::detour), (void**)(&H178::orig), &kD178 },
    { 0x0ea70b70u, (void*)(&H179::detour), (void**)(&H179::orig), &kD179 },
    { 0x0ea71050u, (void*)(&H180::detour), (void**)(&H180::orig), &kD180 },
    { 0x0ea71060u, (void*)(&H181::detour), (void**)(&H181::orig), &kD181 },
    { 0x0ea71120u, (void*)(&H182::detour), (void**)(&H182::orig), &kD182 },
    { 0x0ea711e0u, (void*)(&H183::detour), (void**)(&H183::orig), &kD183 },
    { 0x0ea71270u, (void*)(&H184::detour), (void**)(&H184::orig), &kD184 },
    { 0x0ea71340u, (void*)(&H185::detour), (void**)(&H185::orig), &kD185 },
    { 0x0ea71460u, (void*)(&H186::detour), (void**)(&H186::orig), &kD186 },
    { 0x0ea714d0u, (void*)(&H187::detour), (void**)(&H187::orig), &kD187 },
    { 0x0ea71530u, (void*)(&H188::detour), (void**)(&H188::orig), &kD188 },
    { 0x0ea71600u, (void*)(&H189::detour), (void**)(&H189::orig), &kD189 },
    { 0x0ea71610u, (void*)(&H190::detour), (void**)(&H190::orig), &kD190 },
    { 0x0ea716b0u, (void*)(&H191::detour), (void**)(&H191::orig), &kD191 },
    { 0x0ea71770u, (void*)(&H192::detour), (void**)(&H192::orig), &kD192 },
    { 0x0ea71910u, (void*)(&H193::detour), (void**)(&H193::orig), &kD193 },
    { 0x0ea71b20u, (void*)(&H194::detour), (void**)(&H194::orig), &kD194 },
    { 0x0ea71b80u, (void*)(&H195::detour), (void**)(&H195::orig), &kD195 },
    { 0x0ea71c50u, (void*)(&H196::detour), (void**)(&H196::orig), &kD196 },
    { 0x0ea71e70u, (void*)(&H197::detour), (void**)(&H197::orig), &kD197 },
    { 0x0ea71ef0u, (void*)(&H198::detour), (void**)(&H198::orig), &kD198 },
    { 0x0ea71f00u, (void*)(&H199::detour), (void**)(&H199::orig), &kD199 },
    { 0x0ea71f10u, (void*)(&H200::detour), (void**)(&H200::orig), &kD200 },
    { 0x0ea722b0u, (void*)(&H201::detour), (void**)(&H201::orig), &kD201 },
    { 0x0ea72490u, (void*)(&H202::detour), (void**)(&H202::orig), &kD202 },
    { 0x0ea72600u, (void*)(&H203::detour), (void**)(&H203::orig), &kD203 },
    { 0x0ea72980u, (void*)(&H204::detour), (void**)(&H204::orig), &kD204 },
    { 0x0ea729c0u, (void*)(&H205::detour), (void**)(&H205::orig), &kD205 },
    { 0x0ea72e40u, (void*)(&H206::detour), (void**)(&H206::orig), &kD206 },
    { 0x0ea72e50u, (void*)(&H207::detour), (void**)(&H207::orig), &kD207 },
    { 0x0ea72fd0u, (void*)(&H208::detour), (void**)(&H208::orig), &kD208 },
    { 0x0ea73030u, (void*)(&H209::detour), (void**)(&H209::orig), &kD209 },
    { 0x0ea730e0u, (void*)(&H210::detour), (void**)(&H210::orig), &kD210 },
    { 0x0ea73190u, (void*)(&H211::detour), (void**)(&H211::orig), &kD211 },
    { 0x0ea73250u, (void*)(&H212::detour), (void**)(&H212::orig), &kD212 },
    { 0x0ea73340u, (void*)(&H213::detour), (void**)(&H213::orig), &kD213 },
    { 0x0ea73c00u, (void*)(&H214::detour), (void**)(&H214::orig), &kD214 },
    { 0x0ea73ce0u, (void*)(&H215::detour), (void**)(&H215::orig), &kD215 },
    { 0x0ea73e50u, (void*)(&H216::detour), (void**)(&H216::orig), &kD216 },
    { 0x0ea73f90u, (void*)(&H217::detour), (void**)(&H217::orig), &kD217 },
    { 0x0ea74060u, (void*)(&H218::detour), (void**)(&H218::orig), &kD218 },
    { 0x0ea74120u, (void*)(&H219::detour), (void**)(&H219::orig), &kD219 },
    { 0x0ea74440u, (void*)(&H220::detour), (void**)(&H220::orig), &kD220 },
    { 0x0ea74510u, (void*)(&H221::detour), (void**)(&H221::orig), &kD221 },
    { 0x0ea745a0u, (void*)(&H222::detour), (void**)(&H222::orig), &kD222 },
    { 0x0ea74600u, (void*)(&H223::detour), (void**)(&H223::orig), &kD223 },
    { 0x0ea74830u, (void*)(&H224::detour), (void**)(&H224::orig), &kD224 },
    { 0x0ea74990u, (void*)(&H225::detour), (void**)(&H225::orig), &kD225 },
    { 0x0ea75170u, (void*)(&H226::detour), (void**)(&H226::orig), &kD226 },
    { 0x0ea75230u, (void*)(&H227::detour), (void**)(&H227::orig), &kD227 },
    { 0x0ea75d90u, (void*)(&H228::detour), (void**)(&H228::orig), &kD228 },
    { 0x0ea75fb0u, (void*)(&H229::detour), (void**)(&H229::orig), &kD229 },
    { 0x0ea761c0u, (void*)(&H230::detour), (void**)(&H230::orig), &kD230 },
    { 0x0ea762f0u, (void*)(&H231::detour), (void**)(&H231::orig), &kD231 },
    { 0x0ea763f0u, (void*)(&H232::detour), (void**)(&H232::orig), &kD232 },
    { 0x0ea764c0u, (void*)(&H233::detour), (void**)(&H233::orig), &kD233 },
    { 0x0ea76540u, (void*)(&H234::detour), (void**)(&H234::orig), &kD234 },
    { 0x0ea765c0u, (void*)(&H235::detour), (void**)(&H235::orig), &kD235 },
    { 0x0ea765d0u, (void*)(&H236::detour), (void**)(&H236::orig), &kD236 },
    { 0x0ea74b20u, (void*)(&H237::detour), (void**)(&H237::orig), &kD237 },
    { 0x0ea76720u, (void*)(&H238::detour), (void**)(&H238::orig), &kD238 },
    { 0x0ea767d0u, (void*)(&H239::detour), (void**)(&H239::orig), &kD239 },
    { 0x0ea76970u, (void*)(&H240::detour), (void**)(&H240::orig), &kD240 },
    { 0x0ea76a40u, (void*)(&H241::detour), (void**)(&H241::orig), &kD241 },
    { 0x0ea74930u, (void*)(&H242::detour), (void**)(&H242::orig), &kD242 },
    { 0x0ea76a50u, (void*)(&H243::detour), (void**)(&H243::orig), &kD243 },
    { 0x0ea76b50u, (void*)(&H244::detour), (void**)(&H244::orig), &kD244 },
    { 0x0ea76d50u, (void*)(&H245::detour), (void**)(&H245::orig), &kD245 },
    { 0x0ea76e10u, (void*)(&H246::detour), (void**)(&H246::orig), &kD246 },
    { 0x0ea76ea0u, (void*)(&H247::detour), (void**)(&H247::orig), &kD247 },
    { 0x0ea76f80u, (void*)(&H248::detour), (void**)(&H248::orig), &kD248 },
    { 0x0ea77260u, (void*)(&H249::detour), (void**)(&H249::orig), &kD249 },
    { 0x0ea772f0u, (void*)(&H250::detour), (void**)(&H250::orig), &kD250 },
    { 0x0ea77360u, (void*)(&H251::detour), (void**)(&H251::orig), &kD251 },
    { 0x0ea77760u, (void*)(&H252::detour), (void**)(&H252::orig), &kD252 },
    { 0x0ea771d0u, (void*)(&H253::detour), (void**)(&H253::orig), &kD253 },
    { 0x0ea77830u, (void*)(&H254::detour), (void**)(&H254::orig), &kD254 },
    { 0x0ea77840u, (void*)(&H255::detour), (void**)(&H255::orig), &kD255 },
    { 0x0ea77b40u, (void*)(&H256::detour), (void**)(&H256::orig), &kD256 },
    { 0x0ea77b90u, (void*)(&H257::detour), (void**)(&H257::orig), &kD257 },
    { 0x0ea77c70u, (void*)(&H258::detour), (void**)(&H258::orig), &kD258 },
    { 0x0ea77ff0u, (void*)(&H259::detour), (void**)(&H259::orig), &kD259 },
    { 0x0ea780c0u, (void*)(&H260::detour), (void**)(&H260::orig), &kD260 },
    { 0x0ea78160u, (void*)(&H261::detour), (void**)(&H261::orig), &kD261 },
    { 0x0ea78240u, (void*)(&H262::detour), (void**)(&H262::orig), &kD262 },
    { 0x0ea78310u, (void*)(&H263::detour), (void**)(&H263::orig), &kD263 },
    { 0x0ea78320u, (void*)(&H264::detour), (void**)(&H264::orig), &kD264 },
    { 0x0ea78420u, (void*)(&H265::detour), (void**)(&H265::orig), &kD265 },
    { 0x0ea78460u, (void*)(&H266::detour), (void**)(&H266::orig), &kD266 },
    { 0x0ea78520u, (void*)(&H267::detour), (void**)(&H267::orig), &kD267 },
    { 0x0ea78640u, (void*)(&H268::detour), (void**)(&H268::orig), &kD268 },
    { 0x0ea78710u, (void*)(&H269::detour), (void**)(&H269::orig), &kD269 },
    { 0x0ea75aa0u, (void*)(&H270::detour), (void**)(&H270::orig), &kD270 },
    { 0x0ea78770u, (void*)(&H271::detour), (void**)(&H271::orig), &kD271 },
    { 0x0ea78970u, (void*)(&H272::detour), (void**)(&H272::orig), &kD272 },
    { 0x0ea78a70u, (void*)(&H273::detour), (void**)(&H273::orig), &kD273 },
    { 0x0ea78d20u, (void*)(&H274::detour), (void**)(&H274::orig), &kD274 },
    { 0x0ea78fa0u, (void*)(&H275::detour), (void**)(&H275::orig), &kD275 },
    { 0x0ea79060u, (void*)(&H276::detour), (void**)(&H276::orig), &kD276 },
    { 0x0ea707a0u, (void*)(&H277::detour), (void**)(&H277::orig), &kD277 },
    { 0x0ea79120u, (void*)(&H278::detour), (void**)(&H278::orig), &kD278 },
    { 0x0ea791c0u, (void*)(&H279::detour), (void**)(&H279::orig), &kD279 },
    { 0x0ea792e0u, (void*)(&H280::detour), (void**)(&H280::orig), &kD280 },
    { 0x0ea79380u, (void*)(&H281::detour), (void**)(&H281::orig), &kD281 },
    { 0x0ea79400u, (void*)(&H282::detour), (void**)(&H282::orig), &kD282 },
    { 0x0ea795d0u, (void*)(&H283::detour), (void**)(&H283::orig), &kD283 },
    { 0x0ea778c0u, (void*)(&H284::detour), (void**)(&H284::orig), &kD284 },
    { 0x0ea796a0u, (void*)(&H285::detour), (void**)(&H285::orig), &kD285 },
    { 0x0ea78580u, (void*)(&H286::detour), (void**)(&H286::orig), &kD286 },
    { 0x0ea79cf0u, (void*)(&H287::detour), (void**)(&H287::orig), &kD287 },
    { 0x0ea79df0u, (void*)(&H288::detour), (void**)(&H288::orig), &kD288 },
    { 0x0ea79eb0u, (void*)(&H289::detour), (void**)(&H289::orig), &kD289 },
    { 0x0ea78ca0u, (void*)(&H290::detour), (void**)(&H290::orig), &kD290 },
    { 0x0ea79f10u, (void*)(&H291::detour), (void**)(&H291::orig), &kD291 },
    { 0x0ea79f20u, (void*)(&H292::detour), (void**)(&H292::orig), &kD292 },
    { 0x0ea7a330u, (void*)(&H293::detour), (void**)(&H293::orig), &kD293 },
    { 0x0ea7a3f0u, (void*)(&H294::detour), (void**)(&H294::orig), &kD294 },
    { 0x0ea755b0u, (void*)(&H295::detour), (void**)(&H295::orig), &kD295 },
    { 0x0ea7a480u, (void*)(&H296::detour), (void**)(&H296::orig), &kD296 },
    { 0x0ea72c20u, (void*)(&H297::detour), (void**)(&H297::orig), &kD297 },
    { 0x0ea7a570u, (void*)(&H298::detour), (void**)(&H298::orig), &kD298 },
    { 0x0ea7a670u, (void*)(&H299::detour), (void**)(&H299::orig), &kD299 },
    { 0x0ea7a710u, (void*)(&H300::detour), (void**)(&H300::orig), &kD300 },
    { 0x0ea7a7d0u, (void*)(&H301::detour), (void**)(&H301::orig), &kD301 },
    { 0x0ea7a8c0u, (void*)(&H302::detour), (void**)(&H302::orig), &kD302 },
    { 0x0ea7a9c0u, (void*)(&H303::detour), (void**)(&H303::orig), &kD303 },
    { 0x0ea7aa50u, (void*)(&H304::detour), (void**)(&H304::orig), &kD304 },
    { 0x0ea7ab10u, (void*)(&H305::detour), (void**)(&H305::orig), &kD305 },
    { 0x0ea7ab70u, (void*)(&H306::detour), (void**)(&H306::orig), &kD306 },
    { 0x0ea7abc0u, (void*)(&H307::detour), (void**)(&H307::orig), &kD307 },
    { 0x0ea7abd0u, (void*)(&H308::detour), (void**)(&H308::orig), &kD308 },
    { 0x0ea7ac90u, (void*)(&H309::detour), (void**)(&H309::orig), &kD309 },
    { 0x0ea7ad50u, (void*)(&H310::detour), (void**)(&H310::orig), &kD310 },
    { 0x0ea7ad90u, (void*)(&H311::detour), (void**)(&H311::orig), &kD311 },
    { 0x0ea7aff0u, (void*)(&H312::detour), (void**)(&H312::orig), &kD312 },
    { 0x0ea7b5e0u, (void*)(&H313::detour), (void**)(&H313::orig), &kD313 },
    { 0x0ea7b5f0u, (void*)(&H314::detour), (void**)(&H314::orig), &kD314 },
    { 0x0ea7b600u, (void*)(&H315::detour), (void**)(&H315::orig), &kD315 },
    { 0x0ea7b6c0u, (void*)(&H316::detour), (void**)(&H316::orig), &kD316 },
    { 0x0ea7b790u, (void*)(&H317::detour), (void**)(&H317::orig), &kD317 },
    { 0x0ea7b860u, (void*)(&H318::detour), (void**)(&H318::orig), &kD318 },
    { 0x0ea7bb00u, (void*)(&H319::detour), (void**)(&H319::orig), &kD319 },
    { 0x0ea75d30u, (void*)(&H320::detour), (void**)(&H320::orig), &kD320 },
    { 0x0ea7bbc0u, (void*)(&H321::detour), (void**)(&H321::orig), &kD321 },
    { 0x0ea7bca0u, (void*)(&H322::detour), (void**)(&H322::orig), &kD322 },
    { 0x0ea7bd10u, (void*)(&H323::detour), (void**)(&H323::orig), &kD323 },
    { 0x0ea7bde0u, (void*)(&H324::detour), (void**)(&H324::orig), &kD324 },
    { 0x0ea75cc0u, (void*)(&H325::detour), (void**)(&H325::orig), &kD325 },
    { 0x0ea7bec0u, (void*)(&H326::detour), (void**)(&H326::orig), &kD326 },
    { 0x0ea75530u, (void*)(&H327::detour), (void**)(&H327::orig), &kD327 },
    { 0x0ea7bfc0u, (void*)(&H328::detour), (void**)(&H328::orig), &kD328 },
    { 0x0ea7bfd0u, (void*)(&H329::detour), (void**)(&H329::orig), &kD329 },
    { 0x0ea7c0b0u, (void*)(&H330::detour), (void**)(&H330::orig), &kD330 },
    { 0x0ea7c110u, (void*)(&H331::detour), (void**)(&H331::orig), &kD331 },
    { 0x0ea7c420u, (void*)(&H332::detour), (void**)(&H332::orig), &kD332 },
    { 0x0ea7c630u, (void*)(&H333::detour), (void**)(&H333::orig), &kD333 },
    { 0x0ea74f60u, (void*)(&H334::detour), (void**)(&H334::orig), &kD334 },
    { 0x0ea7c640u, (void*)(&H335::detour), (void**)(&H335::orig), &kD335 },
    { 0x0ea7c870u, (void*)(&H336::detour), (void**)(&H336::orig), &kD336 },
    { 0x0ea7c8f0u, (void*)(&H337::detour), (void**)(&H337::orig), &kD337 },
    { 0x0ea7c980u, (void*)(&H338::detour), (void**)(&H338::orig), &kD338 },
    { 0x0ea7ca60u, (void*)(&H339::detour), (void**)(&H339::orig), &kD339 },
    { 0x0ea7caf0u, (void*)(&H340::detour), (void**)(&H340::orig), &kD340 },
    { 0x0ea7cb70u, (void*)(&H341::detour), (void**)(&H341::orig), &kD341 },
    { 0x0ea7cc70u, (void*)(&H342::detour), (void**)(&H342::orig), &kD342 },
    { 0x0ea735e0u, (void*)(&H343::detour), (void**)(&H343::orig), &kD343 },
    { 0x0ea7cd70u, (void*)(&H344::detour), (void**)(&H344::orig), &kD344 },
    { 0x0ea7ce30u, (void*)(&H345::detour), (void**)(&H345::orig), &kD345 },
    { 0x0ea7d8c0u, (void*)(&H346::detour), (void**)(&H346::orig), &kD346 },
    { 0x0ea7d990u, (void*)(&H347::detour), (void**)(&H347::orig), &kD347 },
    { 0x0ea7d9a0u, (void*)(&H348::detour), (void**)(&H348::orig), &kD348 },
    { 0x0ea7e050u, (void*)(&H349::detour), (void**)(&H349::orig), &kD349 },
    { 0x0ea79a30u, (void*)(&H350::detour), (void**)(&H350::orig), &kD350 },
    { 0x0ea7e1b0u, (void*)(&H351::detour), (void**)(&H351::orig), &kD351 },
    { 0x0ea7e550u, (void*)(&H352::detour), (void**)(&H352::orig), &kD352 },
    { 0x0ea7e5c0u, (void*)(&H353::detour), (void**)(&H353::orig), &kD353 },
    { 0x0ea7e600u, (void*)(&H354::detour), (void**)(&H354::orig), &kD354 },
    { 0x0ea7e910u, (void*)(&H355::detour), (void**)(&H355::orig), &kD355 },
    { 0x0ea7e9d0u, (void*)(&H356::detour), (void**)(&H356::orig), &kD356 },
    { 0x0ea7eb60u, (void*)(&H357::detour), (void**)(&H357::orig), &kD357 },
    { 0x0ea7ec00u, (void*)(&H358::detour), (void**)(&H358::orig), &kD358 },
    { 0x0ea7ec90u, (void*)(&H359::detour), (void**)(&H359::orig), &kD359 },
    { 0x0ea7ed50u, (void*)(&H360::detour), (void**)(&H360::orig), &kD360 },
    { 0x0ea7f060u, (void*)(&H361::detour), (void**)(&H361::orig), &kD361 },
    { 0x0ea7f100u, (void*)(&H362::detour), (void**)(&H362::orig), &kD362 },
    { 0x0ea7f1c0u, (void*)(&H363::detour), (void**)(&H363::orig), &kD363 },
    { 0x0ea7f220u, (void*)(&H364::detour), (void**)(&H364::orig), &kD364 },
    { 0x0ea75860u, (void*)(&H365::detour), (void**)(&H365::orig), &kD365 },
    { 0x0ea7c170u, (void*)(&H366::detour), (void**)(&H366::orig), &kD366 },
    { 0x0ea7f390u, (void*)(&H367::detour), (void**)(&H367::orig), &kD367 },
    { 0x0ea7f450u, (void*)(&H368::detour), (void**)(&H368::orig), &kD368 },
    { 0x0ea7f520u, (void*)(&H369::detour), (void**)(&H369::orig), &kD369 },
    { 0x0ea7f690u, (void*)(&H370::detour), (void**)(&H370::orig), &kD370 },
    { 0x0ea7f720u, (void*)(&H371::detour), (void**)(&H371::orig), &kD371 },
    { 0x0ea7f8a0u, (void*)(&H372::detour), (void**)(&H372::orig), &kD372 },
    { 0x0ea7f8e0u, (void*)(&H373::detour), (void**)(&H373::orig), &kD373 },
    { 0x0ea7f9a0u, (void*)(&H374::detour), (void**)(&H374::orig), &kD374 },
    { 0x0ea7fad0u, (void*)(&H375::detour), (void**)(&H375::orig), &kD375 },
    { 0x0ea7fba0u, (void*)(&H376::detour), (void**)(&H376::orig), &kD376 },
    { 0x0ea7fbb0u, (void*)(&H377::detour), (void**)(&H377::orig), &kD377 },
    { 0x0ea7fc50u, (void*)(&H378::detour), (void**)(&H378::orig), &kD378 },
    { 0x0ea7fd50u, (void*)(&H379::detour), (void**)(&H379::orig), &kD379 },
    { 0x0ea7fe50u, (void*)(&H380::detour), (void**)(&H380::orig), &kD380 },
    { 0x0ea7fed0u, (void*)(&H381::detour), (void**)(&H381::orig), &kD381 },
    { 0x0ea7ff80u, (void*)(&H382::detour), (void**)(&H382::orig), &kD382 },
    { 0x0ea7ffc0u, (void*)(&H383::detour), (void**)(&H383::orig), &kD383 },
    { 0x0ea7e820u, (void*)(&H384::detour), (void**)(&H384::orig), &kD384 },
    { 0x0ea80080u, (void*)(&H385::detour), (void**)(&H385::orig), &kD385 },
    { 0x0ea7f280u, (void*)(&H386::detour), (void**)(&H386::orig), &kD386 },
    { 0x0ea80100u, (void*)(&H387::detour), (void**)(&H387::orig), &kD387 },
    { 0x0ea80180u, (void*)(&H388::detour), (void**)(&H388::orig), &kD388 },
    { 0x0ea80220u, (void*)(&H389::detour), (void**)(&H389::orig), &kD389 },
    { 0x0ea794e0u, (void*)(&H390::detour), (void**)(&H390::orig), &kD390 },
    { 0x0ea802c0u, (void*)(&H391::detour), (void**)(&H391::orig), &kD391 },
    { 0x0ea80550u, (void*)(&H392::detour), (void**)(&H392::orig), &kD392 },
    { 0x0ea80800u, (void*)(&H393::detour), (void**)(&H393::orig), &kD393 },
    { 0x0ea808a0u, (void*)(&H394::detour), (void**)(&H394::orig), &kD394 },
    { 0x0ea808f0u, (void*)(&H395::detour), (void**)(&H395::orig), &kD395 },
    { 0x0ea809b0u, (void*)(&H396::detour), (void**)(&H396::orig), &kD396 },
    { 0x0ea80a80u, (void*)(&H397::detour), (void**)(&H397::orig), &kD397 },
    { 0x0ea80b70u, (void*)(&H398::detour), (void**)(&H398::orig), &kD398 },
    { 0x0ea80bf0u, (void*)(&H399::detour), (void**)(&H399::orig), &kD399 },
    { 0x0ea80da0u, (void*)(&H400::detour), (void**)(&H400::orig), &kD400 },
    { 0x0ea759c0u, (void*)(&H401::detour), (void**)(&H401::orig), &kD401 },
    { 0x0ea80e10u, (void*)(&H402::detour), (void**)(&H402::orig), &kD402 },
    { 0x0ea80e70u, (void*)(&H403::detour), (void**)(&H403::orig), &kD403 },
    { 0x0ea80e80u, (void*)(&H404::detour), (void**)(&H404::orig), &kD404 },
    { 0x0ea81270u, (void*)(&H405::detour), (void**)(&H405::orig), &kD405 },
    { 0x0ea81340u, (void*)(&H406::detour), (void**)(&H406::orig), &kD406 },
    { 0x0ea81660u, (void*)(&H407::detour), (void**)(&H407::orig), &kD407 },
    { 0x0ea7e140u, (void*)(&H408::detour), (void**)(&H408::orig), &kD408 },
    { 0x0ea766c0u, (void*)(&H409::detour), (void**)(&H409::orig), &kD409 },
    { 0x0ea816f0u, (void*)(&H410::detour), (void**)(&H410::orig), &kD410 },
    { 0x0ea817e0u, (void*)(&H411::detour), (void**)(&H411::orig), &kD411 },
    { 0x0ea818e0u, (void*)(&H412::detour), (void**)(&H412::orig), &kD412 },
    { 0x0ea81990u, (void*)(&H413::detour), (void**)(&H413::orig), &kD413 },
    { 0x0ea81a00u, (void*)(&H414::detour), (void**)(&H414::orig), &kD414 },
    { 0x0ea81ac0u, (void*)(&H415::detour), (void**)(&H415::orig), &kD415 },
    { 0x0ea81bc0u, (void*)(&H416::detour), (void**)(&H416::orig), &kD416 },
    { 0x0ea81cc0u, (void*)(&H417::detour), (void**)(&H417::orig), &kD417 },
    { 0x0ea81ec0u, (void*)(&H418::detour), (void**)(&H418::orig), &kD418 },
    { 0x0ea81f70u, (void*)(&H419::detour), (void**)(&H419::orig), &kD419 },
    { 0x0ea81fb0u, (void*)(&H420::detour), (void**)(&H420::orig), &kD420 },
    { 0x0ea82080u, (void*)(&H421::detour), (void**)(&H421::orig), &kD421 },
    { 0x0ea7e760u, (void*)(&H422::detour), (void**)(&H422::orig), &kD422 },
    { 0x0ea7f580u, (void*)(&H423::detour), (void**)(&H423::orig), &kD423 },
    { 0x0ea82140u, (void*)(&H424::detour), (void**)(&H424::orig), &kD424 },
    { 0x0ea82190u, (void*)(&H425::detour), (void**)(&H425::orig), &kD425 },
    { 0x0ea82290u, (void*)(&H426::detour), (void**)(&H426::orig), &kD426 },
    { 0x0ea82380u, (void*)(&H427::detour), (void**)(&H427::orig), &kD427 },
    { 0x0ea824f0u, (void*)(&H428::detour), (void**)(&H428::orig), &kD428 },
    { 0x0ea82580u, (void*)(&H429::detour), (void**)(&H429::orig), &kD429 },
    { 0x0ea82640u, (void*)(&H430::detour), (void**)(&H430::orig), &kD430 },
    { 0x0ea82700u, (void*)(&H431::detour), (void**)(&H431::orig), &kD431 },
    { 0x0ea754e0u, (void*)(&H432::detour), (void**)(&H432::orig), &kD432 },
    { 0x0ea827a0u, (void*)(&H433::detour), (void**)(&H433::orig), &kD433 },
    { 0x0ea82860u, (void*)(&H434::detour), (void**)(&H434::orig), &kD434 },
    { 0x0ea828a0u, (void*)(&H435::detour), (void**)(&H435::orig), &kD435 },
    { 0x0ea828f0u, (void*)(&H436::detour), (void**)(&H436::orig), &kD436 },
    { 0x0ea82c90u, (void*)(&H437::detour), (void**)(&H437::orig), &kD437 },
    { 0x0ea82e60u, (void*)(&H438::detour), (void**)(&H438::orig), &kD438 },
    { 0x0ea82e70u, (void*)(&H439::detour), (void**)(&H439::orig), &kD439 },
    { 0x0ea82fb0u, (void*)(&H440::detour), (void**)(&H440::orig), &kD440 },
    { 0x0ea830a0u, (void*)(&H441::detour), (void**)(&H441::orig), &kD441 },
    { 0x0ea831a0u, (void*)(&H442::detour), (void**)(&H442::orig), &kD442 },
    { 0x0ea83870u, (void*)(&H443::detour), (void**)(&H443::orig), &kD443 },
    { 0x0ea83920u, (void*)(&H444::detour), (void**)(&H444::orig), &kD444 },
    { 0x0ea839e0u, (void*)(&H445::detour), (void**)(&H445::orig), &kD445 },
    { 0x0ea83b10u, (void*)(&H446::detour), (void**)(&H446::orig), &kD446 },
    { 0x0ea83c10u, (void*)(&H447::detour), (void**)(&H447::orig), &kD447 },
    { 0x0ea75520u, (void*)(&H448::detour), (void**)(&H448::orig), &kD448 },
    { 0x0ea83cd0u, (void*)(&H449::detour), (void**)(&H449::orig), &kD449 },
    { 0x0ea83ce0u, (void*)(&H450::detour), (void**)(&H450::orig), &kD450 },
    { 0x0ea83da0u, (void*)(&H451::detour), (void**)(&H451::orig), &kD451 },
    { 0x0ea83e20u, (void*)(&H452::detour), (void**)(&H452::orig), &kD452 },
    { 0x0ea71dc0u, (void*)(&H453::detour), (void**)(&H453::orig), &kD453 },
    { 0x0ea72d90u, (void*)(&H454::detour), (void**)(&H454::orig), &kD454 },
    { 0x0ea83e80u, (void*)(&H455::detour), (void**)(&H455::orig), &kD455 },
    { 0x0ea83f70u, (void*)(&H456::detour), (void**)(&H456::orig), &kD456 },
    { 0x0ea842f0u, (void*)(&H457::detour), (void**)(&H457::orig), &kD457 },
    { 0x0ea7de00u, (void*)(&H458::detour), (void**)(&H458::orig), &kD458 },
    { 0x0ea84350u, (void*)(&H459::detour), (void**)(&H459::orig), &kD459 },
    { 0x0ea84410u, (void*)(&H460::detour), (void**)(&H460::orig), &kD460 },
    { 0x0ea844d0u, (void*)(&H461::detour), (void**)(&H461::orig), &kD461 },
    { 0x0ea845b0u, (void*)(&H462::detour), (void**)(&H462::orig), &kD462 },
    { 0x0ea84640u, (void*)(&H463::detour), (void**)(&H463::orig), &kD463 },
    { 0x0ea84700u, (void*)(&H464::detour), (void**)(&H464::orig), &kD464 },
    { 0x0ea848a0u, (void*)(&H465::detour), (void**)(&H465::orig), &kD465 },
    { 0x0ea849a0u, (void*)(&H466::detour), (void**)(&H466::orig), &kD466 },
    { 0x0ea7f300u, (void*)(&H467::detour), (void**)(&H467::orig), &kD467 },
    { 0x0ea7e060u, (void*)(&H468::detour), (void**)(&H468::orig), &kD468 },
    { 0x0ea84a60u, (void*)(&H469::detour), (void**)(&H469::orig), &kD469 },
    { 0x0ea70890u, (void*)(&H470::detour), (void**)(&H470::orig), &kD470 },
    { 0x0ea84b30u, (void*)(&H471::detour), (void**)(&H471::orig), &kD471 },
    { 0x0ea84bf0u, (void*)(&H472::detour), (void**)(&H472::orig), &kD472 },
    { 0x0ea79250u, (void*)(&H473::detour), (void**)(&H473::orig), &kD473 },
    { 0x0ea84cb0u, (void*)(&H474::detour), (void**)(&H474::orig), &kD474 },
    { 0x0ea84d70u, (void*)(&H475::detour), (void**)(&H475::orig), &kD475 },
    { 0x0ea84f50u, (void*)(&H476::detour), (void**)(&H476::orig), &kD476 },
    { 0x0ea85030u, (void*)(&H477::detour), (void**)(&H477::orig), &kD477 },
    { 0x0ea79930u, (void*)(&H478::detour), (void**)(&H478::orig), &kD478 },
    { 0x0ea85080u, (void*)(&H479::detour), (void**)(&H479::orig), &kD479 },
    { 0x0ea85430u, (void*)(&H480::detour), (void**)(&H480::orig), &kD480 },
    { 0x0ea854f0u, (void*)(&H481::detour), (void**)(&H481::orig), &kD481 },
    { 0x0ea85550u, (void*)(&H482::detour), (void**)(&H482::orig), &kD482 },
    { 0x0ea855a0u, (void*)(&H483::detour), (void**)(&H483::orig), &kD483 },
    { 0x0ea85600u, (void*)(&H484::detour), (void**)(&H484::orig), &kD484 },
    { 0x0ea856d0u, (void*)(&H485::detour), (void**)(&H485::orig), &kD485 },
    { 0x0ea85760u, (void*)(&H486::detour), (void**)(&H486::orig), &kD486 },
    { 0x0ea85940u, (void*)(&H487::detour), (void**)(&H487::orig), &kD487 },
    { 0x0ea85ba0u, (void*)(&H488::detour), (void**)(&H488::orig), &kD488 },
    { 0x0ea85c40u, (void*)(&H489::detour), (void**)(&H489::orig), &kD489 },
    { 0x0ea85ca0u, (void*)(&H490::detour), (void**)(&H490::orig), &kD490 },
    { 0x0ea85d20u, (void*)(&H491::detour), (void**)(&H491::orig), &kD491 },
    { 0x0ea85de0u, (void*)(&H492::detour), (void**)(&H492::orig), &kD492 },
    { 0x0ea85fd0u, (void*)(&H493::detour), (void**)(&H493::orig), &kD493 },
    { 0x0ea862d0u, (void*)(&H494::detour), (void**)(&H494::orig), &kD494 },
    { 0x0ea864e0u, (void*)(&H495::detour), (void**)(&H495::orig), &kD495 },
    { 0x0ea86590u, (void*)(&H496::detour), (void**)(&H496::orig), &kD496 },
    { 0x0ea868c0u, (void*)(&H497::detour), (void**)(&H497::orig), &kD497 },
    { 0x0ea86980u, (void*)(&H498::detour), (void**)(&H498::orig), &kD498 },
    { 0x0ea72ba0u, (void*)(&H499::detour), (void**)(&H499::orig), &kD499 },
    { 0x0ea86bd0u, (void*)(&H500::detour), (void**)(&H500::orig), &kD500 },
    { 0x0ea86c70u, (void*)(&H501::detour), (void**)(&H501::orig), &kD501 },
    { 0x0ea86cd0u, (void*)(&H502::detour), (void**)(&H502::orig), &kD502 },
    { 0x0ea86ce0u, (void*)(&H503::detour), (void**)(&H503::orig), &kD503 },
    { 0x0ea86db0u, (void*)(&H504::detour), (void**)(&H504::orig), &kD504 },
    { 0x0ea86f20u, (void*)(&H505::detour), (void**)(&H505::orig), &kD505 },
    { 0x0ea86f30u, (void*)(&H506::detour), (void**)(&H506::orig), &kD506 },
    { 0x0ea87030u, (void*)(&H507::detour), (void**)(&H507::orig), &kD507 },
    { 0x0ea87090u, (void*)(&H508::detour), (void**)(&H508::orig), &kD508 },
    { 0x0ea87410u, (void*)(&H509::detour), (void**)(&H509::orig), &kD509 },
    { 0x0ea874d0u, (void*)(&H510::detour), (void**)(&H510::orig), &kD510 },
    { 0x0ea87530u, (void*)(&H511::detour), (void**)(&H511::orig), &kD511 },
    { 0x0ea876f0u, (void*)(&H512::detour), (void**)(&H512::orig), &kD512 },
    { 0x0ea877b0u, (void*)(&H513::detour), (void**)(&H513::orig), &kD513 },
    { 0x0ea87800u, (void*)(&H514::detour), (void**)(&H514::orig), &kD514 },
    { 0x0ea835f0u, (void*)(&H515::detour), (void**)(&H515::orig), &kD515 },
    { 0x0ea87620u, (void*)(&H516::detour), (void**)(&H516::orig), &kD516 },
};
static const int kHookCount = 517;

}  // namespace ekhbadnljkf_detail
}  // namespace jk

void RegisterEKHBADNLJKFHooks() {
    jk::RegisterHookTable(jk::ekhbadnljkf_detail::kHooks, jk::ekhbadnljkf_detail::kHookCount);
}

int InstallEKHBADNLJKFHooks(uint64_t base) {
    // 正常路径是 dllmain 先 RegisterAll（日志/过滤/签名表都要用）再 Install；
    // 万一没登记，这里兜底登记一次（只在调用顺序不对时发生，会重置过滤表）。
    if (!jk::HasHookTable()) RegisterEKHBADNLJKFHooks();
    return jk::InstallAllHooks(base);
}

int EKHBADNLJKFHookCount() { return jk::ekhbadnljkf_detail::kHookCount; }

void RemoveEKHBADNLJKFHooks() { jk::RemoveAllHooks(); }
