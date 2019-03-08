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
		if (r == 0 || c == 0 || c == getColCount() - 1 || r == getRowCount() - 1)
		{
			maze[r][c] = TILE_BLOCKED; // U
		}
		else {
			maze[r][c] = TILE_UNBLOCKED; // 0 = blocked, 1 = free in the maze.
		}
    }	
  }
}

/*int randomInt(int min, int max)
{

	if (rand() % 1 == 0)
	{
		min = TILE_UNBLOCKED;
	}
	else 
	{
		max = TILE_BLOCKED;
	}

	return 0;
}*/

string MazeGenerator::toString()
{
	stringstream ss;

	for (int r = 0; r < maze.size(); r++) // iterates through vector size which will be the rows in the maze. 
	{
		for (int c = 0; c < maze[0].size(); c++) // This iterates through one element of the maze vector which is a vector by itself to check which elements are 0 / 1.
		{
			if (maze[r][c] == TILE_BLOCKED) // If r/c == 0
/*
* Requirements to be met here are seperated by OR. Meaning if any of these requirements are met, add B to ss.
* if r == 0 (If the row is == 0) This covers the top with B.	if c == 0 (if the column is zero) this covers the left side with B.
* if c (column) == getColCount (Number of columns assigned by user) -1 which brings us to the correct index for the last column will fill the left side with B
* Finally, if r (row) == getRowCount (Assigned by user) -1 will find the correct index position of rowcount and fill with B's.
*/
			{
				ss << "B"; // cout blocked 'B' 
			}
			else if (maze[r][c] == TILE_UNBLOCKED)// Else fill any space that does not meet requirements with U's
			{
				ss << "U";
			}

			ss << " "; // Print space between chars.
		}

		ss << "\n";  // Print new line after every row iteration
	}
	ss << "\n"; // Creates new line after everything if for loops have finished to give space below last row.

	return ss.str(); // returns all values of B/U 
}

bool MazeGenerator::IsBlocked(int row, int col)
{
	return true;
}
