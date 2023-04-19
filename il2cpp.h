#pragma once

#include <Windows.h>
#include <cstdint>

typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;
typedef void(*Il2CppMethodPointer)();

struct __declspec(align(8)) UnityEngine_Object_Fields {
	intptr_t m_CachedPtr;
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
};

struct UnityEngine_Transform_Fields : UnityEngine_Component_Fields {
};
struct ToggleableMenus_ToggleableMenuBase_Fields : UnityEngine_MonoBehaviour_Fields {
	bool _isEnabled;
	int32_t MenuActionKey;
};

struct ToggleableMenus_SimpleToggleableMenu_Fields : ToggleableMenus_ToggleableMenuBase_Fields {
	struct UnityEngine_GameObject_o* _targetRoot;
};

struct Il2CppObject
{
	LPVOID klass;
	void* monitor;
};

struct RecyclablePlayerId_Fields {
	int32_t Value;
};

struct Il2CppArrayBounds
{
	il2cpp_array_size_t length;
	il2cpp_array_lower_bound_t lower_bound;
};

struct RecyclablePlayerId_o {
	RecyclablePlayerId_Fields fields;
};

struct UnityEngine_Transform_o {
	LPVOID klass;
	void* monitor;
	UnityEngine_Transform_Fields fields;
};

struct UnityEngine_LayerMask_Fields {
	int32_t m_Mask;
};

struct UnityEngine_LayerMask_o {
	UnityEngine_LayerMask_Fields fields;
};

struct __declspec(align(8)) System_String_Fields {
	int32_t m_stringLength;
	uint16_t m_firstChar;
};

struct System_String_o {
	LPVOID klass;
	void* monitor;
	System_String_Fields fields;
};

struct Mirror_NetworkBehaviour_Fields : UnityEngine_MonoBehaviour_Fields {
	float lastSyncTime;
	int32_t syncMode;
	float syncInterval;
	uint64_t _syncVarDirtyBits_k__BackingField;
	uint64_t syncVarHookGuard;
	struct System_Collections_Generic_List_SyncObject__o* syncObjects;
	struct Mirror_NetworkIdentity_o* netIdentityCache;
};

struct NicknameSync_Fields : Mirror_NetworkBehaviour_Fields {
	struct UnityEngine_LayerMask_o RaycastMask;
	struct ReferenceHub_o* _hub;
	LPVOID _nText;
	LPVOID _renderer;
	float _transparency;
	LPVOID _nickFilter;
	struct System_String_o* _replacement;
	bool _NickSet_k__BackingField;
	float ViewRange;
	struct System_String_o* _customPlayerInfoString;
	struct System_String_o* _sanitizedPlayerInfoString;
	int32_t _playerInfoToShow;
	struct System_String_o* _myNickSync;
	struct System_String_o* _firstNickname;
	struct System_String_o* _displayName;
	struct System_String_o* _cleanDisplayName;
};

struct NicknameSync_o {
	LPVOID klass;
	void* monitor;
	NicknameSync_Fields fields;
};

struct ReferenceHub_Fields : Mirror_NetworkBehaviour_Fields {
	struct RecyclablePlayerId_o _playerId;
	struct UnityEngine_Transform_o* PlayerCameraReference;
	LPVOID networkIdentity;
	LPVOID characterClassManager;
	struct PlayerRoles_PlayerRoleManager_o* roleManager;
	struct PlayerStatsSystem_PlayerStats_o* playerStats;
	LPVOID inventory;
	LPVOID searchCoordinator;
	LPVOID serverRoles;
	LPVOID queryProcessor;
	struct NicknameSync_o* nicknameSync;
	LPVOID playerInteract;
	LPVOID interCoordinator;
	LPVOID playerEffectsController;
	LPVOID hints;
	LPVOID aspectRatioSync;
	LPVOID playerRateLimitHandler;
	LPVOID gameConsoleTransmission;
	LPVOID FriendlyFireHandler;
};

struct ReferenceHub_o {
	LPVOID klass;
	void* monitor;
	ReferenceHub_Fields fields;
};

struct __declspec(align(8)) PlayerList_Instance_Fields {
	struct ReferenceHub_o* owner;
	struct PlayerListElement_o* listElementReference;
};

struct PlayerList_Instance_o {
	LPVOID klass;
	void* monitor;
	PlayerList_Instance_Fields fields;
};

struct UnityEngine_Vector3_Fields {
	float x;
	float y;
	float z;
};

struct UnityEngine_Vector3_o {
	UnityEngine_Vector3_Fields fields;
};

struct PlayerList_Instance_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	PlayerList_Instance_o* m_Items[65535];
};

