// https://www.acmicpc.net/problem/2445
// C99

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=1; i<=N; i++) {
    for (int l=1; l<=i; l++) {
      printf("*");
    }
    for (int m=1; m<= 2*(N-i); m++) {
      printf(" ");
    }
    for (int r=1; r<=i; r++) {
      printf("*");
    }
    printf("\n");
  }
  
  for (int i=N-1; i>=1; i--) {
    for (int l=1; l<=i; l++) {
      printf("*");
    }
    for (int m=1; m<=2*(N-i); m++) {
      printf(" ");
    }
    for (int r=1; r<=i; r++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

/*
  가운데 점 찍는게 없어서 N-i 연산부터 적용
*/
