#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <vector>
#include <memory>
#include "Box.h"

using SharedBox = std::shared_ptr<Box>;

class Truckload {
private:
  class Package {
  public:
    SharedBox pBox;
    Package* pNext;

    Package(SharedBox pb) : pBox {pb}, pNext {nullptr} {}
    ~Package() { delete pNext; }
  };

  Package* pHead;
  Package* pTail;

public:
  Truckload() = default;
  Truckload(SharedBox pBox) {
    pHead = pTail = new Package{pBox};
  }
  Truckload(const std::vector<SharedBox>& boxes);
  ~Truckload() { delete pHead; }

  class Iterator {
  private:
    Package* pHead;
    Package* pCurrent;
    friend class Truckload; // only a Truckload can create an Iterator
    explicit Iterator(Package* head) : pHead {head}, pCurrent {nullptr} {}

  public:
    SharedBox getFirstBox();
    SharedBox getNextBox();
  };

  Iterator getIterator() const { return Iterator {pHead}; }

  void addBox(SharedBox pBox);
  bool removeBox(SharedBox pBox);
  void listBoxes() const;
};

#endif
