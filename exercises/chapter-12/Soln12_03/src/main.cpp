#include <iostream>
#include <iomanip>
#include <ostream>
#include "Box.h"

std::ostream& operator<<(std::ostream& stream, const Box& box) {
  stream << "Box(" << std::setw(3) << box.getLength() << ','
    << std::setw(3) << box.getWidth() << ','
    << std::setw(3) << box.getHeight() << ')';
  return stream;
}

Box operator*(double n, const Box& box) {
  return Box { n * box.getLength(), n * box.getWidth(), n * box.getHeight() };
}

Box operator+(const Box& box1, const Box& box2) {
  return Box { std::max(box1.getLength(), box2.getLength()), std::max(box1.getWidth(), box2.getWidth()), box1.getHeight() + box2.getHeight() };
}

Box operator/(double n, const Box& box) {
  return Box { n / box.getLength(), n / box.getWidth(), n / box.getHeight() };
}

int main() {
  Box box1 {1, 1, 1};
  Box box2 {2, 2, 2};
  Box box3 {box1 + box2};
  std::cout << "box3 is " << box3 << std::endl;
  Box box4 {box2 / 2};
  std::cout << "box4 is " << box4 << std::endl;
  Box box5 {1 / box2};
  std::cout << "box5 is " << box5 << std::endl;
}
