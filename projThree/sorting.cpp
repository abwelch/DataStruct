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
void populateVector(std::vector<int> &, std::ifstream &, int);
void printVector(const std::vector<int> &);

int main()
{
	std::ifstream inputFile = openInputFile();
	// sorted will always be passed to algorithms then "reset" for new algorithms
	// by reassigning the contents of unsorted
	std::vector<int> unsorted, sorted;
	int elementsToSort = 0;
	std::cout << "Input the number of elements you wish to sort: ";
	std::cin >> elementsToSort;
	populateVector(unsorted, inputFile, elementsToSort);
	sorted = unsorted;

	// HEAP sort block
	std::cout << "Vector contents before heap sort: ";
	printVector(sorted);
	heapsort(sorted);
	std::cout << "Vector contents after heap sort: ";
	printVector(sorted);

	// MERGE sort block
	// reset sorted vector for new sort
	sorted = unsorted;
	std::cout << "Vector contents before merge sort: ";
	printVector(sorted);
	mergeSort(sorted);
	std::cout << "Vector contents after merge sort: ";
	printVector(sorted);

	// QUICK sort block
	// reset sorted vector for new sort
	sorted = unsorted;
	std::cout << "Vector contents before quick sort (no cutoff): ";
	printVector(sorted);
	quicksort(sorted);
	std::cout << "Vector contents after quick sort (no cutoff): ";
	printVector(sorted);

	// INSERT sort block
	// reset sorted vector for new sort
	sorted = unsorted;
	std::cout << "Vector contents before insertion sort (no cutoff): ";
	printVector(sorted);
	insertionSort(sorted);
	std::cout << "Vector contents after insertion sort (no cutoff): ";
	printVector(sorted);

	// Analyze runtimes
	clock_t start, stop;
	std::cout << "runtime of algorithms for N = 10,000 items: \n";

	// HEAP sort block
	std::cout << "Vector contents before heap sort: ";
	printVector(sorted);
	start = clock();
	heapsort(sorted);
	stop = clock();
	std::cout << "runtime: " << double(stop - start) / double(CLOCKS_PER_SEC) << std::endl;
	std::cout << "Vector contents after heap sort: ";
	printVector(sorted);

	// MERGE sort block
	// reset sorted vector for new sort
	sorted = unsorted;
	std::cout << "Vector contents before merge sort: ";
	printVector(sorted);
	start = clock();
	mergeSort(sorted);
	stop = clock();
	std::cout << "runtime: " << double(stop - start) / double(CLOCKS_PER_SEC) << std::endl;
	std::cout << "Vector contents after merge sort: ";
	printVector(sorted);

	// QUICK sort block
	// reset sorted vector for new sort
	sorted = unsorted;
	std::cout << "Vector contents before quick sort (no cutoff): ";
	printVector(sorted);
	start = clock();
	quicksort(sorted);
	stop = clock();
	std::cout << "runtime: " << double(stop - start) / double(CLOCKS_PER_SEC) << std::endl;
	std::cout << "Vector contents after quick sort (no cutoff): ";
	printVector(sorted);

	// INSERT sort block
	// reset sorted vector for new sort
	sorted = unsorted;
	std::cout << "Vector contents before insertion sort (no cutoff): ";
	printVector(sorted);
	start = clock();
	insertionSort(sorted);
	stop = clock();
	std::cout << "runtime: " << double(stop - start) / double(CLOCKS_PER_SEC) << std::endl;
	;
	std::cout << "Vector contents after insertion sort (no cutoff): ";
	printVector(sorted);

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
void populateVector(std::vector<int> &unsorted, std::ifstream &inputFile, int maxElements)
{
	int nextElement = 0, counter = 0;
	while (inputFile >> nextElement)
	{
		// Only populate amount of elements specified by user
		if (counter == maxElements)
			return;
		unsorted.push_back(nextElement);
		++counter;
	}
}

// PURPOSE: print the contents of the vector
void printVector(const std::vector<int> &printVec)
{
	for (std::vector<int>::const_iterator i = printVec.begin(); i < printVec.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}