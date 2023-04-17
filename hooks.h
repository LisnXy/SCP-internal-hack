#pragma once
#include <Windows.h>
#include "offset.h"
#include "struct.h"
#include <cstdint>

namespace hook {
	/// <summary>
	/// Init function of the hooks, ensure to call this function after "GameAssembly.dll"
	/// has been loaded into memory.
	/// </summary>
	void Init(uintptr_t baseAddress);

	extern uintptr_t PlayerListAddress;
	/*
		hook operators
	*/
	// SetCurValue is used when player is cured(like using a medkit)
	void enableSetCurValue();
	void disableSetCurValue();
	// used to remove camera shake
	void enableAddEffect();
	void disableAddEffect();
	// get attachment value
	void enableGetAttaValue();
	void disableGetAttaValue();
	/*
		hook functions
	*/
	bool __stdcall SetCurValue_hook(DWORD* __this, float value, DWORD* method);
	void __stdcall AddEffect_hook(DWORD* effect, DWORD* method);
	float __stdcall GetAttaValue_hook(DWORD* __this, int32_t param, DWORD* method);
	void __stdcall PlayerListStart_hook(DWORD* __this, DWORD* method);

	/*
	*	other functions
	*/
	void InitPlayerListAddress(uintptr_t playerList_o);
}