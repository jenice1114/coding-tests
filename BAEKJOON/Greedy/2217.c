// https://www.acmicpc.net/problem/2217
// C11

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int rope[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &rope[i]);
  }
  
  qsort(rope, N, sizeof(int), compare);
  
  int max = 0;
  for (int i=0; i<N; i++) {
    int weight = rope[i] * (i+1);
    if (weight > max) {
      max = weight;
    }
  }
  
  printf("%d", max);
  
  return 0;
}

/*
  모든 로프를 사용해야 할 필요는 없으며, 그 중 최대 중량을 구하는 문제
*/
