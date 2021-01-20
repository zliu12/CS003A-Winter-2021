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

  bool before(DayofYear date1, DayofYear date2);

  // friend func declaration
  friend bool after(DayofYear date1, DayofYear date2);

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
// eg: bool equal(DayofYear firstDate, DayofYear SecondDate);
bool equal(DayofYear date1, DayofYear date2);

// friend func @ln26 definition
bool after(DayofYear date1, DayofYear date2) {
  return (date1.month > date2.month || (date1.month == date2.month &&
          date1.day > date2.day));
}

int main() {
  // object today calls the default constructor
  DayofYear today;
  // bachBirthday calls the constructor DayofYear(int theMonth, int theDay)
  DayofYear bachBirthday(3, 21);

  std::cout << "Enter today's date:\n";
  today.input();
  std::cout << "Today's date is ";
  today.output();

  std::cout << "J. S. Bach's birthday is ";
  bachBirthday.output();

  // Using "helper" func equal to test two objs of type DayofYear
  if (equal(today, bachBirthday)) {
    std::cout << "Happy Birthday J. S.!\n";
  } else {
    std::cout << " Happy Unbirthday J. S.!\n";
  }

  return 0;
}

// "Helper" func equal uses "accessor" func getMonth() and getDay() to compare
bool equal(DayofYear date1, DayofYear date2) {
  //! Another way to define, simpler, more efficient but illegal b/c month & day
  //! are private vars, only member func can "use" them.
  //! return (date1.month == date2.month && date1.day == date2.day);
  return (date1.getMonth() == date2.getMonth() &&
          date1.getDay() == date2.getDay());
}

bool before(DayofYear date1, DayofYear date2) {
  // date1.month comes after date2.month
  if (date1.getMonth() > date2.getMonth()) {
    return false;
  } else if (date1.getMonth() == date2.getMonth()) {
    // date1.month is the same w/ date2.month
    // but date1.day comes after date2.day
    if (date1.getDay() > date2.getDay()) {
      return false;
    }
  }
  return true;
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

/**
 * Friends can access private members, so definition @ln70 is illegal unless
 * the func equal is a "friend" of the class DayOfYear.
 * A friend func of a class isn't a member func, but has access to the private
 * member of that class.
 * Can directly read the value of member vars and change'em by "=".
 * Must name it as a friend in the class definition.
 * eg:
 *  Keyword friend at the beginning, declared inside of the class definition
 *  Below, the equal definition is legal
 *  friend bool equal(DayOfYear date1, DayOfYear date2);
 *  ...Other code here...
 *  bool equal(DayOfYear date1, DayOfYear date2) {
 *    return (date1.month == date2.month && date1.day == date2.day); 
 *  }
 * 
 * Friend func defined and called exaclty like the ordinary function.
 * Friend func equal(DayOfYear date1, DayOfYear date2) definition doesn't inlude
 * the qualifier DayOfYear::(included for member funcs), so cannot be called by 
 * using the dot operator.
 * A friend func can access the private member vars/funcs of the class by name,
 * just like the member funcs
 */

/**
 * In most situations, the only reason to make a func a friend is to make the
 * definition of the func simpler and more efficient.
 * A friend func of a class is an ordinary func except it has access to class
 * private members.
 * Must list the friend func declaration in the class definition, preceded by 
 * the keyword friend, maybe placed in private/public section, but it'll be 
 * public, so it's cleared  to list it in the public section
 * Not a member func, called the same way as an ordinary func.
 * !Don't use the dot operator in a call to a friend func,
 * !Don't use a type qualifier in the definition of a friend func
 * Syntax:
 *  class ClassName {
 *    public:
 *      friend FriendFuncDeclaration_1;
 *      friend FriendFuncDeclaration_;
 *      ......
 *      PublicMemberFuncDeclarations
 *    private:
 *      PrivateMemberDeclarations
 * };
 */

/** 
 * Tip Use both Member and Nonmember Funcs
 * In most cases, you can make a func either a member func or a friend and have
 * it perform the same task in the same way
 * 1. Use a member func if the task being performed by the func involves only 1
 *    obj.
 * 2. Use a nonmember func if the task being performed involves more than one
 *    obj. eg: equal(DayOfYear date1, DayOfYear date2)
 * More accurate but harder to understand way:
 * 1. Use member funcs if the task is intimately related to a single obj.
 * 2. Use nonmember funcs when the task involves more than 1 obj and the objs 
 *    are used symmetrically
 */

/**
 * TODO: Modifier const
 * If you use const for one parameter of a particular type, then you should use
 * it for every other parameter that has that type and that is not changed by
 * the func calls.
 * If the type is a class type, then you should also use the const modifier for
 * every member functions that does not change the value of its calling obj.
 * Params of a class type that aren't changed by the func ordinarily should be
 * const call-by-ref params, rather than call-by-val params.
 * If a member func doesn't change the val of its calling obj, then you can mark
 * the func by adding the const modifier to the func declaration;
 * the const is placed at the end of the func declaration, be4 the final
 * semicolon;
 * the heading of the func definition should also have a const to match
 */
class Sample {
 public:
    Sample();
    friend int compare(const Sample &s1, const Sample &s2);
    void input();
    void output() const;
 private:
    int stuff;
    double moreStuff;
};
/**
 * !Use the const modifier whenever it's appropriate for a class param and
 * !whenever it's appropriate for a member func of the class.
 * !If you don't use const every time that it's appropriate for a class, then 
 * !you should never use it for that class.
 */

// double Money::getValue() const {
//   return (allCents * 0.01);
// }

/**
 * Why member func input() cannot use the const modifier?
 * B/c input() changes the val of its calling obj, that will draw an err msg w/
 * the const modifier
 * 
 * Simi and Diff between call-by-val param and call-by-const-ref param?
 * void callByVal(int x);
 * void callByConstRef(const int &x);
 * Simi: Each param call protects the caller's arg from change
 * Diff: The call-by-val makes a copy of the caller's arg, so it uses more
 * memory than a call-by-const-ref.
 */




