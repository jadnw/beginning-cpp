#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>

class Integer {
private:
  int value {};

public:
  // Use default constructor
  Integer() = default;
  Integer(int val);
  // Use constructor without arguments
  // Integer() : value {0} {};
  Integer(const Integer& num);

  int getValue() const;
  void setValue(int val);

  // int compare(Integer aNum);
  int compare(const Integer& aNum);
};

#endif
