// https://www.acmicpc.net/problem/2753
// C99

#include <stdio.h>

int main() {
  int year;
  scanf("%d", &year);
  
  if (year % 4 == 0 && year % 100 != 0 ||
    year % 4 == 0 && year % 400 == 0) {
    printf("1");
  } else {
    printf("0");
  }
  
  return 0;
}

/*
  문제 자체가 배수일 때를 찾는 것이기 때문에 mod 연산으로 계산한다

  # 주의사항
  * 나누기 아님
*/
