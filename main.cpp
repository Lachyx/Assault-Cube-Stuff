#include "includes.h"

using namespace std;

int main()
{
	DWORD pID, baseModule, localPlayerPtr;
	int health = 999;
	int armor = 999;
	int grenades = 999;
	int ammo = 999;
	float viewx;
	float viewy;
	float x;
	float y;
	float z;
	BYTE gravity;
	pID = GetProcessID(L"ac_client.exe");

	baseModule = GetModuleBaseAddress(pID, L"ac_client.exe");

	std::cout << pID << std::endl;
	std::cout << std::hex << baseModule << std::endl;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);

	ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x17E0A8), &localPlayerPtr, sizeof(localPlayerPtr), nullptr);


	std::cout << std::hex << localPlayerPtr << std::endl;

	while (true)
	{
		ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + VIEW_X_OFFSET), &viewx, sizeof(viewx), nullptr);
		ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + VIEW_Y_OFFSET), &viewy, sizeof(viewy), nullptr);
		ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + X_POS_OFFSET), &x, sizeof(x), nullptr);
		ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + Z_POS_OFFSET), &z, sizeof(z), nullptr);
		ReadProcessMemory(handle, (LPVOID)(localPlayerPtr + GRAVITY_OFFSET), &gravity, sizeof(gravity), nullptr);
		ReadProcessMemory(handle, (LPCVOID)(localPlayerPtr + Y_POS_OFFSET), &y, sizeof(y), nullptr);

		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + AMMO_OFFSET), &ammo, sizeof(ammo), nullptr);
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + HEALTH_OFFSET), &health, sizeof(health), nullptr);
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + ARMOR_OFFSET), &armor, sizeof(armor), nullptr);
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + GRENADES_OFFSET), &grenades, sizeof(grenades), nullptr);

	}

	return 0;
}
