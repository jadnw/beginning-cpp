#include <iostream>
#include <iomanip>
#include <cmath>
#include <memory>

int main() {
  unsigned size {};
  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  auto nums {std::make_unique<double[]>(size)};

  for (size_t i {}; i < size; ++i) {
    nums[i] = 1.0 / ((i + 1) * (i + 1));
  }

  double sum {};
  for (size_t i {}; i < size; ++i) {
    sum += nums[i];
  }

  double result = std::sqrt(sum * 6);
  std::cout << "The output is " << std::fixed << std::setprecision(2) << result << std::endl;
}
