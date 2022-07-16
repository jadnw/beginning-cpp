#include <iostream>

int main() {
  int limit {};
  std::cout << "Enter a limit: ";
  std::cin >> limit;

  if (limit <= 1) {
    std::cout << "Hmm. Please enter a limit." << std::endl;
    return 0;
  }

  std::cout << "The squares of the odd intergers from 1 up to " << limit << ":" << std::endl;
  for (size_t i {1}; i <= limit; ++i) {
    if (i % 2 == 1) {
      std::cout << i * i << std::endl;
    }
  }
}
