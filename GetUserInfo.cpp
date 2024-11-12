//This program will write user information for 5 users to a file for use with the ATM machine.

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ofstream outputFile;
    outputFile.open("userInfo.txt");

    outputFile << "First Name:\tLast Name:\tUser ID:\tPassword:\tPIN:\tPhone Number:\n";
    outputFile << "___________________________________________________________________________________________\n";
    outputFile << "Kameron    \tTaylor    \t000001  \tTaylor123\t0001\t(555)555-1234\n";
    outputFile << "Sasha      \tSmith     \t000002  \tSmith123 \t0002\t(555)555-5390\n";
    outputFile << "Ariel      \tJerry     \t000003  \tJerry123 \t0003\t(555)555-2008\n";
    outputFile << "Fay        \tTracey    \t000004  \tTracey123\t0004\t(555)555-0012\n";
    outputFile << "Dennis     \tBeck      \t000005  \tBeck123  \t0005\t(555)555-6594\n";

    outputFile.close();

    return 0;
}