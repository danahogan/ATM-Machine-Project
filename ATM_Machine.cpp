//This is the working ATM code file

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//Function Prototypes
void loadUserData(string [], string [], string [], string [], int [], int[], const int);
void getAccountBalances(double [], double[], const int);
void createNewBalance(string [], string[], double [], double [], const int);
bool displayLogin(int [], string[], string[], int, string [], int&);
int userIDValidation(int [], const int);
bool userPasswordValidation(string [], const int, int);
void mainMenu(double [], double[], int, const int);
void displayAccountBalances(double [], double [], int, const int);
void withdrawl(double [], double [], int, const int);
void deposit(double [], double [], int, const int);
void transfer(double [], double [], int, const int);
char chooseAccount(double [], double [], int, const int);
void reciept(string [], string [], int [], double [], double [], int);


int main()       //     Output updated txt file reflecting new balances. (format it!)
{
    const int SIZE = 5; //Constant amount of users.
    string firstName[SIZE], lastName[SIZE], password[SIZE], phoneNumber[SIZE]; //Arrays for name and password.
    int userID[SIZE], pin[SIZE], user; //Arrays for ID and PIN numbers.
    double savingsBalance[SIZE], checkingsBalance[SIZE]; //Array for account balances.

      /****************************************
     * Loading User Data to System
     ****************************************/

    loadUserData(firstName, lastName, password, phoneNumber, userID, pin, SIZE);
    getAccountBalances(savingsBalance, checkingsBalance, SIZE);

    bool valid = true;
    valid = displayLogin(userID, firstName, lastName, SIZE, password, user); //Validates user login credentials
    if(valid == true)
    {
        mainMenu(savingsBalance, checkingsBalance, user, SIZE);
        cout << "\nPlease take your receipt\n" << endl; //See "receiptATM.txt" for receipt output.
        reciept(firstName, lastName, userID, checkingsBalance, savingsBalance, user);
        createNewBalance(firstName, lastName, savingsBalance, checkingsBalance, SIZE); //See "accountBalances.txt" for updated balances after transactions. 
        exit(1);

    }
    else
    {
        cout << "Goodbye!";
        exit(1);
    }
    return 0;
}

    /****************************************
     * Function to get user data
     ****************************************/

void loadUserData(string firstName[], string lastName[], string password[], string phoneNumber[], int userID[], int pin[], const int SIZE)
{
    string menu; //Misc string to hold first two lines from text file
    int i; //counter variable
    
    //Call "userInfo" text file to read
    ifstream inputFile;
    inputFile.open("userInfo.txt");

    //Store first two lines of text as menu variable.
    for(i=0; i<11; i++)
    {
        inputFile >> menu;
    }

    //Starting at 3rd line, store the first row information as the corresponding variable array element. 
    for(i=0; i<SIZE; i++)
    {
        inputFile >> firstName[i];
        inputFile >> lastName[i];
        inputFile >> userID[i];
        inputFile >> password[i];
        inputFile >> pin[i];
        inputFile >> phoneNumber[i];
    }
    inputFile.close();
}
    
    /****************************************
     * Function to get account balances
     ****************************************/

void getAccountBalances(double savingsBalance[], double checkingsBalance[], const int SIZE)
{
    ifstream inputFile;
    string menu; //Stores first two lines of txt file
    int i; //Counter variable;
    string savingsBalanceString[SIZE], checkingsBalanceString[SIZE]; //Placeholders for string data.

    //Open and read account balances to each user.
    inputFile.open("accountBalance.txt");

    for(i=0; i<12; i++)
    {
        inputFile >> menu;
    }

    for(i=0; i<SIZE; i++)
    {
        inputFile >> savingsBalanceString[i];
        inputFile >> menu;
        inputFile >> checkingsBalanceString[i];
        inputFile >> menu;
        inputFile >> menu;
        inputFile >> menu;

        savingsBalance[i] = stof(savingsBalanceString[i]); //Converts to double values
        checkingsBalance[i] = stof(checkingsBalanceString[i]); //Converts to double values
    }

    inputFile.close();
}

    /****************************************
     * Function to display homepage
     ****************************************/

bool displayLogin(int userID[], string firstName[], string lastName[], int SIZE, string password[], int &user)
{
    /*************************************************
     * Display Login Page and Validate Credentials
     *************************************************/

    int userPin;
    bool valid;

    cout << "      Welcome!\n";
    cout << "\nEnter your User ID: ";
    
    user = userIDValidation(userID, SIZE);
    
    cout << "\nEnter your Password: ";

    valid = userPasswordValidation(password, SIZE, user);

    if(valid == true)
    cout << "Hello, " << firstName[user] << " " << lastName[user] << "!\n";
    
    return valid;


}

int userIDValidation(int userID[], const int SIZE)
{
    int userIDNum, element;
    bool valid; 

    do
    {
        valid = false;
        cin >> userIDNum;

        if(userIDNum > 123455 || userIDNum < 123451)
            cout << "Invalid ID, please try again: ";
        else
            valid = true;
    }while (valid == false);

    //Convert User ID to its element equivalent

    for(int i=0; i<SIZE; i++)
    {
        if(userIDNum == userID[i])
            userIDNum = i;
    }
    
    return userIDNum; //Returns which element of the array we have just used.
}

