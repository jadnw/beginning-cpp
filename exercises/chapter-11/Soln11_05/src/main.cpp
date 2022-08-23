#include "Integer.h"

void showIntRef(const Integer& obj) {
  obj.show();
  Integer::printCount(); // passing by reference, object count doesn't change
}

void showIntVal(Integer obj) {
  obj.show();
  Integer::printCount(); // passing by value, object count temporarily increases
}

int main() {
  Integer zero {};
  Integer one {1};
  Integer::printCount(); // 2
  Integer nums[] {2, 3, 4};
  Integer::printCount(); // 5
  showIntRef(nums[0]); // 5
  showIntVal(nums[1]); // 6
  Integer::printCount(); // 5
}
