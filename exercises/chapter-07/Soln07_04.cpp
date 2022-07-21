#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string first, second;
  std::cout << "Enter two words: ";
  std::cin >> first >> second;

  if (first.length() != second.length()) {
    std::cout << first << " and " << second << " are not anagrams of one another.";
    return 0;
  }

  std::string second_copy {second};
  for (char ch : first) {
    for (size_t i {}; i < second_copy.length(); ++i) {
      if (std::tolower(second_copy[i]) == std::tolower(ch)) {
        second_copy.erase(i, 1);
        break;
      }
    }
  }

  std::cout << first << " and " << second << " are "
    << (second_copy.empty() ? "" : " not ")
    << "anagrams of one another." << std::endl;
}
