// Using a function with a reference parameter in the Integer class
/*****************************************************************\
 Using the version of compare() with the pass-by-value parameter,
 the copy constructor is called because a copy of the argument
 is passed to the function.
 Using the version with the reference parameter a reference
 to the object is passed to the function so no constructor call
 is necessary.
 You cannot overload a function with a reference parameter with
 a function that has a non-reference parameter because the
 compiler cannot tell which function should be called in any 
 particular instance.
\*****************************************************************/
#include <iostream>
#include "Integer.h"

Integer::Integer(int val) : value {val} {
  ++count;
  std::cout << "An object created." << std::endl;
};

Integer::Integer() {
  ++count;
  std::cout << "An object created with default constructor." << std::endl;
}

Integer::Integer(const Integer& obj) : value {obj.value} {
  ++count;
  std::cout << "The copy constructor called." << std::endl;
};

Integer::~Integer() {
  --count;
}

void Integer::show() const {
  std::cout << "Value is " << value << std::endl;
}

int Integer::compare(const Integer& obj) const {
  if (value < obj.value) return -1;
  if (value == obj.value) return 0;
  return 1;
}
