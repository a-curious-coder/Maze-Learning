#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tile
{
	int row;
	int col;
	bool blocked;
	bool visited;
};

struct Player
{
	char symbol;
	int x;
	int y;
};

class mazegenerator
{
public: 

	mazegenerator();

	void Generate(int rowCount, int colCount);

	bool isBlocked(int row, int col);

	int getRowCount();

	int getColCount();

	vector<Tile*> getUnvisitedNeighbours(Tile tile);

	string IsVisitedTrue(int r, int c);

	std::string toString();

	char KeyPress(char keypress);

private:

	vector<vector<Tile> > maze;

};


#endif
