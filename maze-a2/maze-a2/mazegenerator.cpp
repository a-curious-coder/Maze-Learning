#include "mazegenerator.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <stack>
#include <ctime>

using namespace std;

mazegenerator::mazegenerator()
{

}

void mazegenerator::Generate(int rowCount, int colCount) //Generates 'maze' using vectors.
{
	srand(time(NULL)); // Referral for random num generator
	// Resize origin and inner vectors to desired sizes.
	maze.resize(rowCount);
	for (int i = 0; i < rowCount; i++)
	{
		maze[i].resize(colCount);
	}
	// Set defaul values for Tile attributes iterating through every 'Tile'
	for (int r = 0; r < maze.size(); r++)
	{
		for (int c = 0; c < maze[0].size(); c++)
		{
			maze[r][c].row = r;
			maze[r][c].col = c;
			maze[r][c].visited = false;
			maze[r][c].blocked = false;
		}
	}
	// Iterate through every 'Tile' and based on if statement, assign blocked and unblocked state.
	for (int r = 0; r < maze.size(); r++)
	{
		for (int c = 0; c < maze[0].size(); c++)
		{
			if (r == 0 || c == 0 || r == getRowCount() - 1 || c == getColCount() - 1)
			{
				maze[r][c].blocked = true;
			}
			else 
			{
				maze[r][c].blocked = false;
			}
		}
	}

}

bool mazegenerator::isBlocked(int row, int col) // returns whether specific cell is blocked / unblocked
{
	if (maze[row][col].blocked = true)
	{
		return true;
	}
	else if (maze[row][col].blocked = false)
	{
		return false;
	}
		
} // DONE

int mazegenerator::getRowCount()
{
	return maze.size(); // Returns origin vector size
} // DONE

int mazegenerator::getColCount()
{
	return maze[0].size(); // Returns inner vector size
} // DONE

vector<Tile> mazegenerator::getUnvisitedNeighbours(const Tile& tile)
{
	
	vector<Tile> neighbours; // Vector to collect unvisited neighbours
	int row = tile.row;
	int col = tile.col;

	srand(time(NULL)); // Generates a truly random number
	for (int i = 0; i >= getRowCount() && i >= getColCount(); i++)
	{
		//Iterates through all surrounding cells to check whether they've been visited. If not, pushed on to stack.
		if (maze[row - 1][col].visited == false)
		{
			neighbours.push_back(maze[row - 1][col]); // Adds maze row and col spec to neighbours vector
		}
		else if (maze[row + 1][col].visited == false)
		{
			neighbours.push_back(maze[row + 1][col]);
		}
		else if (maze[row][col - 1].visited == false)
		{
			neighbours.push_back(maze[row][col - 1]);
		}
		else if (maze[row][col + 1].visited == false)
		{
			neighbours.push_back(maze[row][col + 1]);
		}
		else {
			neighbours.pop_back();
		} // Checks if all neighbours are visited. If so, pop from stack.
	}
			
	return neighbours;
}

string mazegenerator::toString() // Prints everything from generate function is a format of 'B' - blocked and 'U' - Unblocked
{
	stringstream ss;

	for (int r = 0; r < maze.size(); r++) // iterates through vector size which will be the rows in the maze. 
	{
		for (int c = 0; c < maze[0].size(); c++) // This iterates through one element of the maze vector which is a vector by itself to check which elements are 0 / 1.
		{
			if (maze[r][c].blocked == true) // If r/c == 0
			/*/
			 * Requirements to be met here are seperated by OR. Meaning if any of these requirements are met, add B to ss.
			 * if r == 0 (If the row is == 0) This covers the top with B.	if c == 0 (if the column is zero) this covers the left side with B.
			 * if c (column) == getColCount (Number of columns assigned by user) -1 which brings us to the correct index for the last column will fill the left side with B
			 * Finally, if r (row) == getRowCount (Assigned by user) -1 will find the correct index position of rowcount and fill with B's.
			/*/
			{
				ss << "B"; // cout blocked 'B' 
			}
			else if (maze[r][c].blocked == false) // Else fill any space that does not meet requirements with U's
			{
				ss << " ";
			}

			ss << " "; // Print space between chars.
		}

		ss << "\n"; // Print new line after every row iteration
	}
	ss << "\n"; // Creates new line after everything if for loops have finished to give space below last row.

	return ss.str(); // returns all values of B/U
	system("pause");
}