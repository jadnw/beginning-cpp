#include <iostream>
#include <iomanip>

int main() {
  auto k {430u};
  auto j {(k >> 4) & ~(~0u << 3)};
  std::cout << std::hex << (k >> 4) << std::endl;
  std::cout << std::hex << ((~0u << 3)) << std::endl;
  std::cout << std::hex << j << std::endl;
}
