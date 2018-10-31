//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: Eric Lepki
// Date: 04/02/18
// Class: 2380
// Semester: Spring 18
//
// Program Name: Lab 09
// File Name: lab09.cpp
// Program Description: Sorts char in strings using Quicksort
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 

#include<iostream>
#include<string>
using namespace std;


//Here we use quicksort to sort the string of characters
//we sort the string in place without making any copies, so
//for a call to quicksort we pass in the low and high indices
//we sort to.
void QuickSort(string &input, int low, int high)
{
	//initial conditions
	int smallindex = high;
	int index = low;
	char pivot;

	//base case if only one element
	/*if (low == 0) {
		QuickSort(input, low, high);
	}*/
	
	//choose pivot as middle element
	pivot = input[(low + high) / 2];

	//swap pivot with index
	pivot = input[index];
	input[index] = pivot;

	//execute quicksort loop
	int temp;

	while (index <= smallindex) {
		while (input[index] < pivot) {
			index++;
		}

		while (input[smallindex] > pivot) {
			smallindex--;
		}
		if (index <= smallindex) {
			temp = input[index];
			input[index] = input[smallindex];
			input[smallindex] = temp;
			index++;
			smallindex--;
		}
	}
	
	//swap pivot with smallindex


	//recursively call each side
	if (low < smallindex) {
		QuickSort(input, low, smallindex);
	}
	if (index < high) {
		QuickSort(input, index, high);
	}
}



//in main we just want to take in a string 
int main()
{
	string input;
	cout << "Please input a string:" << endl;

	//get the string
	getline(cin, input);

	//efficiently sort the list
	QuickSort(input, 0, input.length() - 1);
	//print the output
	cout << input << endl;

	return 0;
}