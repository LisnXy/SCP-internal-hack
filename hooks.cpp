#include "hooks.h"
#include "MinHook.h"
#include <stdio.h>
#include "hack.h"

namespace hook {
	/*
	*  basic information
	*/
	uintptr_t GameAssemblyAddress = 0;
	/*
	*  method info to call the functions inside of the game
	*/
	const MethodInfo* TransformGetPosition = nullptr; // this is a nullptr, we dont need to init it
	const MethodInfo* WorldToScreenPoint = nullptr;  // this is a nullptr, we dont need to init it
	const MethodInfo* GetMainCamera = nullptr;  // this is a nullptr, we dont need to init it
	const MethodInfo* GetRoleName = nullptr;  // this is a nullptr, we dont need to init it
	// playerList is a singleton obect, so we only need to init it once
	PlayerList_o* playerList = nullptr;
	System_Collections_Generic_List_PlayerList_Instance__o* instances = nullptr;
	UnityEngine_Camera_o* camera = nullptr;
	/*
	*  original function pointer
	*/
	bool(__fastcall* SetCurValue_original)(DWORD*, float, DWORD*);
	void(__fastcall* AddEffect_original)(DWORD*, DWORD*);
	float(__fastcall* Range_original)(float, float, DWORD*);
	float(__fastcall* GetAttaValue_original)(DWORD*, int32_t, DWORD*);
	void(__fastcall* PlayerListStart_original)(DWORD*, DWORD*);
	UnityEngine_Vector3_o(__fastcall* TransformGetPosition_original)(UnityEngine_Transform_o*, const MethodInfo*);
	UnityEngine_Camera_o* (__fastcall* GetMainCamera_original)(const MethodInfo* method);
	UnityEngine_Vector3_o(__fastcall* WorldToScreenPoint_original)(UnityEngine_Camera_o*, UnityEngine_Vector3_o, const MethodInfo*);
	System_String_o* (__fastcall* GetRoleName_original)(PlayerRoles_PlayerRoleBase_o* __this, const MethodInfo* method);
	/*
	* flags that indicate whether the hook is enabled
	*/
	bool enabledAddEffect = false;
	bool enabledArmSet = false;

	/*
	* Init function to create hook but not enable it
	*/
	void Init(uintptr_t baseAddress) {
		GameAssemblyAddress = baseAddress;
		//MH_Initialize();
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::SetCur), &SetCurValue_hook, (LPVOID*)&SetCurValue_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::AddEffect), &AddEffect_hook, (LPVOID*)&AddEffect_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetAttaValue), &GetAttaValue_hook, (LPVOID*)&GetAttaValue_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::PlayerListStart), &PlayerListStart_hook, (LPVOID*)&PlayerListStart_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::TransformGetPosition), &TransformGetPosition_hook, (LPVOID*)&TransformGetPosition_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetMainCamera), &GetMainCamera_hook, (LPVOID*)&GetMainCamera_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::WorldToScreenPoint), &WorldToScreenPoint_hook, (LPVOID*)&WorldToScreenPoint_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetRoleName), &GetRoleName_hook, (LPVOID*)&GetRoleName_original);
		// necessary hook, can't be disabled by user.
		MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::PlayerListStart));
		MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::TransformGetPosition));
		MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetMainCamera));
		MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::WorldToScreenPoint));
		MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetRoleName));
	}

	void enableSetCurValue() {
		MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::SetCur));
	}

	void disableSetCurValue() {
		MH_DisableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::SetCur));
	}

	// relative to remove the comera shake.
	void enableAddEffect() {
		if (!enabledAddEffect) {
			MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::AddEffect));
			enabledAddEffect = true;
		}
	}

	void disableAddEffect() {
		if (enabledAddEffect) {
			MH_DisableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::AddEffect));
			enabledAddEffect = false;
		}
	}

	void enableGetAttaValue() {
		if (!enabledArmSet) {
			MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetAttaValue));
			enabledArmSet = true;
		}
	}

	void disableGetAttaValue() {
		if (enabledArmSet) {
			MH_DisableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetAttaValue));
			enabledArmSet = false;
		}
	}

	/*
	*  hook functions
	*/
	bool __stdcall SetCurValue_hook(DWORD* __this, float value, DWORD* method) {
		/*printf("SetCurValue_hook called, Value is %f \n", value);*/
		return SetCurValue_original(__this, hack::health, method);
	}

	void __stdcall AddEffect_hook(DWORD* effect, DWORD* method) {
		//printf("AddEffect_hook called %p\n", effect);
	}

	float __stdcall GetAttaValue_hook(DWORD* __this, int32_t param, DWORD* method) {
		float result = GetAttaValue_original(__this, param, method);
		switch (param) {
		case 0:
			return hack::AdsInaccuracyMultiplier;
			break;
		case 6:
			return hack::AdsRecoilMultiplier;
			break;
		case 16:
			return hack::AdsSpeedMultiplier;
			break;
		case 19:
			return hack::AmmoConsumptionMultiplier;
			break;
		case 7:
			return hack::BulletInaccuracyMultiplier;
			break;
		case 2:
			return hack::DamageMultiplier;
			break;
		case 4:
			return hack::FireRateMultiplier;
			break;
		case 8:
			return hack::HipInaccuracyMultiplier;
			break;
		case 5:
			return hack::OverallRecoilMultiplier;
			break;
		case 3:
			return hack::PenetrationMultiplier;
			break;
		case 20:
			return hack::ReloadSpeedMultiplier;
			break;
		case 17:
			return hack::SpreadMultiplier;
			break;
		case 18:
			return hack::SpreadPredictability;
			break;
		default:break;
		}
		return result;
	}

	void __stdcall PlayerListStart_hook(DWORD* __this, DWORD* method) {
		// started call everytime we get into a new game,
		// so we should init the playerlist everytime this function is called.
		if (playerList == nullptr) {
			InitPlayerListAddress(reinterpret_cast<PlayerList_o*>(__this));
		}
		// release last game's cameral
		if (camera != nullptr) {
			printf("release camera %p\n", camera);
			camera = nullptr;
		}
		return PlayerListStart_original(__this, method);
	}

	UnityEngine_Vector3_o __stdcall TransformGetPosition_hook(UnityEngine_Transform_o* __this, const MethodInfo* method)
	{
		return TransformGetPosition_original(__this, method);
	}

	UnityEngine_Camera_o* __stdcall GetMainCamera_hook(const MethodInfo* method)
	{
		camera = GetMainCamera_original(method);
		return camera;
	}

	UnityEngine_Vector3_o __stdcall WorldToScreenPoint_hook(UnityEngine_Camera_o* __this, UnityEngine_Vector3_o position, const MethodInfo* method)
	{
		return WorldToScreenPoint_original(__this, position, method);
	}

	System_String_o* __stdcall GetRoleName_hook(PlayerRoles_PlayerRoleBase_o* __this, const MethodInfo* method) {
		return GetRoleName_original(__this, method);
	}

	/*
	*  other functions
	*/
	// get the player list
	void InitPlayerListAddress(PlayerList_o* playerList_o) {
		playerList = playerList_o->klass->static_fields->singleton;
		uintptr_t instences_address = (uintptr_t)playerList->klass->static_fields->instances;
		instances = (System_Collections_Generic_List_PlayerList_Instance__o*)instences_address;
	}
}