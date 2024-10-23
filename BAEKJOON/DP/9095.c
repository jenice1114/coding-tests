// https://www.acmicpc.net/problem/9095
// C11

#include <stdio.h>

int dp[12];

void DP() {
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  
  for (int i=4; i<=11; i++) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  
  DP();
  
  while (tc--) {
    int N;
    scanf("%d", &N);
    printf("%d\n", dp[N]);
  }
  
  return 0;
}
