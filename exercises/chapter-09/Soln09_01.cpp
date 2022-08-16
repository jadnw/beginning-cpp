#include <iostream>

template <typename T> T my_clamp(T a, T b, T c);

int main() {
  std::cout << "The clamp value of 128 in [0, 255] is " << my_clamp(128, 0, 255) << std::endl;
  std::cout << "The clamp value of -8 in [0, 255] is " << my_clamp(-8, 0, 255) << std::endl;
  std::cout << "The clamp value of 300 in [0, 255] is " << my_clamp(300, 0, 255) << std::endl;
  std::cout << "The clamp value of 28.5 in [1.5, 25.5] is " << my_clamp(28.5, 1.5, 25.5) << std::endl;
}

template <typename T> T my_clamp(T a, T b, T c) {
  return a < b ? b : (a > c ? c : a);
}
