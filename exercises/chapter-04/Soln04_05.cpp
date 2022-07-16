#include <iostream>

int main() {
  unsigned short mice {}, brown {}, white {};

  std::cout << "How many brown mice do you have? ";
  std::cin >> brown;
  std::cout << "How many white mice do you have? ";
  std::cin >> white;

  mice = brown + white;

  if (!mice) {
    return 0;
  }

  if (mice == 1) {
    std::cout << "It is a " << (brown == 1 ? "brown" : "white") << " mouse." << std::endl;
    return 0;
  }

  std::cout << "Of these mice, "
    << brown
    << (brown > 1 ? " are " : " is a ")
    << "brown"
    << (brown > 1 ? " mice." : " mouse.")
    << std::endl;
}
