#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

int main() {
  std::string text;
  std::cout << "Enter the text:\n";
  std::getline(std::cin, text, '*');

  const std::string separators {" .,;:\"!?'\n"};
  std::vector<std::string> words;
  std::vector<size_t> counts;

  size_t start {text.find_first_not_of(separators)};
  while (start != std::string::npos) {
    size_t end {text.find_first_of(separators, start + 1)};
    if (end == std::string::npos) end = text.length();
    std::string word {text.substr(start, end - start)};

    // check if word exists in words
    bool exist {};
    for (size_t i {}; i < words.size(); ++i) {
      if (word.compare(words[i]) == 0) {
        ++counts[i];
        exist = true;
        break;
      }
    }

    if (!exist) {
      words.push_back(word);
      counts.push_back(1);
    }

    start = text.find_first_not_of(separators, end + 1);
  }

  // find the max word length
  size_t max_length {};
  for (auto& w : words) {
    if (w.length() > max_length) max_length = w.length();
  }

  std::stringstream ss {};
  for (size_t i {}; i < words.size(); ++i) {
    ss << std::setw(max_length) << std::left << words[i]
      << " - " << std::setw(2) << std::right << counts[i] << "    ";
    if (!((i + 1) % 3)) ss << std::endl;
  }

  std::string s {ss.str()};
  std::cout << s << std::endl;
}
