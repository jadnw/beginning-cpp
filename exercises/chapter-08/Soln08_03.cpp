#include <iostream>

int main(int argc, char* argv[]) {
  switch (argc - 1) {
    case 2: case 3: case 4:
      for (size_t i {1}; i < argc; ++i)
        std::cout << "Argument " << i << " is " << argv[i] << std::endl;
    default:
      std::cout << "You entered the incorrect number of arguments. Please provide 2-4 arguments." << std::endl;
  }
}
