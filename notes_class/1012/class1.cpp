/**
 * Classes.
 * 
 */

#include <cmath>
#include <cstdio>
#include <iostream>
typedef double Value;

// Note the overloading of the constructor
class Color {
    private:
        // Underscore: a way to tell it's private variables, indication
        double _red, _green, _blue;

    public:
        // Initializing attributes outside the boday is called "delegation"
        // Defalut constructor, MUST be defined explicitly if there's another constructor
        // !If you create a constructor, you must create a defalut constructor
        Color() : _red(0), _green(0), _blue(0) {
            printf("Color()\n");
        }

        // Single paramete constructor, can be invoked w/ assignment
        // !Always use explicit for single parameter constructor
        explicit Color(double value) : _red(value), _green(value), _blue(value){
            printf("Color(%.3lf)\n", value);
            std::cout << "Color(" << value << ")" << std::endl;
        }
        
        Color(double red, double green, double blue) : _red(red), _green(green), _blue(blue) {
            printf("Color(%.3lf, %.3lf, %.3lf\n)", red, green, blue);
        }

        // double value() {
        //     return sqrt(_red * _red + _green * _green + _blue * _blue);
        // }
};

int main() {
    
    // "Default" constructor, meaning the constructor takes no args
    Color c1;

    // Single parameter constructor can be invoked w/ direct assignment
    Color c2a(0.5);         // This is a Color type, corresponds to ln20 by the explicit keyword
    Value ct1 = 0.5;        // This is a double type 
    Color c2b(0.7);
    Color c3(0.5, 0.1, 0.7);
    
    
}