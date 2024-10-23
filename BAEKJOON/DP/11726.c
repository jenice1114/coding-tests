// https://www.acmicpc.net/problem/11726
// C11

#include <stdio.h>

#define MAX_LEN 1001

int main() {
  int n;
  scanf("%d", &n);
  
  int dp[MAX_LEN];
  
  dp[1] = 1;
  dp[2] = 2;
  
  for (int i=3; i<=n; i++) {
    dp[i] = (dp[i-1] + dp[i-2]) % 10007;
  }
  
  printf("%d", dp[n]);
  return 0;
}

/*
  점화식 구하는 방법

  2×3 (n = 3)의 경우:

  1.
  마지막에 세로로 2×1 타일 하나를 놓을 수 있음
  그러면 남는 부분은 2×2 직사각형
  2×2 크기의 직사각형을 채우는 방법의 수는 dp[2]

  2.
  마지막에 가로로 1×2 타일 두 개를 놓을 수 있음
  그러면 남는 부분은 2×1 직사각형
  2×1 크기의 직사각형을 채우는 방법의 수는 dp[1]

  따라서, 2×3 직사각형을 채우는 방법의 수는:
  dp[N] = dp[N-1] + dp[N-2]
*/
