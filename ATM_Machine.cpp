//This is the working ATM code file

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//Function Prototypes
void loadUserData(string [], string [], string [], string [], int [], int[], const int);
void getAccountBalances(double [], double[], const int);
bool displayLogin();
int userIDValidation(int [], const int);
bool userPasswordValidation(string [], const int, int);
void mainMenu();


int main()
{
    bool valid = true;

    valid = displayLogin();

    if(valid == true)
    {
        mainMenu();
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

void getAccountBalances(double savingsBalance[], double checkingsBalance[], int SIZE)
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

bool displayLogin()
{

     /****************************************
     * Variable Declaration
     ****************************************/

    const int SIZE = 5; //Constant amount of users.
    string firstName[SIZE], lastName[SIZE], password[SIZE], phoneNumber[SIZE]; //Arrays for name and password.
    int userID[SIZE], pin[SIZE]; //Arrays for ID and PIN numbers.
    double savingsBalance[SIZE], checkingsBalance[SIZE]; //Array for account balances.


    /****************************************
     * Loading User Data to System
     ****************************************/

    loadUserData(firstName, lastName, password, phoneNumber, userID, pin, SIZE);
    getAccountBalances(savingsBalance, checkingsBalance, SIZE);

    /*************************************************
     * Display Login Page and Validate Credentials
     *************************************************/

    int userIDElement, userPin;
    bool valid;

    cout << "      Welcome!\n";
    cout << "\nEnter your User ID: ";
    
    userIDElement = userIDValidation(userID, SIZE);
    
    cout << "\nEnter your Password: ";

    valid = userPasswordValidation(password, SIZE, userIDElement);
    
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

