#include <iostream>
using namespace std;

double deposit(double& balance)
{
	double amount;
	char confirm;

	cout << "How much would you like to deposit?" << endl;
	
	do														// input validation
	{
		cin >> amount;

		if (amount < 0 || amount > 1000)
			cout << "Error has occured. Please enter valid number." << endl;

	} while (amount < 0 || amount > 1000);

	cout << "Confirm? (Y/N)" << endl;						// confirming action
	cin >> confirm;

	if (confirm == 'y' || confirm == 'Y')
		balance += amount;
	else
	{
		cout << "Deposit cancelled." << endl;
		// mainMenu()										// return to main menu
	}

	return balance;
}

int main()
{
	double balance = 1000;
	deposit(balance);

	cout << balance;
}