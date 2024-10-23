// https://www.acmicpc.net/problem/15688
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000001

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int* count = (int*)malloc(MAX_VALUE * sizeof(int));
  for (int i=0; i<N; i++) {
    scanf("%d", &count[i]);
  }
    
  qsort(count, N, sizeof(int), compare);
    
  for (int i=0; i<N; i++) {
    printf("%d\n", count[i]);
  }
  free(count);
  
  return 0;
}
