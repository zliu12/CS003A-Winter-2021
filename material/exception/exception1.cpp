/**
 *  Try and Exception.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/*
1.抛出异常：
  throw 表达式；
  异常通常以类似于实参(有预先赋值的参数)传递给函数的方式(由throw)抛出和(被catch)捕获，throw
  表达式的类型决定了所抛出的异常类型。
  c++根据类型来区分不同的异常，所以throw表达式的类型非常重要；
  若抛出多处异常，则需用不用表达式类型互相区别：
  if （test == 0）throw test；  // 抛出int型异常
  if （test == 1）throw ‘a'；  // 抛出char型异常
  if （test == 2）throw 333.23  // 抛出double型异常 
*关于throw的说明：
  1.执行throw时，不会跟在throw后面的语句，程序（暂停）从throw转移到匹配的catch，该catch
  可以是同一函数中的catch，也可以在直接/间接调用发生异常函数的上一级函数中。
  2.被抛出的对象是一个用throw表达式初始化的“异常对象”，由throw创建并初始化为被抛出的表达式
  副本，传递给catch，异常处理完成后撤销，因此异常对象必须是可以复制的类型（具有复制构造函数）。
  3.若抛出数组，则抛出对象自动转换为指向该数组首元素的指针，若抛出一个函数，则转换为指向该函数
  的指针。
  4.若抛出一个指向派生类对象的基类指针，则对象被分割，只抛出基类部分，不含派生类部分。
  5.抛出指针不能指向局部对象，必须确保进入异常处理程序时指针所指的对象仍然存在，即指针指向全局
  对象。
2.检测捕获异常/syntax:
  try {
    检测程序块（可能抛出异常的代码）
  } catch （异常说明符1/类型名） {
    处理程序（当异常说明符1被抛出时执行的程序）
  } catch （异常说明符2/类型名 形参名） {
    处理程序（当异常说明符2被抛出时执行的程序）
  } catch (...(3个点代表任何类型的异常)) {
    若有多个catch，catch(...)必须放在最后
  }
3.异常处理的执行过程：
  1.程序执行try，无异常则不执行catch，跳过。
  2.抛出异常时，程序暂停，开始查找匹配的catch子句。
  3.首先检查throw是否在try内部，如果是，检查catch子句，看是否匹配抛出对象，匹配成功则处理，
  不成功则退出当前函数并释放局部对象，然后继续在调用函数（上一级函数）中查找。
  4.沿着嵌套函数调用链查找，直到找到一个匹配的catch子句。
 */
#include <cstdio>
void fun(int test) {
  if (test == 0) {
    throw test;   // throw type int
  } 
  if (test == 1) {
    throw 1.5;    // throw type double
  } 
  if (test == 2) {
    throw "abc";    // throw type char
  }
  printf("fun调用正常结束\n");
}

void caller1(int test) {
  try {
    // 检测异常
    fun(test);
    // 捕获异常
  } catch(int) {
    printf("caller1捕获int, ");
  }
  printf("caller1调用正常结束\n");
}

void caller2(int test) {
  try {
    caller1(test);
  } catch(double) {
    printf("caller2捕获double, ");
  } catch(...) {
    printf("caller2捕获所有未知异常, ");
  }
  printf("caller2调用正常结束\n");
}

int main() {
  for (int i = 5; i >= 0; i--) {
    caller2(i);
  }
  return 0;
}