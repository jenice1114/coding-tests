// https://www.acmicpc.net/problem/15654
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int N,M;
int arr[MAX];
int num[MAX];
int visit[MAX];

int compare(const void* a, const void *b) {
  return (*(int*)a - *(int*)b);
}

void func(int cur) {
  if (cur == M) {
    for (int i=0; i<M; i++) {
      printf("%d ", num[i]);
    }
    printf("\n");
  }
  
  for (int i=0; i<N; i++) {
    if (visit[i] == 0) {
      num[cur] = arr[i];
      visit[i] = 1;
      func(cur+1);
      visit[i] = 0;
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }
  qsort(arr, N, sizeof(int), compare);
  
  func(0);
  return 0;
}
