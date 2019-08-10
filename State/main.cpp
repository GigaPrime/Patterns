#include "StateMachine.h"
#include "State.h"

using namespace std;

void main()
{
	IState* iState = new NoMoneyState(10);
}