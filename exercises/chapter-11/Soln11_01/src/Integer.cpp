#include <iostream>
#include "Integer.h"

Integer::Integer(int val) : value {val} {
  std::cout << "An object created." << std::endl;
};

void Integer::show() const {
  std::cout << "Value is " << value << std::endl;
}
