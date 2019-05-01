#pragma once
#include <string>

using namespace std;

class ITypeOfDuck
{
protected:
	double weight;
	string material;
public:
	virtual string printTypeOfDuck() = 0;
	virtual ~ITypeOfDuck() = 0 {};

	void setWeight(double weight) { this->weight = weight; }
	void setMaterial(string material) { this->material = material; }

	double getWeight() const { return weight; }
	string getMaterial() const { return  material; }
};

class NaturalDuck : public ITypeOfDuck
{
public:
	NaturalDuck() {material = "meat"; }
	string printTypeOfDuck() override { return "This duck is natural and made of " + material + "\n"; }
};

class ArtificialDuck : public ITypeOfDuck
{
public:
	string printTypeOfDuck() override { return "This duck is asrtificial and made of " + material + "\n"; }
};