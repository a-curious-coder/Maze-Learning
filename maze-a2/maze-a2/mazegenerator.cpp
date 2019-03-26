#ifdef TARGET_OS_MAC
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif
#include "mazegenerator.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <stack>
#include <ctime>
#include <thread>

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
			maze[r][c].row = r;
			maze[r][c].col = c;
			maze[r][c].visited = false;
			maze[r][c].blocked = true;

		}
	}

	stack<Tile*> stack;

	//Add tile to top of stack
	stack.push(&maze[row][col]);
	stack.top()->visited = true;
	stack.top()->blocked = false;
	
	while(!stack.empty())
	{
		//Get current tile
		Tile* thisTile = stack.top();
		
		//Get unvisited neighbours'
		vector <Tile*> neighbours = getUnvisitedNeighbours(*thisTile);

		if (!neighbours.empty())
		{
			//Get unvisited neighbour Tiles
			Tile* nexttile = neighbours[rand() % neighbours.size()];
			
			// Get wall between tiles
			int midRow = thisTile->row + (nexttile->row - thisTile->row) / 2;
			int midCol = thisTile->col + (nexttile->col - thisTile->col) / 2;
			Tile* tileWall = &maze[midRow][midCol];

			// Mark neighbour and wall cells as unblocked
			nexttile->blocked = false;
			tileWall->blocked = false;

			//Add neighbour to top of stack and mark visited
			stack.push(nexttile);
			nexttile->visited = true;
		}
		else
		{
			// Removes top most element | LIFO
			stack.pop();
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

vector<Tile*> mazegenerator::getUnvisitedNeighbours(Tile tile)
{

	vector<Tile*> neighbours; // Vector to collect unvisited neighbours

	int row = tile.row;
	int col = tile.col;

			if (row > 2 && !maze[row - 2][col].visited) // Checks if the row is more than 0 and not visited - UP
			{
				neighbours.push_back(&maze[row - 2][col]); // Pushes back this element.
			}
			if (row < getRowCount() -3 && !maze[row + 2][col].visited) // Checks that row is less than getRowCount function value AND is not visited for that specific tile. - DOWN
			{
				neighbours.push_back(&maze[row + 2][col]);
			}
			if (col > 2 && !maze[row][col - 2].visited) // LEFT
			{
				neighbours.push_back(&maze[row][col - 2]);
			}
			if (col < getColCount()-3 && !maze[row][col + 2].visited) // RIGHT
			{
				neighbours.push_back(&maze[row][col +2]);
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
	ss << "Maze Game\n"<< endl;

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
				// To actually print 'B' in real time
				cout << "B";
				mySleep(1);
			}
			else if (maze[r][c].blocked == false) // Else fill any space that does not meet requirements with U's
			{

				ss << " ";	
				// To actually print '-' in real time
				cout << "-";
				mySleep(1);
			}
			// Print space between chars.
			ss << " "; 
			cout << " ";
			mySleep(1);
		}
		ss << "\n"; // Print new line after every row iteration
		cout << "\n";
		mySleep(1);
	}
	ss << "\n"; // Creates new line after everything if for loops have finished to give space below last row.
	cout << "\n";
	system("cls");
	return ss.str(); // returns all values of B/U
	system("pause");
}

void mySleep(int sleepMs)
{
	#ifdef TARGET_OS_MAC
		usleep(sleepMs * 1000);
	#endif
	#ifdef WINDOWS
		Sleep(sleepMs);
	#endif
}
char mazegenerator::KeyPress(char keypress)
{
	Player player;
	player.x = 1;
	player.y = 1;
	player.symbol = 'P';

	switch (keypress)
	{
	case 'w':
		if (maze[player.x][player.y-1].blocked = true)
		{
			maze[player.x][player.y].blocked = false;
			player.y--;
			break;
		}
	case 's':
		if (maze[player.x][player.y + 1].blocked = true)
		{
			maze[player.x][player.y].blocked = false;
			player.y++;
			break;
		}
	case 'a':
		if (maze[player.x-1][player.y].blocked = true)
		{
			maze[player.x][player.y].blocked = false;
			player.x--;
			break;
		}
	case 'd':
		if (maze[player.x+1][player.y].blocked = true)
		{
			maze[player.x][player.y].blocked = false;
			player.x++;
			break;
		}
	case 'q':
		cout << "quit" << endl;
		break;
	
	case 'l': 
		// Prints out particular 'random' number for particular generated maze
		cout << "Seed: " << time(NULL) << endl;
		system("pause");
		
	}
	
	
	return 'a';
}

