//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//StatsList.cpp - This is the implementation file for the class definition    \\
//  assignment  4                                                             \\
//Author: Eric Lepki                                                          \\
//Class: CSCI/CMPE 2380                                                       \\
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include <iostream>
#include "StatsList.h"

using namespace std;

StatsList::StatsList()
{
	Counter = 0;
}

ListType StatsList::At(int element) //Returns value in array at given index
{
	return List[element];
}

int StatsList::Length()		//Returns the number of items in the list
{
	return Counter;
}

double StatsList::Mean()	//The mean of the items in the list
{
	double sum = 0.0;
	double total;

	for (int i = 0; i < Counter; i++) {
		sum += List[i];
	}

	total = sum / Counter;
	
	return total;
}

double StatsList::MeanNoHighLow()	//The mean with the high and low removed
{
	double sum = 0.0;
	double min = GetLow();
	double max = GetHigh();
	double mean;

	for (int i = 0; i < Counter; i++) {
		if (List[i] != min && List[i] != max) {
			sum += List[i];
		}
	}

	mean = sum / (Counter - 2);
	
	return mean; 
}

void StatsList::PrintGradeCount() //Print the number of A's, B's, C's, D's, F's.
{
	cout << GradeCountRange(90, 100) << " A" << endl;
	cout << GradeCountRange(80, 89.9) << " B" << endl;
	cout << GradeCountRange(70, 79.9) << " C" << endl;
	cout << GradeCountRange(60, 69.9) << " D" << endl;
	cout << GradeCountRange(0, 59.9) << " F" << endl;
}

ListType StatsList::GetHigh()		//Return the highest grade in the list
{
	double highest = List[0];		//Start by setting the first element in the list as the highest

	//Or keep going thru the list until the highest is found
	for (int h = 1; h < MAXCELLS; h++) {
		if (List[h] > highest) {
			highest = List[h];
		}
	}

	return highest;
}

ListType StatsList::GetLow()		//Return the lowest grade in the list
{
	double lowest = List[0];		//Start by setting the first element in the list as the lowest

	//Or keep going thru the list until the lowest is found
	for (int i = 1; i < MAXCELLS; i++) {
		if (List[i] < lowest) {
			lowest = List[i];
		}
	}

	return lowest;
}

bool StatsList::NewGrade(ListType ng)	//Add a new grade to the list
{
	if (Counter < MAXCELLS) {
		List[Counter] = ng;
		Counter++;
		return true;
	}

	else {
		return false;
	}
}

int StatsList::GradeCountRange(double score1, double score2)	//Returns the # of grades in that range
{
	int letCont = 0;
	
	for (int i = 0; i < Counter; i++) {
		if (List[i] >= score1 && List[i] <= score2) {		
			letCont++;
		}
	}

	return letCont;
}