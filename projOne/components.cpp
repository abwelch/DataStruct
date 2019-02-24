/*
Andrew Welch <abw28@zips.uakron.edu> 2700340
Data Structures - Project 1
*/

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// prototypes
std::ifstream openInputFile();

int main()
{
	std::ifstream inputFile = openInputFile();
	inputFile.close();
	return 0;
}

// PURPOSE: prompts the user to enter a valid file name and returns an if object
// opened with the inputted file
std::ifstream openInputFile()
{
	std::ifstream inputFile;
	std::string inputtedFileName;
	do
	{
		std::cout << "Enter a file name to read and represent as a graph (include "
					 "extension): ";
		getline(std::cin, inputtedFileName);
		inputFile.open(inputtedFileName.c_str());
		if (!inputFile.is_open())
		{
			std::cout << "ERROR: inputted file does not exist!\n";
		}
	} while (!inputFile.is_open());
	return inputFile;
}

/*
        std::string content;
        while (getline(inputFile, content))
        {
                std::cout << content << std::endl;
        }
*/