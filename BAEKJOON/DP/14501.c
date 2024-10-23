// https://www.acmicpc.net/problem/14501
// C11

#include <stdio.h>

typedef struct Doby {
  int t;
  int p;
} Doby;

Doby counseling[16];
int dp[16];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=1; i<=N; i++) {
    scanf("%d %d", &counseling[i].t, &counseling[i].p);
  }
  
  for (int i=N; i>0; i--) {
    if (i+counseling[i].t -1 <= N) {
      dp[i] = max(dp[i+1], dp[i+counseling[i].t] + counseling[i].p);
    } else {
      dp[i] = dp[i+1];
    }
  }
  
  printf("%d", dp[1]);
  
  return 0;
}

/*
  https://www.acmicpc.net/problem/15486 랑 같음
  N의 조건만 달라졌는데, 150만이라서 MAX_LEN 1500001 주고 돌려도 정답
*/
