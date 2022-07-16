#include <iostream>
#include <iomanip>
#include <array>

int main() {
  std::array<unsigned long long, 93> fib {1, 1};
  // overflow in 94th element

  for (size_t i {2}; i < fib.size(); ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  for (auto num : fib) {
    std::cout << num << std::endl;
  }
}
