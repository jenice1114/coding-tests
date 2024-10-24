// https://www.acmicpc.net/problem/2577
// C99

#include <stdio.h>

int main() {
  int check[10] = {0, };
  
  int A,B,C;
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  
  int result = A * B * C;
  char arr[12];
  sprintf(arr, "%d", result);
  
  for (int i=0; arr[i]!='\0'; i++) {
    check[arr[i] - '0']++;
  }
  
  for (int i=0; i<10; i++) {
    printf("%d\n", check[i]);
  }
  
  return 0;
}

/*
  int to string 에는 sprintf를 사용
*/
