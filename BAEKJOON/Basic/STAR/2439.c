// https://www.acmicpc.net/problem/2439
// C99

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N-i; j++) {
      printf(" ");
    }

    for (int k=1; k<=i; k++) {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}

/*
  공백 먼저 출력하고 -> 별
*/
