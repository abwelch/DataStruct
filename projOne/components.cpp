/*
Andrew Welch <abw28@zips.uakron.edu> 2700340
Data Structures - Project 1

DESCRIPTION: generates a vector of integer lists that are populated with values
read in from a user inputted file. User selects lists to attempt and merge.
Successful merges result in removal of the smaller list.
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
bool connComponent(const std::list<int> &, const std::list<int> &);
bool merge2(std::list<int> &, std::list<int> &);
bool validateListInputs(int &, int &, const std::vector<std::list<int>> &);

int main()
{
	// Vector of integer lists called adjList for adjacency list
	std::vector<std::list<int>> adjList;
	std::ifstream inputFile = openInputFile();
	// Populate adjList with elements within inputFile
	buildAdjList(inputFile, adjList);
	int listInputOne = 0, listInputTwo = 0;
	do
	{
		printAdjList(adjList);
		// Value of -1 was inputted
		if (!validateListInputs(listInputOne, listInputTwo, adjList))
		{
			break;
		}
		// Determine if inputs correspond to lists with shared vertices
		if (connComponent(adjList[listInputOne], adjList[listInputTwo]))
		{
			// Determine if merge of shared vertice lists was successful
			if (merge2(adjList[listInputOne], adjList[listInputTwo]))
			{
				std::cout << "The lists are merged.\n";
				// Find the empty list and remove from vector
				for (int i = 0; i < adjList.size(); ++i)
				{
					if (adjList[i].empty())
					{
						adjList.erase(adjList.begin() + i);
					}
				}
			}
			else
			{
				std::cout << "ERROR: Merge unsuccessful!\n";
			}
		}
		else
		{
			std::cout << "The inputted list ids do not share any vertices!\n";
		}
		std::cout << std::endl;
	} while (adjList.size() != 1);
	std::cout << "Program terminated.\n";
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
	// To compensate for adding a final list that did not receive any values
	if (adjList[vecPosition].empty())
	{
		adjList.pop_back();
	}
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

// PURPOSE: if there is a common element in both lists, return true otherwise
// false assumes lists are sorted in ascending order and elements are unique
bool connComponent(const std::list<int> &L1, const std::list<int> &L2)
{
	// int L1size = L1.size(), L2size = L2.size();
	std::list<int>::const_iterator L1iter = L1.begin(), L2iter = L2.begin();
	while ((L1iter != L1.end()) && (L2iter != L2.end()))
	{
		// Common element
		if (*L1iter == *L2iter)
		{
			return true;
		}
		// If l1 element is greater than l2 element, we move onto next l2 element
		else if (*L1iter > *L2iter)
		{
			++L2iter;
		}
		// If l2 element is greater than l1 element, we move onto next l1 element
		else
		{
			++L1iter;
		}
	}
	// The loop is exhausted by either L1 or l2 reaching its final element without
	// a match
	return false;
}

// PURPOSE: determines which list will be merged within the other, then deletes
// duplicates from the merged list, and returns true if merge was sucessful.
bool merge2(std::list<int> &L1, std::list<int> &L2)
{
	if (connComponent(L1, L2))
	{
		if (L1.size() > L2.size())
		{
			L1.merge(L2);
			// Unique properly deletes all duplicates bc the list is sorted
			L1.unique();
			return true;
		}
		// If L2 is greater or equivalent sizes: merge L1 into L2
		else
		{
			L2.merge(L1);
			L2.unique();
			return true;
		}
	}
	return false;
}

// PURPOSE: prompt user to enter to ints corresponding to lists for potential
// merge. Validates inputs and returns true if they are valid or false if user
// enters -1
bool validateListInputs(int &inputOne, int &inputTwo,
						const std::vector<std::list<int>> &adjList)
{
	std::string userInputString;
	do
	{
		std::cout
			<< "Enter two list ids to potentially merge together or -1 to quit: ";
		getline(std::cin, userInputString);
		std::istringstream lineStream(userInputString);
		lineStream >> inputOne;
		if (inputOne == -1)
		{
			return false;
		}
		lineStream >> inputTwo;
		if (inputOne > adjList.size() - 1 || inputOne < -1 ||
			inputTwo > adjList.size() - 1 || inputTwo < 0)
		{
			std::cout << "ERROR: an invalid value has been entered!\n";
		}
	} while (inputOne > adjList.size() - 1 || inputOne < -1 ||
			 inputTwo > adjList.size() - 1 || inputTwo < 0);
	return true;
}