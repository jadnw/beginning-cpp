#include <Rational.h>

std::ostream& operator<<(std::ostream& s, const Rational& r) {
  s << r.num << "/" << r.den;
  return s;
}

int main() {
  Rational r1 {1, 2};
  Rational r2 {2, 3};
  std::cout << "The value of r1 is " << r1 << std::endl;
  std::cout << "The value is r2 is " << r2 << std::endl;
  Rational add {r1 + r2};
  std::cout << "The value of r1 + r2 is " << add << std::endl;
  Rational sub {r1 - r2};
  std::cout << "The value of r1 - r2 is " << sub << std::endl;
  Rational mul {r1 * r2};
  std::cout << "The value of r1 * r2 is " << mul << std::endl;
  Rational div {r1 / r2};
  std::cout << "The value of r1 / r2 is " << div << std::endl;
  Rational inv {~r1};
  std::cout << "The value of ~r1 is " << inv << std::endl;
  Rational neg {-r1};
  std::cout << "The value of -r1 is " << neg << std::endl;
  double d {r1};
  std::cout << "The double value of r1 is " << d << std::endl;
  float f {r1};
  std::cout << "The float value of r1 is " << f << std::endl;
}
