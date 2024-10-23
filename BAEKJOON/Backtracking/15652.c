// https://www.acmicpc.net/problem/15652
// C11

#include <stdio.h>

int N,M;
int arr[8];

void dfs(int x, int depth) {
  if (depth == M) {
    for (int i=0; i<depth; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  
  for (int i=x; i<=N; i++) {
    arr[depth] = i;
    dfs(i, depth+1);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  dfs(1, 0);
  return 0;
}

