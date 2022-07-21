#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string first, second;
  std::cout << "Enter the first words: ";
  std::getline(std::cin, first);
  std::cout << "Enter the second words: ";
  std::getline(std::cin, second);

  std::string second_copy {second};
  for (char ch : first) {
    for (size_t i {}; i < second_copy.length(); ++i) {
      if (std::tolower(second_copy[i]) == std::tolower(ch)) {
        second_copy.erase(i, 1);
        break;
      }
    }
  }

  bool is_empty_or_contains_whitespaces {true};
  if (!second_copy.empty()) {
    for (char ch : second_copy) {
      if (ch != ' ') {
        is_empty_or_contains_whitespaces = false;
        break;
      }
    }
  }

  std::cout << first << " and " << second << " are "
    << (is_empty_or_contains_whitespaces ? "" : " not ")
    << "anagrams of one another." << std::endl;
}
