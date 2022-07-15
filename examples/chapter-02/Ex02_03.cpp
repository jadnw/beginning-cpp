#include <iostream>
#include <cmath>

int main() {
  const double fish_factor { 2.0 / 0.5 };
  const double inches_per_foot { 12.0 };
  const double pi { 3.1411592653589793238};

  double fish_count {};
  double fish_length {};

  std::cout << "Enter the number of fish you want to keep: ";
  std::cin >> fish_count;
  std::cout << "Enter the average fish length in inches: ";
  std::cin >> fish_length;
  fish_length /= inches_per_foot; // convert to feet
  
  const double pond_area { fish_count * fish_length * fish_factor };
  const double pond_diameter { 2.0 * std::sqrt(pond_area / pi) };

  std::cout << "\nPond diameter required for " << fish_count << " fish is "
    << std::round(pond_diameter) << " feet.\n";
}
