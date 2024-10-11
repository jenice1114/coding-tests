// https://www.acmicpc.net/problem/2446
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
  
  for (int i=2; i<=N; i++) {
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
  2442, 2443 참고
*/
