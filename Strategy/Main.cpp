#include <iostream>
#include "UI.h"

using namespace  std;

void intro();

void main()
{
	intro();
	UserInterface * ui = new UserInterface;
	ui->printDuck(ui->createDuck(ui->selectSettings()));

	system("Pause");
}

void intro()
{
	string input;

	cout << "\n\n\t\t\tDUCK GENERATOR\n\n";
	cout << "\t\t      (c) Denis Styopkin\n\n";
	cout << "\tThis programm simulates \"Strategy\" GOF pattern.\n\n";
	cout << "\tWhile answering questions, user is allowed to write \n\tany text but usage of keywords (e.g. \"natural\" or \"stone\") \n\tis a must.\n\n";
	cout << "\tLatin (English) keyboard layout is the only one to be used.\n\n";

	cout << "\tAre You ready to go on? \n\t";
	getline(cin, input);
	system("cls");
	return;
}