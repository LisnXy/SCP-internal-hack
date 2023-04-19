#include "hooks.h"
#include "pch.h"
#include <cstdio>
#include "UI.h"
#include "MinHook.h"
uintptr_t GameAssemblyAddress = 0;
HMODULE GameAssembly = NULL;

void CreateConsole() {
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
}

void init() {
	// find the base address of "GameAssembly.dll"
	GameAssembly = GetModuleHandleA("GameAssembly.dll");
	while (GameAssembly == NULL) {
		GameAssembly = GetModuleHandleA("GameAssembly.dll");
	}
	GameAssemblyAddress = uintptr_t(GameAssembly);
	printf("GameAssembly base: %llu\n", GameAssemblyAddress);
	// Init hook
	hook::Init(GameAssemblyAddress);
}

void main(LPVOID lpReserved) {
	CreateConsole();
	// 卸载所有钩子
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	// 取消初始化 MinHook 库
	MH_Uninitialize();
	MH_Initialize();
	UI::InitUI(lpReserved);
	init();
	hook::enableAddEffect();
	hook::enableGetAttaValue();
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH: {
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, hModule, 0, 0);
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}