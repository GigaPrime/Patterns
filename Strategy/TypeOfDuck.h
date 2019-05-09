#pragma once
#include <string>

using namespace std;

class ITypeOfDuck
{
protected:
	float weight;
	string material;
public:
	virtual string getTypeOfDuck() = 0;
	virtual ~ITypeOfDuck() = 0 {};

	void setWeight(float weight) { this->weight = weight; }
	void setMaterial(string material) { this->material = material; }

	double getWeight() const { return weight; }
	string getMaterial() const { return  material; }
};

class NaturalDuck : public ITypeOfDuck
{
public:
	NaturalDuck() {material = "meat"; }
	string getTypeOfDuck() override { return "This duck is natural and made of " + material + " and has weight of " + to_string(weight) + " kg\n"; }
};

class ArtificialDuck : public ITypeOfDuck
{
public:
	string getTypeOfDuck() override { return "This duck is artificial and made of " + material + " and has weight of " + to_string(weight) + " kg\n"; }
};