/**
 * Polymorphism Example2.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/*
TODO: 制作饮品 
制作饮品大致流程：煮水，冲泡，入杯，加料
利用多态实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
 */

#include <cstdio>

class AbstractDrink {
 public:
  // pure virtual function
  virtual void boil() = 0;  // boil water
  virtual void brew() = 0;  // brew water
  virtual void pour() = 0;  // pour into the cup
  virtual void add() = 0;   // add seasoning
  void makeDrink() {
    boil();
    brew();
    pour();
    add();
  }
};

// make coffee
class Coffee : public AbstractDrink {
  void boil() {
    printf("Boil water.\n");
  }
  void brew() {
    printf("Brew coffee.\n");
  }
  void pour() {
    printf("Pour into the cup.\n");
  }
  void add() {
    printf("Add cream and sugar.\n");
  }
};

// make tea
class Tea : public AbstractDrink {
  void boil() {
    printf("Boil water.\n");
  }
  void brew() {
    printf("Brew tea.\n");
  }
  void pour() {
    printf("Pour into the cup.\n");
  }
  void add() {
    printf("Add nothing.\n");
  }
};

// process
void doWork(AbstractDrink *abs) {
  abs->makeDrink();
  // free the heap memory
}

void test1() {
  doWork(new Coffee);
  doWork(new Tea);
}

int main() {
  Coffee coffee1;
  AbstractDrink *tea = new Tea;
  AbstractDrink &coffee = coffee1;

  printf("Tea doWork:\n");
  doWork(tea);  // doWork(new Tea) also fine.

  printf("\nCoffee doWOrk:\n");
  doWork(&coffee1);   // doWorl(&coffee) also fine.

  printf("\ntest1:\n");
  test1();
  return 0;
}