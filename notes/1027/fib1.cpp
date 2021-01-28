/**
 * Recursion examples.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>

// uint64_t rounds after MAX
#define MAX 92

// Naive recursion, O(2^n) time complexity, O(n) space complexity
// Using uint64_t to maximize range of values
uint64_t fib1(int n) {
  // Base case, don't forget this or you will get an infinite loop
  if (n < 2) {
    return n;
  }

  return fib1(n - 1) + fib1(n - 2);
}

// Using memoizaton
// Keyword "auto" automatically deduces the type, still statically typed
auto vals = new uint64_t[MAX](); // The () at the end initializes values to 0
uint64_t fib2(int n) {
  // Always check for base case
  if (n < 2) {
    return n;
  }

  // Use cache
  if (vals[n] == 0) {
    // This expensive step runs only in case of cache miss
    vals[n] = fib2(n - 1) + fib2(n - 2);
  }
  return vals[n];
}

void error(const char *cmd) {
  // This prints to sederr (error stream) and not stdout(standard output)
  fprintf(stderr, "Usage: %s <+ve integer>\n", cmd);

  // By convention, anything other than 0 indicates failure
  exit(1);
}

// Note how the command line arguments are detected
int main(int argc, char *argv[]) {
  // Read n from command line
  int n;
  // sscanf() == 0 means the input doesn't match, it tells how many things are
  // successfully matched.
  // one %, if match then return 1, otherwise 0
  // short circuting, which if one of the condition fails, no need to check the 
  // rest of conditions then.
  if (argc < 2 || sscanf(argv[1], "%d", &n) == 0 || n < 0 || n > MAX) {
    error(argv[0]);
  }

  printf("fib2(%d) = %lu\n", n, fib2(n));
}