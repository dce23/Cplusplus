#pragma once

#include <iostream>
#include <fstream>
using namespace std;

#include "position.h"

const int PATH_INDICATOR = -101;

class Map
{
public:
	// Read in a text-based map file from the same directory
	void Read(const string& filename);

	// Return the width (columns) and height (rows) of the map
	int Width() { return _width; }
	int Height() { return _height; }

	// Return the start and end positions specified in the map
	position Start() { return _start; }
	position End() { return _end; }

	// Returns true if the specified position in the map is blocked (can't walk there)
	bool Blocked(const position& loc) { return _occupied[loc.row*_width + loc.col]; }

	// The following functions are used for the Breadth-First Search

	// Mark a given position visited during the search
	//  newloc is the position being visited
	//  fromloc is the prior position in the search
	void MarkVisited(const position& newloc, const position& fromloc);
	// Check if a given position has already been visited during the search
	bool Visited(const position& loc) { return _visited[loc.row*_width + loc.col]; }

	// Call this method after the search when end has been found
	void GeneratePath();
	// Once the path is generated,
	//  call this method to check if a given position is on the path
	bool OnPath(const position& loc) { return _back[loc.row*_width + loc.col] == PATH_INDICATOR; }

private:
	int _width, _height;
	bool * _occupied;
	bool * _visited;
	int * _back;
	position _start;
	position _end;

};
