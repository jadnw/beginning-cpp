#include <iostream>
#include <iomanip>
#include <array>

int main() {
  const unsigned max {50};
  int nums[max] {};
  
  unsigned count {1};
  size_t i {};
  while (i < max) {
    if (count % 2 != 0) {
      nums[i++] = count;
    }
    count++;
  } 

  const unsigned perline = 10;
  std::cout << "The numbers from array: \n";
  for (size_t i {}; i < max; ++i) {
    std::cout << std::setw(6) << *(nums + i); // error if using std::array
    if (++count % 10 == 0) std::cout << std::endl;
  }

  std::cout << "The numbers from array in reverse order: \n";
  for (size_t i {}; i < max; ++i) {
    std::cout << std::setw(6) << *(nums + max - 1 - i);
    if (++count % 10 == 0) std::cout << std::endl;
  }
}
