#include "hooks.h"
#include "MinHook.h"
#include <stdio.h>
#include "hack.h"

namespace hook {
	/*
	*  basic address
	*/
	uintptr_t GameAssemblyAddress = 0;
	/*
	*  original function pointer
	*/
	bool(__fastcall* SetCurValue_original)(DWORD*, float, DWORD*);
	void(__fastcall* AddEffect_original)(DWORD*, DWORD*);
	float(__fastcall* Range_original)(float, float, DWORD*);
	float(__fastcall* GetAttaValue_original)(DWORD*, int32_t, DWORD*);
	void(__fastcall* PlayerListStart_original)(DWORD*, DWORD*);
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
		MH_Initialize();
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::SetCur), &SetCurValue_hook, (LPVOID*)&SetCurValue_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::AddEffect), &AddEffect_hook, (LPVOID*)&AddEffect_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::GetAttaValue), &GetAttaValue_hook, (LPVOID*)&GetAttaValue_original);
		MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::PlayerListStart), &PlayerListStart_hook, (LPVOID*)&PlayerListStart_original);
		// necessary hook, can't be disabled by user.
		MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssemblyAddress + offset::PlayerListStart));
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
		printf("PlayListStart_hook called %p\n", __this);
		InitPlayerListAddress((uintptr_t)__this);
		return PlayerListStart_original(__this, method);
	}

	/*
	*  other functions
	*/
	// get the address of the player list
	void InitPlayerListAddress(uintptr_t playerList_o) {
	}
}