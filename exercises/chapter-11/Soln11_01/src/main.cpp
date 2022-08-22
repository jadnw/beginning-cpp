#include "Integer.h"

int main() {
  Integer num1 {1};
  Integer num2 {2};
  num1.show();
  num2.show();
  num1.setValue(3);
  num1.show();
  const Integer constNum {1};
  constNum.show();
  std::cout << "Try to get value of a const Integer: " << constNum.getValue() << std::endl;
  // constNum.setValue(4); // compile error
}
