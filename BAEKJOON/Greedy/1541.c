// https://www.acmicpc.net/problem/1541
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 51

int main() {
  char formula[MAX_LEN];
  scanf("%s", formula);
  
  int result = 0;
  int temp = 0;
  int sign = 1;
  
  int len = strlen(formula);
  for (int i=0; i<len; i++) {
    if (formula[i] >= '0' && formula[i] <= '9') {
      temp = temp * 10 + (formula[i] - '0');
    } 
    else {
      result += sign * temp;
      temp = 0;
      
      if (formula[i] == '-') {
        sign = -1;
      }
    }
  }
  
  result += sign * temp;
  
  printf("%d\n", result);
  
  return 0;
}

/*
  첫 번째 마이너스 이후에 모든 값을 빼는 것이 최솟값을 만드는 방법

  예시: 10+55-20+50+60-20 일때
  65-(20+50+60)-20 으로 65-130-20 = -85

  예시: 10+55-20-50-60-20 일때
  65-(20)-(50)-(60+20) 으로 65-20-50-80 = -85
*/
