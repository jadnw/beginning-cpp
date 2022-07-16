#include <iostream>
#include <cctype>

int main() {
  double amount {};
  std::cout << "Enter an amount of money: ";
  std::cin >> amount;

  if (amount < 0 || amount > 10) {
    std::cout << "Oops. Invalid money you have." << std::endl;
    return 1;
  } 

  unsigned cents {static_cast<unsigned>(amount * 100)};
  unsigned quarters {}, dimes {}, nickels {}, pennies {};

  quarters = cents / 25;
  cents %= 25;
  dimes = cents / 10;
  cents %= 10;
  nickels = cents / 5;
  pennies = cents % 5;

  std::cout << "You have to pay "
    << quarters << (quarters > 1 ? " quarters, " : " quarter, ")
    << dimes << (dimes > 1 ? " dimes, " : " dime, ")
    << nickels << (nickels > 1 ? " nickels, " : " nickel, ")
    << pennies << (pennies > 1 ? " pennies." : " penny.")
    << std::endl;
}
