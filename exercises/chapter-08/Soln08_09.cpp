#include <iostream>
#include <iomanip>

long double power(double x, int n);

int main() {
  for (int i {-3}; i <= 3; ++i) {
    std::cout << std::setw(10) << power(8.0, i);
  }
  std::cout << std::endl;
}

inline auto mult(long double a, long double b) {
  static size_t count {};
  std::cout << "Counting: " << ++count << std::endl;
  return a * b;
}

long double power(double x, int n) {
  if (n == 0) return 1.0;
  if (n < 0) return 1.0 / power(x, -n);
  if (n % 2) return mult(x, power(x, n - 1));
 
  const auto y = power(x, n / 2);
  return mult(y, y);
}
