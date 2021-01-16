/**
 * Pointer
 * */


#include <iostream>
#include <string>

int main() {
    /**
     * Pointer can be stored in a variable, but can't be stored in type int/ double variable w/o type casting.
     * A pointer variable must be declared to have a point type, e.g: double *p1
     * Use reference operator & to determine the address of a variable and assign to a pointer variable.
     */
    int num1 = 100;         
    int *p1;
    int *p2;
    p1 = &num1;
    std::cout << "num1 before: " << num1 << std::endl;
    *p1 = 200;
    std::cout << "num1 after: " << num1 << std::endl;
    std::cout << "*p1: " << *p1 << std::endl;
    std::cout << "p1: " << p1 << std::endl;
    /**
     * p2 is another pointer, set p2 equal to p1. Since p1 stores the memory location of num1, the same thing w/ p2.
     * p2 and p1 are pointing to the same memory location, so *p2 = *p1
     */
    p2 = p1;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "*p2: " << *p2 << std::endl;
    /**
     * when console out the pointer type variable (w/ aterisk, *p1), the result is the value stored at memory address
     * which is 100 in this case.
     * when console out the pointer variable (w/o aterisk, p1), the result is the memory address of the variable that`s
     * pointed, which is 0x7ffcfeddb59c in this case. 
     * ! when print out, *p1 means the value stored at the memory address; p1 means the memory address itself!
     * ! when w/ asterisk, I'm dealing w/ the variables that the pointers are pointing to instead of the pointers.
     * A pointer is an address, and an address is an integer, but pointer is not an integer. 
     * Can perform a kind of addition/ subtraction on pointers, but they're not nomarl integer operations.
     * When aterisk using in pointer, it's called dereferencing operator, the pointer variable is said to be dereferenced.
     * v1 = 0;
     * p1 = &v1;
     * *p1 = 42;
     * cout << v1 << endl;  v1 = 42     
     * cout << *p1 << endl; *p1 = 42
     * ! p1 stores the memory location of v1, *p1 stores the value that's stored in memory loctaion p1 (v1's memory location), so when 
     * ! *p1 is equal to 42, the value that's stored in memory location p1 (v1's memory location) is equal to 42. 
     */

    /**
     * B/c pointer can refer to a variable, the program can manipulate variables even if the variables have no identifiers to name them.
     * Operator new can be used to create variables that have no identifiers to serve as their names, and they are referred to via pointers.
     * Variables created by the new operator are called dynamic variables b/c they are created and destroyed while the program is running.
     */
    new int;            // Create a nameless variable by operator new
    int *p3;            // Create an int pointer type variable int *p3
    p3 = new int;       // Assign the address of new int to p3
    std::cout << "Enter new int: " << std::endl;
    std::cin >> *p3;
    std::cout << "*p3: " << *p3 << std::endl;           // *p3 stores the integer value entered for the name less variable new int
    std::cout << "p3: " << p3 << std::endl;             // p3 stores the memory location of the nameless variable new int
    std::cout << "New int: " << new int << std::endl;   // Don't know

    int *pa, *pb;
    pa = new int;
    pb = new int;
    *pa = 10;
    *pb = 20;
    std::cout << *pa << " " << *pb << std::endl;        // 10 20
    pa = pb;
    std::cout << *pa << " " << *pb << std::endl;        // 20 20
    *pb = 30;
    std::cout << *pa << " " << *pb << std::endl;        // 30 30


    int *pc, *pd;
    pc = new int;
    pd = new int;
    *pc = 10;
    *pd = 20;
    std::cout << *pc << " " << *pd << std::endl;        // 10 20
    *pc = *pd;      
    std::cout << *pc << " " << *pd << std::endl;        // 20 20
    *pc = 30;
    std::cout << *pc << " " << *pd << std::endl;        // 30 20

    /**
     * New operator crates a new dynamic variable of a specified type and returns a pointer that points to this new variable.
     * Example creates a new dynamic variable of type MyType and leaves the pointer variable p pointing to this new variable
     * MyType *p;           
     * p = new MyType;
     * If no sufficient memroy available to create the new variable, then the new operator by default terminates the program.
     */


    /**
     * Basic Memroy Management
     * Freestore (sometimes called the heap) is reserved for dynamic variables. If too many dynamic variables consume all of the memory
     * in the freestore, any additional calls to new will fail.
     * Size of freestore is typically large, but it's still a good practice to recycle freestore memory that's no longer needed.
     * The delete operator eliminates a dynamic variable and returns the memory occupied so that it can be reused.
     * int *p = new int;    // Create a dynamic variable
     * delete p;            // Destroy the dynamic variable pointed to by p and return the memory used by the dynamic variable to the freestore
     * Now the value of p is undefined and p should be treated like an uninitialized variable, the memory then can be reused.
     */

    /**
     * !Pitfall Dangling Pointers -- Danlging Pointers
     * !When apply detele to a pointer variable, the dynamic variable it's pointing to is destroyed so the value of pointer variable undefined.
     * !U dunno where it's pointing, nor the value that it's pointing to.
     * !If apply the dereferncing operator * to a dangling pointer, the result is unpredictable and usually disastrous.
     * !Be certain that the pointer variable points to some variable be4 applying the dereferencing operator * to a pointer varialble
     */

    /**
     * Static Variables and Automatic Variables
     * Dynamic varaible: variable created with the new operator b/c they're created and destroyed while the program is running.
     * Ordinary variables aren't really static: 
     * 1) if local to a function, then C++ system creates the variable when calling the function and destroys when function call completed,
     * same thing for the main function, main function variables aren't destroyed until the program ends.
     * 2) they're called ordinary/automatic variables b/c their dynamic properties are contorlled automatically for coder.
     * Global variables: declared outside of any function definition, including main function.
     */

    /**
     * Define Pointer Types
     * Define a pointer type name, then declare pointer variables w/o the *
     * typedef int* IntPtr;         // type for pointer variables that contain pointers to int variables         
     * IntPtr p;                    // = int *p: a pointer points to an int variable, this pointer is called p
     * Type name: typedef can define an alias for any type name or definition:
     * typedef double Kilometers;
     * Kilometers distance;
     * Advantages to using defined pointer type names:
     * 1) Avoid the mistake of omitting an asterisk: int *p1, *p2 = IntPtr p1, p2.
     * 2) Easy for function with a call by reference paramenter for a pointer variable: void sample(IntPrt& pointerVariable).
     * Assign a name to a type definition and then use the type name to declare variables by the keyword typedef.
     * Normally placed outside of the body of the main part of the program (and outside the body of other functions)
     * Syntax: typedef Known_Type_Definition New_Type_Name; typedef int* IntPtr; IntPtr pointer1, pointer2;
     * typedef int* NumberPtr; NumberPtr my_point;
     */

    return 0;
}