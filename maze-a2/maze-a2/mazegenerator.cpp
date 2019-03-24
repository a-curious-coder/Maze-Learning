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

	// Resize origin and inner vectors to desired sizes.
	maze.resize(rowCount);
	for (int i = 0; i < rowCount; i++)
	{
		maze[i].resize(colCount);
	}
	int row = 1;
	int col = 1;
	Tile& tile = maze[row][col];
	
	// Set default values for Tile attributes iterating through every 'Tile'
	for (int r = 0; r < maze.size(); r++)
	{
		for (int c = 0; c < maze[0].size(); c++)
		{
			tile.row = r;
			tile.col = c;
			tile.visited = false;
			tile.blocked = true;

		}
	}
	vector <Tile*> neighbours = getUnvisitedNeighbours(&tile, row, col);
	neighbours.push_back(&maze[1][1]);
	tile.blocked = false;
	tile.visited= false;
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
	//cout << "Number of Neighbours for [" << row << "," << col << "]: " << *neighbours.size() << "\n" << endl;
	//cout << "Neighbour\tRow\tCol\tVisited" << endl;
	
	

	while (!maze.empty())
	{
		//Get current tile
		Tile thisTile = maze.front().front();
		//Get unvisited neighbours

		if (!neighbours.empty())
		{
			getUnvisitedNeighbours(&tile, row, col);
			Tile nexttile = *neighbours[rand() % neighbours.size()];

			// Get wall between tiles
			int midRow = tile.row + (nexttile.row = tile.row) / 2;
			int midCol = tile.col + (nexttile.col = tile.col) / 2;
			Tile tileWall = maze[midRow][midCol];

			// Mark neighbour and wall cells as unblocked
			nexttile.blocked = false;
			tileWall.blocked = false;

			//Add neighbour to top of stack and mark visited
			neighbours.push_back(&nexttile);
			nexttile.visited = true;
		}
		else
		{
			maze.pop_back();
		}
	}
	

	
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

vector<Tile*> mazegenerator::getUnvisitedNeighbours(const Tile* tile, int row, int col)
{

	vector<Tile*> neighbours; // Vector to collect unvisited neighbours

	cout << "\n";
	
			if (row > 0 && !maze[row - 1][col].visited) // Checks if the row is more than 0 and not visited - UP
			{
				neighbours.push_back(&maze[row - 1][col]); // Pushes back this element.
			}
			if (row < getRowCount() && !maze[row + 1][col].visited) // Checks that row is less than getRowCount function value AND is not visited for that specific tile. - DOWN
			{
				neighbours.push_back(&maze[row + 1][col]);
			}
			if (col > 0 && !maze[row][col - 1].visited) // LEFT
			{
				neighbours.push_back(&maze[row][col - 1]);
			}
			if (col < getColCount() && !maze[row][col + 1].visited) // RIGHT
			{
				neighbours.push_back(&maze[row][col +1]);
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





// SCRAP CODE
/*
Generate function to find neighbour properties
for (int i = 0; i < neighbours.size(); i++)
	{
		cout << i+1 << "\t\t" << neighbours[i].row << "\t" << neighbours[i].col << "\t";
		maze[neighbours[i].row][neighbours[i].col].blocked = false;
		auto nextcell = neighbours[rand() % neighbours.size()];
		cout << IsVisitedTrue(neighbours[i].row, neighbours[i].col) << endl;
	}*/


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

/*
for (int r = 0; r < getRowCount(); r++)
	{
		row = row + 1;
		for (int c = 0; c < getColCount(); c++)
		{
			getUnvisitedNeighbours(&tile, row, col);
			cout << r << ", " << c  << "\t";
			col = col + 1;
		}

	}




cout << "\nNeighbours are represented by 'B'." << endl;
cout << "\n" << endl;
//TEST TO CHECK NEIGHBOURS
*/