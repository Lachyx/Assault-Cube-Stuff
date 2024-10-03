#include "includes.h"

using namespace std;

int main()
{
	DWORD pID, baseModule, localPlayerPtr;
	BYTE gravity;
	pID = GetProcessID(L"ac_client.exe");

	baseModule = GetModuleBaseAddress(pID, L"ac_client.exe");

	std::cout << pID << std::endl;
	std::cout << std::hex << baseModule << std::endl;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);

	ReadProcessMemory(handle, (LPCVOID)(baseModule + BASE_MODULE_OFFSET), &localPlayerPtr, sizeof(localPlayerPtr), nullptr);

	std::cout << std::hex << localPlayerPtr << std::endl;

	while (true)
	{
		if (GetAsyncKeyState(VK_F1))
		{
			Teleport(localPlayerPtr, handle, true);
			Sleep(50);
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			Teleport(localPlayerPtr, handle, false);
			Sleep(50);
		};

	}

	return 0;
}