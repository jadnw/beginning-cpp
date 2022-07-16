#include <iostream>
#include <cctype>
#include <iomanip>
#include <vector>

int main() {
  std::vector<unsigned long> products {};
  std::vector<unsigned> quantities {};
  std::vector<double> unit_prices {}; 
  
  char ch {'y'};
  while (std::tolower(ch) == 'y') {
    unsigned long product {};
    unsigned quantity {};
    double unit_price {};

    std::cout << "Enter the product: ";
    std::cin >> product;
    std::cout << "Enter the product quantity: ";
    std::cin >> quantity;
    std::cout << "Enter the product unit price: ";
    std::cin >> unit_price;

    products.push_back(product);
    quantities.push_back(quantity);
    unit_prices.push_back(unit_price);

    std::cout << "Do you want to create a new product? [y/N]: ";
    std::cin >> ch;
  }

  std::cout << std::left;
  std::cout << "----------------------------------------------------------------" << std::endl;
  std::cout << std::setw(16) << "Product"
    << std::setw(16) << "Quantity"
    << std::setw(16) << "Unit Price"
    << std::setw(16) << "Cost" << std::endl;
  std::cout << "----------------------------------------------------------------" << std::endl;

  double total {};
  for (size_t i {}; i < products.size(); ++i) {
    double cost = quantities[i] * unit_prices[i];
    total += cost;
    std::cout << std::setw(16) << products[i]
      << std::setw(16) << quantities[i]
      << "$" << std::setw(15) << unit_prices[i]
      << "$" << std::setw(15) << cost << std::endl; 
  }
  std::cout << std::setw(48) << " " << "$" << std::setw(15) << total << std::endl;
  std::cout << "----------------------------------------------------------------" << std::endl;
}