struct __declspec(align(8)) System_Collections_Generic_List_PlayerList_Instance__Fields {
	struct PlayerList_Instance_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};

struct System_Collections_Generic_List_PlayerList_Instance__o {
	LPVOID klass;
	void* monitor;
	System_Collections_Generic_List_PlayerList_Instance__Fields fields;
};

struct PlayerList_StaticFields {
	LPVOID _refreshRate;
	LPVOID Title;
	bool _eventsAssigned;
	LPVOID _alreadyAddedPlayers;
	LPVOID ica;
	struct PlayerList_o* singleton;
	LPVOID s_parent;
	LPVOID s_template;
	bool _anyAdminOnServer;
	struct System_Collections_Generic_List_PlayerList_Instance__o* instances;
};

struct Il2CppType
{
	void* data;
	unsigned int bits;
};

struct Il2CppClass;

struct Il2CppRuntimeInterfaceOffsetPair
{
	Il2CppClass* interfaceType;
	int32_t offset;
};
struct Il2CppClass_1
{
	void* image;
	void* gc_desc;
	const char* name;
	const char* namespaze;
	Il2CppType byval_arg;
	Il2CppType this_arg;
	Il2CppClass* element_class;
	Il2CppClass* castClass;
	Il2CppClass* declaringType;
	Il2CppClass* parent;
	void* generic_class;
	void* typeDefinition;
	void* interopData;
	Il2CppClass* klass;
	void* fields;
	void* events;
	void* properties;
	void* methods;
	Il2CppClass** nestedTypes;
	Il2CppClass** implementedInterfaces;
	Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
};

struct Il2CppClass_2
{
	Il2CppClass** typeHierarchy;
	void* unity_user_data;
	uint32_t initializationExceptionGCHandle;
	uint32_t cctor_started;
	uint32_t cctor_finished;
	size_t cctor_thread;
	int32_t genericContainerIndex;
	uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;
	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;
	uint8_t typeHierarchyDepth;
	uint8_t genericRecursionDepth;
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t naturalAligment;
	uint8_t packingSize;
	uint8_t bitflags1;
	uint8_t bitflags2;
};

struct MethodInfo;

union Il2CppRGCTXData
{
	void* rgctxDataDummy;
	const MethodInfo* method;
	const Il2CppType* type;
	Il2CppClass* klass;
};

struct VirtualInvokeData
{
	Il2CppMethodPointer methodPtr;
	const MethodInfo* method;
};

struct Il2CppClass
{
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[255];
};

struct MethodInfo
{
	Il2CppMethodPointer methodPointer;
	void* invoker_method;
	const char* name;
	Il2CppClass* klass;
	const Il2CppType* return_type;
	const void* parameters;
	union
	{
		const Il2CppRGCTXData* rgctx_data;
		const void* methodDefinition;
	};
	union
	{
		const void* genericMethod;
		const void* genericContainer;
	};
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint8_t parameters_count;
	uint8_t bitflags;
};

struct PlayerList_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_get_CanToggle;
	VirtualInvokeData _7_get_CursorOverride;
	VirtualInvokeData _8_get_LockMovement;
	VirtualInvokeData _9_get_IsEnabled;
	VirtualInvokeData _10_set_IsEnabled;
	VirtualInvokeData _11_OnToggled;
	VirtualInvokeData _12_Awake;
	VirtualInvokeData _13_OnDestroy;
};

struct PlayerList_c {
	Il2CppClass_1 _1;
	struct PlayerList_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	PlayerList_VTable vtable;
};

struct PlayerList_Fields : ToggleableMenus_SimpleToggleableMenu_Fields {
	struct UnityEngine_Transform_o* parent;
	struct UnityEngine_Transform_o* _template;
	struct UnityEngine_GameObject_o* mainPanel;
	struct UnityEngine_GameObject_o* reportForm;
	struct UnityEngine_GameObject_o* reportPopup;
	struct TMPro_TextMeshProUGUI_o* badgeText;
	struct TMPro_TextMeshProUGUI_o* timerText;
	struct TMPro_TextMeshProUGUI_o* serverNameText;
	struct TMPro_TextMeshProUGUI_o* reportPopupText;
	int32_t _timer;
};

struct PlayerList_o {
	PlayerList_c* klass;
	void* monitor;
	PlayerList_Fields fields;
};

struct UnityEngine_Camera_Fields : UnityEngine_Behaviour_Fields {
};
struct UnityEngine_Camera_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Camera_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Camera_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Camera_VTable vtable;
};
struct UnityEngine_Camera_o {
	UnityEngine_Camera_c* klass;
	void* monitor;
	UnityEngine_Camera_Fields fields;
};

struct System_Char_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	uint16_t m_Items[65535];
};

