// https://www.acmicpc.net/problem/2999
// C11

#include <stdio.h>
#include <string.h>

int main() {
  char msg[101];
  scanf("%s", msg);
  
  int N = strlen(msg);
  int R = 1;
  int C = N;
  for (int i = 1; i * i <= N; i++) {
    if (N % i == 0 && i <= N / i) {
      R = i;
      C = N / i;
    }
  }
  
  char grid[R][C];
  int idx = 0;
  for (int j = 0; j < C; j++) {
    for (int i = 0; i < R; i++) {
      grid[i][j] = msg[idx++];
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      putchar(grid[i][j]);
    }
  }
  
  return 0;
}

/*
  문제 조건, R=행, C=열, N=메시지총글자
  1. R*C = N
  2. R <= C
  3. 위의 1,2번 조건을 충족하는 경우가 여러 개 일 경우 R이 제일 큰 값을 선택

  int N = strlen(msg);
  int R = 1;
  int C = N;
  for (int i = 1; i * i <= N; i++) {
    if (N % i == 0 && i <= N / i) {
      R = i;
      C = N / i;
    }
  }

  1. 입력된 문자열 길이를 읽음 (N)
  2. 초기값 설정, R=1, C=N
  3. i가 N의 약수인 경우로 탐색 시작
   3-1. i가 N의 약수이며, R<=C 조건이 만족할 때 값 업데이트
        N % i == 0 해당 조건은 i가 N의 약수인지 판별하는 조건
        i <= N/i 해당 조건은 R*C = N, R = N/C 이 식을 만족하기 위함
  4. 완성된 행,열에 메시지를 열부터 넣음
  5. 넣어진 메시지를 행부터 출력
 */
