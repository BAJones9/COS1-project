// DungeontoDungeon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
	std::cout << "Welcome to the Gauntlet\n";

	bool endloop = false;
	std::string userInput;

	while (!endloop)
	{
		std::cout << "1) Create a player\n2) Load Player\n3) Start playing: Enter the Gauntlet\n4) Exit\n\n Which would you like to choose";
		std::cin >> userInput;

		switch (stoi(userInput))
		{
		case 1:
			std::cout << "1 create player";
			//place for the create player method
			break;
		case 2:
			std::cout << "2 load player";
			//place for the load player method
			break;
		case 3:
			std::cout << "3 starting combat in the gaintlet";
			//starts combat method
			break;
		case 4:
			std::cout << "4 exit";
			//place any methods that need to be done before 
			endloop = true;
			break;


		default:
			std::cout << "That input was invalid, please try again.";		//message for invalid input
			break;
		}





	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
