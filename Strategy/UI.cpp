#include "UI.h"
#include <iostream>

using namespace std;

void UserInterface::selectSettings() const
{
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
	duckSettings->push_back(tmp);
	
	if(natural == tmp)
	{
		// all natural ducks are made of meat able float and fly
		duckSettings->push_back(madeOfMeat);
		duckSettings->push_back(ableToFloat);
		duckSettings->push_back(ableToFly);
	
		cout << "Can the duck quack or can it squeak or is duck mute?\n";
		searchPattern1 = ableToQuack;
		searchPattern2 = ableToSquek;
		searchPattern3 = notAbleToQuack;
		do
		{
			getline(cin, input);
			tmp = isInputContains(input, searchPattern1, searchPattern2, searchPattern3);
		} while (incorrectInput == tmp);
		duckSettings->push_back(tmp);

		cout << "Does the duck eat fish or grass?\n";
		searchPattern1 = eatFish;
		searchPattern2 = eatGrass;
		do
		{
			getline(cin, input);
			tmp = isInputContains(input, searchPattern1, searchPattern2);
		} while (incorrectInput == tmp);
		duckSettings->push_back(tmp);
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
		duckSettings->push_back(tmp);
		if(madeOfStone == tmp)
		{
			duckSettings->push_back(notAbleToFloat);
			duckSettings->push_back(notAbleToFly);
			duckSettings->push_back(notAbleToQuack);
			duckSettings->push_back(eatNothing);
		}
		else if(madeOfWood == tmp)
		{
			duckSettings->push_back(ableToFloat);
			duckSettings->push_back(notAbleToFly);
			duckSettings->push_back(notAbleToQuack);
			duckSettings->push_back(eatNothing);
		}
		else if(madeOfRubber == tmp)
		{
			duckSettings->push_back(ableToFloat);
			duckSettings->push_back(notAbleToFly);
			duckSettings->push_back(ableToQuack);
			duckSettings->push_back(eatNothing);
		}
	}
	duckSettings->shrink_to_fit();
}

void UserInterface::changeSettings() const
{
	string input;
	string tmp;
	cout << "Want to make some changes to the Duck You've been already created?\n\n";
	do
	{
		getline(cin, input);
		tmp = isInputContains(input, "no", "yes");
	} while ("no" == tmp || "yes" == tmp);
	
	if ("no" == tmp)
		return;
	else
		selectSettings();
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

Duck * UserInterface::createDuck() const
{
	ITypeOfDuck * tDuck = nullptr;
	IFloat * iFloat = nullptr;
	IFly * iFly = nullptr;
	IQuack * iQuack = nullptr;
	IEat * iEat = nullptr;

	if(eatNothing == duckSettings->back())
		iEat = new EatNothing;
	else if(eatGrass == duckSettings->back())
		iEat = new EatGrass;
	else if(eatFish == duckSettings->back())
		iEat = new EatFish;
	customDuck->setIEat(iEat);
	duckSettings->pop_back();

	if (ableToQuack == duckSettings->back())
		iQuack = new Quackable;
	else if (ableToSquek == duckSettings->back())
		iQuack = new Squeakable;
	else if (notAbleToQuack == duckSettings->back())
		iQuack = new Mute;
	customDuck->setIQuack(iQuack);
	duckSettings->pop_back();

	if (ableToFly == duckSettings->back())
		iFly = new Flyable;
	else if (notAbleToFly == duckSettings->back())
		iFly = new NonFlyable;
	customDuck->setIFly(iFly);
	duckSettings->pop_back();

	if (ableToFloat == duckSettings->back())
		iFloat = new Floating;
	else if (notAbleToFloat == duckSettings->back())
		iFloat = new NonFloating;
	customDuck->setIFloat(iFloat);
	duckSettings->pop_back();

	if (madeOfMeat == duckSettings->back())
	{
		tDuck = new NaturalDuck;
		tDuck->setMaterial(madeOfMeat);
		tDuck->setWeight(5.0);
	}
	else
		tDuck = new ArtificialDuck;
	
	if(madeOfRubber == duckSettings->back())
	{
		tDuck->setMaterial(madeOfRubber);
		tDuck->setWeight(0.5);
	}
	else if(madeOfWood == duckSettings->back())
	{
		tDuck->setMaterial(madeOfWood);
		tDuck->setWeight(3.0);
	}
	else if(madeOfStone == duckSettings->back())
	{
		tDuck->setMaterial(madeOfStone);
		tDuck->setWeight(1.5);
	}

	customDuck->setTypeOfDuck(tDuck);
	customDuck->setIFloat(iFloat);
	customDuck->setIFly(iFly);
	customDuck->setIQuack(iQuack);
	customDuck->setIEat(iEat);

	cout << customDuck << endl;

	return customDuck;
}

void UserInterface::printDuck(Duck* duck)
{
	cout << duck->getITypeOfDuck();
	cout << duck->getIFloat();
	cout << duck->getIFly();
	cout << duck->getIsEating();
}