struct PlayerRoles_PlayerRoleManager_Fields : Mirror_NetworkBehaviour_Fields {
	struct System_Collections_Generic_Dictionary_uint__RoleTypeId__o* PreviouslySentRole;
	struct ReferenceHub_o* _hub;
	bool _hubSet;
	bool _anySet;
	bool _sendNextFrame;
	struct PlayerRoles_PlayerRoleBase_o* _curRole;
};
struct PlayerRoles_PlayerRoleManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_OnSerialize;
	VirtualInvokeData _5_OnDeserialize;
	VirtualInvokeData _6_SerializeSyncVars;
	VirtualInvokeData _7_DeserializeSyncVars;
	VirtualInvokeData _8_OnStartServer;
	VirtualInvokeData _9_OnStopServer;
	VirtualInvokeData _10_OnStartClient;
	VirtualInvokeData _11_OnStopClient;
	VirtualInvokeData _12_OnStartLocalPlayer;
	VirtualInvokeData _13_OnStartAuthority;
	VirtualInvokeData _14_OnStopAuthority;
};
struct PlayerRoles_PlayerRoleManager_c {
	Il2CppClass_1 _1;
	struct PlayerRoles_PlayerRoleManager_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	PlayerRoles_PlayerRoleManager_VTable vtable;
};
struct PlayerRoles_PlayerRoleManager_o {
	PlayerRoles_PlayerRoleManager_c* klass;
	void* monitor;
	PlayerRoles_PlayerRoleManager_Fields fields;
};
struct PlayerRoles_PlayerRoleManager_StaticFields {
	struct PlayerRoles_PlayerRoleManager_ServerRoleSet_o* OnServerRoleSet;
	struct PlayerRoles_PlayerRoleManager_RoleChanged_o* OnRoleChanged;
};

struct GameObjectPools_PoolObject_Fields : UnityEngine_MonoBehaviour_Fields {
	int32_t InitialPoolSize;
	int32_t OverflowMode;
	bool _Pooled_k__BackingField;
	struct GameObjectPools_IPoolResettable_array* _poolResetables;
	struct GameObjectPools_IPoolSpawnable_array* _poolSpawnables;
	struct GameObjectPools_Pool_o* __myPool_k__BackingField;
};

struct PlayerRoles_PlayerRoleBase_Fields : GameObjectPools_PoolObject_Fields {
	struct ReferenceHub_o* _lastOwner;
	int32_t _spawnFlags;
	uint8_t _spawnReason;
	struct System_Diagnostics_Stopwatch_o* _activeTime;
	struct UnityEngine_GameObject_o* _RoleHelpInfo_k__BackingField;
	struct System_Action_RoleTypeId__o* OnRoleDisabled;
};
struct PlayerRoles_PlayerRoleBase_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_get_RoleHelpInfo;
	VirtualInvokeData _8_Init;
	VirtualInvokeData _9_DisableRole;
};
struct PlayerRoles_PlayerRoleBase_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	PlayerRoles_PlayerRoleBase_VTable vtable;
};
struct PlayerRoles_PlayerRoleBase_o {
	PlayerRoles_PlayerRoleBase_c* klass;
	void* monitor;
	PlayerRoles_PlayerRoleBase_Fields fields;
};
struct UnityEngine_Color_Fields {
	float r;
	float g;
	float b;
	float a;
};
struct UnityEngine_Color_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
};
struct UnityEngine_Color_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Color_VTable vtable;
};

struct UnityEngine_Color_o {
	UnityEngine_Color_Fields fields;
};

struct PlayerRoles_FirstPersonControl_FpcStandardRoleBase_Fields : PlayerRoles_PlayerRoleBase_Fields {
	LPVOID _FpcModule_k__BackingField;
	LPVOID _SpectatorModule_k__BackingField;
	LPVOID _VoiceModule_k__BackingField;
	LPVOID _VisibilityController_k__BackingField;
	LPVOID _Ragdoll_k__BackingField;
	LPVOID _RoleAvatar_k__BackingField;
	struct UnityEngine_Vector3_o _lastPos;
	struct UnityEngine_Transform_o* _hubTransform;
	struct UnityEngine_Transform_o* _cameraTransform;
	LPVOID _noLightFx;
};

struct PlayerRoles_HumanRole_Fields : PlayerRoles_FirstPersonControl_FpcStandardRoleBase_Fields {
	int8_t _roleId;
	uint8_t _team;
	struct UnityEngine_Color_o _roleColor;
	LPVOID _spawnpoints;
	uint8_t _AssignedSpawnableTeam_k__BackingField;
	uint8_t _UnitNameId_k__BackingField;
};