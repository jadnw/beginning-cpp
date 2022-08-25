#include <iostream>
#include <iomanip>
#include "Box.h"

Box operator*(double n, const Box& box) {
  return Box { n * box.getLength(), n * box.getWidth(), n * box.getHeight() };
}

int main() {
  Box box {1, 2, 3};
  Box fiveTimesBox { box * 5 };
  std::cout << "Box(" << std::setw(2) << fiveTimesBox.getLength() << ','
    << std::setw(2) << fiveTimesBox.getWidth() << ','
    << std::setw(2) << fiveTimesBox.getHeight() << ')'
    << std::endl;
}
