// https://www.acmicpc.net/problem/2750
// C11

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int arr[1000];
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }
  
  qsort(arr, N, sizeof(int), compare);
  
  for (int i=0; i<N; i++) {
    printf("%d\n", arr[i]);
  }
  
  return 0;
}

/*
  https://www.acmicpc.net/problem/2751
  해당 문제도 2초라서 배열 크기만 변경하고 같은코드로 가능
*/
