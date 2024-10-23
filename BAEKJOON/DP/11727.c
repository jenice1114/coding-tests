// https://www.acmicpc.net/problem/11727
// C11

#include <stdio.h>

#define MAX_LEN 1001

int dp[MAX_LEN];

void func(int N) {
  dp[1] = 1;
  dp[2] = 3;
  
  for (int i=3; i<=N; i++) {
    dp[i] = (dp[i-1] + (2 * dp[i-2])) % 10007;
  }
}

int main() {
  int N;
  scanf("%d", &N);
  func(N);
  printf("%d", dp[N]);
  return 0;
}

/*
  2x1 일 때, 채울 수 있는 경우의 수 1
  2x2 일 때, 채울 수 있는 경우의 수 3 (2x1 2x1, 2x2, 1x2 1x2)

  점화식:
  dp[n] = dp[n-1] + (dp[n-2] * 2)

  dp[3] = dp[2] + (dp[1] * 2) 인 이유는
  2x2를 채운 경우의 수가 dp[2]에 저장되어 있으니 가져오고, (2x1로 채우는 방안이 포함되어 있음)

  n이 2이상일 때 마지막 두 칸(2x2 부분)을 한 번에 채우는 경우는 2가지다
    * 2x2 타일 하나로 마지막 두 칸을 채우는 경우
    * 1x2 타일 두 개를 가로로 놓아 마지막 두 칸을 채우는 경우
  두 가지 경우는 모두 2x1 직사각형을 먼저 채우고 남은 두 칸을 처리하는 방식인데,
  2x1 직사각형을 채우는 경우의 수는 dp[1]과 같으므로 가져와서 * 2 한다
*/
