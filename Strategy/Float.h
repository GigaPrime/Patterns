#pragma once
#include <string>
using namespace  std;

class IFloat
{
protected:
	bool isFloating;
public:
	virtual string getFloatAbility() = 0;
	virtual ~IFloat() = 0 {};

	void setIsFloating(bool isFloating) { this->isFloating = isFloating; }
	bool getIsFloating() const { return isFloating; }
};

class Floating : public IFloat
{
public:
	Floating() { isFloating = true; }
	string getFloatAbility() override { return "This duck can float\n"; }
};

class NonFloating : public IFloat
{
public:
	NonFloating() { isFloating = false; }
	string getFloatAbility() override { return "This duck can't float\n"; }
};