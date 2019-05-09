#pragma once
#include "Duck.h"
#include <vector>

class UserInterface
{
private:
	string natural = "natural";
	string artificial = "artificial";
	string madeOfMeat = "meat";
	string madeOfStone = "stone";
	string madeOfWood = "wood";
	string madeOfRubber = "rubber";
	string ableToFly = "fly";
	string notAbleToFly = "noFly";
	string ableToFloat = "float";
	string notAbleToFloat = "noFloat";
	string ableToQuack = "quack";
	string ableToSquek = "squeak";
	string notAbleToQuack = "mute";
	string eatGrass = "grass";
	string eatFish = "fish";
	string eatNothing = "noEat";
	string incorrectInput = "error";

	Duck * customDuck = new Duck;

	string isInputContains (string, string, string) const;
	string isInputContains (string, string, string, string) const;	
public:
	
	~UserInterface() { delete customDuck; }

	vector<string> selectSettings() const;
	Duck * createDuck(vector<string> settings) const;
	static void printDuck(Duck * duck);
};
