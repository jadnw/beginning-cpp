#include <iostream>
#include <iomanip>
#include <vector>

int main() {
  std::vector<unsigned> nums {};

  unsigned limit {};
  std::cout << "Enter an arbitrary upper bound: ";
  std::cin >> limit;

  if (limit <= 1) {
    std::cout << "Please enter a value that is greater than 1." << std::endl;
    return 0;
  }

  for (size_t i {1}; i <= limit; ++i) {
    nums.push_back(i);
  }

  const unsigned short perline {10};
  size_t count {};
  for (auto value : nums) {
    if (value % 7 != 0 && value % 13 != 0) {
      std::cout << std::setw(4) << value;
      ++count;
    }

    if (count == perline) {
      std::cout << std::endl;
      count = 0;
    }
  }
}
