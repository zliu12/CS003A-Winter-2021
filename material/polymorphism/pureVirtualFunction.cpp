/**
 * 纯虚函数和抽象类
 *
 * Copyright (c) [2021], Zhao Liu.
 */

 /* 
 在多态中，通常父类中的虚函数的实现是毫无疑义的，主要都是调用子类重写的内容，因此可以将虚函数改
 为纯虚函数
 sytax:
virtual <return type> funcName (param...) = 0;
当类中有了纯虚函数，这个类也称为抽象类：
1.无法实例化对象
2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类*/

#include <cstdio>

class Base {
 public:
  // 纯虚函数
  // 只要有一个纯虚函数，这个类就是抽象类
  // 特点：
  // 1.无法实例化对象(Creating obj is unallowed)
  // 2.抽象类的子类必须要重写父类的纯虚函数，否则也属于抽象类
  virtual void func() = 0;
};

class Derived1 : public Base {
 public:
  // 只有打括号没有具体definition也算重写
  void func() {
    printf("Derived1函数调用\n");
  }
};

class Derived2 : public Base {
 public:
  void func() {
    printf("Derived2函数调用\n");
  }
};

void test1() {
  // 没有virtual void func() {} 时， 以下无法实例化
  // Base a;
  // new Base;
  // Derived b;
  Base *dp1 = new Derived1;
  Base *dp2 = new Derived2;
  dp1->func();
  dp2->func();
}

int main() {
  test1();
  return 0;
}