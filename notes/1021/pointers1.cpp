/**
 * Exercises on pointers
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <cstdio>

class Complex {
 private:
  double _real;
  double _imaginary;

 public:
  Complex(double r, double i) : _real(r), _imaginary(i) {
  }
  void setReal(double r) {
    _real = r;
  }
  void setImaginary(double i) {
    _imaginary = i;
  }

  void dump() {
    printf("(%.3lf, %.3lf)\n", _real, _imaginary);
  }
};

void getComplex(Complex* cp) {
  printf("Complex number (real, imaginary): ");
  double r, i;
  scanf("%lf,%lf", &r, &i);
  cp->setReal(r);
  cp->setImaginary(i);
}

typedef Complex *ComplexPointer;

int main() {
  // i1 is the name of the var holding the val 100
  int i1 = 100;

  // i1p is the name of the pter var that holds the address of i1
  int* i1p = &i1;

  printf("i1 = %d, i1p = %p\n", i1, i1p);

  printf("i1 = %d, *i1p = %d\n", i1, *i1p);
  *i1p = 200;
  printf("i1 = %d, *i1p = %d\n", i1, *i1p);

  Complex c1(0.500, 0.707);
  Complex *c1p = &c1;
  // ComplexPointer is just an alias for Complex *, easier to read
  ComplexPointer c2p = c1p;
  // "Dot" notation
  c1.dump();
  // "Arrow" notation
  c1p->dump();
  c2p->dump();

  // Read by passing pointer (note that this is not by reference)
  // Be sure to use a pointer that points to valid memory region!
  // Complex *c3p;
  // getComplex(c3p); This is invalid b/c c3p points to an unallocated region
  printf("c3p = %p\n", c1p);
  getComplex(c1p);  // This is valid b/c c1p points to teh location of c1
  c1p->dump();
}