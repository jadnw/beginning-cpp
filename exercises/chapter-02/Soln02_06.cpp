#include <iostream>

int main() {
  long a {}, b {};

  std::cout << "Enter two positive integers: ";
  std::cin >> a >> b;

  long large = static_cast<long>((a * a / b + b * b / a) / (a / b + b / a));
  long small = static_cast<long>((a * b / a + b * a / b) / (a / b + b / a));

  std::cout << "The large integer is " << large << std::endl;
  std::cout << "The small integer is " << small << std::endl;
}
