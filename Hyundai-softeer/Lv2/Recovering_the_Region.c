// https://softeer.ai/practice/9497
// C11

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int sudoku[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &sudoku[i][j]);
    }
  }

  // 결과 출력
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", i+1);
    }
    printf("\n");
  }

  return 0;
}