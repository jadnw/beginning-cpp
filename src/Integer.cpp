#include <iostream>
#include "Integer.h"

Integer::Integer(int val) : value {val} {};

Integer::Integer(const Integer& num) : value {num.value} {
  std::cout << "The copy constructor called." << std::endl;
}

int Integer::getValue() const {
  return value;
}

void Integer::setValue(int val) {
  value = val;
}

int Integer::compare(const Integer& aNum) {
  if (value < aNum.getValue()) return -1;
  if (value > aNum.getValue()) return 1;
  return 0;
}
