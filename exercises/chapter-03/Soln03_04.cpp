#include <iostream>
#include <iomanip>

int main() {
  char a {}, b {}, c {}, d {};
  std::cout << "Enter 4 characters a, b, c, d: ";
  std::cin >> a >> b >> c >> d;

  int packed { (a << 24) | (b << 16) | (c << 8) | d  };
  int mask {0xFF};
  std::cout << "\nPacked = " << std::setw(8) << packed << std::endl;

  std::cout << "Four characters in reverse order: " << std::endl;
  std::cout << "d = " << static_cast<char>(packed & mask)  << std::endl;
  std::cout << "c = " << static_cast<char>((packed >> 8) & mask)  << std::endl;
  std::cout << "b = " << static_cast<char>((packed >> 16) & mask)  << std::endl;
  std::cout << "a = " << static_cast<char>((packed >> 24) & mask)  << std::endl;
}
