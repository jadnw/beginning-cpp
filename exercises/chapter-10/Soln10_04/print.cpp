#include <iostream>
#include "print.h"

void print1::print(std::string_view str) {
  std::cout << "Namespace print1: " << str << std::endl;
}

void print2::print(std::string_view str) {
  std::cout << "Namespace print2: " << str << std::endl;
}
