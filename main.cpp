#include "includes.h"

int main()
{
	DWORD pID, baseModule, localPlayerPtr;
	int health = 999;
	float x;
	float y;

	pID = GetProcessID(L"ac_client.exe");

	baseModule = GetModuleBaseAddress(pID, L"ac_client.exe");

	std::cout << pID << std::endl;
	std::cout << std::hex << baseModule << std::endl;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);

	ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x17E0A8), &localPlayerPtr, sizeof(localPlayerPtr), nullptr);


	std::cout << std::hex << localPlayerPtr << std::endl;

	while (true) 
	{
		ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + 0x34), &x, sizeof(x), nullptr);
		ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + 0x38), &y, sizeof(y), nullptr);
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + 0xEC), &health, sizeof(health), nullptr);

		std::cout << "X: " << x << "| Y: " << y << std::endl;

	}

	return 0;
}
