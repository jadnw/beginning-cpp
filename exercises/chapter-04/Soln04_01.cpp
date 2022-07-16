#include <iostream>
#include <iomanip>

int main() {
  int first {}, second {};

  std::cout << "Enter two integers: ";
  std::cin >> first >> second;

  if (first == second) {
    std::cout << "They are the same" << std::endl;
    return 0;
  }

  std::cout << "They are NOT the same" << std::endl;
}
