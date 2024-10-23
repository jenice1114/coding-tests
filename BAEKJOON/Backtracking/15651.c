// https://www.acmicpc.net/problem/15651
// C11

#include <stdio.h>

int N,M;
int arr[7];

void dfs(int depth) {
  if (depth == M) {
    for (int i=0; i<M; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  
  for (int i=1; i<=N; i++) {
    arr[depth] = i;
    dfs(depth+1);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  dfs(0);
  return 0;
}
