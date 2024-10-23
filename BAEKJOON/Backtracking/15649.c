// https://www.acmicpc.net/problem/15649
// C11

#include <stdio.h>

int N,M;
int arr[8];
int visit[8];

void dfs(int x) {
  if (x == M) {
    for (int i=0; i<M; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  
  for (int i=0; i<N; i++) {
    if (visit[i] == 0) {
      visit[i] = 1;
      arr[x] = i+1;
      dfs(x+1);
      visit[i] = 0;
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  dfs(0);
  
  return 0;
}
