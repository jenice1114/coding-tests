// https://www.acmicpc.net/problem/9012
// C11

#include <stdio.h>

#define MAX_LEN 51

int main() {
  int T;
  scanf("%d", &T);
  
  while (T--) {
    char str[MAX_LEN];
    scanf("%s", str);
    
    char stack[MAX_LEN];
    int top = 0;
    for (int i=0; str[i]!='\0'; i++) {
      if (str[i] == '(') {
        stack[top++] = str[i];
      } else {
        if (top > 0 && stack[top-1] == '(') {
          top--;
        } else {
          top = -1;
          break;
        }
      }
    }
    
    if (top == 0) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
