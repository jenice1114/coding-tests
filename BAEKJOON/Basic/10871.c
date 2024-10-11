// 문제: https://www.acmicpc.net/problem/10871
// 언어: C99

#include <stdio.h>

int main() {
  int result[10001];
  int res_cnt = 0;
  
  int N, X;
  scanf("%d %d", &N, &X);
  
  int sequence[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &sequence[i]);
    
    if (X > sequence[i]) {
      result[res_cnt++] = sequence[i];
    }
  }
  
  for (int i=0; i<res_cnt; i++) {
    printf("%d ", result[i]);
  }
  
  return 0;
}
