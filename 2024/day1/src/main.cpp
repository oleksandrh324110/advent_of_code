#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::ifstream file("../src/input.txt", std::ios_base::in);

  std::vector<int> vec1;
  std::vector<int> vec2;

  std::string line;
  while (std::getline(file, line)) {
    vec1.push_back(std::stoi(line.substr(0, line.find_first_of(' '))));
    vec2.push_back(std::stoi(line.substr(line.find_last_of(' '))));
  }

  std::unordered_map<int, int> map2;

  for (int n : vec2)
    map2[n]++;

  int score = 0;
  for (int n : vec1)
    score += n * map2[n];

  std::cout << score << '\n';
}
