#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  const double pounds_per_kg {2.2};
  const double inches_per_foot {12.0};
  const double meters_per_foot {0.3048};

  double w {};
  std::cout << "Enter the weight in pounds: ";
  std::cin >> w;
  w = w / pounds_per_kg;

  unsigned hf, hi {};
  std::cout << "Enter h in feet and inches: ";
  std::cin >> hf >> hi;
  double h = (hf + hi / inches_per_foot) * meters_per_foot;

  double bmi { w / (h * h) };

  std::cout << "The BMI is " << bmi << std::endl;
}
