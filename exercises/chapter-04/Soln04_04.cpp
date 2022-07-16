#include <iostream>

int main() {
  unsigned short age {};
  char gender {'m'};
  enum class AcademicDegree { none, associate, bachelor, professional, master, doctor };
  AcademicDegree degree {AcademicDegree::none};
  bool married {};
  bool speaksHindi {};
  bool speaksUrdu {};

  std::cout << "Enter your age: ";
  std::cin >> age;
  std::cout << "Enter your gender (m for male, f for female): ";
  std::cin >> gender;
  
  unsigned short opt {};
  std::cout << "Choose your academic degree: \n0 - none\n1 - associate\n2 - bachelor\n3 - professional\n4 - master\n5 - doctor" << std::endl;
  std::cin >> opt;

  switch (opt) {
    case 1:
      degree = AcademicDegree::associate;
      break;
    case 2:
      degree = AcademicDegree::bachelor;
      break;
    case 3:
      degree = AcademicDegree::professional;
      break;
    case 4:
      degree = AcademicDegree::master;
      break;
    case 5:
      degree = AcademicDegree::doctor;
      break;
    default:
      degree = AcademicDegree::none;
      break;
  }

  std::cout << "Are you married? ";
  std::cin >> married;
  std::cout << "Can you speak Hindi? ";
  std::cin >> speaksHindi;
  std::cout << "Can you speak Urdu? ";
  std::cin >> speaksUrdu;

  if ((age > 21 && age < 35) &&
      gender == 'f' &&
      (degree == AcademicDegree::bachelor || degree == AcademicDegree::master) &&
      !married &&
      (speaksHindi || speaksUrdu)) {
    std::cout << "Congrats. You get enough qualifications for the job!" << std::endl;
    return 0;
  }

  std::cout << "Hmm. You do not meet the qualifications for this job. Get out of my room!" << std::endl;
}
