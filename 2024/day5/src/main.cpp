#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> split(const std::string &str, const std::string &delimiter,
                       int reserve = 5);

int main(void) {
  std::ifstream file("../src/input.txt");
  std::string str;

  std::vector<std::vector<int>> rules;
  while (std::getline(file, str)) {
    if (str == "\r")
      break;
    rules.emplace_back(split(str, "|", 2));
  }

  std::vector<std::vector<int>> data;
  while (std::getline(file, str))
    data.emplace_back(split(str, ","));

  std::unordered_map<int, std::vector<int>> rules_map;
  for (const auto &vec : rules)
    rules_map[vec[0]].push_back(vec[1]);

  size_t sum = 0;

  for (auto &vec : data) {
    std::unordered_map<int, int> vec_map;
    for (size_t i = 0; i < vec.size(); i++)
      vec_map[vec[i]] = i;

    bool follows_rules = true;

    for (uint32_t i = 0; i < vec.size(); i++) {
      std::unordered_map<int, int> vec_map;
      for (size_t i = 0; i < vec.size(); i++)
        vec_map[vec[i]] = i;
      std::vector<int> &rules = rules_map[vec[i]];
      for (int rule : rules) {
        if (vec_map.contains(rule) && vec_map[rule] < i) {
          follows_rules = false;

          int buff = vec[i];
          vec.erase(vec.begin() + i);
          vec.insert(vec.begin() + vec_map[rule], buff);

          i = -1;
          break;
        }
      }
    }

    if (!follows_rules)
      sum += vec[vec.size() / 2];
  }

  std::cout << sum << '\n';
}

std::vector<int> split(const std::string &str, const std::string &delimiter,
                       int reserve) {
  std::vector<int> result;
  result.reserve(reserve);
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
