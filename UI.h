#pragma once
#include <Windows.h>
#include <string>
namespace UI {
	DWORD WINAPI InitUI(LPVOID lpReserved);

	void drawImgui();
	void checkFeatures();
}