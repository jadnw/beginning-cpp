#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <ostream>

class Rational {
private:
  int num {};
  int den {1};
public:
  Rational(int numerator, int denominator) : num {numerator}, den {denominator} {}
  Rational() = default;

  friend std::ostream& operator<<(std::ostream& s, const Rational& r);

  // Inverse
  inline Rational operator~() const {
    return Rational { den, num };
  }

  // Addition
  inline Rational operator+(const Rational& r) const {
    return Rational { num * r.den + den * r.num, den * r.den };
  }

  // Subtraction
  inline Rational operator-(const Rational& r) const {
    return Rational { num * r.den - den * r.num, den * r.den };
  }

  // Multiplication
  inline Rational operator*(const Rational& r) const {
    return Rational { num * r.num, den * r.den };
  }

  // Division
  inline Rational operator/(const Rational& r) const {
    return *this * (~r);
  }

  // Negate
  inline Rational operator-() const {
    return Rational { -num, den };
  }

  // Increment
  inline Rational operator++() {
    num += den;
    return *this;
  }
  inline Rational operator++(int) {
    auto copy {*this};
    ++(*this);
    return copy;
  }

  // Decrement
  inline Rational operator--() const {
    return Rational { num - den, den };
  }

  explicit operator double() {
    return static_cast<double>(num) / den;
  }

  explicit operator float() {
    return static_cast<float>(num) / den;
  }
};

#endif
