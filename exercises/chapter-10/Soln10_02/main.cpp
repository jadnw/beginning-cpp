#include <iostream>
#include "print.h"
#include "printthis.h"
#include "printthat.h"

int main() {
  print_this("This is a string");
  print_that("This is another string");
  std::cout << "The print() function called " << call_count << " time(s)." << std::endl;
}
