// https://www.acmicpc.net/problem/10799
// C11

#include <stdio.h>

#define MAX_LEN 100001

int main() {
  char pipe[MAX_LEN];
  scanf("%s", pipe);
  
  int top = 0;
  int result = 0;
  for (int i=0; pipe[i]!='\0'; i++) {
    if (pipe[i] == '(') {
      top++;
    } else {
      top--;
      if (pipe[i-1] == '(') {
        // 레이저발사
        result += top;
      } else {
        // 파이프 마지막
        result++;
      }
    }
  }
  
  printf("%d", result);
  
  return 0;
}
