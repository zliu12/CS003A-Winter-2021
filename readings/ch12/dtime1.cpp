/**
 * 12.1 Separate Compilation-Application/Driver File
 *
 * Copyright (c) [2021], Qichang.L
 */

/* 
*The file that contains the program (the main part) is often called the
*application file or driver file.
 */

#include "dtime.h"
#include <iostream>

int main() {
  DigitalTime clock, oldClock;

  std::cout << "Enter the time in 24-hour notation: ";
  std::cin >> clock;

  oldClock = clock;
  clock.advance(15);
  if (clock == oldClock) {
    std::cout << "Something is wrong.";
    std::cout << "You entered" << oldClock << std::endl;
    std::cout << "15 minutes later the time will be" << clock << std::endl;
  }
  clock.advance(2, 15);
  std::cout << "2 hours and 15 minutes after that\n" << "the time will be "
            << clock << std::endl;

  return 0;
}