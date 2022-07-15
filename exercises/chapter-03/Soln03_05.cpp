#include <iostream>
#include <iomanip>

int main() {
  enum class Color { Red = 0xff0000, Green = 0xff00, Yellow = 0xffff00, Purple = 0x800080, Blue = 0xff, Black = 0, White = 0xffffff };
  Color yellow = Color::Yellow;
  Color purple = Color::Purple;
  Color green = Color::Green;

  std::cout << std::hex << std::setfill('0');
  std::cout << "yellow = " << static_cast<int>(yellow) << std::endl;
  std::cout << "purple = " << static_cast<int>(purple) << std::endl;
  std::cout << " green = " << static_cast<int>(green) << std::endl;
}
