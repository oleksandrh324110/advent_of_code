#include <fstream>
#include <iostream>
#include <string>

bool is_number(const std::string &str);

int main(void) {
  std::ifstream file("../src/input.txt");
  std::string input;
  std::string str;
  while (std::getline(file, str))
    input += str;

  for (size_t i = 0; i < input.size(); i++) {
    const size_t dont_index = input.find("don't()", i);
    if (dont_index == std::string::npos)
      break;
    const size_t do_index = input.find("do()", dont_index);
    if (do_index == std::string::npos) {
      input.erase(dont_index);
      break;
    }

    input.erase(dont_index, do_index - dont_index + 4);
    i = dont_index;
  }

  int sum = 0;
  for (size_t i = 0; i < input.size(); i++) {
    const size_t start = input.find("mul(", i) + 4;
    if (start == std::string::npos)
      break;
    const size_t comma = input.find(",", start);
    const size_t end = input.find(")", comma);

    const std::string num1 = input.substr(start, comma - start);
    const std::string num2 = input.substr(comma + 1, end - comma - 1);

    if (!is_number(num1) || !is_number(num2))
      continue;

    sum += std::stoi(num1) * std::stoi(num2);
    i = start + 1;
  }

  std::cout << sum << '\n';
}

bool is_number(const std::string &str) {
  bool is_number = true;
  for (size_t i = 0; i < str.size(); i++) {
    if (!std::isdigit(str[i])) {
      is_number = false;
      break;
    }
  }
  return is_number;
}
