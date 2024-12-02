#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("../src/input.txt", "r");

  size_t res = 0;

  char str[24];
  while (fgets(str, 24, file)) {
    size_t size = 0;
    size_t indexes[8] = {0};
    for (size_t i = 0; i < 24; i++) {
      if (str[i] == '\n')
        break;
      if (str[i] == ' ') {
        indexes[size + 1] = i + 1;
        size++;
      }
    }
    if (size)
      size++;

    int *nums = malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
      nums[i] = atoi(str + indexes[i]);
    }

    bool asc = nums[1] > nums[0];
    bool is_safe = true;
    for (size_t i = 0; i < size - 1; i++) {
      int sub = asc ? nums[i + 1] - nums[i] : nums[i] - nums[i + 1];
      if (sub < 1 || sub > 3) {
        is_safe = false;
        break;
      }
    }
    res += is_safe;
  }

  printf("%zu\n", res);

  return 0;
}
