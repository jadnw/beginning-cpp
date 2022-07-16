#include <iostream>

int main() {
  const unsigned limit {1000};
  char chars[limit] {};

  std::cout << "Enter a line of characters: " << std::endl;
  std::cin.getline(chars, limit);
  
  unsigned count {};
  while (chars[count] != '\0') ++count;

  std::cout << "You have entered " << count << " characters." << std::endl;

  std::cout << "The line of characters in reverse order is: ";
  size_t i {1};
  while (i <= count) {
    std::cout << chars[count - i++];
  }
  std::cout << std::endl;
}
