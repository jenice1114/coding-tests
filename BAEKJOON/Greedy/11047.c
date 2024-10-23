// https://www.acmicpc.net/problem/11047
// C11

#include <stdio.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  
  int coin[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &coin[i]);
  }
  
  int count = 0;
  for (int i=N-1; i>=0; i--) {
    if (K == 0) break;
    
    if (K >= coin[i]) {
      count += K / coin[i];
      K %= coin[i];
    }
  }
  
  printf("%d", count);
  
  return 0;
}
