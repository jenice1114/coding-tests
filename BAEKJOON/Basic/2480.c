// https://www.acmicpc.net/problem/2480
// C99

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int arr[3];
  scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
  qsort(arr, 3, sizeof(int), compare);

  int result = 0;
  if (arr[0] == arr[1] && arr[1] == arr[2]) {
    result = 10000 + arr[0] * 1000;
  } else if (arr[0] == arr[1] || arr[1] == arr[2]) {
    result = 1000 + arr[1] * 100;
  } else {
    result = arr[0] * 100;
  }

  printf("%d\n", result);

  return 0;
}
