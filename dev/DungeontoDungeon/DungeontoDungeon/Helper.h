#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
//#include <string>
namespace Helper
{
	// integerValidation(), printIntegerBinary, Bubbleosrt required
	// all methods must be static
	//5 functions minimum
	//test functions by calling them in main
	//tests for functions after 5 is not required but encouraged

	static bool IntegerValidation(const char* intInput)
	{
		//Description: Validates that the parameter is a valid integer. 
		// It should accept a char* as input, converting the input 
		// into an integer and ensuring the input is valid. 
		// If the input is not a valid integer, it will return false.
		//char testInput[50];
		//strcpy_s(testInput, sizeof(testInput), intInput);

		bool result = true;		//initilizaes return variable

		//runs through the characters of the array and uses std::isdigit method to determine if each character is one of 0123456789
		// sets return variable to false if any of the characters in the array aren't a digit
		// this should detect any alphabet characters along with any decimal points to eliminate any float or alphabetical characters from being counted
		if (intInput[0] == '-')	//checks if the first character is negative
		{
			for (int i = 1; i < strlen(intInput); i++)
			{
				if (std::isdigit(intInput[i]) == 0)
					result = false;
			}
		}
		else
		{
			for (int i = 0; i < strlen(intInput); i++)
			{
				if (std::isdigit(intInput[i]) == 0)
					result = false;
			}
		}
		
		//if (result)
		//	printf("Is %s an integer: Yes \n", intInput);
		//else
		//	printf("Is %s an integer: No \n", intInput);

		return { result };


		
	}

	static void PrintIntegerBinary(int* num)
	{
		//Description: Prints the binary representation of an integer passed as a pointer.
		//This function must print all 32 bits of the passed in integer

		int numToBit = *num;		//dereferences pointer in order to use in the function below
		std::vector<int> bits;		//vector to store bit values in the form of integers and print out later

		for (int i = 0; i < 32; i++)	//runs modulus 2 on the integer, saves the value to bits vector, then right shifts to move to the next bit in the integer
		{
			bits.push_back(numToBit % 2);
			numToBit = (numToBit >> 1);
		}
		printf("%i in binary: ", *num); //prints the input integer to show input to conversion in console
		for (int i = 31; i > -1; i--)		//for loop to print out bit values in proper order
		{
			printf("%i", bits[i]);
		}
		printf("\n");

	}

	static void BubbleSort(int* arr, int size)	//(pointer to the array and its size).
	{
		//Description: Implements the bubble sort algorithm to sort an 
		//array of integers. It should take the array and its size as 
		// parameters and sort the array in ascending order.
		for (int i = 0; i < size; i++)
		{
			if (i == 0)
				printf("Original Array:  %i", arr[i]);	//different to prevent the print of the array starting with a comma
			else
				printf(", %i", arr[i]);
		}
		printf("\n");

		bool swap;		//boolean to tell if the sorting is finished
		int flexSize = size;	//size that can be modified so the original size can be used for printing
		do
		{
			swap = false;
			for (int i = 1; i <= flexSize - 1; i++) //cycles through elements of the int array and moves an element up in the array if the element in front of it is smaller
			{
				if (arr[i - 1] > arr[i])
				{//swaps the position of elements in the array and records a swap happened to continue the while loop
					int temp = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = temp;
					swap = true;
				}
			}
			--flexSize;	//shrinks the for loop iterations so the same two elements aren't compared twice
		} while (swap); //ends the while loop once no swaps are detected

		for (int i = 0; i < size; i++) //prints out the elements of the array
		{
			if (i == 0)
				printf("Sorted array:  %i", arr[i]);	//different to prevent the print of the array starting with a comma
			else
				printf(", %i", arr[i]);
		}
		printf("\n");
	}

	static void ClearConsoleWindow()
	{
		//Description: Clears the entire console window to provide a clean slate 
		// for the user interface. This can be used when the program needs to 
		// reset its output or prompt the user for new input without clutter.
		std::cin.clear();
		system("cls");
	}

