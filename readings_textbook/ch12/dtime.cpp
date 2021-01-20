/**
 * 12.1 Separate Compilation-Implementation File
 *
 * Copyright (c) [2021], Qichang.L
 */

/*
*This is the implementation file that contains "dtime.h".
*Not required but it's a convention to give the interface file and the 
*implementation file the same name.
*Most time the file name suffix is .cpp, it could be .CPP/.CXX depends on sytem
 */

#include "dtime.h"
#include <iostream>
#include <cctype>
#include <cstdlib>

// Below func declarations are for use in the definition of the overloaded input
// operator>>
// Set theHour to the hour part of the time, 24-hour notation, colon has been
// disgarded, like 9:45 or 14:45
void readHour(std::istream& ins, int& theHour);
// Reads the minute from the stream ins after readHour hsa read the hour
void readMinute(std::istream& ins, int& theMinute);

// c is 0~9, returns the integer for the digit, eg: digitToint('3') returns 3.
int digitToint(char c);

bool operator==(const DigitalTime& time1, const DigitalTime& time2) {
  return (time1.hour == time2. hour && time1.minute == time2.minute);
}

// Uses iostream and cstdlib
DigitalTime::DigitalTime(int theHour, int theMinute) {
  if (theHour < 0 || theHour > 23 || theMinute < 0 || theMinute > 59) {
    std::cout <<"Illegal arg to DigitalTime constructor";
    exit(1);
  } else {
    hour = theHour;
    minute = theMinute;
  }
}

DigitalTime::DigitalTime() {
  hour = 0;
  minute = 0;
}

void DigitalTime::advance(int minutesAdded) {
  int grossMinutes = minute + minutesAdded;
  minute = grossMinutes % 60;
  int hourAdjustment = grossMinutes / 60;
  hour = (hour + hourAdjustment) % 24;
}

void DigitalTime::advance(int hoursAdded, int minutesAdded) {
  hour = (hour + hoursAdded) % 24;
  advance(minutesAdded);
}

// Use iostream
std::ostream& operator<<(std::ostream& outs, const DigitalTime& theObject) {
  outs << theObject.hour <<":";
  if (theObject.minute < 10) {
    outs << "0";
  }
  outs << theObject.minute;
  return outs;
}

// Use iostream
std::istream& operator>>(std::istream& ins, DigitalTime& theObject) {
  readHour(ins, theObject.hour);
  readMinute(ins, theObject.minute);
  return ins;
}

int digitToInt(char c) {
  return (static_cast<int>(c) - static_cast<int>('0'));
}

// Use iostream, cctype, and cstdlib
void readMinute(std::istream& ins, int& theMinute) {
  char c1, c2;
  ins >> c1 >> c2;

  if (!(isdigit(c1) && isdigit(c2))) {
    std::cout << "Error illegal input to readMinute\n";
    exit(1);
  }
  theMinute = (digitToInt(c1) * 10) + digitToInt(c2);
  if (theMinute < 0 || theMinute > 59) {
    std::cout << "Error illegal input to readMinute\n";
    exit(1);
  }
}

// Use iostream, cctype, cstdlib
void readHour(std::istream& ins, int& theHour) {
  char c1, c2;
  ins >> c1 >> c2;
  if (!(isdigit(c1) && (isdigit(c2) || c2 == ':'))) {
    std::cout << "Error illegal input to readHours\n";
    exit(1);
  }
  if (isdigit(c1) && c2 ==':') {
    theHour = digitToInt(c1);
  } else {  // (isdigit(c1) && isdigit(c2))
    theHour = (digitToInt(c1) * 10) + digitToInt(c2);
    ins >> c2;    // discard ':'
    if (c2 != ':') {
      std::cout << "Error illegal input to readHour\n";
      exit(1);
    }
  }
  if (theHour < 0 || theHour > 23) {
    std::cout << "Error illegal input to readHour\n";
    exit(1);
  }
}

