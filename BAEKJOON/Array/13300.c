// https://www.acmicpc.net/problem/13300
// C99

#include <stdio.h>

int main() {
  int room[7][2] = {0,};
  
  int N, K;
  scanf("%d %d", &N, &K);
  
  int S, Y;
  for (int i=0; i<N; i++) {
    scanf("%d %d", &S, &Y);
    room[Y][S]++;
  }
  
  int result = 0;
  for (int i=1; i<7; i++) {
    for (int j=0; j<2; j++) {
      if (room[i][j] > 0) {
        result += (room[i][j]+K-1) / K;   
      }
    }
  }
  
  printf("%d", result);
  
  return 0;
}
