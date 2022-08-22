#include <iostream>

class Integer {
private:
  int value {};

public:
  Integer(int val) : value {val} {};
  // Use default constructor
  Integer() = default;
  // Use constructor without arguments
  // Integer() : value {0} {};
  Integer(const Integer& num) : value {num.value} {
    std::cout << "The copy constructor called." << std::endl;
  }
  int getVal() {
    return value;
  }
  void setVal(int valToSet) {
    value = valToSet;
  }
};

int main() {
  Integer num {3};
  std::cout << "The integer value is " << num.getVal() << std::endl;
  num.setVal(4);
  std::cout << "The integer value after setting is " << num.getVal() << std::endl;
  const Integer constNum {1};
  Integer defaultNum {};
  std::cout << "The value of defaultNum is " << defaultNum.getVal() << std::endl;
  Integer copyNum {num};
}
