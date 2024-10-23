// https://www.acmicpc.net/problem/15650
// C11

#include <stdio.h>

int N,M;
int arr[10];

void dfs(int x, int depth) {
  if (depth == M) {
    for (int i=0; i<M; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  
  for (int i=x; i<=N; i++) {
    arr[depth] = i;
    dfs(i+1, depth+1);
  }
} 

int main() {
  scanf("%d %d", &N, &M);
  
  dfs(1,0);
  
  return 0;
}
