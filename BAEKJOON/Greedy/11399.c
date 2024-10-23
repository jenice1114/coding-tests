// https://www.acmicpc.net/problem/11399
// C11

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int P[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &P[i]);
  }
  qsort(P, N, sizeof(int), compare);
  
  int result = 0;
  int sum = 0;
  for (int i=0; i<N; i++) {
    sum += P[i];
    result += sum;
  }
  printf("%d", result);
  
  return 0;
}

/*
  문제를 봤을 때, P를 오름차순으로 정렬하고 합을 세면 그게 최솟값이라고 생각함
*/
