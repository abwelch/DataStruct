// Andrew Welch	2700340	abw28@zips.uakron.edu

// Prompts user to input a file name and then generates a vector of integers using the file
// Utilizes a variety of sorts on the vector

#include <iostream>
#include <fstream>
#include <ctime>

#include "insertsort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"

// prototypes
std::ifstream openInputFile();
void populateVector(std::vector<int> &, std::ifstream &);
void printVector(const std::vector<int> &);

int main()
{
	clock_t start, stop;
	std::ifstream inputFile = openInputFile();
	// sorted will always be passed to algorithms then "reset" for new algorithms
	// by reassigning the contents of unsorted
	std::vector<int> unsorted, sorted;
	int elementsToSort = 0;
	std::cout << "Input the number of elements you wish to sort: ";
	std::cin >> elementsToSort;
	populateVector(unsorted, inputFile);
	sorted = unsorted;
	std::cout << "Contents before heap sort: ";
	printVector(unsorted);

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
		std::cout << "Please enter the filename (include "
					 "extension): ";
		getline(std::cin, inputtedFileName);
		inputFile.open(inputtedFileName.c_str());
		if (!inputFile.is_open())
		{
			std::cout << "ERROR: inputted filename does not exist!\n";
		}
	} while (!inputFile.is_open());
	std::cout << inputtedFileName << " successfully opened!\n";
	return inputFile;
}

// PURPOSE: takes the opened input file stream and empty vector and populates the vector
void populateVector(std::vector<int> &unsorted, std::ifstream &inputFile)
{
	int nextElement = 0;
	while (inputFile >> nextElement)
		unsorted.push_back(nextElement);
}

// PURPOSE: print the contents of the vector
void printVector(const std::vector<int> &printVec)
{
	for (std::vector<int>::const_iterator i = printVec.begin(); i < printVec.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}