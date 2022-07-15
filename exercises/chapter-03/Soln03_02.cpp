#include <iostream>
#include <iomanip>

int main() {
  const unsigned inches_per_foot {12};

  double shelf_length {};
  double shelf_depth {};

  std::cout << "Enter the length and the depth of the shelf: ";
  std::cin >> shelf_length >> shelf_depth;

  int box_side {};
  std::cout << "Enter the side of the box: ";
  std::cin >> box_side;

  long number_of_boxes { static_cast<long>((shelf_length * shelf_depth) * inches_per_foot * inches_per_foot / (box_side * box_side)) };
  std::cout << "Number of the boxes: " << number_of_boxes << std::endl;
}
