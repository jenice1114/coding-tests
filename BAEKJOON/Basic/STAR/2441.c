// https://www.acmicpc.net/problem/2441
// C99

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=N; i>=1; i--) {
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
  2439 와 유사
*/
