/*
Andrew Welch <abw28@zips.uakron.edu> 2700340
Data Structures - Project 1
*/

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

// prototypes
std::ifstream openInputFile();
std::list<int>::iterator find_gt(std::list<int>::iterator,
								 std::list<int>::iterator, int);
void buildAdjList(std::ifstream &, std::vector<std::list<int>> &);
void printAdjList(std::vector<std::list<int>> &);

int main()
{
	// Vector of integer lists called adjList for adjacency list
	std::vector<std::list<int>> adjList;
	std::ifstream inputFile = openInputFile();
	// Populate adjList with elements within inputFile
	buildAdjList(inputFile, adjList);
	printAdjList(adjList);
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
		std::cout << "Enter a graph filename to process (include "
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
	// If the list is empty
	if (start == stop)
	{
		return start;
	}
	while (start != stop)
	{
		if (*start > x)
		{
			return start;
		}
		++start;
	}
	// If x is greater than all elements in list, return iterator to final
	// position in list
	return stop;
}
// PURPOSE: Populates adjList with int values (stored in lists) from the
// inputFile
void buildAdjList(std::ifstream &inputFile,
				  std::vector<std::list<int>> &adjList)
{
	// Create a list object to push onto adjList so adjList is not empty when loop
	// begins for populating
	std::list<int> x;
	adjList.push_back(x);
	int vecPosition = 0, convertedValue;
	std::list<int>::iterator listPosition, start, stop;
	std::string fileLine;
	while (getline(inputFile, fileLine))
	{
		std::istringstream lineStream(fileLine);
		// Reads int values from lineStream
		while (lineStream >> convertedValue)
		{
			start = adjList[vecPosition].begin();
			stop = adjList[vecPosition].end();
			listPosition = find_gt(start, stop, convertedValue);
			// Insert converted value in position before listPosition
			adjList[vecPosition].insert(listPosition, convertedValue);
		}
		// Create a new list to begin populating on next loop iteration
		std::list<int> newList;
		adjList.push_back(newList);
		// Update position of vector
		++vecPosition;
	}
	// To compensate for adding a final list that will not receive any values
	adjList.pop_back();
}

// PURPOSE: output the contents of the adjList
void printAdjList(std::vector<std::list<int>> &adjList)
{
	std::cout << "The adjacency list for your graph is: \n";
	for (int i = 0; i < adjList.size(); ++i)
	{
		std::cout << "list" << i << ": ";
		for (std::list<int>::iterator begin = adjList[i].begin();
			 begin != adjList[i].end(); ++begin)
		{
			std::cout << *begin << " ";
		}
		std::cout << std::endl;
	}
}
