#include <iostream>
using namespace std;

double withdrawl(double& balance)
{
	int choice;
	char confirm;
	bool invalid;		// flag

	cout << "How much would you like to withdrawl?" << endl;
	cout << "1) $20" << endl;
	cout << "2) $40" << endl;
	cout << "3) $60" << endl;
	cout << "4) $80" << endl;
	cout << "5) $100" << endl;
	cout << "6) Back" << endl;

	do
	{
		invalid = false;									   // resets flag

		cin >> choice;

		switch (choice)
		{
		case 1: choice = 20;
			break;
		case 2: choice = 40;
			break;
		case 3: choice = 60;
			break;
		case 4: choice = 80;
			break;
		case 5: choice = 100;
			break;
		case 6: // mainMenu();
			break;
		default:
			cout << "Please enter valid choice." << endl;		// keeps looping until valid choice is entered
			invalid = true;
			break;
		}

		cout << "Confirm? (Y/N) ";								// confirming action
		cin >> confirm;

		if (confirm == 'y' || confirm == 'Y')
			balance -= choice;
		else
		{
			cout << "Withdrawl cancelled." << endl;
			// mainMenu();										// back to main menu 
		}

	} while (invalid);

	return balance;
}

int main()
{
	double balance = 1000;
	withdrawl(balance);

	cout << balance;
}