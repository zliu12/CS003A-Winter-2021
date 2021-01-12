/**
 * Control flows
 * 
*/

#include <iostream>

int main() {
    int i = 0;
    while (i < 3)
    {
        std::cout << i << std::endl;
        i++;
    }

    // Equivalent code using for loop
    for (int i = 0; i < 3; i++)
    {
        std::cout << i << std::endl;
    }
}