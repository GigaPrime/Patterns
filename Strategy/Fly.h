#pragma once
#include <string>

using namespace  std;

class IFly
{
protected:
	bool isFlyable;
public:
	virtual string printFlyAbility() = 0;
	virtual ~IFly() = 0 {};

	void setIsFlyable(bool isFlyable) { this->isFlyable = isFlyable; }
	bool getIsFlyable() const { return isFlyable; }
};

class Flyable : public IFly
{
public:
	Flyable() { isFlyable = true; }
	string printFlyAbility() override { return "This duck can fly\n"; }
};

class NonFlyable : public IFly
{
public:
	NonFlyable() { isFlyable = false; }
	string printFlyAbility() override { return "This duck can't fly\n"; }
};