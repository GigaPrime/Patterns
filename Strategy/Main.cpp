#include <iostream>
#include "Duck.h"

using namespace  std;

void main()
{
	ITypeOfDuck * tDuck = new NaturalDuck;
	IFloat * iFloat = new Floating;
	IFly * iFly = new Flyable;
	IQuack * iQuack = new Mute;
	IEat * iEat = new EatFish;

	Duck * d = new Duck;
	d->setTypeOfDuck(tDuck);
	d->setIFloat(iFloat);
	d->setIFly(iFly);
	d->setIQuack(iQuack);

	cout << d->getITypeOfDuck()->printTypeOfDuck();
	cout << d->getIFloat()->printFloatAbility();
	cout << d->getIQuack()->quackAbility();

	Duck d2(tDuck, iFloat, iFly, iQuack, iEat);
	cout << d2.getITypeOfDuck()->printTypeOfDuck();
	cout << d2.getIsEating()->printEatAbility();

	system("Pause");
}