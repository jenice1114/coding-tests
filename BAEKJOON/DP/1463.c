// https://www.acmicpc.net/problem/1463
// C11

#include <stdio.h>

#define MAX_LEN 1000001

int dp[MAX_LEN];

int main() {
  int X;
  scanf("%d", &X);
  
  // 1을 1로 만드는데 필요한 연산횟수 0부터 시작
  dp[1] = 0;
  
  // +1은 연산횟수를 카운팅하는 것
  for (int i=2; i<=X; i++) {
    dp[i] = dp[i-1] +1;
    
    if (i%2 == 0) {
      if (dp[i] > dp[i/2] +1) {
        dp[i] = dp[i/2] +1;
      }
    }
    
    if (i%3 == 0) {
      if (dp[i] > dp[i/3] +1) {
        dp[i] = dp[i/3] +1;
      }
    }
  }
  
  printf("%d", dp[X]);
  
  return 0;
}
