#include "Truckload.h"

SharedBox Truckload::nullBox {};                   // Initialize static class member

// Constructor
Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
  for (const auto& pBox : boxes)
  {
    addBox(pBox);
  }
}

// Copy constructor
Truckload::Truckload(const Truckload& src)
{
  for (Package* package{src.pHead}; package; package = package->pNext)
  {
    addBox(package->pBox);
  }
}

// Copy assignment operator
Truckload& Truckload::operator=(const Truckload& src)
{
  if (&src != this)              // Prevent problems with self-assignments (do not delete your own packages!)
  {
    delete pHead;	             // Remove all current elements
	pHead = pTail = nullptr;     // Reset pointers to null
	
	// Copy all elements from the source Truckload (as in the copy constructor)
    for (Package* package{src.pHead}; package; package = package->pNext)
    {
      addBox(package->pBox);
    }
  }
  
  return *this;        // Always return *this from an assignment operator to allow for expressions such as "load1 = load2 = load3"
}

// Get the first Box
SharedBox Truckload::Iterator::getFirstBox()
{
  // Return pHead's box (or nullptr if the list is empty)
  pCurrent = pHead;
  return pCurrent? pCurrent->pBox : nullptr;     
}

// Get the next Box
SharedBox Truckload::Iterator::getNextBox()    
{
  if (!pCurrent)                                   // If there's no current...
    return getFirstBox();                          // ...return the 1st Box

  pCurrent = pCurrent->pNext;                      // Move to the next package
  
  return pCurrent? pCurrent->pBox : nullptr;       // Return its box (or nullptr...).
}

// Add a Box to the list
void Truckload::addBox(SharedBox pBox)
{
  auto pPackage = new Package{pBox};       // Create a new Package

  if (pTail)                               // Check list is not empty
    pTail->pNext = pPackage;               // Add the  new  object to the tail
  else                                     // List is empty
    pHead = pPackage;                      // so new object is the head

  pTail = pPackage;                        // Store its address as tail
}

// Find the Package containing pBox and delete it from the list
bool Truckload::removeBox(SharedBox boxToRemove)
{
  Package* previous {nullptr};      // no previous yet
  Package* current {pHead};         // initialize current to the head of the list
  while (current)
  {
    if (current->pBox == boxToRemove)      // We found the Box!
    {
      if (previous)                            // If there is a previous Package...
      {
        previous->pNext = current->pNext;      // ...make it point to the next Package 
      }
      else
      {                                        // If there is no previous, we are removing the 
        pHead = current->pNext;                // first Package in the list, so update pHead
      }
      
      current->pNext = nullptr;                // Disconnect the current Package from the list
      delete current;                          // and delete it
      
      return true;                             // Return true: we found and removed the box
    }
                                               // Move both pointers along (mind the order!)
    previous = current;                        //  - first current becomes the new previous 
    current = current->pNext;                  //  - then move current along to the next Package
  }

  return false;                                // Return false: boxToRemove was not found
}

// Overloaded subscript operator
SharedBox& Truckload::operator[](size_t index)
{
  size_t count {};                                 // Package count
  for (Package* package{pHead}; package; package = package->pNext)
  {
    if (index == count++)                          // Up to index yet?
      return package->pBox;                        // If so return the pointer to Box
  }
  return nullBox;
}

// Stream output operator to replace listBoxes() member
std::ostream& operator<<(std::ostream& stream, const Truckload& load)
{
  size_t count {};
  auto iterator = load.getIterator();
  for (auto box = iterator.getFirstBox(); box; box = iterator.getNextBox())
  {
    std::cout << *box;
    if (!(++count % 5)) std::cout << std::endl;
  }
  if (count % 5) std::cout << std::endl;
  return stream;
}
