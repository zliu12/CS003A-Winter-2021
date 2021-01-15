/**
 * Class inheritance
 *
 * Copyright (c) 2021, Zhao Liu
 */


#include <cstdint>
#include <random>
#include <string>

// "Macro" to Create a random 6-digit number
#define RAND() (100000 + rand() % 900000)



// PCC member (student, faculty, or staff)
// This is the "base" class
class Member {
    private:
        uint32_t _id;
        std::string _phone;
        
        // Avoid the "friend" declaration like the plague, it breaks the encapsulation (data hiding)
        // Can be used when re-implenmention
        friend void dump(Member);

    public:
        // Must be defined even if there's nothing to do b/c there's anther non-default constructor
        Member() : _id(RAND()) {
        } 

        explicit Member(std::string phone) : _id(RAND()), _phone() {
        }

        // Accessor to ge the private attribute value
        uint32_t getID() {
            return _id;
        }

        // Always use setters and getters to have the flexibility to add logic
        void setPhone(std::string phone) {
            _phone = phone;
        }

        std::string getPhone() {
            return _phone;
        }

        void dump() {
            printf("ID: %d, phone: %s\n", _id, _phone.c_str());
        }

        // This method "overloads" the dump() above
        void dump(std::string tag) {
            printf("[%s] ID: %d, phone: %s\n", tag.c_str(), _id, _phone.c_str());
        }
};

// This is a "friend" of the member class
void dump(Member m)
{
    printf("ID: %d, phone: %s\n", m._id, m._phone.c_str());
}

// (Student) This is the "derived" class (derives from base(Member) class)
// The derived class does NOT need to re-implement the base class's logic
class Student : public Member {
    private:
        double _gpa = 0;

    // The system automatically creates a "default" constructor (no params)
    // since there are no other contructors
    public:
        // Student() : _id(RAND()), _gpa(0) {
        // }  

        // Default constructor
        Student() {
        }

        // Note the call to the base class
        Student(std::string phone) : Member(phone) {
        }

        // "Mutator" (AKA "setter")
        bool setGPA(double gpa) {
            if (gpa < 0 || gpa > 4) {
                return false;
            } 
            _gpa = gpa;
            return true;
        }

        // "Accessor" (AKA "getter")
        double getGPA() {
            return _gpa;
        }
    
//         // The derived class is "redefining" the method
//         void dump() {
//             // Note that you need an accessor for the ID, but not the GPA
//             printf("ID: %d, phone: %s, GPA: %.2lf\n", getID(), getPhone().c_str(), _gpa);
//         }
};

int main() {
    Member m1;
    m1.dump();

    Member m2("123-456-7890");
    m2.dump();

    Student s1;
    s1.setGPA(3.9);
    s1.dump();

    Student s2("333-444-5555");
    s2.dump();
    s2.dump("s2");

    // Using an external "friend" function
    // Note that we passed in a Student class instance to a function expecting Member
    dump(s2);
}