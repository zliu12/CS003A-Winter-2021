/**
 * Class
 */

/**
 * Defining classes and member functions
 * A data type whose variables are objects, an obj as a var has member functions as well as the abitliy to hold data values
 * The definition of a class should be a data type definition that describes what kinds of values the variables can hold and also what the 
 * member functions are.
 * Add some member functions to a struct so that obtain a class
 */
//Type DayofYear is a class definition for objs whose values are dates
#include <iostream>
#include <cstdio>
class DayofYear
{
    // public says the member vars and funcs have no restriction on them
    public:
        void output(); // list member function declaration only, definiton is given elsewhere
        void input();  // list member function declaration only, definition is given elsewhere
        int month;     // member variable
        int day;       // member variable
};

int main()
{
    DayofYear today; // DayofYear type variable(object) holds month, day, output()
    today.input();   // Calls to the member function input w/ object today
    today.output();  // calls to the member function output w/ object today
}

// Definition must havethe class name b/c there may be other classes have member function with the name output
// The operator :: is called the scope resolution operator, like the dot operator
// Both scope resolution operator and dot operator tell which class
// Scope uses with a class name (AKA type qualifier), dot uses with an object (class member variables)
// Member function definition syntax:
// ReturnedType ClassName::FunctionName(ParameterList) {FunctionBodyStatements}
// No object name and dot operator when using member functions or member variables belong to the same class
void DayofYear::output()
{
    // month, day have no object and dot (today.) b/c we don't know object name at this point
    // Use the names of all members of that class w/o using the dot operator
    std::cout << "month = " << month << ", day = " << day << std::endl;
}

void DayofYear::input()
{
    std::cout << "Enter a month: " << std::endl;
    std::cin >> month;
    std::cout << "Enter a day: " << std::endl;
    std::cin >> day;
}

class Temperature
{
public:
    void set(double newDegrees, char newScale);
    double degrees;
    char scale;
};

void Temperature::set(double newDegrees, char newScale)
{
    degrees = newDegrees;
    scale = newScale;
}

/**
 * Public and private variables
 * Classes are types you define, so it should behave like the predefined types(double, int, etc)
 * A built library of your own class type definitions can be used as if they are predefined types, and put in a separate file
 * An ideal class definition allows you to change the details of how the class is implemented and you only need to change the definition
 * of the member functions.
 * If you change the member variables, you need only change the definitions of the member functions and nothing else.
 */
class DayOfYear
{
public:
    void input();
    void output();

    // Mutator
    void set(int newMonth, int newDay);

    // Accessor: provide access to private member variables/functions
    int getMonth();
    int getDay();
    // Private member variables/functions cannot be directly accessed in the program except within the definition of a member function
    // Private member variables maybe used in the definition of any of the member functions, but nowhere else.
    // Usually easier to understand and update w/ private member variables
private:
    // This is a helping function, a helper
    void checkDate();
    int month;
    int day;
};

int main()
{
    DayOfYear today1, today2; // Define objects
    today1.input();           // calls to member function
    today1.output();          // calls to member function

    today2.set(3, 21); // calls to member function
    today2.output();   // calls to member function

    // Use accessor to compare
    // !today1.month, today1.day, today2.month, today2.day are illegal b/c month and day are private member variables, can only be
    // !accessed through the "accesor" functions
    if (today1.getMonth() == today2.getMonth() && today1.getDay() == today2.getDay())
    {
        std::cout << "Same day" << std::endl;
    }
    else
    {
        std::cout << "Different day" << std::endl;
    }

    // !Illegal
    // std::cout << today.month;
    // std::cout << today.day;
    // if (today1.month == 1)
    // {
    //     cout << "January";
    // }


    return 0;
}

void DayOfYear::input()
{
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter day: ";
    std::cin >> day;
}

void DayOfYear::output()
{
    std::cout << "Month = " << month << " ";
    std::cout << "Day = " << day << std::endl;
}

void DayOfYear::set(int newMonth, int newDay)
{
    month = newMonth;
    day = newDay;
    checkDate();
}

void DayOfYear::checkDate()
{
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cout << "Illegal date, Exit program\n"
                  << std::endl;
        exit(1);
    }
}

int DayOfYear::getMonth()
{
    return month;
}

int DayOfYear::getDay()
{
    return day;
}

/*
Encapsulation/Data Hiding
Tecknique of making the variables in a class private and accessible only by a controlled interface of public or protected functions.
This allows you to modify the interal variables and data structures w/o breaking the code that uses your class.
Private member function:
eg:
    DayOfYear::checkDate()
!If a member function is a helping function(helper) and used only in the definitions of member functions, make it private
*/

/* 
Classes and Objects
Syntax:
class ClassName
{
    public:
        MemberSpecification_1;
        MemberSpecification_2;
            .
            .
            .
        MemberSpecification_n;
    private:
        MemberSpecification_n+1;
        MemberSpecification_n+2;
            .
            .
            .
};
Each MemberSpecification_i is the declaration of a member variable/function, more public/private sections are OK.
Covention: make all member variables private, which can only be accessed or changed using the member functions.
*/

/* 
Accessor functions
Allow you to check the values of the private members variables.
!Include a complete set of accesor functions w/ each class definition to test objects for equality is important,
!the accessor functions must return sth equivalent to values of member variables(or the value itself)
eg:
    int getMonth();
    int getDay();
*/

/* 
Mutator functions
Allow you to change the values of the private member variables, normally include the word set in the name(not required by c++)
eg:
    void set(int newMonth, int newDay);
!Include mutator functions w/ each class definition so that you can change the data stored in an object
*/
//! It's important to always have accessor and mutator functions w/ each class definition so that you can change the data stored in an obj.

