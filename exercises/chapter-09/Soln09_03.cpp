#include <iostream>
#include <string>

template <typename T1, typename T2> auto plus(T1 a, T2 b) -> decltype(a + b) {
  return a + b;
};
// overload with another template for pointer types
template <typename T1, typename T2> auto plus(const T1* a, const T2* b) -> decltype(*a + *b) {
  return *a + *b;
};

std::string plus(const char* a, const char* b) {
  return std::string{a} + b;
};

int main() {
  std::cout << plus(1, 1.2) << std::endl;
  std::string s1 {"aaa"};
  std::string s2 {"bbb"};
  std::cout << plus(s1, s2) << std::endl;
  // extra part
  std::cout << plus("He", "llo") << std::endl;
}
