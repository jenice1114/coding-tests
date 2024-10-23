// https://www.acmicpc.net/problem/1182
// C11

#include <stdio.h>

#define MAX_LEN 21

int N, S;
int arr[MAX_LEN];
int result;

void dfs(int x, int sum) {
  if (x == N) {
    if (sum == S) result++;
    return;
  }
  
  dfs(x+1, sum);
  dfs(x+1, sum + arr[x]);
}

int main() {
  scanf("%d %d", &N, &S);
  
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }
  
  dfs(0,0);
  if (S == 0) result--;
  
  printf("%d", result);
  return 0;
}
