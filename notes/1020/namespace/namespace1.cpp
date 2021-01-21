/**
 * Using namespace.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <iostream>

// Don't do this brings all names into scope
using namespace std;

// Slightly better b/c only pulling out the namespace you care about
using std::cout; 
using std::endl;

int main() {
  // Recommended: use full namespace to reference
  std::cout << "Using full namespace, recommended" << std::endl;

  // Can cause name clashes since there isn't namespace specified
  cout << "Not recommended" << endl;
}