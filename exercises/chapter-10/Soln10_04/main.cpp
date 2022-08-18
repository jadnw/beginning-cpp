#include <iostream>
#include "printthis.h"
#include "printthat.h"

int main() {
  #ifdef DO_THIS
    print_this("This is a string");
  #else
    print_that("This is another string");
  #endif
}
