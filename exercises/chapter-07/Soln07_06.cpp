#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main() {
  std::string text;
  std::cout << "Enter the text string (terminated by *):\n";
  std::getline(std::cin, text, '*');

  std::string letters;
  std::cout << "\nEnter a string containing one or more letters:\n";
  std::cin >> letters;
  for (char& ch : letters) {
    ch = std::tolower(ch);
  }
  std::cout << letters << std::endl;

  std::vector<std::string> words;
  const std::string separators {" .,:;\"!?'\n"};
  size_t start {text.find_first_not_of(separators)};
  while (start != std::string::npos) {
    size_t end {text.find_first_of(separators, start + 1)};
    if (end == std::string::npos) end = text.length();
    std::string word {text.substr(start, end - start)};
    if (letters.find(std::tolower(word[0])) != std::string::npos) {
      words.push_back(word);
    }
    start = text.find_first_not_of(separators, end + 1);
  }

  std::cout << "The resulting words are: ";
  for (size_t i {}; i < words.size(); ++i) {
    std::cout << words[i];
    if (i < words.size() - 1) std::cout << ", ";
  }
  std::cout << std::endl;
}
