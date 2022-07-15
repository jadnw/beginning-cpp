#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  const double pi {3.141592653589793238};
  const double inches_per_foot {12.0};

  unsigned hi {};
  std::cout << "Enter h in inches: ";
  std::cin >> hi;

  unsigned df {}, di {};
  std::cout << "Enter d in feet and inches: ";
  std::cin >> df >> di;

  unsigned angle_d {};
  std::cout << "Enter angle in degrees: ";
  std::cin >> angle_d;

  double h { hi / inches_per_foot };
  double d { df + di / inches_per_foot };
  double angle { angle_d * pi / 180};

  double tree_height {h + d * std::tan(angle)};
  std::cout << "The tree height is " << tree_height << " feet." << std::endl;
}
