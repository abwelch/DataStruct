/*
Andrew Welch
DESCRIPTION: Provides implementation of functions within the maze class
*/

#include "maze.h"

// Construct the maze
maze::maze(int r, int c) : row(r), col(c) {
  // Special initialization for firstcell
  theMaze.push_back(mazeCell(false, true, false, true));
  // Initialize maze between first and last cell
  for (int i = 0; i < ((row * col) - 2); ++i) {
    theMaze.push_back(mazeCell());
  }
  // Special initialization for last cell
  theMaze.push_back(mazeCell(true, false, true, false));
}

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const {
  // Check if neigh is to the left of cell
  // If cell % col equals 0, cell and neigh are on diff rows
  if ((cell - 1 == neigh) && (cell % col != 0)) {
    return true;
  }
  // Check if neigh is to the right of cell
  else if ((cell + 1 == neigh) && (neigh % col != 0)) {
    return true;
  }
  // Check if neigh is below cell
  else if (cell + col == neigh) {
    return true;
  }
  // Check if neigh is above cell
  else if (cell - col == neigh) {
    return true;
  }
  // cell and neigh are not neighbors
  else {
    return false;
  }
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall(int cell, int neigh) {
  // Smash left cell wall
  if ((cell - 1 == neigh) && (cell % col != 0)) {
    theMaze[cell].setLeft(false);
  }
  // Smash right cell wall
  else if ((cell + 1 == neigh) && (neigh % col != 0)) {
    theMaze[cell].setRight(false);
  }
  // Smash top cell wall
  else if (cell - col == neigh) {
    theMaze[cell].setTop(false);
  }
  // Smash bottom cell wall
  else if (cell + col == neigh) {
    theMaze[cell].setBot(false);
  }
  return;
}

// print the maze
void maze::printMaze() {
  // Start print to the left on first row to accommodate for first cell open
  std::cout << "    ";
  // Print top of first row
  for (int i = 0; i < col - 1; ++i)
    std::cout << "__ ";
  std::cout << std::endl;
  // Print remainder of maze based upon conditions
  for (int i = 1; i <= row * col; ++i) {
    // Begin with left wall
    if (theMaze[i - 1].getLeft() && i != 1) {
      std::cout << "|";
    } else {
      std::cout << " ";
    }
    // Determine if there is a bottom
    if (theMaze[i - 1].getBot()) {
      std::cout << "__";
    } else {
      std::cout << "  ";
    }
    // Right wall at end of each row bc it cannot be smashed bc no neighbor to
    // right Newline at end of each row
    if (i % col == 0 && (i != row * col))
      std::cout << "|" << std::endl;
  }
  std::cout << std::endl;
}