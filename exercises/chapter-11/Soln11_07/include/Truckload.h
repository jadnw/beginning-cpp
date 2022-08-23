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
    Package* pPrev;

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
    Package* pTail;
    Package* pCurrent;
    friend class Truckload; // only a Truckload can create an Iterator
    explicit Iterator(const Truckload* load) : pHead {load->pHead}, pTail {load->pTail}, pCurrent {nullptr} {}

  public:
    SharedBox getFirstBox();
    SharedBox getNextBox();
    SharedBox getLastBox();
    SharedBox getPrevBox();
  };

  Iterator getIterator() const { return Iterator {this}; }

  void addBox(SharedBox pBox);
  bool removeBox(SharedBox pBox);
  void listBoxes() const;
  void listBoxesReversed() const;
};

#endif
