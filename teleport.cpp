#include "includes.h"

void Teleport(DWORD localPlayerPtr, HANDLE handle, bool Bool)
{
	float Y;
	ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + Y_POS_OFFSET), &Y, sizeof(Y), nullptr);
	if (Bool) {
		float newY = Y + 4.0f;
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + Y_POS_OFFSET), &newY, sizeof(newY), nullptr);
		std::cout << "Teleport : " << newY << std::endl;
	}
	else if (!Bool) {
		float newY = Y - 1.0f;
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + Y_POS_OFFSET), &newY, sizeof(newY), nullptr);
		std::cout << "Teleport : " << newY << std::endl;
	};
 }