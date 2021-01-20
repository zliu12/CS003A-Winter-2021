/**
 * Formatted printing using printf 
 *
 * Copyright (c) 2021, Qichang.L
 */

#include <cstdio>

int main() {
    for (int i = 98; i < 101; i++) {
        // % is a place holder, -5 means 5 spaces to the right
        printf("%-5d%-5d\n", i, i);
    }
}