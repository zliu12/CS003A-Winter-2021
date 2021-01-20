/**
 * Dyamic Arrays
 */

#include <iostream>


int main() {
    // Dynamic array is an array whose size is not specified when you write the program, but determined while the program
    // is running.
    // Array variable: a pointer variable that points to the first indexed variable of the array.
    // p and a are the same kind of variable in below example.
    int a[10];              // Pointers points to a variable of type int (namely a[0])
    typedef int* IntPtr;
    IntPtr p;               // Pointer variable that points to an int variable 
    p = a;                  // a(a[0]) can be assigned to p
    // p = a, p and a store the same address
    std::cout << "a: " << a << std::endl;
    std::cout << "p: " << p << std::endl;
    // a[0] and p[0] have the same garbage value 
    std::cout << "a[0]: " << a[0] << std::endl;
    std::cout << "p[0]: " << p[0] << std::endl;
    // p[1] and a[1] have the same garbage value
    std::cout << "a[1]: " << a[1] << std::endl;
    std::cout << "p[1]: " << p[1] << std::endl << std::endl;
    /**
     * p = a;
     * p[0] refer to indexed variables a[0], p[1] to a[1], p[2] to a[2]...
     * Square bracket notation (used for array) applies to pointer variables ALA the pointer variable points to an array in memory
     * After assignment, p can be treated as if a, and vice versa
     * !Important reservation: pointer value in an array variable can't be changed, which the address stored in a or p can't be changed
     * !a[index]/p[index] can be changed
     * IntPtr p2;
     * ... // Assign some pointer value to p2
     * a = p2 //!ILLEGAL, can assign a new address to a.
     */

    int a1[10], index;
    typedef int* IntPtr;
    IntPtr p1;

    // Assign value to array a1
    for (index = 0; index < 10; index++) {
        a1[index] = index;
    }

    // Set the address of array a1(a[0]) to pointer variable p1, p1 now points to the memory location of array a1
    p1 = a1;

    // Output same
    for (index = 0; index < 10; index++) {
        std::cout << "a1[" << index << "]" << a1[index] << " ";
        std::cout << "p1[" << index << "]" << p1[index] << std::endl;
    }
    std::cout << std::endl;

    // Modify the integer values p1 points to
    for (index = 0; index < 10; index++) {
        p1[index] = p1[index] + 1;
    }

    // a1 changes as p1 changes
    for (index = 0; index < 10; index++)
    {
        std::cout << "a1[" << index << "]" << a1[index] << " ";
        std::cout << "p1[" << index << "]" << p1[index] << std::endl;
    }
    std::cout << std::endl;

    /**
     * Regular Array: size must be given when defining the array
     * Disadvantage:
     * 1) estimated size too low, program won't work in all situations
     * 2) too large, waste computer memory
     * Dynamic array avoids issues above since the size can be entered as input and dynamic array can be created to be exactly that size
     */

    // Use new operator
    // Dynamic variables can be treated as if they are ordinary arrays.
    // Replace double w/ the desired type to obtain a dynamic array of elements of any other type
    // Size of array is 
    typedef double* doublePtr;
    doublePtr p2;
    int index2;
    const int ARRAY_SIZE = 10;
    p2 = new double[ARRAY_SIZE];        // when call new, it tells the computer how much storage to reserve for the dynamic array

    for (index2 = 0; index2 < ARRAY_SIZE; index2++) {
        p2[index2] = index2;
    }

    for (index2 = 0; index2 < ARRAY_SIZE; index2++) {
        std::cout << "p2: " << p2[index2] << " ";  
    }
    std::cout << std::endl << std::endl;

    // delete statement destroys the dynamic array variable so that the memory used by dynamic array is returned to the freestore
    // !delete statement for dynamic array variables must include an empty pair of square brackets [] 
    // !W/ a call to new using a pointer to create a dynamic array, after the call to new, I shouldn't assign new pointer value to
    // !to this pointer variable, otherwise it can confuse the system when the memory for the dynamic array is returned to the freestore
    // !with delete call
    delete [] p2;

    /**
     * Dynamic Array Syntax:
     * typedef array_type* array_typeArrayPtr;
     * array_typeArrayPtr array_name;
     * array_name = new array_type[array_size];     //!Must not assign any other pointer value to pointer variable after a call to new
     * delelte [] array_name;                       // Return the array memory to the freestore w/ a call to delete
     * typedef char* CharArray
     * for (int i = 0; i < 10; i++) {std::cin >> entry[i];}
     * delete [] entry;
     */

    int c[10];
    int *q = c;
    for (int i = 0; i < 10; i++) {
        c[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        std::cout << "q[" << i << "]: " << q[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int array_size = 10;
    int *d;
    d = new int[array_size];
    int *e = d;
    for (int i = 0; i < array_size; i++) {
        d[i] = i;
    }
    e[0] = 10;
    for (int i = 0; i < array_size; i++) {
        std::cout << "d[" << i << "]: " << d[i] << " ";
    }
    std::cout << std::endl << std::endl;

    return 0;
    }