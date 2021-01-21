/**
 * 12.1 Separate Compilation
 * (dtime.h/dtime.cpp/dtime1.cpp)
 * Copyright (c) [2021], Qichang.L
 */

/* 
TODO: How to run the Digital Time program
*Basic idea: 
* Compile the implementation file(dtime.cpp), compile the application/driver
* file(dtime1.cpp) that contains the main part of the program.
No need to compile the interface file(dtime.h) b/c the contents of the interface
file are already cotained in each of the other two files by the directive:
#include "dtime.h".
The compiler views the "dtime.h" contents twice: once when compiling the imple-
mentation file, once when compiling the application file.
 */

/*
TODO: Linking the files by the linker
Connect implementation file and the driver file after compiling them so that 
they can work together, this is called linking, done by linker. You can run the
program after the files are linked. (Often done automatically as part of the
process of running the program) */

/* 
TODO: Advantages of separate files
Reuse the class since the definition and the implementation of the class are in
files separate from the driver file;
Only need to compile the implementation file once;
Implementation file(contains definition) is separated from the interface file
(contains declaration), so you can change the implementation file and will not 
need to change any program, will not even need to recompile the program, only
need to compile the implementation file and then relink.
 */

/*
TODO: Separate Files Summary
ADT class declaration and (definition and implementation) in separate files,
1.Interface file:
  a.suffix ".h".
  b.contains the definition of the class, declarations for any funcs and 
    overloaded opertors that define basic operations for the class but that are
    not listed in the class definition. Include comments about how the funcs and
    operators are used.
2.Implementation file:
  a.suffix ".cpp" (or similar)
  b.contains definition of all the funcs and overloaded operators (whether they
    are members or friend or neither).
  c.Must contain an include directive uses quote around the file name. "dtime.h"
  d.Traditionally have the same name w/ the implementation file.
  e.Compiled separated before it's used in any program.
3.Application/Driver file:
  a.contains the main part of the program, and any additional func definitions,
    const declarations, etc.
  b.Must contain an include dirctive naming the interface file. "dtime.h".
  c.Compiled separately from the implementation file.
  d.One pair of interface + implementaion files can serve many driver files.
  e.Link the obj code produced by compiling the driver file and the obj code
    produced by compiling the implementation file.
*/

/* 
TODO: .h vs .hpp
*.hpp file extention can distinguish the file as c++ from files of c.
*Some programmers put the implementation in the .hpp file, this is particularly
*the case for libraries consisting of templates and inline funcs.
 */

/* 
TODO: Implementation details
1.Overloaded func:
  a.void advance(int minuteAdded);
  b.void advance(int hoursAdded, int minutesAdded);
2.Helping func:
  a.void readHour(std::istream& ins, int& theHour);
  b.void readMinute(std::istream& ins, int& theMinute);
  c.Helping func of helping func:
    a.int digitToint(char c);
 */

/*
TODO: Resuable Components
An ADT class developed and coded into separate files is a software that can be
used in many different programs, so the resuability of a ADT class is an crucial
goal when designing software components.
A reusable component can be more reliable:
  1.Time and effort spent is more affordable since it'll be reused.
  2.If the component is used again and again, it's tested again and again.
 */

/* 
TODO: Avoiding Multiple Definitions
!Issue:
A program can be kept in more than three files. For instance, a program may use
several classes which may be kept in a separate pair of files. If a program 
spread across a number of files and more than one file has an include directive
for a class interface file (#include "dtime.h"). This can lead to a case where
a file contains the definitions in "dtime.h" more than once.
?Method:
Make a section of code to say "if you have already included this stuff once be4,
don't include it again.":
#define DTIME_H
The compiler's preprocessor puts DTIME_H on a list to indicate that DTIME_H has
been seen.
You can use another dirctive to test whether or not DTIME_H has been defined and
so test whether or not a section of code has already been processed:
#ifndef DTIME_H
!IF DTIME_H has been defined, then everything between #ifndef DTIME_H and the
!1st occurrence of #endif is skipped. 
#endif
It means if DTIME_H isn't defined, then the compiler processes everything up to
the next #endif.
(Since there's #ifndef, there's also #ifdef)
 */

#ifndef DTIME_H
#define DTIME_H
// Some code here
#endif    // DTIME_H
/*
If above code is in a file named dtime.h, then no matter how many times your 
program contains #include "dtime.h", the class will'be defined only one time. 
The first time #include "dtime.h" incurs the flag DTIME_H, next time the 
compiler sees it again, #ifndef DTIME_H says to skip everything up to #endif, so
the class isn't defined again.
!Covention of the flag name:
  Use the name of the file written in all uppercase letters w/ the underscore 
  used in place of the period.
 */

/* 
TODO: #pragma once
Non-standard but supported by most c++ compiler
It causes the source file to be included only once in ompilation when added at
the top of the file. It's sometimes used in place of the #ifndef construct.
 */