#include "StateMachine.h"

void StateMachine::insertMoney()
{
	if (state == SOLD_OUT)
	{
		cout << "Sorry, no more goods" << endl;
	}
	else if (state == NO_MONEY)
	{
		cout << "Insert money, please!" << endl;
	}
	else if (state == HAS_MONEY)
	{
		state = HAS_MONEY;
		cout << "You've inserted money" << endl;
	}
	else if (state == SOLD)
	{
		cout << "Here are your goods" << endl;
	}
}

void StateMachine::ejectMoney()
{
	if (state == HAS_MONEY)
	{
		state = NO_MONEY;
		cout << "Money returned" << endl;
	}
	else if (state == NO_MONEY)
	{
		cout << "No money were inserted. Nothing to return" << endl;
	}
	else if (state == SOLD_OUT)
	{
		cout << "No money were inserted. Nothing to return" << endl;
	}
	else if (state == SOLD)
	{
		cout << "Goods are already given" << endl;
	}
}

void StateMachine::getGoods()
{
	if (state == SOLD)
	{
		cout << "Goods are already supplied" << endl;
	}
	else if (state == NO_MONEY)
	{
		cout << "No money given. Unable to supply goods" << endl;
	}
	else if (state == HAS_MONEY)
	{
		cout << "Enjoy your goods" << endl;
		state = SOLD;
		supply();
	}
	else if (state == SOLD_OUT)
	{
		cout << "No goods to supply" << endl;
	}
}

void StateMachine::supply()
{
	if (state == SOLD)
	{
		cout << "Supplying... Please, be patient" << endl;
		count--;
		if (count == 0)
		{
			cout << "Out of goods" << endl;
			state = SOLD_OUT;
		}
		else if (count > 0)
		{
			state = NO_MONEY;
		}		
	}
	else if (state == NO_MONEY)
	{
		cout << "No money given. Unable to supply goods" << endl;
	}
	else if (state == HAS_MONEY)
	{
		cout << "Enjoy your goods" << endl;
		state = SOLD;
		supply();
	}
	else if (state == SOLD_OUT)
	{
		cout << "No goods to supply" << endl;
	}
}

void StateMachine::setState(int state)
{
	this->state = state;
}

int StateMachine::getState()
{
	return state;
}

StateMachine::StateMachine(int cout)
{
	this->count = count;
	if (count > 0)
	{
		state = NO_MONEY;
	}
}
