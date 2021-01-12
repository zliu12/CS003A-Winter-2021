/**
 * 
 * Dynamic array
 * 
*/

#include <iostream>
#include <cstdio>
#include <random>
// 0x10 = 10 (base 10)
#define SIZE 0x10

// Note that changes persist after the function returns
void populate(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 1000;
    }
}


int main()
{
    // Allocate memory with "new" - create on the "heap" (NOT STACK)
    // a1 itself is however an "automatic" varibale and is created on the stack
    int *a1 = new int[SIZE];
    populate(a1, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d", a1[i]); // a1[i] is equivalent to *(a1 + i)
    }  
    printf("\n");

    // Note the difference in memory addresses
    printf("&a1 = %p, a1 = %p\n", &a1, a1);

    // Deallocate memory, ALWAYS do this avoid memory leaks!!!
    // Whenever do new, always remember to do delete
    // If no [], then only delete the very first a1, the particular value,
    // the other are still leaking. 
    // W/ [], the whole thing is deleted
    // Don't forget the [] for arrays
    delete [] a1;
}