#include <iostream>
#include <iomanip>

int main() {
  int num {};
  std::cout << "Enter an integer value: ";
  std::cin >> num;
  
  std::cout << std::hex << std::setfill('0');

  std::cout << "\nValue:                            num = " << std::setw(8) << num;
  std::cout << "\nFlipped all bits:                ~num = " << std::setw(8) << ~num;
  std::cout << "\nFlipped all bits and add 1:  ~num + 1 = " << std::setw(8) << ~num + 1;
}
