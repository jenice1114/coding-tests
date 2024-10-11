// https://www.acmicpc.net/problem/1267
// C99

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  int time[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &time[i]);
  }
  
  int M = 0;
  int Y = 0;
  for (int i = 0; i < N; i++) {
    Y += (time[i] / 30 + 1) * 10;
    M += (time[i] / 60 + 1) * 15;
  }
  
  if (Y < M) {
    printf("Y %d", Y);
  } else if (M < Y) {
    printf("M %d", M);
  } else {
    printf("Y M %d", Y);
  }
  
  return 0;
}

/*
  target이 각각의 조건(30s, 60s)에 따라 몇번 나눠지냐기 때문에 나눗셈을 하고
  조건 아래(~29, ~59)일 때도 1번 청구가 되기 때문에 +1 를 한다
*/
