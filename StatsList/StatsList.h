#pragma once
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//StatsList.h - This is the header file with the class definition             \\
//  assignment  4                                                             \\
//Author: Eric Lepki                                                          \\
//Class: CSCI/CMPE 2380                                                       \\
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

const unsigned int MAXCELLS = 6;	//Maximum size of the array
typedef double ListType;			//Data type stored in the array
class StatsList
{
public:
	StatsList();					//Constructor
	ListType At(int);				//Returns value in array at given index
	int Length();					//Returns the number of items in the list
	double Mean();					//The mean of the items in the list
	double MeanNoHighLow();			//The mean with the high and low removed
	void PrintGradeCount();			//Print the number of A's, B's, etc.
	ListType GetHigh();				//Return the highest grade in the list
	ListType GetLow();				//Return the lowest grade in the list
	bool NewGrade(ListType);		//Add a new grade to the list
private:
	int GradeCountRange(double, double);	//Returns the # of grades in that range
	ListType List[MAXCELLS];				//The list
	int Counter;							//Keeps track of how many grades exist
};