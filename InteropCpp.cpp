// InteropCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "CFunction.h"

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

void __stdcall test(int a, int b) {
	std::cout << "Got integer: " << a << std::endl;
	std::cout << "Got float: " << b << std::endl;
}

class ex {
public:
	void stuff() {
		std::cout << "Hello from stuff #" << (this) << std::endl;
	}
};

void __stdcall objtest(ex* e) {
	e->stuff();
}

int __stdcall t1() {
	return 1;
}

void __stdcall t2() {

}

int main() {

	/*CallArgs args;
	args.args = new CallArg[2];
	args.args[0] = CallArg(1);
	args.args[1] = CallArg(-3);
	args.count = 2;

	Invoke(test, args);

	delete[] args.args;

	args.count = 1;
	args.args = new CallArg[1];
	args.args[0] = CallArg(new ex());

	Invoke(objtest, args);*/

	auto t1a = &t1;
	auto t2a = &t2;

	int rt1 = 26;
	int rt2 = 26;

	__asm { // fetch return value
		call [t1a]
		mov [rt1], eax
	}

	__asm { // void ==> ignore return value
		call[t2a]
		xor eax, eax
	}

	std::cout << rt1 << std::endl;
	std::cout << rt2 << std::endl;

	return 0;

}
