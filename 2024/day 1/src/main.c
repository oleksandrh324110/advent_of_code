#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  const size_t size = 1000;

  int arr1[size];
  int arr2[size];

  FILE *file = fopen("../src/input.txt", "r");
  if (!file) {
    perror("fopen");
    return 1;
  }

  for (size_t i = 0; i < size; i++) {
    char str[15];

    if (!fgets(str, sizeof(str), file))
      break;

    int num1, num2;
    sscanf(str, "%d   %d\n", &num1, &num2);

    arr1[i] = num1;
    arr2[i] = num2;
  }

  qsort(arr1, size, sizeof(int), compare);
  qsort(arr2, size, sizeof(int), compare);

  int distance = 0;
  for (size_t i = 0; i < size; i++) {
    distance += abs(arr1[i] - arr2[i]);
  }

  printf("%d\n", distance);

  return 0;
}
