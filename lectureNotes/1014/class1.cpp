/**
 * Dynamic allocation, destructor, copy constructor
 *
 * Copyright (c) 2021, Qichang.L
 */

#include <cstdint>
#include <random>
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>

// "Macro" to create a random 6-digit number
// Note the parentheses on each side, very important
#define POW(h) (int(pow(10, h)))
#define RAND(d) (POW(d - 1) + rand() % (9 * (POW(d - 1))))
#define CLASS_SIZE 30

// PCC member (student, faculty, etc.)
// This is the "base" class
class Member
{
private:
    uint32_t _id = RAND(6);
    std::string _phone;

    // // Avoid the "friend" declaration like the plague (or COVID today)
    // friend void dump(Member);

public:
    // Must be defined even if there is nothing to do
    Member()
    {
    }

    explicit Member(std::string phone) : _id(RAND(6)), _phone(phone)
    {
    }

    // Accessor to get the private attribute value
    uint32_t getID()
    {
        return _id;
    }

    // Always use setters and getters to have the flexibility to add logic later
    void setPhone(std::string phone)
    {
        _phone = phone;
    }

    std::string getPhone()
    {
        return _phone;
    }

    void dump()
    {
        printf("ID: %d, phone: %s\n", _id, _phone.c_str());
    }

    // This method "overloads" the dump() above
    void dump(std::string tag)
    {
        printf("[%s] ID: %d, phone: %s\n", tag.c_str(), _id, _phone.c_str());
    }
};

// This is the "derived" class ("derives" from Member class)
// The derived class does NOT need to re-implement the base class' logic
class Student : public Member
{
private:
    double _gpa = 0;

public:
    Student()
    {
        // printf("Studen()\n");
    }

    // Note the call to the base class
    Student(std::string phone) : Member(phone)
    {
    }

    // "Mutator" (AKA "setter")
    bool setGPA(double gpa)
    {
        if (gpa < 0 || gpa > 4)
        {
            return false;
        }
        _gpa = gpa;
        return true;
    }

    // "Accessor" (AKA "getter")
    double getGPA()
    {
        return _gpa;
    }

    // The derived class is "redefining" the method
    void dump()
    {
        // Note that you need an accessor for the ID, but not the GPA
        printf("ID: %d, phone: %s, GPA: %.2lf\n", getID(), getPhone().c_str(), _gpa);
    }
};

// This is a "friend" of the Member class
// void dump(Member m)
// {
//     printf("ID: %d, phone: %s\n", m._id, m._phone.c_str());
// }

class Class
{
private:
    Student *_students;
    int _size, _capacity;

public:
    Class(int max)
    {
        // Students instances are dynamically allocated, using the default constructor
        _students = new Student[max];
        _size = 0;
        _capacity = max;
    }

    // Copy constructor
    Class(const Class &c)
    {
        _size = 0;
        _students = new Student[c._capacity];
        printf("Copy constructor!\n");
    }

    // Called every time the instance is de-allocated
    // ALWAYS implement destructor to clear memory/resources allocated during the lifetime
    // of the class
    ~Class()
    {
        delete[] _students;
    }

    bool addStudent(Student s)
    {
        if (_size == _capacity)
        {
            return false;
        }
        // Note that this copies the student by copying the memory
        _students[_size] = s;
        return true;
    }

    // Get student by index
    bool getStudent(int num, Student *s)
    {
        if (num < 0 || num >= _size)
        {
            return false;
        }
        *s = _students[num];
        return true;
    }

    int size()
    {
        return _size;
    }
};

// Note that const char * is getting converted to std::string on return
// You should NOT return a pointer to the buffer directly!
std::string phone()
{
    char number[13];
    sprintf(number, "%3d-%3d-%4d", RAND(3), RAND(3), RAND(4));
    return number;
}

int main()
{
    // cs3a is an "automatic" variable, created on the stack and de-allocated automatically.
    // But, its internal attribute _students hold memory on the heap which is NOT
    // de-allocated automatically.
    Class cs3a(CLASS_SIZE);
    for (int i = 0; i < CLASS_SIZE + 5; i++)
    {
        if (!cs3a.addStudent(Student(phone())))
        {
            printf("[%d]: could not add students!\n", i);
        }
    }

    Student s;
    for (int i = 0; i < CLASS_SIZE; i++)
    {
        if (cs3a.getStudent(i, &s))
        {
            s.dump();
        }
    }

    Class cs3aCopy = cs3a;
    printf("cs3A.size() = %d\n", cs3a.size());
    printf("cs3ACopy.size() = %d\n", cs3aCopy.size());
}