/*
Andrew Welch
*** File provided by class website ***
DESCRIPTION: Specifies the functions and members for the DisjSets class
*/

#ifndef DISJ_SETS_H
#define DISJ_SETS_H

// DisjSets class
// Taken from Dr. Weiss material.
// Students will need to code required functionality.
// No error checking is performed in the already written code so use caution.

#include <vector>

class DisjSets
{
public:
  explicit DisjSets(int numElements);
  // int find( int x ) const;

  int find(int x); // you will write code per problem 8.16a in our book

  void unionSets(int root1, int root2); // Dr. Weiss did this code already

  // you will write code for isConnected
  // this function returns true of n1 and n2 are in the same connected compent
  bool isConnected(int n1, int n2);

private:
  std::vector<int> s;
};

#endif