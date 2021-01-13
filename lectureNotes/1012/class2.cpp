/**
 * Classes.
 * 
 */

#include <cmath>
#include <cstdio>
typedef double Value;

// Note the overloading of the constructor
class Color {
    private:
        // Underscore: a way to tell it's private variables, indication
        double _red, _green, _blue;
        // This is a "helper" function, note it's private
        double _value(double v)
        {
            if (v < 0)
            {
                return 0;
            }
            if (v > 1)
            {
                return 1;
            }
            return v;
        }

    public:
        // Defalut constructor, MUST be defined explicitly if there's another constructor
        // !If you create a constructor, you must create a defalut constructor
        Color() : _red(0), _green(0), _blue(0) {
        }

        // Single paramete constructor, can be invoked w/ assignment
        // !Always use explicit for single parameter constructor
        explicit Color(double v) {
            // The value of an assignment is same as the value being assigned
            _red = _green = _blue = _value(v);
        }
        
        Color(double r, double g, double b) : _red(_value(r)), _green(_value(g)), _blue(_value(b)) {
        }

        double value() {
            return sqrt((_red * _red + _green * _green + _blue * _blue) / 3.0);
        }

        /**
        * Abstract Data Type: ADT
        */
        // Remember to assert all checking logic every time you change the attribute values
        void scale(double factor) {
            _red = _value(_red * factor);
            _green = _value(_green * factor);
            _blue = _value(_blue * factor);
        }
};


int main() {  
    // new keyword always returns a pointer, as covention, put a letter p at the end of the name to indicate
    Color *c1p = new Color(0.1, 0.6, 0.3);
    // Use -> for pointers to access the members
    // Note how this is instantiated and the "->" notation to access value()
    printf("c1p->value() = %lf\n", c1p->value());

    // Note how this is instantiated and the "dot" notation to access value()
    Color c2(0.3, 0.4, 0.1);
    printf("c2.value() = %lf\n", c2.value());

    c2.scale(5.0);

    printf("c2.value() = %lf\n", c2.value());

    // This does't work because _red is private;
    // printf("c2._red = %lf\n", c2._red)

    // Don't forget this!
    delete c1p;
}

