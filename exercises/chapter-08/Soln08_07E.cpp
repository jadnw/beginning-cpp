#include <iostream>

unsigned long long fib(size_t n);

int main() {
  size_t num {};
  std::cout << "How many Fibonacci numbers shall I compute today?" << std::endl;
  std::cin >> num;

  for (size_t i {1}; i <= num; ++i)
    std::cout << "fib(" << i << ") = " << fib(i) << '\n';
}

unsigned long long fib(size_t n) {
  unsigned long long fib_i{0};
  unsigned long long fib_i_1{1};

  for (size_t i {}; i < n; ++i) {
    auto fib_i_2 = fib_i + fib_i_1;
    fib_i = fib_i_1;
    fib_i_1 = fib_i_2;
  }

  return fib_i;
}
