#include <iostream>

int main() {
  int num {};
  std::cout << "Enter an integer: ";
  std::cin >> num;

  std::cout << (num <= 20 ? "Number is less or equal to 20" : ((num > 20 && num <= 30) ? "Number is greater than 20 but not greater than 30." : (num > 30 && num <= 100) ? "Number is greater than 30 but not exceeding 100" : "Number is greater than 100")) << std::endl;
}
