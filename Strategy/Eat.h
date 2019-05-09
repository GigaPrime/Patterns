#pragma once
#include <string>

using namespace std;

class IEat
{
protected:
	bool isEating;
public:
	virtual string getEatAbility() = 0;
	virtual ~IEat() = 0 {};

	void setIsEating(bool isEating) { this->isEating = isEating; }
	bool getIsEating() const { return isEating; }
};

class EatGrass : public IEat
{
public:
	EatGrass() { isEating = true; }
	string getEatAbility() override { return "This duck eats grass\n"; }
};

class EatFish : public IEat
{
public:
	EatFish() { isEating = true; }
	string getEatAbility() override { return "This duck eats fish\n"; }
};

class EatNothing : public IEat
{
public:
	EatNothing() { isEating = false; }
	string getEatAbility() override { return "This duck doesn't eat\n"; }
};