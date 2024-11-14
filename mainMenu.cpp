#include <iostream>
using namespace std;

void mainMenu()
{
	int option;

	cout << "1) View Account Balance" << endl;
	cout << "2) Withdrawl" << endl;
	cout << "3) Deposit" << endl;
	cout << "4) Transfer Between Accounts" << endl;
	cout << "5) Leave" << endl;
	cin >> option;

	switch (option)
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		default:
			break;
}