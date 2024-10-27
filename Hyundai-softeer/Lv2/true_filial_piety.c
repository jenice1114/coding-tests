// https://softeer.ai/practice/7374
// C11

#include <stdio.h>
#include <stdlib.h>  // abs 함수 사용

int min(int a, int b) {
  return a < b ? a : b;
}

// 가로 또는 세로에서 3칸을 특정 target으로 맞추는 비용 계산
int cost(int a, int b, int c, int target) {
  return abs(a - target) + abs(b - target) + abs(c - target);
}

int main(void) {
  int fram[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &fram[i][j]);
    }
  }

  int min_cost = 1000000;  // 매우 큰 값으로 초기화

  // 각 행에서 높이를 맞추는 최소 비용 계산
  for (int i = 0; i < 3; i++) { 
    for (int target = 1; target <= 3; target++) {
      int temp_row_cost = cost(fram[i][0], fram[i][1], fram[i][2], target);
      min_cost = min(min_cost, temp_row_cost);
    }
  }

  // 각 열에서 높이를 맞추는 최소 비용 계산
  for (int i = 0; i < 3; i++) {
    for (int target = 1; target <= 3; target++) {
      int temp_column_cost = cost(fram[0][i], fram[1][i], fram[2][i], target);
      min_cost = min(min_cost, temp_column_cost);
    }
  }

  printf("%d\n", min_cost);
  
  return 0;
}
