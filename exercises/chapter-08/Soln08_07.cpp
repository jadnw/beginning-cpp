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
  switch(n) {
    case 0: return 0;
    case 1: return 1;
    default: return fib(n - 1) + fib(n - 2);
  }
}
