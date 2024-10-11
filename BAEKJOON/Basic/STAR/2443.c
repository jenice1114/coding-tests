// https://www.acmicpc.net/problem/2443
// C99

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=N; i>=1; i--) {
    for (int j=1; j<=N-i; j++) {
      printf(" ");
    }

    for (int k=1; k<=2*i-1; k++) {
      printf("*");
    }

  printf("\n");
  }
  
  return 0;
}

/*
  같은 조건에 전제조건만 바꾸면 됨 2442 유사
*/
