#include <iostream>
#include <array>
#include <vector>

template <typename T, size_t N>
inline size_t my_size(const T (&array)[N]) {
  return N;
}

template <typename T>
inline size_t my_size(const std::vector<T>& vector) {
  return vector.size();
}

template <typename T, size_t N>
inline size_t my_size(const std::array<T,N>& array) {
  return N;
}

int main() {
  double doubles[] { 1.0, 2.0, 3.0, 4.0, 5.0};
  std::cout << "The size of doubles is " << my_size(doubles) << std::endl;
  std::array<int, 5> ints {1, 2, 3, 4, 5};
  std::cout << "The size of ints is " << my_size(ints) << std::endl;
  std::vector<double> vector_doubles {1.2, 0.3, 5.6, 8.2};
  std::cout << "The size of vector_doubles is " << my_size(vector_doubles) << std::endl;
}
