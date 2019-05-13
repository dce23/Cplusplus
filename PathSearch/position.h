#pragma once

class position
{
public:
	// public data member, for simplicity
	int col, row;

	// constructors for your convenience
	position() { col = -1; row = -1; }
	position(int _x, int _y) { col = _x; row = _y; }

	// the below methods are "operator overloading"
	// they allow the class creator to define how built-in operators work with
	//  this class

	// this one is called if you try to compare two positions, e.g. pos1 == pos2
	// the method is called on the "left hand side" argument (pos1)
	//  and the "right hand side" (pos2) is passed as a parameter
	bool operator==(const position& rhs) { return col == rhs.col && row == rhs.row; }

	// likewise, this one is called if you do pos1 != pos2
	bool operator!=(const position& rhs) { return !((*this) == rhs); }
};
