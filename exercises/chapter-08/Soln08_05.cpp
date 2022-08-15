#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

bool is_prime(unsigned num);
std::vector<unsigned> generate_nums(unsigned to, unsigned from = 1);
std::vector<unsigned> find_prime_nums(std::vector<unsigned> nums);

int main() {
  unsigned to {}, from {1};
  std::cout << "Enter the end number and the start number: ";
  std::cin >> to >> from;
  size_t perline {};
  std::cout << "How many values per line? ";
  std::cin >> perline;

  std::vector<unsigned> primes {find_prime_nums(generate_nums(to, from))};
  for (size_t i {}; i < primes.size(); ++i) {
    std::cout << std::setw(4) << primes[i];
    if ((i + 1) % perline == 0) {
      std::cout << std::endl;
    }
  }
}

bool is_prime(unsigned num) {
  size_t limit {static_cast<size_t>(std::sqrt(num))};
  for (size_t i {2}; i <= limit; ++i)
    if (num % i == 0) return false;
  return true;
}

std::vector<unsigned> generate_nums(unsigned to, unsigned from) {
  std::vector<unsigned> nums;
  for (size_t i {from}; i <= to; ++i) nums.push_back(i);
  return nums;
}

std::vector<unsigned> find_prime_nums(std::vector<unsigned> nums) {
  std::vector<unsigned> primes;
  for (size_t i {}; i < nums.size(); ++i) {
    if (is_prime(nums[i])) primes.push_back(nums[i]);
  }
  return primes;
}
