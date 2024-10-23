// https://www.acmicpc.net/problem/12852
// C11

#include <stdio.h>

#define MAX_LEN 1000001

int dp[MAX_LEN];
int path[MAX_LEN];

void func(int N) {
  dp[1] = 0;
  
  for (int i=2; i<=N; i++) {
    dp[i] = dp[i-1] + 1;
    path[i] = i-1;
    
    if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
      dp[i] = dp[i/2] + 1;
      path[i] = i/2;
    }
    
    if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
      dp[i] = dp[i/3] + 1;
      path[i] = i/3;
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  func(N);
  
  printf("%d\n", dp[N]);
  while (N > 0) {
    printf("%d ", N);
    N = path[N];
  }
  
  return 0;
}

/*
  1463 문제와 유사

  dp[i]는 i를 1로 만들기 위한 최소 연산 횟수를 저장
  dp[1] = 0, 이미 1이기때문에 연산이 필요 없음

  path[i]는 i가 어떤 숫자에서 왔는지를 저장
  path[10] = 9 일때, 10에서 9로 이동했다는 경로 배열

  점화식:
  dp[i] = min(dp[i-1], dp[i/2], dp[i/3]) + 1
  세가지 연산 경우의 수 중 최소 연산 횟수를 정하고 + 1 해준게 dp[i]가 됨

  dp[i] = dp[i-1] + 1; 로 target값을 먼저 정하고,
  i 가 2로 떨어질 경우 dp[i] 보다 나눠서 계산한 부분이 더 작다면 업데이트 (3 일때도 마찬가지)
*/
