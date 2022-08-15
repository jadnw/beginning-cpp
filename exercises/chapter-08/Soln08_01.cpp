#include <iostream>
#include <string>
#include <string_view>

int validate_input(int lower, int upper, std::string_view desc);
int year();
int month();
int date(int month_val, int year_val);
std::string ending(int date_day);

int main() {
  std::cout << "Enter your date of birth." << std::endl;
  int date_year {year()};
  int date_month {month()};
  int date_day {date(date_month, date_year)};

  std::string months[] {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};

  std::cout << std::endl
    << "We have established that you were born on "
    << months[date_month - 1] << ' ' << date_day << ending(date_day)
    << ", " << date_year << '.' << std::endl;
}

int validate_input(int lower, int upper, std::string_view desc) {
  int value {};
  do {
    std::cout << "Please enter " << desc << " from " << lower << " to " << upper << ": ";
    std::cin >> value;
  } while (value < lower || value > upper);

  return value;
}

int year() {
  const int low_year {1867};
  const int high_year {2022};
  return validate_input(low_year, high_year, "a year");
}

int month() {
  const int low_month {1};
  const int high_month {12};
  return validate_input(low_month, high_month, "a month number");
}

int date(int month_number, int year) {
  const int date_min {1};
  const int feb {2};
  static const int date_max[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month_number == feb && year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
    return validate_input(date_min, date_max[month_number - 1] + 1, "a date");
  else
    return validate_input(date_min, date_max[month_number], "a date");
}

inline std::string ending(int date_day) {
  if (date_day == 1 || date_day == 21 || date_day == 31) return "st";
  else if (date_day == 2 || date_day == 22) return "nd";
  else if (date_day == 3 || date_day == 23) return "rd";
  else return "th";
}
