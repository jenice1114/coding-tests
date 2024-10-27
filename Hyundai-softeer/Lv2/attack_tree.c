// https://softeer.ai/practice/9657
// C11

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // n, m 값 할당
  int n, m;
  scanf("%d %d", &n, &m);

  // n x m 만큼 동적할당
  int** array = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    array[i] = (int*)malloc(m * sizeof(int));
  }

  // n x m 값 할당
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &array[i][j]);
    }
  }

  // 공격 구간 할당
  int L1, R1, L2, R2;
  scanf("%d %d", &L1, &R1);
  scanf("%d %d", &L2, &R2);

  // 첫 번째 공격 처리 (L1~R1 구간)
  for (int i = L1 - 1; i <= R1 - 1; i++) {  // L1부터 R1까지의 행만 탐색
    for (int j = 0; j < m; j++) {  // 오른쪽으로 진행
      if (array[i][j] == 1) {  // 환경 파괴범을 처음 만나면
        array[i][j] = 0;  // 환경 파괴범과 투사체가 사라짐
        break;  // 투사체는 첫 환경 파괴범만 제거하고 사라짐
      }
    }
  }

  // 두 번째 공격 처리 (L2~R2 구간)
  for (int i = L2 - 1; i <= R2 - 1; i++) {  // L2부터 R2까지의 행만 탐색
    for (int j = 0; j < m; j++) {  // 오른쪽으로 진행
      if (array[i][j] == 1) {  // 환경 파괴범을 처음 만나면
        array[i][j] = 0;  // 환경 파괴범과 투사체가 사라짐
        break;  // 투사체는 첫 환경 파괴범만 제거하고 사라짐
      }
    }
  }

  // 남은 환경 파괴범 세기
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (array[i][j] == 1) {
        count++;
      }
    }
  }

  // 결과 출력 (남은 환경 파괴범 수)
  printf("%d", count);

  for (int i = 0; i < n; i++) {
    free(array[i]);
  }
  free(array);

  return 0;
}
