#include "State.h"

void NoMoneyState::insertMoney()
{
	cout << "Money inserted" << endl;
	stateMachine.setState(HAS_MONEY);
}

void NoMoneyState::ejectMoney()
{
	cout << "No money given. Nothing to return" << endl;
}

void NoMoneyState::getGoods()
{
	cout << "No money given. Unable to supply" << endl;
}

void NoMoneyState::supply()
{
	cout << "No money given. Unable to supply" << endl;
}

NoMoneyState::NoMoneyState(StateMachine stateMachine)
{
	this->stateMachine = stateMachine;
}

void HasMoneyState::insertMoney()
{
	cout << "No more money needed" << endl;
}

void HasMoneyState::ejectMoney()
{
	cout << "Returning money" << endl;
	stateMachine.setState(NO_MONEY);
}

HasMoneyState::HasMoneyState(StateMachine stateMachine)
{
	this->stateMachine = stateMachine;
}
