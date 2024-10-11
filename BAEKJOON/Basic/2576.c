// https://www.acmicpc.net/problem/2576
// C99

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void *b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int arr[7];
  for (int i=0; i<7; i++) {
      scanf("%d", &arr[i]);
  }
  
  qsort(arr, 7, sizeof(int), compare);
  
  int sum = 0;
  int min = 101;
  for (int i=0; i<7; i++) {
    if (arr[i] % 2 != 0) {
      sum += arr[i];
      min = arr[i];
    }
  }
  
  if (sum == 0) {
    printf("-1\n");
  } else {
    printf("%d\n%d", sum, min);
  }
  return 0;
}
