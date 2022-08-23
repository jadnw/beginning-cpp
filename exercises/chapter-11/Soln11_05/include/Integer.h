#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>

class Integer {
private:
  int value {};
  static inline size_t count {};

public:
  Integer(int val);
  Integer();
  Integer(const Integer& obj);

  ~Integer();

  int getValue() const {
    return value;
  };
  void setValue(int val) {
    value = val;
  };
  void show() const;
  // int compare(Integer obj) const;
  int compare(const Integer& obj) const;
  static void printCount() {
    std::cout << "There are now " << count << " object(s)." << std::endl;
  }
};

#endif
