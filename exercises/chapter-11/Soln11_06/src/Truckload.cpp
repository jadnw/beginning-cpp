#include "Truckload.h"

// Constructor
Truckload::Truckload(const std::vector<SharedBox>& boxes) {
  for (auto pBox : boxes)
    addBox(pBox);
}

// Output all Boxes in the list
void Truckload::listBoxes() const {
  const size_t boxesPerLine = 5;
  size_t count {};
  for (Package* package {pHead}; package; package = package->pNext) {
    package->pBox->listBox();
    if (!(++count % boxesPerLine)) std::cout << std::endl;
  }
  if (count % boxesPerLine) std::cout << std::endl;
}

// Get the first box
SharedBox Truckload::Iterator::getFirstBox() {
  pCurrent = pHead;
  return pCurrent ? pCurrent->pBox : nullptr;
}

// Get the next box
SharedBox Truckload::Iterator::getNextBox() {
  if (!pCurrent) return getFirstBox();
  pCurrent = pCurrent->pNext;
  return pCurrent ? pCurrent->pBox : nullptr;
}

// Add a Box to the list
void Truckload::addBox(SharedBox pBox) {
  auto pPackage = new Package {pBox};

  if (pTail)
    pTail->pNext = pPackage;
  else
   pHead = pPackage;

  pTail = pPackage;
}

// Find the Package containing pBox and delete it from the list
bool Truckload::removeBox(SharedBox boxToRemove) {
  Package* previous {nullptr};
  Package* current {pHead};
  while(current) {
    if (current->pBox == boxToRemove) {
      if (previous)
        previous->pNext = current->pNext;
      else
        pHead = current->pNext;

      current->pNext = nullptr;
      delete current;
      return true;
    }

    previous = current;
    current = current->pNext;
  }

  return false;
}
