#include "includes.h"

void Teleport(float Y, DWORD localPlayerPtr, HANDLE handle)
{
	float newY = Y + 4.0f;
	WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + Y_POS_OFFSET), &newY, sizeof(newY), nullptr);
	std::cout << "Teleport : " << newY << std::endl;
 }
