/*
Andrew Welch
DESCRIPTION: Driver program which includes main and an input validation function
*/

#include "DisjSets.h"
#include "maze.h"

void obtainValidMazeParameters(int &, int &);

int main() {
  int columns = 0, rows = 0;
  obtainValidMazeParameters(rows, columns);
  maze mazeInstance(rows, columns);
  DisjSets sets(rows * columns);
  int n1, n2;
  // Iterate while first element is not connected to last
  while (!sets.isConnected(0, (rows * columns) - 1)) {
    mazeInstance.printMaze();
    std::cout << "Enter first neighbor: ";
    std::cin >> n1;
    std::cout << "Enter second neighbor: ";
    std::cin >> n2;
    if (mazeInstance.neighbors(n1, n2)) {
      std::cout << "Smashing wall between " << n1 << " and " << n2 << std::endl;
      mazeInstance.smashWall(n1, n2);
      mazeInstance.smashWall(n2, n1);
      sets.unionSets(n1, n2);
    } else {
      std::cout << n1 << " and " << n2
                << " are not neighbors. No wall smashed.\n";
    }
  }
  mazeInstance.printMaze();
  std::cout << std::endl << "The maze is built. Finished!\n";
  return 0;
}

void obtainValidMazeParameters(int &rows, int &columns) {
  // Row input validation block
  std::cout << "How many rows in your maze (greater than 1)? ";
  do {
    std::cin >> rows;
    if (rows <= 1)
      std::cout << "INVALID: User input must be an integer greater than 1.\n"
                << "How many rows in your maze (greater than 1)? ";
  } while (rows <= 1);
  // Column input validation block
  std::cout << "How many columns in your maze (greater than 1)? ";
  do {
    std::cin >> columns;
    if (columns <= 1)
      std::cout << "INVALID: User input must be an integer greater than 1.\n"
                << "How many columns in your maze (greater than 1)? ";
  } while (columns <= 1);
}