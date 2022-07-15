#include <iostream>
#include <iomanip>

int main() {
  int a {}, b {};
  std::cout << "Enter two integers: ";
  std::cin >> a >> b;
  
  a ^= b;
  b ^= a;
  a ^= b;
  
  std::cout << "Swapped values: " << std::endl;
  std::cout << "swapped a = " << a << std::endl;
  std::cout << "swapped b = " << b << std::endl;
}
