// https://www.acmicpc.net/problem/2752
// C99

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b); // 오름차순
}

int main() {
  int arr[3];
  scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
  
  qsort(arr, 3, sizeof(int), compare);
  
  printf("%d %d %d", arr[0], arr[1], arr[2]);
  
  return 0;
}
