#include <iostream>
#include <string>
#include <ctime>
#include "mazegenerator.h"
using namespace std;

int main()
{
	srand(time(NULL)); // Referral for random num generator
	int rowCount = 15;
	int colCount = 15;
	while (1)
	{
		system("cls");
		system("color 0a");
		char quit;
		cout << "Maze Game" << endl;

		mazegenerator generator;
		generator.Generate(rowCount, colCount);
		cout << generator.toString();

		cin >> quit;
		if (quit == 'Q' || quit == 'q')
		{
			break;
		}
		else 
		{
			system("pause");
		}
	}
	
	
	return 0;

}