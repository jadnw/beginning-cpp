#include <iostream>
#include <iomanip>

int main() {
  const unsigned inches_per_foot {12};

  unsigned length {};
  std::cout << "Enter the length in inches: ";
  std::cin >> length;

  unsigned feet {static_cast<unsigned>(length / inches_per_foot)};
  unsigned inches {static_cast<unsigned>(length % inches_per_foot)};
  
  std::cout << "The length is " << feet << " feets, " << inches << " inches.\n";
}
