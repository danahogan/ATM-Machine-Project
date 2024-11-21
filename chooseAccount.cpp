#include <iostream>
using namespace std;

double chooseAccount(double& checking, double& savings)
{
	int account;

	cout << "Which account are you choosing from today?" << endl;
	cout << "1) Checking" << endl;
	cout << "2) Savings" << endl;
	cout << "3) Back" << endl;
	
	do{
		cin >> account;

		switch (account)
		{
		case 1: return checking;
			break;
		case 2: return savings;
			break;
		case 3: //mainMenu();
			break;
		default: cout << "Please select an option." << endl;
				break;
		}
	} while (account != 3);
}