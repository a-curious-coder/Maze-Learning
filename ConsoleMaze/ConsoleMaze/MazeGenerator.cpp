#include "MazeGenerator.h"
#include <iostream>
#include <sstream> 
#include <string>



void MazeGenerator::Generate(int rowCount, int colCount)
{
	maze.resize(rowCount); // Resize to size of rowCount vector.

	// Iterate over each row.
	for (int i = 0; i < rowCount; i++) {
		// Set the number of columns in each row.
		maze[i].resize(colCount);
	}
	for (int r = 0; r < maze.size(); r++) {
    // maze[x] returns the number of columns in row "x".
    // As all rows have the same number of columns, we can just use row 0's size.
    for (int c = 0; c < maze[0].size(); c++) {
      maze[r][c] = 0; // 0 = blocked, 1 = free in the maze.
    }
  }
}

string MazeGenerator::toString()
{
	stringstream ss;

	for (int r = 0; r < maze.size(); r++) // iterates through vector size which will be the rows in the maze. 
	{
		for (int c = 0; c < maze[0].size(); c++) // This iterates through one element of the maze vector which is a vector by itself to check which elements are 0 / 1.
		{
			if (maze[r][c] == TILE_UNBLOCKED) // If r/c == 0
			{
				ss << "B"; // cout blocked 'B' 
			}
			else if (maze[r][c] == TILE_BLOCKED) // otherwise if r/c == 1
			{
				ss << "U"; // cout unblocked 'U'
			}
			ss << " "; // Print space between chars.
		}
		ss << "\n";  // Print new line after every row iteration
	}
	return ss.str(); // returns all values of B/U 
}

bool MazeGenerator::IsBlocked(int row, int col)
{
	return true;
}
