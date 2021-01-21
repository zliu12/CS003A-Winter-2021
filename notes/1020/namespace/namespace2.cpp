/**
 * Creating and accessing  namespaces.
 *
 * Copyright (c) [2021], Qichang.L
 */

#include <iostream>

// Top level namespace
namespace Leopard {
  // Nested namespace
  namespace Javan {
    std::string name = "Javan Leopard";
  }

  namespace Persian {
    std::string name = "Persian Leopard";
  }

  std::string name = "Leopard";
  int speed = 80;

  // Class also behaves like a namespace for scoping
  class Panther {
   public:
    std::string type() {
      return "Panther";
    }
  };
}

namespace Tortoise {
  std::string name = "Tortoise";
  int speed = 0.01;
}

int main() {
  std::cout << Leopard::name << ": " << Leopard::speed << std::endl;
  std::cout << Tortoise::name << ": " << Tortoise::speed << std::endl;
  std::cout << Leopard::Javan::name << std::endl;
  std::cout << Leopard::Persian::name << std::endl;

  Leopard::Panther p1;
  std::cout << Leopard::name << ": " << p1.type() << std::endl;
}