#pragma once
#include "State.h"

#include <iostream>
using namespace std;

class StateMachine
{
private:
	enum STATES
	{
		SOLD_OUT = 0,
		NO_MONEY = 1,
		HAS_MONEY = 2,
		SOLD = 3
	};

	int state = SOLD_OUT;
	int count = 0;

public:
	void insertMoney();
	void ejectMoney();
	void getGoods();
	void supply();
	void setState(int);
	int getState();

	StateMachine(int count);
};