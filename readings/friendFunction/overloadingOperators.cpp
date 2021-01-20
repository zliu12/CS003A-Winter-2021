/**
 * 11.2 Overloading Operators
 *
 * Copyright (c) [2021], Qichang.L
 */

/*
TODO: Func overloading/redefinition/override
重载：函数名相同，函数的参数个数/参数类型/参数顺序三者中必须至少有一个不同。函数返回值的
类型可以相同，也可以不同。发生在一个类内部。

重定义：也叫隐藏，子类重新定义父类中有相同名称的非虚函数（参数列表可以不同），指派生类的
函数屏蔽了与其同名的基类函数。发生在继承中。
1. 如果派生类函数和基类的函数同名,但是参数不同,此时不管有无virtual,基类的函数被隐藏。
2. 如果派生类函数和基类的函数同名,且参数也相同，但是基类函数没有virtual关键字，此时基类
的函数被隐藏（如果相同有virtual就是重写覆盖了）。

重写：也叫覆盖，一般发生在子类和父类继承关系之间。子类重新定义父类中有相同名称和参数的虚
函数。
1. 如果一个类，存在和父类相同的函数，那么这个类将会覆盖其父类的方法，除非在调用的时候
强制转换为父类类型，否则试图对子类和父类做类似重载的调用是不能成功的。
2. 被重写的函数必须是virtual（不能是static）。
3. 重写函数必须具有相同的类型/名称/参数列表。
4. 重写函数的访问修饰符（public/private）可以不同，尽管virtual是private，派生类中重写
改名为public/protected也是可以的。
 */

// A func can be overloaded to take args of diff types, an operator is a func,
// so an operator can be overloaded, bascially the same as the way to overload
// a func name.
// !When overloading an operator, at least one of the args to the operator must
// !be of a class type. This requirement prevents changing the effect of any
// !operator on any built-int type.

/**
 * Overload the operator +
 * Use the name + instead of the name add and precede the + w/ the keyword
 * operator.
 * Overload the operator + (and many other operators) so that it will accept 
 * args of a class type.
 */
#include <iostream>
#include <cstdlib>
#include <cctype>

class Money {
 public:
  // amount1/amount2 have been given values, return the sum of amount1/amount2
  // mind the const modifier
  friend Money operator+(const Money &amount1, const Money &amount2);
  // amount1/amount2 have been given values, true if value equal otherwise false
  // mind the const modifier
  friend bool operator==(const Money &amount1, const Money &amount2);

  Money(int64_t dollars, int cents);
  // Use keyword explicit for single param constructor
  explicit Money(int64_t dollars);
  Money();

  // mind the const modifier
  double getValue() const;
  // void input(istream &ins);
  // void output(ostream &outs) const;

 private:
  int64_t allCents;
};

int main() {
  Money amount1, amount2;
}

// One-arg of type long constructor tells the system how to convert an integer,
// like 25, to a value of type Money, which is allCents
Money::Money(int64_t dollars) {
  allCents = dollars * 100;
}

// friend of the class
Money operator+(const Money &amount1, const Money &amount2) {
  Money temp;
  temp.allCents = amount1.allCents + amount2.allCents;
  return temp;
}
// friend of the class
bool operator==(const Money &amount1, const Money &amount2) {
  return (amount1.allCents == amount2.allCents);
}

/**
 * TODO: Rules on Overloading operators
 * At least one arg of the resulting overloaded operator must be a class type.
 * An overloaded operator can be a friend of a class; the operator function may 
 * be a member of the class or an ordinary (nonfriend) function.
 * Only the existing operators can be overloaded.
 * Cannot change the num of args that an operator can take when overloading.
 *  eg: % is always binary: 2 % 3;
 *      ++ is always unary: i++;
 * Overloading doesn't change the precedence of an operators.
 *  eg: x * y + z always means (x * y) + z
 * Dot operator(.),scope resolution operator(::), .* and ?: can't be overloaded.
 * Some operators must be overloaded in a diff way. eg: =, [], ->
 * */

/**
 * TODO: Constructor for automatic type conversion
 * System will perform certain type conversions automatically if the class
 * definition contains the appriate constructors
 * eg:
 *  Money baseAmount(100, 60), fullAmount;
 *  Money:Money(int_64 dollars) : allCents(dollars * 100) {
 *  }
 *  fullAmount = baseAmount + 25;   // baseAmount is type Money, 25 is type int
 *  fullAmount.output(cout);  //the output will be $125.60
 * int 25 is converted to type Money @ln75, an obj of type Money whose member
 * var allCents is equal to 2500
 * !double var (25.67) won't work since no one-arg contructor takes in double 
 * !arg, such as Money(double amount).
 * Money(double amoount) : allCents(floor(amount * 100)) {
 * }
 * Automatice type conversion is most common and compelling with overloaded
 * numeric operators such as + and -.
 */

/* 
TODO: Overloading Unary Operators
class Money {
 public:
  friend Money operator+(const Money &amount1, const Money &amount2);
  friend Money operator-(const Money &amount1, const Money &amount2);
  friend Money operator-(const Money &amount);
  friend bool operator==(const Money &amount1, const Money &amount2);
  Money(int64_t dollars, int cents);
  Money(int64_t dollars);
  Money();
  double getValue() const;
  void input(istream &ins);
  void output(ostream &outs) const;
 private:
  int64_t allCents;
};
...other codes

* minus sign overloaded as binary
Money operator-(const Money &amount1, const Money &amount2) {
  Money temp;
  temp.allCents = amount1.allCents - amount2.allcents;
  return temp;
}

* minus sign overloaded as unary
Money operator-(const Money &amount) {
  Money temp;
  temp.allCents = -amount.allCents;
  return temp;
}
 */

/* 
TODO: Overloading >> and << (binary)
?Think of what val should be returned when overloading?
The operator << should return its first arg, which is a stream of type ostream
eg:
 class Money {
  public:
   ...
   !Whenever an operator (or a func) returns a stream, you must add an & to the 
   !end of the name for the returned type, it'll allow you to overload the <</>>
   !Add & to the name of a returned type means the operator (or func) returns a 
   !ref. It means to return obj (stream) itself rather than the value of obj.
   !ostream& is the returned type, mind the &
   friend ostream &operator<<(ostream &outs, const Money &amount);
   * precondition: if outs is a file output stream, then outs has alreay been
   * connected to a file.
   * postcondition: a dollar sign and the amount of money recorded in the 
   * calling obj have been sent to the output stream outs.
   ostream &operator<<(ostream &outs, const Money &amount) {
     long positiveCents dollars, cents;
     positiveCents = labs(amount.allCents);
     dollars = positiveCents / 100;
     cents = positiveCents % 100;
   }
   ...

   W/ the extraction(input) operator >>, the 2nd arg will be the obj that 
   receives the input val, so the 2nd param must be an ordinary call-by-ref 
   param.
   istream &operator>>(istream &ins, Money &amount) {
     ...
     return ins;
   }
 }
 ! >>/<< can be overloaded just like other operators. The returned val must be
 !the stream. The type for the val returned must have the & symbol added to the
 !end of the type name.
 syntax:
  class ClassName {
   public:
    friend istream& operator>>(istream& param_1, ClassName& param_2);
    friend ostream& operator<<(ostream& param_3, const ClassName& param_4);
  }
 */
