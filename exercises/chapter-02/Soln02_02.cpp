#include <iostream>
#include <iomanip>

int main() {
  const double pi {3.141592653589793238};

  double radius {};
  std::cout << "Enter the radius of the circle: ";
  std::cin >> radius;

  unsigned digits {};
  std::cout << "Enter the number of digits required: ";
  std::cin >> digits;

  double area { pi * radius * radius };
  std::cout << "The area of the circle is " << std::setprecision(digits) << area << std::endl;
}