bool userPasswordValidation(string password[], const int SIZE, int element)
{
        string passwordInput;
        bool valid = true;
        int attempt = 0;
    do
    {
    valid = false;
    cin >> passwordInput;

        if(password[element] == passwordInput) //User input and password on file do not match.
        {
            valid = true;
            break;
        }
        else
        { 
            cout << "Incorrect password, please try again: ";
            attempt++;

            if(attempt==3) //User allowed 3 attempts until locked out
            {
                cout << "\nYou have exceeded the amount of login attempts, \n";
                cout << "please call our office at (800)123-4567 to have \n";
                cout << "your account reset.\n\n";
                valid = false;
                break; //Break after 3 tries regardless and exit out of program.
            }
        }
    }
    while(valid == false);

    cout << endl;

    return valid;  
}
    /**************************************************
     * Function displays menu once inside ATM account
     **************************************************/

void mainMenu(double savingsBalance[], double checkingsBalance[], int user, const int SIZE)
{
	int option;
    char exitChoice;
   
    cout << " ______________________ \n";
    cout << "|                      |\n";
    cout << "|     Account Menu     |\n";
    cout << "|______________________|\n";
	cout << "\n1) View Account Balance" << endl;
	cout << "2) Withdraw" << endl;
	cout << "3) Deposit" << endl;
	cout << "4) Transfer Between Accounts" << endl;
	cout << "5) Leave" << endl;
	cin >> option;
    cout << endl;


	switch (option)
	{	case 1: displayAccountBalances(savingsBalance, checkingsBalance, user, SIZE);
            break;
		case 2: withdrawl(savingsBalance, checkingsBalance, user, SIZE);
            break;
		case 3: deposit(savingsBalance, checkingsBalance, user, SIZE);
            break;
		case 4: transfer(savingsBalance, checkingsBalance, user, SIZE);
            break;
		case 5: {
                    cout << "Are you sure you want to exit? (Y/N) ";
                    cin >> exitChoice;

                    if(exitChoice == 'Y' || exitChoice == 'y')
                        break;
                    
                    else
                    mainMenu(savingsBalance, checkingsBalance, user, SIZE);
                }
            break;
		default: cout << "Please select a valid option";
			break;
    }
}


void withdrawl(double savingsBalance[], double checkingsBalance[], int user, const int SIZE)
{
	int choice;
	char confirm, accountPicked;
	bool invalid;		// flag

    accountPicked = chooseAccount(savingsBalance, checkingsBalance, user, SIZE);

    if(accountPicked == 'C')
    {
	    cout << "How much would you like to withdraw?" << endl;
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
	        case 6: mainMenu(savingsBalance, checkingsBalance, user, SIZE);
	    	    break;
	        default:
	    	cout << "Please enter valid choice." << endl;		// keeps looping until valid choice is entered
	    	invalid = true;
		    break;
		    }

		    cout << "Confirm? (Y/N) ";								// confirming action
		    cin >> confirm;

		    if (confirm == 'y' || confirm == 'Y')
		    {
                checkingsBalance[user] -= choice;
                mainMenu(savingsBalance, checkingsBalance, user, SIZE);
            }
		    else
		    {
			    cout << "Withdrawal cancelled." << endl;
			    mainMenu(savingsBalance, checkingsBalance, user, SIZE);										// back to main menu 
		    }
	    } while (invalid);
    }

    if(accountPicked == 'S')
    {
        cout << "How much would you like to withdraw?" << endl;
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
	        case 6: mainMenu(savingsBalance, checkingsBalance, user, SIZE);
	    	    break;
	        default:
	    	cout << "Please enter valid choice." << endl;		// keeps looping until valid choice is entered
	    	invalid = true;
		    break;
		    }

		    cout << "Confirm? (Y/N) ";								// confirming action
		    cin >> confirm;

		    if (confirm == 'y' || confirm == 'Y')
		    {
                savingsBalance[user] -= choice;
                mainMenu(savingsBalance, checkingsBalance, user, SIZE);
            }
		    else
		    {
			    cout << "Withdrawal cancelled." << endl;
			    mainMenu(savingsBalance, checkingsBalance, user, SIZE);										// back to main menu 
		    }
	    } while (invalid);
    }
}

void deposit(double savingsBalance[], double checkingsBalance [], int user, const int SIZE)
{
	double amount;
	char confirm, accountPicked;
    double amountAccountPick;

    accountPicked = chooseAccount(savingsBalance, checkingsBalance, user, SIZE);

    if(accountPicked == 'C')
    {
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
	    {	checkingsBalance[user] += amount;
            cout << "Your deposit of $" << amount << " has been made.\n";
            mainMenu(savingsBalance, checkingsBalance, user, SIZE);
        }
	    else
	    {
		    cout << "Deposit cancelled." << endl;
            mainMenu(savingsBalance, checkingsBalance, user, SIZE);
	    }

    }

    if(accountPicked == 'S')
    {
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
	    {	checkingsBalance[user] += amount;
            cout << "Your deposit of $" << amount << " has been made.\n";
            mainMenu(savingsBalance, checkingsBalance, user, SIZE);
        }
	    else
	    {
		    cout << "Deposit cancelled." << endl;
            mainMenu(savingsBalance, checkingsBalance, user, SIZE);
	    }
    }
}

