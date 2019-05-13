//Eric Lepki

#include <iostream>
#include <string>
#include <fstream>
#include "map.h"
#include "position.h"
#include "queue.h"
using namespace std;

/*
The width and height of the map
The position of the adventurer(the start position)
The position of the dog(the end position)
Whether a certain position is blocked or not
*/
void displaymap(Map& e)
{
	position me;  // variable for checking each element for a starting or ending position 
				 // e.position(j,i)
	
	for(int i = 0; i < e.Height(); i++) {
		for (int j = 0; j < e.Width(); j++) {
			
			me = position (j, i);

			if (e.Blocked(me)) {
				cout << 'X';
			}
			
			else if (e.Start() == me) {
				cout << 'A';
			}

			else if (e.End() == me) {
				cout << 'D';
			}

			else  {
				cout << ' ';
			}	
		}
		cout << endl;
	}
}
//Positions that are blocked should be shown as X
//Position that are open should be shown as empty space
//The start position should be shown as an A
//The end position should be shown as a D

/* Part 2
Making sure you don't go back over places you've already been
Making sure that you don't settle for a longer path when a shorter one is available
Knowing when to quit because there is no path
*/

bool FindPath(Map& e)
{
	position next = e.Start();
	// create a queue object
	queue q;
	
	// push the starting position (from map) onto the queue
	q.push(next);

	// while the queue isn't empty
	while (q.size() != NULL){

		// pop the next position off
		next = q.pop();

		// check if that position is the end position
		if (next == e.End()){
			//if i get here I'm done!
			e.GeneratePath();
				//if that position is the end position then return true
				return true;
		}
		// otherwise, repeat this code for each of the four potential neighbors
		else {
			//go over the 4 adjacent squares
				//check if not blocked AND was not visited
					//push to queue
				//ignore
			position square_Top = position(next.col, next.row + 1);
			if (!e.Blocked(square_Top) && !e.Visited(square_Top)) {			//checking if the top square is not blocked AND was not visited
				q.push(next);												//push onto the queue
				e.MarkVisited(square_Top, next);							//have the map mark it as visited
			}

			position square_Bottom = position(next.col, next.row - 1);		//checking if the bottom square is not blocked AND was not visited
			if (!e.Blocked(square_Bottom) && !e.Visited(square_Bottom)) {
				q.push(next);
				e.MarkVisited(square_Bottom, next);
			}

			position square_Left = position(next.col, next.row - 1);		//checking if the left square is not blocked AND was not visited
			if (!e.Blocked(square_Left) && !e.Visited(square_Left)) {
				q.push(next);
				e.MarkVisited(square_Left, next);
			}

			position square_Right = position(next.col, next.row + 1);		//checking if the right square is not blocked AND was not visited
			if (!e.Blocked(square_Right) && !e.Visited(square_Right)) {
				q.push(next);
				e.MarkVisited(square_Right, next);
			}

		}
		// if the queue empties and we haven't found the end, return false
		if (q.size() == NULL && next == e.End()) {
			return false;
		}
			
	}
}

/*
BFS is implemented with a queue. The algorithm looks like this:
	1. Push the start position onto the queue
	2. While the queue is not empty...
		1. Pop the front position off the queue
		2. If it is the end, we're there! Declare success!
		3. Otherwise, push all the unblocked, unvisited neighbors of that position onto the back of the queue
	3. If the queue empties and we haven't found the end, there is no path
*/

int main() {
	Map e;
	e.Read("testmap2.txt");

	displaymap(e);

	FindPath(e);

	return 0;
}