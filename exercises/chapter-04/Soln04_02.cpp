#include <iostream>
#include <iomanip>

int main() {
  int first {}, second {};

  std::cout << "Enter two integers: ";
  std::cin >> first >> second;

  if (first <= 0 || second <= 0) {
    std::cout << "One of theme is zero or negative number." << std::endl;
    return 1;
  }

  if (first % second == 0) {
    std::cout << first << " is an exact multiple of " << second << std::endl;
    return 0;
  }

  if (second % first == 0) {
    std::cout << second << " is an exact multiple of " << first << std::endl;
    return 0;
  }

  std::cout << "There is no number that is an exact multiple of another." << std::endl;
}
