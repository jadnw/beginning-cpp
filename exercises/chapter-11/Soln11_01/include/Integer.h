#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>

class Integer {
private:
  int value {};

public:
  Integer(int val);

  int getValue() const {
    return value;
  };
  void setValue(int val) {
    value = val;
  };
  void show() const;
};

#endif
