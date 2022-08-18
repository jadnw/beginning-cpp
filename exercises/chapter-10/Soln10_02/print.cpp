#include <iostream>
#include "print.h"

size_t call_count {};
void print(std::string_view str) {
  ++call_count;
  std::cout << str << std::endl;
}
