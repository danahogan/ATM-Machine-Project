#include <iostream>
#include <iomanip>
using namespace std;

double transfer(double& checking, double& savings)
{
	cout << setprecision(2) << fixed;
	int choice;
	double amount;
	bool invalid;
	char confirm;

	double check = 0;

	cout << "Choose account to transfer from" << endl;
	cout << "1) Checking" << endl;
	cout << "2) Savings" << endl;
	cout << "3) Back" << endl;
	
	do
	{
		invalid = false;
		cin >> choice;

		switch (choice)
		{
		case 1: check = checking;
			break;
		case 2: check = savings;
			break;
		case 3: // mainMenu()										// return to main menu
			break;
		default:
			cout << "Please enter valid option." << endl;			// keeps going until valid option is selected
			invalid = true;
			continue;
		}
	} while (invalid);

	// validating amount
	cout << "How much are you going to transfer? ";	
	do
	{
		invalid = true;
		cin >> amount;

		if (amount < 0 || amount > 2000)
			cout << "Error has occured. Please enter valid number." << endl;
		else if (amount > check)
			cout << "Insufficient funds. Please try again." << endl;
		else
			invalid = false;

	} while (invalid);

	// confirming choice
	cout << "Confirm transfering $" << amount << "? (Y/N) ";
	cin >> confirm;

	if (confirm == 'n' || confirm == 'N')
	{
		cout << "Transfer cancelled." << endl;
		// mainMenu();
	}
	else
	{
		if (choice == 1)
		{
			checking -= amount;
			savings += amount;

			cout << "$" << amount << " was transfered from checking into savings." << endl;
			// mainMenu()
		}
		else if (choice == 2)
		{
			savings -= amount;
			checking += amount;

			cout << "$" << amount << " was tranfered from savings into checking." << endl;
			// mainMenu()
		}
	}

	return checking, savings;
}

int main()
{
	double checking = 100;
	double savings = 200;

	transfer(checking, savings);

	return 0;
}