	static void PauseConsoleWindow()
	{
		system("pause");
	}

	static bool isPositiveInteger(char* intInput)
	{
		bool result;
		if (IntegerValidation(intInput) == true)
		{
			int numInput = atoi(intInput);
			
			if (numInput > 0)
				result = true;
			else
				result = false;
		}
		else
			result = false;

		if (result)
			printf("Is %s a positive integer: Yes \n", intInput);
		else
			printf("Is %s a positive integer: No \n", intInput);

		return result;
	}

	static void PauseAndClearConosle()
	{
		PauseConsoleWindow();
		ClearConsoleWindow();
	}
	
	static void ClearInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	//GetMenuChoice
	static unsigned int GetMenuChoice(unsigned int _min, unsigned int _max)
	{
		unsigned int userInput;
		

		do
		{
			//std::cout << "Which option would you like to select?";
			std::cin >> userInput;
			if (userInput < _min or userInput > _max)
				std::cout << "\nThat input was not valid.\nPlease select again ";
			ClearInputBuffer();

		} while (userInput < _min or userInput > _max);

		return userInput;
	}
	/*
	GetMenuChoice
    Description: will ask the user what menu option they want, takes in the user input, and validates that the input is within the range of min and max. If is in the range then it will return the user's input.

        Example parameters: unsigned int min and unsigned int max.

        Return type: unsigned int (which menu option the user selected)
	*/


	static int RandomNumberGenerator(int minInput = 0, int maxInput = 2000000000)
	{
		time_t myTime;
		time_t* myTimeptr = &myTime;
		srand(time(myTimeptr));
		int random = rand();	//keeps returning 41 on the first call for some reason, not sure why, yet
		int randomInt = minInput + (random % (maxInput - minInput));	

		return{ randomInt };
	}
	
	static void PrintIntegerHex(int* intPoint)			//later exercise use the method itoa and see how that can be used to make the string how you want
	{
		int intInput = *intPoint;
		int intOutput = *intPoint;
		std::vector<int> fourBits;
		char intToHex[9] = "00000000";
		int j = 0;

		for (int i = 0; i < 32; i = i + 4)
		{
			fourBits.push_back(intInput % 16);
			intInput = (intInput >> 4);
		}
		
		for (int i = fourBits.size() - 1; i > -1; i--)
		{
			switch (fourBits[i])
			{
			case 10:
				intToHex[j] = 'A';
				break;
			case 11:
				intToHex[j] = 'B';
				break;
			case 12:
				intToHex[j] = 'C';
				break;
			case 13:
				intToHex[j] = 'D';
				break;
			case 14:
				intToHex[j] = 'E';
				break;
			case 15:
				intToHex[j] = 'F';
				break;
			default:
				intToHex[j] = 48 + fourBits[i];
				break;
			}
			j++;
		}
		printf("%i in Hexadecimal format is %s \n", intOutput, intToHex);
	}

	static void PrintIntegerOct(int* intPoint)
	{
		int intInput = *intPoint;
		int intOutput = *intPoint;
		std::vector<int> threeBits;
		char intToOct[16];
		int j = 0;

		for (int i = 0; i < 32; i = i + 3)
		{
			threeBits.push_back(intInput % 8);
			intInput = (intInput >> 3);
		}

		for (int i = threeBits.size() - 1; i > -1; i--)
		{
			intToOct[j] = 48 + threeBits[i];
			j++;
		}
		intToOct[j] = 0;
		printf("%i in octal format is %s \n", intOutput, intToOct);

	}

	//UserInputBool

	//IntegerSwap

	//IsEven

	//GetMaxValue

	//GetMinValue

	//ClampInteger

	//IsPrime

	//UserInputChar

	//ValidateRange

	//SafeDivide

	//VectorSum

	//garret methods
}






