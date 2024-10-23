// https://www.acmicpc.net/problem/1932
// C11

#include <stdio.h>

#define MAX_LEN 501

int triangle[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][MAX_LEN];

int max(int a, int b) {
  return (a > b) ? a : b;
}

void func(int N) {
  for (int i=1; i<=N; i++) {
    dp[N][i] = triangle[N][i];
  }
  
  for (int i=N-1; i>=1; i--) {
    for (int j=1; j<=i; j++) {
      dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=i; j++) {
      scanf("%d", &triangle[i][j]);
    }
  }
  
  func(N);
  printf("%d", dp[1][1]);
  
  return 0;
}

/*
  dp[i + 1][j]는 아래층의 대각선 왼쪽 값
  dp[i + 1][j + 1]는 아래층의 대각선 오른쪽 값
  max(dp[i + 1][j], dp[i + 1][j + 1])는 대각선 왼쪽과 오른쪽 중 더 큰 값을 선택

  이런 방식으로 아래층에서 위층으로 올라가며 각 위치에서의 최대 경로 합을 구한다
*/
