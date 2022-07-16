#include <iostream>

int main() {
  char ch {};
  unsigned count {};
  std::cout << "Enter a sequence of characters (# to terminate): " << std::endl;

  do {
    std::cin >> ch;
    if (ch != ' ') count++;
  } while (ch != '#');

  --count; // do not count the last character #
  std::cout << "You have entered " << count << " characters." << std::endl;
}
