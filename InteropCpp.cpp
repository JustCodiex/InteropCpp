// InteropCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <functional>
#include <Windows.h>

void test_no_args() {
	std::cout << "Hello from test without args" << std::endl;
}

void __stdcall test_with_args(int v) {
	std::cout << "Hello from test wth 1 arg: " << v << std::endl;
}

void __stdcall test_with_many_args(int a, int b) {
	std::cout << "Hello from test wth 2 args: " << (a-b) << std::endl;
}

void runFunc() {

	auto addr = &test_with_many_args;

	std::cout << addr << std::endl;

	__asm {

		push 11
		push 5
		call [addr]

	};

}

void runFunc(int argc, int* args) {

	auto addr = &test_with_many_args;

	for (size_t i = 0; i < argc; i++) {
		int v = args[argc - 1 - i];
		__asm {
			push [v]
		};
	}

	__asm {
		call [addr]
	};

}

int main() {

	int args[2];
	args[0] = 11;
	args[1] = 5;
	runFunc(2, args);

	return 0;

}
