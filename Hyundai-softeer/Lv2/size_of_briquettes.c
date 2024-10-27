// https://softeer.ai/practice/7628
// C11

#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int heater[100];
  for (int i = 0; i < n; i++) {
    scanf("%d", &heater[i]);
  }

  int maxHouses = 0;

  // 연탄 반지름을 2부터 100까지 시도
  for (int coalRadius = 2; coalRadius <= 100; coalRadius++) {
    int count = 0;
    // 각 난로 반지름이 연탄 반지름의 배수인 집을 카운트
    for (int i = 0; i < n; i++) {
      if (heater[i] % coalRadius == 0) {
        count++;
      }
    }
    // 최대로 연탄을 사용할 수 있는 집의 수 갱신
    if (count > maxHouses) {
      maxHouses = count;
    }
  }

  printf("%d", maxHouses);

  return 0;
}