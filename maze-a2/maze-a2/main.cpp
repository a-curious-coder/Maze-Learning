#include <iostream>
#include <string>
#include <ctime>
#include "mazegenerator.h"
using namespace std;

int main()
{
	srand(time(NULL)); // Referral for random num generator
	int rowCount = 21;
	int colCount = 21;
	char keypress;

	while (1)
	{
		// Clear screen and style
		system("cls");
		system("color 0a");
		// Title of game
		cout << "Maze Game\n" << endl;

		// Declaration of mazegenerator so I can use this classes functions
		mazegenerator generator;

		// Generate function takes rowCount, colCount and generates maze
		generator.Generate(rowCount, colCount);

		//Prints a text based representation of maze based on requirements in function
		cout << generator.toString();
		// Depending onkeypresse, it will either generate a new maze or quit program

		cin >> keypress;
		generator.KeyPress(keypress);

	}
	
	
	return 0;

}