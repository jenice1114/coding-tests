// https://www.acmicpc.net/problem/11053
// C11

#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int N;
  scanf("%d", &N);
  
  int num[N];
  int dp[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &num[i]);
    dp[i] = 1;
  }
  
  for (int i=1; i<N; i++) {
    for (int j=0; j<i; j++) {
      if (num[i] > num[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  
  int max_sum = dp[0];
  for (int i=1; i<N; i++) {
    max_sum = max(dp[i], max_sum);
  }
  printf("%d", max_sum);
  
  return 0;
}

/*
  수열 A = {10, 20, 10, 30, 20, 50}에서
  i = 3일 때 num[3] = 30이고, j = 0, 1, 2인 경우

  j = 0일 때:
  num[0] = 10이고, num[3] = 30이므로 30 > 10이 성립
  dp[3] = max(dp[3], dp[0] + 1)로 갱신, dp[0] = 1이므로, dp[3] = 2

  j = 1일 때:
  num[1] = 20이고, num[3] = 30이므로 30 > 20이 성립
  dp[3] = max(dp[3], dp[1] + 1)로 갱신, dp[1] = 2이므로, dp[3] = 3

  j = 2일 때:
  num[2] = 10이고, num[3] = 30이므로 30 > 10이 성립
  dp[3] = max(dp[3], dp[2] + 1)일 때 dp[3]이 더 크므로 갱신하지 않음
  
  이때 dp[3]은 "10 → 20 → 30"이라는 수열을 기반으로 계산
*/
