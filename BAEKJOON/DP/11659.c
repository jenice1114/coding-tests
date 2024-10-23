// https://www.acmicpc.net/problem/11659
// C11

/* 시간초과코드

#include <stdio.h>

#define MAX_LEN 100001

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  
  int num[MAX_LEN+1];
  for (int i=1; i<=N; i++) {
    scanf("%d", &num[i]);
  }
  
  while (M--) {
    int x, y;
    scanf("%d %d", &x, &y);
    
    int result = 0;
    for (int i=x; i<=y; i++) {
      result += num[i];
    }
    printf("%d\n", result);
  }
  
  return 0;
}
*/

#include <stdio.h>

#define MAX_LEN 100002

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  
  int num[MAX_LEN];
  int dp[MAX_LEN] = {0, };
  for (int i=1; i<=N; i++) {
    scanf("%d", &num[i]);
    dp[i] = dp[i-1] + num[i];
  }
  
  while (M--) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", dp[y] - dp[x-1]);
}
  
  return 0;
}

/*
  시간초과 안되려면 num받을때 dp에 미리 계산된 값을 넣어놓고 바로 출력해야 함

  점화식:
  dp[1] = num[1]
  dp[2] = dp[1] + num[2]
  dp[i] = dp[i-1] + num[i]

  구간 [2, 4]의 합을 구한다고 가정했을 때
  num[2] + num[3] + num[4]을 구해야 함

  이를 누적 합을 사용해서 계산해보면:
  dp[4] = 14 (1번째부터 4번째까지의 합)
  dp[1] = 5 (1번째부터 1번째까지의 합)
  따라서, 구간 [2, 4]의 합은:
  dp[4] − dp[1] = 14 − 5 = 9 이므로

  dp[y] - dp[x-1] 하면 구간 누적합 값이 나옴
*/
