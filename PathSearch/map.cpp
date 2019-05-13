#include "map.h"

void Map::Read(const string& filename)
{
	ifstream in;
	in.open(filename);

	in >> _width >> _height;

	_occupied = new bool[_width*_height];
	_visited = new bool[_width*_height];
	_back = new int[_width*_height];

	char ch;
	int i = 0;
	for (int row = 0; row < _height; row++) {
		for (int col = 0; col < _width; col++) {
			in >> ch;
			if (ch == 'X') {
				_occupied[i] = true;
			}
			else {
				_occupied[i] = false;
			}

			if (ch == 'S') {
				_start.col = col;
				_start.row = row;
			}
			else if (ch == 'E') {
				_end.col = col;
				_end.row = row;
			}

			_visited[i] = false;
			_back[i] = -1;
			i++;
		}
	}

	in.close();
}

void Map::MarkVisited(const position& newloc, const position& fromloc)
{
	int to = newloc.row*_width + newloc.col;
	int from = fromloc.row*_width + fromloc.col;
	_visited[to] = true;
	_back[to] = from;
}

void Map::GeneratePath()
{
	int next = _end.row*_width + _end.col;
	int begin = _start.row*_width + _start.col;

	while (next != begin) {
		int back = _back[next];
		_back[next] = PATH_INDICATOR;
		next = back;
	}
}