/*
void DayOfYear::checkDate()
{
    if (month == 2) {
        if (day < 1 || day > 29) {
            std::cout << "Illegal Date" << std::endl;
        }
    }    
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) {
            std::cout << "Illegal Date" << std::endl;
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day < 1 || day > 31) {
            std::cout << "Illegal Date" << std::endl;
        }
    }
} 
*/

/* 
Summmary of Some Properties of Classes
Properties of class = properties of structures + properties associated w/ member functions:
1. member variables/functions
2. member variables/functions can be public or private, 
3. member variables are private normally
4. member variables can only be used in the definition of member functions for one same class
5. name of member functions can be overloaded
6. A class may use another as the type for a member variable
7. A function may have formal parameters whose types are classes
8. A function may return an object, which a class may be the type for the value returned by a function
*/

/* 
Structures VS Classes
Struct:
    1. member variables are public and no member functions normally, but can have private/public member variable/functions in c++
    2. A c++ struct can do anything a class can do.*/

/*
Constructor for Initialization
A constructor is a member function that is automatically called when an object of that class is declared, used to initialize the values
of member variables and any other sort of initialization may be needed; Normally public
! 1. Must have the sanme name as the class
! 2. Definition cannot return a value, no return type
! 3. Cannot be called in the same way as an ordinary member function is called. eg: object.memberFunction() // Illegal
Constructors usually are overloaded so that objects can be initialized in more than one way
*/
class BankAccount {
    public:
        // constructor overloaded
        BankAccount(int dollars, int cents, double rate);  
        BankAccount(int dollars, double rate);
        BankAccount();
        
        // Mutator function overloaded
        void set(int dollars, int cents, double rate);
        void set(int dollars, int cents);
        
        void update();
    private:
        double balance;
        double interestRate;
        // Helper function, convert a percentage to a fraction, fraction(50.3) returns 0.503
        double fraction(double percent);
};

int main() {
    BankAccount account1(100, 2.3); // object with two args
    BankAccount account2;           // object with no args, no parentheses in object declaration
    BankAccount account3;

    // This technical is calling the constructor creates an anonymous object w/ new values. An anonymous object is an object that is 
    // not named (as yet) by any variable. Then assign to the named object (the class variable)
    account3 = BankAccount(999, 99, 5.5);
/*
Mutator functions may be omitted if having a good set of constructor definition in some cases, but if want to change the existing member
variables in the object, then should use a mutator function. eg: account3.set(77, 0.77) or account4.set(88, 0.88, 8.8
*/
}

/*
Constructor is a member function that has the same name as the class. 
Auto called when declare an object of the class.
Are used to initialize objects.
Must have the same name with the class possess it*/

/*
Initialization section in constructor initialization section, the part starts w/ a single colon
The initializing values can be given in terms of the constructor parameters
Below two constructor definitions are equivalent
*/
BankAccount::BankAccount() : balance(0), interestRate(0.0) {
    // Body intentionally empty, can also be not empty
}
BankAccount::BankAccount() {
    balance = 0;
    interestRate = 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate) : balance(dollars + 0.01 * cents), interestRate(rate) {
    if ((dollars < 0) || (cents < 0) || (rate < 0)) {
        printf("Illegal Message\n");
        exit(1);
    }
}

/*
Syntax:
1. for an object declaration when you have consturctors
    ClassName ObjectName(ArgumentsForConstructor);
    eg. BankAccount account1(100, 2.3);
2. for an explicit constructor call
    object = ConstructorName(ArgurmentForConstructor);
    eg. account1 = BankAccount(200,3.5);
3. If the object is created as a dynamic variable
    BankAccount *myAcct;
    myAcct = new BankAccount (300, 4.2);
*/

/**
10.4-Introduction to Inheritance/Derived class
 * Derived class: obtained from the class class by adding features: say class A is a derived class of some other class B, it means class A
 * has all the features of class B but it also has added features; a class A can be a derived class of some other class B, which in turn
 * can be a derived class of some other class C, and so on.
 * eg.
 *  class MoneyMarketAccount -> class CheckingAccout -> class BankAccout;
 *  class CDAccount -> class SavingsAccount -> class BankAccount;
 */
class SavingsAccount : public BankAccount {
    public:
        SavingsAccount(int dollars, int cents, double rate);
        // ...Other constructors...
        void deposit(int dollars, int cents);
        void withdraw(int dollars, int cents);
    private:
};
/**
 * SavingsAccount account(100, 50, 5.5);
 * account.deposit(10, 25);             // Invoking a function in the derived class 
 * account.output(cout);                // Invoking a function in the parent class, BankAccount
 */


/**
 * Chapter Summary
 * 1. Struct: combine data of different types into a single/compound data value.
 * 2. Class: combine data and functions into a single/compound object. 
 * 3. A member variable/function of a class can be private/public;
 *  1) if public, can be used outside of the class.
 *  2) if private, can be used only in the definition of the member functions in within the class.
 * 4. A function may have formal params of a class or struct, may return values of a class or struct type.
 * 5. Member function can be overloaded.
 * 6. Constructor: member function of the class, same name as its class name,auto called when an class type obj is created.
 * 7. A data type consists of a collection of values together with a set of basic operations defined on these values
 * 8. ADT: abstract data type, a programmer who uses the type does not need to know any of the details about how the values and
 * operations for that type are implemented.
 * 9. A class with all member variables private and member functions public is one way to implement ADT in c++
 * 10. Inheritance: (parent)class -> (child/derived)class (inherits members from the parent class)
 */
