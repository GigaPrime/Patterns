#pragma once
#include  "TypeOfDuck.h"
#include "Float.h"
#include "Quack.h"
#include "Fly.h"

class Duck
{
protected:
	ITypeOfDuck * typeOfDuck;
	IFloat * iFloat;
	IFly * iFly;
	IQuack * iQuack;
public:
	
	void setTypeOfDuck(ITypeOfDuck * typeOfDuck) { this->typeOfDuck = typeOfDuck; }
	void setIFloat(IFloat * iFloat) { this->iFloat = iFloat; }
	void setIFly(IFly * iFly) { this->iFly = iFly; }
	void setIQuack(IQuack * iQuack) { this->iQuack = iQuack; }

	ITypeOfDuck * getITypeOfDuck() const { return typeOfDuck; }
	IFloat * getIFloat() const { return iFloat; }
	IFly * getIFly() const { return iFly; }
	IQuack* getIQuack() const { return iQuack; }

	Duck() { typeOfDuck, iFloat, iFly, iQuack; };
	Duck(ITypeOfDuck * tD, IFloat * iF, IFly * iFl, IQuack * iQ) { typeOfDuck = tD; iFloat = iF; iFly = iFl; iQuack = iQ; }
	~Duck() { delete typeOfDuck; delete iFloat; delete iFly; delete iQuack; }
};