#include <iostream>
#include "Box.h"

int main() {
  Box box1 {1,2,3};
  Box box2 {2,3,4};
  if (box1 < box2)
    std::cout << "box1 is less than box2" << std::endl;
}
