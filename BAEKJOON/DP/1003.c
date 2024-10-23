// https://www.acmicpc.net/problem/1003
// C11

#include <stdio.h>

#define MAX_LEN 41

typedef struct DP {
  int x;
  int y;
} dp;

dp fibo[MAX_LEN];

void func() {
  // f0
  fibo[0].x = 1;
  fibo[0].y = 0;
  // f1
  fibo[1].x = 0;
  fibo[1].y = 1;
  
  for (int i=2; i<MAX_LEN; i++) {
    fibo[i].x = fibo[i-1].x + fibo[i-2].x;
    fibo[i].y = fibo[i-1].y + fibo[i-2].y;
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  func();
  
  while (tc--) {
    int N;
    scanf("%d", &N);
    printf("%d %d\n", fibo[N].x, fibo[N].y);
  }
  
  return 0;
}
