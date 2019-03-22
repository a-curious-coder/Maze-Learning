#include "mazegenerator.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <stack>
#include <ctime>
#include "windows.h"

using namespace std;

mazegenerator::mazegenerator()
{

}

void mazegenerator::Generate(int rowCount, int colCount) //Generates 'maze' using vectors.
{
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

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

	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

	// Iterate through every 'Tile' and based on if statement, assign blocked and unblocked state.
	// Should make every tile on edge of 'maze' blocked.
	/*for (int r = 0; r < maze.size(); r++) // Iterate through rows
	{
		for (int c = 0; c < maze[0].size(); c++) // iterate through columns
		{
			if (r == 0 || c == 0 || r == getRowCount() - 1 || c == getColCount() - 1) // If row is 0, if col is 0, if row is RowCount, if col is ColCount then set maze vector at value r and c to blocked == true.
			{
				maze[r][c].blocked = true;
			}
			else 
			{
				maze[r][c].blocked = false;
			}
		}
	}*/

	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

	//TEST TO CHECK NEIGHBOURS
	
	int row = 1;
	int col = 2;
	Tile& tile = maze[row][col];
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

	/*cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;
	for (int r = 0; r < getRowCount(); r++)\
	{
		cout << row << "," << col << endl;
		for (int c = 0; c < getColCount(); c++)
		{
			cout << "\tRow: " << r << " Col: " << c << endl;
			
		}
		cout << "\n";

		if(row != getRowCount())
			row = row + 1;
		if (col != getColCount())
			col = col + 1;
	}
	cout << "\n";*/
	cout << "Number of Neighbours for [" << row << "," << col << "]: " << neighbours.size() << "\n" << endl;
	cout << "Neighbour\tRow\tCol\tVisited" << endl;
	//neighbours.push_back(maze[row][col]);
	maze[row][col].visited = true;
	for (int i = 0; i < neighbours.size(); i++)
	{
		cout << i+1 << "\t\t" << neighbours[i].row << "\t" << neighbours[i].col << "\t";
		maze[neighbours[i].row][neighbours[i].col].blocked = true;
		cout << IsVisitedTrue(neighbours[i].row, neighbours[i].col) << endl;
	}

	for (int r = 0; r < getRowCount(); r++)
	{
		row = row + 1;
		for (int c = 0; c < getColCount(); c++)
		{
			getUnvisitedNeighbours(tile);
			cout << r << ", " << c  << "\t";
			col = col + 1;
		}
		cout << "\n";
	}


	

	cout << "\nNeighbours are represented by 'B'." << endl;
	cout << "\n" << endl;
	//TEST TO CHECK NEIGHBOURS

	
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
	/*if (tile.row == 0 && tile.col == 0) // Checks if row and col is at value 0
	{
		//Will check and pushback neighbours next to col 0 and below row 0
		//cout << "Row: " << tile.row << "\tCol: " << tile.col << endl;
		if (maze[row + 1][col].visited == false)
		{
			neighbours.push_back(maze[row + 1][col]);
			maze[row][col].visited = true;
		}
		if (maze[row][col + 1].visited == false)
		{
			neighbours.push_back(maze[row][col + 1]);
			maze[row][col].visited = true;
		}
	}
	else if (tile.row == 0) // Checks if row is at value 0
	{
		//cout << "Row: " << tile.row << "\tCol: " << tile.col << endl;
		//Will check and pushback neighbours next to row 0
		if (maze[row + 1][col].visited == false)
			neighbours.push_back(maze[row + 1][col]);
		maze[row][col].visited = true;
	}
	else if (tile.col == 0) // Checks if column is at value 0
	{
		//cout << "Row: " << tile.row << "\tCol: " << tile.col << endl;
		//Will check and pushback neighbours next to col 0
		if (maze[row][col + 1].visited == false)
			neighbours.push_back(maze[row][col + 1]);
		maze[row][col].visited = true;
	}
	else if (tile.row == getRowCount() - 1) // Checks if row is at the value of RowCount
	{
		//Will check and pushback neighbours above row 'getRowCount()'
		//cout << "Row: " << tile.row << "\tCol: " << tile.col << endl;
		if (maze[row - 1][col].visited == false)
		{
			neighbours.push_back(maze[row - 1][col]); // Pushes the row before max row count
			maze[row][col].visited = true;
		}
		if (maze[row][col - 1].visited == false)
		{
			neighbours.push_back(maze[row][col - 1]); // Pushes row
			maze[row][col].visited = true;
		}
		if (maze[row][col + 1].visited == false)
		{
			neighbours.push_back(maze[row][col + 1]);
			maze[row][col].visited = true;
		}

	}
	else if (tile.col == getColCount() - 1) // Checks if column is at the value of ColCount
	{
		//Will check and pushback neighbours around Col except for Col + 1 because that would be +1 more than the getColCount number. E.g. if Col was 15 then it would look at 16 and throw error
		//cout << "Row: " << tile.row << "\tCol: " << tile.col << endl;

		if (maze[row][col - 1].visited == false)
		{
			neighbours.push_back(maze[row][col - 1]);
			maze[row][col].visited = true;
		}
		if (maze[row - 1][col].visited == false)
		{
			neighbours.push_back(maze[row - 1][col]);
			maze[row][col].visited = true;
			cout << "2";
		}
		if (maze[row + 1][col].visited == false)
		{
			neighbours.push_back(maze[row + 1][col]);
			maze[row][col].visited = true;
		}

	}
	else if (tile.col == getColCount() - 1 && tile.col == getRowCount() - 1) // Checks if both row and col are at the max values.
	{
		if (maze[row - 1][col].visited == false)
		{
			neighbours.push_back(maze[row - 1][col]);
		}
		else if (maze[row][col - 1].visited == false)
		{
			neighbours.push_back(maze[row][col - 1]);

		}
	}
	else
	{
		//Will check and pushback all other neighbours not gone over in the previous requirements
		//cout << "Row: " << tile.row << "\tCol: " << tile.col << endl;
		//for (int i = 0; i < getRowCount(); i++)
		//{
			//Iterates through all surrounding cells to check whether they've been visited. If not, pushed on to stack.
		if (maze[row - 1][col].visited == false)
		{
			neighbours.push_back(maze[row - 1][col]); // Adds maze row and col spec to neighbours vector
			maze[row][col].visited = true;
		}
		if (maze[row + 1][col].visited == false)
		{
			neighbours.push_back(maze[row + 1][col]); //Moves tile to row below
			maze[row][col].visited = true;
		}
		if (maze[row][col - 1].visited == false)
		{
			neighbours.push_back(maze[row][col - 1]); // Moves tile to column 
			maze[row][col].visited = true;
		}
		if (maze[row][col + 1].visited == false)
		{
			neighbours.push_back(maze[row][col + 1]);
			maze[row][col].visited = true;
		}
		else
		{
			neighbours.pop_back();
		} // Checks if all neighbours are visited. If so, pop from stack.
		*/
	
			if (row > 0 && !maze[row - 1][col].visited) // Checks if the row is more than 0 and not visited - UP
			{
				neighbours.push_back(maze[row - 1][col]); // Pushes back this element.
			}
			if (row < getRowCount() && !maze[row + 1][col].visited) // Checks that row is less than getRowCount function value AND is not visited for that specific tile. - DOWN
			{
				maze[row][col].visited = true;
				neighbours.push_back(maze[row + 1][col]);
			}
			if (col > 0 && !maze[row][col - 1].visited) // LEFT
			{
				neighbours.push_back(maze[row][col - 1]);
			}
			if (col < getColCount() && !maze[row][col + 1].visited) // RIGHT
			{
				neighbours.push_back(maze[row][col + 1]);
			}
			if (maze[row - 1][col].visited == true && maze[row + 1][col].visited == true && maze[row][col - 1].visited == true && maze[row][col + 1].visited == true)
			{
				neighbours.pop_back();
				auto nextcell = neighbours[rand() % neighbours.size()];

				switch (nextcell)
				{
				case 0:
					break;
				case 1:
					break;
				case 2:
					break
				case 3:
					break;
				}
			}
			else
			{

			}
	
		return neighbours;
	}
 // DONE?

string mazegenerator::IsVisitedTrue(int r, int c)
{
	string BOOL;
	if (maze[r][c].visited == false)
	{
		BOOL = "FALSE";
	}
	else if (maze[r][c].visited == true)
	{
		BOOL = "TRUE";
	}

	return BOOL;
}

string mazegenerator::toString() // Prints everything from generate function is a format of 'B' - Blocked and 'U' - Unblocked
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
			else if (maze[r][c].visited == true) // Else fill any space that does not meet requirements with U's
			{
				ss << "V";
			}
			else if (maze[r][c].blocked == false) // Else fill any space that does not meet requirements with U's
			{
				ss << "-";
			}
			

			ss << " "; // Print space between chars.
		}

		ss << "\n"; // Print new line after every row iteration
	}
	ss << "\n"; // Creates new line after everything if for loops have finished to give space below last row.

	return ss.str(); // returns all values of B/U
	system("pause");
}