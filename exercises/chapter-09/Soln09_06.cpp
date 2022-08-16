#include <iostream>
#include <iomanip>
#include <vector>

// Swap address at position first with address at position second
template <typename T>
inline void swap(std::vector<T>& data, size_t first, size_t second)
{
  auto temp{data[first]};
  data[first] = data[second];
  data[second] = temp;
}

// Sort elements in ascending sequence
// Addresses of data to be sorted are from data[start] to data[end]
template <typename T>
void sort(std::vector<T>& data, size_t start, size_t end) 
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;                                                

  // Choose middle address to partition set
  swap(data, start, (start + end) / 2);                            // Swap middle address with start

  // Check data against chosen word
  size_t current{start};
  for (size_t i{start + 1}; i <= end; i++)
  {
    if (data[i] < data[start])                                  // Is word less than chosen word?
      swap(data, ++current, i);                                    // Yes, so swap to the left
  }

  swap(data, start, current);                                      // Swap chosen and last swapped data

  if (current > start) sort(data, start, current - 1);             // Sort left subset if exists
  if (end > current + 1) sort(data, current + 1, end);             // Sort right subset if exists
}

// Sort elements in ascending sequence
template <typename T>
void sort(std::vector<T>& data)
{
  if (!data.empty())
    sort(data, 0, data.size() - 1);
}


template <typename T>
void list(const std::vector<T>& data, size_t width = 5) {
  for (auto value : data) std::cout << std::setw(width) << value;
  std::cout << std::endl;
}

int main() {
  std::vector<int> nums { -2, 4, -5, 6, 10, -40, 56, 4, 67, 45};
  list(nums);
  sort(nums);
  std::cout << "Sorted:\n";
  list(nums);
}
