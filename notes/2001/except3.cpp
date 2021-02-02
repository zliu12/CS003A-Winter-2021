/**
 * Exceptions, catching and then rethrowing a different 
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <cstdio>
#include <climits>
#include <cstdlib>

enum class Error {
  INVALID_INPUT, OUT_OF_MEMORY, DIVIDE_BY_ZERO
};

class Read {
 private:
  int a() {
    try {
    return b();

    // Catch one type of exception and throw anther type
  } catch (const char *msg) {
    throw Error::INVALID_INPUT;
    }
  }

  int b() {
    // Exception propagates upward automatically
    return c();
  }

  int c() {
    int i;
    if (scanf("%d", &i) == 0) {
      throw "invalid input";
    }
    return i;
  }

 public:
  // Read int value from stdin
  // Throws Error type exception
  int readInt() {
    return a();
  }
};


int main() {
  Read r1;
  int i1;

  try {
    int i1 = r1.readInt();  
  } catch (int err) {
    // Do whatever is necesarry for handling errors
    fprintf(stderr, "error code %d reading value\n", int(err));
    exit(1);
  }
  printf("i1 = %d\n", i1);
}