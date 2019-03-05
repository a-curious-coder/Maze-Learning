#include <iostream>
#include <string>
#include <sstream>
#include "MazeGenerator.h"

using namespace std;

int main() 
{
	system("cls");
	cout << "Welcome to my maze program\n" << endl;

	MazeGenerator generator;
	generator.Generate(15, 15);
	std::cout << generator.toString();
	system("pause");
	return 0;
}