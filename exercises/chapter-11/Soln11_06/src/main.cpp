#include <cstdlib>
#include <ctime>
#include "Truckload.h"

SharedBox findLargestBox(const Truckload& truckload);
SharedBox findSmallestBox(const Truckload& truckload);
void addRandomBoxes(Truckload& truckload, size_t num);
void addRandomBoxes(std::vector<SharedBox>& vector, size_t num);

int main() {
  std::srand((unsigned)std::time(0));
  
  Truckload load1 {};
  addRandomBoxes(load1, 12);
  std::cout << "The firs list:\n";
  load1.listBoxes();

  // Find the largest Box in the list
  SharedBox largestBox {findLargestBox(load1)};

  std::cout << "\nThe largest box in the first list is ";
  largestBox->listBox();
  std::cout << std::endl;
  load1.removeBox(largestBox);
  std::cout << "\nAfter deleting the largest box, the list contains:\n";
  load1.listBoxes();

  std::vector<SharedBox> boxes;
  addRandomBoxes(boxes, 20);

  Truckload load2 {boxes};
  std::cout << "\nThe second list:\n";
  load2.listBoxes();

  std::cout << "\nThe smallest box in the second list is ";
  SharedBox smallestBox {findSmallestBox(load2)};
  smallestBox->listBox();
  std::cout << std::endl;
}

SharedBox findLargestBox(const Truckload& truckload) {
  auto iterator = truckload.getIterator();
  SharedBox largestBox { iterator.getFirstBox() };

  SharedBox nextBox { iterator.getNextBox() };
  while (nextBox) {
    if (nextBox->compare(*largestBox) > 0)
      largestBox = nextBox;
    nextBox = iterator.getNextBox();
  }

  return largestBox;
}

SharedBox findSmallestBox(const Truckload& truckload) {
  auto iterator = truckload.getIterator();
  SharedBox smallestBox { iterator.getFirstBox() };

  SharedBox nextBox { iterator.getNextBox() };
  while (nextBox) {
    if (nextBox->compare(*smallestBox) < 0)
      smallestBox = nextBox;
    nextBox = iterator.getNextBox();
  }

  return smallestBox;
}

// Generate a random integer 1 to count
inline double random(size_t count) {
  return 1.0 + std::rand() / (RAND_MAX / count + 1);
}

// Generate a Box with random dimensions
inline SharedBox randomBox() {
  const size_t dimLimit {99};
  return std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit));
}

void addRandomBoxes(Truckload& truckload, size_t boxCount) {
  for (size_t i {}; i < boxCount; ++i)
    truckload.addBox(randomBox());
}

void addRandomBoxes(std::vector<SharedBox>& boxes, size_t nBoxes) {
  for (size_t i {}; i < nBoxes; ++i)
    boxes.push_back(randomBox());
}
