#pragma once
#include "StateMachine.h"

class IState
{
protected:
	enum STATES
	{
		SOLD_OUT = 0,
		NO_MONEY = 1,
		HAS_MONEY = 2,
		SOLD = 3
	};

public:
	virtual void insertMoney() = 0;
	virtual void ejectMoney() = 0;
	virtual void getGoods() = 0;
	virtual void supply() = 0;
};

class SoldOutState : public IState
{
public:
	void insertMoney();
	void ejectMoney();
	void getGoods();
	void supply();
};

class SoldState : public IState
{
public:
	void insertMoney();
	void ejectMoney();
	void getGoods();
	void supply();
};

class NoMoneyState : public IState
{
private:
	StateMachine stateMachine;
public:
	void insertMoney();
	void ejectMoney();
	void getGoods();
	void supply();

	NoMoneyState(StateMachine stateMachine);
};

class HasMoneyState : public IState
{
private:
	StateMachine stateMachine;
public:
	void insertMoney();
	void ejectMoney();
	void getGoods();
	void supply();

	HasMoneyState(StateMachine stateMachine);
};


	//SOLD_OUT = 0,
	//NO_MONEY = 1,
	//HAS_MONEY = 2,
	//SOLD = 3