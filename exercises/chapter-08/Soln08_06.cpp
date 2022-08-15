#include <iostream>
#include <vector>
#include <cmath>
#include <optional>
#include <string_view>

void sort(std::vector<unsigned>& numbers);

void computeHighest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&highest)[5]);
void computeLowest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&lowest)[5]);

std::optional<double> computeAverage(const std::vector<unsigned>& numbers);
std::optional<double> computeMedian(const std::vector<unsigned>& numbers);
std::optional<double> computeStandardDeviation(const std::vector<unsigned>& numbers);
std::optional<double> computeVariance(const std::vector<unsigned>& numbers);

void printNumber(std::string_view label, const std::optional<double>& number);
void printNumbers(std::string_view label, const std::optional<unsigned>(&numbers)[5]);

int main() {
  std::vector<unsigned> grades;
  std::cout << "Please enter a number of grades (0-100), terminated by a negative one: " << std::endl;
  while (true) {
    int number {};
    std::cin >> number;
    if (number < 0) break;
    else if (number > 100)
      std::cout << "Only numbers < 100, please ..." << std::endl;
    else
      grades.push_back(number);
  }

  sort(grades);
  
  std::optional<unsigned> highest[5] {};
  std::optional<unsigned> lowest[5] {};
  computeHighest(grades, highest);
  computeLowest(grades, lowest);

  printNumbers("Five highest grades", highest);
  printNumbers("Five lowest grades", lowest);
  printNumber("The grade average", computeAverage(grades));
  printNumber("The median grade", computeMedian(grades));
  printNumber("The standard deviation of the grades", computeStandardDeviation(grades));
  printNumber("The variance of the grades", computeVariance(grades));
}

void swap(std::vector<unsigned>& numbers, size_t first, size_t second) {
  auto temp {numbers[first]};
  numbers[first] = numbers[second];
  numbers[second] = temp;
}

void sort(std::vector<unsigned>& numbers, size_t start, size_t end) {
  if (!(start - end)) return;
  swap(numbers, start, (start + end) / 2);
  size_t current {start};
  for (size_t i {start + 1}; i <= end; ++i) {
    if (numbers[i] < numbers[start]) swap(numbers, ++current, i);
  }

  swap(numbers, start, current);

  if (current > start) sort(numbers, start, current - 1);
  if (end > current + 1) sort(numbers, current + 1, end);
}

void sort(std::vector<unsigned>& numbers) {
  if (!numbers.empty()) sort(numbers, 0, numbers.size() - 1);
}

void computeHighest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&highest)[5]) {
  const auto numHighest = static_cast<int>(std::size(highest));

  for (int i {}; i < numHighest; ++i) {
    const int numberIndex = static_cast<int>(numbers.size()) - numHighest + i;
    if (numberIndex >= 0) highest[i] = numbers[numberIndex];
    else highest[i] = std::nullopt;
  }
}

void computeLowest(const std::vector<unsigned>& numbers, std::optional<unsigned>(&lowest)[5]) {
  const auto numLowest = static_cast<int>(std::size(lowest));

  for (int i {}; i < numLowest; ++i) {
    if (i < numbers.size() - 1) lowest[i] = numbers[i];
    else lowest[i] = std::nullopt;
  }
}

std::optional<double> computeAverage(const std::vector<unsigned>& numbers) {
  if (numbers.empty()) return std::nullopt;
  double average {};
  for (auto& number : numbers) average += number;
  return average / numbers.size();
}

std::optional<double> computeMedian(const std::vector<unsigned>& numbers) {
  if (numbers.empty()) return std::nullopt;
  const auto numNumbers = numbers.size();
  const auto middleIndex = static_cast<int>(numNumbers / 2);
  if (numNumbers % 2) return numbers[middleIndex + 1];
  else return static_cast<double>(numbers[middleIndex] + numbers[middleIndex + 1]) / 2;
}

std::optional<double> computeStandardDeviation(const std::vector<unsigned>& numbers) {
  if (numbers.empty()) return std::nullopt;
  const double average = *computeAverage(numbers);
  double sum {};
  for (auto& number : numbers)
    sum += (number - average) * (number - average);
  return std::sqrt(sum / numbers.size());
}

std::optional<double> computeVariance(const std::vector<unsigned>& numbers) {
  if (numbers.empty()) return std::nullopt;
  const double standardDeviation = *computeStandardDeviation(numbers);
  return standardDeviation * standardDeviation;
}

void printNumber(std::string_view label, const std::optional<double>& number) {
  std::cout << label << ": ";
  if (number) std::cout << *number;
  else std::cout << "n/a";
  std::cout << std::endl;
}

void printNumbers(std::string_view label, const std::optional<unsigned>(&numbers)[5]) {
  std::cout << label << ": ";

  for (auto& number : numbers)
    if (number) std::cout << *number << ' ';

  std::cout << std::endl;
}
