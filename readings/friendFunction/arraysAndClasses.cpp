/**
 * TODO: Arrays and Classes
 *
 * Copyright (c) [2021], Qichang.L
 */

/*
Combine arrays, structs, classes to form structured types such as arrays of 
structs, arrays of classes, and classes w/ arrays as member vars.
 */

#include <iostream>

/*
TODO: Array of Classes
If you want each indexed var to contain items of diff types, make the array an
array of structs.*/
// declare the struct type
// struct WindInfo {
//  double velocity;    // miles/hour
//  char direction;     // "N", "S", "E", "W"
// };

// int main() {
//   WindInfo dataPoint[10];
//   int i = 0;

//   fill the array
//   for (; i < 10l; i++) {
//     std::cout << "Enter velocity for " << i << "numbered data point: ";
//     std::cin >> dataPoint[i].velocity;
//     std::cout << "Enter direction for taht data point"
//               << "(N, S, E, or W): ";
//     std::cin >> dataPoint[i].direction;
//   }

//   output the array
//   for (; i < 10; i++) {
//     std::cout <<"Wind data point number " << i << ":\n"
//               << dataPoint[i].velocity << " miles/hour\n" << "direction "
//               << dataPoint[i].direction << std::endl;
//   }
// }

class Money {
 public:
  friend Money operator+(const Money& amount1, const Money& amount2);
  friend Money operator-(const Money& amount1, const Money& amount2);
  friend Money operator-(const Money& amount);
  friend bool operator==(const Money& amount1, const Money& amount2);
  friend bool operator<(const Money& amount1, const Money& amount2);
  Money(int64_t dollars, int cents);
  explicit Money(int64_t dollars);
  Money();
  double getValue() const;
  friend std::istream& operator>>(std::istream& ins, Money& amount);
  friend std::ostream& operator<<(std::ostream& outs, const Money& amount);
 private:
  int64_t allCents;
};

int main() {
  Money amount[5], max;
  int i = 0;

  // input amount[i], set find the max amount
  std::cout << "Enter 5 amounts of money:\n";
  std::cin >> amount[0];
  max = amount[0];
  for (i = 1; i < 5; i++) {
    std::cin >> amount[i];
    if (max < amount[i]) {
      max = amount[i];
    }
  }
  std::cout << "The highest amount is: " << max << std::endl;

  // find the diff between amount[i] and max amount
  Money difference[5];
  for (; i < 5; i++) {
    difference[i] = max - amount[i];
  }

  // output the difference
  for (; i < 5; i++) {
    std::cout << amount[i] << " off by" << difference[i] << std::endl;
  }
  return 0;
}
/**
 * When an array of classes is declared, the default constructor is called to
 * intialize the indexed vars
 * !It's important to have a default constructor for any class that'll be the 
 * !base type of an array.
 * struct Score {
 *  int homeTeam, opponent;
 * };
 * Score game[10];
 * 
 * int main() {
 *  Money amount[5];
 *  int i = 0;
 *  std::cout << "Enter 5 amounts of money:\n";
 *  for (; i < 5; i++) {
 *    std::cin >> amount[i];
 *  }
 *  for (; i < 5; i++) {
 *    amount[i] += amount[i];
 *  }
 *  std::cout <<" After doubling, the amounts are:\n";
 *  for (;i < 5; i++) {
 *    std::cout << amount[i] << " " << std::endl;
 *  }
 *  return 0;
 * } 
  */

/* 
TODO: Array as Class Members
 */
// Array as a member var of a class or a struct
// struct myBest of type Data records a distantce and the times for each of ten
// practice tries.
// struct Data {
//   int distance;
//   double time[10];
// };
// Data myBest;
// myBest.distance = 20;    // Set the distance
// for (int i = 0; i < 10; i++) {
//   std::cout << "Enter 10 times (int seconds):\n";
//   std::cin >> myBest.time[i];
// }

/*
A class w/ an Array Member
 */
#include <cstdlib>
#include <cstdio>
const int MAX_LIST_SIZE = 50;

class TemperatureList {
 public:
  // Default constructor: initializes the obj to an empty list
  TemperatureList();
  //! Single-param constructor should be marked w/ explicit.
  //! explicit TemperatureList(double length);
  // Member funcs
  void addTemperature(double temperature);  // add temperature
  bool full() const;  // true if list's full, otherwise false
  // insertion operator << overloaded
  friend std::ostream& operator<<(std::ostream& outs,
                                  const TemperatureList& theObject);
 private:
  double list[MAX_LIST_SIZE];   // of temperatures in Fahrenheit
  int size;   // number of array positions filled
};

int main() {
  // obj of type TemperatureList is declared, calls the default constructor, and
  // the obj myData is initialized so that the member var size has the val 0,
  // indicating an empty list
  TemperatureList myData;
  // Add an item to the list of temperatures by calling the member func
  // addTemperature
  myData.addTemperature(77);
  return 0;
}

// Default constructor @ln144 definition, equivalent to:
// TemperatureList::TemperatureList() {
//   size = 0;
// }
TemperatureList::TemperatureList():size(0) {
}

// Member func definition
void TemperatureList::addTemperature(double temperature) {
  // If list is full(=50), output err msg, otherwise store to the
  // temperatureList, size increases by 1
  if (full()) {
    printf("Error: adding to a full list.\n");
    exit(1);
  } else {
    list[size] = temperature;
    size = size + 1;
  }
}

// Member func definition
bool TemperatureList::full() const {
  return (size == MAX_LIST_SIZE);
}

std::ostream& operator<<(std::ostream& outs, const TemperatureList& theObject) {
  for (int i = 0; i < theObject.size; i++) {
    outs << theObject.list[i] << "F\n";
    return outs;
  }
}