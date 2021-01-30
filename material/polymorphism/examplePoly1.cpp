/**
 * Polymorphism Exmaple.
 *
 * Copyright (c) [2021], Qichang.L
 */

/* 
TODO: Advantage of using polymorphism
1.代码组织结构清晰
2.可读性强
3.利于前期和后期的扩展及维护
 */

#include <cstdio>
#include <string>

class Calculator {
 public:
  int getResult(std::string oper) {
    if (oper == "+") {
      return num1 + num2;
    } else if (oper == "-") {
      return num1 - num2;
    } else if (oper == "*") {
      return num1 * num2;
    }
    return 0;
    // 如果想扩展新功能，需求修改源码
    // 在真实的开发中，提倡开闭原则：对扩展进行开放，对修改进行关闭
  }

  int num1, num2; // 操作数1，2
};

void test1() {
  // 创建一个计算器的对象
  Calculator c;
  c.num1 = 10;
  c.num2 = 20;
  printf("%d + %d = %d\n", c.num1, c.num2, c.getResult("+"));
  printf("%d - %d = %d\n", c.num1, c.num2, c.getResult("-"));
  printf("%d * %d = %d\n", c.num1, c.num2, c.getResult("*"));
}

// 利用多态实现计算器
// 好处：
// 1.组织结构清晰，各法各类，谁出错，直接看单类，维护性高
// 2.可读性增强
// 3.对于前期和后期扩展，例如加一个平方，只需直接写class powerCalculator
// 实现计算器抽象类
class AbstractCalculator {
 public:
  virtual double getResult() {
    return 0;
  }
  double polyNum1, polyNum2;
};

// 加法计算类
class AddCalculator : public AbstractCalculator {
 public:
  double getResult() {
     return polyNum1 + polyNum2;
   }
};

// 减法计算类
class SubCalculator : public AbstractCalculator {
 public:
  double getResult() {
    return polyNum1 - polyNum2;
  }
};

// 乘法计算类
class MultiCalculator : public AbstractCalculator {
 public:
  double getResult() {
    return polyNum1 * polyNum2;
  }
};

// 除法计算类
class DivCalculator : public AbstractCalculator {
 public:
  double getResult() {
   if (polyNum2 == 0) {
     printf("Invalid divisor");
   }
   return polyNum1 / polyNum2;
  }
};

void test2() {
  // 多态使用条件：父类指针或引用指向子类对象
  // create a dynamic variable add
  AbstractCalculator *abc = new AddCalculator;
  abc->polyNum1 = 10;
  abc->polyNum2 = 20;
  printf("%.1lf + %.1lf = %.1lf\n", abc->polyNum1, abc->polyNum2, 
    abc->getResult());
  //! 用完记得销毁
  delete abc;

  // 不需要AbstractCalculator因为已经declare过了
  abc = new SubCalculator;
  abc->polyNum1 = 10;
  abc->polyNum2 = 20;
  printf("%.1lf - %.1lf = %.1lf\n", abc->polyNum1, abc->polyNum2,
    abc->getResult());
  delete abc;

  abc = new MultiCalculator;
  abc->polyNum1 = 10;
  abc->polyNum2 = 20;
  printf("%.1lf * %.1lf = %.1lf\n", abc->polyNum1, abc->polyNum2,
    abc->getResult());
  delete abc;

  abc = new DivCalculator;
  abc->polyNum1 = 10;
  abc->polyNum2 = 20;
  printf("%.1lf / %.1lf = %.1lf\n", abc->polyNum1, abc->polyNum2,
    abc->getResult());
  delete abc;
}

int main() {
  test1();
  test2();
  return 0;
}