/**
 * Check for palindromes using recursion.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <iostream>
#include <cstdio>
#include <cstring>

#define SIZE 0x100

/**
 * isPali checks if given string is a palindrome.
 * - s: string to check, never null
 * - n: length of the string, always >= 0
 */
bool isPali(const char *s, int n) {
  // Base case, don't forget this!
  if (n < 2) {
    return true;
  }

  if (s[0] != s[n - 1]) {
    return false;
  }
  return isPali(s + 1, n - 2);
}

int main() {
  char s[SIZE];
  // Not &s b/c char s[SIZE] is already a pointer
  // Loop ends when there's no more input (e.g., w/ ctrl + D on BASH shell)
  while (scanf("%s", s) > 0) {
    printf("%s\n", isPali(s, strlen(s)) ? "Palindrome" : "Not palindrome");
  }
}