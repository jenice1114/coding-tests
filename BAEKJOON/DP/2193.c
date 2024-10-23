// https://www.acmicpc.net/problem/2193
// C11

#include <stdio.h>

#define MAX_LEN 91

int main() {
  int N;
  scanf("%d", &N);
  
  long long dp[MAX_LEN];
  
  dp[1] = 1;
  dp[2] = 1;
  
  for (int i=3; i<=N; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  
  printf("%lld", dp[N]);
  return 0;
}
