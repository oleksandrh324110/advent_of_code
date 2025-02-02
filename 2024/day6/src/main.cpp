#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ifstream file("../src/input.txt");
  std::string str;
  std::vector<std::string> map;
  while (std::getline(file, str))
    map.emplace_back(str);

  for (size_t y = 0; y < map.size(); y++) {
    for (size_t x = 0; x < map[y].size(); x++) {
      if (map[y][x] != '#')
        continue;

      size_t start_x = x, start_y = y + 1;
    }
  }
}
