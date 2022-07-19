#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <memory>

int main() {
  unsigned size {};
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  auto nums {std::make_unique<std::vector<double>>(size)};

  for (size_t i {}; i < size; ++i) {
    nums->push_back(1.0 / ((i + 1) * (i + 1)));
  }

  double sum {};
  for (auto num : *nums) {
    sum += num;
  }

  double result = std::sqrt(sum * 6); // approximately equal to pi
  std::cout << "The output is " << std::fixed << std::setprecision(2) << result << std::endl;
}
