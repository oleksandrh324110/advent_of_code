#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> split(const std::string &str, const std::string &delimiter);

int main(void) {
  std::ifstream file("../src/input.txt");
  std::string str;

  std::vector<std::pair<size_t, std::vector<size_t>>> rows;
  while (std::getline(file, str)) {
    rows.emplace_back(
        std::make_pair(std::stoul(str.substr(0, str.find(": "))),
                       split(str.substr(str.find(": ") + 2), " ")));
  }

  size_t result = 0;

  for (const auto &[value, vec] : rows) {
    for (size_t mask = 0; mask < std::pow(2, vec.size()); mask++) {
      size_t test_value = vec.front();

      for (size_t i = 1; i < vec.size(); i++) {
        if (mask & (static_cast<size_t>(1) << (i - 1)))
          test_value += vec[i];
        else
          test_value *= vec[i];
      }

      if (value == test_value) {
        result += value;
        break;
      }
    }
  }

  std::cout << result << '\n';
}

std::vector<size_t> split(const std::string &str,
                          const std::string &delimiter) {
  std::vector<size_t> result;
  size_t start = 0;
  size_t end = str.find(delimiter);

  while (end != std::string::npos) {
    result.push_back(std::stoul(str.substr(start, end - start)));
    start = end + delimiter.length();
    end = str.find(delimiter, start);
  }
  result.push_back(std::stoul(str.substr(start)));

  return result;
}
