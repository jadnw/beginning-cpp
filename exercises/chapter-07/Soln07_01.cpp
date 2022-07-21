#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

int main() {
  std::vector<std::string> names; 
  std::vector<double> grades;

  char answer {};
  do {
    std::string student_name {};
    std::cout << "Enter the first name of the student: ";
    std::cin >> student_name;
    names.push_back(student_name);

    double grade {};
    std::cout << "Enter the grade of this student: ";
    std::cin >> grade;
    grades.push_back(grade);

    std::cout << "Do you wanna continue? (y/N): ";
    std::cin >> answer;
  } while (std::tolower(answer) == 'y');

  double sum {};
  for (auto& grade : grades) {
    sum += grade;
  }
  double average { sum / names.size() };
  std::cout << "The average grade: " << std::fixed << std::setprecision(2)
    << average << std::endl;

  std::stringstream ss {};
  for (size_t i {}; i < names.size(); ++i) {
    ss << std::setw(12) << std::left << names[i] << " - " << std::fixed << std::setprecision(2) << std::setw(4) << grades[i];  
    if (!((i + 1) % 3)) ss << std::endl;
  }
  
  std::string s {ss.str()};
  std::cout << s << std::endl;
}
