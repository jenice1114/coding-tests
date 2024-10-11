// https://www.acmicpc.net/problem/3986
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001

int main() {
  int N;
  scanf("%d", &N);
  
  int result = 0;
  while(N--) {
    char str[100001];
    scanf("%s", str);
    
    int stack[MAX_LEN];
    int top = 0;
    for (int i=0; i<strlen(str); i++) {
      if (top > 0 && str[i] == str[stack[top-1]]) {
        top--;
      } else {
        stack[top++] = i;
      }
    }
    
    if (top == 0) {
      result++;
    }
  }
  
  printf("%d", result);
  
  return 0;
}
