// https://www.acmicpc.net/problem/2444
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

  for (int i=N-1; i>=1; i--) {
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
  2442, 2443 가져다가 쓰면 되는데, 마지막줄 중복있기 때문에 그것만 생각하면 됨
*/
