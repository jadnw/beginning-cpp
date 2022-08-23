#include "Integer.h"

int main() {
  Integer four {4};
  Integer six {6};
  Integer eight {8};

  Integer result {four};
  std::cout << "The result is "
    << result.multiply(5).add(six).multiply(5).add(7).multiply(5).add(eight).getValue()
    << std::endl;
}
