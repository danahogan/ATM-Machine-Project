//This program will be used to upload the user information to use with the ATM app.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int SIZE = 5;

//Function Prototypes
void loadUserData(string [], string [], string [], string [], int [], int[], const int);
void getAccountBalances(double [], double[], const int);

int main ()
{
    const int SIZE = 5; //Constant amount of users.
    string firstName[SIZE], lastName[SIZE], password[SIZE], phoneNumber[SIZE]; //Arrays for name and password.
    int userID[SIZE], pin[SIZE]; //Arrays for ID and PIN numbers.
    double savingsBalance[SIZE], checkingsBalance[SIZE]; //Array for account balances.

    loadUserData(firstName, lastName, password, phoneNumber, userID, pin, SIZE);
    getAccountBalances(savingsBalance, checkingsBalance, SIZE);

    for(int i=0; i<SIZE; i++)
    {
        cout << firstName[i] << " " << lastName[i] << " " << password[i] << " " << phoneNumber[i] << " ";
        cout << userID[i] << " " << password[i] << " " << fixed << setprecision(2) << savingsBalance[i] << " " << checkingsBalance[i] << endl;
    }
}

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