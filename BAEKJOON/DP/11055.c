// https://www.acmicpc.net/problem/11055
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
    dp[i] = num[i];
  }
  
  for (int i=1; i<N; i++) {
    for (int j=0; j<i; j++) {
      if (num[i] > num[j]) {
        dp[i] = max(dp[i], dp[j] + num[i]);
      }
    }
  }
  
  int max_sum = dp[0];
  for (int i=1; i<N; i++) {
    max_sum = max(max_sum, dp[i]);
  }
  printf("%d", max_sum);
  
  return 0;
}
