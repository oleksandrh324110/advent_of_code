#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool are_safe(int a, int b, bool is_asc);
std::vector<int> split(const std::string &str, const std::string &delimiter);

int main() {
  std::ifstream file("../src/input.txt");
  std::vector<std::vector<int>> data;
  std::string str;
  while (std::getline(file, str))
    data.emplace_back(split(str, " "));
  size_t result = 0;
  for (auto &vec : data) {
    bool is_safe = true;
    bool was_one_removed = false;

    bool is_asc = (vec[0] < vec[1] && vec[1] < vec[2]) ||
                  (vec[2] < vec[3] && vec[3] < vec[4]);

    for (size_t i = 0; i < vec.size() - 1; i++) {
      if (!are_safe(vec[i], vec[i + 1], is_asc)) {
        if (was_one_removed) {
          is_safe = false;
          break;
        }

        if (i == vec.size() - 2)
          vec.erase(vec.end());
        else if (are_safe(vec[i + 1], vec[i + 2], is_asc))
          vec.erase(vec.begin() + i);
        else
          vec.erase(vec.begin() + i + 1);

        was_one_removed = true;
        i = -1;
      }
    }

    result += is_safe;
  }

  std::cout << result << '\n';
}

bool are_safe(int a, int b, bool is_asc) {
  const int sub = is_asc ? b - a : a - b;
  return (sub >= 1 && sub <= 3);
}

std::vector<int> split(const std::string &str, const std::string &delimiter) {
  std::vector<int> result;
  size_t start = 0;
  size_t end = str.find(delimiter);

  while (end != std::string::npos) {
    result.push_back(std::stoi(str.substr(start, end - start)));
    start = end + delimiter.length();
    end = str.find(delimiter, start);
  }
  result.push_back(std::stoi(str.substr(start)));

  return result;
}
