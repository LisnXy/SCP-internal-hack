#pragma once
#include <Windows.h>
#include "offset.h"
#include <cstdint>
#include "il2cpp.h"

namespace hook {
	/// <summary>
	/// Init function of the hooks, ensure to call this function after "GameAssembly.dll"
	/// has been loaded into memory.
	/// </summary>
	void Init(uintptr_t baseAddress);
	/*
	*  global variables
	*/
	extern System_Collections_Generic_List_PlayerList_Instance__o* instances;
	extern UnityEngine_Camera_o* camera;
	extern const MethodInfo* TransformGetPosition;
	extern const MethodInfo* WorldToScreenPoint;
	extern const MethodInfo* GetMainCamera;
	extern const MethodInfo* GetRoleName;
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
	UnityEngine_Vector3_o __stdcall TransformGetPosition_hook(UnityEngine_Transform_o* __this, const MethodInfo* method);
	UnityEngine_Camera_o* __stdcall GetMainCamera_hook(const MethodInfo* method);
	UnityEngine_Vector3_o __stdcall WorldToScreenPoint_hook(UnityEngine_Camera_o* __this, UnityEngine_Vector3_o position, const MethodInfo* method);
	System_String_o* __stdcall GetRoleName_hook(PlayerRoles_PlayerRoleBase_o* __this, const MethodInfo* method);
	/*
	*	other functions
	*/
	void InitPlayerListAddress(PlayerList_o* playerList_o);
}