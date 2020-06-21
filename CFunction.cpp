#include "CFunction.h"

void Invoke(const void* source, const CallArgs args) {

	for (int i = 0; i < args.count; i++) {
		int k = args.count - 1 - i;
		switch (args.args[i].type) {
		case CallArgType::Float: {
			float f = args.args[k].fVal;
			__asm {
				push[f]
			}
			break;
		}
		case CallArgType::Integer: {
			int j = args.args[k].iVal;
			__asm {
				push[j]
			}
			break;
		}
		case CallArgType::Pointer: {
			void* p = args.args[k].val;
			__asm {
				push[p]
			}
			break;
		}
		default:
			break;
		}
	}

	__asm {
		call [source]
	}
	// result is stored in eax register https://en.wikibooks.org/wiki/X86_Disassembly/The_Stack
	// https://en.wikibooks.org/wiki/X86_Assembly/GAS_Syntax
	// https://stackoverflow.com/questions/8226540/use-int-randvoid-in-assembly
	// https://en.wikipedia.org/wiki/X86_calling_conventions
}
