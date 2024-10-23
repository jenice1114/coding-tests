// https://www.acmicpc.net/problem/1149
// C11

#include <stdio.h>

#define MAX_LEN 1001

int min(int a, int b) {
  return (a < b) ? a : b;
}

int house[MAX_LEN][3];
int dp[MAX_LEN][3];

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=1; i<=N; i++) {
    scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
  }
  
  dp[1][0] = house[1][0];
  dp[1][1] = house[1][1];
  dp[1][2] = house[1][2];
  
  for (int i=2; i<=N; i++) {
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
  }
  
  int result = min(min(dp[N][0], dp[N][1]), dp[N][2]);
  printf("%d\n", result);
  
  return 0;
}
