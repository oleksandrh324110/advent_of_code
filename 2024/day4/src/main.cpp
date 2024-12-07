#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ifstream file("../src/input.txt");
  std::vector<std::string> data;
  data.reserve(140);
  std::string str;
  while (std::getline(file, str))
    data.emplace_back(str);

  size_t count = 0;
  for (size_t i = 1; i < data.size() - 1; i++) {
    for (size_t j = 1; j < data[i].size() - 1; j++) {
      if (data[i][j] != 'A')
        continue;

      if (data[i - 1][j + 1] == data[i + 1][j - 1])
        continue;

      size_t m = (data[i - 1][j + 1] == 'M') + (data[i + 1][j + 1] == 'M') +
                 (data[i + 1][j - 1] == 'M') + (data[i - 1][j - 1] == 'M');
      size_t s = (data[i - 1][j + 1] == 'S') + (data[i + 1][j + 1] == 'S') +
                 (data[i + 1][j - 1] == 'S') + (data[i - 1][j - 1] == 'S');

      if (m == 2 && s == 2)
        count++;
    }
  }

  std::cout << count << '\n';
}
