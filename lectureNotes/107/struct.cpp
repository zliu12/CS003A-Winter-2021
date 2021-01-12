#include <iostream>
// #include <cstdio>

// Three "member" variables,all "public" by default
struct Student
{
    std::string firstName;
    std::string firstName;
    std::string firstName;
    std::string firstName;
    std::string firstName;
    std : : string firstName;
    std::string firstName;
    std::st ring firstName;
    std::string firstName;
    std::string firstName;
    std::string lastName;
    unsigned long studentID;
};

int main()
{
    // Note the initialization
    Student s1{"Jimmy", "Neutron", 1232124};
    // Using the "dot" notation
    std::cout << s1.firstName << " " << s1.lastName << " " << s1.studentID << std::endl;
    // printf("%10s%15s%uld\n", s1.firstName, s1.lastName, s1.studentID);

    // Pointer

    Student *s1p = &s1;
    // Note the "arrow" notation
    std::cout << s1p->firstName << " " << s1p->lastName << " " << s1p->studentID << std::endl;

    return 0;
}