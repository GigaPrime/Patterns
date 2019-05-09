#pragma once
#include "TypeOfDuck.h"
#include "Float.h"
#include "Quack.h"
#include "Fly.h"
#include "Eat.h"

class Duck
{
protected:
	ITypeOfDuck * typeOfDuck = nullptr;
	IFloat * iFloat = nullptr;
	IFly * iFly = nullptr;
	IQuack * iQuack = nullptr;
	IEat * iEat = nullptr;
public:
	void setTypeOfDuck(ITypeOfDuck * typeOfDuck) { this->typeOfDuck = typeOfDuck; }
	void setIFloat(IFloat * iFloat) { this->iFloat = iFloat; }
	void setIFly(IFly * iFly) { this->iFly = iFly; }
	void setIQuack(IQuack * iQuack) { this->iQuack = iQuack; }
	void setIEat(IEat * iEat) { this->iEat = iEat; }

	ITypeOfDuck * getITypeOfDuck() const { return typeOfDuck; }
	IFloat * getIFloat() const { return iFloat; }
	IFly * getIFly() const { return iFly; }
	IQuack * getIQuack() const { return iQuack; }
	IEat * getIsEating() const { return iEat; }

	Duck() { typeOfDuck, iFloat, iFly, iQuack; iEat; };
	Duck(ITypeOfDuck * tD, IFloat * iF, IFly * iFl, IQuack * iQ, IEat * iE) { typeOfDuck = tD; iFloat = iF; iFly = iFl; iQuack = iQ; iEat = iE; }
	~Duck() { delete typeOfDuck; delete iFloat; delete iFly; delete iQuack; }
};
