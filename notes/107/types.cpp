#include <iostream>
#define COUNT 100


int main() {
    // "auto" keyword interprets type automatically at compile time, it is NOT dynamic typing
    const char *s1 = "Hello";
    auto s2 = "Hello, world";  // Here "auto" is interpreted as "const char*"
    decltype(s1) s3;    // Also interpreted as "const char*"
    auto s4 = s3;       // Also interpreted as "count char *" because s3 is that
    
    // You can re-assign, but can`t change what it points to because it`s "const char*"
    s1 = "Hi";   // OK
    // s1[0] = "h";

    // You can both re-assign and change value it points to here because it`s "char *"
    // Note that you need to end the array with a null character '\0' for it to a valid string
    char *s5 = new char[3];
    // TODO:
    s5[0] = 'x';
    s5[1] = '\0';
    std::cout << "s5 = " << s5 << std::endl;

    // Here "auto" interprets it as "char *" becuase s5 is "char *"
    auto s6 = s5;
    s6[0] = 'b';

    // FIXME:
    char s7[] = "hi";
    std::cout << "sizeof(s7) = " << sizeof(s7) << std::endl;

    int count = COUNT;  // Note the case for the variable and cosntant
}