#include <iostream>
#include <string>

std::string reverse(std::string str);

int main() {
  std::string text;
  std::cout << "Enter the text to reverse" << std::endl;
  getline(std::cin, text, '*');
  std::string reversed {reverse(text)};
  std::cout << "Original string: " << text << std::endl;
  std::cout << "Reversed string: " << reversed << std::endl;
}

std::string reverse(std::string str) {
  const size_t length {str.length()};
  for (size_t i {}; i < length / 2; ++i) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
  return str;
}
