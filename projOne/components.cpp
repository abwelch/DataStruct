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
std::list<int>::iterator find_gt(std::list<int>::iterator,
								 std::list<int>::iterator, int);
std::vector<std::list<int>> buildAdjList(std::ifstream &);

int main()
{
	// Vector of integer lists called adjList for adjacency list
	std::vector<std::list<int>> adjList;
	// Initial file operations for opening and displaying
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
		std::cout << "Enter a graph filename to prcess (include "
					 "extension): ";
		getline(std::cin, inputtedFileName);
		inputFile.open(inputtedFileName.c_str());
		if (!inputFile.is_open())
		{
			std::cout << "ERROR: inputted file does not exist!\n";
		}
	} while (!inputFile.is_open());
	std::cout << inputtedFileName << " successfully opened!\n";
	return inputFile;
}

// PURPOSE: iterates through a list and returns an iterator to the first element
// greater than x
std::list<int>::iterator find_gt(std::list<int>::iterator start,
								 std::list<int>::iterator stop, int x)
{
	for (start; start != stop; ++start)
	{
		if (*start > x)
		{
			return start;
		}
	}
}

std::vector<std::list<int>> buildAdjList(std::ifstream &inputFile)
{
	std::vector<std::list<int>> adjList;
	char value;
	int position = 0, convertedValue;
	while (std::cin >> value)
	{
		// Restart loop to receive a nonblank value
		if (value == ' ')
		{
			continue;
		}
		// Denotes the end of a line of integers in the file
		else if (value == '\n')
		{
			++position;
			continue;
		}
		else
		{
			convertedValue = value - '0';
			adjList[position].push_back(convertedValue);
		}
	}

	return adjList;
}
