#include <iostream>

int main() {
  double num {};
  std::cout << "Enter a number: ";
  std::cin >> num;

  if (num > 1 && num < 100) {
    if (num > 50) {
      std::cout << "Your number you entered is greater than 50" << std::endl;
    } else if (num < 50) {
      std::cout << "Your number you entered is less than 50" << std::endl;
    } else {
      std::cout << "Your number you entered is 50" << std::endl;
    }

    return 0;
  }

  std::cout << "Hmm. Number must be between 1 and 100." << std::endl;
  return 1;
}
