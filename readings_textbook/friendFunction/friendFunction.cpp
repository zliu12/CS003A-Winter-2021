/**
 * 11.1 Friend Functions
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <iostream>

class DayofYear {
 public:
  // Precondition: theMonth and theDay form a possible date.
  // Initializes the date according to the arguments.
  DayofYear(int theMonth, int theDay);
  // Defacult consturctor declaration: initializes the date to January first.
  DayofYear();
  void input();
  void output();
  // Accessor: returns the month, 1 for Jan, 2 for Feb, etc
  int getMonth();
  // Accessor: return the day of the month
  int getDay();

 private:
  // Helper function
  void checkDate();
  int month;
  int day;
};

// Procondition: date1 and date2 have values.
// Returns true if date 1 and date2 represent the same date; otherwise returns
// false
// This is a nonmember function but it's possible to make equal a DayofYear
// member function. If you do, you must decide whether the calling object should
// be the first date or the second date (which must use the private member
// variables as the args).
// eg: bool equal(DayofYear month, DayofYear day);
bool equal(DayofYear date1, DayofYear date2);

int main() {
  // object today calls the default constructor, bachBirthday calls the
  // constructor DayofYear(int theMonth, int theDay)
  DayofYear today, bachBirthday(3, 21);

  std::cout << "Enter today's date:\n";
  today.input();
  std::cout << "Today's date is ";
  today.output();

  std::cout << "J. S. Bach's birthday is ";
  bachBirthday.output();

  if (equal(today, bachBirthday)) {
    std::cout << "Happy Birthday J. S.!\n";
  } else {
    std::cout << " Happy Unbirthday J. S.!\n";
  }

  return 0;
}

bool equal(DayofYear date1, DayofYear date2) {
  return (date1.getMonth() == date2.getMonth() &&
          date1.getDay() == date2.getDay());
}

// Definition of constructor
// Equivalent to:
// DayofYear::DayofYear(int theMonth, int theDay) {
//  month = theMonth;
//  day = theDay;
//  checkDate();
// }
DayofYear::DayofYear(int theMonth, int theDay) : month(theMonth), day(theDay) {
  checkDate();
}

int DayofYear::getMonth() {
  return month;
}

int DayofYear::getDay() {
  return day;
}

void DayofYear::input() {
  std::cout << "Enter the month as a number: ";
  std::cin >> month;
  std::cout << "Enter the day of the montn: ";
  std::cin >> day;
}

void DayofYear::output() {
  std::cout << "month = " << month << ", day = " << day << std::endl;
}

