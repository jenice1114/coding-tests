// https://www.acmicpc.net/problem/10869
// C99

#include <stdio.h>

int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  
  printf("%d\n", a+b);
  printf("%d\n", a-b);
  printf("%d\n", a*b);
  printf("%d\n", a/b);
  printf("%d", a%b);
  return 0;
}
