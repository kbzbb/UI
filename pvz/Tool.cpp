#include "Tool.h"

void TOOL::Tool::take_pid(std::string name)
{
	HANDLE handle2 = NULL;
	PROCESSENTRY32 list;
	list.dwSize = sizeof(list);
	handle2 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	for (Process32First(handle2, &list); Process32Next(handle2, &list);) {
		if (list.szExeFile == name) {
			pid = list.th32ProcessID;
			handle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
			break;
		}
	}
}

void TOOL::Tool::take_module(std::string name)
{
	HANDLE handle2 = NULL;
	MODULEENTRY32  list;
	list.dwSize = sizeof(list);
	handle2 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32 | TH32CS_SNAPMODULE, pid);
	for (Module32First(handle2, &list); Module32Next(handle2, &list);) {
		if (name.compare(list.szModule)==0) {
			module = (uintptr_t)list.modBaseAddr;
			break;
		}
	}
}
