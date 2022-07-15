#include <iostream>
#include <cmath>

int main() {
  const double pi {3.141592653589793238};

  double radius {};
  std::cout << "Enter the radius of the circle: ";
  std::cin >> radius;

  double area { pi * radius * radius };
  std::cout << "The area of the circle is " << area << std::endl;
}
