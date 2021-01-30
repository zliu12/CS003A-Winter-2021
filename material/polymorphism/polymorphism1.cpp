/**
 * Polymorphism - Theory.
 *
 * Copyright (c) [2021], Qichang.L
 */

/* 
TODO: Two types of polymorphism
1.static polymorphism: 
  1.1-function overloading:
    different params, types, numbers, orders etc...
  1.2-operator overloading:
    use operators on user-defined objects
2.dynamic polymorphism (runtime poly):
  2.1-derived class
  2.2-virtual function
3.Difference:
  3.1-Static: confirm the memory location of functions during the compile time
  3.2-Dynamic: Confirm the memory location of functions during the running time,
      当运行时才去确定函数地址，才去决定要使用哪一个函数
4.Dynamic Polymorphism requirment:
  4.1-Inheritance
  4.2-The virtual func in base class is redefined in the derived class
    4.2.1-重写（redefinition）：函数返回值类型，函数名，参数列表完全相同
5.Use of dynamic polymorphism:
  5.1-父类的指针或引用指向子类对象
 */
#include <cstdio>

class Animal {
 public:
  // virtual在此类中加入了一个4字节的虚函数(表)指针vfptr(virtual func ptr)，指向虚函
  // 数表vftable(virtual func table)，其内部记录了虚函数的地址及作用域
  // (&Animal::speak)
  virtual void speak() {
    printf("animal is speaking.\n");    
  }
};

class Cat : public Animal {
 public:
  // virtual doesn't have to be included in derived function
  // 当子类重写父类的虚函数时，子类中的虚函数表内部会替换成子类的虚函数地址
  // (&Cat::speak),同时父类虚函数表不变，当父类的指针或引用指向子类对象时，多态发生
  virtual void speak() {
    printf("cat is speaking.\n");
  }
};

class Dog : public Animal {
 public:
  void speak() {
    printf("dog is speaking.\n");
  }
};

// 执行speak函数
// 地址早绑定，在编译阶段确定函数地址
// 如果想得到cat speak，那这个函数地址不能提前绑定，需要在运行阶段绑定（晚绑定）
void doSpeak(Animal &animal) {  // Animal &animal = cat;
  animal.speak();
}

void test1() {
  Cat cat;
  doSpeak(cat);

  Dog dog;
  doSpeak(dog);
}

void test2() {
  printf("sizeof Animal = %ld\n", sizeof(Animal));
}

int main() {
  test1();
  test2();
  return 0;
}