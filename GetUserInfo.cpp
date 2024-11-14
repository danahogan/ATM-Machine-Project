//This program will write user information for 5 users to a file for use with the ATM machine.

#include <iostream>
#include <fstream>
using namespace std;

void createUserInfo()
{
    ofstream outputFile;
    outputFile.open("userInfo.txt");

    outputFile << "First Name:\tLast Name:\tUser ID:\tPassword:\tPIN:\tPhone Number:\n";
    outputFile << "___________________________________________________________________________________________\n";
    outputFile << "Kameron    \tTaylor    \t123451  \tTaylor123\t1111\t(555)555-1234\n";
    outputFile << "Sasha      \tSmith     \t123452  \tSmith123 \t1112\t(555)555-5390\n";
    outputFile << "Ariel      \tJerry     \t123453  \tJerry123 \t1113\t(555)555-2008\n";
    outputFile << "Fay        \tTracey    \t123454  \tTracey123\t1114\t(555)555-0012\n";
    outputFile << "Dennis     \tBecks     \t123455  \tBecks123 \t1115\t(555)555-6594\n";

    outputFile.close();
}

void createAccountBalance()
{
    ofstream outputFile;
    outputFile.open("accountBalance.txt");
 
    outputFile << "First Name:\tLast Name:\tAccount Balance:\n";
    outputFile << "___________________________________________________________\n";
    outputFile << "Kameron    \tTaylor    \t$ 10,269.00\n";
    outputFile << "Sasha      \tSmith     \t$ 23,611.00\n";
    outputFile << "Ariel      \tJerry     \t$  9,002.50\n";
    outputFile << "Fay        \tTracey    \t$  5,153.00\n";
    outputFile << "Dennis     \tBecks     \t$ 22,658.50\n";

    outputFile.close();

}

int main ()
{
    createUserInfo();
    createAccountBalance();
}