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
}