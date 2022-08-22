#include "Integer.h"

int main() {
  Integer num1 {4};
  Integer num2 {3};
  int comparisonResult {num1.compare(num2)};
  if (comparisonResult > 0)
    std::cout << "num1 is greater than num2." << std::endl;
  else if (comparisonResult < 0)
    std::cout << "num1 is less than num2." << std::endl;
  else
    std::cout << "num1 is equal to num2." << std::endl;
}

// We cannot have both functions in the class as overloaded functions because the compiler cannot
// determine which functions should compile.
// Passing by value calls the copy constructor, but passing by reference does not.
