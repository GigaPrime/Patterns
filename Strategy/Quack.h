#pragma once
#include <string>

using namespace  std;

class IQuack
{
protected:
	bool isQuackable;
public:
	virtual string quackAbility() = 0;
	virtual ~IQuack() = 0 {};

	void setIsQuackable(bool isQuackable) { this->isQuackable = isQuackable; }
	bool getIsQuackable() const { return isQuackable; }
};

class Quackable : public IQuack
{
public:
	Quackable() { isQuackable = true; }
	string quackAbility() override { return "This duck can quack\n"; }
};

class Squeakable : public IQuack
{
public:
	Squeakable() { isQuackable = true; }
	string quackAbility() override { return "This duck can squeak\n"; }
};

class Mute : public IQuack
{
public:
	Mute() { isQuackable = false; }
	string quackAbility() override { return "This duck is mute\n"; }
};
