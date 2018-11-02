//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//hw5main.cpp - This is the driver file for the static list homework          \\
//  assignment  4                                                              \\
//Author: Eric Lepki                                                           \\
//Class: CSCI/CMPE 2380                                                       \\
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\


#include <iostream>
#include "StatsList.h"

using namespace std;


const double MAXGRADE = 100.0;
const double MINGRADE = 0.0;


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//GetGrades prompts the user for grades and adds them to the stats class using\\
//  the reference to the object,
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

void GetGrades(StatsList* stats)
{
	ListType grade = 0;
	while (grade != -1)
	{
		cout << "Enter grade (-1 quits):";
		cin >> grade;
		if (!cin)
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Invalid number" << endl;
		}
		else if (grade >= MINGRADE && grade <= MAXGRADE)
		{
			if (!stats->NewGrade(grade))
			{
				cout << grade << " not entered - grade list is full" << endl;
			}
		}
		else
		{
			if (grade != -1)
				cout << "Grade out of range" << endl;
		}

	}
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//PrintMenu just prints the menu to the user.                                 \\
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

void PrintMenu()
{
	cout << endl << endl << "Please select what you want to do:" << endl;
	cout << "(1) Obtain the mean" << endl;
	cout << "(2) The mean with high and low grades removed" << endl;
	cout << "(3) Obtain the count of A's, B's, C's, D's, and F's" << endl;
	cout << "(4) Get the high and low grades" << endl;
	cout << "(5) Get the number of grades" << endl;
	cout << "(6) Exit" << endl;
}


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//HandleInput takes in a pointer to the stats class and a reference to the    \\
//  user input.  It processes the input and formats the data received from the\\
//  Stats class.                                                              \\
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

void HandleInput(StatsList* stats, int& user_input)
{
	switch (user_input)
	{
	case 1:
		cout << "The mean of the grades entered is " << stats->Mean() << endl;
		break;
	case 2:
		cout << "The mean of the grades entered with the high and low grades removed is " << stats->MeanNoHighLow() << endl;
		break;
	case 3:
		stats->PrintGradeCount();
		break;
	case 4:
		cout << "The high grade was " << stats->GetHigh() << endl;
		cout << "The low grade was " << stats->GetLow() << endl;
		break;
	case 5:
		cout << "There are " << stats->Length() << " grades" << endl;
		break;
	case 6:
		//exit 
		break;
	default:
		cout << "Invalid option" << endl;
		break;
	}
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//The main class handles the main program loop and declares the Stats object  \\
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

int main()
{
	int user_input = 0;
	StatsList stats;

	cout << "Welcome" << endl;
	GetGrades(&stats);

	while (user_input != 6)
	{
		PrintMenu();
		cout << ">";
		cin >> user_input;
		//if they enter something that is not a number
		while (!cin)
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Invalid option" << endl;
			user_input = 1000;
		}
		HandleInput(&stats, user_input);
	}
	return 0;
}