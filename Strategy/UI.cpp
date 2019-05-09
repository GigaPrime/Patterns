#include "UI.h"
#include <iostream>

using namespace std;

vector<string> UserInterface::selectSettings() const
{
	vector<string> duckSettings;
	string input;
	string searchPattern1 = "";
	string searchPattern2 = "";
	string searchPattern3 = "";
	string tmp;

	cout << "Your duck is natural or artificial?\n";
	searchPattern1 = natural;
	searchPattern2 = artificial;
	do
	{
		getline(cin, input);
		tmp = isInputContains(input, searchPattern1, searchPattern2);
	} while (incorrectInput == tmp);
	duckSettings.push_back(tmp);
	
	if(natural == tmp)
	{
		// all natural ducks are made of meat able float and fly
		duckSettings.push_back(madeOfMeat);
		duckSettings.push_back(ableToFloat);
		duckSettings.push_back(ableToFly);
	
		cout << "Can the duck quack or can it squeak or is duck mute?\n";
		searchPattern1 = ableToQuack;
		searchPattern2 = ableToSquek;
		searchPattern3 = notAbleToQuack;
		do
		{
			getline(cin, input);
			tmp = isInputContains(input, searchPattern1, searchPattern2, searchPattern3);
		} while (incorrectInput == tmp);
		duckSettings.push_back(tmp);

		cout << "Does the duck eat fish or grass?\n";
		searchPattern1 = eatFish;
		searchPattern2 = eatGrass;
		do
		{
			getline(cin, input);
			tmp = isInputContains(input, searchPattern1, searchPattern2);
		} while (incorrectInput == tmp);
		duckSettings.push_back(tmp);
	}
	else if (artificial == tmp)
	{
		//all artificial ducks don't eat and fly, but some of them can float (decoys) and quack (toys)
		cout << "What material the duck is made of (stone, wood, rubber)?\n";
		searchPattern1 = madeOfStone;
		searchPattern2 = madeOfWood;
		searchPattern3 = madeOfRubber;
		do
		{
			getline(cin, input);
			tmp = isInputContains(input, searchPattern1, searchPattern2, searchPattern3);
		} while (incorrectInput == tmp);
		duckSettings.push_back(tmp);
		if(madeOfStone == tmp)
		{
			duckSettings.push_back(notAbleToFloat);
			duckSettings.push_back(notAbleToFly);
			duckSettings.push_back(notAbleToQuack);
			duckSettings.push_back(eatNothing);
		}
		else if(madeOfWood == tmp)
		{
			duckSettings.push_back(ableToFloat);
			duckSettings.push_back(notAbleToFly);
			duckSettings.push_back(notAbleToQuack);
			duckSettings.push_back(eatNothing);
		}
		else if(madeOfRubber == tmp)
		{
			duckSettings.push_back(ableToFloat);
			duckSettings.push_back(notAbleToFly);
			duckSettings.push_back(ableToQuack);
			duckSettings.push_back(eatNothing);
		}
	}
	duckSettings.shrink_to_fit();
	return duckSettings;
}

string UserInterface::isInputContains (string input, string searchPattern1, string searchPattern2) const
{
	int pos = -1;

	pos = input.find(searchPattern1);

	if ((pos = input.find(searchPattern1)) != -1)
		return searchPattern1;
	if ((pos = input.find(searchPattern2)) != -1)
		return searchPattern2;
	return incorrectInput;
}

string UserInterface::isInputContains(string input, string searchPattern1, string searchPattern2, string searchPattern3) const
{
	int pos = -1;
	if ((pos = input.find(searchPattern1)) != -1)
		return searchPattern1;
	if ((pos = input.find(searchPattern2)) != -1)
		return searchPattern2;
	if ((pos = input.find(searchPattern3)) != -1)
		return searchPattern3;
	return incorrectInput;
}

Duck * UserInterface::createDuck(vector<string> settings) const
{
	ITypeOfDuck * tDuck = nullptr;
	IFloat * iFloat = nullptr;
	IFly * iFly = nullptr;
	IQuack * iQuack = nullptr;
	IEat * iEat = nullptr;
	Duck * finalDuck = new Duck;

	if(eatNothing == settings.back())
		iEat = new EatNothing;
	else if(eatGrass == settings.back())
		iEat = new EatGrass;
	else if(eatFish == settings.back())
		iEat = new EatFish;
	customDuck->setIEat(iEat);
	settings.pop_back();

	if (ableToQuack == settings.back())
		iQuack = new Quackable;
	else if (ableToSquek == settings.back())
		iQuack = new Squeakable;
	else if (notAbleToQuack == settings.back())
		iQuack = new Mute;
	customDuck->setIQuack(iQuack);
	settings.pop_back();

	if (ableToFly == settings.back())
		iFly = new Flyable;
	else if (notAbleToFly == settings.back())
		iFly = new NonFlyable;
	customDuck->setIFly(iFly);
	settings.pop_back();

	if (ableToFloat == settings.back())
		iFloat = new Floating;
	else if (notAbleToFloat == settings.back())
		iFloat = new NonFloating;
	customDuck->setIFloat(iFloat);
	settings.pop_back();

	if (madeOfMeat == settings.back())
	{
		tDuck = new NaturalDuck;
		tDuck->setMaterial(madeOfMeat);
		tDuck->setWeight(5.0);
	}
	else
		tDuck = new ArtificialDuck;
	
	if(madeOfRubber == settings.back())
	{
		tDuck->setMaterial(madeOfRubber);
		tDuck->setWeight(0.5);
	}
	else if(madeOfWood == settings.back())
	{
		tDuck->setMaterial(madeOfWood);
		tDuck->setWeight(3.0);
	}
	else if(madeOfStone == settings.back())
	{
		tDuck->setMaterial(madeOfStone);
		tDuck->setWeight(1.5);
	}

	finalDuck->setTypeOfDuck(tDuck);
	finalDuck->setIFloat(iFloat);
	finalDuck->setIFly(iFly);
	finalDuck->setIQuack(iQuack);
	finalDuck->setIEat(iEat);

	return finalDuck;
}

void UserInterface::printDuck(Duck* duck)
{
	cout << duck->getITypeOfDuck()->printTypeOfDuck();
	cout << duck->getIFloat()->printFloatAbility();
	cout << duck->getIFly()->printFlyAbility();
	cout << duck->getIsEating()->printEatAbility();
}
