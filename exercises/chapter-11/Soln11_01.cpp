#include <iostream>

class Integer {
private:
  int value {};

public:
  Integer(int val) : value {val} {};
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
  // The following lines cause compile errors
  // std::cout << constNum.getVal() << std::endl; 
  // constNum.setVal(2);
}
