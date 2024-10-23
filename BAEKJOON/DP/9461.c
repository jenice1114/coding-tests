// https://www.acmicpc.net/problem/9461
// C11

#include <stdio.h>

#define MAX_LEN 101

long long dp[MAX_LEN];

void func() {
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;
  
  for (int i=6; i<MAX_LEN; i++) {
    dp[i] = dp[i-1] + dp[i-5];
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  func();
  
  while (tc--) {
    int N;
    scanf("%d", &N);
    printf("%lld\n", dp[N]);
  }
  
  return 0;
}

/*
  뚜쉬 long long 으로 해야됨 int는 터진다!
*/
