#include <iostream>
#include <cctype>

int main() {
  int total {};
  double average {};

  char yes {'y'};
  size_t count {};

  while (std::tolower(yes) == 'y') {
    int num {};
    std::cout << "Enter an integer: ";
    std::cin >> num;
    total += num;
    average = static_cast<double>(total) / ++count;
    std::cout << "Count: " << count << ", Total: " << total << ", Average: " << average << std::endl;

    std::cout << "Do you want continue? [y/N]: ";
    std::cin >> yes;
  }
}
