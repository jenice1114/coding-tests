// https://www.acmicpc.net/problem/1475
// C99

#include <stdio.h>

int main() {
  char num[8];
  scanf("%s", num);
  
  int check[10] = {0,};
  for (int i=0; num[i]!='\0'; i++) {
    check[num[i]-'0']++;
  }
  
  int cnt = check[6] + check[9];
  check[6] = (cnt+1) / 2;
  check[9] = check[6];
  
  int max = 0;
  for (int i=0; i<10; i++) {
    if (check[i] > max) {
      max = check[i];
    }
  }
  
  printf("%d", max);
  
  return 0;
}

/*
  홀수 나눗셈 처리 시 +1
*/
