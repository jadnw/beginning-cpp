#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

int main() {
  std::string text {};
  std::cout << "Enter the text: ";
  std::getline(std::cin, text, '*');
  std::string word {};
  std::cout << "Enter the word: ";
  std::cin >> word;

  std::string lower_word;
  for (auto ch : word) {
    lower_word += std::tolower(ch);
  }

  const std::string replacement(word.length(), '*');
  const std::string separators {" .,:;\"!?'\n"};
  size_t start {text.find_first_not_of(separators)};
  while (start != std::string::npos) {
    size_t end {text.find_first_of(separators, start + 1)};
    if (end == std::string::npos) end = text.length();

    if (end - start == word.length()) {
      bool is_same_word {true};
      for (size_t i {start}; i < end; ++i) {
        if (lower_word[i - start] != std::tolower(text[i])) {
          is_same_word = false;
          break;
        }
      }

      if (is_same_word) text.replace(start, end, replacement);
    }

    start = text.find_first_not_of(separators, end + 1);
  }

  std::cout << text << std::endl;
}
