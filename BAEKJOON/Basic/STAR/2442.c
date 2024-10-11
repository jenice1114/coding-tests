// https://www.acmicpc.net/problem/2442
// C99

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  for (int i=1; i<=N; i++) {
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
  5개라고 생각했을 때 가운데 기준으로 별을 (2*i)-1개 더 찍으면 됨
*/
