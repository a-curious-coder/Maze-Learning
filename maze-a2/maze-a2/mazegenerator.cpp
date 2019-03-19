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
	// Resize origin and inner vectors to desired sizes.
	maze.resize(rowCount);
	for (int i = 0; i < rowCount; i++)
	{
		maze[i].resize(colCount);
	}
	// Set default values for Tile attributes iterating through every 'Tile'
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
	//cout << "Stage 1 Complete." << endl;
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

	//cout << "Stage 2 Complete." << endl;

	int r = 14;
	int c = 13;
	Tile& tile = maze[r][c];
	vector <Tile> neighbours = getUnvisitedNeighbours(tile);

	/*for (int r = 0; r < getRowCount(); r++) // Iterate through rows
	{
		for (int c = 0; c < getColCount(); c++) // Iterate through cols
		{
			Tile& tile = maze[r][c]; // tile = maze position r, c E.g. 0, 1

			for (int i = 0; i < neighbours.size(); i++) // i = 0; If i is less than size of neighbours then i++
			{
				cout << "Neighbour " << i << ": row:" << neighbours[i].row << " col: " << neighbours[i].col << endl;
			}
		}
	}*/


	/*for (int r = 0; r < getRowCount(); r++)
	{
		for (int c = 0; c < getColCount(); c++)
		{
			
			cout << "Neighbour" << r << "," << c << ":" << maze[r][c].;
		}
		cout << "\n";
	}
	cout << "\n";*/
	cout << "Number of Neighbours: " << neighbours.size() << "\n"<< endl;
	for (int i = 0; i < neighbours.size(); i++)
	{
		cout << "Neighbour " << i+1 << ": row:" << neighbours[i].row << " col: " << neighbours[i].col << endl;
	}
	cout << "\n" << endl;
}

bool mazegenerator::isBlocked(int row, int col) // returns whether specific cell is blocked / unblocked
{
	if (maze[row][col].blocked == true)
	{
		return true;
	}
	else if (maze[row][col].blocked == false)
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
	cout << "\n";
	if (tile.row == 0 && tile.col == 0) // Checks if row and col is at value 0
	{
		//Will check and pushback neighbours next to col 0 and below row 0
		cout << "Tile: " << tile.row << "\tCol: " << tile.col << endl;
		if (maze[row + 1][col].visited == false)
		{
			neighbours.push_back(maze[row + 1][col]);
		} 
		if (maze[row][col + 1].visited == false)
		{
			neighbours.push_back(maze[row][col + 1]);
		}
	}
	else if (tile.row == 0) // Checks if row is at value 0
	{
		cout << "Tile: " << tile.row << "\tCol: " << tile.col << endl;
		//Will check and pushback neighbours next to row 0
		if (maze[row + 1][col].visited == false)
			neighbours.push_back(maze[row + 1][col]);
		
	}
	else if (tile.col == 0) // Checks if column is at value 0
	{
		cout << "Tile: " << tile.row << "\tCol: " << tile.col << endl;
		//Will check and pushback neighbours next to col 0
		if (maze[row][col + 1].visited == false)
			neighbours.push_back(maze[row][col + 1]);
	}
	else if (tile.row == getRowCount()) // Checks if row is at the value of RowCount
	{
		//Will check and pushback neighbours above row 'getRowCount()'
		cout << "Tile: " << tile.row << "\tCol: " << tile.col << endl;
		if (maze[row - 1][col].visited == false)
		{
			neighbours.push_back(maze[row - 1][col]); // Pushes the row before max row count
		}
		else if (maze[row][col - 1].visited == false)
		{
			neighbours.push_back(maze[row][col-1]); // Pushes row
		}
		else if (maze[row][col + 1].visited == false)
		{
			neighbours.push_back(maze[row][col+1]);
		}

	}
	else if (tile.col == getColCount()) // Checks if column is at the value of ColCount
	{
		//Will check and pushback neighbours around Col except for Col + 1 because that would be +1 more than the getColCount number. E.g. if Col was 15 then it would look at 16 and throw error
		cout << "Tile: " << tile.row << "\tCol: " << tile.col << endl;
		
		if (maze[row][col - 1].visited == false)
		{
			neighbours.push_back(maze[row][col - 1]);
		}
		else if (maze[row - 1][col].visited == false)
		{
			neighbours.push_back(maze[row - 1][col]);
		}
		else if (maze[row + 1][col].visited == false)
		{
			neighbours.push_back(maze[row + 1][col]);
		}

	}
	else
	{
		//Will check and pushback all other neighbours not gone over in the previous requirements
		cout << "Tile: " << tile.row << "\tCol: " << tile.col << endl;
		//for (int i = 0; i < getRowCount(); i++)
		//{
			//Iterates through all surrounding cells to check whether they've been visited. If not, pushed on to stack.
			if (maze[row - 1][col].visited == false)
			{
				neighbours.push_back(maze[row - 1][col]); // Adds maze row and col spec to neighbours vector
			}
			if (maze[row + 1][col].visited == false)
			{
				neighbours.push_back(maze[row + 1][col]);
			}
			if (maze[row][col - 1].visited == false)
			{
				neighbours.push_back(maze[row][col - 1]);
			}
			if (maze[row][col + 1].visited == false)
			{
				neighbours.push_back(maze[row][col + 1]);
			}
			else
			{
				neighbours.pop_back();
			} // Checks if all neighbours are visited. If so, pop from stack.
		//}
	}

	return neighbours;
} // DONE?

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
} // DONE