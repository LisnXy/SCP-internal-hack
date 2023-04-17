#include "LinMemory.h"
namespace LinMemory {
	void __fastcall fillWithNop(LPVOID target, size_t size)
	{
		DWORD oldProtect;
		VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &oldProtect);
		memset(target, 0x90, size);
		VirtualProtect(target, size, oldProtect, &oldProtect);
	}
}