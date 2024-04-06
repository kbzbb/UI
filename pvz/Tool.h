#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <memoryapi.h>
#include <rpcndr.h>
#include <vector>

namespace TOOL {
	class Tool {
	public:
		int pid = NULL;
		HANDLE handle = NULL;
		uintptr_t module = NULL;

		Tool(std::string name, std::string module_name) {
			take_pid(name);
			take_module(module_name);
		}

		void take_pid(std::string name);
		void take_module(std::string name);

		template<class T>
		T read(uintptr_t address) {
			T t;
			ReadProcessMemory(handle, reinterpret_cast<LPVOID>(address), &t, sizeof(T), nullptr);
			return t;
		}

		template<class T>
		void read_list(uintptr_t address, T* t, SIZE_T length) {
			ReadProcessMemory(handle, reinterpret_cast<LPVOID>(address), t, length * (sizeof(T)), nullptr);
		}

		template<class T>
		T read_multilevel(uintptr_t address, std::vector<uintptr_t> offset) {
			for (int i = 0; i < offset.size(); i++) {
				if (i + 1 == offset.size()) {
					return (read<T>(address + offset[i]));
				}
				else {
					address = read<T>(address + offset[i]);
				}
			}
		}

		template<class T>
		void write(uintptr_t address, T value) {
			WriteProcessMemory(handle, reinterpret_cast<LPVOID>(address), &value, sizeof(T), NULL);
		}

		template<class T>
		void write_multilevel(uintptr_t address, std::vector<uintptr_t> offset, T value) {
			for (int i = 0; i < offset.size(); i++) {
				if (i + 1 == offset.size()) {
					write<T>(address + offset[i], value);
				}
				else {
					address = read<T>(address + offset[i]);
				}
			}
		}

		void Ð´_×Ö½ÚÊý×é(uintptr_t address, std::vector <byte> byte) {
			for (int i = 0; i < byte.size(); i++) {
				WriteProcessMemory(handle, reinterpret_cast<LPVOID>(address), &byte[i], sizeof(byte), NULL);
				address++;
			}
		}
	};
}