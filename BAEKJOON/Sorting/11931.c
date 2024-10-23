// https://www.acmicpc.net/problem/11931
// C11

#include <stdio.h>
#include <stdlib.h>

#define LEN 1000001

int compare(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int arr[LEN];
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }
  
  qsort(arr, N, sizeof(int), compare);
  
  for (int i=0; i<N; i++) {
    printf("%d\n", arr[i]);
  }
  
  return 0;
}
