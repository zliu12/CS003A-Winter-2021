/**
 * Class demo.
 */

#include <string>
#include <iostream>
#include <random>

#define RAND() (100000 + rand() % 999999)

// Note the syntax
class Student {
    // "Attributes" are basically private "members"
    // Encapsulation: these "attribute" are not visible outside this class
    private:
        unsigned long studentID;
        std::string firstName;
        std::string lastName;

    public:
        // Special method, called a "constructor"
        Student(std::string fn, std::string ln) : studentID(RAND()), firstName(fn), lastName(ln) {
            firstName = fn;
            lastName = ln;
        }

		// "Accessors" provide public access to private attributes
		unsigned long getStudentID() {
			return studentID;
		}

		// "Mutators" provide public write access, but often with extra logic checks
		void setStudentID(unsigned long sid) {
			// "Sad" path
			if (sid < 100000 || sid > 999999){
				return;
			}
			// "Happy" path
			studentID = sid;
		}

        // "Methods" are "member" functions 
        // Public "methods" that provide the interface to the class, providing operations on attributes
        // This attributes and operation on them constitute "informational cohesion"
        std::string name() {
            return firstName + " " + lastName;
        }

        // This method is "abstracting" out the common logic into one place
        void dump(std::string tag) {
            std::cout << "[" << tag << "]" << studentID << ": " << name() << std::endl;
        }
};

// The caller has no idea how Student is implemented (the concept of "encapsulation")
int main() {
    // "Instanciation" of the class "type", type can be only 1, insta can be many
    Student s1("Johnny", "Sokko");       // As if you called Student("Jonny", "Sokko")

	// This does NOT work becasue these attributes are private
	// std::cout << s1.studentID << std::endl;
	// s1.studentID = rand();
	// This works because the reading is through an "accessor"
	std::cout << s1.getStudentID() << std::endl;
	s1.setStudentID(0);
	std::cout << s1.getStudentID() << std::endl;
	s1.setStudentID(445321UL);
	std::cout << s1.getStudentID() << std::endl;

	// This accesses the member function (method) of the class instance
    s1.dump("s1");

    // Couple of other types of instantiation
    Student s2 = {"Johnny", "Sokko"};
    Student s3 = Student("Johnny", "Sokko");
    s2.dump("s2");
    s3.dump("s3");

	
}