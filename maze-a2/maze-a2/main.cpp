#include <iostream>
#include <string>
#include "mazegenerator.h"
using namespace std;

int main()
{
	int rowCount = 15;
	int colCount = 15;
	while (1)
	{
		system("cls");
		system("color 0a");
		char quit;

		cout << "Welcome to my program\n" << endl;

		mazegenerator generator;
		generator.Generate(rowCount, colCount);
		cout << generator.toString();
		generator.getUnvisitedNeighbours(rowCount, colCount);

		cin >> quit;
		if (quit == 'Q' || quit == 'q')
		{
			break;
		}
		else 
		{
			cout << "\n\n\END";
			system("pause");
		}
	}
	
	
	return 0;

}