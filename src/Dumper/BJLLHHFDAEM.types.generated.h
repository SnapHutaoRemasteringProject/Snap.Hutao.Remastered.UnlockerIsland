// ==========================================================================
// 由 tools/jkkbgkiafco_hook_gen.py 自动生成 —— 请勿手改，重跑脚本覆盖
// 源 dump: D:\dump\full dump 7.1.cs
// 类: BJLLHHFDAEM   枚举 14 个 / 结构体 12 个
//
// ABI 判定规则（对应 x64 MS ABI）：
//   * 引用类型      -> void*
//   * 枚举          -> enum class : 底层整型
//   * <= 8 字节结构体 -> 按值；纯浮点聚合必须用真实 float/double 字段（走 xmm）
//   * >  8 字节结构体 -> 按引用传参（detour 形参用 const T*）
//   * >  8 字节返回值 -> 隐藏返回指针（detour 直接返回 T，由编译器生成同样的约定）
// ==========================================================================
#pragma once

#include "HookCore.h"

namespace jk {

// GCLHPKAEIPN（枚举，底层 Int32，4 字节）
enum class T_GCLHPKAEIPN : int32_t {
    Normal = 0,
    Top = 1,
    Bottom = 2,
    LeftMost = 3,
    RightMost = 4
};
static_assert(sizeof(T_GCLHPKAEIPN) == 4, "T_GCLHPKAEIPN");
inline const char* enum_name(T_GCLHPKAEIPN v) {
    switch ((int32_t)v) {
    case 0: return "Normal";
    case 1: return "Top";
    case 2: return "Bottom";
    case 3: return "LeftMost";
    case 4: return "RightMost";
    }
    return nullptr;
}

// MEIOFNANEDB（枚举，底层 Int32，4 字节）
enum class T_MEIOFNANEDB : int32_t {
    DUNGEN_ENTRY_TYPE_NONE = 0,
    DUNGEN_ENTRY_TYPE_AVATAR_EXP = 1,
    DUNGEN_ENTRY_TYPE_WEAPON_PROMOTE = 2,
    DUNGEN_ENTRY_TYPE_AVATAR_TALENT = 3,
    DUNGEN_ENTRY_TYPE_RELIQUARY = 4,
    DUNGEN_ENTRY_TYPE_SCOIN = 5,
    DUNGEON_ENTRY_TYPE_OBSCURAE = 6,
    DUNGEON_ENTRY_TYPE_NORMAL = 7,
    DUNGEON_ENTRY_TYPE_TRIAL = 8,
    DUNGEON_ENTRY_TYPE_EFFIGY = 9,
    DUNGEON_ENTRY_TYPE_FLEUR_FAIR = 10,
    DUNGEON_ENTRY_TYPE_CHANNELLER_SLAB_LOOP = 11,
    DUNGEON_ENTRY_TYPE_CHANNELLER_SLAB_ONE_OFF = 12,
    DUNGEON_ENTRY_TYPE_BLITZ_RUSH = 13,
    DUNGEON_ENTRY_TYPE_SUMO = 14,
    DUNGEON_ENTRY_TYPE_ACTIVITY = 15,
    DUNGEON_ENTRY_TYPE_HACHI = 16,
    DUNGEON_ENTRY_TYPE_ROLE_COMBAT = 17,
    DUNGEON_ENTRY_TYPE_LEY_LINE_CHALLENGE = 18
};
static_assert(sizeof(T_MEIOFNANEDB) == 4, "T_MEIOFNANEDB");
inline const char* enum_name(T_MEIOFNANEDB v) {
    switch ((int32_t)v) {
    case 0: return "DUNGEN_ENTRY_TYPE_NONE";
    case 1: return "DUNGEN_ENTRY_TYPE_AVATAR_EXP";
    case 2: return "DUNGEN_ENTRY_TYPE_WEAPON_PROMOTE";
    case 3: return "DUNGEN_ENTRY_TYPE_AVATAR_TALENT";
    case 4: return "DUNGEN_ENTRY_TYPE_RELIQUARY";
    case 5: return "DUNGEN_ENTRY_TYPE_SCOIN";
    case 6: return "DUNGEON_ENTRY_TYPE_OBSCURAE";
    case 7: return "DUNGEON_ENTRY_TYPE_NORMAL";
    case 8: return "DUNGEON_ENTRY_TYPE_TRIAL";
    case 9: return "DUNGEON_ENTRY_TYPE_EFFIGY";
    case 10: return "DUNGEON_ENTRY_TYPE_FLEUR_FAIR";
    case 11: return "DUNGEON_ENTRY_TYPE_CHANNELLER_SLAB_LOOP";
    case 12: return "DUNGEON_ENTRY_TYPE_CHANNELLER_SLAB_ONE_OFF";
    case 13: return "DUNGEON_ENTRY_TYPE_BLITZ_RUSH";
    case 14: return "DUNGEON_ENTRY_TYPE_SUMO";
    case 15: return "DUNGEON_ENTRY_TYPE_ACTIVITY";
    case 16: return "DUNGEON_ENTRY_TYPE_HACHI";
    case 17: return "DUNGEON_ENTRY_TYPE_ROLE_COMBAT";
    case 18: return "DUNGEON_ENTRY_TYPE_LEY_LINE_CHALLENGE";
    }
    return nullptr;
}

// AIOAPEHHHDC（枚举，底层 Int32，4 字节）
enum class T_AIOAPEHHHDC : int32_t {
    INVESTIGATION = 0,
    TASK = 1,
    DUNGEON = 2,
    MONSTER = 3,
    QUEST_GUIDE = 4,
    EDUCATION = 5,
    Count = 6
};
static_assert(sizeof(T_AIOAPEHHHDC) == 4, "T_AIOAPEHHHDC");
inline const char* enum_name(T_AIOAPEHHHDC v) {
    switch ((int32_t)v) {
    case 0: return "INVESTIGATION";
    case 1: return "TASK";
    case 2: return "DUNGEON";
    case 3: return "MONSTER";
    case 4: return "QUEST_GUIDE";
    case 5: return "EDUCATION";
    case 6: return "Count";
    }
    return nullptr;
}

// JCMIHEHLJOE（枚举，底层 Int32，4 字节）
enum class T_JCMIHEHLJOE : int32_t {
    BLOSSOM_REFRESH_NONE = 0,
    BLOSSOM_REFRESH_SCOIN = 1,
    BLOSSOM_REFRESH_WEAPON = 2,
    BLOSSOM_REFRESH_EXP = 3,
    BLOSSOM_REFRESH_CRYSTAL = 4,
    BLOSSOM_REFRESH_INFUSED_CRYSTAL = 5,
    BLOSSOM_REFRESH_DRAGON_SPINE_A = 6,
    BLOSSOM_REFRESH_DRAGON_SPINE_B = 7,
    BLOSSOM_ISLAND_SENTRY_TOWER_A = 8,
    BLOSSOM_ISLAND_SENTRY_TOWER_B = 9,
    BLOSSOM_ISLAND_BOMB = 10,
    BLOSSOM_REFRESH_BLITZ_RUSH_A = 11,
    BLOSSOM_REFRESH_BLITZ_RUSH_B = 12
};
static_assert(sizeof(T_JCMIHEHLJOE) == 4, "T_JCMIHEHLJOE");
inline const char* enum_name(T_JCMIHEHLJOE v) {
    switch ((int32_t)v) {
    case 0: return "BLOSSOM_REFRESH_NONE";
    case 1: return "BLOSSOM_REFRESH_SCOIN";
    case 2: return "BLOSSOM_REFRESH_WEAPON";
    case 3: return "BLOSSOM_REFRESH_EXP";
    case 4: return "BLOSSOM_REFRESH_CRYSTAL";
    case 5: return "BLOSSOM_REFRESH_INFUSED_CRYSTAL";
    case 6: return "BLOSSOM_REFRESH_DRAGON_SPINE_A";
    case 7: return "BLOSSOM_REFRESH_DRAGON_SPINE_B";
    case 8: return "BLOSSOM_ISLAND_SENTRY_TOWER_A";
    case 9: return "BLOSSOM_ISLAND_SENTRY_TOWER_B";
    case 10: return "BLOSSOM_ISLAND_BOMB";
    case 11: return "BLOSSOM_REFRESH_BLITZ_RUSH_A";
    case 12: return "BLOSSOM_REFRESH_BLITZ_RUSH_B";
    }
    return nullptr;
}

// PEHIBGGNNKA（枚举，底层 Int32，4 字节）
enum class T_PEHIBGGNNKA : int32_t {
    UNLOCKED = 0,
    LOCKED_TO_BE_EXPLORED = 1,
    LOCKED_CANNOT_BE_EXPLORED_QUICK_OPENED = 2,
    LOCKED_CANNOT_BE_EXPLORED_TO_BE_QUICK_OPENED = 3,
    LOCKED_CANNOT_BE_EXPLORED_DEFAULT = 4
};
static_assert(sizeof(T_PEHIBGGNNKA) == 4, "T_PEHIBGGNNKA");
inline const char* enum_name(T_PEHIBGGNNKA v) {
    switch ((int32_t)v) {
    case 0: return "UNLOCKED";
    case 1: return "LOCKED_TO_BE_EXPLORED";
    case 2: return "LOCKED_CANNOT_BE_EXPLORED_QUICK_OPENED";
    case 3: return "LOCKED_CANNOT_BE_EXPLORED_TO_BE_QUICK_OPENED";
    case 4: return "LOCKED_CANNOT_BE_EXPLORED_DEFAULT";
    }
    return nullptr;
}

// HEBKGNGHOLK（枚举，底层 Int32，4 字节）
enum class T_HEBKGNGHOLK : int32_t {
    DAILY_DUNGEON_RELIQUARY = 0,
    DAILY_DUNGEON_WEAPON_PROMOTE = 1,
    DAILY_DUNGEON_AVATAR_TALENT = 2,
    TOWER_DUNGEON = 3,
    TRIAL_DUNGEON = 4,
    ROLE_COMBAT_DUNGEON = 5,
    CHAR_MASTER_DUNGEON = 6,
    TRAINING_GUIDE = 7
};
static_assert(sizeof(T_HEBKGNGHOLK) == 4, "T_HEBKGNGHOLK");
inline const char* enum_name(T_HEBKGNGHOLK v) {
    switch ((int32_t)v) {
    case 0: return "DAILY_DUNGEON_RELIQUARY";
    case 1: return "DAILY_DUNGEON_WEAPON_PROMOTE";
    case 2: return "DAILY_DUNGEON_AVATAR_TALENT";
    case 3: return "TOWER_DUNGEON";
    case 4: return "TRIAL_DUNGEON";
    case 5: return "ROLE_COMBAT_DUNGEON";
    case 6: return "CHAR_MASTER_DUNGEON";
    case 7: return "TRAINING_GUIDE";
    }
    return nullptr;
}

// BLCHPDIABIG（枚举，底层 Int32，4 字节）
enum class T_BLCHPDIABIG : int32_t {
    All = 0,
    Common = 1,
    Elite = 2,
    Boss = 3,
    Blossom = 4,
    EnumCount = 5
};
static_assert(sizeof(T_BLCHPDIABIG) == 4, "T_BLCHPDIABIG");
inline const char* enum_name(T_BLCHPDIABIG v) {
    switch ((int32_t)v) {
    case 0: return "All";
    case 1: return "Common";
    case 2: return "Elite";
    case 3: return "Boss";
    case 4: return "Blossom";
    case 5: return "EnumCount";
    }
    return nullptr;
}

// JNNABMCHMKG（枚举，底层 Int32，4 字节）
enum class T_JNNABMCHMKG : int32_t {
    All = 0,
    Common = 1,
    Elite = 2,
    Boss = 3,
    EnumCount = 4
};
static_assert(sizeof(T_JNNABMCHMKG) == 4, "T_JNNABMCHMKG");
inline const char* enum_name(T_JNNABMCHMKG v) {
    switch ((int32_t)v) {
    case 0: return "All";
    case 1: return "Common";
    case 2: return "Elite";
    case 3: return "Boss";
    case 4: return "EnumCount";
    }
    return nullptr;
}

// MMBJIJOADOD（枚举，底层 Int32，4 字节）
enum class T_MMBJIJOADOD : int32_t {
    Invalid = 0,
    MoveEvent = 1,
    ChangeViewEvent = 2,
    OpenMapEvent = 3,
    OpenCharacterEvent = 4,
    OpenBagEvent = 5,
    OpenGachaEvent = 6,
    OpenChatEvent = 7,
    OpenPaimonEvent = 8,
    ToggleQuestBookEvent = 9,
    ToAvatar1Event = 10,
    ToAvatar2Event = 11,
    ToAvatar3Event = 12,
    ToAvatar4Event = 13,
    TriggerChangeWithSkillEvent = 14,
    CancelChangeWithSkillEvent = 15,
    TriggerWheelMenuEvent = 16,
    CloseWheelMenuEvent = 17,
    TriggerSkill1Event = 18,
    TriggerSkill2Event = 19,
    TriggerSkill3Event = 20,
    TriggerSkill4Event = 21,
    TriggerSkill5Event = 22,
    ReleaseSkill1Event = 23,
    ReleaseSkill2Event = 24,
    ReleaseSkill3Event = 25,
    ReleaseSkill4Event = 26,
    ReleaseSkill5Event = 27,
    SelectingEvent = 28,
    CancelSelectingEvent = 29,
    ToggleAttackModeEvent = 30,
    EnterFocusModeEvent = 31,
    ExitFocusModeEvent = 32,
    TalkOrPickEvent = 33,
    LeftShoulderEvent = 34,
    LeftShoulderReleaseEvent = 35,
    RightShoulderEvent = 36,
    RightShoulderReleaseEvent = 37,
    MenuBackEvent = 38,
    MenuBackingEvent = 39,
    MenuBackingCancelEvent = 40,
    MenuConfirmEvent = 41,
    MenuConfirmingEvent = 42,
    MenuConfirmingCancelEvent = 43,
    MenuLeftEvent = 44,
    MenuLeftPressingEvent = 45,
    MenuLeftJustReleasedEvent = 46,
    MenuUpEvent = 47,
    MenuRightEvent = 48,
    MenuDownEvent = 49,
    LeftStickLeftEvent = 50,
    LeftStickRightEvent = 51,
    LeftStickUpEvent = 52,
    LeftStickDownEvent = 53,
    LeftStickEvent = 54,
    RightStickEvent = 55,
    LeftTriggerEvent = 56,
    LeftTriggerReleaseEvent = 57,
    LeftTriggerAxisEvent = 58,
    RightTriggerEvent = 59,
    RightTriggerReleaseEvent = 60,
    RightTriggerAxisEvent = 61,
    ZoomCameraEvent = 62,
    ResetCameraEvent = 63,
    EnterElementViewEvent = 64,
    ExitElementViewEvent = 65,
    ToggleSlowMoveEvent = 66,
    ToggleSlowMoveTempEvent = 67,
    ResetTempSlowMoveEvent = 68,
    SlipEvent = 69,
    DebugMenuEvent = 70,
    LeftStickButtonEvent = 71,
    RightStickButtonEvent = 72,
    QuestTransportEvent = 73,
    LeftStickVerticalEvent = 74,
    LeftStickHorizontalEvent = 75,
    LeftStickMoveEvent = 76,
    RightStickVerticalEvent = 77,
    RightStickHorizontalEvent = 78,
    RightStickMoveEvent = 79,
    RightStickLeftEvent = 80,
    RightStickRightEvent = 81,
    RightStickUpEvent = 82,
    RightStickDownEvent = 83,
    DPadUpEvent = 84,
    DPadRightEvent = 85,
    DPadDownEvent = 86,
    DPadLeftEvent = 87,
    KeyUpEvent = 88,
    KeyDownEvent = 89,
    KeyLeftEvent = 90,
    KeyRightEvent = 91,
    DPadUpPressingEvent = 92,
    DPadRightPressingEvent = 93,
    DPadDownPressingEvent = 94,
    DPadLeftPressingEvent = 95,
    DPadUpReleaseEvent = 96,
    DPadRightReleaseEvent = 97,
    DPadDownReleaseEvent = 98,
    DPadLeftReleaseEvent = 99,
    HelpEvent = 100,
    MultiplayerEvent = 101,
    ToPrevInteeEvent = 102,
    ToNextInteeEvent = 103,
    JoypadToggleInteeEvent = 104,
    OpenNotifyEvent = 105,
    OpenDungeonFactorEvent = 106,
    OpenHandbookEvent = 107,
    TrackQuestReleaseEvent = 108,
    OpenActivityNormalEvent = 109,
    OpenPushTipsEvent = 110,
    OpenBattlePassEvent = 111,
    ToAvatar5Event = 112,
    OpenChatJoystickEvent = 113,
    OpenChatCancelJoystickEvent = 114,
    ChallengeInterruptEvent = 115,
    ChallengeInterruptJoystickEvent = 116,
    HomeworldCreateCustomSuiteJoystickEvent = 117,
    HomeworldFurnitureSearchJoystickEvent = 118,
    HideEvent = 119,
    TriggerQuickUseEvent = 120,
    ReleaseQuickUseEvent = 121,
    TriggerActivitySkillEvent = 122,
    ReleaseActivitySkillEvent = 123,
    ExteraSelectUpEvent = 124,
    ExteraSelectDownEvent = 125,
    ExteraSelectLeftEvent = 126,
    ExteraSelectRightEvent = 127,
    MusicGameLeftUpEvent = 128,
    MusicGameLeftRightEvent = 129,
    MusicGameLeftDownEvent = 130,
    MusicGameLeftLeftEvent = 131,
    MusicGameRightUpEvent = 132,
    MusicGameRightRightEvent = 133,
    MusicGameRightDownEvent = 134,
    MusicGameRightLeftEvent = 135,
    MusicGameLeftUpReleasedEvent = 136,
    MusicGameLeftRightReleasedEvent = 137,
    MusicGameLeftDownReleasedEvent = 138,
    MusicGameLeftLeftReleasedEvent = 139,
    MusicGameRightUpReleasedEvent = 140,
    MusicGameRightRightReleasedEvent = 141,
    MusicGameRightDownReleasedEvent = 142,
    MusicGameRightLeftReleasedEvent = 143,
    MusicGameFree1Event = 144,
    MusicGameFree2Event = 145,
    MusicGameFree3Event = 146,
    MusicGameFree4Event = 147,
    MusicGameFree5Event = 148,
    MusicGameFree6Event = 149,
    MusicGameFree7Event = 150,
    MusicGameFree8Event = 151,
    MusicGameFree9Event = 152,
    MusicGameFree10Event = 153,
    MusicGameFree11Event = 154,
    MusicGameFree12Event = 155,
    MusicGameFree13Event = 156,
    MusicGameFree14Event = 157,
    MusicGameFree15Event = 158,
    MusicGameFree16Event = 159,
    MusicGameFree17Event = 160,
    MusicGameFree18Event = 161,
    MusicGameFree19Event = 162,
    MusicGameFree20Event = 163,
    MusicGameFree21Event = 164,
    MenuNextEvent = 165,
    F1Event = 166,
    F2Event = 167,
    F3Event = 168,
    ReturnEvent = 169,
    OpenHomeworldHandbookEvent = 170,
    OpenHomeworldEditorEvent = 171,
    OpenTeamPageEvent = 172,
    OpenFriendPageEvent = 173,
    ObjectTurnUpEvent = 174,
    ObjectTurnDownEvent = 175,
    ObjectTurnLeftEvent = 176,
    ObjectTurnRightEvent = 177,
    CameraMoveUpPressedEvent = 178,
    CameraMoveUpReleasedEvent = 179,
    CameraMoveDownPressedEvent = 180,
    CameraMoveDownReleasedEvent = 181,
    CustomLevelSwitchFloatModeEvent = 182,
    CustomLevelDeployConfirmEvent = 183,
    ArrowUpEvent = 184,
    ArrowDownEvent = 185,
    ArrowLeftEvent = 186,
    ArrowRightEvent = 187,
    LeftControlEvent = 188,
    LeftControlReleasedEvent = 189,
    SpaceEvent = 190,
    SpaceReleasedEvent = 191,
    UndoEvent = 192,
    SaveEvent = 193,
    ObjectTurnUpReleaseEvent = 194,
    ObjectTurnDownReleaseEvent = 195,
    ObjectTurnLeftReleaseEvent = 196,
    ObjectTurnRightReleaseEvent = 197,
    ObjectTurnClockwiseEvent = 198,
    ObjectTurnAntiClockwiseEvent = 199,
    ObjectTurnClockwiseReleaseEvent = 200,
    ObjectTurnAntiClockwiseReleaseEvent = 201,
    OpenMenuEvent = 202,
    OpenMenuReleaseEvent = 203,
    MouseLeftButtonEvent = 204,
    HerculesBattleForwardPressEvent = 205,
    HerculesBattleForwardReleaseEvent = 206,
    HerculesBattleBackwardPressEvent = 207,
    HerculesBattleBackwardReleaseEvent = 208,
    HerculesBattleCancelEvent = 209,
    ActivityMapScaleEvent = 210,
    ActivityMapSettingEvent = 211,
    MusicGameFree22Event = 212,
    MusicGameFree23Event = 213,
    MusicGameFree24Event = 214,
    MusicGameFree25Event = 215,
    MusicGameFree26Event = 216,
    TriggerVehicleSkill1Event = 217,
    TriggerVehicleSkill2Event = 218,
    TriggerVehicleSkill3Event = 219,
    TriggerVehicleSkill4Event = 220,
    TriggerVehicleSkill5Event = 221,
    ReleaseVehicleSkill1Event = 222,
    ReleaseVehicleSkill2Event = 223,
    ReleaseVehicleSkill3Event = 224,
    ReleaseVehicleSkill4Event = 225,
    ReleaseVehicleSkill5Event = 226,
    AkaFesAstrolabeLeftTurnPressEvent = 227,
    AkaFesAstrolabeLeftTurnReleaseEvent = 228,
    AkaFesAstrolabeRightTurnPressEvent = 229,
    AkaFesAstrolabeRightTurnReleaseEvent = 230,
    AkaFesAstrolabeHeightChangeEvent = 231,
    SlipReleaseEvent = 232,
    SlowMovePresseEvent = 233,
    SlowMoveReleaseEvent = 234,
    AkaFesAstrolabeHeightChangeReleaseEvent = 235,
    BeyondMoveForwardEvent = 236,
    BeyondMoveLeftEvent = 237,
    BeyondMoveRightEvent = 238,
    BeyondMoveBackwardEvent = 239,
    BeyondSlowMoveEvent = 240,
    BeyondDashEvent = 241,
    BeyondJumpEvent = 242,
    BeyondFallEvent = 243,
    BeyondOpenChatEvent = 244,
    BeyondHideSpecificUIEvent = 245,
    BeyondOpenMicrophoneEvent = 246,
    BeyondOpenSpeakerEvent = 247,
    BeyondInteractive1Event = 248,
    BeyondInteractive2Event = 249,
    BeyondInteractive3Event = 250,
    BeyondOpenExpressionEvent = 251,
    BeyondWheelMenuTriggerEvent = 252,
    BeyondOpenLevelEditEvent = 253,
    BeyondOpenClothingEvent = 254,
    BeyondOpenMapEvent = 255,
    BeyondOpenGuideBookEvent = 256,
    BeyondOpenHallEvent = 257,
    BeyondOpenGachaEvent = 258,
    BeyondOpenBattlePassEvent = 259,
    BeyondOpenRecPlayEvent = 260,
    BeyondOpenReunionEvent = 261,
    BeyondOpenQuestEvent = 262,
    BeyondOpenNotifyEvent = 263,
    BeyondOpenTeamEvent = 264,
    BeyondOpenFriendEvent = 265,
    BeyondMatchRoomEvent = 266,
    BeyondOpenAvatarChangeEvent = 267,
    BeyondOpenLibraryEvent = 268,
    BeyondPickInteractEvent = 269,
    BeyondOpenBagInGameEvent = 270,
    BeyondOpenEquipEvent = 271,
    BeyondOpenMapInGameEvent = 272,
    BeyondAttackEvent = 273,
    BeyondSkill2Event = 274,
    BeyondSkill5Event = 275,
    BeyondAvatarSkill1Event = 276,
    BeyondAvatarSkill2Event = 277,
    BeyondChangeAttackModeEvent = 278,
    BeyondChangeAvatar1Event = 279,
    BeyondChangeAvatar2Event = 280,
    BeyondChangeAvatar3Event = 281,
    BeyondChangeAvatar4Event = 282,
    BeyondUGCSkill1Event = 283,
    BeyondUGCSkill2Event = 284,
    BeyondUGCSkill3Event = 285,
    BeyondUGCSkill4Event = 286,
    BeyondUGCSkill5Event = 287,
    BeyondCreatorKey1Event = 288,
    BeyondCreatorKey2Event = 289,
    BeyondCreatorKey3Event = 290,
    BeyondCreatorKey4Event = 291,
    BeyondCreatorKey5Event = 292,
    BeyondCreatorKey6Event = 293,
    BeyondCreatorKey7Event = 294,
    BeyondCreatorKey8Event = 295,
    BeyondCreatorKey9Event = 296,
    BeyondCreatorKey10Event = 297,
    BeyondCreatorKey11Event = 298,
    BeyondCreatorKey12Event = 299,
    BeyondCreatorKey13Event = 300,
    BeyondCreatorKey14Event = 301,
    BeyondCreatorKey15Event = 302,
    BeyondTeyvatInteractEvent = 303,
    BeyondUGCSkill1ReleaseEvent = 304,
    BeyondUGCSkill2ReleaseEvent = 305,
    BeyondUGCSkill3ReleaseEvent = 306,
    BeyondUGCSkill4ReleaseEvent = 307,
    BeyondUGCSkill5ReleaseEvent = 308,
    BeyondCreatorKey1ReleaseEvent = 309,
    BeyondCreatorKey2ReleaseEvent = 310,
    BeyondCreatorKey3ReleaseEvent = 311,
    BeyondCreatorKey4ReleaseEvent = 312,
    BeyondCreatorKey5ReleaseEvent = 313,
    BeyondCreatorKey6ReleaseEvent = 314,
    BeyondCreatorKey7ReleaseEvent = 315,
    BeyondCreatorKey8ReleaseEvent = 316,
    BeyondCreatorKey9ReleaseEvent = 317,
    BeyondCreatorKey10ReleaseEvent = 318,
    BeyondCreatorKey11ReleaseEvent = 319,
    BeyondCreatorKey12ReleaseEvent = 320,
    BeyondCreatorKey13ReleaseEvent = 321,
    BeyondCreatorKey14ReleaseEvent = 322,
    BeyondCreatorKey15ReleaseEvent = 323,
    BeyondAttackReleaseEvent = 324,
    BeyondOpenBonusInGameEvent = 325,
    BeyondInteractive2ReleaseEvent = 326,
    DPadVerticalEvent = 3701,
    DPadHorizontalEvent = 3702,
    ExteraSelectRightReleaseEvent = 3703,
    UGCOpenGlobalSettingEvent = 3704,
    UGCLeftControlPressEvent = 3705,
    UGCLeftControlReleaseEvent = 3706,
    UGCResetCameraEvent = 3707,
    UGCCameraUpPressEvent = 3708,
    UGCCameraUpReleaseEvent = 3709,
    UGCCameraDownPressEvent = 3710,
    UGCCameraDownReleaseEvent = 3711,
    UGCRedoEvent = 3712,
    UGCUndoEvent = 3713,
    UGCDeploySaveEvent = 3714,
    UGCDeployConfirmEvent = 3715,
    UGCFocusCameraEvent = 3716,
    UGCSwitchFloatEvent = 3717,
    UGCRotateEvent = 3718,
    UGCCopyEvent = 3719,
    UGCRecycleEvent = 3720,
    UGCOpenSettingEvent = 3721,
    UGCOpenTriggerEvent = 3722,
    UGCBatchSelectEvent = 3723,
    UGCSelectSuiteEvent = 3724,
    UGCMoveEvent = 3725,
    WidgetQuickSwitch0Event = 3726,
    WidgetQuickSwitch1Event = 3727,
    WidgetQuickSwitch2Event = 3728,
    WidgetQuickSwitch3Event = 3729,
    ReloadEvent = 3801,
    PenAdvShuffleBoardChargeEvent = 3802,
    PenAdvShuffleBoardChargeReleaseEvent = 3803,
    DPadHorizontalAxisEvent = 3805,
    PenAdvShuffleBoardChargeMoveLEvent = 3806,
    PenAdvShuffleBoardChargeMoveREvent = 3807,
    ExteraSelectDownReleaseEvent = 3808,
    DiveDownDownEvent = 4001,
    DiveDownUpEvent = 4002,
    DiveUpDownEvent = 4003,
    DiveUpUpEvent = 4004,
    JoypadDiveDownDownEvent = 4005,
    JoypadDiveDownUpEvent = 4006,
    JoypadDiveUpDownEvent = 4007,
    JoypadDiveUpUpEvent = 4008,
    JoypadDiveTriggerSkill1Event = 4009,
    JoypadDiveReleaseSkill1Event = 4010,
    ToyBattleQteLeftPressedEvent = 4011,
    ToyBattleQteLeftReleaseEvent = 4012,
    ToyBattleQteRightPressedEvent = 4013,
    ToyBattleQteRightReleaseEvent = 4014,
    PrimaryTabPrevEvent = 4101,
    PrimaryTabNextEvent = 4102,
    KeyCodeCEvent = 4103,
    KeyCodeFEvent = 4104,
    KeyCodeGEvent = 4105,
    KeyCodeQEvent = 4106,
    KeyCodeEEvent = 4107,
    KeyCodeTabEvent = 4108,
    TrackQuestPressEvent = 4109,
    LeftStickButtonPressEvent = 4110,
    LeftStickButtonReleaseEvent = 4111,
    KeyCodeAEvent = 4112,
    KeyCodeDEvent = 4113,
    OpenReunionPageEvent = 4201,
    HomeworldFurnitureSwitchMultiSelectModeEvent = 4301,
    HomeworldLeftShoulderSquareJoyStickEvent = 4302,
    KeyCodeQReleaseEvent = 4303,
    MouseRightButtonEvent = 4304,
    RightStickLeftShowEvent = 4305,
    RightStickRightShowEvent = 4306,
    KeyCodeWEvent = 4401,
    KeyCodeSEvent = 4402,
    ToggleAttackModeReleaseEvent = 4403,
    RightStickButtonReleaseEvent = 4404,
    KeyCodeWPressingEvent = 4405,
    KeyCodeSPressingEvent = 4406,
    KeyCodeAPressingEvent = 4407,
    KeyCodeDPressingEvent = 4408,
    MenuUpReleaseEvent = 4409,
    ReturnKeyReleaseEvent = 4410,
    ReturnKeyPressingEvent = 4411,
    MouseLeftButtonReleaseEvent = 4412,
    MouseLeftButtonPressingEvent = 4413,
    DPadFourWayEvent = 4501,
    MusicGameFree1ReleaseEvent = 4601,
    MusicGameFree2ReleaseEvent = 4602,
    MusicGameFree3ReleaseEvent = 4603,
    MusicGameFree4ReleaseEvent = 4604,
    MusicGameFree5ReleaseEvent = 4605,
    MusicGameFree6ReleaseEvent = 4606,
    MusicGameFree7ReleaseEvent = 4607,
    MusicGameFree8ReleaseEvent = 4608,
    MusicGameFree9ReleaseEvent = 4609,
    MusicGameFree10ReleaseEvent = 4610,
    MusicGameFree11ReleaseEvent = 4611,
    MusicGameFree12ReleaseEvent = 4612,
    MusicGameFree13ReleaseEvent = 4613,
    MusicGameFree14ReleaseEvent = 4614,
    MusicGameFree15ReleaseEvent = 4615,
    MusicGameFree16ReleaseEvent = 4616,
    MusicGameFree17ReleaseEvent = 4617,
    MusicGameFree18ReleaseEvent = 4618,
    MusicGameFree19ReleaseEvent = 4619,
    MusicGameFree20ReleaseEvent = 4620,
    MusicGameFree21ReleaseEvent = 4621,
    LeftShoulderPressingEvent = 4622,
    RightShoulderPressingEvent = 4623,
    MenuRightReleaseEvent = 4624,
    MenuDownReleaseEvent = 4625,
    MusicGameFree25ReleaseEvent = 4626,
    MusicGameFree26ReleaseEvent = 4627,
    KeyCodeHEvent = 4701,
    HideSpecificUIEvent = 4702,
    LeftShiftEvent = 5001,
    MoveEventUnchanged = 5002,
    KeyCodeJEvent = 5003,
    FloatToyQTELeftEvent = 5101,
    FloatToyQTERightEvent = 5102,
    KeyCodeAlpha1Event = 5201,
    KeyCodeAlpha2Event = 5202,
    KeyCodeAlpha3Event = 5203,
    KeyCodeAlpha4Event = 5204,
    KeyCodeAlpha1PressingEvent = 5205,
    KeyCodeAlpha2PressingEvent = 5206,
    KeyCodeAlpha3PressingEvent = 5207,
    KeyCodeAlpha4PressingEvent = 5208,
    KeyCodeAlpha1ReleasedEvent = 5209,
    KeyCodeAlpha2ReleasedEvent = 5210,
    KeyCodeAlpha3ReleasedEvent = 5211,
    KeyCodeAlpha4ReleasedEvent = 5212,
    InstrumentJoypad1Event = 5301,
    InstrumentJoypad2Event = 5302,
    InstrumentJoypad3Event = 5303,
    InstrumentJoypad4Event = 5304,
    InstrumentJoypad5Event = 5305,
    InstrumentJoypad6Event = 5306,
    InstrumentJoypad7Event = 5307,
    InstrumentJoypad8Event = 5308,
    InstrumentJoypad9Event = 5309,
    InstrumentJoypad10Event = 5310,
    InstrumentKeyboard1Event = 5311,
    InstrumentKeyboard2Event = 5312,
    InstrumentKeyboard3Event = 5313,
    InstrumentKeyboard4Event = 5314,
    InstrumentKeyboard5Event = 5315,
    InstrumentKeyboard6Event = 5316,
    InstrumentKeyboard7Event = 5317,
    InstrumentKeyboard8Event = 5318,
    InstrumentKeyboard9Event = 5319,
    InstrumentKeyboard10Event = 5320,
    InstrumentKeyboard11Event = 5321,
    InstrumentKeyboard12Event = 5322,
    InstrumentKeyboard13Event = 5323,
    InstrumentKeyboard14Event = 5324,
    InstrumentKeyboard15Event = 5325,
    InstrumentKeyboard16Event = 5326,
    InstrumentKeyboard17Event = 5327,
    InstrumentKeyboard18Event = 5328,
    InstrumentKeyboard19Event = 5329,
    InstrumentKeyboard20Event = 5330,
    InstrumentKeyboard21Event = 5331,
    InstrumentKeyboard1ReleaseEvent = 5332,
    InstrumentKeyboard2ReleaseEvent = 5333,
    InstrumentKeyboard3ReleaseEvent = 5334,
    InstrumentKeyboard4ReleaseEvent = 5335,
    InstrumentKeyboard5ReleaseEvent = 5336,
    InstrumentKeyboard6ReleaseEvent = 5337,
    InstrumentKeyboard7ReleaseEvent = 5338,
    InstrumentKeyboard8ReleaseEvent = 5339,
    InstrumentKeyboard9ReleaseEvent = 5340,
    InstrumentKeyboard10ReleaseEvent = 5341,
    InstrumentKeyboard11ReleaseEvent = 5342,
    InstrumentKeyboard12ReleaseEvent = 5343,
    InstrumentKeyboard13ReleaseEvent = 5344,
    InstrumentKeyboard14ReleaseEvent = 5345,
    InstrumentKeyboard15ReleaseEvent = 5346,
    InstrumentKeyboard16ReleaseEvent = 5347,
    InstrumentKeyboard17ReleaseEvent = 5348,
    InstrumentKeyboard18ReleaseEvent = 5349,
    InstrumentKeyboard19ReleaseEvent = 5350,
    InstrumentKeyboard20ReleaseEvent = 5351,
    InstrumentKeyboard21ReleaseEvent = 5352,
    InstrumentJoypad1ReleaseEvent = 5353,
    InstrumentJoypad2ReleaseEvent = 5354,
    InstrumentJoypad3ReleaseEvent = 5355,
    InstrumentJoypad4ReleaseEvent = 5356,
    InstrumentJoypad5ReleaseEvent = 5357,
    InstrumentJoypad6ReleaseEvent = 5358,
    InstrumentJoypad7ReleaseEvent = 5359,
    InstrumentJoypad8ReleaseEvent = 5360,
    InstrumentJoypad9ReleaseEvent = 5361,
    InstrumentJoypad10ReleaseEvent = 5362,
    KeyCodeSReleaseEvent = 5363,
    KeyCodeAReleaseEvent = 5364,
    KeyCodeDReleaseEvent = 5365,
    KeyCodeArrowLEvent = 5366,
    KeyCodeArrowREvent = 5367,
    KeyCodeArrowUEvent = 5368,
    KeyCodeArrowDEvent = 5369,
    KeyCodeArrowLPressingEvent = 5370,
    KeyCodeArrowRPressingEvent = 5371,
    KeyCodeArrowUPressingEvent = 5372,
    KeyCodeArrowDPressingEvent = 5373,
    KeyCodeWReleaseEvent = 5374,
    KeyCodeF4PressEvent = 5501,
    KeyCodeF5PressEvent = 5502,
    KeyCodeLeftAltPressEvent = 5503,
    KeyCodeLPressEvent = 5504,
    KeyCodeEndPressEvent = 5505,
    KeyCodePPressEvent = 5506,
    KeyCodeEscPressEvent = 5507,
    KeyCodeZPressEvent = 5508,
    KeyCodeYPressEvent = 5509,
    MouseWheelEvent = 5510,
    KeyCodeVPressEvent = 5511,
    KeyCodeDeletePressEvent = 5512,
    KeyCodeF4PressingEvent = 5513,
    KeyCodeF5PressingEvent = 5514,
    KeyCodeLeftAltPressingEvent = 5515,
    KeyCodeLPressingEvent = 5516,
    KeyCodeEndPressingEvent = 5517,
    KeyCodePPressingEvent = 5518,
    KeyCodeEscPressingEvent = 5519,
    KeyCodeZPressingEvent = 5520,
    KeyCodeYPressingEvent = 5521,
    KeyCodeVPressingEvent = 5522,
    KeyCodeDeletePressingEvent = 5523,
    KeyCodeAlpha5Event = 5524,
    KeyCodeAlpha6Event = 5525,
    KeyCodeAlpha7Event = 5526,
    KeyCodeAlpha8Event = 5527,
    KeyCodeAlpha9Event = 5528,
    KeyCodeAlpha0Event = 5529,
    KeyCodeAlpha5PressingEvent = 5530,
    KeyCodeAlpha6PressingEvent = 5531,
    KeyCodeAlpha7PressingEvent = 5532,
    KeyCodeAlpha8PressingEvent = 5533,
    KeyCodeAlpha9PressingEvent = 5534,
    KeyCodeAlpha0PressingEvent = 5535,
    KeyCodeAlpha5ReleasedEvent = 5536,
    KeyCodeAlpha6ReleasedEvent = 5537,
    KeyCodeAlpha7ReleasedEvent = 5538,
    KeyCodeAlpha8ReleasedEvent = 5539,
    KeyCodeAlpha9ReleasedEvent = 5540,
    KeyCodeAlpha0ReleasedEvent = 5541,
    KeyCodePEvent = 5601,
    ExteraSelectLeftReleaseEvent = 5801,
    KeyUpPressEvent = 5802,
    KeyUpReleaseEvent = 5803,
    UGCKeyCodeEPressingEvent = 6101,
    UGCKeyCodeQPressingEvent = 6102,
    UGCMouseRightButtonReleaseEvent = 6103,
    UGCMouseLeftButtonReleaseEvent = 6104,
    BeyondLeftControlPressEvent = 6105,
    BeyondLeftControlReleaseEvent = 6106,
    BeyondLeftAltPressEvent = 6107,
    BeyondLeftAltReleaseEvent = 6108,
    BeyondSpacePressEvent = 6109,
    BeyondMouseWheelPressEvent = 6110,
    BeyondMouseWheelReleaseEvent = 6111,
    BeyondLeftShiftPressEvent = 6112,
    BeyondLeftShiftReleaseEvent = 6113,
    BeyondFPressEvent = 6114,
    BeyondCapsLockPressEvent = 6115,
    BeyondDeletePressEvent = 6116,
    BeyondZPressEvent = 6117,
    BeyondCPressEvent = 6118,
    BeyondVPressEvent = 6119,
    BeyondSPressEvent = 6120,
    BeyondLPressEvent = 6121,
    BeyondMouseWheelPressingEvent = 6122,
    KeyCodeFReleaseEvent = 6123,
    KeyCodeREvent = 6124,
    KeyCodeRReleaseEvent = 6125,
    KeyCodeQRepeatEvent = 6126,
    KeyCodeERepeatEvent = 6127,
    KeyCodeWRepeatEvent = 6128,
    KeyCodeSRepeatEvent = 6129,
    KeyCodeARepeatEvent = 6130,
    KeyCodeDRepeatEvent = 6131,
    BeyondLeftControlPressingEvent = 6132,
    BeyondLeftAltPressingEvent = 6133,
    BeyondLeftShiftPressingEvent = 6134,
    BeyondMouseRightButtonPressing = 6135,
    UGCCustomPopupHideHint = 6136,
    MenuBackLongPressedEvent = 6137,
    KeyCodeUEvent = 6138,
    KeyCodeJReleaseEvent = 6201,
    OpenNetworkVoiceMicEvent = 6301,
    OpenNetworkVoiceSettingEvent = 6302,
    KeyCodeEReleaseEvent = 6303,
    TriggerInputDragEvent = 6501,
    ReleaseInputDragEvent = 6502,
    InputDragMoveEvent = 6503,
    BeyondMoveForwardReleaseEvent = 6504,
    BeyondMoveBackwardReleaseEvent = 6505,
    BeyondMoveLeftReleaseEvent = 6506,
    BeyondMoveRightReleaseEvent = 6507,
    BeyondSlowMoveReleaseEvent = 6508,
    BeyondDashReleaseEvent = 6509,
    BeyondJumpReleaseEvent = 6510,
    BeyondFallReleaseEvent = 6511,
    BeyondWheelMenuTriggerReleaseEvent = 6512,
    BeyondPickInteractReleaseEvent = 6513,
    BeyondInteractive1ReleaseEvent = 6514,
    KeyMapTest1Event = 6591,
    KeyMapTest2Event = 6592,
    KeyMapTest3Event = 6593,
    BeyondCreatorKey16Event = 6601,
    BeyondCreatorKey17Event = 6602,
    BeyondCreatorKey18Event = 6603,
    BeyondCreatorKey19Event = 6604,
    BeyondCreatorKey20Event = 6605,
    BeyondCreatorKey21Event = 6606,
    BeyondCreatorKey22Event = 6607,
    BeyondCreatorKey23Event = 6608,
    BeyondCreatorKey24Event = 6609,
    BeyondCreatorKey25Event = 6610,
    BeyondCreatorKey26Event = 6611,
    BeyondCreatorKey27Event = 6612,
    BeyondCreatorKey28Event = 6613,
    BeyondCreatorKey29Event = 6614,
    BeyondCreatorKey30Event = 6615,
    BeyondCreatorKey31Event = 6616,
    BeyondCreatorKey32Event = 6617,
    BeyondCreatorKey33Event = 6618,
    BeyondCreatorKey34Event = 6619,
    BeyondCreatorKey35Event = 6620,
    BeyondCreatorKey36Event = 6621,
    BeyondCreatorKey37Event = 6622,
    BeyondCreatorKey38Event = 6623,
    BeyondCreatorKey39Event = 6624,
    BeyondCreatorKey40Event = 6625,
    BeyondCreatorKey41Event = 6626,
    BeyondCreatorKey42Event = 6627,
    BeyondCreatorKey43Event = 6628,
    BeyondCreatorKey16ReleaseEvent = 6636,
    BeyondCreatorKey17ReleaseEvent = 6637,
    BeyondCreatorKey18ReleaseEvent = 6638,
    BeyondCreatorKey19ReleaseEvent = 6639,
    BeyondCreatorKey20ReleaseEvent = 6640,
    BeyondCreatorKey21ReleaseEvent = 6641,
    BeyondCreatorKey22ReleaseEvent = 6642,
    BeyondCreatorKey23ReleaseEvent = 6643,
    BeyondCreatorKey24ReleaseEvent = 6644,
    BeyondCreatorKey25ReleaseEvent = 6645,
    BeyondCreatorKey26ReleaseEvent = 6646,
    BeyondCreatorKey27ReleaseEvent = 6647,
    BeyondCreatorKey28ReleaseEvent = 6648,
    BeyondCreatorKey29ReleaseEvent = 6649,
    BeyondCreatorKey30ReleaseEvent = 6650,
    BeyondCreatorKey31ReleaseEvent = 6651,
    BeyondCreatorKey32ReleaseEvent = 6652,
    BeyondCreatorKey33ReleaseEvent = 6653,
    BeyondCreatorKey34ReleaseEvent = 6654,
    BeyondCreatorKey35ReleaseEvent = 6655,
    BeyondCreatorKey36ReleaseEvent = 6656,
    BeyondCreatorKey37ReleaseEvent = 6657,
    BeyondCreatorKey38ReleaseEvent = 6658,
    BeyondCreatorKey39ReleaseEvent = 6659,
    BeyondCreatorKey40ReleaseEvent = 6660,
    BeyondCreatorKey41ReleaseEvent = 6661,
    BeyondCreatorKey42ReleaseEvent = 6662,
    BeyondCreatorKey43ReleaseEvent = 6663,
    BeyondCardSelectEvent = 6664,
    BeyondLevelTaskEvent = 6665,
    BeyondSmallPropsEvent = 6701,
    BeyondPreTargetingDragMoveEvent = 6702,
    BeyondPreTargetingCancelMouseRightButtonEvent = 6703,
    BeyondPreTargetingCancelEscPressEvent = 6704,
    BeyondPreTargetingCancelRightStickButtonEvent = 6705,
    BeyondSmallPropsReleaseEvent = 6706,
    TpsReloadEvent = 7001,
    TpsAimDownSightsEvent = 7002,
    TpsSkill1FireEvent = 7003,
    TpsSkill2Event = 7004,
    TpsSkill3SprintEvent = 7005,
    TpsSkill4JumpEvent = 7006,
    TpsSkill5Event = 7007,
    TpsActivitySkillEvent = 7008,
    TpsReleaseAimDownSightsEvent = 7009,
    TpsReleaseSkill1FireEvent = 7010,
    TpsReleaseSkill2Event = 7011,
    TpsReleaseSkill3SprintEvent = 7012,
    TpsReleaseSkill4JumpEvent = 7013,
    TpsReleaseSkill5Event = 7014,
    TpsReleaseActivitySkillEvent = 7015,
    TpsReloadSecondaryEvent = 7016,
    TpsAimDownSightsSecondaryEvent = 7017,
    TpsSkill1FireSecondaryEvent = 7018,
    TpsSkill3SprintSecondaryEvent = 7019,
    TpsSkill4JumpSecondaryEvent = 7020,
    TpsChangeWeapon1Event = 7021,
    TpsChangeWeapon2Event = 7022,
    TpsChangeGrenadeEvent = 7023,
    TpsTalkOrPickEvent = 7024,
    TpsReleaseAimDownSightsSecondaryEvent = 7025,
    TpsReleaseSkill1FireSecondaryEvent = 7026,
    TpsReleaseSkill3SprintSecondaryEvent = 7027,
    TpsReleaseSkill4JumpSecondaryEvent = 7028,
    TpsReleaseReloadEvent = 7029,
    TpsReleaseReloadSecondaryEvent = 7030,
    TpsReleaseChangeWeapon1Event = 7031,
    TpsReleaseChangeWeapon2Event = 7032,
    TpsReleaseChangeGrenadeEvent = 7033,
    TpsReleaseTalkOrPickEvent = 7034,
    TalkOrPickPressingEvent = 7035,
    TpsTalkOrPickPressingEvent = 7036,
    BeyondClientUIJoypadNavLeftStickUpEvent = 7101,
    BeyondClientUIJoypadNavLeftStickDownEvent = 7102,
    BeyondClientUIJoypadNavLeftStickLeftEvent = 7103,
    BeyondClientUIJoypadNavLeftStickRightEvent = 7104,
    BeyondClientUIJoypadNavRightStickUpEvent = 7105,
    BeyondClientUIJoypadNavRightStickDownEvent = 7106,
    BeyondClientUIJoypadNavRightStickLeftEvent = 7107,
    BeyondClientUIJoypadNavRightStickRightEvent = 7108,
    BeyondClientUIJoypadNavMenuConfirmEvent = 7109,
    BeyondClientUIJoypadNavMenuBackEvent = 7110,
    BeyondOpenActivityEvent = 7111,
    BeyondClientUIJoypadKeyMenuConfirmEvent = 7112,
    BeyondClientUIJoypadKeyMenuBackEvent = 7113,
    BeyondClientUIJoypadKeyMenuConfirmReleaseEvent = 7114,
    BeyondClientUIJoypadKeyMenuBackReleaseEvent = 7115
};
static_assert(sizeof(T_MMBJIJOADOD) == 4, "T_MMBJIJOADOD");
inline const char* enum_name(T_MMBJIJOADOD v) {
    switch ((int32_t)v) {
    case 0: return "Invalid";
    case 1: return "MoveEvent";
    case 2: return "ChangeViewEvent";
    case 3: return "OpenMapEvent";
    case 4: return "OpenCharacterEvent";
    case 5: return "OpenBagEvent";
    case 6: return "OpenGachaEvent";
    case 7: return "OpenChatEvent";
    case 8: return "OpenPaimonEvent";
    case 9: return "ToggleQuestBookEvent";
    case 10: return "ToAvatar1Event";
    case 11: return "ToAvatar2Event";
    case 12: return "ToAvatar3Event";
    case 13: return "ToAvatar4Event";
    case 14: return "TriggerChangeWithSkillEvent";
    case 15: return "CancelChangeWithSkillEvent";
    case 16: return "TriggerWheelMenuEvent";
    case 17: return "CloseWheelMenuEvent";
    case 18: return "TriggerSkill1Event";
    case 19: return "TriggerSkill2Event";
    case 20: return "TriggerSkill3Event";
    case 21: return "TriggerSkill4Event";
    case 22: return "TriggerSkill5Event";
    case 23: return "ReleaseSkill1Event";
    case 24: return "ReleaseSkill2Event";
    case 25: return "ReleaseSkill3Event";
    case 26: return "ReleaseSkill4Event";
    case 27: return "ReleaseSkill5Event";
    case 28: return "SelectingEvent";
    case 29: return "CancelSelectingEvent";
    case 30: return "ToggleAttackModeEvent";
    case 31: return "EnterFocusModeEvent";
    case 32: return "ExitFocusModeEvent";
    case 33: return "TalkOrPickEvent";
    case 34: return "LeftShoulderEvent";
    case 35: return "LeftShoulderReleaseEvent";
    case 36: return "RightShoulderEvent";
    case 37: return "RightShoulderReleaseEvent";
    case 38: return "MenuBackEvent";
    case 39: return "MenuBackingEvent";
    case 40: return "MenuBackingCancelEvent";
    case 41: return "MenuConfirmEvent";
    case 42: return "MenuConfirmingEvent";
    case 43: return "MenuConfirmingCancelEvent";
    case 44: return "MenuLeftEvent";
    case 45: return "MenuLeftPressingEvent";
    case 46: return "MenuLeftJustReleasedEvent";
    case 47: return "MenuUpEvent";
    case 48: return "MenuRightEvent";
    case 49: return "MenuDownEvent";
    case 50: return "LeftStickLeftEvent";
    case 51: return "LeftStickRightEvent";
    case 52: return "LeftStickUpEvent";
    case 53: return "LeftStickDownEvent";
    case 54: return "LeftStickEvent";
    case 55: return "RightStickEvent";
    case 56: return "LeftTriggerEvent";
    case 57: return "LeftTriggerReleaseEvent";
    case 58: return "LeftTriggerAxisEvent";
    case 59: return "RightTriggerEvent";
    case 60: return "RightTriggerReleaseEvent";
    case 61: return "RightTriggerAxisEvent";
    case 62: return "ZoomCameraEvent";
    case 63: return "ResetCameraEvent";
    case 64: return "EnterElementViewEvent";
    case 65: return "ExitElementViewEvent";
    case 66: return "ToggleSlowMoveEvent";
    case 67: return "ToggleSlowMoveTempEvent";
    case 68: return "ResetTempSlowMoveEvent";
    case 69: return "SlipEvent";
    case 70: return "DebugMenuEvent";
    case 71: return "LeftStickButtonEvent";
    case 72: return "RightStickButtonEvent";
    case 73: return "QuestTransportEvent";
    case 74: return "LeftStickVerticalEvent";
    case 75: return "LeftStickHorizontalEvent";
    case 76: return "LeftStickMoveEvent";
    case 77: return "RightStickVerticalEvent";
    case 78: return "RightStickHorizontalEvent";
    case 79: return "RightStickMoveEvent";
    case 80: return "RightStickLeftEvent";
    case 81: return "RightStickRightEvent";
    case 82: return "RightStickUpEvent";
    case 83: return "RightStickDownEvent";
    case 84: return "DPadUpEvent";
    case 85: return "DPadRightEvent";
    case 86: return "DPadDownEvent";
    case 87: return "DPadLeftEvent";
    case 88: return "KeyUpEvent";
    case 89: return "KeyDownEvent";
    case 90: return "KeyLeftEvent";
    case 91: return "KeyRightEvent";
    case 92: return "DPadUpPressingEvent";
    case 93: return "DPadRightPressingEvent";
    case 94: return "DPadDownPressingEvent";
    case 95: return "DPadLeftPressingEvent";
    case 96: return "DPadUpReleaseEvent";
    case 97: return "DPadRightReleaseEvent";
    case 98: return "DPadDownReleaseEvent";
    case 99: return "DPadLeftReleaseEvent";
    case 100: return "HelpEvent";
    case 101: return "MultiplayerEvent";
    case 102: return "ToPrevInteeEvent";
    case 103: return "ToNextInteeEvent";
    case 104: return "JoypadToggleInteeEvent";
    case 105: return "OpenNotifyEvent";
    case 106: return "OpenDungeonFactorEvent";
    case 107: return "OpenHandbookEvent";
    case 108: return "TrackQuestReleaseEvent";
    case 109: return "OpenActivityNormalEvent";
    case 110: return "OpenPushTipsEvent";
    case 111: return "OpenBattlePassEvent";
    case 112: return "ToAvatar5Event";
    case 113: return "OpenChatJoystickEvent";
    case 114: return "OpenChatCancelJoystickEvent";
    case 115: return "ChallengeInterruptEvent";
    case 116: return "ChallengeInterruptJoystickEvent";
    case 117: return "HomeworldCreateCustomSuiteJoystickEvent";
    case 118: return "HomeworldFurnitureSearchJoystickEvent";
    case 119: return "HideEvent";
    case 120: return "TriggerQuickUseEvent";
    case 121: return "ReleaseQuickUseEvent";
    case 122: return "TriggerActivitySkillEvent";
    case 123: return "ReleaseActivitySkillEvent";
    case 124: return "ExteraSelectUpEvent";
    case 125: return "ExteraSelectDownEvent";
    case 126: return "ExteraSelectLeftEvent";
    case 127: return "ExteraSelectRightEvent";
    case 128: return "MusicGameLeftUpEvent";
    case 129: return "MusicGameLeftRightEvent";
    case 130: return "MusicGameLeftDownEvent";
    case 131: return "MusicGameLeftLeftEvent";
    case 132: return "MusicGameRightUpEvent";
    case 133: return "MusicGameRightRightEvent";
    case 134: return "MusicGameRightDownEvent";
    case 135: return "MusicGameRightLeftEvent";
    case 136: return "MusicGameLeftUpReleasedEvent";
    case 137: return "MusicGameLeftRightReleasedEvent";
    case 138: return "MusicGameLeftDownReleasedEvent";
    case 139: return "MusicGameLeftLeftReleasedEvent";
    case 140: return "MusicGameRightUpReleasedEvent";
    case 141: return "MusicGameRightRightReleasedEvent";
    case 142: return "MusicGameRightDownReleasedEvent";
    case 143: return "MusicGameRightLeftReleasedEvent";
    case 144: return "MusicGameFree1Event";
    case 145: return "MusicGameFree2Event";
    case 146: return "MusicGameFree3Event";
    case 147: return "MusicGameFree4Event";
    case 148: return "MusicGameFree5Event";
    case 149: return "MusicGameFree6Event";
    case 150: return "MusicGameFree7Event";
    case 151: return "MusicGameFree8Event";
    case 152: return "MusicGameFree9Event";
    case 153: return "MusicGameFree10Event";
    case 154: return "MusicGameFree11Event";
    case 155: return "MusicGameFree12Event";
    case 156: return "MusicGameFree13Event";
    case 157: return "MusicGameFree14Event";
    case 158: return "MusicGameFree15Event";
    case 159: return "MusicGameFree16Event";
    case 160: return "MusicGameFree17Event";
    case 161: return "MusicGameFree18Event";
    case 162: return "MusicGameFree19Event";
    case 163: return "MusicGameFree20Event";
    case 164: return "MusicGameFree21Event";
    case 165: return "MenuNextEvent";
    case 166: return "F1Event";
    case 167: return "F2Event";
    case 168: return "F3Event";
    case 169: return "ReturnEvent";
    case 170: return "OpenHomeworldHandbookEvent";
    case 171: return "OpenHomeworldEditorEvent";
    case 172: return "OpenTeamPageEvent";
    case 173: return "OpenFriendPageEvent";
    case 174: return "ObjectTurnUpEvent";
    case 175: return "ObjectTurnDownEvent";
    case 176: return "ObjectTurnLeftEvent";
    case 177: return "ObjectTurnRightEvent";
    case 178: return "CameraMoveUpPressedEvent";
    case 179: return "CameraMoveUpReleasedEvent";
    case 180: return "CameraMoveDownPressedEvent";
    case 181: return "CameraMoveDownReleasedEvent";
    case 182: return "CustomLevelSwitchFloatModeEvent";
    case 183: return "CustomLevelDeployConfirmEvent";
    case 184: return "ArrowUpEvent";
    case 185: return "ArrowDownEvent";
    case 186: return "ArrowLeftEvent";
    case 187: return "ArrowRightEvent";
    case 188: return "LeftControlEvent";
    case 189: return "LeftControlReleasedEvent";
    case 190: return "SpaceEvent";
    case 191: return "SpaceReleasedEvent";
    case 192: return "UndoEvent";
    case 193: return "SaveEvent";
    case 194: return "ObjectTurnUpReleaseEvent";
    case 195: return "ObjectTurnDownReleaseEvent";
    case 196: return "ObjectTurnLeftReleaseEvent";
    case 197: return "ObjectTurnRightReleaseEvent";
    case 198: return "ObjectTurnClockwiseEvent";
    case 199: return "ObjectTurnAntiClockwiseEvent";
    case 200: return "ObjectTurnClockwiseReleaseEvent";
    case 201: return "ObjectTurnAntiClockwiseReleaseEvent";
    case 202: return "OpenMenuEvent";
    case 203: return "OpenMenuReleaseEvent";
    case 204: return "MouseLeftButtonEvent";
    case 205: return "HerculesBattleForwardPressEvent";
    case 206: return "HerculesBattleForwardReleaseEvent";
    case 207: return "HerculesBattleBackwardPressEvent";
    case 208: return "HerculesBattleBackwardReleaseEvent";
    case 209: return "HerculesBattleCancelEvent";
    case 210: return "ActivityMapScaleEvent";
    case 211: return "ActivityMapSettingEvent";
    case 212: return "MusicGameFree22Event";
    case 213: return "MusicGameFree23Event";
    case 214: return "MusicGameFree24Event";
    case 215: return "MusicGameFree25Event";
    case 216: return "MusicGameFree26Event";
    case 217: return "TriggerVehicleSkill1Event";
    case 218: return "TriggerVehicleSkill2Event";
    case 219: return "TriggerVehicleSkill3Event";
    case 220: return "TriggerVehicleSkill4Event";
    case 221: return "TriggerVehicleSkill5Event";
    case 222: return "ReleaseVehicleSkill1Event";
    case 223: return "ReleaseVehicleSkill2Event";
    case 224: return "ReleaseVehicleSkill3Event";
    case 225: return "ReleaseVehicleSkill4Event";
    case 226: return "ReleaseVehicleSkill5Event";
    case 227: return "AkaFesAstrolabeLeftTurnPressEvent";
    case 228: return "AkaFesAstrolabeLeftTurnReleaseEvent";
    case 229: return "AkaFesAstrolabeRightTurnPressEvent";
    case 230: return "AkaFesAstrolabeRightTurnReleaseEvent";
    case 231: return "AkaFesAstrolabeHeightChangeEvent";
    case 232: return "SlipReleaseEvent";
    case 233: return "SlowMovePresseEvent";
    case 234: return "SlowMoveReleaseEvent";
    case 235: return "AkaFesAstrolabeHeightChangeReleaseEvent";
    case 236: return "BeyondMoveForwardEvent";
    case 237: return "BeyondMoveLeftEvent";
    case 238: return "BeyondMoveRightEvent";
    case 239: return "BeyondMoveBackwardEvent";
    case 240: return "BeyondSlowMoveEvent";
    case 241: return "BeyondDashEvent";
    case 242: return "BeyondJumpEvent";
    case 243: return "BeyondFallEvent";
    case 244: return "BeyondOpenChatEvent";
    case 245: return "BeyondHideSpecificUIEvent";
    case 246: return "BeyondOpenMicrophoneEvent";
    case 247: return "BeyondOpenSpeakerEvent";
    case 248: return "BeyondInteractive1Event";
    case 249: return "BeyondInteractive2Event";
    case 250: return "BeyondInteractive3Event";
    case 251: return "BeyondOpenExpressionEvent";
    case 252: return "BeyondWheelMenuTriggerEvent";
    case 253: return "BeyondOpenLevelEditEvent";
    case 254: return "BeyondOpenClothingEvent";
    case 255: return "BeyondOpenMapEvent";
    case 256: return "BeyondOpenGuideBookEvent";
    case 257: return "BeyondOpenHallEvent";
    case 258: return "BeyondOpenGachaEvent";
    case 259: return "BeyondOpenBattlePassEvent";
    case 260: return "BeyondOpenRecPlayEvent";
    case 261: return "BeyondOpenReunionEvent";
    case 262: return "BeyondOpenQuestEvent";
    case 263: return "BeyondOpenNotifyEvent";
    case 264: return "BeyondOpenTeamEvent";
    case 265: return "BeyondOpenFriendEvent";
    case 266: return "BeyondMatchRoomEvent";
    case 267: return "BeyondOpenAvatarChangeEvent";
    case 268: return "BeyondOpenLibraryEvent";
    case 269: return "BeyondPickInteractEvent";
    case 270: return "BeyondOpenBagInGameEvent";
    case 271: return "BeyondOpenEquipEvent";
    case 272: return "BeyondOpenMapInGameEvent";
    case 273: return "BeyondAttackEvent";
    case 274: return "BeyondSkill2Event";
    case 275: return "BeyondSkill5Event";
    case 276: return "BeyondAvatarSkill1Event";
    case 277: return "BeyondAvatarSkill2Event";
    case 278: return "BeyondChangeAttackModeEvent";
    case 279: return "BeyondChangeAvatar1Event";
    case 280: return "BeyondChangeAvatar2Event";
    case 281: return "BeyondChangeAvatar3Event";
    case 282: return "BeyondChangeAvatar4Event";
    case 283: return "BeyondUGCSkill1Event";
    case 284: return "BeyondUGCSkill2Event";
    case 285: return "BeyondUGCSkill3Event";
    case 286: return "BeyondUGCSkill4Event";
    case 287: return "BeyondUGCSkill5Event";
    case 288: return "BeyondCreatorKey1Event";
    case 289: return "BeyondCreatorKey2Event";
    case 290: return "BeyondCreatorKey3Event";
    case 291: return "BeyondCreatorKey4Event";
    case 292: return "BeyondCreatorKey5Event";
    case 293: return "BeyondCreatorKey6Event";
    case 294: return "BeyondCreatorKey7Event";
    case 295: return "BeyondCreatorKey8Event";
    case 296: return "BeyondCreatorKey9Event";
    case 297: return "BeyondCreatorKey10Event";
    case 298: return "BeyondCreatorKey11Event";
    case 299: return "BeyondCreatorKey12Event";
    case 300: return "BeyondCreatorKey13Event";
    case 301: return "BeyondCreatorKey14Event";
    case 302: return "BeyondCreatorKey15Event";
    case 303: return "BeyondTeyvatInteractEvent";
    case 304: return "BeyondUGCSkill1ReleaseEvent";
    case 305: return "BeyondUGCSkill2ReleaseEvent";
    case 306: return "BeyondUGCSkill3ReleaseEvent";
    case 307: return "BeyondUGCSkill4ReleaseEvent";
    case 308: return "BeyondUGCSkill5ReleaseEvent";
    case 309: return "BeyondCreatorKey1ReleaseEvent";
    case 310: return "BeyondCreatorKey2ReleaseEvent";
    case 311: return "BeyondCreatorKey3ReleaseEvent";
    case 312: return "BeyondCreatorKey4ReleaseEvent";
    case 313: return "BeyondCreatorKey5ReleaseEvent";
    case 314: return "BeyondCreatorKey6ReleaseEvent";
    case 315: return "BeyondCreatorKey7ReleaseEvent";
    case 316: return "BeyondCreatorKey8ReleaseEvent";
    case 317: return "BeyondCreatorKey9ReleaseEvent";
    case 318: return "BeyondCreatorKey10ReleaseEvent";
    case 319: return "BeyondCreatorKey11ReleaseEvent";
    case 320: return "BeyondCreatorKey12ReleaseEvent";
    case 321: return "BeyondCreatorKey13ReleaseEvent";
    case 322: return "BeyondCreatorKey14ReleaseEvent";
    case 323: return "BeyondCreatorKey15ReleaseEvent";
    case 324: return "BeyondAttackReleaseEvent";
    case 325: return "BeyondOpenBonusInGameEvent";
    case 326: return "BeyondInteractive2ReleaseEvent";
    case 3701: return "DPadVerticalEvent";
    case 3702: return "DPadHorizontalEvent";
    case 3703: return "ExteraSelectRightReleaseEvent";
    case 3704: return "UGCOpenGlobalSettingEvent";
    case 3705: return "UGCLeftControlPressEvent";
    case 3706: return "UGCLeftControlReleaseEvent";
    case 3707: return "UGCResetCameraEvent";
    case 3708: return "UGCCameraUpPressEvent";
    case 3709: return "UGCCameraUpReleaseEvent";
    case 3710: return "UGCCameraDownPressEvent";
    case 3711: return "UGCCameraDownReleaseEvent";
    case 3712: return "UGCRedoEvent";
    case 3713: return "UGCUndoEvent";
    case 3714: return "UGCDeploySaveEvent";
    case 3715: return "UGCDeployConfirmEvent";
    case 3716: return "UGCFocusCameraEvent";
    case 3717: return "UGCSwitchFloatEvent";
    case 3718: return "UGCRotateEvent";
    case 3719: return "UGCCopyEvent";
    case 3720: return "UGCRecycleEvent";
    case 3721: return "UGCOpenSettingEvent";
    case 3722: return "UGCOpenTriggerEvent";
    case 3723: return "UGCBatchSelectEvent";
    case 3724: return "UGCSelectSuiteEvent";
    case 3725: return "UGCMoveEvent";
    case 3726: return "WidgetQuickSwitch0Event";
    case 3727: return "WidgetQuickSwitch1Event";
    case 3728: return "WidgetQuickSwitch2Event";
    case 3729: return "WidgetQuickSwitch3Event";
    case 3801: return "ReloadEvent";
    case 3802: return "PenAdvShuffleBoardChargeEvent";
    case 3803: return "PenAdvShuffleBoardChargeReleaseEvent";
    case 3805: return "DPadHorizontalAxisEvent";
    case 3806: return "PenAdvShuffleBoardChargeMoveLEvent";
    case 3807: return "PenAdvShuffleBoardChargeMoveREvent";
    case 3808: return "ExteraSelectDownReleaseEvent";
    case 4001: return "DiveDownDownEvent";
    case 4002: return "DiveDownUpEvent";
    case 4003: return "DiveUpDownEvent";
    case 4004: return "DiveUpUpEvent";
    case 4005: return "JoypadDiveDownDownEvent";
    case 4006: return "JoypadDiveDownUpEvent";
    case 4007: return "JoypadDiveUpDownEvent";
    case 4008: return "JoypadDiveUpUpEvent";
    case 4009: return "JoypadDiveTriggerSkill1Event";
    case 4010: return "JoypadDiveReleaseSkill1Event";
    case 4011: return "ToyBattleQteLeftPressedEvent";
    case 4012: return "ToyBattleQteLeftReleaseEvent";
    case 4013: return "ToyBattleQteRightPressedEvent";
    case 4014: return "ToyBattleQteRightReleaseEvent";
    case 4101: return "PrimaryTabPrevEvent";
    case 4102: return "PrimaryTabNextEvent";
    case 4103: return "KeyCodeCEvent";
    case 4104: return "KeyCodeFEvent";
    case 4105: return "KeyCodeGEvent";
    case 4106: return "KeyCodeQEvent";
    case 4107: return "KeyCodeEEvent";
    case 4108: return "KeyCodeTabEvent";
    case 4109: return "TrackQuestPressEvent";
    case 4110: return "LeftStickButtonPressEvent";
    case 4111: return "LeftStickButtonReleaseEvent";
    case 4112: return "KeyCodeAEvent";
    case 4113: return "KeyCodeDEvent";
    case 4201: return "OpenReunionPageEvent";
    case 4301: return "HomeworldFurnitureSwitchMultiSelectModeEvent";
    case 4302: return "HomeworldLeftShoulderSquareJoyStickEvent";
    case 4303: return "KeyCodeQReleaseEvent";
    case 4304: return "MouseRightButtonEvent";
    case 4305: return "RightStickLeftShowEvent";
    case 4306: return "RightStickRightShowEvent";
    case 4401: return "KeyCodeWEvent";
    case 4402: return "KeyCodeSEvent";
    case 4403: return "ToggleAttackModeReleaseEvent";
    case 4404: return "RightStickButtonReleaseEvent";
    case 4405: return "KeyCodeWPressingEvent";
    case 4406: return "KeyCodeSPressingEvent";
    case 4407: return "KeyCodeAPressingEvent";
    case 4408: return "KeyCodeDPressingEvent";
    case 4409: return "MenuUpReleaseEvent";
    case 4410: return "ReturnKeyReleaseEvent";
    case 4411: return "ReturnKeyPressingEvent";
    case 4412: return "MouseLeftButtonReleaseEvent";
    case 4413: return "MouseLeftButtonPressingEvent";
    case 4501: return "DPadFourWayEvent";
    case 4601: return "MusicGameFree1ReleaseEvent";
    case 4602: return "MusicGameFree2ReleaseEvent";
    case 4603: return "MusicGameFree3ReleaseEvent";
    case 4604: return "MusicGameFree4ReleaseEvent";
    case 4605: return "MusicGameFree5ReleaseEvent";
    case 4606: return "MusicGameFree6ReleaseEvent";
    case 4607: return "MusicGameFree7ReleaseEvent";
    case 4608: return "MusicGameFree8ReleaseEvent";
    case 4609: return "MusicGameFree9ReleaseEvent";
    case 4610: return "MusicGameFree10ReleaseEvent";
    case 4611: return "MusicGameFree11ReleaseEvent";
    case 4612: return "MusicGameFree12ReleaseEvent";
    case 4613: return "MusicGameFree13ReleaseEvent";
    case 4614: return "MusicGameFree14ReleaseEvent";
    case 4615: return "MusicGameFree15ReleaseEvent";
    case 4616: return "MusicGameFree16ReleaseEvent";
    case 4617: return "MusicGameFree17ReleaseEvent";
    case 4618: return "MusicGameFree18ReleaseEvent";
    case 4619: return "MusicGameFree19ReleaseEvent";
    case 4620: return "MusicGameFree20ReleaseEvent";
    case 4621: return "MusicGameFree21ReleaseEvent";
    case 4622: return "LeftShoulderPressingEvent";
    case 4623: return "RightShoulderPressingEvent";
    case 4624: return "MenuRightReleaseEvent";
    case 4625: return "MenuDownReleaseEvent";
    case 4626: return "MusicGameFree25ReleaseEvent";
    case 4627: return "MusicGameFree26ReleaseEvent";
    case 4701: return "KeyCodeHEvent";
    case 4702: return "HideSpecificUIEvent";
    case 5001: return "LeftShiftEvent";
    case 5002: return "MoveEventUnchanged";
    case 5003: return "KeyCodeJEvent";
    case 5101: return "FloatToyQTELeftEvent";
    case 5102: return "FloatToyQTERightEvent";
    case 5201: return "KeyCodeAlpha1Event";
    case 5202: return "KeyCodeAlpha2Event";
    case 5203: return "KeyCodeAlpha3Event";
    case 5204: return "KeyCodeAlpha4Event";
    case 5205: return "KeyCodeAlpha1PressingEvent";
    case 5206: return "KeyCodeAlpha2PressingEvent";
    case 5207: return "KeyCodeAlpha3PressingEvent";
    case 5208: return "KeyCodeAlpha4PressingEvent";
    case 5209: return "KeyCodeAlpha1ReleasedEvent";
    case 5210: return "KeyCodeAlpha2ReleasedEvent";
    case 5211: return "KeyCodeAlpha3ReleasedEvent";
    case 5212: return "KeyCodeAlpha4ReleasedEvent";
    case 5301: return "InstrumentJoypad1Event";
    case 5302: return "InstrumentJoypad2Event";
    case 5303: return "InstrumentJoypad3Event";
    case 5304: return "InstrumentJoypad4Event";
    case 5305: return "InstrumentJoypad5Event";
    case 5306: return "InstrumentJoypad6Event";
    case 5307: return "InstrumentJoypad7Event";
    case 5308: return "InstrumentJoypad8Event";
    case 5309: return "InstrumentJoypad9Event";
    case 5310: return "InstrumentJoypad10Event";
    case 5311: return "InstrumentKeyboard1Event";
    case 5312: return "InstrumentKeyboard2Event";
    case 5313: return "InstrumentKeyboard3Event";
    case 5314: return "InstrumentKeyboard4Event";
    case 5315: return "InstrumentKeyboard5Event";
    case 5316: return "InstrumentKeyboard6Event";
    case 5317: return "InstrumentKeyboard7Event";
    case 5318: return "InstrumentKeyboard8Event";
    case 5319: return "InstrumentKeyboard9Event";
    case 5320: return "InstrumentKeyboard10Event";
    case 5321: return "InstrumentKeyboard11Event";
    case 5322: return "InstrumentKeyboard12Event";
    case 5323: return "InstrumentKeyboard13Event";
    case 5324: return "InstrumentKeyboard14Event";
    case 5325: return "InstrumentKeyboard15Event";
    case 5326: return "InstrumentKeyboard16Event";
    case 5327: return "InstrumentKeyboard17Event";
    case 5328: return "InstrumentKeyboard18Event";
    case 5329: return "InstrumentKeyboard19Event";
    case 5330: return "InstrumentKeyboard20Event";
    case 5331: return "InstrumentKeyboard21Event";
    case 5332: return "InstrumentKeyboard1ReleaseEvent";
    case 5333: return "InstrumentKeyboard2ReleaseEvent";
    case 5334: return "InstrumentKeyboard3ReleaseEvent";
    case 5335: return "InstrumentKeyboard4ReleaseEvent";
    case 5336: return "InstrumentKeyboard5ReleaseEvent";
    case 5337: return "InstrumentKeyboard6ReleaseEvent";
    case 5338: return "InstrumentKeyboard7ReleaseEvent";
    case 5339: return "InstrumentKeyboard8ReleaseEvent";
    case 5340: return "InstrumentKeyboard9ReleaseEvent";
    case 5341: return "InstrumentKeyboard10ReleaseEvent";
    case 5342: return "InstrumentKeyboard11ReleaseEvent";
    case 5343: return "InstrumentKeyboard12ReleaseEvent";
    case 5344: return "InstrumentKeyboard13ReleaseEvent";
    case 5345: return "InstrumentKeyboard14ReleaseEvent";
    case 5346: return "InstrumentKeyboard15ReleaseEvent";
    case 5347: return "InstrumentKeyboard16ReleaseEvent";
    case 5348: return "InstrumentKeyboard17ReleaseEvent";
    case 5349: return "InstrumentKeyboard18ReleaseEvent";
    case 5350: return "InstrumentKeyboard19ReleaseEvent";
    case 5351: return "InstrumentKeyboard20ReleaseEvent";
    case 5352: return "InstrumentKeyboard21ReleaseEvent";
    case 5353: return "InstrumentJoypad1ReleaseEvent";
    case 5354: return "InstrumentJoypad2ReleaseEvent";
    case 5355: return "InstrumentJoypad3ReleaseEvent";
    case 5356: return "InstrumentJoypad4ReleaseEvent";
    case 5357: return "InstrumentJoypad5ReleaseEvent";
    case 5358: return "InstrumentJoypad6ReleaseEvent";
    case 5359: return "InstrumentJoypad7ReleaseEvent";
    case 5360: return "InstrumentJoypad8ReleaseEvent";
    case 5361: return "InstrumentJoypad9ReleaseEvent";
    case 5362: return "InstrumentJoypad10ReleaseEvent";
    case 5363: return "KeyCodeSReleaseEvent";
    case 5364: return "KeyCodeAReleaseEvent";
    case 5365: return "KeyCodeDReleaseEvent";
    case 5366: return "KeyCodeArrowLEvent";
    case 5367: return "KeyCodeArrowREvent";
    case 5368: return "KeyCodeArrowUEvent";
    case 5369: return "KeyCodeArrowDEvent";
    case 5370: return "KeyCodeArrowLPressingEvent";
    case 5371: return "KeyCodeArrowRPressingEvent";
    case 5372: return "KeyCodeArrowUPressingEvent";
    case 5373: return "KeyCodeArrowDPressingEvent";
    case 5374: return "KeyCodeWReleaseEvent";
    case 5501: return "KeyCodeF4PressEvent";
    case 5502: return "KeyCodeF5PressEvent";
    case 5503: return "KeyCodeLeftAltPressEvent";
    case 5504: return "KeyCodeLPressEvent";
    case 5505: return "KeyCodeEndPressEvent";
    case 5506: return "KeyCodePPressEvent";
    case 5507: return "KeyCodeEscPressEvent";
    case 5508: return "KeyCodeZPressEvent";
    case 5509: return "KeyCodeYPressEvent";
    case 5510: return "MouseWheelEvent";
    case 5511: return "KeyCodeVPressEvent";
    case 5512: return "KeyCodeDeletePressEvent";
    case 5513: return "KeyCodeF4PressingEvent";
    case 5514: return "KeyCodeF5PressingEvent";
    case 5515: return "KeyCodeLeftAltPressingEvent";
    case 5516: return "KeyCodeLPressingEvent";
    case 5517: return "KeyCodeEndPressingEvent";
    case 5518: return "KeyCodePPressingEvent";
    case 5519: return "KeyCodeEscPressingEvent";
    case 5520: return "KeyCodeZPressingEvent";
    case 5521: return "KeyCodeYPressingEvent";
    case 5522: return "KeyCodeVPressingEvent";
    case 5523: return "KeyCodeDeletePressingEvent";
    case 5524: return "KeyCodeAlpha5Event";
    case 5525: return "KeyCodeAlpha6Event";
    case 5526: return "KeyCodeAlpha7Event";
    case 5527: return "KeyCodeAlpha8Event";
    case 5528: return "KeyCodeAlpha9Event";
    case 5529: return "KeyCodeAlpha0Event";
    case 5530: return "KeyCodeAlpha5PressingEvent";
    case 5531: return "KeyCodeAlpha6PressingEvent";
    case 5532: return "KeyCodeAlpha7PressingEvent";
    case 5533: return "KeyCodeAlpha8PressingEvent";
    case 5534: return "KeyCodeAlpha9PressingEvent";
    case 5535: return "KeyCodeAlpha0PressingEvent";
    case 5536: return "KeyCodeAlpha5ReleasedEvent";
    case 5537: return "KeyCodeAlpha6ReleasedEvent";
    case 5538: return "KeyCodeAlpha7ReleasedEvent";
    case 5539: return "KeyCodeAlpha8ReleasedEvent";
    case 5540: return "KeyCodeAlpha9ReleasedEvent";
    case 5541: return "KeyCodeAlpha0ReleasedEvent";
    case 5601: return "KeyCodePEvent";
    case 5801: return "ExteraSelectLeftReleaseEvent";
    case 5802: return "KeyUpPressEvent";
    case 5803: return "KeyUpReleaseEvent";
    case 6101: return "UGCKeyCodeEPressingEvent";
    case 6102: return "UGCKeyCodeQPressingEvent";
    case 6103: return "UGCMouseRightButtonReleaseEvent";
    case 6104: return "UGCMouseLeftButtonReleaseEvent";
    case 6105: return "BeyondLeftControlPressEvent";
    case 6106: return "BeyondLeftControlReleaseEvent";
    case 6107: return "BeyondLeftAltPressEvent";
    case 6108: return "BeyondLeftAltReleaseEvent";
    case 6109: return "BeyondSpacePressEvent";
    case 6110: return "BeyondMouseWheelPressEvent";
    case 6111: return "BeyondMouseWheelReleaseEvent";
    case 6112: return "BeyondLeftShiftPressEvent";
    case 6113: return "BeyondLeftShiftReleaseEvent";
    case 6114: return "BeyondFPressEvent";
    case 6115: return "BeyondCapsLockPressEvent";
    case 6116: return "BeyondDeletePressEvent";
    case 6117: return "BeyondZPressEvent";
    case 6118: return "BeyondCPressEvent";
    case 6119: return "BeyondVPressEvent";
    case 6120: return "BeyondSPressEvent";
    case 6121: return "BeyondLPressEvent";
    case 6122: return "BeyondMouseWheelPressingEvent";
    case 6123: return "KeyCodeFReleaseEvent";
    case 6124: return "KeyCodeREvent";
    case 6125: return "KeyCodeRReleaseEvent";
    case 6126: return "KeyCodeQRepeatEvent";
    case 6127: return "KeyCodeERepeatEvent";
    case 6128: return "KeyCodeWRepeatEvent";
    case 6129: return "KeyCodeSRepeatEvent";
    case 6130: return "KeyCodeARepeatEvent";
    case 6131: return "KeyCodeDRepeatEvent";
    case 6132: return "BeyondLeftControlPressingEvent";
    case 6133: return "BeyondLeftAltPressingEvent";
    case 6134: return "BeyondLeftShiftPressingEvent";
    case 6135: return "BeyondMouseRightButtonPressing";
    case 6136: return "UGCCustomPopupHideHint";
    case 6137: return "MenuBackLongPressedEvent";
    case 6138: return "KeyCodeUEvent";
    case 6201: return "KeyCodeJReleaseEvent";
    case 6301: return "OpenNetworkVoiceMicEvent";
    case 6302: return "OpenNetworkVoiceSettingEvent";
    case 6303: return "KeyCodeEReleaseEvent";
    case 6501: return "TriggerInputDragEvent";
    case 6502: return "ReleaseInputDragEvent";
    case 6503: return "InputDragMoveEvent";
    case 6504: return "BeyondMoveForwardReleaseEvent";
    case 6505: return "BeyondMoveBackwardReleaseEvent";
    case 6506: return "BeyondMoveLeftReleaseEvent";
    case 6507: return "BeyondMoveRightReleaseEvent";
    case 6508: return "BeyondSlowMoveReleaseEvent";
    case 6509: return "BeyondDashReleaseEvent";
    case 6510: return "BeyondJumpReleaseEvent";
    case 6511: return "BeyondFallReleaseEvent";
    case 6512: return "BeyondWheelMenuTriggerReleaseEvent";
    case 6513: return "BeyondPickInteractReleaseEvent";
    case 6514: return "BeyondInteractive1ReleaseEvent";
    case 6591: return "KeyMapTest1Event";
    case 6592: return "KeyMapTest2Event";
    case 6593: return "KeyMapTest3Event";
    case 6601: return "BeyondCreatorKey16Event";
    case 6602: return "BeyondCreatorKey17Event";
    case 6603: return "BeyondCreatorKey18Event";
    case 6604: return "BeyondCreatorKey19Event";
    case 6605: return "BeyondCreatorKey20Event";
    case 6606: return "BeyondCreatorKey21Event";
    case 6607: return "BeyondCreatorKey22Event";
    case 6608: return "BeyondCreatorKey23Event";
    case 6609: return "BeyondCreatorKey24Event";
    case 6610: return "BeyondCreatorKey25Event";
    case 6611: return "BeyondCreatorKey26Event";
    case 6612: return "BeyondCreatorKey27Event";
    case 6613: return "BeyondCreatorKey28Event";
    case 6614: return "BeyondCreatorKey29Event";
    case 6615: return "BeyondCreatorKey30Event";
    case 6616: return "BeyondCreatorKey31Event";
    case 6617: return "BeyondCreatorKey32Event";
    case 6618: return "BeyondCreatorKey33Event";
    case 6619: return "BeyondCreatorKey34Event";
    case 6620: return "BeyondCreatorKey35Event";
    case 6621: return "BeyondCreatorKey36Event";
    case 6622: return "BeyondCreatorKey37Event";
    case 6623: return "BeyondCreatorKey38Event";
    case 6624: return "BeyondCreatorKey39Event";
    case 6625: return "BeyondCreatorKey40Event";
    case 6626: return "BeyondCreatorKey41Event";
    case 6627: return "BeyondCreatorKey42Event";
    case 6628: return "BeyondCreatorKey43Event";
    case 6636: return "BeyondCreatorKey16ReleaseEvent";
    case 6637: return "BeyondCreatorKey17ReleaseEvent";
    case 6638: return "BeyondCreatorKey18ReleaseEvent";
    case 6639: return "BeyondCreatorKey19ReleaseEvent";
    case 6640: return "BeyondCreatorKey20ReleaseEvent";
    case 6641: return "BeyondCreatorKey21ReleaseEvent";
    case 6642: return "BeyondCreatorKey22ReleaseEvent";
    case 6643: return "BeyondCreatorKey23ReleaseEvent";
    case 6644: return "BeyondCreatorKey24ReleaseEvent";
    case 6645: return "BeyondCreatorKey25ReleaseEvent";
    case 6646: return "BeyondCreatorKey26ReleaseEvent";
    case 6647: return "BeyondCreatorKey27ReleaseEvent";
    case 6648: return "BeyondCreatorKey28ReleaseEvent";
    case 6649: return "BeyondCreatorKey29ReleaseEvent";
    case 6650: return "BeyondCreatorKey30ReleaseEvent";
    case 6651: return "BeyondCreatorKey31ReleaseEvent";
    case 6652: return "BeyondCreatorKey32ReleaseEvent";
    case 6653: return "BeyondCreatorKey33ReleaseEvent";
    case 6654: return "BeyondCreatorKey34ReleaseEvent";
    case 6655: return "BeyondCreatorKey35ReleaseEvent";
    case 6656: return "BeyondCreatorKey36ReleaseEvent";
    case 6657: return "BeyondCreatorKey37ReleaseEvent";
    case 6658: return "BeyondCreatorKey38ReleaseEvent";
    case 6659: return "BeyondCreatorKey39ReleaseEvent";
    case 6660: return "BeyondCreatorKey40ReleaseEvent";
    case 6661: return "BeyondCreatorKey41ReleaseEvent";
    case 6662: return "BeyondCreatorKey42ReleaseEvent";
    case 6663: return "BeyondCreatorKey43ReleaseEvent";
    case 6664: return "BeyondCardSelectEvent";
    case 6665: return "BeyondLevelTaskEvent";
    case 6701: return "BeyondSmallPropsEvent";
    case 6702: return "BeyondPreTargetingDragMoveEvent";
    case 6703: return "BeyondPreTargetingCancelMouseRightButtonEvent";
    case 6704: return "BeyondPreTargetingCancelEscPressEvent";
    case 6705: return "BeyondPreTargetingCancelRightStickButtonEvent";
    case 6706: return "BeyondSmallPropsReleaseEvent";
    case 7001: return "TpsReloadEvent";
    case 7002: return "TpsAimDownSightsEvent";
    case 7003: return "TpsSkill1FireEvent";
    case 7004: return "TpsSkill2Event";
    case 7005: return "TpsSkill3SprintEvent";
    case 7006: return "TpsSkill4JumpEvent";
    case 7007: return "TpsSkill5Event";
    case 7008: return "TpsActivitySkillEvent";
    case 7009: return "TpsReleaseAimDownSightsEvent";
    case 7010: return "TpsReleaseSkill1FireEvent";
    case 7011: return "TpsReleaseSkill2Event";
    case 7012: return "TpsReleaseSkill3SprintEvent";
    case 7013: return "TpsReleaseSkill4JumpEvent";
    case 7014: return "TpsReleaseSkill5Event";
    case 7015: return "TpsReleaseActivitySkillEvent";
    case 7016: return "TpsReloadSecondaryEvent";
    case 7017: return "TpsAimDownSightsSecondaryEvent";
    case 7018: return "TpsSkill1FireSecondaryEvent";
    case 7019: return "TpsSkill3SprintSecondaryEvent";
    case 7020: return "TpsSkill4JumpSecondaryEvent";
    case 7021: return "TpsChangeWeapon1Event";
    case 7022: return "TpsChangeWeapon2Event";
    case 7023: return "TpsChangeGrenadeEvent";
    case 7024: return "TpsTalkOrPickEvent";
    case 7025: return "TpsReleaseAimDownSightsSecondaryEvent";
    case 7026: return "TpsReleaseSkill1FireSecondaryEvent";
    case 7027: return "TpsReleaseSkill3SprintSecondaryEvent";
    case 7028: return "TpsReleaseSkill4JumpSecondaryEvent";
    case 7029: return "TpsReleaseReloadEvent";
    case 7030: return "TpsReleaseReloadSecondaryEvent";
    case 7031: return "TpsReleaseChangeWeapon1Event";
    case 7032: return "TpsReleaseChangeWeapon2Event";
    case 7033: return "TpsReleaseChangeGrenadeEvent";
    case 7034: return "TpsReleaseTalkOrPickEvent";
    case 7035: return "TalkOrPickPressingEvent";
    case 7036: return "TpsTalkOrPickPressingEvent";
    case 7101: return "BeyondClientUIJoypadNavLeftStickUpEvent";
    case 7102: return "BeyondClientUIJoypadNavLeftStickDownEvent";
    case 7103: return "BeyondClientUIJoypadNavLeftStickLeftEvent";
    case 7104: return "BeyondClientUIJoypadNavLeftStickRightEvent";
    case 7105: return "BeyondClientUIJoypadNavRightStickUpEvent";
    case 7106: return "BeyondClientUIJoypadNavRightStickDownEvent";
    case 7107: return "BeyondClientUIJoypadNavRightStickLeftEvent";
    case 7108: return "BeyondClientUIJoypadNavRightStickRightEvent";
    case 7109: return "BeyondClientUIJoypadNavMenuConfirmEvent";
    case 7110: return "BeyondClientUIJoypadNavMenuBackEvent";
    case 7111: return "BeyondOpenActivityEvent";
    case 7112: return "BeyondClientUIJoypadKeyMenuConfirmEvent";
    case 7113: return "BeyondClientUIJoypadKeyMenuBackEvent";
    case 7114: return "BeyondClientUIJoypadKeyMenuConfirmReleaseEvent";
    case 7115: return "BeyondClientUIJoypadKeyMenuBackReleaseEvent";
    }
    return nullptr;
}

// JOCMONMOJJD（枚举，底层 Int32，4 字节）
enum class T_JOCMONMOJJD : int32_t {
    Invalid = 0,
    ContextEnd = 1,
    FrameEnd = 2,
    CloseEvent = 3,
    BackEvent = 4,
    ConfirmEvent = 5,
    ConfirmingEvent = 6,
    ConfirmingCancelEvent = 7,
    ToPrevPrimaryTabEvent = 8,
    ToNextPrimaryTabEvent = 9,
    ToPrevSecondaryTabEvent = 10,
    ToNextSecondaryTabEvent = 11,
    MenuNavigationUp = 12,
    MenuNavigationDown = 13,
    MenuNavigationLeft = 14,
    MenuNavigationRight = 15,
    IncreaseCountEvent = 16,
    DecreaseCountEvent = 17,
    TriggerInputEvent = 18,
    LogoutConfirmingEvent = 19,
    LogoutConfirmEndEvent = 20,
    BackingEvent = 21,
    BackingCancelEvent = 22,
    OpenSortingDropdownEvent = 23,
    OpenScreenDropdownEvent = 24,
    RevertSortingOrderEvent = 25,
    OpenDropdownEvent = 26,
    ToNextDropdownOptionEvent = 27,
    ToPrevDropdownOptionEvent = 28,
    ConfirmDropdownSelectEvent = 29,
    CancelDropdownSelectEvent = 30,
    ScrollPrimaryScrollerEvent = 31,
    ReturnToQuestEvent = 32,
    ToAvatar1Event = 33,
    ToAvatar2Event = 34,
    ToAvatar3Event = 35,
    ToAvatar4Event = 36,
    OpenChatEvent = 37,
    ToAvatar5Event = 38,
    ActionNorthEvent = 39,
    ActionEastEvent = 40,
    ActionSouthEvent = 41,
    ActionWestEvent = 42,
    ShowItemDetailEvent = 43,
    ShowPlayerLevelRewardEvent = 44,
    ChangeTeamEvent = 45,
    ChangeTeamNameEvent = 46,
    FastTeamSelectEvent = 47,
    SubmitFastTeamSelect = 48,
    ShowHelpTips = 49,
    BuyResin = 51,
    ChangeFocusZone = 52,
    ShowCycleDungeonOnly = 53,
    ChangeCustomMarkName = 54,
    RemoveCustomMark = 55,
    OpenChatCancelEvent = 56,
    IncreaseCountReleaseEvent = 57,
    DecreaseCountReleaseEvent = 58,
    ItemSourceSelectEvent = 59,
    ChallengeInterruptEvent = 60,
    ToNextScrollerOptionEvent = 61,
    ToPrevScrollerOptionEvent = 62,
    ConfirmScrollerSelectEvent = 63,
    CancelScrollerSelectEvent = 64,
    HomeworldCreateCustomSuiteEvent = 65,
    HomeworldFurnitureSearchEvent = 66,
    HomeworldFurnitureSwitchMultiSelectModeEvent = 67,
    HomeworldLeftShoulderSquareEvent = 68,
    ToRewardDetailEvent = 100,
    ToPrevRewardEvent = 101,
    ToNextRewardEvent = 102,
    ToPrevMainQuestEvent = 103,
    ToNextMainQuestEvent = 104,
    ToggleChapterFold = 105,
    NavigateToQuestEvent = 106,
    ScrollSubQuestEvent = 107,
    ChapterSelectEvent = 108,
    ChoosePrevChapterEvent = 109,
    ChooseNextChapterEvent = 110,
    ShowSubQuestDetailEvent = 111,
    ToRewardPageEvent = 112,
    ToggleQuestTrackingEvent = 113,
    ToPrevTabEvent = 200,
    ToNextTabEvent = 201,
    UseEvent = 202,
    DropEvent = 203,
    ToPrevRowEvent = 204,
    ToNextRowEvent = 205,
    ToPrevSlotEvent = 206,
    ToNextSlotEvent = 207,
    ReNameEvent = 300,
    UIZoomCameraEvent = 400,
    UIDetails = 401,
    MoveCursorEvent = 500,
    ZoomInMapEvent = 501,
    ZoomOutMapEvent = 502,
    CommonLeftStickUpEvent = 600,
    CommonLeftStickDownEvent = 601,
    CommonLeftStickLeftEvent = 602,
    CommonLeftStickRightEvent = 603,
    CommonChangeViewEvent = 604,
    CommonMenuUpEvent = 605,
    CommonMenuLeftEvent = 606,
    CommonRightStickLeftEvent = 607,
    CommonRightStickRightEvent = 608,
    CommonRightStickUpEvent = 630,
    CommonRightStickDownEvent = 631,
    CommonLeftStickButtonEvent = 610,
    CommonRightStickButtonEvent = 611,
    CommonRightTriggerEvent = 612,
    CommonLeftTriggerEvent = 613,
    CommonRightShoulderEvent = 614,
    CommonLeftShoulderEvent = 615,
    CommonLeftShoulderReleaseEvent = 616,
    CommonRightShoulderReleaseEvent = 617,
    CommonLeftStickVerticalEvent = 620,
    CommonRightStickVerticalEvent = 621,
    CommonLeftStickHorizontalEvent = 622,
    CommonRightStickHorizontalEvent = 623,
    Revive = 700,
    Goddess_ContributeSome = 800,
    Goddess_ContributeAll = 801,
    Goddess_ScrollUpgradeReward = 802,
    ToggleSpringAutoUseEvent = 803,
    DialogSelectEvent = 900,
    ToNextDialogEvent = 901,
    VisitorLoginEvent = 1000,
    SwitchServerLoginEvent = 1001,
    GachaNoticeEvent = 1020,
    GachaHistoryEvent = 1021,
    GachaOnceEvent = 1022,
    GachaTenTimesEvent = 1023,
    GachaNextEvent = 1024,
    BuyEvent = 1101,
    TipsEvent = 1102,
    BuyInfoEvent = 1103,
    MallHelpEvent = 1104,
    MaterialAddEvent = 1201,
    McoinAddEvent = 1202,
    GachaTicketAddEvent = 1203,
    HideEvent = 1301,
    PhotographOpenEmotion = 1302,
    QuickUseEvent = 1401,
    ActivitySkillEvent = 1402,
    ExteraSelectUpEvent = 1403,
    ExteraSelectDownEvent = 1404,
    ExteraSelectLeftEvent = 1405,
    ExteraSelectRightEvent = 1406,
    MusicGameLeftUpEvent = 1407,
    MusicGameLeftRightEvent = 1408,
    MusicGameLeftDownEvent = 1409,
    MusicGameLeftLeftEvent = 1410,
    MusicGameRightUpEvent = 1411,
    MusicGameRightRightEvent = 1412,
    MusicGameRightDownEvent = 1413,
    MusicGameRightLeftEvent = 1414,
    MusicGameLeftUpReleasedEvent = 1415,
    MusicGameLeftRightReleasedEvent = 1416,
    MusicGameLeftDownReleasedEvent = 1417,
    MusicGameLeftLeftReleasedEvent = 1418,
    MusicGameRightUpReleasedEvent = 1419,
    MusicGameRightRightReleasedEvent = 1420,
    MusicGameRightDownReleasedEvent = 1421,
    MusicGameRightLeftReleasedEvent = 1422,
    MusicGameFree1Event = 1423,
    MusicGameFree2Event = 1424,
    MusicGameFree3Event = 1425,
    MusicGameFree4Event = 1426,
    MusicGameFree5Event = 1427,
    MusicGameFree6Event = 1428,
    MusicGameFree7Event = 1429,
    MusicGameFree8Event = 1430,
    MusicGameFree9Event = 1431,
    MusicGameFree10Event = 1432,
    MusicGameFree11Event = 1433,
    MusicGameFree12Event = 1434,
    MusicGameFree13Event = 1435,
    MusicGameFree14Event = 1436,
    MusicGameFree15Event = 1437,
    MusicGameFree16Event = 1438,
    MusicGameFree17Event = 1439,
    MusicGameFree18Event = 1440,
    MusicGameFree19Event = 1441,
    MusicGameFree20Event = 1442,
    MusicGameFree21Event = 1443,
    MusicGamePauseEvent = 1444,
    OpenTeamPageEvent = 1445,
    OpenFriendPageEvent = 1446,
    CommonLeftTriggerPressEvent = 1447,
    CommonLeftTriggerReleaseEvent = 1448,
    CommonRightTriggerPressEvent = 1449,
    CommonRightTriggerReleaseEvent = 1450,
    ArrowUpEvent = 1451,
    ArrowDownEvent = 1452,
    ArrowLeftEvent = 1453,
    ArrowRightEvent = 1454,
    LeftControlEvent = 1455,
    LeftControlReleasedEvent = 1456,
    SpaceEvent = 1457,
    SpaceReleasedEvent = 1458,
    UndoEvent = 1459,
    SaveEvent = 1460,
    OpenMenuEvent = 1461,
    OpenMenuReleaseEvent = 1462,
    HerculesBattleForwardEvent = 1463,
    HerculesBattleBackwardEvent = 1464,
    HerculesBattleCancelEvent = 1465,
    MusicGameFree22Event = 3501,
    MusicGameFree23Event = 3502,
    MusicGameFree24Event = 3503,
    MusicGameFree25Event = 3504,
    MusicGameFree26Event = 3505,
    AkaFesAstrolabeLeftTurnEvent = 3506,
    AkaFesAstrolabeRightTurnEvent = 3507,
    AkaFesAstrolabeHeightChangeEvent = 3508,
    CommonDPadVerticalEvent = 3701,
    CommonDPadHorizontalEvent = 3702,
    ExteraSelectRightReleaseEvent = 3703,
    UGCOpenGlobalSettingEvent = 3704,
    UGCLeftControlPressEvent = 3705,
    UGCLeftControlReleaseEvent = 3706,
    UGCResetCameraEvent = 3707,
    UGCCameraUpPressEvent = 3708,
    UGCCameraUpReleaseEvent = 3709,
    UGCCameraDownPressEvent = 3710,
    UGCCameraDownReleaseEvent = 3711,
    UGCRedoEvent = 3712,
    UGCUndoEvent = 3713,
    UGCDeploySaveEvent = 3714,
    UGCDeployConfirmEvent = 3715,
    UGCFocusCameraEvent = 3716,
    UGCSwitchFloatEvent = 3717,
    UGCRotateEvent = 3718,
    UGCCopyEvent = 3719,
    UGCRecycleEvent = 3720,
    UGCOpenSettingEvent = 3721,
    UGCOpenTriggerEvent = 3722,
    UGCBatchSelectEvent = 3723,
    UGCSelectSuiteEvent = 3724,
    UGCMoveEvent = 3725,
    WidgetQuickSwitch0Event = 3726,
    WidgetQuickSwitch1Event = 3727,
    WidgetQuickSwitch2Event = 3728,
    WidgetQuickSwitch3Event = 3729,
    ReloadEvent = 3801,
    PenAdvShuffleBoardChargeEvent = 3802,
    PenAdvShuffleBoardChargeReleaseEvent = 3803,
    CommonDPadHorizontalAxisEvent = 3805,
    PenAdvShuffleBoardChargeMoveLEvent = 3806,
    PenAdvShuffleBoardChargeMoveREvent = 3807,
    ToyBattleQteLeftEvent = 4011,
    ToyBattleQteRightEvent = 4012,
    ToyBattleQteLeftReleaseEvent = 4013,
    ToyBattleQteRightReleaseEvent = 4014,
    BoxMatchSkill1 = 4101,
    BoxMatchSkill2 = 4102,
    TrackQuestPressEvent = 4103,
    CommonLeftStickButtonPressEvent = 4104,
    CommonLeftStickButtonReleaseEvent = 4105,
    OpenReunionEvent = 4201,
    FungusV3UseSkill = 4202,
    FungusV3SelectAll = 4203,
    CommonRightStickLeftShowEvent = 4301,
    CommonRightStickRightShowEvent = 4302,
    CommonDPadFourWayEvent = 4501,
    MusicGameFree1ReleaseEvent = 4601,
    MusicGameFree2ReleaseEvent = 4602,
    MusicGameFree3ReleaseEvent = 4603,
    MusicGameFree4ReleaseEvent = 4604,
    MusicGameFree5ReleaseEvent = 4605,
    MusicGameFree6ReleaseEvent = 4606,
    MusicGameFree7ReleaseEvent = 4607,
    MusicGameFree8ReleaseEvent = 4608,
    MusicGameFree9ReleaseEvent = 4609,
    MusicGameFree10ReleaseEvent = 4610,
    MusicGameFree11ReleaseEvent = 4611,
    MusicGameFree12ReleaseEvent = 4612,
    MusicGameFree13ReleaseEvent = 4613,
    MusicGameFree14ReleaseEvent = 4614,
    MusicGameFree15ReleaseEvent = 4615,
    MusicGameFree16ReleaseEvent = 4616,
    MusicGameFree17ReleaseEvent = 4617,
    MusicGameFree18ReleaseEvent = 4618,
    MusicGameFree19ReleaseEvent = 4619,
    MusicGameFree20ReleaseEvent = 4620,
    MusicGameFree21ReleaseEvent = 4621,
    CommonLeftShoulderPressingEvent = 4622,
    CommonRightShoulderPressingEvent = 4623,
    HideSpecificUIEvent = 4701,
    BomberDodocoMoveEvent = 5001,
    BomberDodocoSkill1Event = 5002,
    BomberDodocoSkill2Event = 5003,
    SynthesisAvatarLevelLeftReleaseEvent = 5101,
    SynthesisAvatarLevelRightReleaseEvent = 5102,
    LightStrikeDefendEvent = 5201,
    LightStrikeUltimateEvent = 5202,
    LightStrikeDefendReleaseEvent = 5203,
    InstrumentJoypad1Event = 5301,
    InstrumentJoypad2Event = 5302,
    InstrumentJoypad3Event = 5303,
    InstrumentJoypad4Event = 5304,
    InstrumentJoypad5Event = 5305,
    InstrumentJoypad6Event = 5306,
    InstrumentJoypad7Event = 5307,
    InstrumentJoypad8Event = 5308,
    InstrumentJoypad9Event = 5309,
    InstrumentJoypad10Event = 5310,
    InstrumentKeyboard1Event = 5311,
    InstrumentKeyboard2Event = 5312,
    InstrumentKeyboard3Event = 5313,
    InstrumentKeyboard4Event = 5314,
    InstrumentKeyboard5Event = 5315,
    InstrumentKeyboard6Event = 5316,
    InstrumentKeyboard7Event = 5317,
    InstrumentKeyboard8Event = 5318,
    InstrumentKeyboard9Event = 5319,
    InstrumentKeyboard10Event = 5320,
    InstrumentKeyboard11Event = 5321,
    InstrumentKeyboard12Event = 5322,
    InstrumentKeyboard13Event = 5323,
    InstrumentKeyboard14Event = 5324,
    InstrumentKeyboard15Event = 5325,
    InstrumentKeyboard16Event = 5326,
    InstrumentKeyboard17Event = 5327,
    InstrumentKeyboard18Event = 5328,
    InstrumentKeyboard19Event = 5329,
    InstrumentKeyboard20Event = 5330,
    InstrumentKeyboard21Event = 5331,
    InstrumentKeyboard1ReleaseEvent = 5332,
    InstrumentKeyboard2ReleaseEvent = 5333,
    InstrumentKeyboard3ReleaseEvent = 5334,
    InstrumentKeyboard4ReleaseEvent = 5335,
    InstrumentKeyboard5ReleaseEvent = 5336,
    InstrumentKeyboard6ReleaseEvent = 5337,
    InstrumentKeyboard7ReleaseEvent = 5338,
    InstrumentKeyboard8ReleaseEvent = 5339,
    InstrumentKeyboard9ReleaseEvent = 5340,
    InstrumentKeyboard10ReleaseEvent = 5341,
    InstrumentKeyboard11ReleaseEvent = 5342,
    InstrumentKeyboard12ReleaseEvent = 5343,
    InstrumentKeyboard13ReleaseEvent = 5344,
    InstrumentKeyboard14ReleaseEvent = 5345,
    InstrumentKeyboard15ReleaseEvent = 5346,
    InstrumentKeyboard16ReleaseEvent = 5347,
    InstrumentKeyboard17ReleaseEvent = 5348,
    InstrumentKeyboard18ReleaseEvent = 5349,
    InstrumentKeyboard19ReleaseEvent = 5350,
    InstrumentKeyboard20ReleaseEvent = 5351,
    InstrumentKeyboard21ReleaseEvent = 5352,
    InstrumentJoypad1ReleaseEvent = 5353,
    InstrumentJoypad2ReleaseEvent = 5354,
    InstrumentJoypad3ReleaseEvent = 5355,
    InstrumentJoypad4ReleaseEvent = 5356,
    InstrumentJoypad5ReleaseEvent = 5357,
    InstrumentJoypad6ReleaseEvent = 5358,
    InstrumentJoypad7ReleaseEvent = 5359,
    InstrumentJoypad8ReleaseEvent = 5360,
    InstrumentJoypad9ReleaseEvent = 5361,
    InstrumentJoypad10ReleaseEvent = 5362,
    PuzzleFighterLeftEvent = 5363,
    PuzzleFighterRightEvent = 5364,
    PuzzleFighterDownEvent = 5365,
    PuzzleFighterDownReleaseEvent = 5366,
    PuzzleFighterRotEvent = 5367,
    PuzzleFighterSkillEvent = 5368,
    PuzzleFighterLeftReleaseEvent = 5369,
    PuzzleFighterRightReleaseEvent = 5370,
    PuzzleFighterLeftPressingEvent = 5371,
    PuzzleFighterRightPressingEvent = 5372,
    PuzzleFighterDownPressingEvent = 5373,
    PuzzleFighterRotAlt1Event = 5374,
    KeyCodeWReleaseEvent = 5375,
    TriggerWheelMenuEvent = 5401,
    LongyiwuCannonLaunchEvent = 5501,
    CommonKeyCodePEvent = 5601,
    CommonTriggerActivitySkillEvent = 5602,
    CommonMouseLeftButtonEvent = 5801,
    CommonMouseRightButtonEvent = 5802,
    KeyCodeEEvent = 5803,
    PartyDJLeftPressingEvent = 5804,
    PartyDJLeftReleaseEvent = 5805,
    PartyDJRightPressingEvent = 5806,
    PartyDJRightReleaseEvent = 5807,
    PartyDJSwitchCameraEvent = 5808,
    PartyDJBulletEvent = 5809,
    PartyDJSubQTEEvent = 5810,
    PartyDJMainQTEEvent = 5811,
    ShootCoasReloadEvent = 5812,
    ShootCoasSkillPressingEvent = 5813,
    ShootCoasSkillReleaseEvent = 5814,
    ShootCoasExitPressingEvent = 5815,
    ShootCoasExitReleaseEvent = 5816,
    ShootCoasShotPressingEvent = 5817,
    ShootCoasShotReleaseEvent = 5818,
    ShootCoasLeftShotEvent = 5819,
    LockStepQuitEvent = 6001,
    BomberV3Skill3Event = 6002,
    LockStepGMEvent = 6003,
    ExteraSelectLeftReleaseEvent = 6004,
    ShortcutKeyCodeQEvent = 6101,
    ShortcutKeyCodeEEvent = 6102,
    ShortcutKeyCodeAEvent = 6103,
    ShortcutKeyCodeDEvent = 6104,
    ShortcutKeyCodeWEvent = 6105,
    ShortcutKeyCodeSEvent = 6106,
    ShortcutKeyCodeREvent = 6107,
    ShortcutKeyCodeRReleaseEvent = 6108,
    ShortcutKeyCodeFEvent = 6109,
    ShortcutKeyCodeFReleaseEvent = 6110,
    UGCCustomPopupHideHintEvent = 6111,
    HomeworldEditorSettingEvent = 6201,
    HomeworldEditorSelectModeEvent = 6202,
    HomeworldEditorRotateModeEvent = 6203,
    HomeworldEditorCancelEvent = 6204,
    HomeworldEditorTakeEvent = 6205,
    HomeworldEditorRotateEvent = 6206,
    HomeworldEditorConfirmEvent = 6207,
    HomeworldEditorEditSuitEvent = 6208,
    HomeworldEditorMoveCameraEvent = 6209,
    KeyCodeQEvent = 6301,
    CommonRightStickMoveEvent = 6501
};
static_assert(sizeof(T_JOCMONMOJJD) == 4, "T_JOCMONMOJJD");
inline const char* enum_name(T_JOCMONMOJJD v) {
    switch ((int32_t)v) {
    case 0: return "Invalid";
    case 1: return "ContextEnd";
    case 2: return "FrameEnd";
    case 3: return "CloseEvent";
    case 4: return "BackEvent";
    case 5: return "ConfirmEvent";
    case 6: return "ConfirmingEvent";
    case 7: return "ConfirmingCancelEvent";
    case 8: return "ToPrevPrimaryTabEvent";
    case 9: return "ToNextPrimaryTabEvent";
    case 10: return "ToPrevSecondaryTabEvent";
    case 11: return "ToNextSecondaryTabEvent";
    case 12: return "MenuNavigationUp";
    case 13: return "MenuNavigationDown";
    case 14: return "MenuNavigationLeft";
    case 15: return "MenuNavigationRight";
    case 16: return "IncreaseCountEvent";
    case 17: return "DecreaseCountEvent";
    case 18: return "TriggerInputEvent";
    case 19: return "LogoutConfirmingEvent";
    case 20: return "LogoutConfirmEndEvent";
    case 21: return "BackingEvent";
    case 22: return "BackingCancelEvent";
    case 23: return "OpenSortingDropdownEvent";
    case 24: return "OpenScreenDropdownEvent";
    case 25: return "RevertSortingOrderEvent";
    case 26: return "OpenDropdownEvent";
    case 27: return "ToNextDropdownOptionEvent";
    case 28: return "ToPrevDropdownOptionEvent";
    case 29: return "ConfirmDropdownSelectEvent";
    case 30: return "CancelDropdownSelectEvent";
    case 31: return "ScrollPrimaryScrollerEvent";
    case 32: return "ReturnToQuestEvent";
    case 33: return "ToAvatar1Event";
    case 34: return "ToAvatar2Event";
    case 35: return "ToAvatar3Event";
    case 36: return "ToAvatar4Event";
    case 37: return "OpenChatEvent";
    case 38: return "ToAvatar5Event";
    case 39: return "ActionNorthEvent";
    case 40: return "ActionEastEvent";
    case 41: return "ActionSouthEvent";
    case 42: return "ActionWestEvent";
    case 43: return "ShowItemDetailEvent";
    case 44: return "ShowPlayerLevelRewardEvent";
    case 45: return "ChangeTeamEvent";
    case 46: return "ChangeTeamNameEvent";
    case 47: return "FastTeamSelectEvent";
    case 48: return "SubmitFastTeamSelect";
    case 49: return "ShowHelpTips";
    case 51: return "BuyResin";
    case 52: return "ChangeFocusZone";
    case 53: return "ShowCycleDungeonOnly";
    case 54: return "ChangeCustomMarkName";
    case 55: return "RemoveCustomMark";
    case 56: return "OpenChatCancelEvent";
    case 57: return "IncreaseCountReleaseEvent";
    case 58: return "DecreaseCountReleaseEvent";
    case 59: return "ItemSourceSelectEvent";
    case 60: return "ChallengeInterruptEvent";
    case 61: return "ToNextScrollerOptionEvent";
    case 62: return "ToPrevScrollerOptionEvent";
    case 63: return "ConfirmScrollerSelectEvent";
    case 64: return "CancelScrollerSelectEvent";
    case 65: return "HomeworldCreateCustomSuiteEvent";
    case 66: return "HomeworldFurnitureSearchEvent";
    case 67: return "HomeworldFurnitureSwitchMultiSelectModeEvent";
    case 68: return "HomeworldLeftShoulderSquareEvent";
    case 100: return "ToRewardDetailEvent";
    case 101: return "ToPrevRewardEvent";
    case 102: return "ToNextRewardEvent";
    case 103: return "ToPrevMainQuestEvent";
    case 104: return "ToNextMainQuestEvent";
    case 105: return "ToggleChapterFold";
    case 106: return "NavigateToQuestEvent";
    case 107: return "ScrollSubQuestEvent";
    case 108: return "ChapterSelectEvent";
    case 109: return "ChoosePrevChapterEvent";
    case 110: return "ChooseNextChapterEvent";
    case 111: return "ShowSubQuestDetailEvent";
    case 112: return "ToRewardPageEvent";
    case 113: return "ToggleQuestTrackingEvent";
    case 200: return "ToPrevTabEvent";
    case 201: return "ToNextTabEvent";
    case 202: return "UseEvent";
    case 203: return "DropEvent";
    case 204: return "ToPrevRowEvent";
    case 205: return "ToNextRowEvent";
    case 206: return "ToPrevSlotEvent";
    case 207: return "ToNextSlotEvent";
    case 300: return "ReNameEvent";
    case 400: return "UIZoomCameraEvent";
    case 401: return "UIDetails";
    case 500: return "MoveCursorEvent";
    case 501: return "ZoomInMapEvent";
    case 502: return "ZoomOutMapEvent";
    case 600: return "CommonLeftStickUpEvent";
    case 601: return "CommonLeftStickDownEvent";
    case 602: return "CommonLeftStickLeftEvent";
    case 603: return "CommonLeftStickRightEvent";
    case 604: return "CommonChangeViewEvent";
    case 605: return "CommonMenuUpEvent";
    case 606: return "CommonMenuLeftEvent";
    case 607: return "CommonRightStickLeftEvent";
    case 608: return "CommonRightStickRightEvent";
    case 630: return "CommonRightStickUpEvent";
    case 631: return "CommonRightStickDownEvent";
    case 610: return "CommonLeftStickButtonEvent";
    case 611: return "CommonRightStickButtonEvent";
    case 612: return "CommonRightTriggerEvent";
    case 613: return "CommonLeftTriggerEvent";
    case 614: return "CommonRightShoulderEvent";
    case 615: return "CommonLeftShoulderEvent";
    case 616: return "CommonLeftShoulderReleaseEvent";
    case 617: return "CommonRightShoulderReleaseEvent";
    case 620: return "CommonLeftStickVerticalEvent";
    case 621: return "CommonRightStickVerticalEvent";
    case 622: return "CommonLeftStickHorizontalEvent";
    case 623: return "CommonRightStickHorizontalEvent";
    case 700: return "Revive";
    case 800: return "Goddess_ContributeSome";
    case 801: return "Goddess_ContributeAll";
    case 802: return "Goddess_ScrollUpgradeReward";
    case 803: return "ToggleSpringAutoUseEvent";
    case 900: return "DialogSelectEvent";
    case 901: return "ToNextDialogEvent";
    case 1000: return "VisitorLoginEvent";
    case 1001: return "SwitchServerLoginEvent";
    case 1020: return "GachaNoticeEvent";
    case 1021: return "GachaHistoryEvent";
    case 1022: return "GachaOnceEvent";
    case 1023: return "GachaTenTimesEvent";
    case 1024: return "GachaNextEvent";
    case 1101: return "BuyEvent";
    case 1102: return "TipsEvent";
    case 1103: return "BuyInfoEvent";
    case 1104: return "MallHelpEvent";
    case 1201: return "MaterialAddEvent";
    case 1202: return "McoinAddEvent";
    case 1203: return "GachaTicketAddEvent";
    case 1301: return "HideEvent";
    case 1302: return "PhotographOpenEmotion";
    case 1401: return "QuickUseEvent";
    case 1402: return "ActivitySkillEvent";
    case 1403: return "ExteraSelectUpEvent";
    case 1404: return "ExteraSelectDownEvent";
    case 1405: return "ExteraSelectLeftEvent";
    case 1406: return "ExteraSelectRightEvent";
    case 1407: return "MusicGameLeftUpEvent";
    case 1408: return "MusicGameLeftRightEvent";
    case 1409: return "MusicGameLeftDownEvent";
    case 1410: return "MusicGameLeftLeftEvent";
    case 1411: return "MusicGameRightUpEvent";
    case 1412: return "MusicGameRightRightEvent";
    case 1413: return "MusicGameRightDownEvent";
    case 1414: return "MusicGameRightLeftEvent";
    case 1415: return "MusicGameLeftUpReleasedEvent";
    case 1416: return "MusicGameLeftRightReleasedEvent";
    case 1417: return "MusicGameLeftDownReleasedEvent";
    case 1418: return "MusicGameLeftLeftReleasedEvent";
    case 1419: return "MusicGameRightUpReleasedEvent";
    case 1420: return "MusicGameRightRightReleasedEvent";
    case 1421: return "MusicGameRightDownReleasedEvent";
    case 1422: return "MusicGameRightLeftReleasedEvent";
    case 1423: return "MusicGameFree1Event";
    case 1424: return "MusicGameFree2Event";
    case 1425: return "MusicGameFree3Event";
    case 1426: return "MusicGameFree4Event";
    case 1427: return "MusicGameFree5Event";
    case 1428: return "MusicGameFree6Event";
    case 1429: return "MusicGameFree7Event";
    case 1430: return "MusicGameFree8Event";
    case 1431: return "MusicGameFree9Event";
    case 1432: return "MusicGameFree10Event";
    case 1433: return "MusicGameFree11Event";
    case 1434: return "MusicGameFree12Event";
    case 1435: return "MusicGameFree13Event";
    case 1436: return "MusicGameFree14Event";
    case 1437: return "MusicGameFree15Event";
    case 1438: return "MusicGameFree16Event";
    case 1439: return "MusicGameFree17Event";
    case 1440: return "MusicGameFree18Event";
    case 1441: return "MusicGameFree19Event";
    case 1442: return "MusicGameFree20Event";
    case 1443: return "MusicGameFree21Event";
    case 1444: return "MusicGamePauseEvent";
    case 1445: return "OpenTeamPageEvent";
    case 1446: return "OpenFriendPageEvent";
    case 1447: return "CommonLeftTriggerPressEvent";
    case 1448: return "CommonLeftTriggerReleaseEvent";
    case 1449: return "CommonRightTriggerPressEvent";
    case 1450: return "CommonRightTriggerReleaseEvent";
    case 1451: return "ArrowUpEvent";
    case 1452: return "ArrowDownEvent";
    case 1453: return "ArrowLeftEvent";
    case 1454: return "ArrowRightEvent";
    case 1455: return "LeftControlEvent";
    case 1456: return "LeftControlReleasedEvent";
    case 1457: return "SpaceEvent";
    case 1458: return "SpaceReleasedEvent";
    case 1459: return "UndoEvent";
    case 1460: return "SaveEvent";
    case 1461: return "OpenMenuEvent";
    case 1462: return "OpenMenuReleaseEvent";
    case 1463: return "HerculesBattleForwardEvent";
    case 1464: return "HerculesBattleBackwardEvent";
    case 1465: return "HerculesBattleCancelEvent";
    case 3501: return "MusicGameFree22Event";
    case 3502: return "MusicGameFree23Event";
    case 3503: return "MusicGameFree24Event";
    case 3504: return "MusicGameFree25Event";
    case 3505: return "MusicGameFree26Event";
    case 3506: return "AkaFesAstrolabeLeftTurnEvent";
    case 3507: return "AkaFesAstrolabeRightTurnEvent";
    case 3508: return "AkaFesAstrolabeHeightChangeEvent";
    case 3701: return "CommonDPadVerticalEvent";
    case 3702: return "CommonDPadHorizontalEvent";
    case 3703: return "ExteraSelectRightReleaseEvent";
    case 3704: return "UGCOpenGlobalSettingEvent";
    case 3705: return "UGCLeftControlPressEvent";
    case 3706: return "UGCLeftControlReleaseEvent";
    case 3707: return "UGCResetCameraEvent";
    case 3708: return "UGCCameraUpPressEvent";
    case 3709: return "UGCCameraUpReleaseEvent";
    case 3710: return "UGCCameraDownPressEvent";
    case 3711: return "UGCCameraDownReleaseEvent";
    case 3712: return "UGCRedoEvent";
    case 3713: return "UGCUndoEvent";
    case 3714: return "UGCDeploySaveEvent";
    case 3715: return "UGCDeployConfirmEvent";
    case 3716: return "UGCFocusCameraEvent";
    case 3717: return "UGCSwitchFloatEvent";
    case 3718: return "UGCRotateEvent";
    case 3719: return "UGCCopyEvent";
    case 3720: return "UGCRecycleEvent";
    case 3721: return "UGCOpenSettingEvent";
    case 3722: return "UGCOpenTriggerEvent";
    case 3723: return "UGCBatchSelectEvent";
    case 3724: return "UGCSelectSuiteEvent";
    case 3725: return "UGCMoveEvent";
    case 3726: return "WidgetQuickSwitch0Event";
    case 3727: return "WidgetQuickSwitch1Event";
    case 3728: return "WidgetQuickSwitch2Event";
    case 3729: return "WidgetQuickSwitch3Event";
    case 3801: return "ReloadEvent";
    case 3802: return "PenAdvShuffleBoardChargeEvent";
    case 3803: return "PenAdvShuffleBoardChargeReleaseEvent";
    case 3805: return "CommonDPadHorizontalAxisEvent";
    case 3806: return "PenAdvShuffleBoardChargeMoveLEvent";
    case 3807: return "PenAdvShuffleBoardChargeMoveREvent";
    case 4011: return "ToyBattleQteLeftEvent";
    case 4012: return "ToyBattleQteRightEvent";
    case 4013: return "ToyBattleQteLeftReleaseEvent";
    case 4014: return "ToyBattleQteRightReleaseEvent";
    case 4101: return "BoxMatchSkill1";
    case 4102: return "BoxMatchSkill2";
    case 4103: return "TrackQuestPressEvent";
    case 4104: return "CommonLeftStickButtonPressEvent";
    case 4105: return "CommonLeftStickButtonReleaseEvent";
    case 4201: return "OpenReunionEvent";
    case 4202: return "FungusV3UseSkill";
    case 4203: return "FungusV3SelectAll";
    case 4301: return "CommonRightStickLeftShowEvent";
    case 4302: return "CommonRightStickRightShowEvent";
    case 4501: return "CommonDPadFourWayEvent";
    case 4601: return "MusicGameFree1ReleaseEvent";
    case 4602: return "MusicGameFree2ReleaseEvent";
    case 4603: return "MusicGameFree3ReleaseEvent";
    case 4604: return "MusicGameFree4ReleaseEvent";
    case 4605: return "MusicGameFree5ReleaseEvent";
    case 4606: return "MusicGameFree6ReleaseEvent";
    case 4607: return "MusicGameFree7ReleaseEvent";
    case 4608: return "MusicGameFree8ReleaseEvent";
    case 4609: return "MusicGameFree9ReleaseEvent";
    case 4610: return "MusicGameFree10ReleaseEvent";
    case 4611: return "MusicGameFree11ReleaseEvent";
    case 4612: return "MusicGameFree12ReleaseEvent";
    case 4613: return "MusicGameFree13ReleaseEvent";
    case 4614: return "MusicGameFree14ReleaseEvent";
    case 4615: return "MusicGameFree15ReleaseEvent";
    case 4616: return "MusicGameFree16ReleaseEvent";
    case 4617: return "MusicGameFree17ReleaseEvent";
    case 4618: return "MusicGameFree18ReleaseEvent";
    case 4619: return "MusicGameFree19ReleaseEvent";
    case 4620: return "MusicGameFree20ReleaseEvent";
    case 4621: return "MusicGameFree21ReleaseEvent";
    case 4622: return "CommonLeftShoulderPressingEvent";
    case 4623: return "CommonRightShoulderPressingEvent";
    case 4701: return "HideSpecificUIEvent";
    case 5001: return "BomberDodocoMoveEvent";
    case 5002: return "BomberDodocoSkill1Event";
    case 5003: return "BomberDodocoSkill2Event";
    case 5101: return "SynthesisAvatarLevelLeftReleaseEvent";
    case 5102: return "SynthesisAvatarLevelRightReleaseEvent";
    case 5201: return "LightStrikeDefendEvent";
    case 5202: return "LightStrikeUltimateEvent";
    case 5203: return "LightStrikeDefendReleaseEvent";
    case 5301: return "InstrumentJoypad1Event";
    case 5302: return "InstrumentJoypad2Event";
    case 5303: return "InstrumentJoypad3Event";
    case 5304: return "InstrumentJoypad4Event";
    case 5305: return "InstrumentJoypad5Event";
    case 5306: return "InstrumentJoypad6Event";
    case 5307: return "InstrumentJoypad7Event";
    case 5308: return "InstrumentJoypad8Event";
    case 5309: return "InstrumentJoypad9Event";
    case 5310: return "InstrumentJoypad10Event";
    case 5311: return "InstrumentKeyboard1Event";
    case 5312: return "InstrumentKeyboard2Event";
    case 5313: return "InstrumentKeyboard3Event";
    case 5314: return "InstrumentKeyboard4Event";
    case 5315: return "InstrumentKeyboard5Event";
    case 5316: return "InstrumentKeyboard6Event";
    case 5317: return "InstrumentKeyboard7Event";
    case 5318: return "InstrumentKeyboard8Event";
    case 5319: return "InstrumentKeyboard9Event";
    case 5320: return "InstrumentKeyboard10Event";
    case 5321: return "InstrumentKeyboard11Event";
    case 5322: return "InstrumentKeyboard12Event";
    case 5323: return "InstrumentKeyboard13Event";
    case 5324: return "InstrumentKeyboard14Event";
    case 5325: return "InstrumentKeyboard15Event";
    case 5326: return "InstrumentKeyboard16Event";
    case 5327: return "InstrumentKeyboard17Event";
    case 5328: return "InstrumentKeyboard18Event";
    case 5329: return "InstrumentKeyboard19Event";
    case 5330: return "InstrumentKeyboard20Event";
    case 5331: return "InstrumentKeyboard21Event";
    case 5332: return "InstrumentKeyboard1ReleaseEvent";
    case 5333: return "InstrumentKeyboard2ReleaseEvent";
    case 5334: return "InstrumentKeyboard3ReleaseEvent";
    case 5335: return "InstrumentKeyboard4ReleaseEvent";
    case 5336: return "InstrumentKeyboard5ReleaseEvent";
    case 5337: return "InstrumentKeyboard6ReleaseEvent";
    case 5338: return "InstrumentKeyboard7ReleaseEvent";
    case 5339: return "InstrumentKeyboard8ReleaseEvent";
    case 5340: return "InstrumentKeyboard9ReleaseEvent";
    case 5341: return "InstrumentKeyboard10ReleaseEvent";
    case 5342: return "InstrumentKeyboard11ReleaseEvent";
    case 5343: return "InstrumentKeyboard12ReleaseEvent";
    case 5344: return "InstrumentKeyboard13ReleaseEvent";
    case 5345: return "InstrumentKeyboard14ReleaseEvent";
    case 5346: return "InstrumentKeyboard15ReleaseEvent";
    case 5347: return "InstrumentKeyboard16ReleaseEvent";
    case 5348: return "InstrumentKeyboard17ReleaseEvent";
    case 5349: return "InstrumentKeyboard18ReleaseEvent";
    case 5350: return "InstrumentKeyboard19ReleaseEvent";
    case 5351: return "InstrumentKeyboard20ReleaseEvent";
    case 5352: return "InstrumentKeyboard21ReleaseEvent";
    case 5353: return "InstrumentJoypad1ReleaseEvent";
    case 5354: return "InstrumentJoypad2ReleaseEvent";
    case 5355: return "InstrumentJoypad3ReleaseEvent";
    case 5356: return "InstrumentJoypad4ReleaseEvent";
    case 5357: return "InstrumentJoypad5ReleaseEvent";
    case 5358: return "InstrumentJoypad6ReleaseEvent";
    case 5359: return "InstrumentJoypad7ReleaseEvent";
    case 5360: return "InstrumentJoypad8ReleaseEvent";
    case 5361: return "InstrumentJoypad9ReleaseEvent";
    case 5362: return "InstrumentJoypad10ReleaseEvent";
    case 5363: return "PuzzleFighterLeftEvent";
    case 5364: return "PuzzleFighterRightEvent";
    case 5365: return "PuzzleFighterDownEvent";
    case 5366: return "PuzzleFighterDownReleaseEvent";
    case 5367: return "PuzzleFighterRotEvent";
    case 5368: return "PuzzleFighterSkillEvent";
    case 5369: return "PuzzleFighterLeftReleaseEvent";
    case 5370: return "PuzzleFighterRightReleaseEvent";
    case 5371: return "PuzzleFighterLeftPressingEvent";
    case 5372: return "PuzzleFighterRightPressingEvent";
    case 5373: return "PuzzleFighterDownPressingEvent";
    case 5374: return "PuzzleFighterRotAlt1Event";
    case 5375: return "KeyCodeWReleaseEvent";
    case 5401: return "TriggerWheelMenuEvent";
    case 5501: return "LongyiwuCannonLaunchEvent";
    case 5601: return "CommonKeyCodePEvent";
    case 5602: return "CommonTriggerActivitySkillEvent";
    case 5801: return "CommonMouseLeftButtonEvent";
    case 5802: return "CommonMouseRightButtonEvent";
    case 5803: return "KeyCodeEEvent";
    case 5804: return "PartyDJLeftPressingEvent";
    case 5805: return "PartyDJLeftReleaseEvent";
    case 5806: return "PartyDJRightPressingEvent";
    case 5807: return "PartyDJRightReleaseEvent";
    case 5808: return "PartyDJSwitchCameraEvent";
    case 5809: return "PartyDJBulletEvent";
    case 5810: return "PartyDJSubQTEEvent";
    case 5811: return "PartyDJMainQTEEvent";
    case 5812: return "ShootCoasReloadEvent";
    case 5813: return "ShootCoasSkillPressingEvent";
    case 5814: return "ShootCoasSkillReleaseEvent";
    case 5815: return "ShootCoasExitPressingEvent";
    case 5816: return "ShootCoasExitReleaseEvent";
    case 5817: return "ShootCoasShotPressingEvent";
    case 5818: return "ShootCoasShotReleaseEvent";
    case 5819: return "ShootCoasLeftShotEvent";
    case 6001: return "LockStepQuitEvent";
    case 6002: return "BomberV3Skill3Event";
    case 6003: return "LockStepGMEvent";
    case 6004: return "ExteraSelectLeftReleaseEvent";
    case 6101: return "ShortcutKeyCodeQEvent";
    case 6102: return "ShortcutKeyCodeEEvent";
    case 6103: return "ShortcutKeyCodeAEvent";
    case 6104: return "ShortcutKeyCodeDEvent";
    case 6105: return "ShortcutKeyCodeWEvent";
    case 6106: return "ShortcutKeyCodeSEvent";
    case 6107: return "ShortcutKeyCodeREvent";
    case 6108: return "ShortcutKeyCodeRReleaseEvent";
    case 6109: return "ShortcutKeyCodeFEvent";
    case 6110: return "ShortcutKeyCodeFReleaseEvent";
    case 6111: return "UGCCustomPopupHideHintEvent";
    case 6201: return "HomeworldEditorSettingEvent";
    case 6202: return "HomeworldEditorSelectModeEvent";
    case 6203: return "HomeworldEditorRotateModeEvent";
    case 6204: return "HomeworldEditorCancelEvent";
    case 6205: return "HomeworldEditorTakeEvent";
    case 6206: return "HomeworldEditorRotateEvent";
    case 6207: return "HomeworldEditorConfirmEvent";
    case 6208: return "HomeworldEditorEditSuitEvent";
    case 6209: return "HomeworldEditorMoveCameraEvent";
    case 6301: return "KeyCodeQEvent";
    case 6501: return "CommonRightStickMoveEvent";
    }
    return nullptr;
}

// IDGNBAFCBOI（枚举，底层 Int32，4 字节）
enum class T_IDGNBAFCBOI : int32_t {
    INVESTIGATION_ADVENTURE = 0,
    INVESTIGATION_HOMEWORLD = 1,
    INVESTIGATION_EDCATION = 2,
    INVESTIGATION_GCG = 3,
    INVESTIGATION_MAIN_QUEST = 4
};
static_assert(sizeof(T_IDGNBAFCBOI) == 4, "T_IDGNBAFCBOI");
inline const char* enum_name(T_IDGNBAFCBOI v) {
    switch ((int32_t)v) {
    case 0: return "INVESTIGATION_ADVENTURE";
    case 1: return "INVESTIGATION_HOMEWORLD";
    case 2: return "INVESTIGATION_EDCATION";
    case 3: return "INVESTIGATION_GCG";
    case 4: return "INVESTIGATION_MAIN_QUEST";
    }
    return nullptr;
}

// QuestState（枚举，底层 Int32，4 字节）
enum class T_MoleMole_Config_QuestState : int32_t {
    QUEST_STATE_NONE = 0,
    QUEST_STATE_UNSTARTED = 1,
    QUEST_STATE_UNFINISHED = 2,
    QUEST_STATE_FINISHED = 3,
    QUEST_STATE_FAILED = 4
};
static_assert(sizeof(T_MoleMole_Config_QuestState) == 4, "T_MoleMole_Config_QuestState");
inline const char* enum_name(T_MoleMole_Config_QuestState v) {
    switch ((int32_t)v) {
    case 0: return "QUEST_STATE_NONE";
    case 1: return "QUEST_STATE_UNSTARTED";
    case 2: return "QUEST_STATE_UNFINISHED";
    case 3: return "QUEST_STATE_FINISHED";
    case 4: return "QUEST_STATE_FAILED";
    }
    return nullptr;
}

// GFJCNBMJPCH（枚举，底层 Int32，4 字节）
enum class T_GFJCNBMJPCH : int32_t {
    None = 0,
    NetworkPacket = 1,
    LoginNotify = 2,
    EnterSceneNotify = 3,
    DisConnectNotify = 4,
    PlayerListNotify = 5,
    PlayerLeaveNotify = 6,
    GetOnlinePlayerInfoNotify = 7,
    WorldPlayerListUpdate = 8,
    ScenePlayerListUpdate = 9,
    PrompStandy2Climb = 10,
    RegisterMonsterAIController = 11,
    AttackDamegeNotify = 12,
    AttackShieldNotify = 13,
    ShowDamageTextNotify = 14,
    AttackCureNotify = 15,
    RefreshAvatarData = 16,
    RefreshAvatarBuff = 17,
    AvatarChangeNotify = 18,
    AvatarActionPanelNotify = 19,
    PlayerStaminaWarning = 20,
    AvatarFocusModeChangeNotify = 21,
    ElementReactionNotify = 22,
    ShowCustomDamageTextNotify = 23,
    OnApplicationFocus = 24,
    OnApplicationPauseCanNotCache = 25,
    AvatarSkillInfoUpdate = 26,
    FestivalUpdateNotify = 27,
    AfterSECTRFastReset = 28,
    AvatarRenameInfoReady = 29,
    AvatarRenameInfoUpdated = 30,
    AvatarRenameValidityCheckPassed = 31,
    AvatarRenameValidityCheckFailed = 32,
    MiscRenameInfoReady = 33,
    MiscRenameInfoUpdated = 34,
    MiscRenameValidityCheckPassed = 35,
    MiscRenameValidityCheckFailed = 36,
    AddMiniMapMark = 37,
    MapNotify = 38,
    MapToggle = 39,
    EnterArea = 40,
    EnterAreaLateUpdate = 41,
    EnterSubArea = 42,
    ExitSubArea = 43,
    EnterErosionArea = 44,
    MapMarkChanged = 45,
    MapMarkMoved = 46,
    MapMarkDailyTaskChanged = 47,
    MapMarkDungeonEntryExploreChanged = 48,
    MapMarkDynamicAlwaysShowUpdate = 49,
    AreaExploreUpdated = 50,
    AreaExplorePointUpdated = 51,
    MultiAreaExplorePercentUpdated = 52,
    AreaUnlcoked = 53,
    GuidePointAppear = 54,
    GuidePointDisappear = 55,
    NavigationPointAppear = 56,
    NavigationPointDisappear = 57,
    NavigationPointRefresh = 58,
    NavigtaionPointRefreshWithId = 59,
    NavigationPointChangeIcon = 60,
    NavigationShowGuideTips = 61,
    POIIndicatorAppear = 62,
    POIIndicatorDisappear = 63,
    BossNavigationAppear = 64,
    BossNavigationDisappear = 65,
    SorushIndicatorAppear = 66,
    SorushIndicatorDisappear = 67,
    TradeShowBonusIndicatorAppear = 68,
    TradeShowBonusIndicatorDisappear = 69,
    QuestPOINaviPathUpdate = 70,
    PlayMarkUnlockEffect = 71,
    UnlockTransPoint = 72,
    UnlockScenePoint = 73,
    UpdateSceneUnlockState = 74,
    ScenePointLockStateChanged = 75,
    ScenePointMarkUpdate = 76,
    AddGadgetIndicator = 77,
    RemoveGadgetIndicator = 78,
    SetGadgetIndicatorCountDown = 79,
    SetBossIndicatorCountDown = 80,
    ForceSetGadgetIndicatorCountDown = 81,
    MapMarkClicked = 82,
    MapMarkClickNeared = 83,
    RefreshMapRewardTips = 84,
    RefreshMapMarkTips = 85,
    MapAreaUpdated = 86,
    MapPlaceNameUpdated = 87,
    MarkManagerReady = 88,
    MarkRemovedOnCancelTracing = 89,
    MarkCustomTrackChanged = 90,
    ShowMiniMapCustomSignal = 91,
    GetSceneAreaRsp = 92,
    GetScenePointRsp = 93,
    RefreshMiniMapScale = 94,
    RefreshSubAreaHideStatus = 95,
    CloseMapMarkTipsOfMark = 96,
    ActivityMapMarkBatchUpdate = 97,
    ActivityMapScaleUpdate = 98,
    ActivityMapCoinUpdate = 99,
    DungeonEntryInfo = 100,
    DungeonEntryInfoProtoClone = 101,
    DungeonEntryInfoRecommendIgnoreQuest = 102,
    DungeonEntryAppeared = 103,
    DungeonEntryDisappeared = 104,
    DungeonPlayerDie = 105,
    DungeonSettled = 106,
    DungeonGetReward = 107,
    DungeonDifficultyChanged = 108,
    DungeonEntryQuickOpened = 109,
    GetDailyDungeonEntryInfo = 110,
    GetDungeonEntryExploreCondition = 111,
    GeneralInteeCreate = 112,
    GeneralInteeCommand = 113,
    GeneralInteeDisable = 114,
    RegisterUICombatBar = 115,
    UnregisterUICombatBar = 116,
    RefreshUICombatBars = 117,
    ShowUICombatBarSpark = 118,
    ShowUICombatBarCharge = 119,
    ShowUICombatBarFireEffect = 120,
    ShowShakeOff = 121,
    VehicleSkillDepotChange = 122,
    VehicleSkillEnergyChange = 123,
    InteractionUITrigger = 124,
    InteractionUIClose = 125,
    InteractionUIAnimSetTrigger = 126,
    InteractionUIAnimSetInt = 127,
    InteractionUIAnimSetFloat = 128,
    InteractionUIAnimSetBool = 129,
    InterQueryUiJumpNextGrp = 130,
    InteractionRealStart = 131,
    TalkNoBlackPrepareStart = 132,
    TalkStart = 133,
    TalkStartInternal = 134,
    TalkEndInternal = 135,
    TalkEndReal = 136,
    TalkValueUpdate = 137,
    OnTalkQuickSkip = 138,
    GroupLinkUpdated = 139,
    GroupLinkRemoved = 140,
    CheckGroupReplacedRsp = 141,
    RefreshCrossHair = 142,
    CustomLoadingFadeInFinish = 143,
    ChallengeBegin = 144,
    ChallengeUpdated = 145,
    ChallengeFailed = 146,
    ChallengeCompleted = 147,
    ChallengeAddSub = 148,
    ChallengeSubFinish = 149,
    ChallengeSubFail = 150,
    RefreshInLevelChallengeView = 151,
    RefreshSpacecraftExhibitManagePage = 152,
    DialogSelectNotify = 153,
    DialogSelectFinishNotify = 154,
    DialogSelectItemNotify = 155,
    DialogSelectItemTimeOut = 156,
    TalkSelectDialogNotify = 157,
    AutoTalkDialogFinish = 158,
    ChangeAutoTalk = 159,
    TalkShowItemList = 160,
    TalkCloseItemList = 161,
    CutScenePageShowTopText = 162,
    CutScenePageCloseTopText = 163,
    TalkShowReminder = 164,
    TalkCloseReminder = 165,
    TalkBgPicSetPosAndScale = 166,
    TalkBgPicMove = 167,
    UpdateTalkerName = 168,
    UITriggerStart = 169,
    OnDispatchFinishInterEvent = 170,
    OnStartInterEvent = 171,
    CoopSelectNotify = 172,
    CurrCoopConfidenceValueChanged = 173,
    CurrCoopTemperamentValueChanged = 174,
    CoopTemperamentSelect = 175,
    CoopTakeChapterReward = 176,
    CoopUnlockChapter = 177,
    CoopStartPointFromPage = 178,
    CoopCancelQuest = 179,
    CoopUIRefresh = 180,
    CoopNewChapterAdd = 181,
    CoopChapterViewed = 182,
    CoopStartFirstPoint = 183,
    CoopShowDefeatDialog = 184,
    CoopTryStartPoint = 185,
    CoopStartPointFailed = 186,
    CoopDefeatNotify = 187,
    CoopPressureMaxNotify = 188,
    QuestDialogToggle = 189,
    QuestBookUpdate = 190,
    QuestBookSelectItem = 191,
    AddQuestHint = 192,
    AddQuestPauseHint = 193,
    ContinueMutualQuest = 194,
    QuestMutualStateChangedPre = 195,
    QuestMutualStateChangedPost = 196,
    QuestLackNPCChangedPre = 197,
    QuestLackNPCChangedPost = 198,
    QuestLackPlaceChangedPre = 199,
    QuestLackPlaceChangedPost = 200,
    PaimenNavigationEnabled = 201,
    PaimenNavigationFailed = 202,
    PaimenNavigationAlreadyInArea = 203,
    PaimenNavigationInAreaOtherLayer = 204,
    PaimenNavigationGuideHint = 205,
    PaimenNavigationClockPageHint = 206,
    NavigationUpdate = 207,
    RemindQuest = 208,
    BindTransButton = 209,
    QuestProgressHint = 210,
    QuestLackHint = 211,
    QuestRemovedHint = 212,
    GetFocusModeConflictParentQuestRspSucc = 213,
    GetFocusModeConflictParentQuestRsp = 214,
    QuestFocusModeDataUpdate = 215,
    QuestQuitFocusMessageHint = 216,
    ConfirmFocusAfterContinueMutual = 217,
    QuestSceneryPausedMainPageHint = 218,
    QuestSceneryResume = 219,
    QuestSceneryInfoUpdate = 220,
    NewDungeonQuestRewindPoint = 221,
    QuestQuickLaunch = 222,
    ActiveMainQuestDeleted = 223,
    AfterQuestUpdatePreOnStateChanged = 224,
    AfterQuestUpdatePostOnStateChanged = 225,
    AfterQuestUpdatePre = 226,
    AfterQuestUpdatePost = 227,
    QuestRemoved = 228,
    QuestStateUpdated = 229,
    MainQuestStateUpdated = 230,
    QuestTalkFinished = 231,
    QuestGlobalVarUpdate = 232,
    QuestVarUpdate = 233,
    QuestTakePhotograph = 234,
    ServerGameTimeLockedQuestListRsp = 235,
    TalkWithPerformStart = 236,
    FinishedTalkRecordUpdate = 237,
    NearbyTrackableQuestAppear = 238,
    NearbyTrackableQuestDisappear = 239,
    TribalChapterInfoUpdate = 240,
    TribalRedpointRefresh = 241,
    ExecQuestLoadCtxOp = 242,
    StopAllNarratorWithPriority = 243,
    SubQuestTrackUpdate = 244,
    OngoingQuestMarkUpdate = 245,
    AnecdoteInfoInit = 246,
    AnecdoteUpdate = 247,
    AnecdoteFinish = 248,
    AnecdoteConflictInfoRsp = 249,
    AnecdoteCanWishRsp = 250,
    AnecdoteWishSucc = 251,
    AnecdoteWishInfoUpdate = 252,
    AnecdoteRewardInfoUpdate = 253,
    AnecdoteAreaInfoUpdate = 254,
    AnecdotePopAreaUnlock = 255,
    AnecdoteRewardItemAdd = 256,
    StoryPreCancel = 257,
    StoryCancel = 258,
    CloseQPCDebug = 259,
    StoryStart = 260,
    StoryEnd = 261,
    StoryGlobalValueChanged = 262,
    NpcReady = 263,
    NpcReadyPost = 264,
    NpcAppear = 265,
    NpcDisappear = 266,
    NpcDestroy = 267,
    NpcTalkStateChange = 268,
    NpcDailyStart = 269,
    NpcReactionStateChange = 270,
    NpcDisabled = 271,
    NpcBornInfoRemove = 272,
    NpcBanned = 273,
    NpcFreed = 274,
    NpcNotify = 275,
    OrphanNpcRemove = 276,
    ClientScriptEventRsp = 277,
    BagWeightUIRefresh = 278,
    BagDialogToggle = 279,
    BagSlotUpdate = 280,
    BagItemUsed = 281,
    BagItemDrop = 282,
    BagAddChest = 283,
    BagAddWidget = 284,
    BagAddQuest = 285,
    BagCombinableMaterialRPChanged = 286,
    ForceCloseBagPage = 287,
    BagItemDeleteReturnNotify = 288,
    BeyondItemDeleteReturnNotify = 289,
    BeyondMaterialDeleteTransferRsp = 290,
    BeyondMaterialDeleteInfoUpdate = 291,
    BeyondMaterialExpiredNotify = 292,
    BeyondMaterialObtainedNotify = 293,
    RefreshBagPageRedpoints = 294,
    NewItemEncountered = 295,
    SpecialItemEncountered = 296,
    AccessCardItemEncountered = 297,
    EscoffierCookItemEncountered = 298,
    BeyondAvatarItemEncountered = 299,
    ItemAdded = 300,
    ItemAddedByShop = 301,
    ItemAddedByShopBydAutoFreeBuyBundle = 302,
    MaterialDeleteReturnItemAdded = 303,
    ItemAddExceedLimitNotify = 304,
    GatherItemAdded = 305,
    GeneralItemAdded = 306,
    GeneralItemMiddleShowAdded = 307,
    QuestItemAdded = 308,
    DailyTaskItemAdded = 309,
    RandTaskItemAdded = 310,
    ActivityItemAdded = 311,
    HuntingItemAdded = 312,
    HuntingV2ItemAdded = 313,
    DonationItemAdded = 314,
    ReputationCityTribalLevelRewardItemAdded = 315,
    ReputationCityTotalRewardItemAdded = 316,
    BlossomItemAdded = 317,
    VirtualShopItemAdded = 318,
    BeyondBagItemAdded = 319,
    CollectedItemAdded = 320,
    BatchItemAdded = 321,
    BatchRealItemAdded = 322,
    BatchBuyGoodsNotify = 323,
    ItemGivingFinish = 324,
    CloseItemGiving = 325,
    GadgetGivingClose = 326,
    ItemExchangeFinish = 327,
    OnItemGivingRsp = 328,
    OnItemExchangeRsp = 329,
    DestroyItemFinish = 330,
    GetCalcWeaponUpgradeReturnItemsResult = 331,
    ChangeEquipLockState = 332,
    ChangeRelicStarState = 333,
    ChangeFoodStarState = 334,
    UseItemFail = 335,
    BagAddRenameItem = 336,
    BagAddFireMaster = 337,
    BagAddNatlanRaceEnvelope = 338,
    BagAddNatlanRaceAlbum = 339,
    BagAddHomeworldModuleItem = 340,
    BagItemDestroyUIRefresh = 341,
    StoredItemsChanged = 342,
    RepeatedCostumeItemUsed = 343,
    GainWeaponSkinItem = 344,
    BagAddTreasureKey = 345,
    AvatarVehicleStateChange = 346,
    VehicleHPChange = 347,
    VehicleLevelChange = 348,
    OperateVehicleStateChange = 349,
    VehicleInteractFailed = 350,
    OperateVehicleListChange = 351,
    AvatarInfoUIRefresh = 352,
    AvatarFightPropRefresh = 353,
    AvatarEquipUIRefresh = 354,
    AvatarEquipChanged = 355,
    AvatarSwitch = 356,
    ManekinCtrl = 357,
    TeamInfoRefresh = 358,
    TeamNameRefresh = 359,
    CurrentTeamChanged = 360,
    AvatarDead = 361,
    AvatarSkillDepotIdChanged = 362,
    AvatarLevelChangedNoDependent = 363,
    AvatarBreakLevelChanged = 364,
    AvatarBreakRewardGet = 365,
    RefreshBreachMaterialBtnRPShow = 366,
    AvatarLifeStateChanged = 367,
    AvatarFetterExpChanged = 368,
    AvatarFetterRewardGet = 369,
    AvatarHPChanged = 370,
    AvatarHPChangedEnd = 371,
    AvatarHPDebtRefresh = 372,
    AvatarHPDebtPayFinish = 373,
    AvatarHPDebtClear = 374,
    AvatarHungerChanged = 375,
    BackgroundAvatarRefreshed = 376,
    AvatarUpgradeNotify = 377,
    AvatarLevelChanged = 378,
    BeyondAvatarPromoteNotify = 379,
    AvatarEnergyAdded = 380,
    AvatarEnergyFull = 381,
    AvatarSpecialEnergyAdded = 382,
    AvatarSpecialEnergyStateChange = 383,
    CharacterSprintBS = 384,
    AvatarSkillChanged = 385,
    AvatarSkillDisable = 386,
    AvatarSkillCDChanged = 387,
    AvatarSkillEnable = 388,
    AvatarHideSkill = 389,
    AvatarAttackModeChanged = 390,
    CurAvatarNum = 391,
    FocusAvatar = 392,
    AvatarFlycloakChanged = 393,
    AvatarGainFlycloak = 394,
    ActivitySkillState = 395,
    ShowActivitySkill = 396,
    RefreshActivitySkillVFX = 397,
    AvatarCostumeChanged = 398,
    AvatarGainCostume = 399,
    AvatarTraceEffectChanged = 400,
    AvatarGainTraceEffect = 401,
    AvatarWeaponSkinChanged = 402,
    AppearanceAvatarChanged = 403,
    AvatarSkillLTChanged = 404,
    AvatarSkillLeftChanged = 405,
    PlayerStaminaChanged = 406,
    AvatarRedPointRefresh = 407,
    AvatarShowHyperLinkExplanation = 408,
    AvatarExtraLevelUpNotify = 409,
    TipShow = 410,
    TipClose = 411,
    ActivityCommonPlayerTipsStart = 412,
    ActivityCommonPlayerTipsFinish = 413,
    ActivityCommonPlayerTipsFinishWithSubtitle = 414,
    ActivityCommonPlayerTipsFail = 415,
    ShopOpen = 416,
    ShopClose = 417,
    ShopItemSelect = 418,
    ShopRefresh = 419,
    ShopMaterialRefresh = 420,
    ShopRequest = 421,
    ShopRequestRecommend = 422,
    ShopRequestPackage = 423,
    ShopMallRequest = 424,
    ShopDataUpdated = 425,
    ActivityShopSheetUpdated = 426,
    ShopOpenSubTab = 427,
    MallJumpRecommend = 428,
    HomeShopCartInfoUpdated = 429,
    OnBuyGoodsSuccess = 430,
    MockAppearanceShopPurchase = 431,
    ActivityRegionSearchProgressUpdate = 432,
    ActivityRegionSearchProgressBegin = 433,
    ActivityRegionSearchProgressComplete = 434,
    ActivityRegionSearchIn = 435,
    ActivityRegionSearchOut = 436,
    ActivityRegionSearchRegionRewardGet = 437,
    ActivityRegionSearchRegionDisappear = 438,
    ActivityRegionSearchRegionAppear = 439,
    ActivityRegionSearchRegionInfoUpdate = 440,
    CountDownUIStart = 441,
    CountDownUIEndLevelTime = 442,
    CountDownUITerminate = 443,
    CountDownUIBegin = 444,
    CountDownUIPause = 445,
    CountDownUIResume = 446,
    CountDownUIEnd = 447,
    DungeonCountDownUpdate = 448,
    DungeonCountDownEnd = 449,
    BeginCustomDungeonCountDown = 450,
    EndCustomDungeonCountDown = 451,
    PauseCustomDungeonCountDown = 452,
    ResumeCustomDungeonCountDown = 453,
    CountNumUIStart = 454,
    CountNumUpdate = 455,
    CountNumUITerminate = 456,
    CountNumUIStartNew = 457,
    CountNumUpdateNew = 458,
    CountNumUITerminateNew = 459,
    QuestQuitShow = 460,
    QuestQuitHide = 461,
    GachaWishUpdate = 462,
    LoadingNewScenePre = 463,
    LoadingScene = 464,
    LevelPreLoaded = 465,
    LevelLoaded = 466,
    LevelPostLoad = 467,
    LevelLoadBegin = 468,
    LoadingBundle = 469,
    LevelLoadFinish = 470,
    QuestTransmitFail = 471,
    NoStaminaStopSprint = 472,
    JumpFly = 473,
    PostAvatarEntityReady = 474,
    AudioEventPost = 475,
    LevelTagNotify = 476,
    SceneAreaWeatherChangeNotify = 477,
    TouchMsgBoard = 478,
    EasyTouchWorking = 479,
    RefreshUISetting = 480,
    ScreenResolutionChanged = 481,
    RefreshAvatarTalent = 482,
    RefreshAvatarTalentPRShow = 483,
    Resist = 484,
    GuideStarted = 485,
    GuideUpdate = 486,
    GuideFinished = 487,
    PageLoad = 488,
    UIContextOpen = 489,
    UIContextClose = 490,
    UIContextCloseFinal = 491,
    PageShow = 492,
    PageDestroy = 493,
    ElementViewChange = 494,
    SealProgress = 495,
    CommonChallengeStartTips = 496,
    CommonChallengeEndTips = 497,
    RefreshGuide = 498,
    RefreshGuideForceInit = 499,
    GeneralGuideFinish = 500,
    GeneralGuideUpdate = 501,
    GuideMaskAppear = 502,
    ActionToUINotify = 503,
    ActionToUINotifyWithTarget = 504,
    ActionToUIQteNotify = 505,
    UIModelSetupEasyTouchClick = 506,
    RefreshDebugUI = 507,
    CheckDebugLoginServerList = 508,
    ShowDebugLoginPanel = 509,
    TimeChanged = 510,
    PlayerGameTimeNotify = 511,
    TeamSceneReady = 512,
    TeamChanged = 513,
    AvatarReviveRequested = 514,
    TeamRttRefresh = 515,
    ShowTeamBtn = 516,
    TeamPageChangeESP = 517,
    FireTeamButtonEffect = 518,
    LevelUpItemFinished = 519,
    PostSetupMPTeamPanel = 520,
    WeaponUpgrade = 521,
    WeaponPromote = 522,
    WeaponAwaken = 523,
    ReliquaryUpgrade = 524,
    ReliquaryPromote = 525,
    TeammateSpeechBegin = 526,
    TeammateSpeechEnd = 527,
    AvatarCardChange = 528,
    SpringVolumeChanged = 529,
    WebviewClose = 530,
    MihoyoAccountInfoChanged = 531,
    MihoyoAccountRegisterSuccess = 532,
    CutsceneStart = 533,
    CutsceneFinish = 534,
    FinalTalkFinished = 535,
    CutsceneQTEJump = 536,
    CurrentQTEFinishCS = 537,
    CurrentQTEBlackScreenStart = 538,
    CutsceneQTEEnableSavePoint = 539,
    CutsceneQTEEnableSavePointId = 540,
    CutsceneChangeTimeScale = 541,
    CutsceneResumeTimeScale = 542,
    InterCutsceneActionStart = 543,
    VideoStart = 544,
    NetworkVideoServerCfgNotFound = 545,
    NetworkVideoSimulateCriErrRecovery = 546,
    BlackScreenStart = 547,
    SetMainPageMoveToggleActive = 548,
    SetMainPageMoveToggleToWalk = 549,
    OpenStateInit = 550,
    OpenStateChange = 551,
    GuestOpenStateInit = 552,
    GuestOpenStateChange = 553,
    StartFadeOutWormhole = 554,
    StartFadeOutTemplateLoading = 555,
    OnAuthorityAvatarAppearBeforeTrans = 556,
    OnAuthorityAvatarAppearAfterTrans = 557,
    EnterSneakMode = 558,
    EnterCombatSneakMode = 559,
    ExitSneakMode = 560,
    PlayModeChange = 561,
    ActionSlotChange = 562,
    ActionPanelStateChangedByPlayModeSys = 563,
    TrainingGuideCustomNetworkAction = 564,
    ActionPanelSetup = 565,
    ActionPanelRefresh = 566,
    ActionPanelClearInputState = 567,
    RefreshActionPanel = 568,
    RefreshCookPage = 569,
    GetCookQTEArgs = 570,
    OnCookRecipeDataNotify = 571,
    RefreshCookCompoundPage = 572,
    GetCompoundOutput = 573,
    CompoundBoostRsp = 574,
    GetCombineOutput = 575,
    CombineFormulaUnlock = 576,
    CombineLimitUpdate = 577,
    SmeltSuccess = 578,
    SmeltGetDrop = 579,
    GetForgeQueue = 580,
    ForgeQueueUpdate = 581,
    GetForgeOutput = 582,
    ForgeStart = 583,
    ForgeStop = 584,
    ForgeFormulaUnlock = 585,
    RefreshMailPage = 586,
    RefreshMailPageAfterDel = 587,
    MailDataReady = 588,
    ShowMailItemGet = 589,
    NewMailGot = 590,
    AddToFavorites = 591,
    RefreshMailFavoritesDialog = 592,
    RefreshMailFavoritesDialogAfterDel = 593,
    RefreshMailPageAfterFavMailChange = 594,
    FavoriteMailDataReady = 595,
    RefreshCoinNum = 596,
    MutiPlayerAvailableChange = 597,
    MutiPlayerModeChange = 598,
    CompanionCurrAvatarChanged = 599,
    CompanionAvatarHPChangedEnd = 600,
    KickGuestFailed = 601,
    MPTeamChangeFailed = 602,
    MPDeathOpenChat = 603,
    MPCloseMainPageBtn = 604,
    MPOpenMainPageBtn = 605,
    PlayerMatchInfoUpdate = 606,
    WorldPlayerDie = 607,
    MpSettingType = 608,
    JoinOtherPlayerScene = 609,
    BackMyWorld = 610,
    DraftOwnerStartInviteRsp = 611,
    DraftInviteResult = 612,
    PlayerMatchAgreedResult = 613,
    UpdateDungeonExitBtn = 614,
    DungeonTeamChanged = 615,
    DungeonTeamChangeFailed = 616,
    DungeonTeamDismissed = 617,
    DungeonInviteRefused = 618,
    DungeonTeamKicked = 619,
    EnterTowerLevel = 620,
    TowerStarRefresh = 621,
    TowerRecordHandbookRefresh = 622,
    DungeonBanSwitchTeam = 623,
    DungeonEnterTeamInfo = 624,
    RefreshPlayGuestState = 625,
    CloseMPPlayDialog = 626,
    CloseMPPlayPage = 627,
    RefreshMPPlayDialogTwiceConfirm = 628,
    MpPlayGuestReplyInviteSucc = 629,
    OnGuestPostEnterSceneNotify = 630,
    GCGMatchSucc = 631,
    GCGMatchStateUpdated = 632,
    GCGBattleInvitationStateUpdated = 633,
    CloseGCGMatchDialog = 634,
    GCGWorldPlayerStateGot = 635,
    PlayerMatchAgreedResultNotify = 636,
    MpPlayInviteResultNotify = 637,
    ScenePlayInviteResultNotify = 638,
    DraftInviteResultNotify = 639,
    DraftTwiceConfirmResultNotify = 640,
    PlayerPreEnterMp = 641,
    PlayerLevelChange = 642,
    PlayerBeyondLevelChanged = 643,
    PlayerExpChange = 644,
    PlayerWorldLevelChange = 645,
    ClosePlayerProfilePage = 646,
    PlayerWorldLevelAdjust = 647,
    ShowGuideRatingDialog = 648,
    PlayerCanDiveUpdate = 649,
    ChargeBarValueChange = 650,
    ProgressBarRefresh = 651,
    InitProgressTip = 652,
    RefreshProgressTip = 653,
    BlinkProgressTip = 654,
    DestroyProgressTip = 655,
    DailyTaskStarted = 656,
    DailyTaskProgresUpdated = 657,
    DailyTaskComplete = 658,
    DailyTaskExitRegion = 659,
    DailyTaskScoreReward = 660,
    DailyTaskAttendanceReward = 661,
    DailyTaskAttendanceUpdate = 662,
    DailyTaskRefresh = 663,
    WorldOwnerDailyTaskUpdate = 664,
    TaskVarChange = 665,
    RandTaskStarted = 666,
    RandTaskComplete = 667,
    RandTaskFail = 668,
    RandTaskExitRegion = 669,
    RoutineStarted = 670,
    RoutineProgresUpdated = 671,
    RoutineComplete = 672,
    RoutineExitRegion = 673,
    RoutineScoreReward = 674,
    RoutineRefresh = 675,
    ProudSkillUpgrade = 676,
    ProudSkillChange = 677,
    CombatSkillChange = 678,
    PlayerLevelRewardChange = 679,
    GetInvestigationMonsterFail = 680,
    GetInvestigationMonsterList = 681,
    GetInvestigationMonsterListForMark = 682,
    InvestigationChange = 683,
    InvestigationChapterComplete = 684,
    InvestigationTargetChange = 685,
    InvestigationQuestDailyNotify = 686,
    InvestigationUnlock = 687,
    InvestigationUpdate = 688,
    TrackGatherGroupRefresh = 689,
    ExplorationAllDataChange = 690,
    ExplorationCharacterDataChange = 691,
    MainPageTips = 692,
    MiracleRingItemAdded = 693,
    NewPlayerAppling = 694,
    PushTipsChange = 695,
    GetPushTipsReward = 696,
    PushTipsNotifyFinish = 697,
    NewPushTips = 698,
    PushTipsReactive = 699,
    GetTowerAllData = 700,
    GetTowerStarReward = 701,
    GetTowerSkipFloorReward = 702,
    TowerSkipFloorClose = 703,
    TowerFinishLevelSettle = 704,
    TowerFloorRecordRefresh = 705,
    VersusBattleBegin = 706,
    VersusBattleUpdate = 707,
    VersusBattleEnd = 708,
    NatlanBallVSBegin = 709,
    NatlanBallVSEnd = 710,
    ActivityOpen = 711,
    ActivityClose = 712,
    ActivityContextClose = 713,
    ActivityRefresh = 714,
    ActivityUpdate = 715,
    ActivityBannerShow = 716,
    ActivityBannerEffectShow = 717,
    ActivitySeaLampContriFinish = 718,
    ActivityStart = 719,
    ActivityCrucibleInfo = 720,
    ActivityOperationBonusUpdate = 721,
    ActivityWatcherUpdate = 722,
    ActivityDeliveryRewardUpdate = 723,
    ActivityDeliveryUpdate = 724,
    ActivityWatcherFinish = 725,
    ActivityAsterScoreUpdate = 726,
    ActivitySaleUpdate = 727,
    ActivityEchoShellUpdate = 728,
    ActivityCoinInfoNotify = 729,
    ActivityBlitzRushContentClose = 730,
    ActivityCondUpdate = 731,
    ActivityScrollSwitch = 732,
    ActivityClientPlayStartRsp = 733,
    ActivityClientPlayFinishRsp = 734,
    ActivityClientPlayStartRspSucc = 735,
    ActivityClientPlayFinishRspSucc = 736,
    ActivityPushTipsUpdate = 737,
    ActivityDebugClose = 738,
    ActivityTakeBatchWatcherReward = 739,
    ActivityPotionStageReset = 740,
    RefreshRadarHintEffect = 741,
    CloseActivityMainPage = 742,
    EffigyChallengeResultNotify = 743,
    MistTrialTimeOutNotify = 744,
    BannerReminderAppeared = 745,
    BannerReminderDisappeared = 746,
    BannerReminderForceClosed = 747,
    BannerReminderForceInterrupt = 748,
    BannerReminderAppeareForComponent = 749,
    SpecialBannerReminderAppeared = 750,
    SpecialBannerReminderDisappeared = 751,
    CommonSpecialReminderAppeared = 752,
    CommonSpecialReminderDisappeared = 753,
    InstituteHomeReminderAppeared = 754,
    InstituteHomeReminderDisappeared = 755,
    InLevelQuestHintReminderAppeared = 756,
    InLevelQuestHintReminderDisappeared = 757,
    ChallengeBannerStartAppeared = 758,
    ChallengeBannerDisappeared = 759,
    DialogueWithPortraitReminderAppeared = 760,
    DialogueWithPortraitReminderDisappeared = 761,
    CombatChatAppeared = 762,
    CombatChatDisappeared = 763,
    CombatChatFinish = 764,
    CombatChatDialogAppeared = 765,
    CombatChatDialogDisappeared = 766,
    TalkPanelReminderAppeared = 767,
    TalkPanelReminderDisappeared = 768,
    OnGetGameplayRecommendationNotify = 769,
    CloseRecommendationNotify = 770,
    OnGetGameplayRecommendationFailedNotify = 771,
    CameraLookBegin = 772,
    CameraLookBeginWithFadeAfterTime = 773,
    CameraLookEnd = 774,
    CameraLock = 775,
    CameraFieldLook = 776,
    OnCameraDiveStateSpawn = 777,
    DisableMainPageControl = 778,
    DisableMainPageControlWithConfigName = 779,
    DisableMainPageControlRollerCoasterSpecialCamera = 780,
    DisableMainPageChat = 781,
    TerminateMainPageTeamCountDown = 782,
    HideSpecificUIShowPaimon = 783,
    ResinChanged = 784,
    ResinPurchased = 785,
    BlossomBriefInfoNotify = 786,
    BlossomStart = 787,
    BlossomUpdate = 788,
    BlossomEnd = 789,
    BlossomFinish = 790,
    ShowDamageTextComponent = 791,
    SinInRefresh = 792,
    OnSignInInfoRsp = 793,
    BonusActivityRewardRsp = 794,
    ShowActivityMainBtn = 795,
    OnBonusActivityInfoRsp = 796,
    OnOpActivityStateRsp = 797,
    OnOpActivityStateNotify = 798,
    TrialActivityRewardUpdate = 799,
    SalesManTakeRewardRsp = 800,
    SalesmanDeliverItemRsp = 801,
    GetAuthSalesmanInfoRsp = 802,
    OnVirtualDialHandleCloseWheelMenuAction = 803,
    OnVirtualDialAction = 804,
    OnVirtualDialEntryAction = 805,
    CloseVirtualDial = 806,
    OpenBeyondVirtualDial = 807,
    OnTransmitStart = 808,
    OnTransmitEnd = 809,
    OnTransmitAfterAudioEvent = 810,
    BundleDownloadStart = 811,
    BundleDownloadRestart = 812,
    BundleDownloadStartForLogin = 813,
    BargainStart = 814,
    BargainPriceRsp = 815,
    BargainTerminate = 816,
    BargainDataRsp = 817,
    AllActivatedBargainData = 818,
    HideRoom = 819,
    ShowRoom = 820,
    DeleteFriend = 821,
    AddFriend = 822,
    RefreshFriendList = 823,
    RefreshFriendListWithAni = 824,
    RefreshFriendRequestList = 825,
    RefreshFriendRequestListWithAni = 826,
    RefreshFriendRequestListAndKeepPosition = 827,
    RefreshBlacklist = 828,
    RefreshMultiplayRecentlyListWithAni = 829,
    RefreshPSNFriendList = 830,
    RefreshPSNFriendListWithAni = 831,
    GetPlayerSocialDetail = 832,
    GetPlayerSocialDetailFail = 833,
    OnGetPlayerBriefListRsp = 834,
    GetFriendShowAvatarInfo = 835,
    GetFriendShowAvatarInfoInCD = 836,
    RefreshNickname = 837,
    RefreshRemarkname = 838,
    RefreshHeadPortrait = 839,
    RefreshNameCard = 840,
    RefreshAllNameCard = 841,
    RefreshSignature = 842,
    RefreshAvatarShowList = 843,
    RefreshNameCardShowList = 844,
    NicknameWordIllegal = 845,
    TeamNameIllegal = 846,
    SignatureIllegal = 847,
    RefreshBirthday = 848,
    AddInBlockChatList = 849,
    RemoveFromBlockChatList = 850,
    AddInBlacklist = 851,
    RemoveFromBlacklist = 852,
    ChatRoomInfoUpdate = 853,
    SetActivitySocialPublicRsp = 854,
    GetSimplePlayerBriefListFailed = 855,
    GetSimplePlayerBriefListSuccess = 856,
    RefreshMainPageChatContent = 857,
    RefreshMainPageChatContentForce = 858,
    RefreshChatEmojiCollectionList = 859,
    RefreshStrangerListFormal = 860,
    RefreshStrangerListTempRecv = 861,
    RefreshStrangerListTempRecvRemove = 862,
    RefreshStrangerListTempSend = 863,
    ClearStrangerChatInfoByMuip = 864,
    ChatChannelContentShrink = 865,
    ClearGlobalChatByMuip = 866,
    GlobalChannelChatOnLimit = 867,
    StrangerChatSysConfigSet = 868,
    BeyondPlayerDetailOnlineInfoStrangerOnRsp = 869,
    ChatChannelBanStateUpdate = 870,
    ChatChannelHideStateUpdate = 871,
    ChatTryMentionUid = 872,
    ChatMentionInfoUpdate = 873,
    ChatUGCChannelUpdate = 874,
    ChatSpecialInfoStatesChange = 875,
    OnChatDialogOpen = 876,
    OpenMainPageChatDialog = 877,
    VoiceChannelWillUpdate = 878,
    VoiceChannelUpdated = 879,
    BattlePassMissionChange = 880,
    BattlePassScheduleChange = 881,
    BattlePassProductPay = 882,
    BattlePassLevelChange = 883,
    BattlePassBuySuccess = 884,
    BattlePassSetRewardPlanSuccess = 885,
    BattlePassSetRewardPlanSuccessButRewardChangeForbidden = 886,
    BattlePassSetRewardPlanFailure = 887,
    BattlePassGetMissionRewardItem = 888,
    BattlePassGetMissionRewardItemFinish = 889,
    RefreshLocalNotification = 890,
    EnterSceneDone = 891,
    PSNStateChange = 892,
    PS5LaunchActivity = 893,
    MpPlayPrepareNotify = 894,
    GadgetPlayStartNotify = 895,
    GadgetPlayDataNotify = 896,
    GadgetPlayUidOpNotify = 897,
    GadgetPlayStopNotify = 898,
    GadgetChainChangeNotify = 899,
    ScenePlayBattlePrepare = 900,
    ScenePlayBattlePrestart = 901,
    ScenePlayBattleStart = 902,
    ScenePlayBattleStop = 903,
    ScenePlayBattleInterrupt = 904,
    ScenePlayUidOpNotify = 905,
    StartChargeCountDown = 906,
    InterruptChargeCountDown = 907,
    ShowTemplateReminderNotify = 908,
    StopTemplateReminderNotify = 909,
    CloseTemplateReminderDialog = 910,
    ShowPromptDownReminderNotify = 911,
    ForceDestroyPromptDownReminderNotify = 912,
    NormalUidOpNotify = 913,
    OnDispatchConfigSet = 914,
    ShowDistanceTarget = 915,
    ShowDistanceTargetV2 = 916,
    CloseDistanceTarget = 917,
    ClimateMeterType = 918,
    ClimateMeterValue = 919,
    ClimateAreaType = 920,
    ClimateAreaID = 921,
    ClimateMeterValueChanged = 922,
    ClimateMeterTypeChanged = 923,
    ClimateAreaTypeChanged = 924,
    ClimateMeterWarning = 925,
    ClimateMeterRefresh = 926,
    ShowClimateInfoDialog = 927,
    ShowSpecifiedClimateInfoDialog = 928,
    DungeonFactorDialogOpen = 929,
    DungeonFactorDialogClose = 930,
    ShowRestrictionEffect = 931,
    ShowMonthlyCardReward = 932,
    AchievementPageRefresh = 933,
    AchievementItemAdded = 934,
    AvatarFilterSetActiveCond = 935,
    AvatarFilterSetExpanded = 936,
    AvatarFilterVisionStateChanged = 937,
    AvatarFilterCloseFilterDialog = 938,
    BeyondPlayerFilterSetExpanded = 939,
    GeneralFilterSetActiveCond = 940,
    GeneralFilterSetExpanded = 941,
    GeneralFilterVisionStateChanged = 942,
    GeneralFilterCloseFilterDialog = 943,
    RefreshAvatarLinePage = 944,
    OnPersonalLineAllDataRsp = 945,
    AvatarLineGetKey = 946,
    AvatarLineUnlock = 947,
    AvatarLineAccept = 948,
    ShareComplete = 949,
    SDKPayStart = 950,
    SDKPayEnd = 951,
    SDKGetProductList = 952,
    AvatarAddNotify = 953,
    TrialAvatarDelete = 954,
    OnTakeReputationLevelReward = 955,
    RefreshReputation = 956,
    OnCityReputationLevelup = 957,
    RefreshHunting = 958,
    HuntingStart = 959,
    HuntingRevealClue = 960,
    HuntingRevealFinal = 961,
    HuntingSuccess = 962,
    HuntingFail = 963,
    CloseReputationHuntingDialog = 964,
    CloseReputationRequestDialog = 965,
    HuntingTaken = 966,
    HuntingFinished = 967,
    CityReputationDonationInfoUpdate = 968,
    CityReputationDonationInfoRsp = 969,
    CityReputationDonationRewardTaken = 970,
    TribalReputationInfoUpdate = 971,
    TribalExpAdd = 972,
    CityReputationTotalRewardInfoUpdate = 973,
    HuntingV2OfferUpdate = 974,
    HuntingV2Start = 975,
    HuntingV2Success = 976,
    HuntingV2Fail = 977,
    FlowerLandReputationInfoUpdate = 978,
    OfferingDataUpdated = 979,
    TakeOfferingLevelReward = 980,
    OfferingLevelChange = 981,
    OfferingLevelChangeReward = 982,
    ForbiddenToggleMoveStateChange = 983,
    OnToggleMoveSettingChange = 984,
    KeyboardLayoutUpdate = 985,
    ControllerMapModified = 986,
    OnControllerConnected = 987,
    OnDeviceTypeSet = 988,
    SetDeviceTypeInSettingPage = 989,
    OnJoypadIconDisplayTypeChange = 990,
    OnInputHotSwap = 991,
    InputDeviceChanged = 992,
    OnControllerDisConnected = 993,
    WidgetActionBtnRefresh = 994,
    WidgetEquipChange = 995,
    WidgetCollectorWindSeed = 996,
    WidgetQuickUseButtonRelease = 997,
    JoypadTriggerWidgetQuickUseButton = 998,
    WidgetQuickUseRsp = 999,
    ForcePlayBattleBtnCdEndEffect = 1000,
    WidgetWeatherWizardValueUpdate = 1001,
    WidgetQuickSwitchListChange = 1002,
    WidgetSwitchDialogOpen = 1003,
    WidgetWispCageUpdate = 1004,
    WidgetWispCageDiscard = 1005,
    WidgetWispCageItemAdded = 1006,
    WidgetBackGroundStateChanged = 1007,
    WidgetByIsGadgetExistNotify = 1008,
    WidgetSlotChange = 1009,
    FlightChallengeBegin = 1010,
    FlightChallengeFinish = 1011,
    ReportSuccNotify = 1012,
    PlayerQuitFromMpByHostBlock = 1013,
    PlayerQuitFromMpByGuestBlock = 1014,
    PlayerQuitFromMpByHostAdsBlock = 1015,
    PlayerQuitFromMpByGuestAdsBlock = 1016,
    ActivityBlessingDataRefresh = 1017,
    ActivityBlessingScanSuccess = 1018,
    ActivityBlessingScanFail = 1019,
    ActivityBlessingRefresh = 1020,
    ActivityGiveFriendPicSuccess = 1021,
    TreasureHuntCurrencyNumChange = 1022,
    ReunionAddToOpActivityListNotify = 1023,
    ReunionRemoveFromOpActivityListNotify = 1024,
    ReunionOpenNotify = 1025,
    ReunionCloseNotify = 1026,
    ReunionGetFirstRewardSuccNotify = 1027,
    ReunionSignInGetRewardNotify = 1028,
    ReunionTaskClaimFinalRewardSuccNotify = 1029,
    ReunionTaskClaimWatcherRewardSuccNotify = 1030,
    ReunionShowBannerNotify = 1031,
    ReunionRecommendAvatarUpdateNotify = 1032,
    ReunionRecommendRegionUpdateNotify = 1033,
    ReunionRecommendQuestUpdateNotify = 1034,
    ReunionSignInInfoUpdateNotify = 1035,
    ReunionPrivilegeInfoUpdateNotify = 1036,
    ReunionMissionUpdateNotify = 1037,
    ReunionMainPageEffectShowNotify = 1038,
    ReunionVideoUpdateNotify = 1039,
    AvatarExpeditionStartNtf = 1040,
    ShowLendHistoryNotify = 1041,
    ExpeditionActivityStartNotify = 1042,
    ExpeditionActivityRecallNotify = 1043,
    ExpeditionActivityRewardClaimedNotify = 1044,
    ExpeditionActivityInfoUpdateNotify = 1045,
    OpenExpeditionMap = 1046,
    OnExpeditionChallengeEnterRegion = 1047,
    OnExpeditionChallengeFinish = 1048,
    GetExpeditionRewardNotify = 1049,
    GadgetGroupButtonAddNotify = 1050,
    GadgetGroupButtonRemoveNotify = 1051,
    NetworkVoiceSendVolumeChanged = 1052,
    NetworkVoiceReceiveVolumeChanged = 1053,
    NetworkVoiceBlockDataUpdated = 1054,
    NetworkVoiceUsingMobileMicChanged = 1055,
    ActivityUpdateRegion = 1056,
    WalkModeChanged = 1057,
    FireUIEffectNotify = 1058,
    AttachUIEffectNotify = 1059,
    UntachUIEffectNotify = 1060,
    FireUIMultiCombatBarEffectNotify = 1061,
    AttachUIMultiCombatBarEffectNotify = 1062,
    DetachUIMultiCombatBarEffectNotify = 1063,
    SendUIEffectAnimatorNotify = 1064,
    PlayerApplyEnterMpResult = 1065,
    PlayerQuitFromMp = 1066,
    PlayerVehilceUpdate = 1067,
    UpdateFriendsWishNotify = 1068,
    UpdateRecvGiftsNotify = 1069,
    UpdateGiftRecvInfoNotify = 1070,
    UpdateGiveGiftDialog = 1071,
    HaveRecvGiftNotify = 1072,
    OnActivitySetGiftWishRsp = 1073,
    GachaActivityPercentNotify = 1074,
    GachaActivityCreateRobotRsp = 1075,
    GachaActivityResetRsp = 1076,
    GachaActivityTakeRewardRsp = 1077,
    GachaActivityNextStageRsp = 1078,
    GetMechanicusInfoRsp = 1079,
    UpdateGearItem = 1080,
    UnLockGearItem = 1081,
    FoundationOpLockFailed = 1082,
    MechanicusCoinNotify = 1083,
    FoundationUpdateNotify = 1084,
    OnInBattleMechanicusStageKillStartNotify = 1085,
    OnInBattleMechanicusStageKillEndNotify = 1086,
    OnInBattleMechanicusStageCardFlipEndNotify = 1087,
    OnInBattleMechanicusStart = 1088,
    OnInBattleMechanicusUpdate = 1089,
    OnInBattleMechanicusFinish = 1090,
    OnInBattleMechanicusPickCardRsp = 1091,
    OnInBattleMechanicusPickCardNotify = 1092,
    OnInBattleMechanicusConfirmCardRsp = 1093,
    OnInBattleMechanicusConfirmCardNotify = 1094,
    OnInBattleMechanicusCardResultNotify = 1095,
    OnInBattleChessPickCardNotify = 1096,
    OnInBattleChessCandidateCardsNotify = 1097,
    FleurFairDungeonPreview = 1098,
    FleurFairDungeonPrepare = 1099,
    FleurFairDungeonGallery = 1100,
    FleurFairDungeonBoss = 1101,
    FleurFairDungeonGallerySettle = 1102,
    FleurFairDungeonBossSettle = 1103,
    FleurFairDungeonEnergy = 1104,
    FleurFairDungeonGalleryUpdate = 1105,
    SummerTimeStage4JoypadFocusChange = 1106,
    SummerTimeSprintBoatRedpointChange = 1107,
    GalleryDialogShow = 1108,
    GalleryPreStart = 1109,
    GalleryStart = 1110,
    GalleryStop = 1111,
    GalleryUpdateAll = 1112,
    GalleryPreStartEndTimeChange = 1113,
    GalleryModuleComponentInit = 1114,
    GalleryModuleComponentDestroy = 1115,
    GalleryModuleComponentPreStart = 1116,
    GalleryModuleComponentStart = 1117,
    GalleryModuleComponentRecover = 1118,
    GalleryModuleComponentStop = 1119,
    CheckGalleryPlay = 1120,
    GalleryDialogOnRefresh = 1121,
    GalleryBalloonShoot = 1122,
    GalleryBalloonScore = 1123,
    GalleryFallCatch = 1124,
    GalleryFallScore = 1125,
    GalleryMusicGameClose = 1126,
    GallerySettleRestart = 1127,
    GalleryPreInitCountDownStart = 1128,
    GalleryPreInitCountDownEnd = 1129,
    RefreshAvatarPanel = 1130,
    CheckUIOpenState = 1131,
    GalleryPhotoStop = 1132,
    GalleryForceHideSideAlpha = 1133,
    SlabCheckEnterLoopDungeon = 1134,
    SlabEquipBuffChange = 1135,
    GallerySumoStageStart = 1136,
    GallerySumoStageFinish = 1137,
    GallerySumoChangeTeam = 1138,
    GallerySumoChangeTeamCdUpdate = 1139,
    GallerySumoChangeTeamUpdateScore = 1140,
    StartCrystalLinkGalleryNotify = 1141,
    UpdateCrystalLinkGalleryNotify = 1142,
    StopCrystalLinkGalleryNotify = 1143,
    CrystalLinkBuffUpdate = 1144,
    CrystalLinkBuffEffect = 1145,
    CrystalLinkBuffActiveNotify = 1146,
    QuickSwitchTeamFetchNextTeamInfo = 1147,
    QuickSwitchTeamReqToChangeTeam = 1148,
    ArenaChallengeStart = 1149,
    ArenaChallengeTakeWatcherReward = 1150,
    ActivityMistTrialTakeReward = 1151,
    ActivityMistTrialExhibitionRefresh = 1152,
    ActivityMistTrialGalleryCountDown = 1153,
    ActivityMiniTomoClose = 1154,
    HomeWorldCompInfoUpdate = 1155,
    HomeWorldModuleChange = 1156,
    HomeWorldModuleChoose = 1157,
    HomeWorldModuleSeenUpdate = 1158,
    HomeWorldModulePrepareGoIn = 1159,
    HomeWorldFurnitureMakeInfoRefresh = 1160,
    HomeWorldFurnitureMakeGetResult = 1161,
    HomeWorldFurnitureMakeCancel = 1162,
    HomeWorldFurnitureFormulaUnlock = 1163,
    HomeWorldLevelUp = 1164,
    HomeWorldSuiteDetailShow = 1165,
    GetHomeworldVisitor = 1166,
    HomeKickPlayerRspSuccess = 1167,
    HomeWorldComfortInfoUpdate = 1168,
    ClearDeployGadgetData = 1169,
    HomeWorldChangeBGM = 1170,
    HomeWorldUnlockBGM = 1171,
    HomeWorldBlueprintSearchInfoUpdate = 1172,
    HomeWorldNpcSpawnForAllEnvironment = 1173,
    HomeWorldNpcRemoveForAllEnvironment = 1174,
    ReplyApplyingGuest = 1175,
    MpInvitationListShow = 1176,
    HideAndSeekStagePrepare = 1177,
    HideAndSeekStagePick = 1178,
    HideAndSeekStageHide = 1179,
    HideAndSeekStageSeek = 1180,
    HideAndSeekPlayerSetAvatarNotify = 1181,
    HideAndSeekSelectSkillRsp = 1182,
    HideAndSeekPlayerReadyNotify = 1183,
    HideAndSeekStageSettle = 1184,
    HideAndSeekCaught = 1185,
    HideAndSeekBecomeGhost = 1186,
    HideAndSeekPlayerChosenMapUpdate = 1187,
    HideAndSeekV4GalleryDataUpdate = 1188,
    HideAndSeekV4Caught = 1189,
    HideAndSeekV4BecomeGhost = 1190,
    HideAndSeekV4PlayerSetAvatarNotify = 1191,
    HideAndSeekV4SelectSkillRsp = 1192,
    HideAndSeekV4PlayerReadyNotify = 1193,
    HideAndSeekV4MultistagePlayInfoUpdate = 1194,
    HideAndSeekV4PlayerChosenMapUpdate = 1195,
    HideAndSeekV4Settle = 1196,
    AvatarChargeSkillNotify = 1197,
    LoginSceneNotify = 1198,
    CharacterPageNotify = 1199,
    CloseCharacterPageNotify = 1200,
    WeaponPageNotify = 1201,
    CloseWeaponPageNotify = 1202,
    LoadingBeginNotify = 1203,
    LoadingEndNotify = 1204,
    GachaItemNotify = 1205,
    CloseGachaNotify = 1206,
    GoToGachaPageNotify = 1207,
    GrowFlowersUpdateTodaySeedNotify = 1208,
    GrowFlowersUpdateExchangePage = 1209,
    GrowFlowersUpdateFriendsWishNotify = 1210,
    GrowFlowersUpdateRecvFlowersNotify = 1211,
    GrowFlowersUpdateRecvInfo = 1212,
    GrowFlowersUpdateGiveDialog = 1213,
    WinterCampSnowmanUpdateFriendsWishNotify = 1214,
    WinterCampSnowmanUpdateRecvItemNotify = 1215,
    WinterCampSnowmanUpdateRecvInfo = 1216,
    WinterCampSnowmanUpdateGiveDialog = 1217,
    StartBuoyantCombatGallerySuccess = 1218,
    StartBuoyantCombatGalleryNotify = 1219,
    UpdateBuoyantCombatGalleryNotify = 1220,
    StopBuoyantCombatGalleryNotify = 1221,
    StartGalleryProgressNotify = 1222,
    UpdateGalleryProgressNotify = 1223,
    StopGalleryProgressNotify = 1224,
    StartDigCombatGalleryNotify = 1225,
    UpdateDigCombatGalleryNotify = 1226,
    StopDigCombatGalleryNotify = 1227,
    SalvagePreventUpdateNotify = 1228,
    SalvageEscortUpdateNotify = 1229,
    UpdateSalvageBundleMark = 1230,
    UpdateBounceConjuringScore = 1231,
    AddBounceConjuringScore = 1232,
    LunaRiteSacrificeSuccess = 1233,
    LunaRiteRefresh = 1234,
    MoonfinTrialWatcherUpdated = 1235,
    TryShowQTEDialog = 1236,
    EnableSubtitleInputPenetrate = 1237,
    OnQTEButtonClick = 1238,
    ShowQTEReminder = 1239,
    ShowUITriggerQTE = 1240,
    ShowAbyssPurify = 1241,
    CodexKillNumRefresh = 1242,
    FishCastRod = 1243,
    FishBaitUpdate = 1244,
    FishQteStart = 1245,
    FishBattleEnd = 1246,
    ExitFishing = 1247,
    FishRippleEffectStart = 1248,
    FishRippleEffectEnd = 1249,
    OnShikigamiSkillUpgrade = 1250,
    OnRefreshRoguelikeDungeonCardRsp = 1251,
    OnTakeRoguelikeStageFirstPassReward = 1252,
    OnEnterRoguelikeDungeonNotify = 1253,
    ActivityRogueContentClose = 1254,
    CustomGadgetSubmitRsp = 1255,
    IrodoriEditFlowerSubmitRsp = 1256,
    CustomGadgetPendingDataUnexpectedlyRemoved = 1257,
    ProjectionGameGuideFinishFreeRotationXY = 1258,
    ProjectionGameGuideFinishFreeRotationZ = 1259,
    ProjectionGameGuideFinishSwitch = 1260,
    ProjectionGameAnswerUnlocked = 1261,
    FireworkMakerRefreshPage = 1262,
    FireworkReformSettlement = 1263,
    LanternRiteStartFireworksReformRsp = 1264,
    LanternRiteDoFireworksReformRsp = 1265,
    LanternRiteEndFireworksReformRsp = 1266,
    LanternRiteEndFireworksReform = 1267,
    LanternRiteFireworksReformDoOnce = 1268,
    LocalAvatarDoSkillSucc = 1269,
    BattleFervorAuthorityOnBeingHit = 1270,
    BattleFervorAttackDamageResult = 1271,
    BattleFervorKilledNotify = 1272,
    BattleFervorMaterialAdd = 1273,
    BattleFervorChestStateChanged = 1274,
    SendBuyGoodsReq = 1275,
    CustomLevelDungeonUpdate = 1276,
    CustomDungeonTryTypeChanged = 1277,
    CustomLevelSearchResult = 1278,
    CustomLevelSubscribeResult = 1279,
    CustomLevelLikeResult = 1280,
    CustomLevelSaveResult = 1281,
    UGCCandidateDataChange = 1282,
    UGCCandidateTeamProcessDataChange = 1283,
    OnUGCDungeonCandidateTeamInfoNotify = 1284,
    UGCGalleryStart = 1285,
    UGCGalleryStop = 1286,
    UGCUpdateLeftDeathCount = 1287,
    BeforeHandleUGCSettleNotify = 1288,
    UGCSocialDataUpdateByProto = 1289,
    UGCSocialDataUpdateByClient = 1290,
    ForceCloseUploadDialog = 1291,
    OnPublishUgcDungeonRsp = 1292,
    OnGetSearchResultFromProto = 1293,
    UGCAuditFailed = 1294,
    UGCV2RoomTempSideDialogContextClose = 1295,
    UGCResetRoomMapJoySelect = 1296,
    UGCAvatarSelectDialogClose = 1297,
    UGCV2LocalRoomMapChange = 1298,
    UGCV2OnEditUgcDungeonSettingNotify = 1299,
    UGCV2OnSaveUgcDungeonDataRsp = 1300,
    OnSettingItemJoyIndexChange = 1301,
    OnEditUgcDungeonNotify = 1302,
    OnSaveUgcDungeonDeploymentRsp = 1303,
    RegionalPlayEnable = 1304,
    RegionalPlayDisable = 1305,
    AbnormalClimateMixinEnable = 1306,
    AbnormalClimateMixinDisable = 1307,
    MichiaeBattleSkillUnlock = 1308,
    ShowSignalMichiae = 1309,
    LifeCountShow = 1310,
    LifeCountHide = 1311,
    LifeCountChange = 1312,
    AttachBartenderEffectNotify = 1313,
    DetachBartenderEffectNotify = 1314,
    BartenderRecipeUnlockNotify = 1315,
    HomeBalloonShootStartNotify = 1316,
    HomeBalloonShootScoreUpdateNotify = 1317,
    HomeBalloonShootEndNotify = 1318,
    SpiceActivityProcessFoodRsp = 1319,
    SpiceActivityFinishMakeSpiceRsp = 1320,
    IrodoriAcitvityInfoUpdate = 1321,
    IrodoriAcitvityWatcherInfoUpdate = 1322,
    FillPoetry = 1323,
    ScanPoetryEntity = 1324,
    MasterGalleryStart = 1325,
    MasterGallerySettle = 1326,
    IrodoriChessEquipCardUpdate = 1327,
    WidgetToyOnPhotographRelease = 1328,
    WidgetToyStartTakingPhoto = 1329,
    WidgetToyContinousTakingPhoto = 1330,
    OnPhotoSettleNotify = 1331,
    OnGalleryPhotoStart = 1332,
    OnGalleryPhotoEnd = 1333,
    ActivityPhotoConfirmCameraSetting = 1334,
    PostActivityPhotoConfirmCameraSetting = 1335,
    OnPhotoActivityFinishRsp = 1336,
    BeforeShowActivityPhotoAdjustCameraPage = 1337,
    GetQuestLackingResourceRsp = 1338,
    ArrangeSaveFoundNotify = 1339,
    ArrangeSaveNotFoundNotify = 1340,
    UGCLimitedNotify = 1341,
    UGCLockedNotify = 1342,
    UGCStateUpdateNotify = 1343,
    CheckHistorySavesUpdateNotify = 1344,
    MusicGameRewardUnlockNotify = 1345,
    MusicGameRefreshUgcArchivesNotify = 1346,
    MusicGameImportOfficialLevelNotify = 1347,
    MusicGameImportUgcLevelNotify = 1348,
    MusicGameImportUgcLevelNewEditorNotify = 1349,
    MusicGameCompareUgcLevelNotify = 1350,
    MusicGameTrialUgcLevelNotify = 1351,
    MusicGamePlayUgcLevelNotify = 1352,
    MusicGameSettleNotify = 1353,
    MusicGameEndNotify = 1354,
    MusicGameRestartNotify = 1355,
    MusicGameSaveUgcNotify = 1356,
    MusicGameAutoSaveUgcNotify = 1357,
    GetRecommendUgcInfoRsp = 1358,
    GetRecommendUgcInfoFailed = 1359,
    GetSearchUgcInfoRsp = 1360,
    GetStoreUgcInfoRsp = 1361,
    GetUgcRecordBriefInfoRsp = 1362,
    MusicGameRecordListRefresh = 1363,
    OnSetUgcMusicOptionRsp = 1364,
    StoreUgcRsp = 1365,
    SaveUgcRecommendParamRsp = 1366,
    RogueDiaryCardReroll = 1367,
    RogueDiaryStartDungeon = 1368,
    RogueDiaryResetDungeon = 1369,
    RogueDiaryCardSelected = 1370,
    RogueDiaryAvatarRevive = 1371,
    RogueDiaryFinishBanPick = 1372,
    ActivityQuickOpen = 1373,
    ActivitySpecialItem = 1374,
    ChasmChallengeGalleryInfoUpdateNotify = 1375,
    HomeSeekGalleryInfoUpdateNotify = 1376,
    IslandMoutainSelectRsp = 1377,
    IslandPartyAcitvityWatcherInfoUpdate = 1378,
    IslandPartyRaftReminderRefresh = 1379,
    IslandPartyRaftGalleryInfoUpdate = 1380,
    IslandPartySailGalleryInfoUpdate = 1381,
    IslandPartyDownHillGalleryInfoUpdate = 1382,
    ActivityJigsawGameSuccess = 1383,
    ActivityGearGameSuccess = 1384,
    ActivityGearAutoPlaceUpperLayer = 1385,
    ActivityGearAutoFlip = 1386,
    PlotInferenceFinishTalk = 1387,
    PlotInferenceUpdate = 1388,
    PlotInferenceRemove = 1389,
    TeamManaged = 1390,
    BackupTeamDeleted = 1391,
    UpdateShownTeamId = 1392,
    TeamMoved = 1393,
    DeathZoneActiveChange = 1394,
    MuqadasPotionGalleryInfoUpdate = 1395,
    InstableSprayTeamRefresh = 1396,
    InstableSprayGalleryInfoUpdate = 1397,
    InstableSpraySwitchTeamRspFail = 1398,
    HomeWoodExchangeInfoRefresh = 1399,
    HomeWoodExchangeUpdate = 1400,
    HomeWoodSelectedMaterialExchange = 1401,
    HomeWoodSelectedMaterialDialogClsoe = 1402,
    WindFieldActivityWatcherInfoUpdate = 1403,
    WindFieldGalleryInfoUpdate = 1404,
    WindFieldChallengeInfoUpdate = 1405,
    VintageHuntingGalleryStart = 1406,
    VintageHuntingGalleryStop = 1407,
    VintageHuntingGalleryUpdate = 1408,
    OnVintageMarketStrategySlotUnlockRsp = 1409,
    OnVintageMarketStoreChooseStrategyRsp = 1410,
    OnVintageMarketStoreViewStrategyRsp = 1411,
    OnVintageMarketDividendFinishNotify = 1412,
    OnVintageMarketNpcEventFinishNotify = 1413,
    OnVintageStoreAttrTooSmall = 1414,
    OnVintageMarketFinishStorePlayRsp = 1415,
    SwitchSkillIcon = 1416,
    CalalogWatcherUpdated = 1417,
    GCGClientSettle = 1418,
    GcgGuideTaskStateCancel = 1419,
    GcgHistoryMsgUpdated = 1420,
    GcgSettle = 1421,
    RefreshGcgDeckName = 1422,
    GcgRefreshDeck = 1423,
    GcgDeckSaved = 1424,
    GcgCurrentDeckChanged = 1425,
    GcgRefreshCardDetail = 1426,
    GcgCardNumChanged = 1427,
    GcgFilterDataConfirm = 1428,
    GcgFilterDialogVisionStateChanged = 1429,
    GcgFilterDialogShow = 1430,
    GcgFilterDialogUpdate = 1431,
    RefreshGcgDeckAppearance = 1432,
    GcgPlayerDataReady = 1433,
    GcgPlayerDataUpdate = 1434,
    GcgPlayerLevelInfoUpdate = 1435,
    GcgHandbookWeeklyChallengeInfoUpdate = 1436,
    GCGWeekChallengeNotifyNpcChange = 1437,
    GcgCardProficiencyUpdate = 1438,
    GcgCardProficiencyRewardTaken = 1439,
    GcgCardProficiencyRewardItemAdded = 1440,
    GcgBannedCardListUpdate = 1441,
    GcgBannedCardListUpdateRefresh = 1442,
    GcgCardFaceUnlock = 1443,
    GcgGetReplayList = 1444,
    GcgReplaySetFavorite = 1445,
    GcgReplayBecameInvalid = 1446,
    GcgReplayStart = 1447,
    GcgClientBannedCardsUpdate = 1448,
    GcgPickDataReady = 1449,
    GcgPickDataUpdated = 1450,
    GcgPickFinished = 1451,
    GcgPickInterrupted = 1452,
    GcgPickRoundDataUpdated = 1453,
    GcgPickCurPrePicksUpdated = 1454,
    GcgTavernTransport = 1455,
    GcgShareCodeSuccessfully = 1456,
    GcgShareCodeFailed = 1457,
    GcgImportDeck = 1458,
    GcgShareCodePreCheck = 1459,
    GcgServerSettingUpdate = 1460,
    FungusFighterCaptureGalleryStart = 1461,
    FungusFighterCaptureGalleryInfoUpdate = 1462,
    FungusFighterCaptureGallerySettle = 1463,
    FungusFighterCaptureGalleryStop = 1464,
    FungusFighterTrainingGalleryStart = 1465,
    FungusFighterTrainingGalleryInfoUpdate = 1466,
    FungusFighterTrainingGallerySettle = 1467,
    FungusFighterTrainingGalleryStop = 1468,
    FungusFighterTrainingOrganizeSuccess = 1469,
    FungusFighterTrainingBackupSuccess = 1470,
    FungusFighterTrainingClearSuccess = 1471,
    FungusFighterPartnerUseSkillSuccess = 1472,
    CharAmusementStagePreview = 1473,
    CharAmusementStagePrepare = 1474,
    CharAmusementStageGallery = 1475,
    CharAmusementGalleryInfoUpdate = 1476,
    FungusFighterLevelUp = 1477,
    FungusFighterLevelError = 1478,
    FungusRenameSuccess = 1479,
    FungusRenameFailed = 1480,
    EffigyV2GalleryInfoUpdate = 1481,
    HomeworldBlueprintSlotInfoUpdate = 1482,
    HomeworldBlueprintFriendCopyOption = 1483,
    HomeworldBlueprintSlotOptionUpdate = 1484,
    HomeworldBlueprintCreateInfo = 1485,
    HomeworldBlueprintDeleInfo = 1486,
    HomeworldBlueprintSaveFromShare = 1487,
    HomeworldBlueprintSetCreatButtonTimer = 1488,
    HomeworldPreviewBlockChange = 1489,
    HomeworldCrossModulePreview = 1490,
    HomeworldEnterPreviewModeSuccess = 1491,
    HomeworldResumeBlueprintHandBook = 1492,
    HomeworldSceneFishpondFarmSuccess = 1493,
    BrickBreakerStagePrepare = 1494,
    BrickBreakerStagePick = 1495,
    BrickBreakerStageGame = 1496,
    BrickBreakerPlayerSetAvatarNotify = 1497,
    BrickBreakerSelectSkillRsp = 1498,
    BrickBreakerPlayerSetSkillNotify = 1499,
    BrickBreakerPlayerReadyNotify = 1500,
    BrickBreakerStageSettle = 1501,
    BrickBreakerPlayerChangingNotify = 1502,
    OnSingleStartBrickBreakerRsp = 1503,
    OnInBattleBrickBreakerStart = 1504,
    OnInBattleBrickBreakerUpdate = 1505,
    OnInBattleBrickBreakerFinish = 1506,
    OnInBattleBrickBreakerShowBanner = 1507,
    BrickBreakerLevelChecked = 1508,
    OnInBattleBrickBreakerChallengeStart = 1509,
    OnInBattleBrickBreakerChallengeSuccess = 1510,
    OnInBattleBrickBreakerChallengeFail = 1511,
    BrickBreakerWatcherInfoUpdate = 1512,
    OnGalleryElectroHercluesBattleStart = 1513,
    OnGalleryElectroHercluesBattleStop = 1514,
    HerculesBattleStopGuideTask = 1515,
    HerculesBattlePreAccumulateNodeFinish = 1516,
    ElectroherculesBattleSelectDifficultyRsp = 1517,
    BeforeSendElectroherculesBattleGalleryFinishReq = 1518,
    CoinCollectSkillSelectFailed = 1519,
    CoinCollectSkillSelectSucceed = 1520,
    CoinCollectInviteCheckFailed = 1521,
    CoinCollectInviteCheckSucceed = 1522,
    CoinCollectGalleryInfoUpdate = 1523,
    CoinCollectGalleryReady = 1524,
    CoinCollectMultistagePrepare = 1525,
    CoinCollectMultistageCutScene = 1526,
    CoinCollectMultistageGallery = 1527,
    CoinCollectMultistageEnd = 1528,
    CoinCollectMultistagePlayerInfoUpdate = 1529,
    LanV3ConditionUpdate = 1530,
    LanV3BoatGameStagePrepare = 1531,
    LanV3BoatGameStagePlay = 1532,
    LanV3BoatGameStageSettle = 1533,
    LanV3BoatGameMultistagePlayEnd = 1534,
    LanV3BoatGameTransferFinish = 1535,
    LanV3BoatGameGalleryMultiInfoUpdate = 1536,
    LanV3BoatGameSingleStart = 1537,
    ShadowGameBlockSwap = 1538,
    ShadowGameSettle = 1539,
    ShadowGameSuccess = 1540,
    ShadowGameFail = 1541,
    ShadowGameQuit = 1542,
    ShadowGameRestart = 1543,
    ShadowGameNextLevel = 1544,
    ShadowGameFinishLevel = 1545,
    StartTeamChainGalleryNotify = 1546,
    UpdateTeamChainGalleryNotify = 1547,
    StopTeamChainGalleryNotify = 1548,
    DuelHeartSelectDifficultySucc = 1549,
    UpdateDuelHeartDifficulty = 1550,
    DuelHeartCreateCountDown = 1551,
    DuelHeartClearCountDown = 1552,
    SorushGoOutLimit = 1553,
    SorushBackLimit = 1554,
    PacmanActivityWatcherInfoUpdate = 1555,
    PacmanGalleryInfoUpdate = 1556,
    PacmanDungeonSettle = 1557,
    PacmanGameStagePrepare = 1558,
    PacmanGameStageGallery = 1559,
    PacmanGameStageSettle = 1560,
    FungusV2PartnerSpawn = 1561,
    FungusV2PartnerDie = 1562,
    FungusV2EnemySpawn = 1563,
    FungusV2EnemyDie = 1564,
    OnServerRedpointUpdated = 1565,
    AkaFesRhythmClick = 1566,
    AkaFesRhythmLongPress = 1567,
    AkaFesRhythmRoundEnd = 1568,
    AkaFesRhythmLevelEnd = 1569,
    AkaFesRhythmSuccess = 1570,
    AkaFesRhythmFail = 1571,
    AkaFesRhythmMiss = 1572,
    AkaFesRhythmFinishPlay = 1573,
    AkaFesRhythmStartPlay = 1574,
    AkaFesRhythmPause = 1575,
    AkaFesRhythmShakeCamera = 1576,
    AkaFesAstrolabeReturnToSelectLevel = 1577,
    AkaFesAstrolabeEnterNextLevel = 1578,
    AkaFesAstrolabeSelectLevelStart = 1579,
    AkaFesAstrolabeSelectLevelFinish = 1580,
    AkaFesAstrolabeChangeGearBtnState = 1581,
    AkaFesArchitectSaveComplete = 1582,
    AkaFesArchaeologyReminderRefresh = 1583,
    SandWormCannonGalleryStart = 1584,
    SandWormCannonGalleryFinish = 1585,
    SandWormCannonChargeProgressUpdate = 1586,
    SandWormCannonExitChallenge = 1587,
    CustomGalleryUpdateAll = 1588,
    CustomGalleryUpdateSingleProgress = 1589,
    CustomGalleryRemoveAllProgress = 1590,
    LanguageChange = 1591,
    GalleryCountDownEndTimeChange = 1592,
    PauseGalleryCountDown = 1593,
    SorushTrialGalleryStart = 1594,
    SorushTrialGalleryStop = 1595,
    SorushTrialOnPhotomatchSettle = 1596,
    UGCV2ShopItemRefresh = 1597,
    UGCV2TeamInfoRefresh = 1598,
    UGCV2TeamLevelUp = 1599,
    UGCV2ItemAdd = 1600,
    UGCV2TowerBuildSuccess = 1601,
    UGCV2ShopBounghtSuccess = 1602,
    UGCV2TowerLevelUp = 1603,
    UGCV2TowerDisMantle = 1604,
    UGCV2RunTimePackRefresh = 1605,
    UGCV2DungeonFeatureSwitch = 1606,
    UGCV2PostDungeonFeatureSwitch = 1607,
    EffigyV4AvatarPrepare = 1608,
    EffigyV4CancelPrepare = 1609,
    EffigyV4InDungeonChangeAvatarFinish = 1610,
    PenumbraSwitch = 1611,
    PenumbraStop = 1612,
    PenumbraRefreshInteract = 1613,
    PenumbraShowGiveDialog = 1614,
    PenumbraReminderAppeared = 1615,
    PenumbraReminderDisappeared = 1616,
    PenumbraDisableInput = 1617,
    PenumbraItemAdded = 1618,
    GCGArenaScheduleChange = 1619,
    GCGArenaScheduleDataUpdate = 1620,
    GCGArenaChallengeStart = 1621,
    GCGArenaChallengeCancel = 1622,
    JourneyDiceDungeonGalleryInfoUpdate = 1623,
    JourneyDiceDungeonUseBuff = 1624,
    MuqadasPotionTrailAvatarChanged = 1625,
    CommonMultiStageStateChange = 1626,
    CommonMultiStageEnd = 1627,
    PenAdvTargetShootingTransferFinish = 1628,
    PenAdvTargetShootingDialogShow = 1629,
    PenAdvTargetShootingGalleryRecover = 1630,
    PenAdvTargetShootingGalleryUpdate = 1631,
    ShuffleBoardRoundBeg = 1632,
    ShuffleBoardRoundEnd = 1633,
    ShuffleBoardRoundFail = 1634,
    ShuffleBoardRoundSucc = 1635,
    ShuffleBoardRoundsEnd = 1636,
    MultiCharacterFightStartFailed = 1637,
    MultiCharacterFightStartSucc = 1638,
    MultiCharacterFightFinishLoad = 1639,
    OnActivityGetMonsterIdListRsp = 1640,
    EnterCanDiveArea = 1641,
    LeaveCanDiveArea = 1642,
    MultiLayerGroupPlayerEnter = 1643,
    MultiLayerGroupRebuild = 1644,
    MultiLayerMapShowFloorChange = 1645,
    MultiLayerUnloadAll = 1646,
    PlayDialogCompPostDialogPlay = 1647,
    PlayDialogCompPostDialogFinish = 1648,
    PlayDialogCompPostNextDialogPlay = 1649,
    QuestEventClientDataChange = 1650,
    OnSubmitQuestEventsGivingRsp = 1651,
    BeforeRequestNPCInteractionByInput = 1652,
    PostStartQuestDiscover = 1653,
    QuestInferenceLocalServerDataChange = 1654,
    QuestInferenceSettle = 1655,
    SetCorrectClueToPreFillAndClearListFinish = 1656,
    QuestRefuteLocalServerDataChange = 1657,
    OnRefuteResult = 1658,
    QuestRefuteResumeDialog = 1659,
    NotifyQuestPlayDialogRefresh = 1660,
    QuestRefuteTriggerRouletteBulletAnim = 1661,
    QuestEventIconForceHideStateChange = 1662,
    RemoveQuestEventIndicator = 1663,
    AddQuestEventIndicator = 1664,
    RequestUnlockQuestEventsItemSuccess = 1665,
    QuestRefuteAutoQuitDialog = 1666,
    IgnoreAutoFinishCurrTalkOnLandFromBackOnce = 1667,
    TalkOpenPage = 1668,
    ToyBattleGameStart = 1669,
    ToyBattleGameFinish = 1670,
    ToyBattleGamePause = 1671,
    ToyBattleGameResumeWithCountDown = 1672,
    ToyBattleGameRestartWithCountDown = 1673,
    ReloadToyBattleGameData = 1674,
    ToyBattleGadgetWaitListChange = 1675,
    ToyBattleComboAdd = 1676,
    ToyBattleComboReset = 1677,
    ToyBattleScoreAdd = 1678,
    ToyBattleCountDown = 1679,
    ToyBattleUIRefresh = 1680,
    ToyBattleChangeToNormal = 1681,
    ToyBattleDestoryInViewNotes = 1682,
    RefreshAllHeadPortrait = 1683,
    RefreshHeadPortraitRP = 1684,
    FishBlasterAddScore = 1685,
    FishBlasterAddBall = 1686,
    FishBlasterDragEnd = 1687,
    QuickTimeCombatEnterDungeon = 1688,
    QuickTimeCombatGalleryStart = 1689,
    QuickTimeCombatGalleryUpdate = 1690,
    QuickTimeCombatGalleryStop = 1691,
    InspirationSpurtRestartCountdown = 1692,
    PoetryFesPaintingFinish = 1693,
    PoetryFesPaintingStart = 1694,
    BlessingV2ScanSuccess = 1695,
    BlessingV2ScanFailed = 1696,
    FriendGift_GiveFriendGiftRsp = 1697,
    FriendGift_GetRecvGiftListRsp = 1698,
    FriendGift_HaveRecvGiftNotify = 1699,
    FriendGift_AcceptGiveGiftRsp = 1700,
    FriendGift_AcceptAllGiveGiftRsp = 1701,
    FriendGift_AcceptAllGiveGiftFailedRsp = 1702,
    FriendGift_GetCanGiveFriendGiftRsp = 1703,
    FriendGift_SetGiftWishRsp = 1704,
    FriendGift_GetFriendGiftWishListRsp = 1705,
    FilmfestSniperGalleryStart = 1706,
    FilmfestSniperGalleryUpdate = 1707,
    FilmfestSniperGalleryStop = 1708,
    FilmfestBallgamePlayerScoreUpdate = 1709,
    HomeworldConstructMappingChanged = 1710,
    HomeworldJumpToWoodTab = 1711,
    OnGetReliquarySetScheme = 1712,
    OnGetSaveReliquarySetSchemeRsp = 1713,
    OnGetSetEquipLockStateBatchRsp = 1714,
    OnGetReliquaryLockGeneralOptionRsp = 1715,
    OnGetReliquaryLockGeneralOptionRspFail = 1716,
    LanV4PushBoxRequestUnLock = 1717,
    LanV4PushBoxRequestKillEntityByRuntimeID = 1718,
    LanV4PushBoxRequestCheckAllPerformFinish = 1719,
    LanV4PushBoxBeforeEntityLeaveCell = 1720,
    LanV4PushBoxLeftStepChange = 1721,
    OnGalleryLanV4CarpJumpStart = 1722,
    StaminaFightChooseAvatar = 1723,
    StaminaFightStartChallenge = 1724,
    OnGetSetEquipAvatarPreviewRsp = 1725,
    OnGetReliquaryWearCustomDataRsp = 1726,
    OnGetSetEquipBatchRsp = 1727,
    HomeworldFilterRequest = 1728,
    HomeworldFilterClose = 1729,
    CatCafeEnterNewFavorStage = 1730,
    CatCafeFeedSuccess = 1731,
    EntityTouchLoadingFinished = 1732,
    EntityTouchFavorValueChanged = 1733,
    ForceCloseEntitySelect = 1734,
    EntityTouchEnableUIAction = 1735,
    ActionButtonPointerDown = 1736,
    ActionButtonPointerUp = 1737,
    OnActivitySkillDoSkillNotify = 1738,
    AutoTimeStopGalleryInfoUpdate = 1739,
    AutoTimeStopTrialAvatarMapUpdate = 1740,
    AlchemySimPotionStart = 1741,
    AlchemySimBottlingReady = 1742,
    AlchemySimPotionFinish = 1743,
    AlchemySimPotionExamFinish = 1744,
    AlchemySimPotionPuzzlePlaced = 1745,
    AlchemySimCropRspFailed = 1746,
    AlchemySimCropHarvested = 1747,
    AlchemySimCropPlanted = 1748,
    AlchemySimCropRipened = 1749,
    AlchemySimCropUpgrade = 1750,
    AlchemySimGalleryUpdate = 1751,
    AlchemySimGalleryNewRound = 1752,
    AlchemySimGalleryDealerReportUpdate = 1753,
    SlimeCannonScoreUpdate = 1754,
    SlimeCannonComboUpdate = 1755,
    SlimeCannonComboReset = 1756,
    SlimeCannonDifficultyUpdate = 1757,
    SlimeCannonBulletUpdate = 1758,
    QuestCheckFinish = 1759,
    QuestCheckFail = 1760,
    CharacterPageRedirect = 1761,
    RemusMagicDragonDashQTE = 1762,
    RemusMagicDragonDashBeginQTE = 1763,
    GreatFestivalV2TakeUpgradeRewardRsp = 1764,
    GreatFestivalActivityClose = 1765,
    GreatFestivalAcitvityInfoUpdate = 1766,
    GreatFestivalAcitvityWatcherInfoUpdate = 1767,
    EffigyChallengeV5SupportListUpdate = 1768,
    GetEffigyChallengeV5SelectDifficultyRsp = 1769,
    RemusCatReminder = 1770,
    HomeworldWishListRefresh = 1771,
    HomeworldWishListSaveSuccess = 1772,
    HomeworldWishListDeleteSuccess = 1773,
    HomeworldWishListUnLockFurnitureBatch = 1774,
    HomeworldTakeFurnitureBatch = 1775,
    RoleCombatCardEventRefresh = 1776,
    RoleCombatCardEventRefreshFinish = 1777,
    RoleCombatSelectCardRefresh = 1778,
    RoleCombatCoinRefresh = 1779,
    RoleCombatCoinChangePerform = 1780,
    RoleCombatAvatarBonusPerform = 1781,
    RoleCombatGetFriendBriefRentInfo = 1782,
    RoleCombatGetFriendRentInfo = 1783,
    RoleCombatGetFriendRentInfoFail = 1784,
    RoleCombatSetRentAvatar = 1785,
    RoleCombatRecordHandbookRefresh = 1786,
    RoleCombatSelectRewardAvatar = 1787,
    RoleCombatRefreshRewardAvatar = 1788,
    RoleCombatStartGallery = 1789,
    RoleCombatSurrender = 1790,
    RoleCombatBackTrackPreview = 1791,
    RoleCombatRewardItemAdded = 1792,
    RoleCombatTeamSelect = 1793,
    RoleCombatTeamChange = 1794,
    RoleCombatTrialAvatarPreview = 1795,
    RoleCombatBriefInfoUpdate = 1796,
    RoleCombatAllMaxRoundIdUpdate = 1797,
    RoleCombatPhonographBgmUpdate = 1798,
    RoleCombatPersonalSettingUpdate = 1799,
    RoleCombatToggleSelectCardContent = 1800,
    RoleCombatSelectCard = 1801,
    RoleCombatViewAvatar = 1802,
    RoleCombatScheduleEnd = 1803,
    RoleCombatOneOffRewardItemAdded = 1804,
    RoleCombatStarRewardItemAdded = 1805,
    RoleCombatRewardTaken = 1806,
    RoleCombatOneOffRewardTaken = 1807,
    RoleCombatStarRewardTaken = 1808,
    RoleCombatGetRentCount = 1809,
    RoleCombatFlipAvatar = 1810,
    RoleCombatGetRentInfo = 1811,
    RoleCombatAllFinish = 1812,
    WatergunTransferFinish = 1813,
    WatergunDialogShow = 1814,
    WatergunGalleryStart = 1815,
    WatergunGalleryUpdate = 1816,
    WatergunGuidePrepare = 1817,
    BulletHellGalleryPreStart = 1818,
    BulletHellGalleryStart = 1819,
    SyncBulletHellProgress = 1820,
    BulletHellGalleryUpdate = 1821,
    BulletHellProgressIncrease = 1822,
    BulletHellProgressClear = 1823,
    BulletHellGalleryStop = 1824,
    OnMvMAbilityEvent = 1825,
    OnMvMUseCardRsp = 1826,
    OnMvMEnterDungeon = 1827,
    OnMvMEnemyCreate = 1828,
    TalkReviewForceHideStateChange = 1829,
    TalkHideUIForceHideStateChange = 1830,
    OnTalkHideUI = 1831,
    OnTalkDialogActiveAnimChange = 1832,
    FairyTalesCombatFeverInfoUpdate = 1833,
    FairyTalesTakeBonus = 1834,
    BeforeCatchDollEnterScenePerformFinish = 1835,
    CatchDollOnScoreChange = 1836,
    CatchDollOnHitValueChange = 1837,
    CatchDollTipMemoryWaveSpawn = 1838,
    CatchDollOnSameDollAdditionTimesAdd = 1839,
    CatchDollCatchTimesChange = 1840,
    FairyTalesCurrentGalleryStart = 1841,
    FairyTalesCurrentGalleryStop = 1842,
    GetFairyTalesCapsuleToyLotterRsp = 1843,
    CharMasterInfoUpdate = 1844,
    CharMasterPreviewTrialAvatar = 1845,
    CharMasterKeyAdded = 1846,
    CharMasterShowBanner = 1847,
    GadgetSpeechBubbleRefresh = 1848,
    GetActivityPreviewAvatarInfo = 1849,
    RechargeDiskPreviewAvatarInfoAdded = 1850,
    ResidentRedPointInitFinish = 1851,
    PhlogistonBarRefresh = 1852,
    PhlogistonInVehicleChange = 1853,
    TriggerPhlogistonBarFocus = 1854,
    TriggerLackPhlogistonAnim = 1855,
    DrillEnergyGalleryFinish = 1856,
    DrillEnergyGalleryStart = 1857,
    BoltBugGalleryFinish = 1858,
    BoltBugGalleryStart = 1859,
    ResonantCrystalGalleryStart = 1860,
    ResonantProHintInit = 1861,
    ResonantCrystalGalleryAdd = 1862,
    ResonantCrystalGalleryStop = 1863,
    ResonantCrystalGalleryBlink = 1864,
    ResonantCrystalGalleryUpdate = 1865,
    ResonantCrystalGallerySuccuss = 1866,
    PriorityUISourceUpdate = 1867,
    SetNyxBarAnimatorTrigger = 1868,
    DelusionExpBarValueUpdate = 1869,
    FoodFilterClose = 1870,
    OnUnlockCookRecipe = 1871,
    GainBuffPreviewAvatarInfoAdded = 1872,
    GainBuffGalleryStart = 1873,
    GainBuffBehaviorAdd = 1874,
    GainBuffGalleryStop = 1875,
    NatlanTourDetailUnlockAni = 1876,
    NatlanTourSideDetailRefresh = 1877,
    ReunionCacheRewardItem = 1878,
    ReunionWPGetReward = 1879,
    OnGetReliquaryPurchaseItem = 1880,
    OnGetReliquaryOfferingItem = 1881,
    OnGetReliquaryPurchaseRsp = 1882,
    OnGetReliquaryOfferingRsp = 1883,
    OnGetReliquaryOfferPurchaseInfoNotify = 1884,
    OnGetReliquaryTransferItem = 1885,
    OnGetReliquaryTransferRsp = 1886,
    BomberDodocoDetonateChange = 1887,
    BomberDodocoReminderStart = 1888,
    NatlanStylizeGalleryPreStart = 1889,
    NatlanStylizeGalleryStart = 1890,
    NatlanStylizeGalleryRecover = 1891,
    NatlanStylizeGalleryRefresh = 1892,
    LevelTimePause = 1893,
    BoltbugAbyssGalleryStart = 1894,
    BoltbugAbyssGalleryFinish = 1895,
    BoltbugAbyssGalleryUpdate = 1896,
    DreamExploreScoreUpdate = 1897,
    FloatToyPreLoadFinsished = 1898,
    FloatToyGameStart = 1899,
    FloatToyGameFinish = 1900,
    FloatToyGamePause = 1901,
    FloatToyGameRestart = 1902,
    FloatToyChangeMedal = 1903,
    FloatToyGadgetWaitListChange = 1904,
    CoChallengePlayerInfoUpdate = 1905,
    CoChallengeStageChange = 1906,
    CoChallengeGalleryInfoChange = 1907,
    CoChallengeGalleryBuffInfoChange = 1908,
    CoChallengeStageUpdate = 1909,
    CoChallengeSelfDie = 1910,
    GalleryArenaChallengeStart = 1911,
    GalleryArenaChallengeStop = 1912,
    ArenaChallengeMonsterPreloadBegin = 1913,
    AbyssWarInfoChange = 1914,
    AbyssWarAccountRsp = 1915,
    AbyssWarErosionHud = 1916,
    ReliquaryQuickPutFiveStarUpgrade = 1917,
    GcgAbcShowSettle = 1918,
    GcgAbcGiveUp = 1919,
    GcgAbcPickFailed = 1920,
    MonsterChessPhaseChange = 1921,
    MonsterChessRecordInfoUpdate = 1922,
    MonsterChessDetailDialogContextUpdate = 1923,
    MonsterChessInLevelCameraReset = 1924,
    MonsterChessFightControllerInfoUpdate = 1925,
    MonsterChessTriggerArtifactNotify = 1926,
    MonsterChessCardLevelUpNotify = 1927,
    MonsterChessCardStarUpNotify = 1928,
    MonsterChessBriefInfoRsp = 1929,
    MonsterChessPrepareChosenListUpdate = 1930,
    MonsterChessDrawDialogUpdate = 1931,
    LightStrikeGalleryStart = 1932,
    LightStrikeGalleryUpdate = 1933,
    LightStrikeGalleryStop = 1934,
    BeyondLevelDataSaveRefresh = 1935,
    BeyondLevelRenameStart = 1936,
    BeyondLevelRenameEnd = 1937,
    BeyondRefreshCloudLevelItem = 1938,
    BeyondLocalSaveCreateCategory = 1939,
    BeyondLocalSaveSortChange = 1940,
    BeyondRuntimeCountDownInfoNotify = 1941,
    BeyondUploadCloudData = 1942,
    BeyondLevelMatchStatusChange = 1943,
    BeyondLevelMatchStageChange = 1944,
    BeyondLevelMatchGetLevelBriefInfo = 1945,
    BeyondLevelMatchFinished = 1946,
    BeyondLevelDetailDialogOpen = 1947,
    BeyondLevelDetailDialogClose = 1948,
    BeyondAnniversaryDialogClose = 1949,
    BeyondCreateWorldFailNotify = 1950,
    BeyondMatchHideScoreNotifyReceive = 1951,
    BeyondAfterUploadCloudData = 1952,
    BeyondCommunityResourceGet = 1953,
    BeyondDataConfigTabSelectChange = 1954,
    BeyondEnterRandomPublicHallRsp = 1955,
    BeyondEmojiPanelButtonClicked = 1956,
    BeyondDataConfigClose = 1957,
    BeyondDataConfigRightRefresh = 1958,
    BeyondRecommendDataRefresh = 1959,
    BeyondRecommendUIRefresh = 1960,
    BeyondUpdateCreatorData = 1961,
    BeyondRecommendDataGetNextPage = 1962,
    BeyondFeatureSwitchRefresh = 1963,
    BeyondActiveSuiteReady = 1964,
    BeyondActiveSuiteChanged = 1965,
    BeyondDungeonSettle = 1966,
    BeyondLevelChipChanged = 1967,
    BeyondPaidDlcManageUpdate = 1968,
    BeyondPaidDlcCapacityUpgrade = 1969,
    OnBeyondDlcShelveRsp = 1970,
    OnBeyondDlcUnshelveRsp = 1971,
    BeyondUpdateMiniMap = 1972,
    OnLoadMonoLevelMapFinished = 1973,
    OnLoadMonoLevelMapUIFinished = 1974,
    BeyondBigMapZoomInitScaleApplied = 1975,
    BeyondUpdateOptionSelectorPanel = 1976,
    BeyondOptionSelectorRuntimePostMountToParent = 1977,
    BeyondOnPostEnterSceneRsp = 1978,
    BeyondOnReceiveEnterSceneNotify = 1979,
    BeyondRefreshSettleLikeCntNotify = 1980,
    BeyondRefreshSettlePage = 1981,
    BeyondSettleRecLevelListUpdated = 1982,
    BeyondCloseUGCStarUpgradeDialogNotify = 1983,
    BeyondHandbookInfoChanged = 1984,
    BeyondHandbookRewardRsp = 1985,
    BeyondHandbookRewardReceive = 1986,
    BeyondLevelWatcherRewardReceive = 1987,
    BeyondSeasonDLCInfoChanged = 1988,
    BeyondEnteringDialogMsgRsp = 1989,
    AvatarFactionChange = 1990,
    BeyondCurrentLevelStateAbnormal = 1991,
    BeyondDungeonPlayerDie = 1992,
    BeyondSeasonChanged = 1993,
    BeyondDungeonBeforeShowPlayerReviveDialog = 1994,
    BeyondInitialActiveInfoChanged = 1995,
    BeyondInitialActiveInfoClosed = 1996,
    BeyondCustomUIFactionRefresh = 1997,
    BeyondCustomUILayerUpdate = 1998,
    BeyondCommunityGetPublishTrendList = 1999,
    BeyondCommunityGetPublishTrendUnreadCount = 2000,
    BeyondCommunityGetPublishTrendRemainCount = 2001,
    BeyondCreatorSubscribeInfoUpdate = 2002,
    BeyondCommunityBatchGetUserSubscribeLevel = 2003,
    BeyondCommunityGetCollectionLevelList = 2004,
    RefreshBeyondPlayerDetailOnlineInfo = 2005,
    RefreshBeyondTeamPlayer = 2006,
    BeyondHallMessageGet = 2007,
    RefreshBeAllowState = 2008,
    RefreshBeyondRecommendFriend = 2009,
    BeyondPlayerDetailOnlineInfoFetcherOnRsp = 2010,
    BeyondShowAvatarChange = 2011,
    BydCreateAvatarOnSelectBodyConfirm = 2012,
    BydCreateAvatarOnServerCreateAvatarSuccess = 2013,
    BydCreateAvatarOnServerCreateAvatarFail = 2014,
    BydCreateAvatarRefreshPage = 2015,
    BydCreateAvatarPageOnApplicationPause = 2016,
    BydCreateAvatarPlayerBreakIdle = 2017,
    BydCreateAvatarStopIdleAnim = 2018,
    BydCostumeVideoPlayFinish = 2019,
    BydOnCreateFollowUpAvatarFinish = 2020,
    BydCostumeInfoInitialized = 2021,
    BydCostumeInfoUpdated = 2022,
    BydCostumeInfoUpdatedExceptTrialSuitPart = 2023,
    BydCostumeInfoUpdaeForRedPoint = 2024,
    BydCostumeMarkInfoUpdated = 2025,
    BydCostumeLocalSetInfoInitialized = 2026,
    BydCostumeLocalSetAutoSwitch = 2027,
    BydCostumeLocalSetInfoIUpdated = 2028,
    BydCostumeSelectSameCostumeSet = 2029,
    BydCostumeAvatarVoiceInfoUpdated = 2030,
    BydCostumeTransferEffectInfoUpdated = 2031,
    BeyondCostumeSetNameUpdated = 2032,
    BeyondCostumeSetNameIllegal = 2033,
    BeyondCostumeSetDeleted = 2034,
    BeyondCostumeShareCodeGenSuccess = 2035,
    BeyondCostumeShareCodeGenFail = 2036,
    BeyondCostumeSynthesisSuccess = 2037,
    BydCostumeAvatarSetInfoUpdated = 2038,
    BydCostumeCurCostumeSetInfoUpdated = 2039,
    BydCostumeSetIndexUpdated = 2040,
    BydCostumeSetIndexUpdatedLocal = 2041,
    BydCostumeTrialCostumeSetInfoUpdated = 2042,
    BydCostumeUesTrialCardSuccess = 2043,
    BydCostumeAvatarSetInitialized = 2044,
    BydCostumePageFilterResultUpdated = 2045,
    BydCostumePagefilterFailed = 2046,
    BydCostumeLackinfoUpdated = 2047,
    BeyondCostumePostInfoUpdated = 2048,
    BeyondCostumeSetSaveSuccess = 2049,
    BeyondCostumeEmojiSaveSuccess = 2050,
    BeyondCostumeSetDisplaySuccess = 2051,
    BeyondCostumeSetDisplayUpdate = 2052,
    BeyondFromClosetToCostumePage = 2053,
    BeyondBeforeTriggerSkillBtnByInput = 2054,
    BeyondBeforeBuyGoodsFromBeyondPurchaseDialog = 2055,
    BeyondChangeHallAvatarSuccess = 2056,
    OnBeyondCreateAvatarCommonCheckRsp = 2057,
    BeyondPlayerInfoSwitchAvatarShowMode = 2058,
    BeyondShowTwinAvatarModeUpdated = 2059,
    BeyondPlayerSocialConfigNotify = 2060,
    BeyondRequestShopCostumeListSuccess = 2061,
    BeyondRequestGachaCostumeListSuccess = 2062,
    OnVersionIndexDataNotify = 2063,
    BeyondCustomRandStateChange = 2064,
    BeyondTrialCostumeExpired = 2065,
    BeyondTrialSuitExpired = 2066,
    BeyondTrialCardExpired = 2067,
    BeyondCostumeBlueprintRemoved = 2068,
    BeyondCostumeBlueprintObtained = 2069,
    BeyondCostumeSynthesisInfoUpdated = 2070,
    BeyondGetSynthesizedCostume = 2071,
    BeyondGetSynthesizedSuit = 2072,
    BeyondAvatarInteractMoveEvent = 2073,
    BeyondAvatarInteractZoomEvent = 2074,
    BeyondAvatarInteractTouchWithoutMoveEvent = 2075,
    BeyondProfilePageOpen = 2076,
    BeyondSelfProfileInfoUpdated = 2077,
    BeyondSelfProfileSetSuccess = 2078,
    BeyondCustomizeProfileUploadFinish = 2079,
    BeyondCustomizeProfileAuditFail = 2080,
    BeyondCustomizeProfileAuditSuccess = 2081,
    BeyondCustomizeProfileStartAudit = 2082,
    BeyondCustomizeProfileSwitch = 2083,
    BeyondActivityOpen = 2084,
    BeyondActivityClose = 2085,
    BeyondActivityCommonContentClose = 2086,
    BeyondActivityInfoUpdate = 2087,
    BeyondActivityStageUpdate = 2088,
    BeyondActivityCoinInfoUpdate = 2089,
    BeyondActivityScoreInfoUpdate = 2090,
    BeyondActivityTakeReward = 2091,
    BeyondActivityLevelRelatedInfoUpdate = 2092,
    BeyondLevelRelatedInfoUpdate = 2093,
    BeyondActivityFashionWelfareTakeDailyReward = 2094,
    BeyondActivityFashionWelfareTakeAllScoreReward = 2095,
    BeyondActivityFashionWelfareTargetRewardChanged = 2096,
    BeyondActivityFashionWelfareIsPopularLevel = 2097,
    BeyondActivityFashionWelfareReceiveDailyReward = 2098,
    BeyondActivityFashionWelfareReceiveScoreReward = 2099,
    BeyondCommunityGetLibLevelList = 2100,
    BeyondCommunityGetAnnual26Heat = 2101,
    BeyondGachaGiftFriendBriefListUpdated = 2102,
    BeyondShopGiftFriendBriefListUpdated = 2103,
    BeyondGachaGiftSendCheck = 2104,
    BeyondGachaGiftFriendDetailInfoUpdated = 2105,
    BeyondGachaGiftFriendBriefUpdated = 2106,
    BeyondGachaGiftModeUpdated = 2107,
    BeyondGachaGiftModeDataUpdated = 2108,
    BeyondGachaGiftBlessTextCheckResult = 2109,
    BeyondGachaGiftSendSuccess = 2110,
    BeyondShopGiftSendSuccess = 2111,
    BeyondGiftHistoryUpdated = 2112,
    BeyondGiftHistoryRsp = 2113,
    BeyondGiftDeleteHistory = 2114,
    BeyondGiftBriefHistoryListFetched = 2115,
    PostRecvBeyondGiftDataNotify = 2116,
    BeyondGiftNotifyNeedClose = 2117,
    BeyondGiftDialogOpen = 2118,
    BeyondPlayerSocialInfoUpdated = 2119,
    BeyondPlayerSocialLikeCntUpdated = 2120,
    BeyondPlayerSocialLikeRsp = 2121,
    BeyondPlayerTagUpdated = 2122,
    FeatureBlockSocialInfoUpdated = 2123,
    BeyondGetPlayerSocialDisplayCostume = 2124,
    PostBeyondMall3DSceneSetup = 2125,
    RefreshBeyondMallPage = 2126,
    BeyondMallSwitchToShopTypeAndRefresh = 2127,
    PreTryOpenBeyondMallPage = 2128,
    PostTryOpenBeyondMallPage = 2129,
    BeyondShopCartGoodsInfoUpdated = 2130,
    BeyondShopCartBydMcoinCostInfoUpdated = 2131,
    BeyondRerunDiscountNumNotify = 2132,
    BeyondMcoinExchangeFreeMcoinSuccess = 2133,
    PostBeyondEnterSceneDisplay3DSceneSetup = 2134,
    PostBeyondWorldPrepareShowDataNotify = 2135,
    OnGetBeyondLoadingWebImageInfoSuccess = 2136,
    PostBeyondCurDungeonDataStatusNotify = 2137,
    BeyondCurDungeonDataStatusNotifyDownloadFinish = 2138,
    BeyondCommunityOtherLevelRecommendListUpdated = 2139,
    BeyondCommunityMonthlyHotLevelUpdated = 2140,
    BeyondCommunityGetDataFailed = 2141,
    BeyondCommunityGetBbsDataFinish = 2142,
    BeyondCommunityGetBbsDataDetailFinish = 2143,
    BeyondCommunityLikeRefresh = 2144,
    BeyondCommunityRecommendGetDataUpdated = 2145,
    BeyondClassicModeTeamChangeFailed = 2146,
    BeyondLevelDetailWebDataReceive = 2147,
    BeyondPlayerSocialInfoReceive = 2148,
    BeyondLevelFriendRespReceive = 2149,
    BeyondLevelRetailRecRespReceive = 2150,
    BeyondFashionWelfareIsPopularLevelRspReceive = 2151,
    BeyondLevelRelatedInfoRspReceive = 2152,
    BeyondGetUserLevelGameRecordsRespReceive = 2153,
    BeyondLevelHotCommendReceive = 2154,
    BeyondLevelInFloorCommendReceive = 2155,
    BeyondGetChipBriefRespReceive = 2156,
    BeyondGetLevelAchievementUnlockInfoRespReceive = 2157,
    BeyondChangelogReceive = 2158,
    BeyondGetAllRankingList = 2159,
    BeyondGetTopRankingList = 2160,
    BeyondGetTailRankingList = 2161,
    BeyondGetAllTierList = 2162,
    BeyondGetTopTierList = 2163,
    BeyondGetTailTierList = 2164,
    BeyondGetFriendChipBriefRsp = 2165,
    BeyondCommentDeleted = 2166,
    BeyondGetMaxAchievementCount = 2167,
    BeyondPublishCommentReceive = 2168,
    BeyondReplyCommentReceive = 2169,
    OnGetBeyondLevelPlatinumAchievementImage = 2170,
    OnGetBeyondLevelDLcImage = 2171,
    BeyondGetPlatinumFinishedInfo = 2172,
    GetUserLevelTierBestRecord = 2173,
    BeyondGetUserTrendData = 2174,
    BeyondGetUserCommentRsp = 2175,
    BeyondGetMultiLangRsp = 2176,
    BeyondSetDisplayPlatinumRsp = 2177,
    BeyondLevelCommentLikeRefresh = 2178,
    BeyondLevelCommentDislikeRefresh = 2179,
    BeyondLevelLibraryMainWebDataReceive = 2180,
    BeyondGetUserPlayTotalInfoRespReceive = 2181,
    BeyondLevelCollectionRefresh = 2182,
    BeyondLevelLibraryFavouriteLevelChipInfoReceive = 2183,
    BeyondLevelLibraryRefresh = 2184,
    BeyondLibraryBatchDeleteStateChange = 2185,
    BeyondLibrarySingleDataGiven = 2186,
    BeyondLibraryFocusInput = 2187,
    BeyondLibraryActivateInput = 2188,
    BeyondPlayActivityChipDataList = 2189,
    BeyondPlayActivityDungeonAndBriefInfo = 2190,
    BeyondPlayActivityOnBeyondGetRankingListRankRsp = 2191,
    BeyondGetUserPlayTrendInfoPageResp = 2192,
    BeyondGetUserLatestPlayTrendInfoResp = 2193,
    BeyondLevelLibraryGetDungeonBriefRsp = 2194,
    BeyondLevelLibraryFoldToggleFocus = 2195,
    PostGetBeyondWishItemRsp = 2196,
    PostSetBeyondWishItemRsp = 2197,
    PostBeyondWishItemNotify = 2198,
    BeyondRewardStateUpdate = 2199,
    BeyondVirtualDialPrepareDialogReleaseButtonPre = 2200,
    BeyondEquipStuffBagSlotChange = 2201,
    BeyondRuntimeEquipSlotUpdate = 2202,
    BeyondRuntimeHighlightSlot = 2203,
    BeyondRuntimeCancalHighligh = 2204,
    BeyondSelfBagPluginChanged = 2205,
    BeyondSelfEquipPluginChanged = 2206,
    BeyondShopDataUpdated = 2207,
    BeyondShopUIRefresh = 2208,
    BeyondShopDisappear = 2209,
    BeyondDropDataUpdated = 2210,
    BeyondDropDisappear = 2211,
    BeyondDropUIRefresh = 2212,
    BeyondInventoryPanelStateUpdated = 2213,
    BeyondShopEnterSellMode = 2214,
    BeyondShopSellFinished = 2215,
    BeyondBagAllSlotsUpdated = 2216,
    BeyondBagSlotsUpdated = 2217,
    BeyondBagItemRefIdsUpdated = 2218,
    BeyondBagCategoryItemsUpdated = 2219,
    BeyondBagAllCurrencyUpdated = 2220,
    BeyondBagSlotCountUpdated = 2221,
    BeyondBagGuidItemUpdated = 2222,
    BeyondBagItemCdUpdated = 2223,
    BeyondItemOwnerUpdated = 2224,
    BeyondBagItemCdFinish = 2225,
    BeyondDragDropBagItem = 2226,
    BeyondItemTipClose = 2227,
    BeyondShopTemplateGoodCountChanged = 2228,
    BeyondShopTemplateGoodTableColChanged = 2229,
    BeyondShopTemplateGoodRefStuffChanged = 2230,
    BeyondCommonCountChanged = 2231,
    BeyondCommonTableColChanged = 2232,
    BeyondHallRoomEnter = 2233,
    BeyondHallRoomLeave = 2234,
    BeyondTrialWhiteListChange = 2235,
    BeyondDownloadTaskUpdate = 2236,
    BeyondRoomCaptainChange = 2237,
    BeyondRoomPlayerExit = 2238,
    BeyondRoomPlayerEnter = 2239,
    BeyondEditorRoomReady = 2240,
    BeyondEditorRoomUpdate = 2241,
    BeyondRecommendLevelListUpdated = 2242,
    BeyondRecommendShowLevelChanged = 2243,
    BeyondRecommendShowLevelChangeFailed = 2244,
    BeyondRecommendShowLevelPreferredRankingIdChanged = 2245,
    BeyondGetRecommendLevelChipDataList = 2246,
    BeyondGetRecommendLevelRankInfoData = 2247,
    BeyondGetPlayerInfoRecommendLevelRankInfoData = 2248,
    BeyondGetRecommendLevelRankNumData = 2249,
    BeyondGetPlayerInfoRecommendLevelChipDataList = 2250,
    BeyondRecommendLevelRankUpdated = 2251,
    BeyondGetBatchTinyLevelInfoDataList = 2252,
    BeyondEnviroChangeLight = 2253,
    BeyondCollectPageFrontendChanged = 2254,
    BeyondBattlePassLevelChanged = 2255,
    BeyondBattlePassDataUpdated = 2256,
    BeyondBattlePassMissionUpdated = 2257,
    BeyondBattlePassProductPay = 2258,
    BeyondBattlePassPurchased = 2259,
    BeyondBattlePassMissionRewardItemAdd = 2260,
    BeyondBattlePassLevelRewardItemAdd = 2261,
    BeyondBattlePassPaidRewardItemAdd = 2262,
    BeyondLevelLangPacketLoaded = 2263,
    BeyondCreatorContestInfoUpdated = 2264,
    CeremonyGhostTeamBarValueChange = 2265,
    CeremonyGhostTeamBarBuffStart = 2266,
    CeremonyBattleRefreshMonsterScore = 2267,
    CeremonyBattleRefreshTargetScore = 2268,
    UpdateInstrumentalEnsemble = 2269,
    InstrumentalEnsembleMatchEnd = 2270,
    InstrumentalEnsembleMatchFailed = 2271,
    InstrumentalEnsemblePlayEnd = 2272,
    MusicMainPageBackToFirst = 2273,
    MusicMainPageBackToSelectSubPage = 2274,
    MusicBookGuideNext = 2275,
    MusicGameBookDataUpdate = 2276,
    MusicGameEditorDirty = 2277,
    MusicGameUploadSuccess = 2278,
    MusicGameUgcDataDirty = 2279,
    MusicGameMetronomeSettingChange = 2280,
    MusicGameUgcReportRsp = 2281,
    MusicGameUgcUpdateClientSetting = 2282,
    UpdateMusicGameBookDraftInvite = 2283,
    MusicGameBookDraftInviteFailed = 2284,
    MusicGameBookUpdateUgcMusicData = 2285,
    MusicGameBookMpEnd = 2286,
    MusicGameBookModListUpdate = 2287,
    LanV5GreetingCardStickerAdd = 2288,
    LanV5GreetingCardStickerRemove = 2289,
    LanV5GreetingCardStickerScale = 2290,
    LanV5GreetingCardSubmit = 2291,
    LanV5GreetingCardGetReceivedCardMinimum = 2292,
    LanV5GreetingCardGetReceivedCardBrief = 2293,
    LanV5GreetingCardGetReceivedCardDetail = 2294,
    LanV5GreetingCardSetReceivedCardFavorite = 2295,
    LanV5GreetingCardLevelFinish = 2296,
    LanV5GreetingCardSendNpcGift = 2297,
    LanV5GreetingCardSendNpcGiftFinish = 2298,
    LanV5GreetingCardGetEditSlotCards = 2299,
    LanV5GreetingCardSaveEditSlotCardSuccess = 2300,
    LanV5GreetingCardSaveEditSlotCardFail = 2301,
    LanV5GreetingCardEditSlotCardUpdate = 2302,
    LanV5GreetingCardGetRecommandCommunityCards = 2303,
    LanV5GreetingCardGetFavoriteCommunityCards = 2304,
    LanV5GreetingCardCommunityCardUpdate = 2305,
    LanV5GreetingCardSetCommunityCardLiked = 2306,
    LanV5GreetingCardSetCommunityCardFavorite = 2307,
    LanV5GreetingCardSearchCommunityCard = 2308,
    LanV5GreetingCardGetUgcCardDetail = 2309,
    LanV5GreetingCardGetUgcCardDetailFailed = 2310,
    LanV5GreetingCardGetStampValue = 2311,
    PuzzleFighterPlayerInfoUpdate = 2312,
    PuzzleFighterPlayerJoin = 2313,
    PuzzleFighterSettle = 2314,
    PuzzleFighterRestart = 2315,
    PuzzleFighterRecover = 2316,
    NatlanRaceGalleryPreStart = 2317,
    NatlanRaceGalleryStart = 2318,
    NatlanRaceGalleryRecover = 2319,
    NatlanRaceGalleryRefresh = 2320,
    NatlanRaceGalleryCowLevelStart = 2321,
    GetEffigyChallengeV6SelectDifficultyRsp = 2322,
    EffigyV6ChallengeBuffSelect = 2323,
    EffigyV6ChallengeSocialDetail = 2324,
    EffigyV6ChallengeSocialPublic = 2325,
    EffigyV6ChallengeSocialPublicInvalid = 2326,
    HerculesBattleV3GalleryStart = 2327,
    HerculesBattleV3GalleryUpdateRecover = 2328,
    HerculesBattleV3GalleryUpdate = 2329,
    HerculesBattleV3ShowReminder = 2330,
    HerculesBattleV3CloseReminder = 2331,
    HerculesBattlePreJumpNodeFinish = 2332,
    HerculesBattleJumpNodeFinish = 2333,
    HerculesBattleJumpPreAccumulateNodeFinish = 2334,
    HerculesBattlePreJumpAccumulateNodeFinish = 2335,
    HerculesBattleJumpAccelerateNodeFinish = 2336,
    HerculesBattleJumpAcceleratePreAccumulateNodeFinish = 2337,
    OnGetRelicRecommendData = 2338,
    LanV5UnLockReminder = 2339,
    InazumaBadmintonGalleryPreStart = 2340,
    InazumaBadmintonGalleryStart = 2341,
    InazumaBadmintonGalleryStop = 2342,
    InazumaBadmintonGalleryRecover = 2343,
    InazumaBadmintonTriggerPerfect = 2344,
    InazumaBadmintonTriggerTutorial = 2345,
    DoppelgangerPuzzleObservation = 2346,
    DoppelgangerPuzzleStartRound = 2347,
    DoppelgangerPuzzleStartRecord = 2348,
    DoppelgangerPuzzlePauseRecord = 2349,
    DoppelgangerPuzzleFinishRecord = 2350,
    DoppelgangerPuzzleRefresh = 2351,
    DoppelgangerPuzzleRoundOver = 2352,
    DoppelgangerPuzzleAssist = 2353,
    DoppelgangerPuzzleRetry = 2354,
    FishingJoyBuffUpdate = 2355,
    FishingJoyHitUpdate = 2356,
    FishingJoyComboUpdate = 2357,
    FishingJoyCatchSpecialFish = 2358,
    FishingJoyGalleryStart = 2359,
    GetActivitySocialBriefRsp = 2360,
    TowerChallengeStageStart = 2361,
    TowerChallengeStageEnd = 2362,
    TowerChallengePickUpBuff = 2363,
    TowerChallengeFriendBuffUpdate = 2364,
    TowerChallengeStartFloorUpdate = 2365,
    TowerChallengeSocialDetail = 2366,
    TowerChallengeFriendBuffCountUpdate = 2367,
    TowerChallengeSocialPublic = 2368,
    TowerChallengeSocialPublicInvalid = 2369,
    TowerChallengeFriendBuffToggleUpdate = 2370,
    TalkOnlyShowContent = 2371,
    TalkContextDataUpdate = 2372,
    FreeMizukiFocusEntity = 2373,
    CutScenePageCloseRaycastTarget = 2374,
    OnGetSetWeaponLockStateBatchRsp = 2375,
    ADShootingFinish = 2376,
    ADShootingRecordUpdate = 2377,
    ADShootingGetFriendRecord = 2378,
    ADShootingGetFriendRecordFailed = 2379,
    DrillBattleGalleryUpdate = 2380,
    DrillBattleReminderShow = 2381,
    DrillBattleStartTipsShow = 2382,
    AbyssCoreGalleryStart = 2383,
    AbyssCoreGalleryUpdate = 2384,
    AbyssCoreGalleryStop = 2385,
    NatlanArenaPreviewAvatarInfoAdded = 2386,
    NatlanArenaBuffGalleryStart = 2387,
    NatlanArenaBossGalleryStart = 2388,
    NatlanArenaBehaviorAdd = 2389,
    NatlanArenaKillHPNumAdd = 2390,
    NatlanArenaBuffGalleryStop = 2391,
    MultiStageHpBarChange = 2392,
    PartyScoreUpdate = 2393,
    PartyHurtNotice = 2394,
    PartyShowGetPropNotice = 2395,
    PartyMissileCountdownUINotice = 2396,
    PartySpecialReminder = 2397,
    PartySettle = 2398,
    PartyCloseMapRandomPage = 2399,
    DrugCollectShowPlayerChoosePanel = 2400,
    DrugCollectShowRedirectorChoosePanel = 2401,
    DrugCollectControlled = 2402,
    DrugCollectChatSkill = 2403,
    DrugCollectChatSwitch = 2404,
    DrugCollectChatProgress = 2405,
    DrugCollectChatHealth = 2406,
    DrugCollectScoreUpdate = 2407,
    DrugCollectHealthUpdate = 2408,
    PlayerJumpPosDelay = 2409,
    ThemeParkZooDoGachaRsp = 2410,
    ThemeParkZooSaveDeployRsp = 2411,
    ThemeParkZooPutAnimalItem = 2412,
    ThemeParkTriathlonGalleryUpdate = 2413,
    ThemeParkSimAvatarQuestAccept = 2414,
    ThemeParkSimAvatarQuestFinish = 2415,
    ThemeParkSimCloseQuestSubpage = 2416,
    ThemeParkSimGalleryInfoUpdate = 2417,
    ThemeParkSimRoundResume = 2418,
    ThemeParkSimRoundSettle = 2419,
    ThemeParkSimFoodBuffActivated = 2420,
    ThemeParkSimFoodBuffGachaFail = 2421,
    ThemeParkSimGoalProgressUpdate = 2422,
    ThemeParkSimBuffChange = 2423,
    ThemeParkSimBuffProgressUpdate = 2424,
    ThemeParkSimCloseReminder = 2425,
    ThemeParkSimUpgradeFacilityFailed = 2426,
    ThemeParkSimExpandFacilityFailed = 2427,
    ThemeParkStartTrialLevelFailed = 2428,
    ThemeParkSimEmployeeUpgradeCost = 2429,
    ThemeParkSimUpgradeEmployee = 2430,
    ThemeParkSimUpgradeEmployeeFailed = 2431,
    ThemeParkSimHireEmployeeFailed = 2432,
    ThemeParkSimFireEmployee = 2433,
    ThemeParkSimDeployEmployee = 2434,
    ThemeParkSimUndeployEmployee = 2435,
    ThemeParkSimNewbieGuideNarrate = 2436,
    ThemeParkSimNewbieGuideNarrateAbort = 2437,
    ThemeParkSimNewbieGuideUIMask = 2438,
    ThemeParkSimNewbieGuideEnd = 2439,
    ThemeParkSimGalleryStart = 2440,
    DiversityBattleChangeDifficulty = 2441,
    DiversityBattlePreviewAvatarInfoAdded = 2442,
    DiversityBattleSocialPublicInvalid = 2443,
    DiversityBattleScoreChange = 2444,
    DiversityBattleStateChange = 2445,
    DiversityBattleSocialPublic = 2446,
    EscoffierCookingGalleryUpdate = 2447,
    EscoffierCookingGallleryStageStart = 2448,
    EscoffierCookingGalleryStageEnd = 2449,
    EscoffierCookingGalleryUpdateStageEnd = 2450,
    EscoffierCookingGalleryTargetUnfinished = 2451,
    EscoffierCookingGalleryFlavorBarComplete = 2452,
    EscoffierCookingReminderAppeared = 2453,
    EscoffierCookingReminderDisappeared = 2454,
    MvMv2PvpGalleryStart = 2455,
    MvMv2SimulateGalleryStart = 2456,
    MvMv2PveGalleryRecover = 2457,
    MvMv2PvpGalleryRecover = 2458,
    MvMv2PveMonsterDeploy = 2459,
    MvMv2PvpMonsterDeploy = 2460,
    MvMv2ProgressUpdate = 2461,
    MvMv2PveBuildDestroyed = 2462,
    MvMv2GameOver = 2463,
    MvMv2PveGalleryStop = 2464,
    MvMv2PvpGalleryStop = 2465,
    MvMv2AvailableCardNotify = 2466,
    MvMv2PvpMultiPlayerInfoCheck = 2467,
    MvMv2PvpSelfProgressUpdate = 2468,
    MvMv2PvpTargetProgressUpdate = 2469,
    MvMv2PvpSelfBuildDestroyed = 2470,
    MvMv2PvpTargetBuildDestroyed = 2471,
    MvMv2SimulateProgressUpdate = 2472,
    MvMv2SimulateBuildDestroyed = 2473,
    MvMv2PvpDefenseSetSuccess = 2474,
    MvMv2InLevelAvailableCardNotify = 2475,
    MvMv2DungeonInfoUpdate = 2476,
    MvMv2PvpPreStart = 2477,
    MvMv2PvpPreStartEnd = 2478,
    Saurus1V3GalleryUpdate = 2479,
    Saurus1V3AttackUpdate = 2480,
    Saurus1V3ScoreUpdate = 2481,
    OnGetReliquaryDustRsp = 2482,
    OnGetReliquaryDustSelectRsp = 2483,
    RelicDustSelectNew = 2484,
    OptionalResourceDownloadAskEnd = 2485,
    SupportSkillInfoChange = 2486,
    ShowSupportSkillReminder = 2487,
    LeyLineChallengeReward = 2488,
    LeyLineChallengeRewardExtra = 2489,
    LeyLineChallengeResidentInfoUpdate = 2490,
    LeyLineChallengePlayerInfoUpdate = 2491,
    LeyLineChallengeFriendDataUpdate = 2492,
    LeyLineChallengePopularAvatarUpdate = 2493,
    LeyLineChallengePopularOutdate = 2494,
    LeyLineChallengeSetReliquary = 2495,
    LeyLineChallengeAvailableReliquaryUpdate = 2496,
    LeyLineChallengeTeamCreated = 2497,
    LeyLineChallengeDungeonContextUpdate = 2498,
    LeyLineChallengeTeamOperateFailed = 2499,
    LeyLineChallengeMpRoundLocked = 2500,
    LeyLineChallengeRecordCommited = 2501,
    LeyLineChallengeTeamAdjustSucceed = 2502,
    LLCBattleGalleryPreStart = 2503,
    LLCBattleGalleryStart = 2504,
    ShowLLCPopularEffect = 2505,
    LLCBattleGalleryStop = 2506,
    DungeonTeamBuilderDismiss = 2507,
    DungeonTeamBuilderInviteFailed = 2508,
    DungeonTeamBuilderPlayerReply = 2509,
    DungeonTeamBuilderAllInfoUpdate = 2510,
    SlimeCannonV2HPUpdate = 2511,
    SlimeCannonV2KillScoreUpdate = 2512,
    SlimeCannonV2WaveUpdate = 2513,
    CooperateChallengeV2GalleryStart = 2514,
    CooperateChallengeV2HideBuffBar = 2515,
    CooperateChallengeV2ShowBuffBar = 2516,
    CooperateChallengeV2ShowCloseBtn = 2517,
    CooperateChallengeV2ChangeDifficulty = 2518,
    OnFruitPickGameStart = 2519,
    OnFruitPickGameRestart = 2520,
    BillBoardV2ElementShieldUpdate = 2521,
    AutoChessInLevelArtifactSelected = 2522,
    AutoChessInLevelArtifactRefresh = 2523,
    AutoChessInLevelGridUpdate = 2524,
    AutoChessInLevelChessUpdate = 2525,
    AutoChessInLevelChessLevelUp = 2526,
    AutoChessInLevelEquipUpdate = 2527,
    AutoChessInLevelShopUpdate = 2528,
    AutoChessInLevelShopRefresh = 2529,
    AutoChessInLevelCampUpdate = 2530,
    AutoChessInLevelCounterUpdate = 2531,
    AutoChessInLevelStartChallenge = 2532,
    AutoChessInLevelOpenTips = 2533,
    AutoChessInLevelCloseTips = 2534,
    AutoChessInLevelPopTips = 2535,
    AutoChessInLevelWearEquip = 2536,
    AutoChessInLevelTakeOffEquip = 2537,
    AutoChessInLevelChessDuplicator = 2538,
    AutoChessInLevelReminderShow = 2539,
    AutoChessNodeEnter = 2540,
    AutoChessOptionSelect = 2541,
    AutoChessInLevelFightSettle = 2542,
    AutoChessEquipShopRefresh = 2543,
    AutoChessEquipShopLeave = 2544,
    AutoChessEquipShopBuy = 2545,
    AutoChessEquipShopSell = 2546,
    AutoChessCoinChange = 2547,
    AutoChessPackageDialogClose = 2548,
    AutoChessNodeInfoUpdate = 2549,
    AutoChessTalentUpgrade = 2550,
    AutoChessGuideButtonUpdate = 2551,
    AutoChessUpdateBillBoard = 2552,
    AutoChessTipsHover = 2553,
    AutoChessTipsFocus = 2554,
    AutoChessTipsCloseFromJoypad = 2555,
    AutoChessTipsTryTakeOffEquip = 2556,
    AutoChessBossInfoDialogOpenTips = 2557,
    DungeonPlayerOrderChange = 2558,
    BossFirstPassRewardRefresh = 2559,
    BossFirstPassRewardItemAdded = 2560,
    ResortBuildShowBanner = 2561,
    ResortBuildBannerFadeOut = 2562,
    GraffitiSniperGalleryStart = 2563,
    GraffitiSniperGalleryUpdate = 2564,
    GraffitiSniperGalleryStop = 2565,
    PaintProgressGalleryInfoUpdate = 2566,
    PaintSeeliePaletteCloseDialog = 2567,
    AgentReconEvidenceDialogClose = 2568,
    AgentReconPuzzleSuccess = 2569,
    AgentReconGalleryStop = 2570,
    HolidayResortAdvInPlayStartLevel = 2571,
    HolidayResortAdvRestartLevel = 2572,
    HolidayResortAdvQuit = 2573,
    HolidayResortAdvShowBubble = 2574,
    HolidayResortAdvRestartLevelOnDeath = 2575,
    HolidayResortGraffitiGalleryStart = 2576,
    HolidayResortGraffitiHeatChange = 2577,
    HolidayResortGraffitiHeatMaxValue = 2578,
    HolidayResortGraffitiProgress = 2579,
    HolidayResortGraffitiTrappedStart = 2580,
    HolidayResortGraffitiTriggerSlotEffect = 2581,
    HolidayResortGraffitiGalleryStartNoRecover = 2582,
    HolidayResortGraffitiPlayCutscene = 2583,
    HolidayResortGraffitiColorHint = 2584,
    HolidayResortSniperGalleryStart = 2585,
    HolidayResortSniperGalleryStop = 2586,
    HolidayResortSniperGalleryDataUpdate = 2587,
    HolidayResortBattleGalleryStart = 2588,
    HolidayResortBattleGalleryStop = 2589,
    HolidayResortBattleGalleryDataUpdate = 2590,
    BeyondPrivateHallEditorSwitchState = 2591,
    BeyondHallContextDataUpdate = 2592,
    BeyondHallListUpdate = 2593,
    BeyondHallPlayerDataUpdate = 2594,
    BeyondHallDataBatchUpdate = 2595,
    BeyondPrivateHallBriefUpdate = 2596,
    BeyondPrivateHallCreateSuccess = 2597,
    BeyondPrivateHallEditorSwitchCamera = 2598,
    BeyondPrivateHallUndeployAllFacility = 2599,
    BeyondPrivateHallResetCameraToSceneCenter = 2600,
    BeyondPrivateHallUndo = 2601,
    BeyondPrivateHallRedo = 2602,
    BeyondPrivateHallSwitchMultiSelectMode = 2603,
    BeyondPrivateHallPasswordIncorrect = 2604,
    BeyondPrivateHallPasswordCorrect = 2605,
    BeyondPrivateHallSelectChange = 2606,
    BeyondPrivateHallUIDragStart = 2607,
    BeyondPrivateHallUIDragEnd = 2608,
    BeyondPrivateHallCameraFocus = 2609,
    BeyondPrivateHallPerformPlacement = 2610,
    BeyondPrivateHallLodChange = 2611,
    BeyondGetFreeDlc = 2612,
    BeyondGetPaidDlc = 2613,
    BeyondCombatEffectOverAllocate = 2614,
    WorldWatcherInfoUpdate = 2615,
    WorldWatcherItemAdd = 2616,
    MoonPhaseLevelUpdateMainPage = 2617,
    MoonPhaseLevelUpdate = 2618,
    MoonPhaseTypeUpdate = 2619,
    SetMoonOvergrowBarAnimatorTrigger = 2620,
    RobotVacuumVehicleOn = 2621,
    RobotVacuumVehicleOff = 2622,
    NodKraiTourParkourGalleryPreStart = 2623,
    NodKraiTourParkourGalleryStart = 2624,
    NodKraiTourParkourGalleryRecover = 2625,
    NodKraiTourParkourGalleryRefresh = 2626,
    NodkraiTourHackGalleryStart = 2627,
    NodkraiTourHackGalleryRecover = 2628,
    NodkraiTourHackGalleryStop = 2629,
    NodkraiTourRoboGalleryUpdate = 2630,
    MateCompeteVSStart = 2631,
    MateCompeteVSStop = 2632,
    NightwatLanternGalleryUpdate = 2633,
    TrialAvatarGalleryUpdate = 2634,
    PhotoV7ActionDone = 2635,
    BomberV3TransitFinish = 2636,
    LockStepV2Recovery = 2637,
    SaveAvatarsToNewBackupTeam = 2638,
    GallantPathInfoNotify = 2639,
    LocalLegendInfoUpdate = 2640,
    LocalLegendGroupRewardItemAdd = 2641,
    RoleCombatTarotExchangeInviteReply = 2642,
    RoleCombatTarotExchangeInviteReplyRsp = 2643,
    RoleCombatTarotExchangeUpdate = 2644,
    RoleCombatTarotExchangeFinish = 2645,
    RoleCombatSetTarotWish = 2646,
    RoleCombatGetFriendTarotInfo = 2647,
    RoleCombatGetTarotExchangeRecord = 2648,
    WeekActiveUpdate = 2649,
    WeekActiveDetailUpdate = 2650,
    WeekActiveGetReward = 2651,
    SceneUISetupReady = 2652,
    NodKraiOfferingLevelUpdate = 2653,
    PlayerExpTipsOpen = 2654,
    PlayerExpTipsClose = 2655,
    MoonPhaseTipsClose = 2656,
    TicTacToePlayCmd = 2657,
    RobotAbyssalReminderAppear = 2658,
    RobotAbyssalReminderDisappear = 2659,
    RobotAbyssalPageReset = 2660,
    RobotAbyssalGalleryUpdate = 2661,
    RobotAbyssalPhaseEnd = 2662,
    PostHandleGetAllSceneGalleryInfoRsp = 2663,
    SumeruAdvPathwayGalleryStart = 2664,
    SumeruAdvPathwayGalleryStop = 2665,
    SumeruAdvPathwayGalleryDataUpdate = 2666,
    SumeruAdvParkourGalleryStart = 2667,
    SumeruAdvParkourGalleryStop = 2668,
    SumeruAdvParkourGalleryDataUpdate = 2669,
    SumeruAdvFightPreviewAvatarInfoAdded = 2670,
    SumeruAdvFightResetRecordSuccess = 2671,
    SumeruAdvFightBehaviorCountUpdate = 2672,
    SumeruAdvFightAdvanceSettleOpen = 2673,
    SumeruAdvFightStartPause = 2674,
    SumeruAdvFightEndPause = 2675,
    HumanDragonPuzzleLevelInfoUpdate = 2676,
    HumanDragonPuzzleGalleryStart = 2677,
    NeferInfoNotify = 2678,
    NeferScanRsp = 2679,
    NeferBuyGoodsRsp = 2680,
    QuestNextReview = 2681,
    AbyssWhisperReminderUpdate = 2682,
    AbyssWhisperReminderAppeared = 2683,
    AbyssWhisperReminderDisappeared = 2684,
    BeyondItemAdd = 2685,
    SnowRacePauseGalleryCountDown = 2686,
    SnowRaceThrowScoreUpdate = 2687,
    SnowRaceThrowGalleryStart = 2688,
    SnowRaceCombatScoreUpdate = 2689,
    SnowRaceHideGalleryDataUpdate = 2690,
    SnowRaceHideCaught = 2691,
    SnowRaceHideBecomeGhost = 2692,
    SnowRaceHidePlayerSetAvatarNotify = 2693,
    SnowRaceHidePlayerReadyNotify = 2694,
    SnowRaceHideStageInfoUpdate = 2695,
    SnowRaceHideSettle = 2696,
    SnowRaceHideMiniMapFog = 2697,
    SnowRaceHideFirstHunter = 2698,
    SnowRaceHideLevelClearTag = 2699,
    SnowRaceParkourUpdateScoreCollect = 2700,
    NatlanDragonPartyScoreUpdate = 2701,
    NatlanDragonPartyReminderUpdate = 2702,
    NatlanDragonPartyKillReminderUpdate = 2703,
    NatlanDragonPartyItemReminderUpdate = 2704,
    NatlanDragonPartyMissleAimUpdate = 2705,
    MagicInkEnergyBarStart = 2706,
    MagicInkEnergyBarStop = 2707,
    BirdPinballCreatePrepareBall = 2708,
    BirdPinballLaunchBall = 2709,
    BirdPinballLevelStateChange = 2710,
    BirdPinballShowReminder = 2711,
    BirdPinballShowDungeonTarget = 2712,
    BirdPinballRefreshScore = 2713,
    BirdPinballRefreshCombo = 2714,
    BirdPinballShowScorePopup = 2715,
    BirdPinballRefreshBallCount = 2716,
    BirdPinballStartFever = 2717,
    BirdPinballEndFever = 2718,
    BirdPinballOpenRewardLevel = 2719,
    BirdPinballCloseRewardLevel = 2720,
    BirdPinballAchieveTarget = 2721,
    BirdPinballPreBossDivision = 2722,
    BirdPinballBossDivision = 2723,
    HexenzirkelTeamBonusTips = 2724,
    LanV6BattleGalleryStart = 2725,
    LanV6BattleStartReminder = 2726,
    LanV6BattleReminderUpdate = 2727,
    LanV6BattleScoreUpdate = 2728,
    LanV6BattlePauseGalleryCountDown = 2729,
    LanV6BattleLevelUpInfoUpdate = 2730,
    TPSAimChange = 2731,
    TPSAimBlockChange = 2732,
    TPSWeaponInit = 2733,
    TPSWeaponSwitched = 2734,
    TPSWeaponEquiped = 2735,
    TPSAccessoryUnlocked = 2736,
    RefreshTPSExpandUI = 2737,
    RefreshTpsIceGunCharge = 2738,
    TPSSupplyPreparedAmmo = 2739,
    TPSSupplyMagazineAmmo = 2740,
    TPSSetPcKeyMap = 2741,
    TpsMercenariesInfoUpdate = 2742,
    TpsMercenariesGalleryPreStart = 2743,
    TpsMercenariesGalleryStart = 2744,
    TpsMercenariesGalleryUpdate = 2745,
    TpsMercenariesRewardItemAdd = 2746,
    TpsMercenariesLevelUnlock = 2747,
    LanV6LikeHintNotify = 2748,
    LanV6LanternGiftSelect = 2749,
    LanV6LanternGiftReceiveSuccess = 2750,
    LanV6LanternFriendSelect = 2751,
    LanV6CardRemoveSuccess = 2752,
    LanV6CardFavoriteSuccess = 2753,
    LanV6CardUpdateNotify = 2754,
    LanV6LanternGiftReceive = 2755,
    LanV6MapSelectDialogClose = 2756,
    LanV6MapSelectDialogSelect = 2757,
    AsyncGadgetDestroySuccess = 2758,
    MonsterChessV2PhaseChange = 2759,
    MonsterChessV2RecordInfoUpdate = 2760,
    MonsterChessV2FightControllerInfoUpdate = 2761,
    MonsterChessV2CardLevelChangeNotify = 2762,
    MonsterChessV2TriggerSkillNotify = 2763,
    MonsterChessV2DrawDialogUpdate = 2764,
    MonsterChessV2CardStarUpNotify = 2765,
    MonsterChessV2DetailDialogContextUpdate = 2766,
    MonsterChessV2PrepareChosenListUpdate = 2767,
    MonsterChessV2InLevelCameraReset = 2768,
    MonsterChessV2FocusToDetailDialog = 2769,
    MonsterChessV2FlagUpNotify = 2770,
    OnTimeStopPhotoFinishPlayRsp = 2771,
    OnTimeStopPhotoSkipStage1 = 2772,
    OnTimeStopPhotoGalleryStop = 2773,
    LanV6ParkourUpdateScore = 2774,
    LanV6ParkourReduceRunningCountdown = 2775,
    LanV6ParkourEnableActionPanel = 2776,
    LanV6DanmakuAvtarHpChange = 2777,
    LanV6DanmakuProgressUpdate = 2778,
    LanV6DanmakuGainAttackBuff = 2779,
    LanV6DanmakuGainTimeBuff = 2780,
    LanV6DanmakuGainCoin = 2781,
    LanV6DanmakuGadgetBurst = 2782,
    LanV6DanmakuBossAppear = 2783,
    LanV6DanmakuBossHpChange = 2784,
    LanV6DanmakuBossPhaseChange = 2785,
    LanV6DanmakuTechGroupUpgrade = 2786,
    LanV6DanmakuTechGroupUpgradeFail = 2787,
    LanV6DanmakuTechUpgrade = 2788,
    LanV6DanmakuTechUpgradeFail = 2789,
    LanV6DanmakuSettle = 2790,
    LanV6DanmakuAddIndicator = 2791,
    LanV6DanmakuRemoveIndicator = 2792,
    LanV6DanmakuBonusUpdate = 2793,
    MallReplaceCardColumbinaFirstNotify = 2794,
    TeamHideInfoRefresh = 2795,
    ShowMapEffect = 2796,
    HideMapEffect = 2797,
    OperationCardProgressUpdate = 2798,
    WxycReminderInterrupt = 2799,
    CinePlayAnimatorEffectAttach = 2800,
    CinePlayAnimatorEffectDetach = 2801,
    TowerDefenseDataUpdate = 2802,
    TowerDefenseMonsterDataUpdate = 2803,
    TowerDefenseStartForReminder = 2804,
    TowerDefenseSkillSelect = 2805,
    TowerDefenseSGVInfoUpdate = 2806,
    TowerDefenseTryClearTips = 2807,
    TowerDefenseMonsterDie = 2808,
    TowerDefenseMonsterArrive = 2809,
    TowerDefenseCardSelectPageUpdate = 2810,
    TowerDefenseChallengeSettle = 2811,
    TowerDefenseWaveSettle = 2812,
    TowerDefenseCameraChange = 2813,
    TowerDefenseWaveUpdate = 2814,
    TowerDefenseSwitchFight = 2815,
    TowerDefenseMonsterPointUpdate = 2816,
    TowerDefenseGuideButtonUpdate = 2817,
    TowerDefenseGuideResetCamera = 2818,
    TowerDefenseReturnToNormal = 2819,
    TowerDefenseSwitchToWaiting = 2820,
    TowerDefenseSwitchToPanelFocus = 2821,
    TowerDefenseSwitchToDragging = 2822,
    TowerDefenseSwitchToBuilding = 2823,
    TowerDefenseSwitchToModify = 2824,
    TowerDefenseFailDeploy = 2825,
    TowerDefenseFullBuild = 2826,
    TowerDefenseHideHintReminder = 2827,
    TowerDefenseSwitchState = 2828,
    TowerDefenseOccupiedUpdate = 2829,
    CommanderWarTeamEnter = 2830,
    CommanderWarTeamLeave = 2831,
    CommanderWarMapChangeMode = 2832,
    CommanderWarMapReleaseMist = 2833,
    CommanderWarMapCameraMove = 2834,
    CommanderWarMapForceShowMark = 2835,
    BubbleDramaBladeGalleryPrestart = 2836,
    BubbleDramaBladeGalleryStart = 2837,
    BubbleDramaBladeGalleryRecover = 2838,
    BubbleDramaBladeUpdateScore = 2839,
    BubbleDramaAirFightUpdateScore = 2840,
    UINotifyAttachToGVUpdate = 2841,
    UINotifyAttachToGVRemove = 2842,
    BeyondDlcFreeCoinExpire = 2843,
    MonsterSnapPaintingRepairFinish = 2844,
    MonsterSnapPaintingRepairStart = 2845,
    FirmamentMnemoOfferingLevelUpdate = 2846,
    QuestSceneViewDialogClose = 2847,
    TalkOnlyShowContentButCanClick = 2848,
    ShortVideoSearchUgcBrief = 2849,
    ShortVideoUpdateBrief = 2850,
    ShortVideoSaveRecord = 2851,
    ShortVideoDeleteRecord = 2852,
    ShortVideoGalleryInfoUpdate = 2853,
    ShortVideoVoteSuccess = 2854,
    ShortVideoLevelStatePreBegin = 2855,
    ShortVideoRequestChangeAvatar = 2856,
    ShortVideoLoadingDialogClose = 2857,
    ShortVideoNotifyCountDownStart = 2858,
    TradeShowShootingGalleryUpdate = 2859,
    MusketChallengeGalleryStart = 2860,
    MusketChallengeGalleryUpdate = 2861,
    MusketChallengeGalleryStop = 2862,
    MusketChallengeClosePage = 2863,
    TradeShowTdLevelStateUpdate = 2864,
    TradeShowTdInLevelReminder = 2865,
    TradeShowTdInteePanelAppear = 2866,
    TradeShowTdInteePanelDisappear = 2867,
    TradeShowTdInteeTowerEnergyGain = 2868,
    TradeShowTdInteePickupEnergy = 2869,
    TradeShowTdTutorialWave = 2870,
    TradeShowTdExitDungeon = 2871,
    TradeShowBattlePhaseUpdate = 2872,
    TradeShowBattleScoreUpdate = 2873,
    TradeShowStgHpUpdate = 2874,
    TradeShowStgProgressUpdate = 2875,
    TradeShowStgPhaseChange = 2876,
    EntityEnergyBarUpdate = 2877,
    FirmamentFoldOperate = 2878,
    FirmamentFoldGuideUpdate = 2879,
    FirmamentBookUpdateTarget = 2880,
    FirmamentBookSelectDefault = 2881,
    FirmamentBookDeselect = 2882,
    FirmamentBookCreatePage = 2883,
    FirmamentBookEnterPort = 2884,
    FirmamentBookPleatFinish = 2885,
    FirmamentBookPleating = 2886,
    FirmamentBookSelectPoint = 2887,
    FirmamentBookMove = 2888,
    FirmamentElementCubeGalleryUpdate = 2889,
    FirmamentDeformReady = 2890,
    FirmamentDeformUnready = 2891,
    NaturalistCaptureItemAdded = 2892,
    BeastsBattleGMSettle = 2893,
    BeastsBattleGMTakeDamage = 2894,
    BeastsBattleShowOption = 2895,
    BeastsBattleSelectOption = 2896,
    BeastsBattleSpecialRoundFinish = 2897,
    MapMarkShowStartReminder = 2898,
    MapMarkShowGeneralReminder = 2899,
    MapMarkShowSurveyProgress = 2900,
    MapMarkShowSurveying = 2901,
    MapMarkHelpChanged = 2902,
    MapMarkCloseSurveying = 2903,
    MapMarkHideActivityUI = 2904,
    BeyondCustomUIWindowFrameButtonAction = 2905,
    BeyondCustomUIWindowFrameToggleAction = 2906,
    BeyondCustomUIWindowFrameToggleStateChanged = 2907,
    BeyondCustomUIWindowFrameUpdate = 2908,
    BeyondCustomUIRuntimePlayCustomEffect = 2909,
    BeyondCustomUIWindowFrameChildDialogLoadFinish = 2910,
    BeyondCustomUIRuntimeUpdateMsgQueue = 2911,
    BeyondCustomUIRuntimeUpdateBuffList = 2912,
    RefuseRecvGiftSet = 2913,
    ColorBallLoadingClose = 2914,
    TalkUpdateShowAdventureGlossary = 2915,
    TalkUnlockAdventureGlossary = 2916,
    DSCharacterDie = 2917,
    LoliGolfDataUpdate = 2918,
    LoliGolfStageUpdate = 2919,
    LoliGolfHoleUpdate = 2920,
    LoliGolfBuffUpdate = 2921,
    LoliGolfReminderUpdate = 2922,
    LoliGolfQTEUpdate = 2923,
    LoliGolfWindUpdate = 2924,
    LoliGolfSettlement = 2925,
    LoliGolfSettlement2Loading = 2926,
    LoliGolfItemTipsDialogClose = 2927,
    LoliGolfItemTipsDialogCloseAll = 2928,
    LoliGolfItemTipsDialogBtnClose = 2929,
    LoliGolfPropSelectionChanged = 2930,
    LoliGolfTreasureWeaselUpdate = 2931,
    LoliGolfGuideAction = 2932,
    LoliGolfInitialReminder = 2933,
    LoliBattleGalleryStart = 2934,
    LoliBattleGalleryStop = 2935,
    LoliBattleDataUpdate = 2936,
    LoliBattlePrepareCountdown = 2937,
    NickRoomInfoUpdate = 2938,
    BeyondLevelObjectiveRewardFetched = 2939,
    MoonInfoAlarmWarningUpdate = 2940,
    MoonCoreDefenderHpBarUpdate = 2941,
    MoonCoreDefenderGalleryStart = 2942,
    MoonCoreDefenderGalleryStop = 2943,
    AquariumDivingGalleryStart = 2944,
    AquariumDivingGalleryRecover = 2945,
    AquariumDivingGalleryStop = 2946,
    AquariumDivingGalleryDataUpdate = 2947,
    AquariumDivingGalleryInfoUpdate = 2948,
    AquariumDivingShowStartReminder = 2949,
    AquariumDivingShowQTEFinishReminder = 2950,
    AquariumDivingSwitchTargetTask = 2951,
    AquariumDivingHideInLevelDialog = 2952,
    AquariumDivingStartExit = 2953,
    AquariumDivingInterruptExit = 2954,
    AquariumDivingSpecialExitPointActivated = 2955,
    AquariumDivingSpecialEventStart = 2956,
    AquariumDivingSpecialEventUpdate = 2957,
    AquariumDivingPlayerGetHit = 2958,
    AquariumDivingPlayerHpChange = 2959,
    AquariumDivingPlayerDie = 2960,
    AquariumDetectFishSuccess = 2961,
    AquariumDivingBagBroken = 2962,
    MarionetteTeaTimeInfoUpdate = 2963,
    MarionetteTeaTimeAccept = 2964,
    MarionetteTeaTimeCancel = 2965,
    OneShotGalleryContextUpdate = 2966,
    OneShotStartAiming = 2967,
    OneShotStopAiming = 2968,
    AquariumFishingBuffUpdate = 2969,
    AquariumFishingHitUpdate = 2970,
    AquariumFishingWaveUpdate = 2971,
    AquariumFishingGalleryEnd = 2972,
    AquariumFishingComboUpdate = 2973,
    AquariumFishingFundsUpdate = 2974,
    TPLCloseMainPageDialog = 2975,
    AquariumTaskFinished = 2976,
    AquariumTechUnlocked = 2977,
    AquariumPlayAreaGalleryStart = 2978,
    AquariumPlayAreaGalleryStop = 2979,
    AquariumItemGotBigDialogClosed = 2980,
    AquariumSellDataUpdate = 2981,
    AquariumSellGameEnd = 2982,
    AquariumSellEditorDecoUpdate = 2983,
    AquariumSellEditorBuyDecoUpdate = 2984,
    AquariumSellItemPlaceCondition = 2985,
    AvatarEnhanceHyperLinkClicked = 2986,
    MarionetteTeaTimeReminderAppeared = 2987,
    MarionetteTeaTimeReminderDisappeared = 2988,
    MusicPartyHotReload = 2989,
    MusicPartyJumpMusic = 2990,
    RegionPreloadRefresh = 2991,
    SnezhnayaTrainMapShowMarkEffect = 2992,
    SnezhnayaTrainMapSetDestSuccess = 2993,
    SnezhnayaTrainSetPlayerOnTrain = 2994,
    TpsGlassesChatTopicDataUpdated = 2995,
    RankedMatchShootingScoreUpdate = 2996,
    RankedMatchShootingChallengeBannerAppeared = 2997,
    RankedMatchShootingChallengeBannerDisappeared = 2998,
    RankedMatchShootingFeverReminderAppeared = 2999,
    RankedMatchShootingFeverReminderDisappeared = 3000,
    RankedMatchShootingGalleryContextUpdate = 3001,
    RankedMatchTrainPageStateUpdate = 3002,
    RankedMatchTrainPageScoreUpdate = 3003,
    RankedMatchTrainFinalStatsUpdate = 3004,
    RankedMatchTrainPageTimerUpdate = 3005,
    RankedMatchSnowBallScoreUpdate = 3006,
    RankedMatchSnowBallEnergyUpdate = 3007,
    RankedMatchSnowBallKillCountUpdate = 3008,
    RankedMatchSnowBallGalleryStart = 3009,
    RankedMatchSnowBallParamUpdate = 3010,
    RankedMatchSnowBallEnergyInfoUpdate = 3011,
    RankedMatchSnowBallRoundUpdate = 3012,
    RankedMatchSnowBallRatioUpdate = 3013,
    AdventurerStatueOnGetPlayerBriefUpdate = 3014,
    AdventurerStatueParkourOpenChestRewardUpdate = 3015,
    OnGetAdventurerStatueDriftBottleRecordRsp = 3016,
    OnGetAdventurerStatuePickDriftBottleRsp = 3017,
    OnGetAdventurerStatueThrowDriftBottleRsp = 3018,
    OnFinishAdventurerStatuePickDriftBottle = 3019,
    OnAdventurerStatueSendDriftBottleFinished = 3020,
    AdventurerStatueParkourGalleryPreStart = 3021,
    AdventurerStatueParkourGalleryStart = 3022,
    AdventurerStatueParkourGalleryRecover = 3023,
    AdventurerStatueParkourGalleryRefresh = 3024,
    AdventurerStatueParkourGalleryContextState = 3025,
    AdventurerStatueParkourGalleryContextScore = 3026,
    RankedMatchPuzzlePhaseChanged = 3027,
    RankedMatchPuzzleItemUpdate = 3028,
    RankedMatchPuzzleChallengeUpdate = 3029,
    RankedMatchPuzzleReminderAppeared = 3030,
    RankedMatchPuzzleReminderDisappeared = 3031,
    RankedMatchPuzzleBubbleAppeared = 3032,
    RankedMatchPuzzleBubbleDisappeared = 3033,
    RankedMatchPuzzleSupportCountChanged = 3034,
    TpsDefenseBuildPointUpdate = 3035,
    TpsDefenseHpUpdate = 3036,
    TpsDefenseProgressUpdate = 3037,
    TpsDefenseNewWave = 3038,
    TpsDefenseDungeonInfoUpdate = 3039,
    TpsDefenseInteePanelAppear = 3040,
    TpsDefenseInteePanelDisappear = 3041,
    IceCreatureAllGadgetInfoUpdate = 3042,
    IceCreatureGadgetInfoUpdate = 3043,
    IceCreatureAllInfoUpdate = 3044,
    IceCreatureLikeRsp = 3045,
    IceCreatureBeLikedNotify = 3046,
    IceCreaturePutStorageSuccess = 3047,
    IceCreatureTakeStorageSuccess = 3048,
    IceCreatureStorageItemAdd = 3049,
    GrappleCannonLineEffectChanged = 3050,
    IceCreatureGadgetUnlockNotify = 3051,
    ShowIceCreatureGotDialog = 3052,
    OdetteReputationInfoUpdate = 3053,
    OdetteChooseScheduleResult = 3054,
    OdetteSubmitEventResult = 3055,
    OdetteAdvancePhaseResult = 3056,
    OdetteDailySettleResult = 3057,
    OdetteResetPlaythroughResult = 3058,
    OdetteChangeTruthKeyStateResult = 3059,
    OdetteNextDay = 3060,
    OdetteSettle = 3061,
    OdetteCalenderSubPageEnable = 3062,
    OdetteOpenDaySubPageEnable = 3063,
    OdetteBlackScreen = 3064,
    BeyondRoomNotExists = 3065,
    BeyondRoomRecruitmentDealed = 3066,
    SituationButtonChanged = 3067,
    SnezhnayaBookDataUpdated = 3068,
    SnezhnayaBookSituationButtonFlash = 3069,
    SnezhnayaOfferingLevelUpdate = 3070,
    ReputationSnezDataUpdated = 3071,
    GlobalRankUpdate = 3072,
    GlobalRankClosed = 3073,
    GlobalRankRecordUpdate = 3074,
    GlobalRankPrivateUpdate = 3075,
    OnGetGlobalRankRecord = 3076,
    FriendRankUpdate = 3077,
    FriendRankClosed = 3078,
    FriendRankRecordUpdate = 3079,
    FriendRankPublicUpdate = 3080,
    OnGetFriendRankRecord = 3081,
    LongPressInteeCreate = 3082,
    LongPressInteeDisappear = 3083,
    GuideV2Update = 3084,
    GuideV2PathUpdate = 3085,
    GuideV2CustomValueUpdate = 3086,
    DynamicAudioArea3DChanged = 3087,
    PostNewItemGotDialogFinalDestroy = 3088,
    HpBarOverrideRefresh = 3089,
    SnowBallFightScoreUpdate = 3090,
    SnowBallFightEnergyUpdate = 3091,
    SnowBallFightBulletUpdate = 3092,
    SnowBallFightHealthUpdate = 3093,
    SnowBallFightHitUpdate = 3094,
    SnowBallFightBuffUpdate = 3095,
    SnowBallFightAimUpdate = 3096,
    SnowBallFightReminderUpdate = 3097,
    SnowBallFightShowScore = 3098,
    SnowBallFightShoot = 3099,
    SnowBallFightAlivenessUpdate = 3100,
    GamblingChessInLevelCameraAdjust = 3101,
    GamblingChessFightBattleStart = 3102,
    GamblingChessFightBattleInfo = 3103,
    GamblingChessTeamVoteSuccess = 3104,
    GamblingChessCancelVoteSuccess = 3105,
    GamblingChessAppendVoteSuccess = 3106,
    GamblingChessSupportRateUpdate = 3107,
    GamblingChessGetSettlePreviewRsp = 3108,
    GamblingChessSettleScoreSuccess = 3109,
    GamblingChessGetSocialBriefRsp = 3110,
    RogueBallGameStart = 3111,
    RogueBallDungeonSettle = 3112,
    RogueBallResetLevel = 3113,
    RogueBallWaveChanged = 3114,
    RogueBallRoundChanged = 3115,
    RogueBallScoreChanged = 3116,
    RogueBallExpChanged = 3117,
    RogueBallBallAcquired = 3118,
    RogueBallBuffAcquired = 3119,
    RogueBallFirstDrawCompleted = 3120,
    RogueBallPauseInLevelPage = 3121,
    SummonBattlePhaseUpdate = 3122,
    SummonBattleStartReminderUpdate = 3123,
    SummonBattleChargeUpdate = 3124,
    VineManScoreDetailUpdate = 3125,
    VodyanitsaSlotChange = 3126
};
static_assert(sizeof(T_GFJCNBMJPCH) == 4, "T_GFJCNBMJPCH");
inline const char* enum_name(T_GFJCNBMJPCH v) {
    switch ((int32_t)v) {
    case 0: return "None";
    case 1: return "NetworkPacket";
    case 2: return "LoginNotify";
    case 3: return "EnterSceneNotify";
    case 4: return "DisConnectNotify";
    case 5: return "PlayerListNotify";
    case 6: return "PlayerLeaveNotify";
    case 7: return "GetOnlinePlayerInfoNotify";
    case 8: return "WorldPlayerListUpdate";
    case 9: return "ScenePlayerListUpdate";
    case 10: return "PrompStandy2Climb";
    case 11: return "RegisterMonsterAIController";
    case 12: return "AttackDamegeNotify";
    case 13: return "AttackShieldNotify";
    case 14: return "ShowDamageTextNotify";
    case 15: return "AttackCureNotify";
    case 16: return "RefreshAvatarData";
    case 17: return "RefreshAvatarBuff";
    case 18: return "AvatarChangeNotify";
    case 19: return "AvatarActionPanelNotify";
    case 20: return "PlayerStaminaWarning";
    case 21: return "AvatarFocusModeChangeNotify";
    case 22: return "ElementReactionNotify";
    case 23: return "ShowCustomDamageTextNotify";
    case 24: return "OnApplicationFocus";
    case 25: return "OnApplicationPauseCanNotCache";
    case 26: return "AvatarSkillInfoUpdate";
    case 27: return "FestivalUpdateNotify";
    case 28: return "AfterSECTRFastReset";
    case 29: return "AvatarRenameInfoReady";
    case 30: return "AvatarRenameInfoUpdated";
    case 31: return "AvatarRenameValidityCheckPassed";
    case 32: return "AvatarRenameValidityCheckFailed";
    case 33: return "MiscRenameInfoReady";
    case 34: return "MiscRenameInfoUpdated";
    case 35: return "MiscRenameValidityCheckPassed";
    case 36: return "MiscRenameValidityCheckFailed";
    case 37: return "AddMiniMapMark";
    case 38: return "MapNotify";
    case 39: return "MapToggle";
    case 40: return "EnterArea";
    case 41: return "EnterAreaLateUpdate";
    case 42: return "EnterSubArea";
    case 43: return "ExitSubArea";
    case 44: return "EnterErosionArea";
    case 45: return "MapMarkChanged";
    case 46: return "MapMarkMoved";
    case 47: return "MapMarkDailyTaskChanged";
    case 48: return "MapMarkDungeonEntryExploreChanged";
    case 49: return "MapMarkDynamicAlwaysShowUpdate";
    case 50: return "AreaExploreUpdated";
    case 51: return "AreaExplorePointUpdated";
    case 52: return "MultiAreaExplorePercentUpdated";
    case 53: return "AreaUnlcoked";
    case 54: return "GuidePointAppear";
    case 55: return "GuidePointDisappear";
    case 56: return "NavigationPointAppear";
    case 57: return "NavigationPointDisappear";
    case 58: return "NavigationPointRefresh";
    case 59: return "NavigtaionPointRefreshWithId";
    case 60: return "NavigationPointChangeIcon";
    case 61: return "NavigationShowGuideTips";
    case 62: return "POIIndicatorAppear";
    case 63: return "POIIndicatorDisappear";
    case 64: return "BossNavigationAppear";
    case 65: return "BossNavigationDisappear";
    case 66: return "SorushIndicatorAppear";
    case 67: return "SorushIndicatorDisappear";
    case 68: return "TradeShowBonusIndicatorAppear";
    case 69: return "TradeShowBonusIndicatorDisappear";
    case 70: return "QuestPOINaviPathUpdate";
    case 71: return "PlayMarkUnlockEffect";
    case 72: return "UnlockTransPoint";
    case 73: return "UnlockScenePoint";
    case 74: return "UpdateSceneUnlockState";
    case 75: return "ScenePointLockStateChanged";
    case 76: return "ScenePointMarkUpdate";
    case 77: return "AddGadgetIndicator";
    case 78: return "RemoveGadgetIndicator";
    case 79: return "SetGadgetIndicatorCountDown";
    case 80: return "SetBossIndicatorCountDown";
    case 81: return "ForceSetGadgetIndicatorCountDown";
    case 82: return "MapMarkClicked";
    case 83: return "MapMarkClickNeared";
    case 84: return "RefreshMapRewardTips";
    case 85: return "RefreshMapMarkTips";
    case 86: return "MapAreaUpdated";
    case 87: return "MapPlaceNameUpdated";
    case 88: return "MarkManagerReady";
    case 89: return "MarkRemovedOnCancelTracing";
    case 90: return "MarkCustomTrackChanged";
    case 91: return "ShowMiniMapCustomSignal";
    case 92: return "GetSceneAreaRsp";
    case 93: return "GetScenePointRsp";
    case 94: return "RefreshMiniMapScale";
    case 95: return "RefreshSubAreaHideStatus";
    case 96: return "CloseMapMarkTipsOfMark";
    case 97: return "ActivityMapMarkBatchUpdate";
    case 98: return "ActivityMapScaleUpdate";
    case 99: return "ActivityMapCoinUpdate";
    case 100: return "DungeonEntryInfo";
    case 101: return "DungeonEntryInfoProtoClone";
    case 102: return "DungeonEntryInfoRecommendIgnoreQuest";
    case 103: return "DungeonEntryAppeared";
    case 104: return "DungeonEntryDisappeared";
    case 105: return "DungeonPlayerDie";
    case 106: return "DungeonSettled";
    case 107: return "DungeonGetReward";
    case 108: return "DungeonDifficultyChanged";
    case 109: return "DungeonEntryQuickOpened";
    case 110: return "GetDailyDungeonEntryInfo";
    case 111: return "GetDungeonEntryExploreCondition";
    case 112: return "GeneralInteeCreate";
    case 113: return "GeneralInteeCommand";
    case 114: return "GeneralInteeDisable";
    case 115: return "RegisterUICombatBar";
    case 116: return "UnregisterUICombatBar";
    case 117: return "RefreshUICombatBars";
    case 118: return "ShowUICombatBarSpark";
    case 119: return "ShowUICombatBarCharge";
    case 120: return "ShowUICombatBarFireEffect";
    case 121: return "ShowShakeOff";
    case 122: return "VehicleSkillDepotChange";
    case 123: return "VehicleSkillEnergyChange";
    case 124: return "InteractionUITrigger";
    case 125: return "InteractionUIClose";
    case 126: return "InteractionUIAnimSetTrigger";
    case 127: return "InteractionUIAnimSetInt";
    case 128: return "InteractionUIAnimSetFloat";
    case 129: return "InteractionUIAnimSetBool";
    case 130: return "InterQueryUiJumpNextGrp";
    case 131: return "InteractionRealStart";
    case 132: return "TalkNoBlackPrepareStart";
    case 133: return "TalkStart";
    case 134: return "TalkStartInternal";
    case 135: return "TalkEndInternal";
    case 136: return "TalkEndReal";
    case 137: return "TalkValueUpdate";
    case 138: return "OnTalkQuickSkip";
    case 139: return "GroupLinkUpdated";
    case 140: return "GroupLinkRemoved";
    case 141: return "CheckGroupReplacedRsp";
    case 142: return "RefreshCrossHair";
    case 143: return "CustomLoadingFadeInFinish";
    case 144: return "ChallengeBegin";
    case 145: return "ChallengeUpdated";
    case 146: return "ChallengeFailed";
    case 147: return "ChallengeCompleted";
    case 148: return "ChallengeAddSub";
    case 149: return "ChallengeSubFinish";
    case 150: return "ChallengeSubFail";
    case 151: return "RefreshInLevelChallengeView";
    case 152: return "RefreshSpacecraftExhibitManagePage";
    case 153: return "DialogSelectNotify";
    case 154: return "DialogSelectFinishNotify";
    case 155: return "DialogSelectItemNotify";
    case 156: return "DialogSelectItemTimeOut";
    case 157: return "TalkSelectDialogNotify";
    case 158: return "AutoTalkDialogFinish";
    case 159: return "ChangeAutoTalk";
    case 160: return "TalkShowItemList";
    case 161: return "TalkCloseItemList";
    case 162: return "CutScenePageShowTopText";
    case 163: return "CutScenePageCloseTopText";
    case 164: return "TalkShowReminder";
    case 165: return "TalkCloseReminder";
    case 166: return "TalkBgPicSetPosAndScale";
    case 167: return "TalkBgPicMove";
    case 168: return "UpdateTalkerName";
    case 169: return "UITriggerStart";
    case 170: return "OnDispatchFinishInterEvent";
    case 171: return "OnStartInterEvent";
    case 172: return "CoopSelectNotify";
    case 173: return "CurrCoopConfidenceValueChanged";
    case 174: return "CurrCoopTemperamentValueChanged";
    case 175: return "CoopTemperamentSelect";
    case 176: return "CoopTakeChapterReward";
    case 177: return "CoopUnlockChapter";
    case 178: return "CoopStartPointFromPage";
    case 179: return "CoopCancelQuest";
    case 180: return "CoopUIRefresh";
    case 181: return "CoopNewChapterAdd";
    case 182: return "CoopChapterViewed";
    case 183: return "CoopStartFirstPoint";
    case 184: return "CoopShowDefeatDialog";
    case 185: return "CoopTryStartPoint";
    case 186: return "CoopStartPointFailed";
    case 187: return "CoopDefeatNotify";
    case 188: return "CoopPressureMaxNotify";
    case 189: return "QuestDialogToggle";
    case 190: return "QuestBookUpdate";
    case 191: return "QuestBookSelectItem";
    case 192: return "AddQuestHint";
    case 193: return "AddQuestPauseHint";
    case 194: return "ContinueMutualQuest";
    case 195: return "QuestMutualStateChangedPre";
    case 196: return "QuestMutualStateChangedPost";
    case 197: return "QuestLackNPCChangedPre";
    case 198: return "QuestLackNPCChangedPost";
    case 199: return "QuestLackPlaceChangedPre";
    case 200: return "QuestLackPlaceChangedPost";
    case 201: return "PaimenNavigationEnabled";
    case 202: return "PaimenNavigationFailed";
    case 203: return "PaimenNavigationAlreadyInArea";
    case 204: return "PaimenNavigationInAreaOtherLayer";
    case 205: return "PaimenNavigationGuideHint";
    case 206: return "PaimenNavigationClockPageHint";
    case 207: return "NavigationUpdate";
    case 208: return "RemindQuest";
    case 209: return "BindTransButton";
    case 210: return "QuestProgressHint";
    case 211: return "QuestLackHint";
    case 212: return "QuestRemovedHint";
    case 213: return "GetFocusModeConflictParentQuestRspSucc";
    case 214: return "GetFocusModeConflictParentQuestRsp";
    case 215: return "QuestFocusModeDataUpdate";
    case 216: return "QuestQuitFocusMessageHint";
    case 217: return "ConfirmFocusAfterContinueMutual";
    case 218: return "QuestSceneryPausedMainPageHint";
    case 219: return "QuestSceneryResume";
    case 220: return "QuestSceneryInfoUpdate";
    case 221: return "NewDungeonQuestRewindPoint";
    case 222: return "QuestQuickLaunch";
    case 223: return "ActiveMainQuestDeleted";
    case 224: return "AfterQuestUpdatePreOnStateChanged";
    case 225: return "AfterQuestUpdatePostOnStateChanged";
    case 226: return "AfterQuestUpdatePre";
    case 227: return "AfterQuestUpdatePost";
    case 228: return "QuestRemoved";
    case 229: return "QuestStateUpdated";
    case 230: return "MainQuestStateUpdated";
    case 231: return "QuestTalkFinished";
    case 232: return "QuestGlobalVarUpdate";
    case 233: return "QuestVarUpdate";
    case 234: return "QuestTakePhotograph";
    case 235: return "ServerGameTimeLockedQuestListRsp";
    case 236: return "TalkWithPerformStart";
    case 237: return "FinishedTalkRecordUpdate";
    case 238: return "NearbyTrackableQuestAppear";
    case 239: return "NearbyTrackableQuestDisappear";
    case 240: return "TribalChapterInfoUpdate";
    case 241: return "TribalRedpointRefresh";
    case 242: return "ExecQuestLoadCtxOp";
    case 243: return "StopAllNarratorWithPriority";
    case 244: return "SubQuestTrackUpdate";
    case 245: return "OngoingQuestMarkUpdate";
    case 246: return "AnecdoteInfoInit";
    case 247: return "AnecdoteUpdate";
    case 248: return "AnecdoteFinish";
    case 249: return "AnecdoteConflictInfoRsp";
    case 250: return "AnecdoteCanWishRsp";
    case 251: return "AnecdoteWishSucc";
    case 252: return "AnecdoteWishInfoUpdate";
    case 253: return "AnecdoteRewardInfoUpdate";
    case 254: return "AnecdoteAreaInfoUpdate";
    case 255: return "AnecdotePopAreaUnlock";
    case 256: return "AnecdoteRewardItemAdd";
    case 257: return "StoryPreCancel";
    case 258: return "StoryCancel";
    case 259: return "CloseQPCDebug";
    case 260: return "StoryStart";
    case 261: return "StoryEnd";
    case 262: return "StoryGlobalValueChanged";
    case 263: return "NpcReady";
    case 264: return "NpcReadyPost";
    case 265: return "NpcAppear";
    case 266: return "NpcDisappear";
    case 267: return "NpcDestroy";
    case 268: return "NpcTalkStateChange";
    case 269: return "NpcDailyStart";
    case 270: return "NpcReactionStateChange";
    case 271: return "NpcDisabled";
    case 272: return "NpcBornInfoRemove";
    case 273: return "NpcBanned";
    case 274: return "NpcFreed";
    case 275: return "NpcNotify";
    case 276: return "OrphanNpcRemove";
    case 277: return "ClientScriptEventRsp";
    case 278: return "BagWeightUIRefresh";
    case 279: return "BagDialogToggle";
    case 280: return "BagSlotUpdate";
    case 281: return "BagItemUsed";
    case 282: return "BagItemDrop";
    case 283: return "BagAddChest";
    case 284: return "BagAddWidget";
    case 285: return "BagAddQuest";
    case 286: return "BagCombinableMaterialRPChanged";
    case 287: return "ForceCloseBagPage";
    case 288: return "BagItemDeleteReturnNotify";
    case 289: return "BeyondItemDeleteReturnNotify";
    case 290: return "BeyondMaterialDeleteTransferRsp";
    case 291: return "BeyondMaterialDeleteInfoUpdate";
    case 292: return "BeyondMaterialExpiredNotify";
    case 293: return "BeyondMaterialObtainedNotify";
    case 294: return "RefreshBagPageRedpoints";
    case 295: return "NewItemEncountered";
    case 296: return "SpecialItemEncountered";
    case 297: return "AccessCardItemEncountered";
    case 298: return "EscoffierCookItemEncountered";
    case 299: return "BeyondAvatarItemEncountered";
    case 300: return "ItemAdded";
    case 301: return "ItemAddedByShop";
    case 302: return "ItemAddedByShopBydAutoFreeBuyBundle";
    case 303: return "MaterialDeleteReturnItemAdded";
    case 304: return "ItemAddExceedLimitNotify";
    case 305: return "GatherItemAdded";
    case 306: return "GeneralItemAdded";
    case 307: return "GeneralItemMiddleShowAdded";
    case 308: return "QuestItemAdded";
    case 309: return "DailyTaskItemAdded";
    case 310: return "RandTaskItemAdded";
    case 311: return "ActivityItemAdded";
    case 312: return "HuntingItemAdded";
    case 313: return "HuntingV2ItemAdded";
    case 314: return "DonationItemAdded";
    case 315: return "ReputationCityTribalLevelRewardItemAdded";
    case 316: return "ReputationCityTotalRewardItemAdded";
    case 317: return "BlossomItemAdded";
    case 318: return "VirtualShopItemAdded";
    case 319: return "BeyondBagItemAdded";
    case 320: return "CollectedItemAdded";
    case 321: return "BatchItemAdded";
    case 322: return "BatchRealItemAdded";
    case 323: return "BatchBuyGoodsNotify";
    case 324: return "ItemGivingFinish";
    case 325: return "CloseItemGiving";
    case 326: return "GadgetGivingClose";
    case 327: return "ItemExchangeFinish";
    case 328: return "OnItemGivingRsp";
    case 329: return "OnItemExchangeRsp";
    case 330: return "DestroyItemFinish";
    case 331: return "GetCalcWeaponUpgradeReturnItemsResult";
    case 332: return "ChangeEquipLockState";
    case 333: return "ChangeRelicStarState";
    case 334: return "ChangeFoodStarState";
    case 335: return "UseItemFail";
    case 336: return "BagAddRenameItem";
    case 337: return "BagAddFireMaster";
    case 338: return "BagAddNatlanRaceEnvelope";
    case 339: return "BagAddNatlanRaceAlbum";
    case 340: return "BagAddHomeworldModuleItem";
    case 341: return "BagItemDestroyUIRefresh";
    case 342: return "StoredItemsChanged";
    case 343: return "RepeatedCostumeItemUsed";
    case 344: return "GainWeaponSkinItem";
    case 345: return "BagAddTreasureKey";
    case 346: return "AvatarVehicleStateChange";
    case 347: return "VehicleHPChange";
    case 348: return "VehicleLevelChange";
    case 349: return "OperateVehicleStateChange";
    case 350: return "VehicleInteractFailed";
    case 351: return "OperateVehicleListChange";
    case 352: return "AvatarInfoUIRefresh";
    case 353: return "AvatarFightPropRefresh";
    case 354: return "AvatarEquipUIRefresh";
    case 355: return "AvatarEquipChanged";
    case 356: return "AvatarSwitch";
    case 357: return "ManekinCtrl";
    case 358: return "TeamInfoRefresh";
    case 359: return "TeamNameRefresh";
    case 360: return "CurrentTeamChanged";
    case 361: return "AvatarDead";
    case 362: return "AvatarSkillDepotIdChanged";
    case 363: return "AvatarLevelChangedNoDependent";
    case 364: return "AvatarBreakLevelChanged";
    case 365: return "AvatarBreakRewardGet";
    case 366: return "RefreshBreachMaterialBtnRPShow";
    case 367: return "AvatarLifeStateChanged";
    case 368: return "AvatarFetterExpChanged";
    case 369: return "AvatarFetterRewardGet";
    case 370: return "AvatarHPChanged";
    case 371: return "AvatarHPChangedEnd";
    case 372: return "AvatarHPDebtRefresh";
    case 373: return "AvatarHPDebtPayFinish";
    case 374: return "AvatarHPDebtClear";
    case 375: return "AvatarHungerChanged";
    case 376: return "BackgroundAvatarRefreshed";
    case 377: return "AvatarUpgradeNotify";
    case 378: return "AvatarLevelChanged";
    case 379: return "BeyondAvatarPromoteNotify";
    case 380: return "AvatarEnergyAdded";
    case 381: return "AvatarEnergyFull";
    case 382: return "AvatarSpecialEnergyAdded";
    case 383: return "AvatarSpecialEnergyStateChange";
    case 384: return "CharacterSprintBS";
    case 385: return "AvatarSkillChanged";
    case 386: return "AvatarSkillDisable";
    case 387: return "AvatarSkillCDChanged";
    case 388: return "AvatarSkillEnable";
    case 389: return "AvatarHideSkill";
    case 390: return "AvatarAttackModeChanged";
    case 391: return "CurAvatarNum";
    case 392: return "FocusAvatar";
    case 393: return "AvatarFlycloakChanged";
    case 394: return "AvatarGainFlycloak";
    case 395: return "ActivitySkillState";
    case 396: return "ShowActivitySkill";
    case 397: return "RefreshActivitySkillVFX";
    case 398: return "AvatarCostumeChanged";
    case 399: return "AvatarGainCostume";
    case 400: return "AvatarTraceEffectChanged";
    case 401: return "AvatarGainTraceEffect";
    case 402: return "AvatarWeaponSkinChanged";
    case 403: return "AppearanceAvatarChanged";
    case 404: return "AvatarSkillLTChanged";
    case 405: return "AvatarSkillLeftChanged";
    case 406: return "PlayerStaminaChanged";
    case 407: return "AvatarRedPointRefresh";
    case 408: return "AvatarShowHyperLinkExplanation";
    case 409: return "AvatarExtraLevelUpNotify";
    case 410: return "TipShow";
    case 411: return "TipClose";
    case 412: return "ActivityCommonPlayerTipsStart";
    case 413: return "ActivityCommonPlayerTipsFinish";
    case 414: return "ActivityCommonPlayerTipsFinishWithSubtitle";
    case 415: return "ActivityCommonPlayerTipsFail";
    case 416: return "ShopOpen";
    case 417: return "ShopClose";
    case 418: return "ShopItemSelect";
    case 419: return "ShopRefresh";
    case 420: return "ShopMaterialRefresh";
    case 421: return "ShopRequest";
    case 422: return "ShopRequestRecommend";
    case 423: return "ShopRequestPackage";
    case 424: return "ShopMallRequest";
    case 425: return "ShopDataUpdated";
    case 426: return "ActivityShopSheetUpdated";
    case 427: return "ShopOpenSubTab";
    case 428: return "MallJumpRecommend";
    case 429: return "HomeShopCartInfoUpdated";
    case 430: return "OnBuyGoodsSuccess";
    case 431: return "MockAppearanceShopPurchase";
    case 432: return "ActivityRegionSearchProgressUpdate";
    case 433: return "ActivityRegionSearchProgressBegin";
    case 434: return "ActivityRegionSearchProgressComplete";
    case 435: return "ActivityRegionSearchIn";
    case 436: return "ActivityRegionSearchOut";
    case 437: return "ActivityRegionSearchRegionRewardGet";
    case 438: return "ActivityRegionSearchRegionDisappear";
    case 439: return "ActivityRegionSearchRegionAppear";
    case 440: return "ActivityRegionSearchRegionInfoUpdate";
    case 441: return "CountDownUIStart";
    case 442: return "CountDownUIEndLevelTime";
    case 443: return "CountDownUITerminate";
    case 444: return "CountDownUIBegin";
    case 445: return "CountDownUIPause";
    case 446: return "CountDownUIResume";
    case 447: return "CountDownUIEnd";
    case 448: return "DungeonCountDownUpdate";
    case 449: return "DungeonCountDownEnd";
    case 450: return "BeginCustomDungeonCountDown";
    case 451: return "EndCustomDungeonCountDown";
    case 452: return "PauseCustomDungeonCountDown";
    case 453: return "ResumeCustomDungeonCountDown";
    case 454: return "CountNumUIStart";
    case 455: return "CountNumUpdate";
    case 456: return "CountNumUITerminate";
    case 457: return "CountNumUIStartNew";
    case 458: return "CountNumUpdateNew";
    case 459: return "CountNumUITerminateNew";
    case 460: return "QuestQuitShow";
    case 461: return "QuestQuitHide";
    case 462: return "GachaWishUpdate";
    case 463: return "LoadingNewScenePre";
    case 464: return "LoadingScene";
    case 465: return "LevelPreLoaded";
    case 466: return "LevelLoaded";
    case 467: return "LevelPostLoad";
    case 468: return "LevelLoadBegin";
    case 469: return "LoadingBundle";
    case 470: return "LevelLoadFinish";
    case 471: return "QuestTransmitFail";
    case 472: return "NoStaminaStopSprint";
    case 473: return "JumpFly";
    case 474: return "PostAvatarEntityReady";
    case 475: return "AudioEventPost";
    case 476: return "LevelTagNotify";
    case 477: return "SceneAreaWeatherChangeNotify";
    case 478: return "TouchMsgBoard";
    case 479: return "EasyTouchWorking";
    case 480: return "RefreshUISetting";
    case 481: return "ScreenResolutionChanged";
    case 482: return "RefreshAvatarTalent";
    case 483: return "RefreshAvatarTalentPRShow";
    case 484: return "Resist";
    case 485: return "GuideStarted";
    case 486: return "GuideUpdate";
    case 487: return "GuideFinished";
    case 488: return "PageLoad";
    case 489: return "UIContextOpen";
    case 490: return "UIContextClose";
    case 491: return "UIContextCloseFinal";
    case 492: return "PageShow";
    case 493: return "PageDestroy";
    case 494: return "ElementViewChange";
    case 495: return "SealProgress";
    case 496: return "CommonChallengeStartTips";
    case 497: return "CommonChallengeEndTips";
    case 498: return "RefreshGuide";
    case 499: return "RefreshGuideForceInit";
    case 500: return "GeneralGuideFinish";
    case 501: return "GeneralGuideUpdate";
    case 502: return "GuideMaskAppear";
    case 503: return "ActionToUINotify";
    case 504: return "ActionToUINotifyWithTarget";
    case 505: return "ActionToUIQteNotify";
    case 506: return "UIModelSetupEasyTouchClick";
    case 507: return "RefreshDebugUI";
    case 508: return "CheckDebugLoginServerList";
    case 509: return "ShowDebugLoginPanel";
    case 510: return "TimeChanged";
    case 511: return "PlayerGameTimeNotify";
    case 512: return "TeamSceneReady";
    case 513: return "TeamChanged";
    case 514: return "AvatarReviveRequested";
    case 515: return "TeamRttRefresh";
    case 516: return "ShowTeamBtn";
    case 517: return "TeamPageChangeESP";
    case 518: return "FireTeamButtonEffect";
    case 519: return "LevelUpItemFinished";
    case 520: return "PostSetupMPTeamPanel";
    case 521: return "WeaponUpgrade";
    case 522: return "WeaponPromote";
    case 523: return "WeaponAwaken";
    case 524: return "ReliquaryUpgrade";
    case 525: return "ReliquaryPromote";
    case 526: return "TeammateSpeechBegin";
    case 527: return "TeammateSpeechEnd";
    case 528: return "AvatarCardChange";
    case 529: return "SpringVolumeChanged";
    case 530: return "WebviewClose";
    case 531: return "MihoyoAccountInfoChanged";
    case 532: return "MihoyoAccountRegisterSuccess";
    case 533: return "CutsceneStart";
    case 534: return "CutsceneFinish";
    case 535: return "FinalTalkFinished";
    case 536: return "CutsceneQTEJump";
    case 537: return "CurrentQTEFinishCS";
    case 538: return "CurrentQTEBlackScreenStart";
    case 539: return "CutsceneQTEEnableSavePoint";
    case 540: return "CutsceneQTEEnableSavePointId";
    case 541: return "CutsceneChangeTimeScale";
    case 542: return "CutsceneResumeTimeScale";
    case 543: return "InterCutsceneActionStart";
    case 544: return "VideoStart";
    case 545: return "NetworkVideoServerCfgNotFound";
    case 546: return "NetworkVideoSimulateCriErrRecovery";
    case 547: return "BlackScreenStart";
    case 548: return "SetMainPageMoveToggleActive";
    case 549: return "SetMainPageMoveToggleToWalk";
    case 550: return "OpenStateInit";
    case 551: return "OpenStateChange";
    case 552: return "GuestOpenStateInit";
    case 553: return "GuestOpenStateChange";
    case 554: return "StartFadeOutWormhole";
    case 555: return "StartFadeOutTemplateLoading";
    case 556: return "OnAuthorityAvatarAppearBeforeTrans";
    case 557: return "OnAuthorityAvatarAppearAfterTrans";
    case 558: return "EnterSneakMode";
    case 559: return "EnterCombatSneakMode";
    case 560: return "ExitSneakMode";
    case 561: return "PlayModeChange";
    case 562: return "ActionSlotChange";
    case 563: return "ActionPanelStateChangedByPlayModeSys";
    case 564: return "TrainingGuideCustomNetworkAction";
    case 565: return "ActionPanelSetup";
    case 566: return "ActionPanelRefresh";
    case 567: return "ActionPanelClearInputState";
    case 568: return "RefreshActionPanel";
    case 569: return "RefreshCookPage";
    case 570: return "GetCookQTEArgs";
    case 571: return "OnCookRecipeDataNotify";
    case 572: return "RefreshCookCompoundPage";
    case 573: return "GetCompoundOutput";
    case 574: return "CompoundBoostRsp";
    case 575: return "GetCombineOutput";
    case 576: return "CombineFormulaUnlock";
    case 577: return "CombineLimitUpdate";
    case 578: return "SmeltSuccess";
    case 579: return "SmeltGetDrop";
    case 580: return "GetForgeQueue";
    case 581: return "ForgeQueueUpdate";
    case 582: return "GetForgeOutput";
    case 583: return "ForgeStart";
    case 584: return "ForgeStop";
    case 585: return "ForgeFormulaUnlock";
    case 586: return "RefreshMailPage";
    case 587: return "RefreshMailPageAfterDel";
    case 588: return "MailDataReady";
    case 589: return "ShowMailItemGet";
    case 590: return "NewMailGot";
    case 591: return "AddToFavorites";
    case 592: return "RefreshMailFavoritesDialog";
    case 593: return "RefreshMailFavoritesDialogAfterDel";
    case 594: return "RefreshMailPageAfterFavMailChange";
    case 595: return "FavoriteMailDataReady";
    case 596: return "RefreshCoinNum";
    case 597: return "MutiPlayerAvailableChange";
    case 598: return "MutiPlayerModeChange";
    case 599: return "CompanionCurrAvatarChanged";
    case 600: return "CompanionAvatarHPChangedEnd";
    case 601: return "KickGuestFailed";
    case 602: return "MPTeamChangeFailed";
    case 603: return "MPDeathOpenChat";
    case 604: return "MPCloseMainPageBtn";
    case 605: return "MPOpenMainPageBtn";
    case 606: return "PlayerMatchInfoUpdate";
    case 607: return "WorldPlayerDie";
    case 608: return "MpSettingType";
    case 609: return "JoinOtherPlayerScene";
    case 610: return "BackMyWorld";
    case 611: return "DraftOwnerStartInviteRsp";
    case 612: return "DraftInviteResult";
    case 613: return "PlayerMatchAgreedResult";
    case 614: return "UpdateDungeonExitBtn";
    case 615: return "DungeonTeamChanged";
    case 616: return "DungeonTeamChangeFailed";
    case 617: return "DungeonTeamDismissed";
    case 618: return "DungeonInviteRefused";
    case 619: return "DungeonTeamKicked";
    case 620: return "EnterTowerLevel";
    case 621: return "TowerStarRefresh";
    case 622: return "TowerRecordHandbookRefresh";
    case 623: return "DungeonBanSwitchTeam";
    case 624: return "DungeonEnterTeamInfo";
    case 625: return "RefreshPlayGuestState";
    case 626: return "CloseMPPlayDialog";
    case 627: return "CloseMPPlayPage";
    case 628: return "RefreshMPPlayDialogTwiceConfirm";
    case 629: return "MpPlayGuestReplyInviteSucc";
    case 630: return "OnGuestPostEnterSceneNotify";
    case 631: return "GCGMatchSucc";
    case 632: return "GCGMatchStateUpdated";
    case 633: return "GCGBattleInvitationStateUpdated";
    case 634: return "CloseGCGMatchDialog";
    case 635: return "GCGWorldPlayerStateGot";
    case 636: return "PlayerMatchAgreedResultNotify";
    case 637: return "MpPlayInviteResultNotify";
    case 638: return "ScenePlayInviteResultNotify";
    case 639: return "DraftInviteResultNotify";
    case 640: return "DraftTwiceConfirmResultNotify";
    case 641: return "PlayerPreEnterMp";
    case 642: return "PlayerLevelChange";
    case 643: return "PlayerBeyondLevelChanged";
    case 644: return "PlayerExpChange";
    case 645: return "PlayerWorldLevelChange";
    case 646: return "ClosePlayerProfilePage";
    case 647: return "PlayerWorldLevelAdjust";
    case 648: return "ShowGuideRatingDialog";
    case 649: return "PlayerCanDiveUpdate";
    case 650: return "ChargeBarValueChange";
    case 651: return "ProgressBarRefresh";
    case 652: return "InitProgressTip";
    case 653: return "RefreshProgressTip";
    case 654: return "BlinkProgressTip";
    case 655: return "DestroyProgressTip";
    case 656: return "DailyTaskStarted";
    case 657: return "DailyTaskProgresUpdated";
    case 658: return "DailyTaskComplete";
    case 659: return "DailyTaskExitRegion";
    case 660: return "DailyTaskScoreReward";
    case 661: return "DailyTaskAttendanceReward";
    case 662: return "DailyTaskAttendanceUpdate";
    case 663: return "DailyTaskRefresh";
    case 664: return "WorldOwnerDailyTaskUpdate";
    case 665: return "TaskVarChange";
    case 666: return "RandTaskStarted";
    case 667: return "RandTaskComplete";
    case 668: return "RandTaskFail";
    case 669: return "RandTaskExitRegion";
    case 670: return "RoutineStarted";
    case 671: return "RoutineProgresUpdated";
    case 672: return "RoutineComplete";
    case 673: return "RoutineExitRegion";
    case 674: return "RoutineScoreReward";
    case 675: return "RoutineRefresh";
    case 676: return "ProudSkillUpgrade";
    case 677: return "ProudSkillChange";
    case 678: return "CombatSkillChange";
    case 679: return "PlayerLevelRewardChange";
    case 680: return "GetInvestigationMonsterFail";
    case 681: return "GetInvestigationMonsterList";
    case 682: return "GetInvestigationMonsterListForMark";
    case 683: return "InvestigationChange";
    case 684: return "InvestigationChapterComplete";
    case 685: return "InvestigationTargetChange";
    case 686: return "InvestigationQuestDailyNotify";
    case 687: return "InvestigationUnlock";
    case 688: return "InvestigationUpdate";
    case 689: return "TrackGatherGroupRefresh";
    case 690: return "ExplorationAllDataChange";
    case 691: return "ExplorationCharacterDataChange";
    case 692: return "MainPageTips";
    case 693: return "MiracleRingItemAdded";
    case 694: return "NewPlayerAppling";
    case 695: return "PushTipsChange";
    case 696: return "GetPushTipsReward";
    case 697: return "PushTipsNotifyFinish";
    case 698: return "NewPushTips";
    case 699: return "PushTipsReactive";
    case 700: return "GetTowerAllData";
    case 701: return "GetTowerStarReward";
    case 702: return "GetTowerSkipFloorReward";
    case 703: return "TowerSkipFloorClose";
    case 704: return "TowerFinishLevelSettle";
    case 705: return "TowerFloorRecordRefresh";
    case 706: return "VersusBattleBegin";
    case 707: return "VersusBattleUpdate";
    case 708: return "VersusBattleEnd";
    case 709: return "NatlanBallVSBegin";
    case 710: return "NatlanBallVSEnd";
    case 711: return "ActivityOpen";
    case 712: return "ActivityClose";
    case 713: return "ActivityContextClose";
    case 714: return "ActivityRefresh";
    case 715: return "ActivityUpdate";
    case 716: return "ActivityBannerShow";
    case 717: return "ActivityBannerEffectShow";
    case 718: return "ActivitySeaLampContriFinish";
    case 719: return "ActivityStart";
    case 720: return "ActivityCrucibleInfo";
    case 721: return "ActivityOperationBonusUpdate";
    case 722: return "ActivityWatcherUpdate";
    case 723: return "ActivityDeliveryRewardUpdate";
    case 724: return "ActivityDeliveryUpdate";
    case 725: return "ActivityWatcherFinish";
    case 726: return "ActivityAsterScoreUpdate";
    case 727: return "ActivitySaleUpdate";
    case 728: return "ActivityEchoShellUpdate";
    case 729: return "ActivityCoinInfoNotify";
    case 730: return "ActivityBlitzRushContentClose";
    case 731: return "ActivityCondUpdate";
    case 732: return "ActivityScrollSwitch";
    case 733: return "ActivityClientPlayStartRsp";
    case 734: return "ActivityClientPlayFinishRsp";
    case 735: return "ActivityClientPlayStartRspSucc";
    case 736: return "ActivityClientPlayFinishRspSucc";
    case 737: return "ActivityPushTipsUpdate";
    case 738: return "ActivityDebugClose";
    case 739: return "ActivityTakeBatchWatcherReward";
    case 740: return "ActivityPotionStageReset";
    case 741: return "RefreshRadarHintEffect";
    case 742: return "CloseActivityMainPage";
    case 743: return "EffigyChallengeResultNotify";
    case 744: return "MistTrialTimeOutNotify";
    case 745: return "BannerReminderAppeared";
    case 746: return "BannerReminderDisappeared";
    case 747: return "BannerReminderForceClosed";
    case 748: return "BannerReminderForceInterrupt";
    case 749: return "BannerReminderAppeareForComponent";
    case 750: return "SpecialBannerReminderAppeared";
    case 751: return "SpecialBannerReminderDisappeared";
    case 752: return "CommonSpecialReminderAppeared";
    case 753: return "CommonSpecialReminderDisappeared";
    case 754: return "InstituteHomeReminderAppeared";
    case 755: return "InstituteHomeReminderDisappeared";
    case 756: return "InLevelQuestHintReminderAppeared";
    case 757: return "InLevelQuestHintReminderDisappeared";
    case 758: return "ChallengeBannerStartAppeared";
    case 759: return "ChallengeBannerDisappeared";
    case 760: return "DialogueWithPortraitReminderAppeared";
    case 761: return "DialogueWithPortraitReminderDisappeared";
    case 762: return "CombatChatAppeared";
    case 763: return "CombatChatDisappeared";
    case 764: return "CombatChatFinish";
    case 765: return "CombatChatDialogAppeared";
    case 766: return "CombatChatDialogDisappeared";
    case 767: return "TalkPanelReminderAppeared";
    case 768: return "TalkPanelReminderDisappeared";
    case 769: return "OnGetGameplayRecommendationNotify";
    case 770: return "CloseRecommendationNotify";
    case 771: return "OnGetGameplayRecommendationFailedNotify";
    case 772: return "CameraLookBegin";
    case 773: return "CameraLookBeginWithFadeAfterTime";
    case 774: return "CameraLookEnd";
    case 775: return "CameraLock";
    case 776: return "CameraFieldLook";
    case 777: return "OnCameraDiveStateSpawn";
    case 778: return "DisableMainPageControl";
    case 779: return "DisableMainPageControlWithConfigName";
    case 780: return "DisableMainPageControlRollerCoasterSpecialCamera";
    case 781: return "DisableMainPageChat";
    case 782: return "TerminateMainPageTeamCountDown";
    case 783: return "HideSpecificUIShowPaimon";
    case 784: return "ResinChanged";
    case 785: return "ResinPurchased";
    case 786: return "BlossomBriefInfoNotify";
    case 787: return "BlossomStart";
    case 788: return "BlossomUpdate";
    case 789: return "BlossomEnd";
    case 790: return "BlossomFinish";
    case 791: return "ShowDamageTextComponent";
    case 792: return "SinInRefresh";
    case 793: return "OnSignInInfoRsp";
    case 794: return "BonusActivityRewardRsp";
    case 795: return "ShowActivityMainBtn";
    case 796: return "OnBonusActivityInfoRsp";
    case 797: return "OnOpActivityStateRsp";
    case 798: return "OnOpActivityStateNotify";
    case 799: return "TrialActivityRewardUpdate";
    case 800: return "SalesManTakeRewardRsp";
    case 801: return "SalesmanDeliverItemRsp";
    case 802: return "GetAuthSalesmanInfoRsp";
    case 803: return "OnVirtualDialHandleCloseWheelMenuAction";
    case 804: return "OnVirtualDialAction";
    case 805: return "OnVirtualDialEntryAction";
    case 806: return "CloseVirtualDial";
    case 807: return "OpenBeyondVirtualDial";
    case 808: return "OnTransmitStart";
    case 809: return "OnTransmitEnd";
    case 810: return "OnTransmitAfterAudioEvent";
    case 811: return "BundleDownloadStart";
    case 812: return "BundleDownloadRestart";
    case 813: return "BundleDownloadStartForLogin";
    case 814: return "BargainStart";
    case 815: return "BargainPriceRsp";
    case 816: return "BargainTerminate";
    case 817: return "BargainDataRsp";
    case 818: return "AllActivatedBargainData";
    case 819: return "HideRoom";
    case 820: return "ShowRoom";
    case 821: return "DeleteFriend";
    case 822: return "AddFriend";
    case 823: return "RefreshFriendList";
    case 824: return "RefreshFriendListWithAni";
    case 825: return "RefreshFriendRequestList";
    case 826: return "RefreshFriendRequestListWithAni";
    case 827: return "RefreshFriendRequestListAndKeepPosition";
    case 828: return "RefreshBlacklist";
    case 829: return "RefreshMultiplayRecentlyListWithAni";
    case 830: return "RefreshPSNFriendList";
    case 831: return "RefreshPSNFriendListWithAni";
    case 832: return "GetPlayerSocialDetail";
    case 833: return "GetPlayerSocialDetailFail";
    case 834: return "OnGetPlayerBriefListRsp";
    case 835: return "GetFriendShowAvatarInfo";
    case 836: return "GetFriendShowAvatarInfoInCD";
    case 837: return "RefreshNickname";
    case 838: return "RefreshRemarkname";
    case 839: return "RefreshHeadPortrait";
    case 840: return "RefreshNameCard";
    case 841: return "RefreshAllNameCard";
    case 842: return "RefreshSignature";
    case 843: return "RefreshAvatarShowList";
    case 844: return "RefreshNameCardShowList";
    case 845: return "NicknameWordIllegal";
    case 846: return "TeamNameIllegal";
    case 847: return "SignatureIllegal";
    case 848: return "RefreshBirthday";
    case 849: return "AddInBlockChatList";
    case 850: return "RemoveFromBlockChatList";
    case 851: return "AddInBlacklist";
    case 852: return "RemoveFromBlacklist";
    case 853: return "ChatRoomInfoUpdate";
    case 854: return "SetActivitySocialPublicRsp";
    case 855: return "GetSimplePlayerBriefListFailed";
    case 856: return "GetSimplePlayerBriefListSuccess";
    case 857: return "RefreshMainPageChatContent";
    case 858: return "RefreshMainPageChatContentForce";
    case 859: return "RefreshChatEmojiCollectionList";
    case 860: return "RefreshStrangerListFormal";
    case 861: return "RefreshStrangerListTempRecv";
    case 862: return "RefreshStrangerListTempRecvRemove";
    case 863: return "RefreshStrangerListTempSend";
    case 864: return "ClearStrangerChatInfoByMuip";
    case 865: return "ChatChannelContentShrink";
    case 866: return "ClearGlobalChatByMuip";
    case 867: return "GlobalChannelChatOnLimit";
    case 868: return "StrangerChatSysConfigSet";
    case 869: return "BeyondPlayerDetailOnlineInfoStrangerOnRsp";
    case 870: return "ChatChannelBanStateUpdate";
    case 871: return "ChatChannelHideStateUpdate";
    case 872: return "ChatTryMentionUid";
    case 873: return "ChatMentionInfoUpdate";
    case 874: return "ChatUGCChannelUpdate";
    case 875: return "ChatSpecialInfoStatesChange";
    case 876: return "OnChatDialogOpen";
    case 877: return "OpenMainPageChatDialog";
    case 878: return "VoiceChannelWillUpdate";
    case 879: return "VoiceChannelUpdated";
    case 880: return "BattlePassMissionChange";
    case 881: return "BattlePassScheduleChange";
    case 882: return "BattlePassProductPay";
    case 883: return "BattlePassLevelChange";
    case 884: return "BattlePassBuySuccess";
    case 885: return "BattlePassSetRewardPlanSuccess";
    case 886: return "BattlePassSetRewardPlanSuccessButRewardChangeForbidden";
    case 887: return "BattlePassSetRewardPlanFailure";
    case 888: return "BattlePassGetMissionRewardItem";
    case 889: return "BattlePassGetMissionRewardItemFinish";
    case 890: return "RefreshLocalNotification";
    case 891: return "EnterSceneDone";
    case 892: return "PSNStateChange";
    case 893: return "PS5LaunchActivity";
    case 894: return "MpPlayPrepareNotify";
    case 895: return "GadgetPlayStartNotify";
    case 896: return "GadgetPlayDataNotify";
    case 897: return "GadgetPlayUidOpNotify";
    case 898: return "GadgetPlayStopNotify";
    case 899: return "GadgetChainChangeNotify";
    case 900: return "ScenePlayBattlePrepare";
    case 901: return "ScenePlayBattlePrestart";
    case 902: return "ScenePlayBattleStart";
    case 903: return "ScenePlayBattleStop";
    case 904: return "ScenePlayBattleInterrupt";
    case 905: return "ScenePlayUidOpNotify";
    case 906: return "StartChargeCountDown";
    case 907: return "InterruptChargeCountDown";
    case 908: return "ShowTemplateReminderNotify";
    case 909: return "StopTemplateReminderNotify";
    case 910: return "CloseTemplateReminderDialog";
    case 911: return "ShowPromptDownReminderNotify";
    case 912: return "ForceDestroyPromptDownReminderNotify";
    case 913: return "NormalUidOpNotify";
    case 914: return "OnDispatchConfigSet";
    case 915: return "ShowDistanceTarget";
    case 916: return "ShowDistanceTargetV2";
    case 917: return "CloseDistanceTarget";
    case 918: return "ClimateMeterType";
    case 919: return "ClimateMeterValue";
    case 920: return "ClimateAreaType";
    case 921: return "ClimateAreaID";
    case 922: return "ClimateMeterValueChanged";
    case 923: return "ClimateMeterTypeChanged";
    case 924: return "ClimateAreaTypeChanged";
    case 925: return "ClimateMeterWarning";
    case 926: return "ClimateMeterRefresh";
    case 927: return "ShowClimateInfoDialog";
    case 928: return "ShowSpecifiedClimateInfoDialog";
    case 929: return "DungeonFactorDialogOpen";
    case 930: return "DungeonFactorDialogClose";
    case 931: return "ShowRestrictionEffect";
    case 932: return "ShowMonthlyCardReward";
    case 933: return "AchievementPageRefresh";
    case 934: return "AchievementItemAdded";
    case 935: return "AvatarFilterSetActiveCond";
    case 936: return "AvatarFilterSetExpanded";
    case 937: return "AvatarFilterVisionStateChanged";
    case 938: return "AvatarFilterCloseFilterDialog";
    case 939: return "BeyondPlayerFilterSetExpanded";
    case 940: return "GeneralFilterSetActiveCond";
    case 941: return "GeneralFilterSetExpanded";
    case 942: return "GeneralFilterVisionStateChanged";
    case 943: return "GeneralFilterCloseFilterDialog";
    case 944: return "RefreshAvatarLinePage";
    case 945: return "OnPersonalLineAllDataRsp";
    case 946: return "AvatarLineGetKey";
    case 947: return "AvatarLineUnlock";
    case 948: return "AvatarLineAccept";
    case 949: return "ShareComplete";
    case 950: return "SDKPayStart";
    case 951: return "SDKPayEnd";
    case 952: return "SDKGetProductList";
    case 953: return "AvatarAddNotify";
    case 954: return "TrialAvatarDelete";
    case 955: return "OnTakeReputationLevelReward";
    case 956: return "RefreshReputation";
    case 957: return "OnCityReputationLevelup";
    case 958: return "RefreshHunting";
    case 959: return "HuntingStart";
    case 960: return "HuntingRevealClue";
    case 961: return "HuntingRevealFinal";
    case 962: return "HuntingSuccess";
    case 963: return "HuntingFail";
    case 964: return "CloseReputationHuntingDialog";
    case 965: return "CloseReputationRequestDialog";
    case 966: return "HuntingTaken";
    case 967: return "HuntingFinished";
    case 968: return "CityReputationDonationInfoUpdate";
    case 969: return "CityReputationDonationInfoRsp";
    case 970: return "CityReputationDonationRewardTaken";
    case 971: return "TribalReputationInfoUpdate";
    case 972: return "TribalExpAdd";
    case 973: return "CityReputationTotalRewardInfoUpdate";
    case 974: return "HuntingV2OfferUpdate";
    case 975: return "HuntingV2Start";
    case 976: return "HuntingV2Success";
    case 977: return "HuntingV2Fail";
    case 978: return "FlowerLandReputationInfoUpdate";
    case 979: return "OfferingDataUpdated";
    case 980: return "TakeOfferingLevelReward";
    case 981: return "OfferingLevelChange";
    case 982: return "OfferingLevelChangeReward";
    case 983: return "ForbiddenToggleMoveStateChange";
    case 984: return "OnToggleMoveSettingChange";
    case 985: return "KeyboardLayoutUpdate";
    case 986: return "ControllerMapModified";
    case 987: return "OnControllerConnected";
    case 988: return "OnDeviceTypeSet";
    case 989: return "SetDeviceTypeInSettingPage";
    case 990: return "OnJoypadIconDisplayTypeChange";
    case 991: return "OnInputHotSwap";
    case 992: return "InputDeviceChanged";
    case 993: return "OnControllerDisConnected";
    case 994: return "WidgetActionBtnRefresh";
    case 995: return "WidgetEquipChange";
    case 996: return "WidgetCollectorWindSeed";
    case 997: return "WidgetQuickUseButtonRelease";
    case 998: return "JoypadTriggerWidgetQuickUseButton";
    case 999: return "WidgetQuickUseRsp";
    case 1000: return "ForcePlayBattleBtnCdEndEffect";
    case 1001: return "WidgetWeatherWizardValueUpdate";
    case 1002: return "WidgetQuickSwitchListChange";
    case 1003: return "WidgetSwitchDialogOpen";
    case 1004: return "WidgetWispCageUpdate";
    case 1005: return "WidgetWispCageDiscard";
    case 1006: return "WidgetWispCageItemAdded";
    case 1007: return "WidgetBackGroundStateChanged";
    case 1008: return "WidgetByIsGadgetExistNotify";
    case 1009: return "WidgetSlotChange";
    case 1010: return "FlightChallengeBegin";
    case 1011: return "FlightChallengeFinish";
    case 1012: return "ReportSuccNotify";
    case 1013: return "PlayerQuitFromMpByHostBlock";
    case 1014: return "PlayerQuitFromMpByGuestBlock";
    case 1015: return "PlayerQuitFromMpByHostAdsBlock";
    case 1016: return "PlayerQuitFromMpByGuestAdsBlock";
    case 1017: return "ActivityBlessingDataRefresh";
    case 1018: return "ActivityBlessingScanSuccess";
    case 1019: return "ActivityBlessingScanFail";
    case 1020: return "ActivityBlessingRefresh";
    case 1021: return "ActivityGiveFriendPicSuccess";
    case 1022: return "TreasureHuntCurrencyNumChange";
    case 1023: return "ReunionAddToOpActivityListNotify";
    case 1024: return "ReunionRemoveFromOpActivityListNotify";
    case 1025: return "ReunionOpenNotify";
    case 1026: return "ReunionCloseNotify";
    case 1027: return "ReunionGetFirstRewardSuccNotify";
    case 1028: return "ReunionSignInGetRewardNotify";
    case 1029: return "ReunionTaskClaimFinalRewardSuccNotify";
    case 1030: return "ReunionTaskClaimWatcherRewardSuccNotify";
    case 1031: return "ReunionShowBannerNotify";
    case 1032: return "ReunionRecommendAvatarUpdateNotify";
    case 1033: return "ReunionRecommendRegionUpdateNotify";
    case 1034: return "ReunionRecommendQuestUpdateNotify";
    case 1035: return "ReunionSignInInfoUpdateNotify";
    case 1036: return "ReunionPrivilegeInfoUpdateNotify";
    case 1037: return "ReunionMissionUpdateNotify";
    case 1038: return "ReunionMainPageEffectShowNotify";
    case 1039: return "ReunionVideoUpdateNotify";
    case 1040: return "AvatarExpeditionStartNtf";
    case 1041: return "ShowLendHistoryNotify";
    case 1042: return "ExpeditionActivityStartNotify";
    case 1043: return "ExpeditionActivityRecallNotify";
    case 1044: return "ExpeditionActivityRewardClaimedNotify";
    case 1045: return "ExpeditionActivityInfoUpdateNotify";
    case 1046: return "OpenExpeditionMap";
    case 1047: return "OnExpeditionChallengeEnterRegion";
    case 1048: return "OnExpeditionChallengeFinish";
    case 1049: return "GetExpeditionRewardNotify";
    case 1050: return "GadgetGroupButtonAddNotify";
    case 1051: return "GadgetGroupButtonRemoveNotify";
    case 1052: return "NetworkVoiceSendVolumeChanged";
    case 1053: return "NetworkVoiceReceiveVolumeChanged";
    case 1054: return "NetworkVoiceBlockDataUpdated";
    case 1055: return "NetworkVoiceUsingMobileMicChanged";
    case 1056: return "ActivityUpdateRegion";
    case 1057: return "WalkModeChanged";
    case 1058: return "FireUIEffectNotify";
    case 1059: return "AttachUIEffectNotify";
    case 1060: return "UntachUIEffectNotify";
    case 1061: return "FireUIMultiCombatBarEffectNotify";
    case 1062: return "AttachUIMultiCombatBarEffectNotify";
    case 1063: return "DetachUIMultiCombatBarEffectNotify";
    case 1064: return "SendUIEffectAnimatorNotify";
    case 1065: return "PlayerApplyEnterMpResult";
    case 1066: return "PlayerQuitFromMp";
    case 1067: return "PlayerVehilceUpdate";
    case 1068: return "UpdateFriendsWishNotify";
    case 1069: return "UpdateRecvGiftsNotify";
    case 1070: return "UpdateGiftRecvInfoNotify";
    case 1071: return "UpdateGiveGiftDialog";
    case 1072: return "HaveRecvGiftNotify";
    case 1073: return "OnActivitySetGiftWishRsp";
    case 1074: return "GachaActivityPercentNotify";
    case 1075: return "GachaActivityCreateRobotRsp";
    case 1076: return "GachaActivityResetRsp";
    case 1077: return "GachaActivityTakeRewardRsp";
    case 1078: return "GachaActivityNextStageRsp";
    case 1079: return "GetMechanicusInfoRsp";
    case 1080: return "UpdateGearItem";
    case 1081: return "UnLockGearItem";
    case 1082: return "FoundationOpLockFailed";
    case 1083: return "MechanicusCoinNotify";
    case 1084: return "FoundationUpdateNotify";
    case 1085: return "OnInBattleMechanicusStageKillStartNotify";
    case 1086: return "OnInBattleMechanicusStageKillEndNotify";
    case 1087: return "OnInBattleMechanicusStageCardFlipEndNotify";
    case 1088: return "OnInBattleMechanicusStart";
    case 1089: return "OnInBattleMechanicusUpdate";
    case 1090: return "OnInBattleMechanicusFinish";
    case 1091: return "OnInBattleMechanicusPickCardRsp";
    case 1092: return "OnInBattleMechanicusPickCardNotify";
    case 1093: return "OnInBattleMechanicusConfirmCardRsp";
    case 1094: return "OnInBattleMechanicusConfirmCardNotify";
    case 1095: return "OnInBattleMechanicusCardResultNotify";
    case 1096: return "OnInBattleChessPickCardNotify";
    case 1097: return "OnInBattleChessCandidateCardsNotify";
    case 1098: return "FleurFairDungeonPreview";
    case 1099: return "FleurFairDungeonPrepare";
    case 1100: return "FleurFairDungeonGallery";
    case 1101: return "FleurFairDungeonBoss";
    case 1102: return "FleurFairDungeonGallerySettle";
    case 1103: return "FleurFairDungeonBossSettle";
    case 1104: return "FleurFairDungeonEnergy";
    case 1105: return "FleurFairDungeonGalleryUpdate";
    case 1106: return "SummerTimeStage4JoypadFocusChange";
    case 1107: return "SummerTimeSprintBoatRedpointChange";
    case 1108: return "GalleryDialogShow";
    case 1109: return "GalleryPreStart";
    case 1110: return "GalleryStart";
    case 1111: return "GalleryStop";
    case 1112: return "GalleryUpdateAll";
    case 1113: return "GalleryPreStartEndTimeChange";
    case 1114: return "GalleryModuleComponentInit";
    case 1115: return "GalleryModuleComponentDestroy";
    case 1116: return "GalleryModuleComponentPreStart";
    case 1117: return "GalleryModuleComponentStart";
    case 1118: return "GalleryModuleComponentRecover";
    case 1119: return "GalleryModuleComponentStop";
    case 1120: return "CheckGalleryPlay";
    case 1121: return "GalleryDialogOnRefresh";
    case 1122: return "GalleryBalloonShoot";
    case 1123: return "GalleryBalloonScore";
    case 1124: return "GalleryFallCatch";
    case 1125: return "GalleryFallScore";
    case 1126: return "GalleryMusicGameClose";
    case 1127: return "GallerySettleRestart";
    case 1128: return "GalleryPreInitCountDownStart";
    case 1129: return "GalleryPreInitCountDownEnd";
    case 1130: return "RefreshAvatarPanel";
    case 1131: return "CheckUIOpenState";
    case 1132: return "GalleryPhotoStop";
    case 1133: return "GalleryForceHideSideAlpha";
    case 1134: return "SlabCheckEnterLoopDungeon";
    case 1135: return "SlabEquipBuffChange";
    case 1136: return "GallerySumoStageStart";
    case 1137: return "GallerySumoStageFinish";
    case 1138: return "GallerySumoChangeTeam";
    case 1139: return "GallerySumoChangeTeamCdUpdate";
    case 1140: return "GallerySumoChangeTeamUpdateScore";
    case 1141: return "StartCrystalLinkGalleryNotify";
    case 1142: return "UpdateCrystalLinkGalleryNotify";
    case 1143: return "StopCrystalLinkGalleryNotify";
    case 1144: return "CrystalLinkBuffUpdate";
    case 1145: return "CrystalLinkBuffEffect";
    case 1146: return "CrystalLinkBuffActiveNotify";
    case 1147: return "QuickSwitchTeamFetchNextTeamInfo";
    case 1148: return "QuickSwitchTeamReqToChangeTeam";
    case 1149: return "ArenaChallengeStart";
    case 1150: return "ArenaChallengeTakeWatcherReward";
    case 1151: return "ActivityMistTrialTakeReward";
    case 1152: return "ActivityMistTrialExhibitionRefresh";
    case 1153: return "ActivityMistTrialGalleryCountDown";
    case 1154: return "ActivityMiniTomoClose";
    case 1155: return "HomeWorldCompInfoUpdate";
    case 1156: return "HomeWorldModuleChange";
    case 1157: return "HomeWorldModuleChoose";
    case 1158: return "HomeWorldModuleSeenUpdate";
    case 1159: return "HomeWorldModulePrepareGoIn";
    case 1160: return "HomeWorldFurnitureMakeInfoRefresh";
    case 1161: return "HomeWorldFurnitureMakeGetResult";
    case 1162: return "HomeWorldFurnitureMakeCancel";
    case 1163: return "HomeWorldFurnitureFormulaUnlock";
    case 1164: return "HomeWorldLevelUp";
    case 1165: return "HomeWorldSuiteDetailShow";
    case 1166: return "GetHomeworldVisitor";
    case 1167: return "HomeKickPlayerRspSuccess";
    case 1168: return "HomeWorldComfortInfoUpdate";
    case 1169: return "ClearDeployGadgetData";
    case 1170: return "HomeWorldChangeBGM";
    case 1171: return "HomeWorldUnlockBGM";
    case 1172: return "HomeWorldBlueprintSearchInfoUpdate";
    case 1173: return "HomeWorldNpcSpawnForAllEnvironment";
    case 1174: return "HomeWorldNpcRemoveForAllEnvironment";
    case 1175: return "ReplyApplyingGuest";
    case 1176: return "MpInvitationListShow";
    case 1177: return "HideAndSeekStagePrepare";
    case 1178: return "HideAndSeekStagePick";
    case 1179: return "HideAndSeekStageHide";
    case 1180: return "HideAndSeekStageSeek";
    case 1181: return "HideAndSeekPlayerSetAvatarNotify";
    case 1182: return "HideAndSeekSelectSkillRsp";
    case 1183: return "HideAndSeekPlayerReadyNotify";
    case 1184: return "HideAndSeekStageSettle";
    case 1185: return "HideAndSeekCaught";
    case 1186: return "HideAndSeekBecomeGhost";
    case 1187: return "HideAndSeekPlayerChosenMapUpdate";
    case 1188: return "HideAndSeekV4GalleryDataUpdate";
    case 1189: return "HideAndSeekV4Caught";
    case 1190: return "HideAndSeekV4BecomeGhost";
    case 1191: return "HideAndSeekV4PlayerSetAvatarNotify";
    case 1192: return "HideAndSeekV4SelectSkillRsp";
    case 1193: return "HideAndSeekV4PlayerReadyNotify";
    case 1194: return "HideAndSeekV4MultistagePlayInfoUpdate";
    case 1195: return "HideAndSeekV4PlayerChosenMapUpdate";
    case 1196: return "HideAndSeekV4Settle";
    case 1197: return "AvatarChargeSkillNotify";
    case 1198: return "LoginSceneNotify";
    case 1199: return "CharacterPageNotify";
    case 1200: return "CloseCharacterPageNotify";
    case 1201: return "WeaponPageNotify";
    case 1202: return "CloseWeaponPageNotify";
    case 1203: return "LoadingBeginNotify";
    case 1204: return "LoadingEndNotify";
    case 1205: return "GachaItemNotify";
    case 1206: return "CloseGachaNotify";
    case 1207: return "GoToGachaPageNotify";
    case 1208: return "GrowFlowersUpdateTodaySeedNotify";
    case 1209: return "GrowFlowersUpdateExchangePage";
    case 1210: return "GrowFlowersUpdateFriendsWishNotify";
    case 1211: return "GrowFlowersUpdateRecvFlowersNotify";
    case 1212: return "GrowFlowersUpdateRecvInfo";
    case 1213: return "GrowFlowersUpdateGiveDialog";
    case 1214: return "WinterCampSnowmanUpdateFriendsWishNotify";
    case 1215: return "WinterCampSnowmanUpdateRecvItemNotify";
    case 1216: return "WinterCampSnowmanUpdateRecvInfo";
    case 1217: return "WinterCampSnowmanUpdateGiveDialog";
    case 1218: return "StartBuoyantCombatGallerySuccess";
    case 1219: return "StartBuoyantCombatGalleryNotify";
    case 1220: return "UpdateBuoyantCombatGalleryNotify";
    case 1221: return "StopBuoyantCombatGalleryNotify";
    case 1222: return "StartGalleryProgressNotify";
    case 1223: return "UpdateGalleryProgressNotify";
    case 1224: return "StopGalleryProgressNotify";
    case 1225: return "StartDigCombatGalleryNotify";
    case 1226: return "UpdateDigCombatGalleryNotify";
    case 1227: return "StopDigCombatGalleryNotify";
    case 1228: return "SalvagePreventUpdateNotify";
    case 1229: return "SalvageEscortUpdateNotify";
    case 1230: return "UpdateSalvageBundleMark";
    case 1231: return "UpdateBounceConjuringScore";
    case 1232: return "AddBounceConjuringScore";
    case 1233: return "LunaRiteSacrificeSuccess";
    case 1234: return "LunaRiteRefresh";
    case 1235: return "MoonfinTrialWatcherUpdated";
    case 1236: return "TryShowQTEDialog";
    case 1237: return "EnableSubtitleInputPenetrate";
    case 1238: return "OnQTEButtonClick";
    case 1239: return "ShowQTEReminder";
    case 1240: return "ShowUITriggerQTE";
    case 1241: return "ShowAbyssPurify";
    case 1242: return "CodexKillNumRefresh";
    case 1243: return "FishCastRod";
    case 1244: return "FishBaitUpdate";
    case 1245: return "FishQteStart";
    case 1246: return "FishBattleEnd";
    case 1247: return "ExitFishing";
    case 1248: return "FishRippleEffectStart";
    case 1249: return "FishRippleEffectEnd";
    case 1250: return "OnShikigamiSkillUpgrade";
    case 1251: return "OnRefreshRoguelikeDungeonCardRsp";
    case 1252: return "OnTakeRoguelikeStageFirstPassReward";
    case 1253: return "OnEnterRoguelikeDungeonNotify";
    case 1254: return "ActivityRogueContentClose";
    case 1255: return "CustomGadgetSubmitRsp";
    case 1256: return "IrodoriEditFlowerSubmitRsp";
    case 1257: return "CustomGadgetPendingDataUnexpectedlyRemoved";
    case 1258: return "ProjectionGameGuideFinishFreeRotationXY";
    case 1259: return "ProjectionGameGuideFinishFreeRotationZ";
    case 1260: return "ProjectionGameGuideFinishSwitch";
    case 1261: return "ProjectionGameAnswerUnlocked";
    case 1262: return "FireworkMakerRefreshPage";
    case 1263: return "FireworkReformSettlement";
    case 1264: return "LanternRiteStartFireworksReformRsp";
    case 1265: return "LanternRiteDoFireworksReformRsp";
    case 1266: return "LanternRiteEndFireworksReformRsp";
    case 1267: return "LanternRiteEndFireworksReform";
    case 1268: return "LanternRiteFireworksReformDoOnce";
    case 1269: return "LocalAvatarDoSkillSucc";
    case 1270: return "BattleFervorAuthorityOnBeingHit";
    case 1271: return "BattleFervorAttackDamageResult";
    case 1272: return "BattleFervorKilledNotify";
    case 1273: return "BattleFervorMaterialAdd";
    case 1274: return "BattleFervorChestStateChanged";
    case 1275: return "SendBuyGoodsReq";
    case 1276: return "CustomLevelDungeonUpdate";
    case 1277: return "CustomDungeonTryTypeChanged";
    case 1278: return "CustomLevelSearchResult";
    case 1279: return "CustomLevelSubscribeResult";
    case 1280: return "CustomLevelLikeResult";
    case 1281: return "CustomLevelSaveResult";
    case 1282: return "UGCCandidateDataChange";
    case 1283: return "UGCCandidateTeamProcessDataChange";
    case 1284: return "OnUGCDungeonCandidateTeamInfoNotify";
    case 1285: return "UGCGalleryStart";
    case 1286: return "UGCGalleryStop";
    case 1287: return "UGCUpdateLeftDeathCount";
    case 1288: return "BeforeHandleUGCSettleNotify";
    case 1289: return "UGCSocialDataUpdateByProto";
    case 1290: return "UGCSocialDataUpdateByClient";
    case 1291: return "ForceCloseUploadDialog";
    case 1292: return "OnPublishUgcDungeonRsp";
    case 1293: return "OnGetSearchResultFromProto";
    case 1294: return "UGCAuditFailed";
    case 1295: return "UGCV2RoomTempSideDialogContextClose";
    case 1296: return "UGCResetRoomMapJoySelect";
    case 1297: return "UGCAvatarSelectDialogClose";
    case 1298: return "UGCV2LocalRoomMapChange";
    case 1299: return "UGCV2OnEditUgcDungeonSettingNotify";
    case 1300: return "UGCV2OnSaveUgcDungeonDataRsp";
    case 1301: return "OnSettingItemJoyIndexChange";
    case 1302: return "OnEditUgcDungeonNotify";
    case 1303: return "OnSaveUgcDungeonDeploymentRsp";
    case 1304: return "RegionalPlayEnable";
    case 1305: return "RegionalPlayDisable";
    case 1306: return "AbnormalClimateMixinEnable";
    case 1307: return "AbnormalClimateMixinDisable";
    case 1308: return "MichiaeBattleSkillUnlock";
    case 1309: return "ShowSignalMichiae";
    case 1310: return "LifeCountShow";
    case 1311: return "LifeCountHide";
    case 1312: return "LifeCountChange";
    case 1313: return "AttachBartenderEffectNotify";
    case 1314: return "DetachBartenderEffectNotify";
    case 1315: return "BartenderRecipeUnlockNotify";
    case 1316: return "HomeBalloonShootStartNotify";
    case 1317: return "HomeBalloonShootScoreUpdateNotify";
    case 1318: return "HomeBalloonShootEndNotify";
    case 1319: return "SpiceActivityProcessFoodRsp";
    case 1320: return "SpiceActivityFinishMakeSpiceRsp";
    case 1321: return "IrodoriAcitvityInfoUpdate";
    case 1322: return "IrodoriAcitvityWatcherInfoUpdate";
    case 1323: return "FillPoetry";
    case 1324: return "ScanPoetryEntity";
    case 1325: return "MasterGalleryStart";
    case 1326: return "MasterGallerySettle";
    case 1327: return "IrodoriChessEquipCardUpdate";
    case 1328: return "WidgetToyOnPhotographRelease";
    case 1329: return "WidgetToyStartTakingPhoto";
    case 1330: return "WidgetToyContinousTakingPhoto";
    case 1331: return "OnPhotoSettleNotify";
    case 1332: return "OnGalleryPhotoStart";
    case 1333: return "OnGalleryPhotoEnd";
    case 1334: return "ActivityPhotoConfirmCameraSetting";
    case 1335: return "PostActivityPhotoConfirmCameraSetting";
    case 1336: return "OnPhotoActivityFinishRsp";
    case 1337: return "BeforeShowActivityPhotoAdjustCameraPage";
    case 1338: return "GetQuestLackingResourceRsp";
    case 1339: return "ArrangeSaveFoundNotify";
    case 1340: return "ArrangeSaveNotFoundNotify";
    case 1341: return "UGCLimitedNotify";
    case 1342: return "UGCLockedNotify";
    case 1343: return "UGCStateUpdateNotify";
    case 1344: return "CheckHistorySavesUpdateNotify";
    case 1345: return "MusicGameRewardUnlockNotify";
    case 1346: return "MusicGameRefreshUgcArchivesNotify";
    case 1347: return "MusicGameImportOfficialLevelNotify";
    case 1348: return "MusicGameImportUgcLevelNotify";
    case 1349: return "MusicGameImportUgcLevelNewEditorNotify";
    case 1350: return "MusicGameCompareUgcLevelNotify";
    case 1351: return "MusicGameTrialUgcLevelNotify";
    case 1352: return "MusicGamePlayUgcLevelNotify";
    case 1353: return "MusicGameSettleNotify";
    case 1354: return "MusicGameEndNotify";
    case 1355: return "MusicGameRestartNotify";
    case 1356: return "MusicGameSaveUgcNotify";
    case 1357: return "MusicGameAutoSaveUgcNotify";
    case 1358: return "GetRecommendUgcInfoRsp";
    case 1359: return "GetRecommendUgcInfoFailed";
    case 1360: return "GetSearchUgcInfoRsp";
    case 1361: return "GetStoreUgcInfoRsp";
    case 1362: return "GetUgcRecordBriefInfoRsp";
    case 1363: return "MusicGameRecordListRefresh";
    case 1364: return "OnSetUgcMusicOptionRsp";
    case 1365: return "StoreUgcRsp";
    case 1366: return "SaveUgcRecommendParamRsp";
    case 1367: return "RogueDiaryCardReroll";
    case 1368: return "RogueDiaryStartDungeon";
    case 1369: return "RogueDiaryResetDungeon";
    case 1370: return "RogueDiaryCardSelected";
    case 1371: return "RogueDiaryAvatarRevive";
    case 1372: return "RogueDiaryFinishBanPick";
    case 1373: return "ActivityQuickOpen";
    case 1374: return "ActivitySpecialItem";
    case 1375: return "ChasmChallengeGalleryInfoUpdateNotify";
    case 1376: return "HomeSeekGalleryInfoUpdateNotify";
    case 1377: return "IslandMoutainSelectRsp";
    case 1378: return "IslandPartyAcitvityWatcherInfoUpdate";
    case 1379: return "IslandPartyRaftReminderRefresh";
    case 1380: return "IslandPartyRaftGalleryInfoUpdate";
    case 1381: return "IslandPartySailGalleryInfoUpdate";
    case 1382: return "IslandPartyDownHillGalleryInfoUpdate";
    case 1383: return "ActivityJigsawGameSuccess";
    case 1384: return "ActivityGearGameSuccess";
    case 1385: return "ActivityGearAutoPlaceUpperLayer";
    case 1386: return "ActivityGearAutoFlip";
    case 1387: return "PlotInferenceFinishTalk";
    case 1388: return "PlotInferenceUpdate";
    case 1389: return "PlotInferenceRemove";
    case 1390: return "TeamManaged";
    case 1391: return "BackupTeamDeleted";
    case 1392: return "UpdateShownTeamId";
    case 1393: return "TeamMoved";
    case 1394: return "DeathZoneActiveChange";
    case 1395: return "MuqadasPotionGalleryInfoUpdate";
    case 1396: return "InstableSprayTeamRefresh";
    case 1397: return "InstableSprayGalleryInfoUpdate";
    case 1398: return "InstableSpraySwitchTeamRspFail";
    case 1399: return "HomeWoodExchangeInfoRefresh";
    case 1400: return "HomeWoodExchangeUpdate";
    case 1401: return "HomeWoodSelectedMaterialExchange";
    case 1402: return "HomeWoodSelectedMaterialDialogClsoe";
    case 1403: return "WindFieldActivityWatcherInfoUpdate";
    case 1404: return "WindFieldGalleryInfoUpdate";
    case 1405: return "WindFieldChallengeInfoUpdate";
    case 1406: return "VintageHuntingGalleryStart";
    case 1407: return "VintageHuntingGalleryStop";
    case 1408: return "VintageHuntingGalleryUpdate";
    case 1409: return "OnVintageMarketStrategySlotUnlockRsp";
    case 1410: return "OnVintageMarketStoreChooseStrategyRsp";
    case 1411: return "OnVintageMarketStoreViewStrategyRsp";
    case 1412: return "OnVintageMarketDividendFinishNotify";
    case 1413: return "OnVintageMarketNpcEventFinishNotify";
    case 1414: return "OnVintageStoreAttrTooSmall";
    case 1415: return "OnVintageMarketFinishStorePlayRsp";
    case 1416: return "SwitchSkillIcon";
    case 1417: return "CalalogWatcherUpdated";
    case 1418: return "GCGClientSettle";
    case 1419: return "GcgGuideTaskStateCancel";
    case 1420: return "GcgHistoryMsgUpdated";
    case 1421: return "GcgSettle";
    case 1422: return "RefreshGcgDeckName";
    case 1423: return "GcgRefreshDeck";
    case 1424: return "GcgDeckSaved";
    case 1425: return "GcgCurrentDeckChanged";
    case 1426: return "GcgRefreshCardDetail";
    case 1427: return "GcgCardNumChanged";
    case 1428: return "GcgFilterDataConfirm";
    case 1429: return "GcgFilterDialogVisionStateChanged";
    case 1430: return "GcgFilterDialogShow";
    case 1431: return "GcgFilterDialogUpdate";
    case 1432: return "RefreshGcgDeckAppearance";
    case 1433: return "GcgPlayerDataReady";
    case 1434: return "GcgPlayerDataUpdate";
    case 1435: return "GcgPlayerLevelInfoUpdate";
    case 1436: return "GcgHandbookWeeklyChallengeInfoUpdate";
    case 1437: return "GCGWeekChallengeNotifyNpcChange";
    case 1438: return "GcgCardProficiencyUpdate";
    case 1439: return "GcgCardProficiencyRewardTaken";
    case 1440: return "GcgCardProficiencyRewardItemAdded";
    case 1441: return "GcgBannedCardListUpdate";
    case 1442: return "GcgBannedCardListUpdateRefresh";
    case 1443: return "GcgCardFaceUnlock";
    case 1444: return "GcgGetReplayList";
    case 1445: return "GcgReplaySetFavorite";
    case 1446: return "GcgReplayBecameInvalid";
    case 1447: return "GcgReplayStart";
    case 1448: return "GcgClientBannedCardsUpdate";
    case 1449: return "GcgPickDataReady";
    case 1450: return "GcgPickDataUpdated";
    case 1451: return "GcgPickFinished";
    case 1452: return "GcgPickInterrupted";
    case 1453: return "GcgPickRoundDataUpdated";
    case 1454: return "GcgPickCurPrePicksUpdated";
    case 1455: return "GcgTavernTransport";
    case 1456: return "GcgShareCodeSuccessfully";
    case 1457: return "GcgShareCodeFailed";
    case 1458: return "GcgImportDeck";
    case 1459: return "GcgShareCodePreCheck";
    case 1460: return "GcgServerSettingUpdate";
    case 1461: return "FungusFighterCaptureGalleryStart";
    case 1462: return "FungusFighterCaptureGalleryInfoUpdate";
    case 1463: return "FungusFighterCaptureGallerySettle";
    case 1464: return "FungusFighterCaptureGalleryStop";
    case 1465: return "FungusFighterTrainingGalleryStart";
    case 1466: return "FungusFighterTrainingGalleryInfoUpdate";
    case 1467: return "FungusFighterTrainingGallerySettle";
    case 1468: return "FungusFighterTrainingGalleryStop";
    case 1469: return "FungusFighterTrainingOrganizeSuccess";
    case 1470: return "FungusFighterTrainingBackupSuccess";
    case 1471: return "FungusFighterTrainingClearSuccess";
    case 1472: return "FungusFighterPartnerUseSkillSuccess";
    case 1473: return "CharAmusementStagePreview";
    case 1474: return "CharAmusementStagePrepare";
    case 1475: return "CharAmusementStageGallery";
    case 1476: return "CharAmusementGalleryInfoUpdate";
    case 1477: return "FungusFighterLevelUp";
    case 1478: return "FungusFighterLevelError";
    case 1479: return "FungusRenameSuccess";
    case 1480: return "FungusRenameFailed";
    case 1481: return "EffigyV2GalleryInfoUpdate";
    case 1482: return "HomeworldBlueprintSlotInfoUpdate";
    case 1483: return "HomeworldBlueprintFriendCopyOption";
    case 1484: return "HomeworldBlueprintSlotOptionUpdate";
    case 1485: return "HomeworldBlueprintCreateInfo";
    case 1486: return "HomeworldBlueprintDeleInfo";
    case 1487: return "HomeworldBlueprintSaveFromShare";
    case 1488: return "HomeworldBlueprintSetCreatButtonTimer";
    case 1489: return "HomeworldPreviewBlockChange";
    case 1490: return "HomeworldCrossModulePreview";
    case 1491: return "HomeworldEnterPreviewModeSuccess";
    case 1492: return "HomeworldResumeBlueprintHandBook";
    case 1493: return "HomeworldSceneFishpondFarmSuccess";
    case 1494: return "BrickBreakerStagePrepare";
    case 1495: return "BrickBreakerStagePick";
    case 1496: return "BrickBreakerStageGame";
    case 1497: return "BrickBreakerPlayerSetAvatarNotify";
    case 1498: return "BrickBreakerSelectSkillRsp";
    case 1499: return "BrickBreakerPlayerSetSkillNotify";
    case 1500: return "BrickBreakerPlayerReadyNotify";
    case 1501: return "BrickBreakerStageSettle";
    case 1502: return "BrickBreakerPlayerChangingNotify";
    case 1503: return "OnSingleStartBrickBreakerRsp";
    case 1504: return "OnInBattleBrickBreakerStart";
    case 1505: return "OnInBattleBrickBreakerUpdate";
    case 1506: return "OnInBattleBrickBreakerFinish";
    case 1507: return "OnInBattleBrickBreakerShowBanner";
    case 1508: return "BrickBreakerLevelChecked";
    case 1509: return "OnInBattleBrickBreakerChallengeStart";
    case 1510: return "OnInBattleBrickBreakerChallengeSuccess";
    case 1511: return "OnInBattleBrickBreakerChallengeFail";
    case 1512: return "BrickBreakerWatcherInfoUpdate";
    case 1513: return "OnGalleryElectroHercluesBattleStart";
    case 1514: return "OnGalleryElectroHercluesBattleStop";
    case 1515: return "HerculesBattleStopGuideTask";
    case 1516: return "HerculesBattlePreAccumulateNodeFinish";
    case 1517: return "ElectroherculesBattleSelectDifficultyRsp";
    case 1518: return "BeforeSendElectroherculesBattleGalleryFinishReq";
    case 1519: return "CoinCollectSkillSelectFailed";
    case 1520: return "CoinCollectSkillSelectSucceed";
    case 1521: return "CoinCollectInviteCheckFailed";
    case 1522: return "CoinCollectInviteCheckSucceed";
    case 1523: return "CoinCollectGalleryInfoUpdate";
    case 1524: return "CoinCollectGalleryReady";
    case 1525: return "CoinCollectMultistagePrepare";
    case 1526: return "CoinCollectMultistageCutScene";
    case 1527: return "CoinCollectMultistageGallery";
    case 1528: return "CoinCollectMultistageEnd";
    case 1529: return "CoinCollectMultistagePlayerInfoUpdate";
    case 1530: return "LanV3ConditionUpdate";
    case 1531: return "LanV3BoatGameStagePrepare";
    case 1532: return "LanV3BoatGameStagePlay";
    case 1533: return "LanV3BoatGameStageSettle";
    case 1534: return "LanV3BoatGameMultistagePlayEnd";
    case 1535: return "LanV3BoatGameTransferFinish";
    case 1536: return "LanV3BoatGameGalleryMultiInfoUpdate";
    case 1537: return "LanV3BoatGameSingleStart";
    case 1538: return "ShadowGameBlockSwap";
    case 1539: return "ShadowGameSettle";
    case 1540: return "ShadowGameSuccess";
    case 1541: return "ShadowGameFail";
    case 1542: return "ShadowGameQuit";
    case 1543: return "ShadowGameRestart";
    case 1544: return "ShadowGameNextLevel";
    case 1545: return "ShadowGameFinishLevel";
    case 1546: return "StartTeamChainGalleryNotify";
    case 1547: return "UpdateTeamChainGalleryNotify";
    case 1548: return "StopTeamChainGalleryNotify";
    case 1549: return "DuelHeartSelectDifficultySucc";
    case 1550: return "UpdateDuelHeartDifficulty";
    case 1551: return "DuelHeartCreateCountDown";
    case 1552: return "DuelHeartClearCountDown";
    case 1553: return "SorushGoOutLimit";
    case 1554: return "SorushBackLimit";
    case 1555: return "PacmanActivityWatcherInfoUpdate";
    case 1556: return "PacmanGalleryInfoUpdate";
    case 1557: return "PacmanDungeonSettle";
    case 1558: return "PacmanGameStagePrepare";
    case 1559: return "PacmanGameStageGallery";
    case 1560: return "PacmanGameStageSettle";
    case 1561: return "FungusV2PartnerSpawn";
    case 1562: return "FungusV2PartnerDie";
    case 1563: return "FungusV2EnemySpawn";
    case 1564: return "FungusV2EnemyDie";
    case 1565: return "OnServerRedpointUpdated";
    case 1566: return "AkaFesRhythmClick";
    case 1567: return "AkaFesRhythmLongPress";
    case 1568: return "AkaFesRhythmRoundEnd";
    case 1569: return "AkaFesRhythmLevelEnd";
    case 1570: return "AkaFesRhythmSuccess";
    case 1571: return "AkaFesRhythmFail";
    case 1572: return "AkaFesRhythmMiss";
    case 1573: return "AkaFesRhythmFinishPlay";
    case 1574: return "AkaFesRhythmStartPlay";
    case 1575: return "AkaFesRhythmPause";
    case 1576: return "AkaFesRhythmShakeCamera";
    case 1577: return "AkaFesAstrolabeReturnToSelectLevel";
    case 1578: return "AkaFesAstrolabeEnterNextLevel";
    case 1579: return "AkaFesAstrolabeSelectLevelStart";
    case 1580: return "AkaFesAstrolabeSelectLevelFinish";
    case 1581: return "AkaFesAstrolabeChangeGearBtnState";
    case 1582: return "AkaFesArchitectSaveComplete";
    case 1583: return "AkaFesArchaeologyReminderRefresh";
    case 1584: return "SandWormCannonGalleryStart";
    case 1585: return "SandWormCannonGalleryFinish";
    case 1586: return "SandWormCannonChargeProgressUpdate";
    case 1587: return "SandWormCannonExitChallenge";
    case 1588: return "CustomGalleryUpdateAll";
    case 1589: return "CustomGalleryUpdateSingleProgress";
    case 1590: return "CustomGalleryRemoveAllProgress";
    case 1591: return "LanguageChange";
    case 1592: return "GalleryCountDownEndTimeChange";
    case 1593: return "PauseGalleryCountDown";
    case 1594: return "SorushTrialGalleryStart";
    case 1595: return "SorushTrialGalleryStop";
    case 1596: return "SorushTrialOnPhotomatchSettle";
    case 1597: return "UGCV2ShopItemRefresh";
    case 1598: return "UGCV2TeamInfoRefresh";
    case 1599: return "UGCV2TeamLevelUp";
    case 1600: return "UGCV2ItemAdd";
    case 1601: return "UGCV2TowerBuildSuccess";
    case 1602: return "UGCV2ShopBounghtSuccess";
    case 1603: return "UGCV2TowerLevelUp";
    case 1604: return "UGCV2TowerDisMantle";
    case 1605: return "UGCV2RunTimePackRefresh";
    case 1606: return "UGCV2DungeonFeatureSwitch";
    case 1607: return "UGCV2PostDungeonFeatureSwitch";
    case 1608: return "EffigyV4AvatarPrepare";
    case 1609: return "EffigyV4CancelPrepare";
    case 1610: return "EffigyV4InDungeonChangeAvatarFinish";
    case 1611: return "PenumbraSwitch";
    case 1612: return "PenumbraStop";
    case 1613: return "PenumbraRefreshInteract";
    case 1614: return "PenumbraShowGiveDialog";
    case 1615: return "PenumbraReminderAppeared";
    case 1616: return "PenumbraReminderDisappeared";
    case 1617: return "PenumbraDisableInput";
    case 1618: return "PenumbraItemAdded";
    case 1619: return "GCGArenaScheduleChange";
    case 1620: return "GCGArenaScheduleDataUpdate";
    case 1621: return "GCGArenaChallengeStart";
    case 1622: return "GCGArenaChallengeCancel";
    case 1623: return "JourneyDiceDungeonGalleryInfoUpdate";
    case 1624: return "JourneyDiceDungeonUseBuff";
    case 1625: return "MuqadasPotionTrailAvatarChanged";
    case 1626: return "CommonMultiStageStateChange";
    case 1627: return "CommonMultiStageEnd";
    case 1628: return "PenAdvTargetShootingTransferFinish";
    case 1629: return "PenAdvTargetShootingDialogShow";
    case 1630: return "PenAdvTargetShootingGalleryRecover";
    case 1631: return "PenAdvTargetShootingGalleryUpdate";
    case 1632: return "ShuffleBoardRoundBeg";
    case 1633: return "ShuffleBoardRoundEnd";
    case 1634: return "ShuffleBoardRoundFail";
    case 1635: return "ShuffleBoardRoundSucc";
    case 1636: return "ShuffleBoardRoundsEnd";
    case 1637: return "MultiCharacterFightStartFailed";
    case 1638: return "MultiCharacterFightStartSucc";
    case 1639: return "MultiCharacterFightFinishLoad";
    case 1640: return "OnActivityGetMonsterIdListRsp";
    case 1641: return "EnterCanDiveArea";
    case 1642: return "LeaveCanDiveArea";
    case 1643: return "MultiLayerGroupPlayerEnter";
    case 1644: return "MultiLayerGroupRebuild";
    case 1645: return "MultiLayerMapShowFloorChange";
    case 1646: return "MultiLayerUnloadAll";
    case 1647: return "PlayDialogCompPostDialogPlay";
    case 1648: return "PlayDialogCompPostDialogFinish";
    case 1649: return "PlayDialogCompPostNextDialogPlay";
    case 1650: return "QuestEventClientDataChange";
    case 1651: return "OnSubmitQuestEventsGivingRsp";
    case 1652: return "BeforeRequestNPCInteractionByInput";
    case 1653: return "PostStartQuestDiscover";
    case 1654: return "QuestInferenceLocalServerDataChange";
    case 1655: return "QuestInferenceSettle";
    case 1656: return "SetCorrectClueToPreFillAndClearListFinish";
    case 1657: return "QuestRefuteLocalServerDataChange";
    case 1658: return "OnRefuteResult";
    case 1659: return "QuestRefuteResumeDialog";
    case 1660: return "NotifyQuestPlayDialogRefresh";
    case 1661: return "QuestRefuteTriggerRouletteBulletAnim";
    case 1662: return "QuestEventIconForceHideStateChange";
    case 1663: return "RemoveQuestEventIndicator";
    case 1664: return "AddQuestEventIndicator";
    case 1665: return "RequestUnlockQuestEventsItemSuccess";
    case 1666: return "QuestRefuteAutoQuitDialog";
    case 1667: return "IgnoreAutoFinishCurrTalkOnLandFromBackOnce";
    case 1668: return "TalkOpenPage";
    case 1669: return "ToyBattleGameStart";
    case 1670: return "ToyBattleGameFinish";
    case 1671: return "ToyBattleGamePause";
    case 1672: return "ToyBattleGameResumeWithCountDown";
    case 1673: return "ToyBattleGameRestartWithCountDown";
    case 1674: return "ReloadToyBattleGameData";
    case 1675: return "ToyBattleGadgetWaitListChange";
    case 1676: return "ToyBattleComboAdd";
    case 1677: return "ToyBattleComboReset";
    case 1678: return "ToyBattleScoreAdd";
    case 1679: return "ToyBattleCountDown";
    case 1680: return "ToyBattleUIRefresh";
    case 1681: return "ToyBattleChangeToNormal";
    case 1682: return "ToyBattleDestoryInViewNotes";
    case 1683: return "RefreshAllHeadPortrait";
    case 1684: return "RefreshHeadPortraitRP";
    case 1685: return "FishBlasterAddScore";
    case 1686: return "FishBlasterAddBall";
    case 1687: return "FishBlasterDragEnd";
    case 1688: return "QuickTimeCombatEnterDungeon";
    case 1689: return "QuickTimeCombatGalleryStart";
    case 1690: return "QuickTimeCombatGalleryUpdate";
    case 1691: return "QuickTimeCombatGalleryStop";
    case 1692: return "InspirationSpurtRestartCountdown";
    case 1693: return "PoetryFesPaintingFinish";
    case 1694: return "PoetryFesPaintingStart";
    case 1695: return "BlessingV2ScanSuccess";
    case 1696: return "BlessingV2ScanFailed";
    case 1697: return "FriendGift_GiveFriendGiftRsp";
    case 1698: return "FriendGift_GetRecvGiftListRsp";
    case 1699: return "FriendGift_HaveRecvGiftNotify";
    case 1700: return "FriendGift_AcceptGiveGiftRsp";
    case 1701: return "FriendGift_AcceptAllGiveGiftRsp";
    case 1702: return "FriendGift_AcceptAllGiveGiftFailedRsp";
    case 1703: return "FriendGift_GetCanGiveFriendGiftRsp";
    case 1704: return "FriendGift_SetGiftWishRsp";
    case 1705: return "FriendGift_GetFriendGiftWishListRsp";
    case 1706: return "FilmfestSniperGalleryStart";
    case 1707: return "FilmfestSniperGalleryUpdate";
    case 1708: return "FilmfestSniperGalleryStop";
    case 1709: return "FilmfestBallgamePlayerScoreUpdate";
    case 1710: return "HomeworldConstructMappingChanged";
    case 1711: return "HomeworldJumpToWoodTab";
    case 1712: return "OnGetReliquarySetScheme";
    case 1713: return "OnGetSaveReliquarySetSchemeRsp";
    case 1714: return "OnGetSetEquipLockStateBatchRsp";
    case 1715: return "OnGetReliquaryLockGeneralOptionRsp";
    case 1716: return "OnGetReliquaryLockGeneralOptionRspFail";
    case 1717: return "LanV4PushBoxRequestUnLock";
    case 1718: return "LanV4PushBoxRequestKillEntityByRuntimeID";
    case 1719: return "LanV4PushBoxRequestCheckAllPerformFinish";
    case 1720: return "LanV4PushBoxBeforeEntityLeaveCell";
    case 1721: return "LanV4PushBoxLeftStepChange";
    case 1722: return "OnGalleryLanV4CarpJumpStart";
    case 1723: return "StaminaFightChooseAvatar";
    case 1724: return "StaminaFightStartChallenge";
    case 1725: return "OnGetSetEquipAvatarPreviewRsp";
    case 1726: return "OnGetReliquaryWearCustomDataRsp";
    case 1727: return "OnGetSetEquipBatchRsp";
    case 1728: return "HomeworldFilterRequest";
    case 1729: return "HomeworldFilterClose";
    case 1730: return "CatCafeEnterNewFavorStage";
    case 1731: return "CatCafeFeedSuccess";
    case 1732: return "EntityTouchLoadingFinished";
    case 1733: return "EntityTouchFavorValueChanged";
    case 1734: return "ForceCloseEntitySelect";
    case 1735: return "EntityTouchEnableUIAction";
    case 1736: return "ActionButtonPointerDown";
    case 1737: return "ActionButtonPointerUp";
    case 1738: return "OnActivitySkillDoSkillNotify";
    case 1739: return "AutoTimeStopGalleryInfoUpdate";
    case 1740: return "AutoTimeStopTrialAvatarMapUpdate";
    case 1741: return "AlchemySimPotionStart";
    case 1742: return "AlchemySimBottlingReady";
    case 1743: return "AlchemySimPotionFinish";
    case 1744: return "AlchemySimPotionExamFinish";
    case 1745: return "AlchemySimPotionPuzzlePlaced";
    case 1746: return "AlchemySimCropRspFailed";
    case 1747: return "AlchemySimCropHarvested";
    case 1748: return "AlchemySimCropPlanted";
    case 1749: return "AlchemySimCropRipened";
    case 1750: return "AlchemySimCropUpgrade";
    case 1751: return "AlchemySimGalleryUpdate";
    case 1752: return "AlchemySimGalleryNewRound";
    case 1753: return "AlchemySimGalleryDealerReportUpdate";
    case 1754: return "SlimeCannonScoreUpdate";
    case 1755: return "SlimeCannonComboUpdate";
    case 1756: return "SlimeCannonComboReset";
    case 1757: return "SlimeCannonDifficultyUpdate";
    case 1758: return "SlimeCannonBulletUpdate";
    case 1759: return "QuestCheckFinish";
    case 1760: return "QuestCheckFail";
    case 1761: return "CharacterPageRedirect";
    case 1762: return "RemusMagicDragonDashQTE";
    case 1763: return "RemusMagicDragonDashBeginQTE";
    case 1764: return "GreatFestivalV2TakeUpgradeRewardRsp";
    case 1765: return "GreatFestivalActivityClose";
    case 1766: return "GreatFestivalAcitvityInfoUpdate";
    case 1767: return "GreatFestivalAcitvityWatcherInfoUpdate";
    case 1768: return "EffigyChallengeV5SupportListUpdate";
    case 1769: return "GetEffigyChallengeV5SelectDifficultyRsp";
    case 1770: return "RemusCatReminder";
    case 1771: return "HomeworldWishListRefresh";
    case 1772: return "HomeworldWishListSaveSuccess";
    case 1773: return "HomeworldWishListDeleteSuccess";
    case 1774: return "HomeworldWishListUnLockFurnitureBatch";
    case 1775: return "HomeworldTakeFurnitureBatch";
    case 1776: return "RoleCombatCardEventRefresh";
    case 1777: return "RoleCombatCardEventRefreshFinish";
    case 1778: return "RoleCombatSelectCardRefresh";
    case 1779: return "RoleCombatCoinRefresh";
    case 1780: return "RoleCombatCoinChangePerform";
    case 1781: return "RoleCombatAvatarBonusPerform";
    case 1782: return "RoleCombatGetFriendBriefRentInfo";
    case 1783: return "RoleCombatGetFriendRentInfo";
    case 1784: return "RoleCombatGetFriendRentInfoFail";
    case 1785: return "RoleCombatSetRentAvatar";
    case 1786: return "RoleCombatRecordHandbookRefresh";
    case 1787: return "RoleCombatSelectRewardAvatar";
    case 1788: return "RoleCombatRefreshRewardAvatar";
    case 1789: return "RoleCombatStartGallery";
    case 1790: return "RoleCombatSurrender";
    case 1791: return "RoleCombatBackTrackPreview";
    case 1792: return "RoleCombatRewardItemAdded";
    case 1793: return "RoleCombatTeamSelect";
    case 1794: return "RoleCombatTeamChange";
    case 1795: return "RoleCombatTrialAvatarPreview";
    case 1796: return "RoleCombatBriefInfoUpdate";
    case 1797: return "RoleCombatAllMaxRoundIdUpdate";
    case 1798: return "RoleCombatPhonographBgmUpdate";
    case 1799: return "RoleCombatPersonalSettingUpdate";
    case 1800: return "RoleCombatToggleSelectCardContent";
    case 1801: return "RoleCombatSelectCard";
    case 1802: return "RoleCombatViewAvatar";
    case 1803: return "RoleCombatScheduleEnd";
    case 1804: return "RoleCombatOneOffRewardItemAdded";
    case 1805: return "RoleCombatStarRewardItemAdded";
    case 1806: return "RoleCombatRewardTaken";
    case 1807: return "RoleCombatOneOffRewardTaken";
    case 1808: return "RoleCombatStarRewardTaken";
    case 1809: return "RoleCombatGetRentCount";
    case 1810: return "RoleCombatFlipAvatar";
    case 1811: return "RoleCombatGetRentInfo";
    case 1812: return "RoleCombatAllFinish";
    case 1813: return "WatergunTransferFinish";
    case 1814: return "WatergunDialogShow";
    case 1815: return "WatergunGalleryStart";
    case 1816: return "WatergunGalleryUpdate";
    case 1817: return "WatergunGuidePrepare";
    case 1818: return "BulletHellGalleryPreStart";
    case 1819: return "BulletHellGalleryStart";
    case 1820: return "SyncBulletHellProgress";
    case 1821: return "BulletHellGalleryUpdate";
    case 1822: return "BulletHellProgressIncrease";
    case 1823: return "BulletHellProgressClear";
    case 1824: return "BulletHellGalleryStop";
    case 1825: return "OnMvMAbilityEvent";
    case 1826: return "OnMvMUseCardRsp";
    case 1827: return "OnMvMEnterDungeon";
    case 1828: return "OnMvMEnemyCreate";
    case 1829: return "TalkReviewForceHideStateChange";
    case 1830: return "TalkHideUIForceHideStateChange";
    case 1831: return "OnTalkHideUI";
    case 1832: return "OnTalkDialogActiveAnimChange";
    case 1833: return "FairyTalesCombatFeverInfoUpdate";
    case 1834: return "FairyTalesTakeBonus";
    case 1835: return "BeforeCatchDollEnterScenePerformFinish";
    case 1836: return "CatchDollOnScoreChange";
    case 1837: return "CatchDollOnHitValueChange";
    case 1838: return "CatchDollTipMemoryWaveSpawn";
    case 1839: return "CatchDollOnSameDollAdditionTimesAdd";
    case 1840: return "CatchDollCatchTimesChange";
    case 1841: return "FairyTalesCurrentGalleryStart";
    case 1842: return "FairyTalesCurrentGalleryStop";
    case 1843: return "GetFairyTalesCapsuleToyLotterRsp";
    case 1844: return "CharMasterInfoUpdate";
    case 1845: return "CharMasterPreviewTrialAvatar";
    case 1846: return "CharMasterKeyAdded";
    case 1847: return "CharMasterShowBanner";
    case 1848: return "GadgetSpeechBubbleRefresh";
    case 1849: return "GetActivityPreviewAvatarInfo";
    case 1850: return "RechargeDiskPreviewAvatarInfoAdded";
    case 1851: return "ResidentRedPointInitFinish";
    case 1852: return "PhlogistonBarRefresh";
    case 1853: return "PhlogistonInVehicleChange";
    case 1854: return "TriggerPhlogistonBarFocus";
    case 1855: return "TriggerLackPhlogistonAnim";
    case 1856: return "DrillEnergyGalleryFinish";
    case 1857: return "DrillEnergyGalleryStart";
    case 1858: return "BoltBugGalleryFinish";
    case 1859: return "BoltBugGalleryStart";
    case 1860: return "ResonantCrystalGalleryStart";
    case 1861: return "ResonantProHintInit";
    case 1862: return "ResonantCrystalGalleryAdd";
    case 1863: return "ResonantCrystalGalleryStop";
    case 1864: return "ResonantCrystalGalleryBlink";
    case 1865: return "ResonantCrystalGalleryUpdate";
    case 1866: return "ResonantCrystalGallerySuccuss";
    case 1867: return "PriorityUISourceUpdate";
    case 1868: return "SetNyxBarAnimatorTrigger";
    case 1869: return "DelusionExpBarValueUpdate";
    case 1870: return "FoodFilterClose";
    case 1871: return "OnUnlockCookRecipe";
    case 1872: return "GainBuffPreviewAvatarInfoAdded";
    case 1873: return "GainBuffGalleryStart";
    case 1874: return "GainBuffBehaviorAdd";
    case 1875: return "GainBuffGalleryStop";
    case 1876: return "NatlanTourDetailUnlockAni";
    case 1877: return "NatlanTourSideDetailRefresh";
    case 1878: return "ReunionCacheRewardItem";
    case 1879: return "ReunionWPGetReward";
    case 1880: return "OnGetReliquaryPurchaseItem";
    case 1881: return "OnGetReliquaryOfferingItem";
    case 1882: return "OnGetReliquaryPurchaseRsp";
    case 1883: return "OnGetReliquaryOfferingRsp";
    case 1884: return "OnGetReliquaryOfferPurchaseInfoNotify";
    case 1885: return "OnGetReliquaryTransferItem";
    case 1886: return "OnGetReliquaryTransferRsp";
    case 1887: return "BomberDodocoDetonateChange";
    case 1888: return "BomberDodocoReminderStart";
    case 1889: return "NatlanStylizeGalleryPreStart";
    case 1890: return "NatlanStylizeGalleryStart";
    case 1891: return "NatlanStylizeGalleryRecover";
    case 1892: return "NatlanStylizeGalleryRefresh";
    case 1893: return "LevelTimePause";
    case 1894: return "BoltbugAbyssGalleryStart";
    case 1895: return "BoltbugAbyssGalleryFinish";
    case 1896: return "BoltbugAbyssGalleryUpdate";
    case 1897: return "DreamExploreScoreUpdate";
    case 1898: return "FloatToyPreLoadFinsished";
    case 1899: return "FloatToyGameStart";
    case 1900: return "FloatToyGameFinish";
    case 1901: return "FloatToyGamePause";
    case 1902: return "FloatToyGameRestart";
    case 1903: return "FloatToyChangeMedal";
    case 1904: return "FloatToyGadgetWaitListChange";
    case 1905: return "CoChallengePlayerInfoUpdate";
    case 1906: return "CoChallengeStageChange";
    case 1907: return "CoChallengeGalleryInfoChange";
    case 1908: return "CoChallengeGalleryBuffInfoChange";
    case 1909: return "CoChallengeStageUpdate";
    case 1910: return "CoChallengeSelfDie";
    case 1911: return "GalleryArenaChallengeStart";
    case 1912: return "GalleryArenaChallengeStop";
    case 1913: return "ArenaChallengeMonsterPreloadBegin";
    case 1914: return "AbyssWarInfoChange";
    case 1915: return "AbyssWarAccountRsp";
    case 1916: return "AbyssWarErosionHud";
    case 1917: return "ReliquaryQuickPutFiveStarUpgrade";
    case 1918: return "GcgAbcShowSettle";
    case 1919: return "GcgAbcGiveUp";
    case 1920: return "GcgAbcPickFailed";
    case 1921: return "MonsterChessPhaseChange";
    case 1922: return "MonsterChessRecordInfoUpdate";
    case 1923: return "MonsterChessDetailDialogContextUpdate";
    case 1924: return "MonsterChessInLevelCameraReset";
    case 1925: return "MonsterChessFightControllerInfoUpdate";
    case 1926: return "MonsterChessTriggerArtifactNotify";
    case 1927: return "MonsterChessCardLevelUpNotify";
    case 1928: return "MonsterChessCardStarUpNotify";
    case 1929: return "MonsterChessBriefInfoRsp";
    case 1930: return "MonsterChessPrepareChosenListUpdate";
    case 1931: return "MonsterChessDrawDialogUpdate";
    case 1932: return "LightStrikeGalleryStart";
    case 1933: return "LightStrikeGalleryUpdate";
    case 1934: return "LightStrikeGalleryStop";
    case 1935: return "BeyondLevelDataSaveRefresh";
    case 1936: return "BeyondLevelRenameStart";
    case 1937: return "BeyondLevelRenameEnd";
    case 1938: return "BeyondRefreshCloudLevelItem";
    case 1939: return "BeyondLocalSaveCreateCategory";
    case 1940: return "BeyondLocalSaveSortChange";
    case 1941: return "BeyondRuntimeCountDownInfoNotify";
    case 1942: return "BeyondUploadCloudData";
    case 1943: return "BeyondLevelMatchStatusChange";
    case 1944: return "BeyondLevelMatchStageChange";
    case 1945: return "BeyondLevelMatchGetLevelBriefInfo";
    case 1946: return "BeyondLevelMatchFinished";
    case 1947: return "BeyondLevelDetailDialogOpen";
    case 1948: return "BeyondLevelDetailDialogClose";
    case 1949: return "BeyondAnniversaryDialogClose";
    case 1950: return "BeyondCreateWorldFailNotify";
    case 1951: return "BeyondMatchHideScoreNotifyReceive";
    case 1952: return "BeyondAfterUploadCloudData";
    case 1953: return "BeyondCommunityResourceGet";
    case 1954: return "BeyondDataConfigTabSelectChange";
    case 1955: return "BeyondEnterRandomPublicHallRsp";
    case 1956: return "BeyondEmojiPanelButtonClicked";
    case 1957: return "BeyondDataConfigClose";
    case 1958: return "BeyondDataConfigRightRefresh";
    case 1959: return "BeyondRecommendDataRefresh";
    case 1960: return "BeyondRecommendUIRefresh";
    case 1961: return "BeyondUpdateCreatorData";
    case 1962: return "BeyondRecommendDataGetNextPage";
    case 1963: return "BeyondFeatureSwitchRefresh";
    case 1964: return "BeyondActiveSuiteReady";
    case 1965: return "BeyondActiveSuiteChanged";
    case 1966: return "BeyondDungeonSettle";
    case 1967: return "BeyondLevelChipChanged";
    case 1968: return "BeyondPaidDlcManageUpdate";
    case 1969: return "BeyondPaidDlcCapacityUpgrade";
    case 1970: return "OnBeyondDlcShelveRsp";
    case 1971: return "OnBeyondDlcUnshelveRsp";
    case 1972: return "BeyondUpdateMiniMap";
    case 1973: return "OnLoadMonoLevelMapFinished";
    case 1974: return "OnLoadMonoLevelMapUIFinished";
    case 1975: return "BeyondBigMapZoomInitScaleApplied";
    case 1976: return "BeyondUpdateOptionSelectorPanel";
    case 1977: return "BeyondOptionSelectorRuntimePostMountToParent";
    case 1978: return "BeyondOnPostEnterSceneRsp";
    case 1979: return "BeyondOnReceiveEnterSceneNotify";
    case 1980: return "BeyondRefreshSettleLikeCntNotify";
    case 1981: return "BeyondRefreshSettlePage";
    case 1982: return "BeyondSettleRecLevelListUpdated";
    case 1983: return "BeyondCloseUGCStarUpgradeDialogNotify";
    case 1984: return "BeyondHandbookInfoChanged";
    case 1985: return "BeyondHandbookRewardRsp";
    case 1986: return "BeyondHandbookRewardReceive";
    case 1987: return "BeyondLevelWatcherRewardReceive";
    case 1988: return "BeyondSeasonDLCInfoChanged";
    case 1989: return "BeyondEnteringDialogMsgRsp";
    case 1990: return "AvatarFactionChange";
    case 1991: return "BeyondCurrentLevelStateAbnormal";
    case 1992: return "BeyondDungeonPlayerDie";
    case 1993: return "BeyondSeasonChanged";
    case 1994: return "BeyondDungeonBeforeShowPlayerReviveDialog";
    case 1995: return "BeyondInitialActiveInfoChanged";
    case 1996: return "BeyondInitialActiveInfoClosed";
    case 1997: return "BeyondCustomUIFactionRefresh";
    case 1998: return "BeyondCustomUILayerUpdate";
    case 1999: return "BeyondCommunityGetPublishTrendList";
    case 2000: return "BeyondCommunityGetPublishTrendUnreadCount";
    case 2001: return "BeyondCommunityGetPublishTrendRemainCount";
    case 2002: return "BeyondCreatorSubscribeInfoUpdate";
    case 2003: return "BeyondCommunityBatchGetUserSubscribeLevel";
    case 2004: return "BeyondCommunityGetCollectionLevelList";
    case 2005: return "RefreshBeyondPlayerDetailOnlineInfo";
    case 2006: return "RefreshBeyondTeamPlayer";
    case 2007: return "BeyondHallMessageGet";
    case 2008: return "RefreshBeAllowState";
    case 2009: return "RefreshBeyondRecommendFriend";
    case 2010: return "BeyondPlayerDetailOnlineInfoFetcherOnRsp";
    case 2011: return "BeyondShowAvatarChange";
    case 2012: return "BydCreateAvatarOnSelectBodyConfirm";
    case 2013: return "BydCreateAvatarOnServerCreateAvatarSuccess";
    case 2014: return "BydCreateAvatarOnServerCreateAvatarFail";
    case 2015: return "BydCreateAvatarRefreshPage";
    case 2016: return "BydCreateAvatarPageOnApplicationPause";
    case 2017: return "BydCreateAvatarPlayerBreakIdle";
    case 2018: return "BydCreateAvatarStopIdleAnim";
    case 2019: return "BydCostumeVideoPlayFinish";
    case 2020: return "BydOnCreateFollowUpAvatarFinish";
    case 2021: return "BydCostumeInfoInitialized";
    case 2022: return "BydCostumeInfoUpdated";
    case 2023: return "BydCostumeInfoUpdatedExceptTrialSuitPart";
    case 2024: return "BydCostumeInfoUpdaeForRedPoint";
    case 2025: return "BydCostumeMarkInfoUpdated";
    case 2026: return "BydCostumeLocalSetInfoInitialized";
    case 2027: return "BydCostumeLocalSetAutoSwitch";
    case 2028: return "BydCostumeLocalSetInfoIUpdated";
    case 2029: return "BydCostumeSelectSameCostumeSet";
    case 2030: return "BydCostumeAvatarVoiceInfoUpdated";
    case 2031: return "BydCostumeTransferEffectInfoUpdated";
    case 2032: return "BeyondCostumeSetNameUpdated";
    case 2033: return "BeyondCostumeSetNameIllegal";
    case 2034: return "BeyondCostumeSetDeleted";
    case 2035: return "BeyondCostumeShareCodeGenSuccess";
    case 2036: return "BeyondCostumeShareCodeGenFail";
    case 2037: return "BeyondCostumeSynthesisSuccess";
    case 2038: return "BydCostumeAvatarSetInfoUpdated";
    case 2039: return "BydCostumeCurCostumeSetInfoUpdated";
    case 2040: return "BydCostumeSetIndexUpdated";
    case 2041: return "BydCostumeSetIndexUpdatedLocal";
    case 2042: return "BydCostumeTrialCostumeSetInfoUpdated";
    case 2043: return "BydCostumeUesTrialCardSuccess";
    case 2044: return "BydCostumeAvatarSetInitialized";
    case 2045: return "BydCostumePageFilterResultUpdated";
    case 2046: return "BydCostumePagefilterFailed";
    case 2047: return "BydCostumeLackinfoUpdated";
    case 2048: return "BeyondCostumePostInfoUpdated";
    case 2049: return "BeyondCostumeSetSaveSuccess";
    case 2050: return "BeyondCostumeEmojiSaveSuccess";
    case 2051: return "BeyondCostumeSetDisplaySuccess";
    case 2052: return "BeyondCostumeSetDisplayUpdate";
    case 2053: return "BeyondFromClosetToCostumePage";
    case 2054: return "BeyondBeforeTriggerSkillBtnByInput";
    case 2055: return "BeyondBeforeBuyGoodsFromBeyondPurchaseDialog";
    case 2056: return "BeyondChangeHallAvatarSuccess";
    case 2057: return "OnBeyondCreateAvatarCommonCheckRsp";
    case 2058: return "BeyondPlayerInfoSwitchAvatarShowMode";
    case 2059: return "BeyondShowTwinAvatarModeUpdated";
    case 2060: return "BeyondPlayerSocialConfigNotify";
    case 2061: return "BeyondRequestShopCostumeListSuccess";
    case 2062: return "BeyondRequestGachaCostumeListSuccess";
    case 2063: return "OnVersionIndexDataNotify";
    case 2064: return "BeyondCustomRandStateChange";
    case 2065: return "BeyondTrialCostumeExpired";
    case 2066: return "BeyondTrialSuitExpired";
    case 2067: return "BeyondTrialCardExpired";
    case 2068: return "BeyondCostumeBlueprintRemoved";
    case 2069: return "BeyondCostumeBlueprintObtained";
    case 2070: return "BeyondCostumeSynthesisInfoUpdated";
    case 2071: return "BeyondGetSynthesizedCostume";
    case 2072: return "BeyondGetSynthesizedSuit";
    case 2073: return "BeyondAvatarInteractMoveEvent";
    case 2074: return "BeyondAvatarInteractZoomEvent";
    case 2075: return "BeyondAvatarInteractTouchWithoutMoveEvent";
    case 2076: return "BeyondProfilePageOpen";
    case 2077: return "BeyondSelfProfileInfoUpdated";
    case 2078: return "BeyondSelfProfileSetSuccess";
    case 2079: return "BeyondCustomizeProfileUploadFinish";
    case 2080: return "BeyondCustomizeProfileAuditFail";
    case 2081: return "BeyondCustomizeProfileAuditSuccess";
    case 2082: return "BeyondCustomizeProfileStartAudit";
    case 2083: return "BeyondCustomizeProfileSwitch";
    case 2084: return "BeyondActivityOpen";
    case 2085: return "BeyondActivityClose";
    case 2086: return "BeyondActivityCommonContentClose";
    case 2087: return "BeyondActivityInfoUpdate";
    case 2088: return "BeyondActivityStageUpdate";
    case 2089: return "BeyondActivityCoinInfoUpdate";
    case 2090: return "BeyondActivityScoreInfoUpdate";
    case 2091: return "BeyondActivityTakeReward";
    case 2092: return "BeyondActivityLevelRelatedInfoUpdate";
    case 2093: return "BeyondLevelRelatedInfoUpdate";
    case 2094: return "BeyondActivityFashionWelfareTakeDailyReward";
    case 2095: return "BeyondActivityFashionWelfareTakeAllScoreReward";
    case 2096: return "BeyondActivityFashionWelfareTargetRewardChanged";
    case 2097: return "BeyondActivityFashionWelfareIsPopularLevel";
    case 2098: return "BeyondActivityFashionWelfareReceiveDailyReward";
    case 2099: return "BeyondActivityFashionWelfareReceiveScoreReward";
    case 2100: return "BeyondCommunityGetLibLevelList";
    case 2101: return "BeyondCommunityGetAnnual26Heat";
    case 2102: return "BeyondGachaGiftFriendBriefListUpdated";
    case 2103: return "BeyondShopGiftFriendBriefListUpdated";
    case 2104: return "BeyondGachaGiftSendCheck";
    case 2105: return "BeyondGachaGiftFriendDetailInfoUpdated";
    case 2106: return "BeyondGachaGiftFriendBriefUpdated";
    case 2107: return "BeyondGachaGiftModeUpdated";
    case 2108: return "BeyondGachaGiftModeDataUpdated";
    case 2109: return "BeyondGachaGiftBlessTextCheckResult";
    case 2110: return "BeyondGachaGiftSendSuccess";
    case 2111: return "BeyondShopGiftSendSuccess";
    case 2112: return "BeyondGiftHistoryUpdated";
    case 2113: return "BeyondGiftHistoryRsp";
    case 2114: return "BeyondGiftDeleteHistory";
    case 2115: return "BeyondGiftBriefHistoryListFetched";
    case 2116: return "PostRecvBeyondGiftDataNotify";
    case 2117: return "BeyondGiftNotifyNeedClose";
    case 2118: return "BeyondGiftDialogOpen";
    case 2119: return "BeyondPlayerSocialInfoUpdated";
    case 2120: return "BeyondPlayerSocialLikeCntUpdated";
    case 2121: return "BeyondPlayerSocialLikeRsp";
    case 2122: return "BeyondPlayerTagUpdated";
    case 2123: return "FeatureBlockSocialInfoUpdated";
    case 2124: return "BeyondGetPlayerSocialDisplayCostume";
    case 2125: return "PostBeyondMall3DSceneSetup";
    case 2126: return "RefreshBeyondMallPage";
    case 2127: return "BeyondMallSwitchToShopTypeAndRefresh";
    case 2128: return "PreTryOpenBeyondMallPage";
    case 2129: return "PostTryOpenBeyondMallPage";
    case 2130: return "BeyondShopCartGoodsInfoUpdated";
    case 2131: return "BeyondShopCartBydMcoinCostInfoUpdated";
    case 2132: return "BeyondRerunDiscountNumNotify";
    case 2133: return "BeyondMcoinExchangeFreeMcoinSuccess";
    case 2134: return "PostBeyondEnterSceneDisplay3DSceneSetup";
    case 2135: return "PostBeyondWorldPrepareShowDataNotify";
    case 2136: return "OnGetBeyondLoadingWebImageInfoSuccess";
    case 2137: return "PostBeyondCurDungeonDataStatusNotify";
    case 2138: return "BeyondCurDungeonDataStatusNotifyDownloadFinish";
    case 2139: return "BeyondCommunityOtherLevelRecommendListUpdated";
    case 2140: return "BeyondCommunityMonthlyHotLevelUpdated";
    case 2141: return "BeyondCommunityGetDataFailed";
    case 2142: return "BeyondCommunityGetBbsDataFinish";
    case 2143: return "BeyondCommunityGetBbsDataDetailFinish";
    case 2144: return "BeyondCommunityLikeRefresh";
    case 2145: return "BeyondCommunityRecommendGetDataUpdated";
    case 2146: return "BeyondClassicModeTeamChangeFailed";
    case 2147: return "BeyondLevelDetailWebDataReceive";
    case 2148: return "BeyondPlayerSocialInfoReceive";
    case 2149: return "BeyondLevelFriendRespReceive";
    case 2150: return "BeyondLevelRetailRecRespReceive";
    case 2151: return "BeyondFashionWelfareIsPopularLevelRspReceive";
    case 2152: return "BeyondLevelRelatedInfoRspReceive";
    case 2153: return "BeyondGetUserLevelGameRecordsRespReceive";
    case 2154: return "BeyondLevelHotCommendReceive";
    case 2155: return "BeyondLevelInFloorCommendReceive";
    case 2156: return "BeyondGetChipBriefRespReceive";
    case 2157: return "BeyondGetLevelAchievementUnlockInfoRespReceive";
    case 2158: return "BeyondChangelogReceive";
    case 2159: return "BeyondGetAllRankingList";
    case 2160: return "BeyondGetTopRankingList";
    case 2161: return "BeyondGetTailRankingList";
    case 2162: return "BeyondGetAllTierList";
    case 2163: return "BeyondGetTopTierList";
    case 2164: return "BeyondGetTailTierList";
    case 2165: return "BeyondGetFriendChipBriefRsp";
    case 2166: return "BeyondCommentDeleted";
    case 2167: return "BeyondGetMaxAchievementCount";
    case 2168: return "BeyondPublishCommentReceive";
    case 2169: return "BeyondReplyCommentReceive";
    case 2170: return "OnGetBeyondLevelPlatinumAchievementImage";
    case 2171: return "OnGetBeyondLevelDLcImage";
    case 2172: return "BeyondGetPlatinumFinishedInfo";
    case 2173: return "GetUserLevelTierBestRecord";
    case 2174: return "BeyondGetUserTrendData";
    case 2175: return "BeyondGetUserCommentRsp";
    case 2176: return "BeyondGetMultiLangRsp";
    case 2177: return "BeyondSetDisplayPlatinumRsp";
    case 2178: return "BeyondLevelCommentLikeRefresh";
    case 2179: return "BeyondLevelCommentDislikeRefresh";
    case 2180: return "BeyondLevelLibraryMainWebDataReceive";
    case 2181: return "BeyondGetUserPlayTotalInfoRespReceive";
    case 2182: return "BeyondLevelCollectionRefresh";
    case 2183: return "BeyondLevelLibraryFavouriteLevelChipInfoReceive";
    case 2184: return "BeyondLevelLibraryRefresh";
    case 2185: return "BeyondLibraryBatchDeleteStateChange";
    case 2186: return "BeyondLibrarySingleDataGiven";
    case 2187: return "BeyondLibraryFocusInput";
    case 2188: return "BeyondLibraryActivateInput";
    case 2189: return "BeyondPlayActivityChipDataList";
    case 2190: return "BeyondPlayActivityDungeonAndBriefInfo";
    case 2191: return "BeyondPlayActivityOnBeyondGetRankingListRankRsp";
    case 2192: return "BeyondGetUserPlayTrendInfoPageResp";
    case 2193: return "BeyondGetUserLatestPlayTrendInfoResp";
    case 2194: return "BeyondLevelLibraryGetDungeonBriefRsp";
    case 2195: return "BeyondLevelLibraryFoldToggleFocus";
    case 2196: return "PostGetBeyondWishItemRsp";
    case 2197: return "PostSetBeyondWishItemRsp";
    case 2198: return "PostBeyondWishItemNotify";
    case 2199: return "BeyondRewardStateUpdate";
    case 2200: return "BeyondVirtualDialPrepareDialogReleaseButtonPre";
    case 2201: return "BeyondEquipStuffBagSlotChange";
    case 2202: return "BeyondRuntimeEquipSlotUpdate";
    case 2203: return "BeyondRuntimeHighlightSlot";
    case 2204: return "BeyondRuntimeCancalHighligh";
    case 2205: return "BeyondSelfBagPluginChanged";
    case 2206: return "BeyondSelfEquipPluginChanged";
    case 2207: return "BeyondShopDataUpdated";
    case 2208: return "BeyondShopUIRefresh";
    case 2209: return "BeyondShopDisappear";
    case 2210: return "BeyondDropDataUpdated";
    case 2211: return "BeyondDropDisappear";
    case 2212: return "BeyondDropUIRefresh";
    case 2213: return "BeyondInventoryPanelStateUpdated";
    case 2214: return "BeyondShopEnterSellMode";
    case 2215: return "BeyondShopSellFinished";
    case 2216: return "BeyondBagAllSlotsUpdated";
    case 2217: return "BeyondBagSlotsUpdated";
    case 2218: return "BeyondBagItemRefIdsUpdated";
    case 2219: return "BeyondBagCategoryItemsUpdated";
    case 2220: return "BeyondBagAllCurrencyUpdated";
    case 2221: return "BeyondBagSlotCountUpdated";
    case 2222: return "BeyondBagGuidItemUpdated";
    case 2223: return "BeyondBagItemCdUpdated";
    case 2224: return "BeyondItemOwnerUpdated";
    case 2225: return "BeyondBagItemCdFinish";
    case 2226: return "BeyondDragDropBagItem";
    case 2227: return "BeyondItemTipClose";
    case 2228: return "BeyondShopTemplateGoodCountChanged";
    case 2229: return "BeyondShopTemplateGoodTableColChanged";
    case 2230: return "BeyondShopTemplateGoodRefStuffChanged";
    case 2231: return "BeyondCommonCountChanged";
    case 2232: return "BeyondCommonTableColChanged";
    case 2233: return "BeyondHallRoomEnter";
    case 2234: return "BeyondHallRoomLeave";
    case 2235: return "BeyondTrialWhiteListChange";
    case 2236: return "BeyondDownloadTaskUpdate";
    case 2237: return "BeyondRoomCaptainChange";
    case 2238: return "BeyondRoomPlayerExit";
    case 2239: return "BeyondRoomPlayerEnter";
    case 2240: return "BeyondEditorRoomReady";
    case 2241: return "BeyondEditorRoomUpdate";
    case 2242: return "BeyondRecommendLevelListUpdated";
    case 2243: return "BeyondRecommendShowLevelChanged";
    case 2244: return "BeyondRecommendShowLevelChangeFailed";
    case 2245: return "BeyondRecommendShowLevelPreferredRankingIdChanged";
    case 2246: return "BeyondGetRecommendLevelChipDataList";
    case 2247: return "BeyondGetRecommendLevelRankInfoData";
    case 2248: return "BeyondGetPlayerInfoRecommendLevelRankInfoData";
    case 2249: return "BeyondGetRecommendLevelRankNumData";
    case 2250: return "BeyondGetPlayerInfoRecommendLevelChipDataList";
    case 2251: return "BeyondRecommendLevelRankUpdated";
    case 2252: return "BeyondGetBatchTinyLevelInfoDataList";
    case 2253: return "BeyondEnviroChangeLight";
    case 2254: return "BeyondCollectPageFrontendChanged";
    case 2255: return "BeyondBattlePassLevelChanged";
    case 2256: return "BeyondBattlePassDataUpdated";
    case 2257: return "BeyondBattlePassMissionUpdated";
    case 2258: return "BeyondBattlePassProductPay";
    case 2259: return "BeyondBattlePassPurchased";
    case 2260: return "BeyondBattlePassMissionRewardItemAdd";
    case 2261: return "BeyondBattlePassLevelRewardItemAdd";
    case 2262: return "BeyondBattlePassPaidRewardItemAdd";
    case 2263: return "BeyondLevelLangPacketLoaded";
    case 2264: return "BeyondCreatorContestInfoUpdated";
    case 2265: return "CeremonyGhostTeamBarValueChange";
    case 2266: return "CeremonyGhostTeamBarBuffStart";
    case 2267: return "CeremonyBattleRefreshMonsterScore";
    case 2268: return "CeremonyBattleRefreshTargetScore";
    case 2269: return "UpdateInstrumentalEnsemble";
    case 2270: return "InstrumentalEnsembleMatchEnd";
    case 2271: return "InstrumentalEnsembleMatchFailed";
    case 2272: return "InstrumentalEnsemblePlayEnd";
    case 2273: return "MusicMainPageBackToFirst";
    case 2274: return "MusicMainPageBackToSelectSubPage";
    case 2275: return "MusicBookGuideNext";
    case 2276: return "MusicGameBookDataUpdate";
    case 2277: return "MusicGameEditorDirty";
    case 2278: return "MusicGameUploadSuccess";
    case 2279: return "MusicGameUgcDataDirty";
    case 2280: return "MusicGameMetronomeSettingChange";
    case 2281: return "MusicGameUgcReportRsp";
    case 2282: return "MusicGameUgcUpdateClientSetting";
    case 2283: return "UpdateMusicGameBookDraftInvite";
    case 2284: return "MusicGameBookDraftInviteFailed";
    case 2285: return "MusicGameBookUpdateUgcMusicData";
    case 2286: return "MusicGameBookMpEnd";
    case 2287: return "MusicGameBookModListUpdate";
    case 2288: return "LanV5GreetingCardStickerAdd";
    case 2289: return "LanV5GreetingCardStickerRemove";
    case 2290: return "LanV5GreetingCardStickerScale";
    case 2291: return "LanV5GreetingCardSubmit";
    case 2292: return "LanV5GreetingCardGetReceivedCardMinimum";
    case 2293: return "LanV5GreetingCardGetReceivedCardBrief";
    case 2294: return "LanV5GreetingCardGetReceivedCardDetail";
    case 2295: return "LanV5GreetingCardSetReceivedCardFavorite";
    case 2296: return "LanV5GreetingCardLevelFinish";
    case 2297: return "LanV5GreetingCardSendNpcGift";
    case 2298: return "LanV5GreetingCardSendNpcGiftFinish";
    case 2299: return "LanV5GreetingCardGetEditSlotCards";
    case 2300: return "LanV5GreetingCardSaveEditSlotCardSuccess";
    case 2301: return "LanV5GreetingCardSaveEditSlotCardFail";
    case 2302: return "LanV5GreetingCardEditSlotCardUpdate";
    case 2303: return "LanV5GreetingCardGetRecommandCommunityCards";
    case 2304: return "LanV5GreetingCardGetFavoriteCommunityCards";
    case 2305: return "LanV5GreetingCardCommunityCardUpdate";
    case 2306: return "LanV5GreetingCardSetCommunityCardLiked";
    case 2307: return "LanV5GreetingCardSetCommunityCardFavorite";
    case 2308: return "LanV5GreetingCardSearchCommunityCard";
    case 2309: return "LanV5GreetingCardGetUgcCardDetail";
    case 2310: return "LanV5GreetingCardGetUgcCardDetailFailed";
    case 2311: return "LanV5GreetingCardGetStampValue";
    case 2312: return "PuzzleFighterPlayerInfoUpdate";
    case 2313: return "PuzzleFighterPlayerJoin";
    case 2314: return "PuzzleFighterSettle";
    case 2315: return "PuzzleFighterRestart";
    case 2316: return "PuzzleFighterRecover";
    case 2317: return "NatlanRaceGalleryPreStart";
    case 2318: return "NatlanRaceGalleryStart";
    case 2319: return "NatlanRaceGalleryRecover";
    case 2320: return "NatlanRaceGalleryRefresh";
    case 2321: return "NatlanRaceGalleryCowLevelStart";
    case 2322: return "GetEffigyChallengeV6SelectDifficultyRsp";
    case 2323: return "EffigyV6ChallengeBuffSelect";
    case 2324: return "EffigyV6ChallengeSocialDetail";
    case 2325: return "EffigyV6ChallengeSocialPublic";
    case 2326: return "EffigyV6ChallengeSocialPublicInvalid";
    case 2327: return "HerculesBattleV3GalleryStart";
    case 2328: return "HerculesBattleV3GalleryUpdateRecover";
    case 2329: return "HerculesBattleV3GalleryUpdate";
    case 2330: return "HerculesBattleV3ShowReminder";
    case 2331: return "HerculesBattleV3CloseReminder";
    case 2332: return "HerculesBattlePreJumpNodeFinish";
    case 2333: return "HerculesBattleJumpNodeFinish";
    case 2334: return "HerculesBattleJumpPreAccumulateNodeFinish";
    case 2335: return "HerculesBattlePreJumpAccumulateNodeFinish";
    case 2336: return "HerculesBattleJumpAccelerateNodeFinish";
    case 2337: return "HerculesBattleJumpAcceleratePreAccumulateNodeFinish";
    case 2338: return "OnGetRelicRecommendData";
    case 2339: return "LanV5UnLockReminder";
    case 2340: return "InazumaBadmintonGalleryPreStart";
    case 2341: return "InazumaBadmintonGalleryStart";
    case 2342: return "InazumaBadmintonGalleryStop";
    case 2343: return "InazumaBadmintonGalleryRecover";
    case 2344: return "InazumaBadmintonTriggerPerfect";
    case 2345: return "InazumaBadmintonTriggerTutorial";
    case 2346: return "DoppelgangerPuzzleObservation";
    case 2347: return "DoppelgangerPuzzleStartRound";
    case 2348: return "DoppelgangerPuzzleStartRecord";
    case 2349: return "DoppelgangerPuzzlePauseRecord";
    case 2350: return "DoppelgangerPuzzleFinishRecord";
    case 2351: return "DoppelgangerPuzzleRefresh";
    case 2352: return "DoppelgangerPuzzleRoundOver";
    case 2353: return "DoppelgangerPuzzleAssist";
    case 2354: return "DoppelgangerPuzzleRetry";
    case 2355: return "FishingJoyBuffUpdate";
    case 2356: return "FishingJoyHitUpdate";
    case 2357: return "FishingJoyComboUpdate";
    case 2358: return "FishingJoyCatchSpecialFish";
    case 2359: return "FishingJoyGalleryStart";
    case 2360: return "GetActivitySocialBriefRsp";
    case 2361: return "TowerChallengeStageStart";
    case 2362: return "TowerChallengeStageEnd";
    case 2363: return "TowerChallengePickUpBuff";
    case 2364: return "TowerChallengeFriendBuffUpdate";
    case 2365: return "TowerChallengeStartFloorUpdate";
    case 2366: return "TowerChallengeSocialDetail";
    case 2367: return "TowerChallengeFriendBuffCountUpdate";
    case 2368: return "TowerChallengeSocialPublic";
    case 2369: return "TowerChallengeSocialPublicInvalid";
    case 2370: return "TowerChallengeFriendBuffToggleUpdate";
    case 2371: return "TalkOnlyShowContent";
    case 2372: return "TalkContextDataUpdate";
    case 2373: return "FreeMizukiFocusEntity";
    case 2374: return "CutScenePageCloseRaycastTarget";
    case 2375: return "OnGetSetWeaponLockStateBatchRsp";
    case 2376: return "ADShootingFinish";
    case 2377: return "ADShootingRecordUpdate";
    case 2378: return "ADShootingGetFriendRecord";
    case 2379: return "ADShootingGetFriendRecordFailed";
    case 2380: return "DrillBattleGalleryUpdate";
    case 2381: return "DrillBattleReminderShow";
    case 2382: return "DrillBattleStartTipsShow";
    case 2383: return "AbyssCoreGalleryStart";
    case 2384: return "AbyssCoreGalleryUpdate";
    case 2385: return "AbyssCoreGalleryStop";
    case 2386: return "NatlanArenaPreviewAvatarInfoAdded";
    case 2387: return "NatlanArenaBuffGalleryStart";
    case 2388: return "NatlanArenaBossGalleryStart";
    case 2389: return "NatlanArenaBehaviorAdd";
    case 2390: return "NatlanArenaKillHPNumAdd";
    case 2391: return "NatlanArenaBuffGalleryStop";
    case 2392: return "MultiStageHpBarChange";
    case 2393: return "PartyScoreUpdate";
    case 2394: return "PartyHurtNotice";
    case 2395: return "PartyShowGetPropNotice";
    case 2396: return "PartyMissileCountdownUINotice";
    case 2397: return "PartySpecialReminder";
    case 2398: return "PartySettle";
    case 2399: return "PartyCloseMapRandomPage";
    case 2400: return "DrugCollectShowPlayerChoosePanel";
    case 2401: return "DrugCollectShowRedirectorChoosePanel";
    case 2402: return "DrugCollectControlled";
    case 2403: return "DrugCollectChatSkill";
    case 2404: return "DrugCollectChatSwitch";
    case 2405: return "DrugCollectChatProgress";
    case 2406: return "DrugCollectChatHealth";
    case 2407: return "DrugCollectScoreUpdate";
    case 2408: return "DrugCollectHealthUpdate";
    case 2409: return "PlayerJumpPosDelay";
    case 2410: return "ThemeParkZooDoGachaRsp";
    case 2411: return "ThemeParkZooSaveDeployRsp";
    case 2412: return "ThemeParkZooPutAnimalItem";
    case 2413: return "ThemeParkTriathlonGalleryUpdate";
    case 2414: return "ThemeParkSimAvatarQuestAccept";
    case 2415: return "ThemeParkSimAvatarQuestFinish";
    case 2416: return "ThemeParkSimCloseQuestSubpage";
    case 2417: return "ThemeParkSimGalleryInfoUpdate";
    case 2418: return "ThemeParkSimRoundResume";
    case 2419: return "ThemeParkSimRoundSettle";
    case 2420: return "ThemeParkSimFoodBuffActivated";
    case 2421: return "ThemeParkSimFoodBuffGachaFail";
    case 2422: return "ThemeParkSimGoalProgressUpdate";
    case 2423: return "ThemeParkSimBuffChange";
    case 2424: return "ThemeParkSimBuffProgressUpdate";
    case 2425: return "ThemeParkSimCloseReminder";
    case 2426: return "ThemeParkSimUpgradeFacilityFailed";
    case 2427: return "ThemeParkSimExpandFacilityFailed";
    case 2428: return "ThemeParkStartTrialLevelFailed";
    case 2429: return "ThemeParkSimEmployeeUpgradeCost";
    case 2430: return "ThemeParkSimUpgradeEmployee";
    case 2431: return "ThemeParkSimUpgradeEmployeeFailed";
    case 2432: return "ThemeParkSimHireEmployeeFailed";
    case 2433: return "ThemeParkSimFireEmployee";
    case 2434: return "ThemeParkSimDeployEmployee";
    case 2435: return "ThemeParkSimUndeployEmployee";
    case 2436: return "ThemeParkSimNewbieGuideNarrate";
    case 2437: return "ThemeParkSimNewbieGuideNarrateAbort";
    case 2438: return "ThemeParkSimNewbieGuideUIMask";
    case 2439: return "ThemeParkSimNewbieGuideEnd";
    case 2440: return "ThemeParkSimGalleryStart";
    case 2441: return "DiversityBattleChangeDifficulty";
    case 2442: return "DiversityBattlePreviewAvatarInfoAdded";
    case 2443: return "DiversityBattleSocialPublicInvalid";
    case 2444: return "DiversityBattleScoreChange";
    case 2445: return "DiversityBattleStateChange";
    case 2446: return "DiversityBattleSocialPublic";
    case 2447: return "EscoffierCookingGalleryUpdate";
    case 2448: return "EscoffierCookingGallleryStageStart";
    case 2449: return "EscoffierCookingGalleryStageEnd";
    case 2450: return "EscoffierCookingGalleryUpdateStageEnd";
    case 2451: return "EscoffierCookingGalleryTargetUnfinished";
    case 2452: return "EscoffierCookingGalleryFlavorBarComplete";
    case 2453: return "EscoffierCookingReminderAppeared";
    case 2454: return "EscoffierCookingReminderDisappeared";
    case 2455: return "MvMv2PvpGalleryStart";
    case 2456: return "MvMv2SimulateGalleryStart";
    case 2457: return "MvMv2PveGalleryRecover";
    case 2458: return "MvMv2PvpGalleryRecover";
    case 2459: return "MvMv2PveMonsterDeploy";
    case 2460: return "MvMv2PvpMonsterDeploy";
    case 2461: return "MvMv2ProgressUpdate";
    case 2462: return "MvMv2PveBuildDestroyed";
    case 2463: return "MvMv2GameOver";
    case 2464: return "MvMv2PveGalleryStop";
    case 2465: return "MvMv2PvpGalleryStop";
    case 2466: return "MvMv2AvailableCardNotify";
    case 2467: return "MvMv2PvpMultiPlayerInfoCheck";
    case 2468: return "MvMv2PvpSelfProgressUpdate";
    case 2469: return "MvMv2PvpTargetProgressUpdate";
    case 2470: return "MvMv2PvpSelfBuildDestroyed";
    case 2471: return "MvMv2PvpTargetBuildDestroyed";
    case 2472: return "MvMv2SimulateProgressUpdate";
    case 2473: return "MvMv2SimulateBuildDestroyed";
    case 2474: return "MvMv2PvpDefenseSetSuccess";
    case 2475: return "MvMv2InLevelAvailableCardNotify";
    case 2476: return "MvMv2DungeonInfoUpdate";
    case 2477: return "MvMv2PvpPreStart";
    case 2478: return "MvMv2PvpPreStartEnd";
    case 2479: return "Saurus1V3GalleryUpdate";
    case 2480: return "Saurus1V3AttackUpdate";
    case 2481: return "Saurus1V3ScoreUpdate";
    case 2482: return "OnGetReliquaryDustRsp";
    case 2483: return "OnGetReliquaryDustSelectRsp";
    case 2484: return "RelicDustSelectNew";
    case 2485: return "OptionalResourceDownloadAskEnd";
    case 2486: return "SupportSkillInfoChange";
    case 2487: return "ShowSupportSkillReminder";
    case 2488: return "LeyLineChallengeReward";
    case 2489: return "LeyLineChallengeRewardExtra";
    case 2490: return "LeyLineChallengeResidentInfoUpdate";
    case 2491: return "LeyLineChallengePlayerInfoUpdate";
    case 2492: return "LeyLineChallengeFriendDataUpdate";
    case 2493: return "LeyLineChallengePopularAvatarUpdate";
    case 2494: return "LeyLineChallengePopularOutdate";
    case 2495: return "LeyLineChallengeSetReliquary";
    case 2496: return "LeyLineChallengeAvailableReliquaryUpdate";
    case 2497: return "LeyLineChallengeTeamCreated";
    case 2498: return "LeyLineChallengeDungeonContextUpdate";
    case 2499: return "LeyLineChallengeTeamOperateFailed";
    case 2500: return "LeyLineChallengeMpRoundLocked";
    case 2501: return "LeyLineChallengeRecordCommited";
    case 2502: return "LeyLineChallengeTeamAdjustSucceed";
    case 2503: return "LLCBattleGalleryPreStart";
    case 2504: return "LLCBattleGalleryStart";
    case 2505: return "ShowLLCPopularEffect";
    case 2506: return "LLCBattleGalleryStop";
    case 2507: return "DungeonTeamBuilderDismiss";
    case 2508: return "DungeonTeamBuilderInviteFailed";
    case 2509: return "DungeonTeamBuilderPlayerReply";
    case 2510: return "DungeonTeamBuilderAllInfoUpdate";
    case 2511: return "SlimeCannonV2HPUpdate";
    case 2512: return "SlimeCannonV2KillScoreUpdate";
    case 2513: return "SlimeCannonV2WaveUpdate";
    case 2514: return "CooperateChallengeV2GalleryStart";
    case 2515: return "CooperateChallengeV2HideBuffBar";
    case 2516: return "CooperateChallengeV2ShowBuffBar";
    case 2517: return "CooperateChallengeV2ShowCloseBtn";
    case 2518: return "CooperateChallengeV2ChangeDifficulty";
    case 2519: return "OnFruitPickGameStart";
    case 2520: return "OnFruitPickGameRestart";
    case 2521: return "BillBoardV2ElementShieldUpdate";
    case 2522: return "AutoChessInLevelArtifactSelected";
    case 2523: return "AutoChessInLevelArtifactRefresh";
    case 2524: return "AutoChessInLevelGridUpdate";
    case 2525: return "AutoChessInLevelChessUpdate";
    case 2526: return "AutoChessInLevelChessLevelUp";
    case 2527: return "AutoChessInLevelEquipUpdate";
    case 2528: return "AutoChessInLevelShopUpdate";
    case 2529: return "AutoChessInLevelShopRefresh";
    case 2530: return "AutoChessInLevelCampUpdate";
    case 2531: return "AutoChessInLevelCounterUpdate";
    case 2532: return "AutoChessInLevelStartChallenge";
    case 2533: return "AutoChessInLevelOpenTips";
    case 2534: return "AutoChessInLevelCloseTips";
    case 2535: return "AutoChessInLevelPopTips";
    case 2536: return "AutoChessInLevelWearEquip";
    case 2537: return "AutoChessInLevelTakeOffEquip";
    case 2538: return "AutoChessInLevelChessDuplicator";
    case 2539: return "AutoChessInLevelReminderShow";
    case 2540: return "AutoChessNodeEnter";
    case 2541: return "AutoChessOptionSelect";
    case 2542: return "AutoChessInLevelFightSettle";
    case 2543: return "AutoChessEquipShopRefresh";
    case 2544: return "AutoChessEquipShopLeave";
    case 2545: return "AutoChessEquipShopBuy";
    case 2546: return "AutoChessEquipShopSell";
    case 2547: return "AutoChessCoinChange";
    case 2548: return "AutoChessPackageDialogClose";
    case 2549: return "AutoChessNodeInfoUpdate";
    case 2550: return "AutoChessTalentUpgrade";
    case 2551: return "AutoChessGuideButtonUpdate";
    case 2552: return "AutoChessUpdateBillBoard";
    case 2553: return "AutoChessTipsHover";
    case 2554: return "AutoChessTipsFocus";
    case 2555: return "AutoChessTipsCloseFromJoypad";
    case 2556: return "AutoChessTipsTryTakeOffEquip";
    case 2557: return "AutoChessBossInfoDialogOpenTips";
    case 2558: return "DungeonPlayerOrderChange";
    case 2559: return "BossFirstPassRewardRefresh";
    case 2560: return "BossFirstPassRewardItemAdded";
    case 2561: return "ResortBuildShowBanner";
    case 2562: return "ResortBuildBannerFadeOut";
    case 2563: return "GraffitiSniperGalleryStart";
    case 2564: return "GraffitiSniperGalleryUpdate";
    case 2565: return "GraffitiSniperGalleryStop";
    case 2566: return "PaintProgressGalleryInfoUpdate";
    case 2567: return "PaintSeeliePaletteCloseDialog";
    case 2568: return "AgentReconEvidenceDialogClose";
    case 2569: return "AgentReconPuzzleSuccess";
    case 2570: return "AgentReconGalleryStop";
    case 2571: return "HolidayResortAdvInPlayStartLevel";
    case 2572: return "HolidayResortAdvRestartLevel";
    case 2573: return "HolidayResortAdvQuit";
    case 2574: return "HolidayResortAdvShowBubble";
    case 2575: return "HolidayResortAdvRestartLevelOnDeath";
    case 2576: return "HolidayResortGraffitiGalleryStart";
    case 2577: return "HolidayResortGraffitiHeatChange";
    case 2578: return "HolidayResortGraffitiHeatMaxValue";
    case 2579: return "HolidayResortGraffitiProgress";
    case 2580: return "HolidayResortGraffitiTrappedStart";
    case 2581: return "HolidayResortGraffitiTriggerSlotEffect";
    case 2582: return "HolidayResortGraffitiGalleryStartNoRecover";
    case 2583: return "HolidayResortGraffitiPlayCutscene";
    case 2584: return "HolidayResortGraffitiColorHint";
    case 2585: return "HolidayResortSniperGalleryStart";
    case 2586: return "HolidayResortSniperGalleryStop";
    case 2587: return "HolidayResortSniperGalleryDataUpdate";
    case 2588: return "HolidayResortBattleGalleryStart";
    case 2589: return "HolidayResortBattleGalleryStop";
    case 2590: return "HolidayResortBattleGalleryDataUpdate";
    case 2591: return "BeyondPrivateHallEditorSwitchState";
    case 2592: return "BeyondHallContextDataUpdate";
    case 2593: return "BeyondHallListUpdate";
    case 2594: return "BeyondHallPlayerDataUpdate";
    case 2595: return "BeyondHallDataBatchUpdate";
    case 2596: return "BeyondPrivateHallBriefUpdate";
    case 2597: return "BeyondPrivateHallCreateSuccess";
    case 2598: return "BeyondPrivateHallEditorSwitchCamera";
    case 2599: return "BeyondPrivateHallUndeployAllFacility";
    case 2600: return "BeyondPrivateHallResetCameraToSceneCenter";
    case 2601: return "BeyondPrivateHallUndo";
    case 2602: return "BeyondPrivateHallRedo";
    case 2603: return "BeyondPrivateHallSwitchMultiSelectMode";
    case 2604: return "BeyondPrivateHallPasswordIncorrect";
    case 2605: return "BeyondPrivateHallPasswordCorrect";
    case 2606: return "BeyondPrivateHallSelectChange";
    case 2607: return "BeyondPrivateHallUIDragStart";
    case 2608: return "BeyondPrivateHallUIDragEnd";
    case 2609: return "BeyondPrivateHallCameraFocus";
    case 2610: return "BeyondPrivateHallPerformPlacement";
    case 2611: return "BeyondPrivateHallLodChange";
    case 2612: return "BeyondGetFreeDlc";
    case 2613: return "BeyondGetPaidDlc";
    case 2614: return "BeyondCombatEffectOverAllocate";
    case 2615: return "WorldWatcherInfoUpdate";
    case 2616: return "WorldWatcherItemAdd";
    case 2617: return "MoonPhaseLevelUpdateMainPage";
    case 2618: return "MoonPhaseLevelUpdate";
    case 2619: return "MoonPhaseTypeUpdate";
    case 2620: return "SetMoonOvergrowBarAnimatorTrigger";
    case 2621: return "RobotVacuumVehicleOn";
    case 2622: return "RobotVacuumVehicleOff";
    case 2623: return "NodKraiTourParkourGalleryPreStart";
    case 2624: return "NodKraiTourParkourGalleryStart";
    case 2625: return "NodKraiTourParkourGalleryRecover";
    case 2626: return "NodKraiTourParkourGalleryRefresh";
    case 2627: return "NodkraiTourHackGalleryStart";
    case 2628: return "NodkraiTourHackGalleryRecover";
    case 2629: return "NodkraiTourHackGalleryStop";
    case 2630: return "NodkraiTourRoboGalleryUpdate";
    case 2631: return "MateCompeteVSStart";
    case 2632: return "MateCompeteVSStop";
    case 2633: return "NightwatLanternGalleryUpdate";
    case 2634: return "TrialAvatarGalleryUpdate";
    case 2635: return "PhotoV7ActionDone";
    case 2636: return "BomberV3TransitFinish";
    case 2637: return "LockStepV2Recovery";
    case 2638: return "SaveAvatarsToNewBackupTeam";
    case 2639: return "GallantPathInfoNotify";
    case 2640: return "LocalLegendInfoUpdate";
    case 2641: return "LocalLegendGroupRewardItemAdd";
    case 2642: return "RoleCombatTarotExchangeInviteReply";
    case 2643: return "RoleCombatTarotExchangeInviteReplyRsp";
    case 2644: return "RoleCombatTarotExchangeUpdate";
    case 2645: return "RoleCombatTarotExchangeFinish";
    case 2646: return "RoleCombatSetTarotWish";
    case 2647: return "RoleCombatGetFriendTarotInfo";
    case 2648: return "RoleCombatGetTarotExchangeRecord";
    case 2649: return "WeekActiveUpdate";
    case 2650: return "WeekActiveDetailUpdate";
    case 2651: return "WeekActiveGetReward";
    case 2652: return "SceneUISetupReady";
    case 2653: return "NodKraiOfferingLevelUpdate";
    case 2654: return "PlayerExpTipsOpen";
    case 2655: return "PlayerExpTipsClose";
    case 2656: return "MoonPhaseTipsClose";
    case 2657: return "TicTacToePlayCmd";
    case 2658: return "RobotAbyssalReminderAppear";
    case 2659: return "RobotAbyssalReminderDisappear";
    case 2660: return "RobotAbyssalPageReset";
    case 2661: return "RobotAbyssalGalleryUpdate";
    case 2662: return "RobotAbyssalPhaseEnd";
    case 2663: return "PostHandleGetAllSceneGalleryInfoRsp";
    case 2664: return "SumeruAdvPathwayGalleryStart";
    case 2665: return "SumeruAdvPathwayGalleryStop";
    case 2666: return "SumeruAdvPathwayGalleryDataUpdate";
    case 2667: return "SumeruAdvParkourGalleryStart";
    case 2668: return "SumeruAdvParkourGalleryStop";
    case 2669: return "SumeruAdvParkourGalleryDataUpdate";
    case 2670: return "SumeruAdvFightPreviewAvatarInfoAdded";
    case 2671: return "SumeruAdvFightResetRecordSuccess";
    case 2672: return "SumeruAdvFightBehaviorCountUpdate";
    case 2673: return "SumeruAdvFightAdvanceSettleOpen";
    case 2674: return "SumeruAdvFightStartPause";
    case 2675: return "SumeruAdvFightEndPause";
    case 2676: return "HumanDragonPuzzleLevelInfoUpdate";
    case 2677: return "HumanDragonPuzzleGalleryStart";
    case 2678: return "NeferInfoNotify";
    case 2679: return "NeferScanRsp";
    case 2680: return "NeferBuyGoodsRsp";
    case 2681: return "QuestNextReview";
    case 2682: return "AbyssWhisperReminderUpdate";
    case 2683: return "AbyssWhisperReminderAppeared";
    case 2684: return "AbyssWhisperReminderDisappeared";
    case 2685: return "BeyondItemAdd";
    case 2686: return "SnowRacePauseGalleryCountDown";
    case 2687: return "SnowRaceThrowScoreUpdate";
    case 2688: return "SnowRaceThrowGalleryStart";
    case 2689: return "SnowRaceCombatScoreUpdate";
    case 2690: return "SnowRaceHideGalleryDataUpdate";
    case 2691: return "SnowRaceHideCaught";
    case 2692: return "SnowRaceHideBecomeGhost";
    case 2693: return "SnowRaceHidePlayerSetAvatarNotify";
    case 2694: return "SnowRaceHidePlayerReadyNotify";
    case 2695: return "SnowRaceHideStageInfoUpdate";
    case 2696: return "SnowRaceHideSettle";
    case 2697: return "SnowRaceHideMiniMapFog";
    case 2698: return "SnowRaceHideFirstHunter";
    case 2699: return "SnowRaceHideLevelClearTag";
    case 2700: return "SnowRaceParkourUpdateScoreCollect";
    case 2701: return "NatlanDragonPartyScoreUpdate";
    case 2702: return "NatlanDragonPartyReminderUpdate";
    case 2703: return "NatlanDragonPartyKillReminderUpdate";
    case 2704: return "NatlanDragonPartyItemReminderUpdate";
    case 2705: return "NatlanDragonPartyMissleAimUpdate";
    case 2706: return "MagicInkEnergyBarStart";
    case 2707: return "MagicInkEnergyBarStop";
    case 2708: return "BirdPinballCreatePrepareBall";
    case 2709: return "BirdPinballLaunchBall";
    case 2710: return "BirdPinballLevelStateChange";
    case 2711: return "BirdPinballShowReminder";
    case 2712: return "BirdPinballShowDungeonTarget";
    case 2713: return "BirdPinballRefreshScore";
    case 2714: return "BirdPinballRefreshCombo";
    case 2715: return "BirdPinballShowScorePopup";
    case 2716: return "BirdPinballRefreshBallCount";
    case 2717: return "BirdPinballStartFever";
    case 2718: return "BirdPinballEndFever";
    case 2719: return "BirdPinballOpenRewardLevel";
    case 2720: return "BirdPinballCloseRewardLevel";
    case 2721: return "BirdPinballAchieveTarget";
    case 2722: return "BirdPinballPreBossDivision";
    case 2723: return "BirdPinballBossDivision";
    case 2724: return "HexenzirkelTeamBonusTips";
    case 2725: return "LanV6BattleGalleryStart";
    case 2726: return "LanV6BattleStartReminder";
    case 2727: return "LanV6BattleReminderUpdate";
    case 2728: return "LanV6BattleScoreUpdate";
    case 2729: return "LanV6BattlePauseGalleryCountDown";
    case 2730: return "LanV6BattleLevelUpInfoUpdate";
    case 2731: return "TPSAimChange";
    case 2732: return "TPSAimBlockChange";
    case 2733: return "TPSWeaponInit";
    case 2734: return "TPSWeaponSwitched";
    case 2735: return "TPSWeaponEquiped";
    case 2736: return "TPSAccessoryUnlocked";
    case 2737: return "RefreshTPSExpandUI";
    case 2738: return "RefreshTpsIceGunCharge";
    case 2739: return "TPSSupplyPreparedAmmo";
    case 2740: return "TPSSupplyMagazineAmmo";
    case 2741: return "TPSSetPcKeyMap";
    case 2742: return "TpsMercenariesInfoUpdate";
    case 2743: return "TpsMercenariesGalleryPreStart";
    case 2744: return "TpsMercenariesGalleryStart";
    case 2745: return "TpsMercenariesGalleryUpdate";
    case 2746: return "TpsMercenariesRewardItemAdd";
    case 2747: return "TpsMercenariesLevelUnlock";
    case 2748: return "LanV6LikeHintNotify";
    case 2749: return "LanV6LanternGiftSelect";
    case 2750: return "LanV6LanternGiftReceiveSuccess";
    case 2751: return "LanV6LanternFriendSelect";
    case 2752: return "LanV6CardRemoveSuccess";
    case 2753: return "LanV6CardFavoriteSuccess";
    case 2754: return "LanV6CardUpdateNotify";
    case 2755: return "LanV6LanternGiftReceive";
    case 2756: return "LanV6MapSelectDialogClose";
    case 2757: return "LanV6MapSelectDialogSelect";
    case 2758: return "AsyncGadgetDestroySuccess";
    case 2759: return "MonsterChessV2PhaseChange";
    case 2760: return "MonsterChessV2RecordInfoUpdate";
    case 2761: return "MonsterChessV2FightControllerInfoUpdate";
    case 2762: return "MonsterChessV2CardLevelChangeNotify";
    case 2763: return "MonsterChessV2TriggerSkillNotify";
    case 2764: return "MonsterChessV2DrawDialogUpdate";
    case 2765: return "MonsterChessV2CardStarUpNotify";
    case 2766: return "MonsterChessV2DetailDialogContextUpdate";
    case 2767: return "MonsterChessV2PrepareChosenListUpdate";
    case 2768: return "MonsterChessV2InLevelCameraReset";
    case 2769: return "MonsterChessV2FocusToDetailDialog";
    case 2770: return "MonsterChessV2FlagUpNotify";
    case 2771: return "OnTimeStopPhotoFinishPlayRsp";
    case 2772: return "OnTimeStopPhotoSkipStage1";
    case 2773: return "OnTimeStopPhotoGalleryStop";
    case 2774: return "LanV6ParkourUpdateScore";
    case 2775: return "LanV6ParkourReduceRunningCountdown";
    case 2776: return "LanV6ParkourEnableActionPanel";
    case 2777: return "LanV6DanmakuAvtarHpChange";
    case 2778: return "LanV6DanmakuProgressUpdate";
    case 2779: return "LanV6DanmakuGainAttackBuff";
    case 2780: return "LanV6DanmakuGainTimeBuff";
    case 2781: return "LanV6DanmakuGainCoin";
    case 2782: return "LanV6DanmakuGadgetBurst";
    case 2783: return "LanV6DanmakuBossAppear";
    case 2784: return "LanV6DanmakuBossHpChange";
    case 2785: return "LanV6DanmakuBossPhaseChange";
    case 2786: return "LanV6DanmakuTechGroupUpgrade";
    case 2787: return "LanV6DanmakuTechGroupUpgradeFail";
    case 2788: return "LanV6DanmakuTechUpgrade";
    case 2789: return "LanV6DanmakuTechUpgradeFail";
    case 2790: return "LanV6DanmakuSettle";
    case 2791: return "LanV6DanmakuAddIndicator";
    case 2792: return "LanV6DanmakuRemoveIndicator";
    case 2793: return "LanV6DanmakuBonusUpdate";
    case 2794: return "MallReplaceCardColumbinaFirstNotify";
    case 2795: return "TeamHideInfoRefresh";
    case 2796: return "ShowMapEffect";
    case 2797: return "HideMapEffect";
    case 2798: return "OperationCardProgressUpdate";
    case 2799: return "WxycReminderInterrupt";
    case 2800: return "CinePlayAnimatorEffectAttach";
    case 2801: return "CinePlayAnimatorEffectDetach";
    case 2802: return "TowerDefenseDataUpdate";
    case 2803: return "TowerDefenseMonsterDataUpdate";
    case 2804: return "TowerDefenseStartForReminder";
    case 2805: return "TowerDefenseSkillSelect";
    case 2806: return "TowerDefenseSGVInfoUpdate";
    case 2807: return "TowerDefenseTryClearTips";
    case 2808: return "TowerDefenseMonsterDie";
    case 2809: return "TowerDefenseMonsterArrive";
    case 2810: return "TowerDefenseCardSelectPageUpdate";
    case 2811: return "TowerDefenseChallengeSettle";
    case 2812: return "TowerDefenseWaveSettle";
    case 2813: return "TowerDefenseCameraChange";
    case 2814: return "TowerDefenseWaveUpdate";
    case 2815: return "TowerDefenseSwitchFight";
    case 2816: return "TowerDefenseMonsterPointUpdate";
    case 2817: return "TowerDefenseGuideButtonUpdate";
    case 2818: return "TowerDefenseGuideResetCamera";
    case 2819: return "TowerDefenseReturnToNormal";
    case 2820: return "TowerDefenseSwitchToWaiting";
    case 2821: return "TowerDefenseSwitchToPanelFocus";
    case 2822: return "TowerDefenseSwitchToDragging";
    case 2823: return "TowerDefenseSwitchToBuilding";
    case 2824: return "TowerDefenseSwitchToModify";
    case 2825: return "TowerDefenseFailDeploy";
    case 2826: return "TowerDefenseFullBuild";
    case 2827: return "TowerDefenseHideHintReminder";
    case 2828: return "TowerDefenseSwitchState";
    case 2829: return "TowerDefenseOccupiedUpdate";
    case 2830: return "CommanderWarTeamEnter";
    case 2831: return "CommanderWarTeamLeave";
    case 2832: return "CommanderWarMapChangeMode";
    case 2833: return "CommanderWarMapReleaseMist";
    case 2834: return "CommanderWarMapCameraMove";
    case 2835: return "CommanderWarMapForceShowMark";
    case 2836: return "BubbleDramaBladeGalleryPrestart";
    case 2837: return "BubbleDramaBladeGalleryStart";
    case 2838: return "BubbleDramaBladeGalleryRecover";
    case 2839: return "BubbleDramaBladeUpdateScore";
    case 2840: return "BubbleDramaAirFightUpdateScore";
    case 2841: return "UINotifyAttachToGVUpdate";
    case 2842: return "UINotifyAttachToGVRemove";
    case 2843: return "BeyondDlcFreeCoinExpire";
    case 2844: return "MonsterSnapPaintingRepairFinish";
    case 2845: return "MonsterSnapPaintingRepairStart";
    case 2846: return "FirmamentMnemoOfferingLevelUpdate";
    case 2847: return "QuestSceneViewDialogClose";
    case 2848: return "TalkOnlyShowContentButCanClick";
    case 2849: return "ShortVideoSearchUgcBrief";
    case 2850: return "ShortVideoUpdateBrief";
    case 2851: return "ShortVideoSaveRecord";
    case 2852: return "ShortVideoDeleteRecord";
    case 2853: return "ShortVideoGalleryInfoUpdate";
    case 2854: return "ShortVideoVoteSuccess";
    case 2855: return "ShortVideoLevelStatePreBegin";
    case 2856: return "ShortVideoRequestChangeAvatar";
    case 2857: return "ShortVideoLoadingDialogClose";
    case 2858: return "ShortVideoNotifyCountDownStart";
    case 2859: return "TradeShowShootingGalleryUpdate";
    case 2860: return "MusketChallengeGalleryStart";
    case 2861: return "MusketChallengeGalleryUpdate";
    case 2862: return "MusketChallengeGalleryStop";
    case 2863: return "MusketChallengeClosePage";
    case 2864: return "TradeShowTdLevelStateUpdate";
    case 2865: return "TradeShowTdInLevelReminder";
    case 2866: return "TradeShowTdInteePanelAppear";
    case 2867: return "TradeShowTdInteePanelDisappear";
    case 2868: return "TradeShowTdInteeTowerEnergyGain";
    case 2869: return "TradeShowTdInteePickupEnergy";
    case 2870: return "TradeShowTdTutorialWave";
    case 2871: return "TradeShowTdExitDungeon";
    case 2872: return "TradeShowBattlePhaseUpdate";
    case 2873: return "TradeShowBattleScoreUpdate";
    case 2874: return "TradeShowStgHpUpdate";
    case 2875: return "TradeShowStgProgressUpdate";
    case 2876: return "TradeShowStgPhaseChange";
    case 2877: return "EntityEnergyBarUpdate";
    case 2878: return "FirmamentFoldOperate";
    case 2879: return "FirmamentFoldGuideUpdate";
    case 2880: return "FirmamentBookUpdateTarget";
    case 2881: return "FirmamentBookSelectDefault";
    case 2882: return "FirmamentBookDeselect";
    case 2883: return "FirmamentBookCreatePage";
    case 2884: return "FirmamentBookEnterPort";
    case 2885: return "FirmamentBookPleatFinish";
    case 2886: return "FirmamentBookPleating";
    case 2887: return "FirmamentBookSelectPoint";
    case 2888: return "FirmamentBookMove";
    case 2889: return "FirmamentElementCubeGalleryUpdate";
    case 2890: return "FirmamentDeformReady";
    case 2891: return "FirmamentDeformUnready";
    case 2892: return "NaturalistCaptureItemAdded";
    case 2893: return "BeastsBattleGMSettle";
    case 2894: return "BeastsBattleGMTakeDamage";
    case 2895: return "BeastsBattleShowOption";
    case 2896: return "BeastsBattleSelectOption";
    case 2897: return "BeastsBattleSpecialRoundFinish";
    case 2898: return "MapMarkShowStartReminder";
    case 2899: return "MapMarkShowGeneralReminder";
    case 2900: return "MapMarkShowSurveyProgress";
    case 2901: return "MapMarkShowSurveying";
    case 2902: return "MapMarkHelpChanged";
    case 2903: return "MapMarkCloseSurveying";
    case 2904: return "MapMarkHideActivityUI";
    case 2905: return "BeyondCustomUIWindowFrameButtonAction";
    case 2906: return "BeyondCustomUIWindowFrameToggleAction";
    case 2907: return "BeyondCustomUIWindowFrameToggleStateChanged";
    case 2908: return "BeyondCustomUIWindowFrameUpdate";
    case 2909: return "BeyondCustomUIRuntimePlayCustomEffect";
    case 2910: return "BeyondCustomUIWindowFrameChildDialogLoadFinish";
    case 2911: return "BeyondCustomUIRuntimeUpdateMsgQueue";
    case 2912: return "BeyondCustomUIRuntimeUpdateBuffList";
    case 2913: return "RefuseRecvGiftSet";
    case 2914: return "ColorBallLoadingClose";
    case 2915: return "TalkUpdateShowAdventureGlossary";
    case 2916: return "TalkUnlockAdventureGlossary";
    case 2917: return "DSCharacterDie";
    case 2918: return "LoliGolfDataUpdate";
    case 2919: return "LoliGolfStageUpdate";
    case 2920: return "LoliGolfHoleUpdate";
    case 2921: return "LoliGolfBuffUpdate";
    case 2922: return "LoliGolfReminderUpdate";
    case 2923: return "LoliGolfQTEUpdate";
    case 2924: return "LoliGolfWindUpdate";
    case 2925: return "LoliGolfSettlement";
    case 2926: return "LoliGolfSettlement2Loading";
    case 2927: return "LoliGolfItemTipsDialogClose";
    case 2928: return "LoliGolfItemTipsDialogCloseAll";
    case 2929: return "LoliGolfItemTipsDialogBtnClose";
    case 2930: return "LoliGolfPropSelectionChanged";
    case 2931: return "LoliGolfTreasureWeaselUpdate";
    case 2932: return "LoliGolfGuideAction";
    case 2933: return "LoliGolfInitialReminder";
    case 2934: return "LoliBattleGalleryStart";
    case 2935: return "LoliBattleGalleryStop";
    case 2936: return "LoliBattleDataUpdate";
    case 2937: return "LoliBattlePrepareCountdown";
    case 2938: return "NickRoomInfoUpdate";
    case 2939: return "BeyondLevelObjectiveRewardFetched";
    case 2940: return "MoonInfoAlarmWarningUpdate";
    case 2941: return "MoonCoreDefenderHpBarUpdate";
    case 2942: return "MoonCoreDefenderGalleryStart";
    case 2943: return "MoonCoreDefenderGalleryStop";
    case 2944: return "AquariumDivingGalleryStart";
    case 2945: return "AquariumDivingGalleryRecover";
    case 2946: return "AquariumDivingGalleryStop";
    case 2947: return "AquariumDivingGalleryDataUpdate";
    case 2948: return "AquariumDivingGalleryInfoUpdate";
    case 2949: return "AquariumDivingShowStartReminder";
    case 2950: return "AquariumDivingShowQTEFinishReminder";
    case 2951: return "AquariumDivingSwitchTargetTask";
    case 2952: return "AquariumDivingHideInLevelDialog";
    case 2953: return "AquariumDivingStartExit";
    case 2954: return "AquariumDivingInterruptExit";
    case 2955: return "AquariumDivingSpecialExitPointActivated";
    case 2956: return "AquariumDivingSpecialEventStart";
    case 2957: return "AquariumDivingSpecialEventUpdate";
    case 2958: return "AquariumDivingPlayerGetHit";
    case 2959: return "AquariumDivingPlayerHpChange";
    case 2960: return "AquariumDivingPlayerDie";
    case 2961: return "AquariumDetectFishSuccess";
    case 2962: return "AquariumDivingBagBroken";
    case 2963: return "MarionetteTeaTimeInfoUpdate";
    case 2964: return "MarionetteTeaTimeAccept";
    case 2965: return "MarionetteTeaTimeCancel";
    case 2966: return "OneShotGalleryContextUpdate";
    case 2967: return "OneShotStartAiming";
    case 2968: return "OneShotStopAiming";
    case 2969: return "AquariumFishingBuffUpdate";
    case 2970: return "AquariumFishingHitUpdate";
    case 2971: return "AquariumFishingWaveUpdate";
    case 2972: return "AquariumFishingGalleryEnd";
    case 2973: return "AquariumFishingComboUpdate";
    case 2974: return "AquariumFishingFundsUpdate";
    case 2975: return "TPLCloseMainPageDialog";
    case 2976: return "AquariumTaskFinished";
    case 2977: return "AquariumTechUnlocked";
    case 2978: return "AquariumPlayAreaGalleryStart";
    case 2979: return "AquariumPlayAreaGalleryStop";
    case 2980: return "AquariumItemGotBigDialogClosed";
    case 2981: return "AquariumSellDataUpdate";
    case 2982: return "AquariumSellGameEnd";
    case 2983: return "AquariumSellEditorDecoUpdate";
    case 2984: return "AquariumSellEditorBuyDecoUpdate";
    case 2985: return "AquariumSellItemPlaceCondition";
    case 2986: return "AvatarEnhanceHyperLinkClicked";
    case 2987: return "MarionetteTeaTimeReminderAppeared";
    case 2988: return "MarionetteTeaTimeReminderDisappeared";
    case 2989: return "MusicPartyHotReload";
    case 2990: return "MusicPartyJumpMusic";
    case 2991: return "RegionPreloadRefresh";
    case 2992: return "SnezhnayaTrainMapShowMarkEffect";
    case 2993: return "SnezhnayaTrainMapSetDestSuccess";
    case 2994: return "SnezhnayaTrainSetPlayerOnTrain";
    case 2995: return "TpsGlassesChatTopicDataUpdated";
    case 2996: return "RankedMatchShootingScoreUpdate";
    case 2997: return "RankedMatchShootingChallengeBannerAppeared";
    case 2998: return "RankedMatchShootingChallengeBannerDisappeared";
    case 2999: return "RankedMatchShootingFeverReminderAppeared";
    case 3000: return "RankedMatchShootingFeverReminderDisappeared";
    case 3001: return "RankedMatchShootingGalleryContextUpdate";
    case 3002: return "RankedMatchTrainPageStateUpdate";
    case 3003: return "RankedMatchTrainPageScoreUpdate";
    case 3004: return "RankedMatchTrainFinalStatsUpdate";
    case 3005: return "RankedMatchTrainPageTimerUpdate";
    case 3006: return "RankedMatchSnowBallScoreUpdate";
    case 3007: return "RankedMatchSnowBallEnergyUpdate";
    case 3008: return "RankedMatchSnowBallKillCountUpdate";
    case 3009: return "RankedMatchSnowBallGalleryStart";
    case 3010: return "RankedMatchSnowBallParamUpdate";
    case 3011: return "RankedMatchSnowBallEnergyInfoUpdate";
    case 3012: return "RankedMatchSnowBallRoundUpdate";
    case 3013: return "RankedMatchSnowBallRatioUpdate";
    case 3014: return "AdventurerStatueOnGetPlayerBriefUpdate";
    case 3015: return "AdventurerStatueParkourOpenChestRewardUpdate";
    case 3016: return "OnGetAdventurerStatueDriftBottleRecordRsp";
    case 3017: return "OnGetAdventurerStatuePickDriftBottleRsp";
    case 3018: return "OnGetAdventurerStatueThrowDriftBottleRsp";
    case 3019: return "OnFinishAdventurerStatuePickDriftBottle";
    case 3020: return "OnAdventurerStatueSendDriftBottleFinished";
    case 3021: return "AdventurerStatueParkourGalleryPreStart";
    case 3022: return "AdventurerStatueParkourGalleryStart";
    case 3023: return "AdventurerStatueParkourGalleryRecover";
    case 3024: return "AdventurerStatueParkourGalleryRefresh";
    case 3025: return "AdventurerStatueParkourGalleryContextState";
    case 3026: return "AdventurerStatueParkourGalleryContextScore";
    case 3027: return "RankedMatchPuzzlePhaseChanged";
    case 3028: return "RankedMatchPuzzleItemUpdate";
    case 3029: return "RankedMatchPuzzleChallengeUpdate";
    case 3030: return "RankedMatchPuzzleReminderAppeared";
    case 3031: return "RankedMatchPuzzleReminderDisappeared";
    case 3032: return "RankedMatchPuzzleBubbleAppeared";
    case 3033: return "RankedMatchPuzzleBubbleDisappeared";
    case 3034: return "RankedMatchPuzzleSupportCountChanged";
    case 3035: return "TpsDefenseBuildPointUpdate";
    case 3036: return "TpsDefenseHpUpdate";
    case 3037: return "TpsDefenseProgressUpdate";
    case 3038: return "TpsDefenseNewWave";
    case 3039: return "TpsDefenseDungeonInfoUpdate";
    case 3040: return "TpsDefenseInteePanelAppear";
    case 3041: return "TpsDefenseInteePanelDisappear";
    case 3042: return "IceCreatureAllGadgetInfoUpdate";
    case 3043: return "IceCreatureGadgetInfoUpdate";
    case 3044: return "IceCreatureAllInfoUpdate";
    case 3045: return "IceCreatureLikeRsp";
    case 3046: return "IceCreatureBeLikedNotify";
    case 3047: return "IceCreaturePutStorageSuccess";
    case 3048: return "IceCreatureTakeStorageSuccess";
    case 3049: return "IceCreatureStorageItemAdd";
    case 3050: return "GrappleCannonLineEffectChanged";
    case 3051: return "IceCreatureGadgetUnlockNotify";
    case 3052: return "ShowIceCreatureGotDialog";
    case 3053: return "OdetteReputationInfoUpdate";
    case 3054: return "OdetteChooseScheduleResult";
    case 3055: return "OdetteSubmitEventResult";
    case 3056: return "OdetteAdvancePhaseResult";
    case 3057: return "OdetteDailySettleResult";
    case 3058: return "OdetteResetPlaythroughResult";
    case 3059: return "OdetteChangeTruthKeyStateResult";
    case 3060: return "OdetteNextDay";
    case 3061: return "OdetteSettle";
    case 3062: return "OdetteCalenderSubPageEnable";
    case 3063: return "OdetteOpenDaySubPageEnable";
    case 3064: return "OdetteBlackScreen";
    case 3065: return "BeyondRoomNotExists";
    case 3066: return "BeyondRoomRecruitmentDealed";
    case 3067: return "SituationButtonChanged";
    case 3068: return "SnezhnayaBookDataUpdated";
    case 3069: return "SnezhnayaBookSituationButtonFlash";
    case 3070: return "SnezhnayaOfferingLevelUpdate";
    case 3071: return "ReputationSnezDataUpdated";
    case 3072: return "GlobalRankUpdate";
    case 3073: return "GlobalRankClosed";
    case 3074: return "GlobalRankRecordUpdate";
    case 3075: return "GlobalRankPrivateUpdate";
    case 3076: return "OnGetGlobalRankRecord";
    case 3077: return "FriendRankUpdate";
    case 3078: return "FriendRankClosed";
    case 3079: return "FriendRankRecordUpdate";
    case 3080: return "FriendRankPublicUpdate";
    case 3081: return "OnGetFriendRankRecord";
    case 3082: return "LongPressInteeCreate";
    case 3083: return "LongPressInteeDisappear";
    case 3084: return "GuideV2Update";
    case 3085: return "GuideV2PathUpdate";
    case 3086: return "GuideV2CustomValueUpdate";
    case 3087: return "DynamicAudioArea3DChanged";
    case 3088: return "PostNewItemGotDialogFinalDestroy";
    case 3089: return "HpBarOverrideRefresh";
    case 3090: return "SnowBallFightScoreUpdate";
    case 3091: return "SnowBallFightEnergyUpdate";
    case 3092: return "SnowBallFightBulletUpdate";
    case 3093: return "SnowBallFightHealthUpdate";
    case 3094: return "SnowBallFightHitUpdate";
    case 3095: return "SnowBallFightBuffUpdate";
    case 3096: return "SnowBallFightAimUpdate";
    case 3097: return "SnowBallFightReminderUpdate";
    case 3098: return "SnowBallFightShowScore";
    case 3099: return "SnowBallFightShoot";
    case 3100: return "SnowBallFightAlivenessUpdate";
    case 3101: return "GamblingChessInLevelCameraAdjust";
    case 3102: return "GamblingChessFightBattleStart";
    case 3103: return "GamblingChessFightBattleInfo";
    case 3104: return "GamblingChessTeamVoteSuccess";
    case 3105: return "GamblingChessCancelVoteSuccess";
    case 3106: return "GamblingChessAppendVoteSuccess";
    case 3107: return "GamblingChessSupportRateUpdate";
    case 3108: return "GamblingChessGetSettlePreviewRsp";
    case 3109: return "GamblingChessSettleScoreSuccess";
    case 3110: return "GamblingChessGetSocialBriefRsp";
    case 3111: return "RogueBallGameStart";
    case 3112: return "RogueBallDungeonSettle";
    case 3113: return "RogueBallResetLevel";
    case 3114: return "RogueBallWaveChanged";
    case 3115: return "RogueBallRoundChanged";
    case 3116: return "RogueBallScoreChanged";
    case 3117: return "RogueBallExpChanged";
    case 3118: return "RogueBallBallAcquired";
    case 3119: return "RogueBallBuffAcquired";
    case 3120: return "RogueBallFirstDrawCompleted";
    case 3121: return "RogueBallPauseInLevelPage";
    case 3122: return "SummonBattlePhaseUpdate";
    case 3123: return "SummonBattleStartReminderUpdate";
    case 3124: return "SummonBattleChargeUpdate";
    case 3125: return "VineManScoreDetailUpdate";
    case 3126: return "VodyanitsaSlotChange";
    }
    return nullptr;
}

// DGKHDNOFHAO（枚举，底层 Int32，4 字节）
enum class T_DGKHDNOFHAO : int32_t {
    ActionReasonNone = 0,
    ActionReasonQuestItem = 1,
    ActionReasonQuestReward = 2,
    ActionReasonTrifle = 3,
    ActionReasonShop = 4,
    ActionReasonPlayerUpgradeReward = 5,
    ActionReasonAddAvatar = 6,
    ActionReasonGadgetEnvAnimal = 7,
    ActionReasonMonsterEnvAnimal = 8,
    ActionReasonCompound = 9,
    ActionReasonCook = 10,
    ActionReasonGather = 11,
    ActionReasonMailAttachment = 12,
    ActionReasonCityLevelupReturn = 15,
    ActionReasonCityLevelupReward = 17,
    ActionReasonAreaExploreReward = 18,
    ActionReasonUnlockPointReward = 19,
    ActionReasonDungeonFirstPass = 20,
    ActionReasonDungeonPass = 21,
    ActionReasonChangeElemType = 23,
    ActionReasonFetterOpen = 25,
    ActionReasonDailyTaskScore = 26,
    ActionReasonDailyTaskHost = 27,
    ActionReasonRandTaskHost = 28,
    ActionReasonExpedition = 29,
    ActionReasonGacha = 30,
    ActionReasonCombine = 31,
    ActionReasonRandTaskGuest = 32,
    ActionReasonDailyTaskGuest = 33,
    ActionReasonForgeOutput = 34,
    ActionReasonForgeReturn = 35,
    ActionReasonInitAvatar = 36,
    ActionReasonMonsterDie = 37,
    ActionReasonGm = 38,
    ActionReasonOpenChest = 39,
    ActionReasonGadgetDie = 40,
    ActionReasonMonsterChangeHp = 41,
    ActionReasonSubfieldDrop = 42,
    ActionReasonPushTipsReward = 43,
    ActionReasonActivityMonsterDrop = 44,
    ActionReasonActivityGather = 45,
    ActionReasonActivitySubfieldDrop = 46,
    ActionReasonTowerScheduleReward = 47,
    ActionReasonTowerFloorStarReward = 48,
    ActionReasonTowerFirstPassReward = 49,
    ActionReasonTowerDailyReward = 50,
    ActionReasonHitClientTrivialEntity = 51,
    ActionReasonOpenWorldBossChest = 52,
    ActionReasonMaterialDeleteReturn = 53,
    ActionReasonSignInReward = 54,
    ActionReasonOpenBlossomChest = 55,
    ActionReasonRecharge = 56,
    ActionReasonBonusActivityReward = 57,
    ActionReasonTowerCommemorativeReward = 58,
    ActionReasonTowerSkipFloorReward = 59,
    ActionReasonRechargeBonus = 60,
    ActionReasonRechargeCard = 61,
    ActionReasonRechargeCardDaily = 62,
    ActionReasonRechargeCardReplace = 63,
    ActionReasonRechargeCardReplaceFree = 64,
    ActionReasonRechargePlayReplace = 65,
    ActionReasonMpPlayTakeReward = 66,
    ActionReasonActivityWatcher = 67,
    ActionReasonSalesmanDeliverItem = 68,
    ActionReasonSalesmanReward = 69,
    ActionReasonRebate = 70,
    ActionReasonMcoinExchangeHcoin = 71,
    ActionReasonDailyTaskExchangeLegendaryKey = 72,
    ActionReasonUnlockPersonLine = 73,
    ActionReasonFetterLevelReward = 74,
    ActionReasonBuyResin = 75,
    ActionReasonRechargePackage = 76,
    ActionReasonDeliveryDailyReward = 77,
    ActionReasonCityReputationLevel = 78,
    ActionReasonCityReputationQuest = 79,
    ActionReasonCityReputationRequest = 80,
    ActionReasonCityReputationExplore = 81,
    ActionReasonOffergingLevel = 82,
    ActionReasonRoutineHost = 83,
    ActionReasonRoutineGuest = 84,
    ActionReasonTreasureMapSpotToken = 89,
    ActionReasonTreasureMapBonusLevelReward = 90,
    ActionReasonTreasureMapMpReward = 91,
    ActionReasonConvert = 92,
    ActionReasonOverflowTransform = 93,
    ActionReasonActivityAvatarSelectionReward = 96,
    ActionReasonActivityWatcherBatch = 97,
    ActionReasonHitTreeDrop = 98,
    ActionReasonGetHomeLevelupReward = 99,
    ActionReasonHomeDefaultFurniture = 100,
    ActionReasonActivityCond = 101,
    ActionReasonBattlePassNotify = 102,
    ActionReasonReliquaryDecompose = 103,
    ActionReasonRechargeGoogleGiftGard = 104,
    ActionReasonRechargeConcertProduct = 105,
    ActionReasonRechargeConcertProductReplace = 106,
    ActionReasonSendConcertProductByMuip = 107,
    ActionReasonRechargeAppleGiftGard = 108,
    ActionReasonRechargePsnCompensationProduct = 109,
    ActionReasonCompoundBoost = 110,
    ActionReasonWoodExchange = 111,
    ActionReasonAvatarRenameAuditFailed = 112,
    ActionReasonAvatarRenameReset = 113,
    ActionReasonActivityChestDrop = 114,
    ActionReasonAvatarRenameCompensate = 115,
    ActionReasonDailyAttendance = 116,
    ActionReasonRoleCombatReward = 117,
    ActionReasonRoleCombatOneoffReward = 118,
    ActionReasonUnlockCharMasterLevel = 119,
    ActionReasonCharMasterLevelReward = 120,
    ActionReasonCharMasterKeyReward = 121,
    ActionReasonExtraChestDrop = 122,
    ActionReasonExtraSubfieldDrop = 123,
    ActionReasonExtraGatherDrop = 124,
    ActionReasonExtraMonsterDrop = 125,
    ActionReasonReliquaryTransfer = 126,
    ActionReasonReliquaryOffer = 127,
    ActionReasonReliquaryPurchase = 128,
    ActionReasonRechargeXgpPackageProduct = 129,
    ActionReasonRechargeXboxPackageProduct = 130,
    ActionReasonRoleCombatMedalReward = 131,
    ActionReasonRechargeGachaTicketProduct = 132,
    ActionReasonReliquaryDust = 133,
    ActionReasonBydCreateAvatar = 134,
    ActionReasonBeyondMaterialDeleteReturn = 135,
    ActionReasonBeyondMcoinExchangeDlcCoin = 136,
    ActionReasonBeyondDlcFreeCoinExpireDelete = 137,
    ActionReasonBeyondActivityWatcher = 138,
    ActionReasonBeyondActivityWatcherBatch = 139,
    ActionReasonExtraBossChestDrop = 140,
    ActionReasonBeyondMcoinExchangeFreeMcoin = 141,
    ActionReasonPlayerUseItem = 1001,
    ActionReasonDropItem = 1002,
    ActionReasonWeaponUpgrade = 1011,
    ActionReasonWeaponPromote = 1012,
    ActionReasonWeaponAwaken = 1013,
    ActionReasonRelicUpgrade = 1014,
    ActionReasonAbility = 1015,
    ActionReasonDungeonStatueDrop = 1016,
    ActionReasonOfflineMsg = 1017,
    ActionReasonAvatarUpgrade = 1018,
    ActionReasonAvatarPromote = 1019,
    ActionReasonQuestAction = 1021,
    ActionReasonCityLevelup = 1022,
    ActionReasonUpgradeSkill = 1024,
    ActionReasonUnlockTalent = 1025,
    ActionReasonUpgradeProudSkill = 1026,
    ActionReasonPlayerLevelLimitUp = 1027,
    ActionReasonDungeonDaily = 1028,
    ActionReasonItemGiving = 1030,
    ActionReasonForgeCost = 1031,
    ActionReasonInvestigationReward = 1032,
    ActionReasonInvestigationTargetReward = 1033,
    ActionReasonGadgetInteract = 1034,
    ActionReasonSeaLampCiMaterial = 1036,
    ActionReasonSeaLampContributionReward = 1037,
    ActionReasonSeaLampPhaseReward = 1038,
    ActionReasonSeaLampFlyLamp = 1039,
    ActionReasonAutoRecover = 1040,
    ActionReasonActivityExpireItem = 1041,
    ActionReasonSubCoinNegative = 1042,
    ActionReasonBargainDeduct = 1043,
    ActionReasonBattlePassPaidReward = 1044,
    ActionReasonBattlePassLevelReward = 1045,
    ActionReasonTrialAvatarActivityFirstPassReward = 1046,
    ActionReasonBuyBattlePassLevel = 1047,
    ActionReasonGrantBirthdayBenefit = 1048,
    ActionReasonAchievementReward = 1049,
    ActionReasonAchievementGoalReward = 1050,
    ActionReasonFirstShareToSocialNetwork = 1051,
    ActionReasonDestroyMaterial = 1052,
    ActionReasonCodexLevelupReward = 1053,
    ActionReasonHuntingOfferReward = 1054,
    ActionReasonUseWidgetAnchorPoint = 1055,
    ActionReasonUseWidgetBonfire = 1056,
    ActionReasonUngradeWeaponReturnMaterial = 1057,
    ActionReasonUseWidgetOneoffGatherPointDetector = 1058,
    ActionReasonUseWidgetClientCollector = 1059,
    ActionReasonUseWidgetClientDetector = 1060,
    ActionReasonTakeGeneralReward = 1061,
    ActionReasonAsterTakeSpecialReward = 1062,
    ActionReasonRemoveCodexBook = 1063,
    ActionReasonOfferingItem = 1064,
    ActionReasonUseWidgetGadgetBuilder = 1065,
    ActionReasonEffigyFirstPassReward = 1066,
    ActionReasonEffigyReward = 1067,
    ActionReasonReunionFirstGiftReward = 1068,
    ActionReasonReunionSignInReward = 1069,
    ActionReasonReunionWatcherReward = 1070,
    ActionReasonSalesmanMpReward = 1071,
    ActionReasionAvatarPromoteReward = 1072,
    ActionReasonBlessingRedeemReward = 1073,
    ActionMiracleRingReward = 1074,
    ActionReasonExpeditionReward = 1075,
    ActionReasonTreasureMapRemoveDetector = 1076,
    ActionReasonMechanicusDungeonTicket = 1077,
    ActionReasonMechanicusLevelupGear = 1078,
    ActionReasonMechanicusBattleSettle = 1079,
    ActionReasonRegionSearchReward = 1080,
    ActionReasonUnlockCoopChapter = 1081,
    ActionReasonTakeCoopReward = 1082,
    ActionReasonFleurFairDungeonReward = 1083,
    ActionReasonActivityScore = 1084,
    ActionReasonChannellerSlabOneoffDungeonReward = 1085,
    ActionReasonFurnitureMakeStart = 1086,
    ActionReasonFurnitureMakeTake = 1087,
    ActionReasonFurnitureMakeCancel = 1088,
    ActionReasonFurnitureMakeFastFinish = 1089,
    ActionReasonChannellerSlabLoopDungeonFirstPassReward = 1090,
    ActionReasonChannellerSlabLoopDungeonScoreReward = 1091,
    ActionReasonHomeLimitedShopBuy = 1092,
    ActionReasonHomeCoinCollect = 1093,
    ActionReasonSummerTimeSentryTowerReward = 1094,
    ActionReasonSummerTimeSprintBoatReward = 1095,
    ActionReasonSummerTimeBossReward = 1096,
    ActionReasonSummerTimeBombReward = 1097,
    ActionReasonHomeFetterCollect = 1098,
    ActionReasonEchoShellReward = 1099,
    ActionReasonHomeEventReward = 1100,
    ActionReasonBlitzRushDungeonReward = 1101,
    ActionReasonFurnitureMakeReturn = 1102,
    ActionReasonHomePlantBoxGather = 1103,
    ActionReasonHomePlantSeed = 1104,
    ActionReasonHomePlantGather = 1105,
    ActionReasonChessDungeonReward = 1106,
    ActionReasonGroupLinkBundleFinish = 1107,
    ActionReasonLunaRiteSacrifice = 1108,
    ActionReasonLunaRiteTakeSacrificeReward = 1109,
    ActionReasonFishBite = 1110,
    ActionReasonFishSucc = 1111,
    ActionReasonPlantFlowerReward = 1112,
    ActionReasonPlantFlowerDeliverItem = 1113,
    ActionReasonPlantFlowerGiveFlower = 1114,
    ActionReasonPlantFlowerRecvFlower = 1115,
    ActionReasonRogueChallengeSettle = 1116,
    ActionReasonRogueTakeFirstPassReward = 1117,
    ActionReasonRogueUpgradeShikigami = 1118,
    ActionReasonRogueRefreshCard = 1119,
    ActionReasonUseWidgetCaptureAnimal = 1120,
    ActionReasonCaptureAnimalSucc = 1121,
    ActionReasonSnowDrifts = 1122,
    ActionReasonWinterCampGiveItem = 1123,
    ActionReasonWinterCampRecvItem = 1124,
    ActionReasonWinterCampExploreReward = 1125,
    ActionReasonWinterCampBattleReward = 1126,
    ActionReasonLanternRiteSkinReward = 1127,
    ActionReasonLanternRiteDungeonReward = 1128,
    ActionReasonMichiaeMatsuriDarkChallengeReward = 1129,
    ActionReasonMichiaeMatsuriUnlockCrystalSkill = 1130,
    ActionReasonLanternRiteGroupReward = 1131,
    ActionReasonCostumeDefaultUnlock = 1132,
    ActionReasonSpiceActivityMakeSpice = 1133,
    ActionReasonSpiceActivityProcessFood = 1134,
    ActionReasonSpiceAddAvatarFetter = 1135,
    ActionReasonGachaActivityRobotReward = 1136,
    ActionReasonGivingTakeBack = 1137,
    ActionReasonSummerTimeV2DungeonReward = 1138,
    ActionReasonGravenInnocenceCampReward = 1139,
    ActionReasonTreasureSeelieChestReward = 1140,
    ActionReasonGcgTavernChallengeUnlockCharacter = 1141,
    ActionReasonGcgLevelReward = 1143,
    ActionReasonGcgChallengeFinish = 1144,
    ActionReasonVintageMarketDeal = 1145,
    ActionReasonVintageMarketBargain = 1146,
    ActionReasonVintageMarketStore = 1147,
    ActionReasonVintagePresent = 1148,
    ActionReasonVintageOpenStore = 1149,
    ActionReasonVintageStoreUnlockSlot = 1150,
    ActionReasonVintageStoreNpcEvent = 1151,
    ActionReasonRockBoardExploreReward = 1152,
    ActionReasonVintageStoreDividend = 1153,
    ActionReasonAvatarRename = 1154,
    ActionReasonGcgFinishLevelQuest = 1155,
    ActionReasonGcgProficiencyReward = 1156,
    ActionReasonTeamChainCostumeReward = 1157,
    ActionReasonOfferingPariFinishReward = 1158,
    ActionReasonPenumbraChestReward = 1159,
    ActionReasonRaffleTicketTakeBonus = 1160,
    ActionReasonWispCageReward = 1161,
    ActionReasonAlchemySimCropRipen = 1162,
    ActionReasonAlchemySimUnlockTechTree = 1163,
    ActionReasonAlchemySimUpgradePotion = 1164,
    ActionReasonAlchemySimSell = 1165,
    ActionReasonAlchemySimOrder = 1166,
    ActionReasonAlchemySimExam = 1167,
    ActionReasonAlchemySimDealer = 1168,
    ActionReasonAlchemySimLetter = 1169,
    ActionReasonAlchemySimStage = 1170,
    ActionReasonAlchemySimUpgradeCrop = 1171,
    ActionReasonAlchemySimFinishAlchemy = 1172,
    ActionReasonCatcafeFeed = 1173,
    ActionReasonAlchemySimAlchemyLevelUpgrade = 1174,
    ActionReasonAlchemySimCropHarvest = 1175,
    ActionReasonGreatFestivalV2Upgrade = 1176,
    ActionReasonFairyTalesCapsuleToyLotter = 1177,
    ActionReasonFairyTalesCapsuleToyGiveGift = 1178,
    ActionReasonFairyTalesCapsuleToyRecvGift = 1179,
    ActionReasonFairyTalesTicketBonusReward = 1180,
    ActionReasonFairyTalesTicketBonusDelNormalRadar = 1181,
    ActionReasonCityReputationDonation = 1182,
    ActionReasonCityReputationTotalReward = 1183,
    ActionReasonMiscRename = 1184,
    ActionReasonMiscRenameAuditFailed = 1185,
    ActionReasonMiscRenameReset = 1186,
    ActionReasonMiscRenameCompensate = 1187,
    ActionReasonReunionVideoReward = 1188,
    ActionReasonHuntingV2OfferReward = 1189,
    ActionReasonTribalReputationLevel = 1190,
    ActionReasonBattlePassMissionReward = 1191,
    ActionReasonReunionReminderMailReward = 1192,
    ActionReasonReunionWpReward = 1193,
    ActionReasonCooperateChallengeReward = 1194,
    ActionReasonAnimalViewReward = 1195,
    ActionReasonMusicGameBookReward = 1196,
    ActionReasonNatlanRaceSpecialReward = 1197,
    ActionReasonMonthCardRemindMail = 1198,
    ActionReasonThemeParkZooRaffleTicketReward = 1199,
    ActionReasonThemeParkZooGacha = 1200,
    ActionReasonAvatarEscoffierSkillCook = 1201,
    ActionReasonLeyLineChallenge = 1202,
    ActionReasonLeyLineChallengeExtra = 1203,
    ActionReasonBossDungeonFirstPassReward = 1204,
    ActionReasonAutochessTalentPoint = 1205,
    ActionReasonWorldWatcher = 1206,
    ActionReasonUseFoodProbGetItem = 1207,
    ActionReasonFlowerLandReputation = 1208,
    ActionReasonAnecdoteTakeReward = 1209,
    ActionReasonAnecdoteFinish = 1210,
    ActionReasonLocalLegendGroupReward = 1211,
    ActionReasonReissueAvatarExtraLevelMaterial = 1213,
    ActionReasonAvatarExtraLevelUpgrade = 1214,
    ActionReasonHcoinDirectTakeReward = 1215,
    ActionReasonActivityWeekActive = 1216,
    ActionReasonNeferIntelligenceScan = 1217,
    ActionReasonNeferIntelligenceShopBuy = 1218,
    ActionReasonCerateBeyondAvatar = 2000,
    ActionReasonCompoundBeyondCostume = 2001,
    ActionReasonHallOpenState = 2002,
    ActionReasonCreatePrivateHall = 2003,
    ActionReasonBeyondGacha = 2004,
    ActionReasonBeyondShopGiftRecvReturn = 2005,
    ActionReasonGetAutoUnlockPrivateHall = 2006,
    ActionReasonRechargeBydBattlePassReplace = 2007,
    ActionReasonRechargeBydGachaTicketProduct = 2008,
    ActionReasonPlayerUseBeyondMaterial = 2009,
    ActionReasonBeyondBattlePassPaidReward = 2010,
    ActionReasonBeyondBattlePassLevelReward = 2011,
    ActionReasonBeyondBattlePassMissionReward = 2012,
    ActionReasonBuyBeyondBattlePassLevel = 2013,
    ActionReasonPlayerBeyondHandbookReward = 2014,
    ActionReasonBeyondLevelWatcherReward = 2016,
    ActionReasonBeyondShopGift = 2018,
    ActionReasonBeyondGachaGift = 2019,
    ActionReasonBeyondInitialActiveReward = 2020,
    ActionReasonBeyondMaterialAutoUseTransGot = 2021,
    ActionReasonAsyncGadgetCreate = 2022,
    ActionReasonActivityLanternRiteV6Gift = 2023,
    ActionReasonActivityLanternRiteV6BuySkin = 2024,
    ActionReasonBeyondBuyPaidDlc = 2025,
    ActionReasonRechargeBeyondSubscriber = 2026,
    ActionReasonRechargeBeyondSubscriberReplace = 2027,
    ActionReasonBeyondSubscriberRemindMail = 2028,
    ActionReasonBeyondActivityExpireItem = 2029,
    ActionReasonBeyondActivity = 2030,
    ActionReasonBeyondScoreLevelActivityFinishLevel = 2031,
    ActionReasonBeyondPaidDlcRefund = 2032,
    ActionReasonBeyondFashionWelfareTakeDailyReward = 2033,
    ActionReasonBeyondFashionWelfareTakeScoreReward = 2034,
    ActionReasonBeyondShopAutoFreeBuyBundle = 2035,
    ActionReasonBeyondShopGiftAutoFreeBuyBundle = 2036,
    ActionReasonItemExchange = 2037,
    ActionReasonLinneaSkillCaptureAnimalSucc = 2038,
    ActionReasonRechargeTopupBonusMail = 2039,
    ActionReasonRechargeTopupFirstBonusMail = 2040,
    ActionReasonAvatarMarionetteLifeTalent = 2041,
    ActionReasonUnlockTpsWeaponAccessory = 2042,
    ActionReasonTpsMercenariesLevelReward = 2043,
    ActionReasonTpsMercenariesTotalReward = 2044,
    ActionReasonIceCreatureStorage = 2045,
    ActionReasonActivityRankedMatchAutoCoinReward = 2046,
    ActionReasonAdventurerStatueThrowDriftBottle = 2047,
    ActionReasonAdventurerStatuePickDriftBottle = 2048,
    ActionReasonAdventurerStatueOpenChest = 2049,
    ActionReasonReputationSnez = 2050,
    ActionReasonItemUpgradeChain = 2051,
    ActionReasonIceCreatureMaterialRefund = 2052,
    ActionReasonBuildIceCreature = 2053,
    ActionReasonGamblingChessVote = 2054,
    ActionReasonGamblingChessStageRelease = 2055,
    ActionReasonGamblingChessStageSettle = 2056,
    ActionReasonBeyondAnniversaryAnnouncementReward = 2057
};
static_assert(sizeof(T_DGKHDNOFHAO) == 4, "T_DGKHDNOFHAO");
inline const char* enum_name(T_DGKHDNOFHAO v) {
    switch ((int32_t)v) {
    case 0: return "ActionReasonNone";
    case 1: return "ActionReasonQuestItem";
    case 2: return "ActionReasonQuestReward";
    case 3: return "ActionReasonTrifle";
    case 4: return "ActionReasonShop";
    case 5: return "ActionReasonPlayerUpgradeReward";
    case 6: return "ActionReasonAddAvatar";
    case 7: return "ActionReasonGadgetEnvAnimal";
    case 8: return "ActionReasonMonsterEnvAnimal";
    case 9: return "ActionReasonCompound";
    case 10: return "ActionReasonCook";
    case 11: return "ActionReasonGather";
    case 12: return "ActionReasonMailAttachment";
    case 15: return "ActionReasonCityLevelupReturn";
    case 17: return "ActionReasonCityLevelupReward";
    case 18: return "ActionReasonAreaExploreReward";
    case 19: return "ActionReasonUnlockPointReward";
    case 20: return "ActionReasonDungeonFirstPass";
    case 21: return "ActionReasonDungeonPass";
    case 23: return "ActionReasonChangeElemType";
    case 25: return "ActionReasonFetterOpen";
    case 26: return "ActionReasonDailyTaskScore";
    case 27: return "ActionReasonDailyTaskHost";
    case 28: return "ActionReasonRandTaskHost";
    case 29: return "ActionReasonExpedition";
    case 30: return "ActionReasonGacha";
    case 31: return "ActionReasonCombine";
    case 32: return "ActionReasonRandTaskGuest";
    case 33: return "ActionReasonDailyTaskGuest";
    case 34: return "ActionReasonForgeOutput";
    case 35: return "ActionReasonForgeReturn";
    case 36: return "ActionReasonInitAvatar";
    case 37: return "ActionReasonMonsterDie";
    case 38: return "ActionReasonGm";
    case 39: return "ActionReasonOpenChest";
    case 40: return "ActionReasonGadgetDie";
    case 41: return "ActionReasonMonsterChangeHp";
    case 42: return "ActionReasonSubfieldDrop";
    case 43: return "ActionReasonPushTipsReward";
    case 44: return "ActionReasonActivityMonsterDrop";
    case 45: return "ActionReasonActivityGather";
    case 46: return "ActionReasonActivitySubfieldDrop";
    case 47: return "ActionReasonTowerScheduleReward";
    case 48: return "ActionReasonTowerFloorStarReward";
    case 49: return "ActionReasonTowerFirstPassReward";
    case 50: return "ActionReasonTowerDailyReward";
    case 51: return "ActionReasonHitClientTrivialEntity";
    case 52: return "ActionReasonOpenWorldBossChest";
    case 53: return "ActionReasonMaterialDeleteReturn";
    case 54: return "ActionReasonSignInReward";
    case 55: return "ActionReasonOpenBlossomChest";
    case 56: return "ActionReasonRecharge";
    case 57: return "ActionReasonBonusActivityReward";
    case 58: return "ActionReasonTowerCommemorativeReward";
    case 59: return "ActionReasonTowerSkipFloorReward";
    case 60: return "ActionReasonRechargeBonus";
    case 61: return "ActionReasonRechargeCard";
    case 62: return "ActionReasonRechargeCardDaily";
    case 63: return "ActionReasonRechargeCardReplace";
    case 64: return "ActionReasonRechargeCardReplaceFree";
    case 65: return "ActionReasonRechargePlayReplace";
    case 66: return "ActionReasonMpPlayTakeReward";
    case 67: return "ActionReasonActivityWatcher";
    case 68: return "ActionReasonSalesmanDeliverItem";
    case 69: return "ActionReasonSalesmanReward";
    case 70: return "ActionReasonRebate";
    case 71: return "ActionReasonMcoinExchangeHcoin";
    case 72: return "ActionReasonDailyTaskExchangeLegendaryKey";
    case 73: return "ActionReasonUnlockPersonLine";
    case 74: return "ActionReasonFetterLevelReward";
    case 75: return "ActionReasonBuyResin";
    case 76: return "ActionReasonRechargePackage";
    case 77: return "ActionReasonDeliveryDailyReward";
    case 78: return "ActionReasonCityReputationLevel";
    case 79: return "ActionReasonCityReputationQuest";
    case 80: return "ActionReasonCityReputationRequest";
    case 81: return "ActionReasonCityReputationExplore";
    case 82: return "ActionReasonOffergingLevel";
    case 83: return "ActionReasonRoutineHost";
    case 84: return "ActionReasonRoutineGuest";
    case 89: return "ActionReasonTreasureMapSpotToken";
    case 90: return "ActionReasonTreasureMapBonusLevelReward";
    case 91: return "ActionReasonTreasureMapMpReward";
    case 92: return "ActionReasonConvert";
    case 93: return "ActionReasonOverflowTransform";
    case 96: return "ActionReasonActivityAvatarSelectionReward";
    case 97: return "ActionReasonActivityWatcherBatch";
    case 98: return "ActionReasonHitTreeDrop";
    case 99: return "ActionReasonGetHomeLevelupReward";
    case 100: return "ActionReasonHomeDefaultFurniture";
    case 101: return "ActionReasonActivityCond";
    case 102: return "ActionReasonBattlePassNotify";
    case 103: return "ActionReasonReliquaryDecompose";
    case 104: return "ActionReasonRechargeGoogleGiftGard";
    case 105: return "ActionReasonRechargeConcertProduct";
    case 106: return "ActionReasonRechargeConcertProductReplace";
    case 107: return "ActionReasonSendConcertProductByMuip";
    case 108: return "ActionReasonRechargeAppleGiftGard";
    case 109: return "ActionReasonRechargePsnCompensationProduct";
    case 110: return "ActionReasonCompoundBoost";
    case 111: return "ActionReasonWoodExchange";
    case 112: return "ActionReasonAvatarRenameAuditFailed";
    case 113: return "ActionReasonAvatarRenameReset";
    case 114: return "ActionReasonActivityChestDrop";
    case 115: return "ActionReasonAvatarRenameCompensate";
    case 116: return "ActionReasonDailyAttendance";
    case 117: return "ActionReasonRoleCombatReward";
    case 118: return "ActionReasonRoleCombatOneoffReward";
    case 119: return "ActionReasonUnlockCharMasterLevel";
    case 120: return "ActionReasonCharMasterLevelReward";
    case 121: return "ActionReasonCharMasterKeyReward";
    case 122: return "ActionReasonExtraChestDrop";
    case 123: return "ActionReasonExtraSubfieldDrop";
    case 124: return "ActionReasonExtraGatherDrop";
    case 125: return "ActionReasonExtraMonsterDrop";
    case 126: return "ActionReasonReliquaryTransfer";
    case 127: return "ActionReasonReliquaryOffer";
    case 128: return "ActionReasonReliquaryPurchase";
    case 129: return "ActionReasonRechargeXgpPackageProduct";
    case 130: return "ActionReasonRechargeXboxPackageProduct";
    case 131: return "ActionReasonRoleCombatMedalReward";
    case 132: return "ActionReasonRechargeGachaTicketProduct";
    case 133: return "ActionReasonReliquaryDust";
    case 134: return "ActionReasonBydCreateAvatar";
    case 135: return "ActionReasonBeyondMaterialDeleteReturn";
    case 136: return "ActionReasonBeyondMcoinExchangeDlcCoin";
    case 137: return "ActionReasonBeyondDlcFreeCoinExpireDelete";
    case 138: return "ActionReasonBeyondActivityWatcher";
    case 139: return "ActionReasonBeyondActivityWatcherBatch";
    case 140: return "ActionReasonExtraBossChestDrop";
    case 141: return "ActionReasonBeyondMcoinExchangeFreeMcoin";
    case 1001: return "ActionReasonPlayerUseItem";
    case 1002: return "ActionReasonDropItem";
    case 1011: return "ActionReasonWeaponUpgrade";
    case 1012: return "ActionReasonWeaponPromote";
    case 1013: return "ActionReasonWeaponAwaken";
    case 1014: return "ActionReasonRelicUpgrade";
    case 1015: return "ActionReasonAbility";
    case 1016: return "ActionReasonDungeonStatueDrop";
    case 1017: return "ActionReasonOfflineMsg";
    case 1018: return "ActionReasonAvatarUpgrade";
    case 1019: return "ActionReasonAvatarPromote";
    case 1021: return "ActionReasonQuestAction";
    case 1022: return "ActionReasonCityLevelup";
    case 1024: return "ActionReasonUpgradeSkill";
    case 1025: return "ActionReasonUnlockTalent";
    case 1026: return "ActionReasonUpgradeProudSkill";
    case 1027: return "ActionReasonPlayerLevelLimitUp";
    case 1028: return "ActionReasonDungeonDaily";
    case 1030: return "ActionReasonItemGiving";
    case 1031: return "ActionReasonForgeCost";
    case 1032: return "ActionReasonInvestigationReward";
    case 1033: return "ActionReasonInvestigationTargetReward";
    case 1034: return "ActionReasonGadgetInteract";
    case 1036: return "ActionReasonSeaLampCiMaterial";
    case 1037: return "ActionReasonSeaLampContributionReward";
    case 1038: return "ActionReasonSeaLampPhaseReward";
    case 1039: return "ActionReasonSeaLampFlyLamp";
    case 1040: return "ActionReasonAutoRecover";
    case 1041: return "ActionReasonActivityExpireItem";
    case 1042: return "ActionReasonSubCoinNegative";
    case 1043: return "ActionReasonBargainDeduct";
    case 1044: return "ActionReasonBattlePassPaidReward";
    case 1045: return "ActionReasonBattlePassLevelReward";
    case 1046: return "ActionReasonTrialAvatarActivityFirstPassReward";
    case 1047: return "ActionReasonBuyBattlePassLevel";
    case 1048: return "ActionReasonGrantBirthdayBenefit";
    case 1049: return "ActionReasonAchievementReward";
    case 1050: return "ActionReasonAchievementGoalReward";
    case 1051: return "ActionReasonFirstShareToSocialNetwork";
    case 1052: return "ActionReasonDestroyMaterial";
    case 1053: return "ActionReasonCodexLevelupReward";
    case 1054: return "ActionReasonHuntingOfferReward";
    case 1055: return "ActionReasonUseWidgetAnchorPoint";
    case 1056: return "ActionReasonUseWidgetBonfire";
    case 1057: return "ActionReasonUngradeWeaponReturnMaterial";
    case 1058: return "ActionReasonUseWidgetOneoffGatherPointDetector";
    case 1059: return "ActionReasonUseWidgetClientCollector";
    case 1060: return "ActionReasonUseWidgetClientDetector";
    case 1061: return "ActionReasonTakeGeneralReward";
    case 1062: return "ActionReasonAsterTakeSpecialReward";
    case 1063: return "ActionReasonRemoveCodexBook";
    case 1064: return "ActionReasonOfferingItem";
    case 1065: return "ActionReasonUseWidgetGadgetBuilder";
    case 1066: return "ActionReasonEffigyFirstPassReward";
    case 1067: return "ActionReasonEffigyReward";
    case 1068: return "ActionReasonReunionFirstGiftReward";
    case 1069: return "ActionReasonReunionSignInReward";
    case 1070: return "ActionReasonReunionWatcherReward";
    case 1071: return "ActionReasonSalesmanMpReward";
    case 1072: return "ActionReasionAvatarPromoteReward";
    case 1073: return "ActionReasonBlessingRedeemReward";
    case 1074: return "ActionMiracleRingReward";
    case 1075: return "ActionReasonExpeditionReward";
    case 1076: return "ActionReasonTreasureMapRemoveDetector";
    case 1077: return "ActionReasonMechanicusDungeonTicket";
    case 1078: return "ActionReasonMechanicusLevelupGear";
    case 1079: return "ActionReasonMechanicusBattleSettle";
    case 1080: return "ActionReasonRegionSearchReward";
    case 1081: return "ActionReasonUnlockCoopChapter";
    case 1082: return "ActionReasonTakeCoopReward";
    case 1083: return "ActionReasonFleurFairDungeonReward";
    case 1084: return "ActionReasonActivityScore";
    case 1085: return "ActionReasonChannellerSlabOneoffDungeonReward";
    case 1086: return "ActionReasonFurnitureMakeStart";
    case 1087: return "ActionReasonFurnitureMakeTake";
    case 1088: return "ActionReasonFurnitureMakeCancel";
    case 1089: return "ActionReasonFurnitureMakeFastFinish";
    case 1090: return "ActionReasonChannellerSlabLoopDungeonFirstPassReward";
    case 1091: return "ActionReasonChannellerSlabLoopDungeonScoreReward";
    case 1092: return "ActionReasonHomeLimitedShopBuy";
    case 1093: return "ActionReasonHomeCoinCollect";
    case 1094: return "ActionReasonSummerTimeSentryTowerReward";
    case 1095: return "ActionReasonSummerTimeSprintBoatReward";
    case 1096: return "ActionReasonSummerTimeBossReward";
    case 1097: return "ActionReasonSummerTimeBombReward";
    case 1098: return "ActionReasonHomeFetterCollect";
    case 1099: return "ActionReasonEchoShellReward";
    case 1100: return "ActionReasonHomeEventReward";
    case 1101: return "ActionReasonBlitzRushDungeonReward";
    case 1102: return "ActionReasonFurnitureMakeReturn";
    case 1103: return "ActionReasonHomePlantBoxGather";
    case 1104: return "ActionReasonHomePlantSeed";
    case 1105: return "ActionReasonHomePlantGather";
    case 1106: return "ActionReasonChessDungeonReward";
    case 1107: return "ActionReasonGroupLinkBundleFinish";
    case 1108: return "ActionReasonLunaRiteSacrifice";
    case 1109: return "ActionReasonLunaRiteTakeSacrificeReward";
    case 1110: return "ActionReasonFishBite";
    case 1111: return "ActionReasonFishSucc";
    case 1112: return "ActionReasonPlantFlowerReward";
    case 1113: return "ActionReasonPlantFlowerDeliverItem";
    case 1114: return "ActionReasonPlantFlowerGiveFlower";
    case 1115: return "ActionReasonPlantFlowerRecvFlower";
    case 1116: return "ActionReasonRogueChallengeSettle";
    case 1117: return "ActionReasonRogueTakeFirstPassReward";
    case 1118: return "ActionReasonRogueUpgradeShikigami";
    case 1119: return "ActionReasonRogueRefreshCard";
    case 1120: return "ActionReasonUseWidgetCaptureAnimal";
    case 1121: return "ActionReasonCaptureAnimalSucc";
    case 1122: return "ActionReasonSnowDrifts";
    case 1123: return "ActionReasonWinterCampGiveItem";
    case 1124: return "ActionReasonWinterCampRecvItem";
    case 1125: return "ActionReasonWinterCampExploreReward";
    case 1126: return "ActionReasonWinterCampBattleReward";
    case 1127: return "ActionReasonLanternRiteSkinReward";
    case 1128: return "ActionReasonLanternRiteDungeonReward";
    case 1129: return "ActionReasonMichiaeMatsuriDarkChallengeReward";
    case 1130: return "ActionReasonMichiaeMatsuriUnlockCrystalSkill";
    case 1131: return "ActionReasonLanternRiteGroupReward";
    case 1132: return "ActionReasonCostumeDefaultUnlock";
    case 1133: return "ActionReasonSpiceActivityMakeSpice";
    case 1134: return "ActionReasonSpiceActivityProcessFood";
    case 1135: return "ActionReasonSpiceAddAvatarFetter";
    case 1136: return "ActionReasonGachaActivityRobotReward";
    case 1137: return "ActionReasonGivingTakeBack";
    case 1138: return "ActionReasonSummerTimeV2DungeonReward";
    case 1139: return "ActionReasonGravenInnocenceCampReward";
    case 1140: return "ActionReasonTreasureSeelieChestReward";
    case 1141: return "ActionReasonGcgTavernChallengeUnlockCharacter";
    case 1143: return "ActionReasonGcgLevelReward";
    case 1144: return "ActionReasonGcgChallengeFinish";
    case 1145: return "ActionReasonVintageMarketDeal";
    case 1146: return "ActionReasonVintageMarketBargain";
    case 1147: return "ActionReasonVintageMarketStore";
    case 1148: return "ActionReasonVintagePresent";
    case 1149: return "ActionReasonVintageOpenStore";
    case 1150: return "ActionReasonVintageStoreUnlockSlot";
    case 1151: return "ActionReasonVintageStoreNpcEvent";
    case 1152: return "ActionReasonRockBoardExploreReward";
    case 1153: return "ActionReasonVintageStoreDividend";
    case 1154: return "ActionReasonAvatarRename";
    case 1155: return "ActionReasonGcgFinishLevelQuest";
    case 1156: return "ActionReasonGcgProficiencyReward";
    case 1157: return "ActionReasonTeamChainCostumeReward";
    case 1158: return "ActionReasonOfferingPariFinishReward";
    case 1159: return "ActionReasonPenumbraChestReward";
    case 1160: return "ActionReasonRaffleTicketTakeBonus";
    case 1161: return "ActionReasonWispCageReward";
    case 1162: return "ActionReasonAlchemySimCropRipen";
    case 1163: return "ActionReasonAlchemySimUnlockTechTree";
    case 1164: return "ActionReasonAlchemySimUpgradePotion";
    case 1165: return "ActionReasonAlchemySimSell";
    case 1166: return "ActionReasonAlchemySimOrder";
    case 1167: return "ActionReasonAlchemySimExam";
    case 1168: return "ActionReasonAlchemySimDealer";
    case 1169: return "ActionReasonAlchemySimLetter";
    case 1170: return "ActionReasonAlchemySimStage";
    case 1171: return "ActionReasonAlchemySimUpgradeCrop";
    case 1172: return "ActionReasonAlchemySimFinishAlchemy";
    case 1173: return "ActionReasonCatcafeFeed";
    case 1174: return "ActionReasonAlchemySimAlchemyLevelUpgrade";
    case 1175: return "ActionReasonAlchemySimCropHarvest";
    case 1176: return "ActionReasonGreatFestivalV2Upgrade";
    case 1177: return "ActionReasonFairyTalesCapsuleToyLotter";
    case 1178: return "ActionReasonFairyTalesCapsuleToyGiveGift";
    case 1179: return "ActionReasonFairyTalesCapsuleToyRecvGift";
    case 1180: return "ActionReasonFairyTalesTicketBonusReward";
    case 1181: return "ActionReasonFairyTalesTicketBonusDelNormalRadar";
    case 1182: return "ActionReasonCityReputationDonation";
    case 1183: return "ActionReasonCityReputationTotalReward";
    case 1184: return "ActionReasonMiscRename";
    case 1185: return "ActionReasonMiscRenameAuditFailed";
    case 1186: return "ActionReasonMiscRenameReset";
    case 1187: return "ActionReasonMiscRenameCompensate";
    case 1188: return "ActionReasonReunionVideoReward";
    case 1189: return "ActionReasonHuntingV2OfferReward";
    case 1190: return "ActionReasonTribalReputationLevel";
    case 1191: return "ActionReasonBattlePassMissionReward";
    case 1192: return "ActionReasonReunionReminderMailReward";
    case 1193: return "ActionReasonReunionWpReward";
    case 1194: return "ActionReasonCooperateChallengeReward";
    case 1195: return "ActionReasonAnimalViewReward";
    case 1196: return "ActionReasonMusicGameBookReward";
    case 1197: return "ActionReasonNatlanRaceSpecialReward";
    case 1198: return "ActionReasonMonthCardRemindMail";
    case 1199: return "ActionReasonThemeParkZooRaffleTicketReward";
    case 1200: return "ActionReasonThemeParkZooGacha";
    case 1201: return "ActionReasonAvatarEscoffierSkillCook";
    case 1202: return "ActionReasonLeyLineChallenge";
    case 1203: return "ActionReasonLeyLineChallengeExtra";
    case 1204: return "ActionReasonBossDungeonFirstPassReward";
    case 1205: return "ActionReasonAutochessTalentPoint";
    case 1206: return "ActionReasonWorldWatcher";
    case 1207: return "ActionReasonUseFoodProbGetItem";
    case 1208: return "ActionReasonFlowerLandReputation";
    case 1209: return "ActionReasonAnecdoteTakeReward";
    case 1210: return "ActionReasonAnecdoteFinish";
    case 1211: return "ActionReasonLocalLegendGroupReward";
    case 1213: return "ActionReasonReissueAvatarExtraLevelMaterial";
    case 1214: return "ActionReasonAvatarExtraLevelUpgrade";
    case 1215: return "ActionReasonHcoinDirectTakeReward";
    case 1216: return "ActionReasonActivityWeekActive";
    case 1217: return "ActionReasonNeferIntelligenceScan";
    case 1218: return "ActionReasonNeferIntelligenceShopBuy";
    case 2000: return "ActionReasonCerateBeyondAvatar";
    case 2001: return "ActionReasonCompoundBeyondCostume";
    case 2002: return "ActionReasonHallOpenState";
    case 2003: return "ActionReasonCreatePrivateHall";
    case 2004: return "ActionReasonBeyondGacha";
    case 2005: return "ActionReasonBeyondShopGiftRecvReturn";
    case 2006: return "ActionReasonGetAutoUnlockPrivateHall";
    case 2007: return "ActionReasonRechargeBydBattlePassReplace";
    case 2008: return "ActionReasonRechargeBydGachaTicketProduct";
    case 2009: return "ActionReasonPlayerUseBeyondMaterial";
    case 2010: return "ActionReasonBeyondBattlePassPaidReward";
    case 2011: return "ActionReasonBeyondBattlePassLevelReward";
    case 2012: return "ActionReasonBeyondBattlePassMissionReward";
    case 2013: return "ActionReasonBuyBeyondBattlePassLevel";
    case 2014: return "ActionReasonPlayerBeyondHandbookReward";
    case 2016: return "ActionReasonBeyondLevelWatcherReward";
    case 2018: return "ActionReasonBeyondShopGift";
    case 2019: return "ActionReasonBeyondGachaGift";
    case 2020: return "ActionReasonBeyondInitialActiveReward";
    case 2021: return "ActionReasonBeyondMaterialAutoUseTransGot";
    case 2022: return "ActionReasonAsyncGadgetCreate";
    case 2023: return "ActionReasonActivityLanternRiteV6Gift";
    case 2024: return "ActionReasonActivityLanternRiteV6BuySkin";
    case 2025: return "ActionReasonBeyondBuyPaidDlc";
    case 2026: return "ActionReasonRechargeBeyondSubscriber";
    case 2027: return "ActionReasonRechargeBeyondSubscriberReplace";
    case 2028: return "ActionReasonBeyondSubscriberRemindMail";
    case 2029: return "ActionReasonBeyondActivityExpireItem";
    case 2030: return "ActionReasonBeyondActivity";
    case 2031: return "ActionReasonBeyondScoreLevelActivityFinishLevel";
    case 2032: return "ActionReasonBeyondPaidDlcRefund";
    case 2033: return "ActionReasonBeyondFashionWelfareTakeDailyReward";
    case 2034: return "ActionReasonBeyondFashionWelfareTakeScoreReward";
    case 2035: return "ActionReasonBeyondShopAutoFreeBuyBundle";
    case 2036: return "ActionReasonBeyondShopGiftAutoFreeBuyBundle";
    case 2037: return "ActionReasonItemExchange";
    case 2038: return "ActionReasonLinneaSkillCaptureAnimalSucc";
    case 2039: return "ActionReasonRechargeTopupBonusMail";
    case 2040: return "ActionReasonRechargeTopupFirstBonusMail";
    case 2041: return "ActionReasonAvatarMarionetteLifeTalent";
    case 2042: return "ActionReasonUnlockTpsWeaponAccessory";
    case 2043: return "ActionReasonTpsMercenariesLevelReward";
    case 2044: return "ActionReasonTpsMercenariesTotalReward";
    case 2045: return "ActionReasonIceCreatureStorage";
    case 2046: return "ActionReasonActivityRankedMatchAutoCoinReward";
    case 2047: return "ActionReasonAdventurerStatueThrowDriftBottle";
    case 2048: return "ActionReasonAdventurerStatuePickDriftBottle";
    case 2049: return "ActionReasonAdventurerStatueOpenChest";
    case 2050: return "ActionReasonReputationSnez";
    case 2051: return "ActionReasonItemUpgradeChain";
    case 2052: return "ActionReasonIceCreatureMaterialRefund";
    case 2053: return "ActionReasonBuildIceCreature";
    case 2054: return "ActionReasonGamblingChessVote";
    case 2055: return "ActionReasonGamblingChessStageRelease";
    case 2056: return "ActionReasonGamblingChessStageSettle";
    case 2057: return "ActionReasonBeyondAnniversaryAnnouncementReward";
    }
    return nullptr;
}

// ---- 结构体前置声明 + fmt 前置声明（互相嵌套时也能编译）----
struct T_EIDAIBHGFDD;
struct T_IJGACJNNLDA;
struct T_BPOCICOCMJI;
struct T_JCICBDDMHMK;
struct T_FDJEDLNJIEH;
struct T_BGGFLFOAHGE;
struct T_UnityEngine_Vector3;
struct T_MoleMole_Notify;
struct T_UnityEngine_Vector2;
struct T_GCBPLBGGHAL;
struct T_FDIKBDFDDEA;
struct T_HAKOGFAMJLN;
inline void fmt(LineBuf& b, const T_EIDAIBHGFDD& v);
inline void fmt(LineBuf& b, const T_EIDAIBHGFDD* v);
inline void fmt(LineBuf& b, const T_IJGACJNNLDA& v);
inline void fmt(LineBuf& b, const T_IJGACJNNLDA* v);
inline void fmt(LineBuf& b, const T_BPOCICOCMJI& v);
inline void fmt(LineBuf& b, const T_BPOCICOCMJI* v);
inline void fmt(LineBuf& b, const T_JCICBDDMHMK& v);
inline void fmt(LineBuf& b, const T_JCICBDDMHMK* v);
inline void fmt(LineBuf& b, const T_FDJEDLNJIEH& v);
inline void fmt(LineBuf& b, const T_FDJEDLNJIEH* v);
inline void fmt(LineBuf& b, const T_BGGFLFOAHGE& v);
inline void fmt(LineBuf& b, const T_BGGFLFOAHGE* v);
inline void fmt(LineBuf& b, const T_UnityEngine_Vector3& v);
inline void fmt(LineBuf& b, const T_UnityEngine_Vector3* v);
inline void fmt(LineBuf& b, const T_MoleMole_Notify& v);
inline void fmt(LineBuf& b, const T_MoleMole_Notify* v);
inline void fmt(LineBuf& b, const T_UnityEngine_Vector2& v);
inline void fmt(LineBuf& b, const T_UnityEngine_Vector2* v);
inline void fmt(LineBuf& b, const T_GCBPLBGGHAL& v);
inline void fmt(LineBuf& b, const T_GCBPLBGGHAL* v);
inline void fmt(LineBuf& b, const T_FDIKBDFDDEA& v);
inline void fmt(LineBuf& b, const T_FDIKBDFDDEA* v);
inline void fmt(LineBuf& b, const T_HAKOGFAMJLN& v);
inline void fmt(LineBuf& b, const T_HAKOGFAMJLN* v);

// EIDAIBHGFDD（32 字节；按引用传参）
struct T_EIDAIBHGFDD { uint8_t raw[32]; };
static_assert(sizeof(T_EIDAIBHGFDD) == 32, "T_EIDAIBHGFDD");

// IJGACJNNLDA（16 字节；按引用传参）
struct T_IJGACJNNLDA { uint8_t raw[16]; };
static_assert(sizeof(T_IJGACJNNLDA) == 16, "T_IJGACJNNLDA");

// BPOCICOCMJI（64 字节；按引用传参）
struct T_BPOCICOCMJI { uint8_t raw[64]; };
static_assert(sizeof(T_BPOCICOCMJI) == 64, "T_BPOCICOCMJI");

// JCICBDDMHMK（96 字节；按引用传参）
struct T_JCICBDDMHMK { uint8_t raw[96]; };
static_assert(sizeof(T_JCICBDDMHMK) == 96, "T_JCICBDDMHMK");

// FDJEDLNJIEH（20 字节；按引用传参）
struct T_FDJEDLNJIEH { uint8_t raw[20]; };
static_assert(sizeof(T_FDJEDLNJIEH) == 20, "T_FDJEDLNJIEH");

// BGGFLFOAHGE（24 字节；按引用传参）
struct T_BGGFLFOAHGE { uint8_t raw[24]; };
static_assert(sizeof(T_BGGFLFOAHGE) == 24, "T_BGGFLFOAHGE");

// Vector3（12 字节；按引用传参）
struct T_UnityEngine_Vector3 { uint8_t raw[12]; };
static_assert(sizeof(T_UnityEngine_Vector3) == 12, "T_UnityEngine_Vector3");

// Notify（24 字节；按引用传参）
struct T_MoleMole_Notify { uint8_t raw[24]; };
static_assert(sizeof(T_MoleMole_Notify) == 24, "T_MoleMole_Notify");

// Vector2（纯浮点聚合 8 字节，<= 8 直接按值传，走 xmm）
struct T_UnityEngine_Vector2 {
    float x;   // +0x00
    float y;   // +0x04
};
static_assert(sizeof(T_UnityEngine_Vector2) == 8, "T_UnityEngine_Vector2");

// GCBPLBGGHAL（56 字节；按引用传参）
struct T_GCBPLBGGHAL { uint8_t raw[56]; };
static_assert(sizeof(T_GCBPLBGGHAL) == 56, "T_GCBPLBGGHAL");

// FDIKBDFDDEA（4 字节；按值传参，整型聚合）
struct T_FDIKBDFDDEA { uint8_t raw[4]; };
static_assert(sizeof(T_FDIKBDFDDEA) == 4, "T_FDIKBDFDDEA");

// HAKOGFAMJLN（16 字节；按引用传参）
struct T_HAKOGFAMJLN { uint8_t raw[16]; };
static_assert(sizeof(T_HAKOGFAMJLN) == 16, "T_HAKOGFAMJLN");

inline void fmt(LineBuf& b, const T_EIDAIBHGFDD& v) {
    b.puts("EIDAIBHGFDD{");
    b.puts("OLABPLAPIIL=");
    fmt(b, rd<T_FDIKBDFDDEA>(&v, 0));
    b.puts(", ");
    b.puts("GNEPBMFADFI=");
    fmt(b, rd<T_MMBJIJOADOD>(&v, 4));
    b.puts(", ");
    b.puts("COMEMDLJFFN=");
    fmt(b, rd<T_JOCMONMOJJD>(&v, 8));
    b.puts(", ");
    b.puts("MICGGGFCNBL=");
    fmt(b, rd<void*>(&v, 16));
    b.puts(", ");
    b.puts("CJELFDAEGBL=");
    fmt(b, rd<T_MMBJIJOADOD>(&v, 24));
    b.puts(", ");
    b.puts("PIJPHKDILAO=");
    fmt(b, rd<T_JOCMONMOJJD>(&v, 28));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_EIDAIBHGFDD* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_IJGACJNNLDA& v) {
    b.puts("IJGACJNNLDA{");
    b.puts("OLHDDMPLLGD=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.puts(", ");
    b.puts("PAHGCDAIMOM=");
    fmt(b, rd<uint32_t>(&v, 4));
    b.puts(", ");
    b.puts("LMEDDIIJOOD=");
    fmt(b, rd<uint32_t>(&v, 8));
    b.puts(", ");
    b.puts("ELIFKNNMFJO=");
    fmt(b, rd<uint32_t>(&v, 12));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_IJGACJNNLDA* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_BPOCICOCMJI& v) {
    b.puts("BPOCICOCMJI{");
    b.puts("EDJGMOGMCIE=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.puts(", ");
    b.puts("ICILJLLHBCK=");
    fmt(b, rd<uint32_t>(&v, 4));
    b.puts(", ");
    b.puts("GGIFDMGMKJL=");
    fmt(b, rd<uint32_t>(&v, 8));
    b.puts(", ");
    b.puts("PACPNFKCLGA=");
    fmt(b, rd<bool>(&v, 12));
    b.puts(", ");
    b.puts("GDHDNNALMEP=");
    fmt(b, rd<bool>(&v, 13));
    b.puts(", ");
    b.puts("KFBONLHBBDG=");
    fmt(b, rd<bool>(&v, 14));
    b.puts(", ");
    b.puts("GKMDADBHCPB=");
    fmt(b, rd<uint32_t>(&v, 16));
    b.puts(", ");
    b.puts("PLJJIHONBKL=");
    fmt(b, rd<uint32_t>(&v, 20));
    b.puts(", ");
    b.puts("FNNNAFAKBNA=");
    fmt(b, rd<uint32_t>(&v, 24));
    b.puts(", ");
    b.puts("EKHJIMKFIIK=");
    fmt(b, rd<T_HAKOGFAMJLN>(&v, 28));
    b.puts(", ");
    b.puts("LNPECDHHKLE=");
    fmt(b, rd<void*>(&v, 48));
    b.puts(", ");
    b.puts("EFCIIKCFJML=");
    fmt(b, rd<uint32_t>(&v, 56));
    b.puts(", ");
    b.puts("IIFOPHAGMBH=");
    fmt(b, rd<uint32_t>(&v, 60));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_BPOCICOCMJI* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_JCICBDDMHMK& v) {
    b.puts("JCICBDDMHMK{");
    b.puts("ICILJLLHBCK=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.puts(", ");
    b.puts("ABOMJBGHECI=");
    fmt(b, rd<uint32_t>(&v, 4));
    b.puts(", ");
    b.puts("PMDLPLCPIEE=");
    fmt(b, rd<uint32_t>(&v, 8));
    b.puts(", ");
    b.puts("DGNPEJAHPHB=");
    fmt(b, rd<uint32_t>(&v, 12));
    b.puts(", ");
    b.puts("EFCIIKCFJML=");
    fmt(b, rd<uint32_t>(&v, 16));
    b.puts(", ");
    b.puts("GFJKAPBNKJH=");
    fmt(b, rd<uint32_t>(&v, 20));
    b.puts(", ");
    b.puts("NBJJMKIBMIM=");
    fmt(b, rd<uint32_t>(&v, 24));
    b.puts(", ");
    b.puts("EANCLNKCOIA=");
    fmt(b, rd<uint32_t>(&v, 28));
    b.puts(", ");
    b.puts("HBEKGAEPKAM=");
    fmt(b, rd<uint32_t>(&v, 32));
    b.puts(", ");
    b.puts("KBFMPKBGBOD=");
    fmt(b, rd<uint32_t>(&v, 36));
    b.puts(", ");
    b.puts("MKCNNHKANNF=");
    fmt(b, rd<bool>(&v, 40));
    b.puts(", ");
    b.puts("BEAHEFNJNCP=");
    fmt(b, rd<T_UnityEngine_Vector3>(&v, 44));
    b.puts(", ");
    b.puts("GKMDADBHCPB=");
    fmt(b, rd<uint32_t>(&v, 56));
    b.puts(", ");
    b.puts("PLJJIHONBKL=");
    fmt(b, rd<uint32_t>(&v, 60));
    b.puts(", ");
    b.puts("BFCJHNEDGPJ=");
    fmt(b, rd<uint32_t>(&v, 64));
    b.puts(", ");
    b.puts("OLOLIADDMPL=");
    fmt(b, rd<bool>(&v, 68));
    b.puts(", ");
    b.puts("ODJKBAGEOMA=");
    fmt(b, rd<bool>(&v, 69));
    b.puts(", ");
    b.puts("KEBHIBMDHFI=");
    fmt(b, rd<void*>(&v, 72));
    b.puts(", ");
    b.puts("EKHJIMKFIIK=");
    fmt(b, rd<T_HAKOGFAMJLN>(&v, 80));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_JCICBDDMHMK* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_FDJEDLNJIEH& v) {
    b.puts("FDJEDLNJIEH{");
    b.puts("ICILJLLHBCK=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.puts(", ");
    b.puts("LMEDDIIJOOD=");
    fmt(b, rd<uint32_t>(&v, 4));
    b.puts(", ");
    b.puts("ELIFKNNMFJO=");
    fmt(b, rd<uint32_t>(&v, 8));
    b.puts(", ");
    b.puts("PAHGCDAIMOM=");
    fmt(b, rd<uint32_t>(&v, 12));
    b.puts(", ");
    b.puts("EANLLEAPANL=");
    fmt(b, rd<T_IDGNBAFCBOI>(&v, 16));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_FDJEDLNJIEH* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_BGGFLFOAHGE& v) {
    b.puts("BGGFLFOAHGE{");
    b.puts("PEOMOFADDBJ=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.puts(", ");
    b.puts("INOFPNMINMP=");
    fmt(b, rd<bool>(&v, 4));
    b.puts(", ");
    b.puts("EFIIICPBEMG=");
    fmt(b, rd<uint32_t>(&v, 8));
    b.puts(", ");
    b.puts("FINGAMEFIPG=");
    fmt(b, rd<T_MoleMole_Config_QuestState>(&v, 12));
    b.puts(", ");
    b.puts("KEBHIBMDHFI=");
    fmt(b, rd<void*>(&v, 16));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_BGGFLFOAHGE* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_UnityEngine_Vector3& v) {
    b.puts("Vector3{");
    b.puts("x=");
    fmt(b, rd<float>(&v, 0));
    b.puts(", ");
    b.puts("y=");
    fmt(b, rd<float>(&v, 4));
    b.puts(", ");
    b.puts("z=");
    fmt(b, rd<float>(&v, 8));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_UnityEngine_Vector3* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_MoleMole_Notify& v) {
    b.puts("Notify{");
    b.puts("type=");
    fmt(b, rd<T_GFJCNBMJPCH>(&v, 0));
    b.puts(", ");
    b.puts("body=");
    fmt(b, rd<void*>(&v, 8));
    b.puts(", ");
    b.puts("udpPacket=");
    fmt(b, rd<void*>(&v, 16));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_MoleMole_Notify* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_UnityEngine_Vector2& v) {
    b.puts("Vector2{");
    b.puts("x=");
    fmt(b, v.x);
    b.puts(", ");
    b.puts("y=");
    fmt(b, v.y);
    b.put('}');
}
inline void fmt(LineBuf& b, const T_UnityEngine_Vector2* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_GCBPLBGGHAL& v) {
    b.puts("GCBPLBGGHAL{");
    b.puts("KEDLGGIKIPP=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.puts(", ");
    b.puts("FCGFOOMCAPM=");
    fmt(b, rd<uint64_t>(&v, 8));
    b.puts(", ");
    b.puts("FAGIEAPBLCP=");
    fmt(b, rd<uint32_t>(&v, 16));
    b.puts(", ");
    b.puts("GFJKAPBNKJH=");
    fmt(b, rd<uint32_t>(&v, 20));
    b.puts(", ");
    b.puts("OOOEOOOODDC=");
    fmt(b, rd<uint32_t>(&v, 24));
    b.puts(", ");
    b.puts("KBFPHHAIBGI=");
    fmt(b, rd<bool>(&v, 28));
    b.puts(", ");
    b.puts("ADMNDLJIACM=");
    fmt(b, rd<void*>(&v, 32));
    b.puts(", ");
    b.puts("AKEEJCBELMN=");
    fmt(b, rd<void*>(&v, 40));
    b.puts(", ");
    b.puts("ODEBAMOGPAJ=");
    fmt(b, rd<uint32_t>(&v, 48));
    b.puts(", ");
    b.puts("GAJADADKLNP=");
    fmt(b, rd<T_DGKHDNOFHAO>(&v, 52));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_GCBPLBGGHAL* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_FDIKBDFDDEA& v) {
    b.puts("FDIKBDFDDEA{");
    b.puts("CBOMLBFIPJM=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_FDIKBDFDDEA* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

inline void fmt(LineBuf& b, const T_HAKOGFAMJLN& v) {
    b.puts("HAKOGFAMJLN{");
    b.puts("PIPFOKEGPPO=");
    fmt(b, rd<uint32_t>(&v, 0));
    b.puts(", ");
    b.puts("PMJPCGHENDB=");
    fmt(b, rd<uint32_t>(&v, 4));
    b.puts(", ");
    b.puts("BFCJHNEDGPJ=");
    fmt(b, rd<uint32_t>(&v, 8));
    b.puts(", ");
    b.puts("NKDBDJDOLHJ=");
    fmt(b, rd<uint32_t>(&v, 12));
    b.put('}');
}
inline void fmt(LineBuf& b, const T_HAKOGFAMJLN* v) {
    if (!v) { b.puts("null"); return; }
    fmt(b, *v);
}

}  // namespace jk
