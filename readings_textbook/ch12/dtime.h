/**
 * 12.1 Separate Compilation-Header File
 *
 * Copyright (c) [2021], Qichang.L
 */

/*
TODO: ADTs Reviewed
*Abstrac Data Type (ADT):
*Programmer don't have access to the details of the type regards how the vals
*and operations are implemented.
*All the classes should be ADTs.
Separate the specification of how the class is used by a programmer from the
details of how the class is implemented.
You can change the implementation w/ needing to change any program tha uses the
class in any way.
3 rules to ensure the separation:
1.Make all the member vars private member of the class.
2.Make interface(basic operations for the ADT (the class))/interface file:
  a.Public member fuc of the class.
  b.Friend func.
  c.Ordinary func.
  d.Overloaded operator.
  e.Comments: specify how to use each such func or operator w/ the class or w/
              the func or operator declaration.
3.Make implementation(basic operations) unavailable to ADT users/implementation
  file:
  a.Func definition.
  b.Overloaded operator definitions.
  3.Helping funcs.
  4.Other additional item required.

*The best way in c++ to ensure to follow rules is to place the interface and the
*implementation of the ADT class in separate files.
 */

/* 
TODO: Private members are part of the implementation
!Issue: 
! The public part of the class definition for an ADT is part of the interface 
! for the ADT,but the private part is part of the implementation which c++ don't
! allow you to split the class definition accross two files.
?Compromise:
? Place the entire class definition in the interface file. (Programmer who uses
? the ADT class cannot use any of the private member of the class, the private
? member will still be hidden)
 */
#include <iostream>

class DigitalTime {
 public:
  // True if time1/time2 represent the same time, otherwise false
  friend bool operator==(const DigitalTime &time1, const DigitalTime &time2);

  // Initialize the time value to theHour and the Minute
  // Hour: 0~23, Minute: 0~59
  DigitalTime(int theHour, int theMinute);

  // Initialize the time value to 0:00(midnight)
  DigitalTime();

  // The obj has a time value then changed by adding minutes
  void advance(int minutesAdded);

  // The obj has a time value then changed by adding hours and minutes
  void advance(int hourseAddes, int minutesAdded);

  // Overloads the >> operator for input vals of type DigitalTime
  friend std::istream& operator>>(std::istream& ins, DigitalTime& theObject);

  // Overloads the << opertor for output vals of type DigitalTime
  friend std::ostream& operator<<(std::ostream& outs,
                                  const DigitalTime& theobject);

 private:
  // The word private indicates that this isn't part of the public interface
  // Ths is part of the implementation, not the interface
  int hour;
  int minute;
};

/* 
TODO: dtime.h
1.dtime.h is a header file.
2.The suffix .h indicates a file is a header file.
3.An interface file is always a header file and always w/ .h as suffix.
4.Directive #include "dtime.h" must be contained in any program uses the class
  DigitalTime.
5.Predefined header file uses <angular brackets>, <iostream>.
6.Header file programmer wrote uses "quotes", "dtime.h".
*/