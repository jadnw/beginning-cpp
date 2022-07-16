#include <iostream>
#include <cctype>

int main() {
  char letter {};
  std::cout << "Enter a letter: ";
  std::cin >> letter;

  if (!std::islower(letter)) {
    std::cout << "Hmm. This letter is not lowercase.";
    return 0;
  }

  char lowercase_letter {static_cast<char>(std::tolower(letter))};

  if (!(lowercase_letter == 'a' || lowercase_letter == 'e' || lowercase_letter == 'o' || lowercase_letter == 'u' || lowercase_letter == 'i')) {
    std::cout << "Hmm. This letter is not a vowel.";
    return 0;
  }

  std::cout << "The letter is a vowel and lowercase" << std::endl;
  std::cout << "The letter is " << letter << std::endl;
  std::cout << "The character code = 0b"
    << ((letter & (1u << 7)) >> 7)
    << ((letter & (1u << 6)) >> 6)
    << ((letter & (1u << 5)) >> 5)
    << ((letter & (1u << 4)) >> 4)
    << ((letter & (1u << 3)) >> 3)
    << ((letter & (1u << 2)) >> 2)
    << ((letter & (1u << 1)) >> 1)
    << (letter & 1u)
    << std::endl;
}
