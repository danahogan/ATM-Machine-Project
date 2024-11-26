#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

void reciept(string name, int userID, double checkings, double savings)
{
	ofstream outputFile;

	// getting time
	time_t now = time(0);
	tm localtm;

	// time starts 1/1/1970
	localtime_s(&localtm, &now); 

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
	outputFile << left << setw(14) << "\n\nUSER ID" << right << setw(18) << userID;
	outputFile << left << setw(14) << "\nCUSTOMER NAME" << right << setw(17) << name;
	outputFile << left << setw(14) << "\nCHECKINGS" << right << setw(8) << "$" << setw(9) << checkings;
	outputFile << left << setw(14) << "\nSAVINGS" << right << setw(8) << "$" << setw(9) << savings;
	outputFile << left << setw(14) << "\nTOTAL BALANCE" << right << setw(8) << "$" << setw(9) << checkings + savings;
	outputFile << "\n==============================";
	outputFile << "\nThank you for banking with us!";

	outputFile.close();

}

int main()
{
	string name;
	double checkings, savings;
	int userID;

	name = "Taylor";
	userID = 123451;
	checkings = 1000;
	savings = 500;

	reciept(name, userID, checkings, savings);

}