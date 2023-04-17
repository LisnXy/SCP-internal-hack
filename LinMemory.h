#pragma once
#include <Windows.h>

namespace LinMemory {
	void __fastcall fillWithNop(LPVOID target, size_t size);
}