void transfer(double savingsBalance[], double checkingsBalance[], int user, const int SIZE)
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
		case 1: check = checkingsBalance[user];
			break;
		case 2: check = savingsBalance[user];
			break;
		case 3: {
                    mainMenu(savingsBalance, checkingsBalance, user, SIZE);
                    exit(1);
                }   
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
		mainMenu(savingsBalance, checkingsBalance, user, SIZE);
	}
	else
	{
		if (choice == 1)
		{
			checkingsBalance[user] -= amount;
			savingsBalance[user] += amount;

			cout << "$" << amount << " was transfered from checking into savings." << endl;
			mainMenu(savingsBalance, checkingsBalance, user, SIZE);
		}
		else if (choice == 2)
		{
			savingsBalance[user] -= amount;
			checkingsBalance[user] += amount;

			cout << "$" << amount << " was tranfered from savings into checking." << endl;
			mainMenu(savingsBalance, checkingsBalance, user, SIZE);
		}
	}
}

char chooseAccount(double savingsBalance[], double checkingsBalance[], int user, const int SIZE)
{
	int account;
    char accountPicked;

	cout << "Which account are you choosing from today?" << endl;
	cout << "1) Checking" << endl;
	cout << "2) Savings" << endl;
	cout << "3) Back" << endl;
	
		cin >> account;

		switch (account)
		{
		case 1: accountPicked = 'C';
			break;
		case 2: accountPicked = 'S';
			break;
		case 3: mainMenu(savingsBalance, checkingsBalance, user, SIZE);
			break;
		default: cout << "Please select an option." << endl;
			break;
        }

    return accountPicked;
}

void createNewBalance(string firstName[], string lastName[], double savingsBalance[], double checkingsBalance[], const int SIZE)
{
    ofstream outputFile;
    outputFile.open("accountBalance.txt");
 
    outputFile << "First Name:\tLast Name:\tSaving Balance:\tChecking Balance:\n";
    outputFile << "__________________________________________________________________\n";  
    for(int i = 0; i< SIZE; i++)
    {
        outputFile << firstName[i] << "\t\t" << lastName[i] << " \t";
        outputFile << fixed << setprecision(2) << "\t$ " << savingsBalance[i] << "    \t$ " << checkingsBalance[i] << endl;
    }

    outputFile.close();
}

void displayAccountBalances(double savingsBalance[], double checkingsBalance[], int user, const int SIZE)
{
    cout << fixed << setprecision(2);
    cout << "Checkings Balance: $" << checkingsBalance[user] << "\nSavings Balance: $" << savingsBalance[user]<< "\n\n";

    mainMenu(savingsBalance, checkingsBalance, user, SIZE);
}

void reciept(string firstName [], string lastName[], int userID [], double checkingsBalance [], double savingsBalance [], int user)
{
	ofstream outputFile;

	// getting time
	time_t now = time(0);
	tm localtm;

	// time starts 1/1/1970
	localtime_r(&now, &localtm); 

	// converting time to correct dates
	int year = localtm.tm_year + 1900;			// adjusting for correct date
	int month = localtm.tm_mon + 1;				// adjusting for 0 indexing
	int day = localtm.tm_mday;
	int hr = localtm.tm_hour;
	int min = localtm.tm_min;
	int sec = localtm.tm_sec;

	// open text file for reciept
	outputFile.open("recieptATM.txt");

	outputFile << "\tATM MACHINE";
	outputFile << "\n==============================";
	outputFile << left << setw(14) << "\nTIME" << right << setw(11) << hr << ":" << min << ":" << sec;
	outputFile << left << setw(14) << "\nDATE" << right << setw(9) << month << "/" << day << "/" << year;

	outputFile << setprecision(2) << fixed;
	outputFile << left << setw(14) << "\n\nUSER ID" << right << setw(18) << userID[user];
	outputFile << left << setw(14) << "\nFIRST NAME" << right << setw(17) << firstName[user];
    outputFile << left << setw(14) << "\nLAST NAME" << right << setw(17) << lastName[user];
	outputFile << left << setw(14) << "\nCHECKINGS" << right << setw(8) << "$" << setw(9) << checkingsBalance[user];
	outputFile << left << setw(14) << "\nSAVINGS" << right << setw(8) << "$" << setw(9) << savingsBalance[user];
	outputFile << left << setw(14) << "\nTOTAL BALANCE" << right << setw(8) << "$" << setw(9) << checkingsBalance[user] + savingsBalance[user];
	outputFile << "\n==============================";
	outputFile << "\nThank you for banking with us!";

	outputFile.close();

}