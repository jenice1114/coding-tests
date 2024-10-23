// https://www.acmicpc.net/problem/2579
// C11

#include <stdio.h>

#define LEN 301

int max(int a, int b) {
  return (a > b) ? a : b;
}

int main() {
  int N;
  scanf("%d", &N);
  
  int arr[LEN];
  int dp[LEN];
  for (int i=1; i<=N; i++) {
    scanf("%d", &arr[i]);
  }
  
  dp[1] = arr[1];
  if (N > 1) dp[2] = max(arr[2], arr[1] + arr[2]);
  if (N > 2) dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
  for (int i=4; i<=N; i++) {
    dp[i] = max(dp[i-2]+arr[i], dp[i-3] + arr[i-1] + arr[i]);
  }
  
  printf("%d", dp[N]);
  
  return 0;
}
