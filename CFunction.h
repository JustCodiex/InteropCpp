#pragma once
#include <cstdint>

enum class CallArgType {
	Integer,
	Double,
	Float,
	Pointer,
	Boolean
};

struct CallArg {
	CallArgType type;
	int iVal;
	float fVal;
	double dVal;
	void* val;
	bool bVal;
	CallArg() : CallArg(0){}
	CallArg(int32_t i) {
		this->type = CallArgType::Integer;
		this->fVal = 0;
		this->bVal = false;
		this->val = 0;
		this->dVal = 0;
		this->iVal = i;
	}
	CallArg(float f) {
		this->type = CallArgType::Float;
		this->fVal = f;
		this->bVal = false;
		this->val = 0;
		this->dVal = 0;
		this->iVal = 0;
	}
	CallArg(void* p) {
		this->type = CallArgType::Pointer;
		this->fVal = 0;
		this->bVal = false;
		this->val = p;
		this->iVal = 0;
		this->dVal = 0;
	}
	CallArg(bool b) {
		this->type = CallArgType::Boolean;
		this->fVal = 0;
		this->bVal = b;
		this->val = 0;
		this->iVal = 0;
		this->dVal = 0;
	}
};

struct CallArgs {
	int count;
	CallArg* args;
};

void Invoke(const void* source, const CallArgs args);
