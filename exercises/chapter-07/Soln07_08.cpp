#include <iostream>
#include <string>

int main() {
  std::string nums;
  std::cout << "Enter the sequence of integers:\n";

  std::string input {};
  while (true) {
    std::cin >> input;
    if (input == "#") break;
    nums += input + " "; 
  };

  long sum {};
  size_t index {};
  while (true) {
    const size_t found = nums.find(' ', index);
    if (found == std::string::npos) break;
    const size_t length = found - index;
    sum += std::stoi(nums.substr(index, length));
    index = found + 1;
  }

  std::cout << sum << std::endl;
}
