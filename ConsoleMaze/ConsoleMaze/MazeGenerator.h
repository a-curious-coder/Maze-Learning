#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MazeGenerator
{
	static const int TILE_BLOCKED = 1;
	static const int TILE_UNBLOCKED = 0;
public:
	
	void Generate(int rowCount, int colCount);
	string toString();
	bool IsBlocked(int row, int col);

	int getRowCount() { return maze.size(); }
	int getColCount() { return maze[0].size(); }
	//int randomInt(int min, int max);

private:
	vector<vector<int>> maze;
	//vector<int>rowCount;
};

#endif
