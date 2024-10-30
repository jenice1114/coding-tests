// https://www.acmicpc.net/problem/15663
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX 9

int N,M;
int num[MAX];
int arr[MAX];
int visit[MAX];

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

void func(int cur) {
  if (cur == M) {
    for (int i=0; i<M; i++) {
      printf("%d ", num[i]);
    }
    printf("\n");
    return;
  }
  
  int select = -1;
  for (int i=0; i<N; i++) {
    if (visit[i] == 0 && arr[i] != select) {
      visit[i] = 1;
      num[cur] = arr[i];
      select = arr[i];
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

/*
  엄청 헤맨 문제인데..
  백트래킹을 줬는데도 출력초과 라고 나와서 뭐지? 하고 시간걸렸다

  근데 결국 내가 오타나서 였음......... 자중해~!
*/
