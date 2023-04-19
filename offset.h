#pragma once
#include <Windows.h>

namespace offset {
	// PlayerStatusSystem
	uintptr_t constexpr SetCur = 0xEE9390;
	// CameraShakeController
	uintptr_t constexpr AddEffect = 0x126E070;
	// Attachment
	uintptr_t constexpr GetAttaValue = 0xF95550;
	// PlayerList.Start()
	uintptr_t constexpr PlayerListStart = 0xE76760;
	// UnityEngine.Transform.get_position()
	uintptr_t constexpr TransformGetPosition = 0x14FBAB0;
	// Camera.get_main();
	uintptr_t constexpr GetMainCamera = 0x972730;
	// Camera.WorldToScreenPoint()
	uintptr_t constexpr WorldToScreenPoint = 0x972110;
	// PlayerRoles.Rolebase.GetRoleName()
	uintptr_t constexpr GetRoleName = 0xF54E50;
}