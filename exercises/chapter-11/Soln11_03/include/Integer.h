#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>

class Integer {
private:
  int value {};

public:
  Integer(int val);
  Integer() = default;
  Integer(const Integer& obj);

  int getValue() const {
    return value;
  };
  void setValue(int val) {
    value = val;
  };
  void show() const;
  // int compare(Integer obj) const;
  int compare(const Integer& obj) const;
  Integer& add(const Integer& obj);
  Integer& subtract(const Integer& obj);
  Integer& multiply(const Integer& obj);
};

#endif
