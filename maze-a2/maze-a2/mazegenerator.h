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

class mazegenerator
{
public: 

	mazegenerator();

	void Generate(int rowCount, int colCount);

	bool isBlocked(int row, int col);

	int getRowCount();

	int getColCount();

	vector<Tile*> getUnvisitedNeighbours(const Tile* tile, int row, int col);

	string IsVisitedTrue(int r, int c);

	std::string toString();

private:

	vector<vector<Tile>> maze;

};


#endif
