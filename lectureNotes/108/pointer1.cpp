/**
 * 
 * 
 * 
 * 
 * 
*/
#include <iostream>
#include <cstdio>

// Swap using reference, pass by reference
// Not great to use reference for making changes (why?)
void swap (int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

// Swap using pointers
// Good to use pointers to make changes (why?)
// Because it`s harder to see it in the function call
void swap(int *ap, int * bp)
{
    int c = *ap;
    *ap = *bp;
    *bp = c;
}


int main() {
    int i1 = 100;
    int *i1p = &i1;
    int i2 = *i1p;
    int i3 = 100;

    // %d means treats i1 as integer, %p means treat i1p as pointer
    // Note that the value s are the same, but with different addresses
    printf("i1 = %d, i1p = %p\n", i1, i1p);
    printf("i2 = %d, &i2 = %p\n", i2, &i2);

    // Contents are getting modified
    *i1p = 200;
    printf("i1 = %d, i2 = %d\n", i1, i2);

    // Modified by reference
    swap(i1, i2);
    printf("i1 = %d, i2 = %d\n", i1, i2);

    // Modified by pointer
    swap(&i1, &i2);
    printf("i1 = %d, i2 = %d\n", i1, i2);
}