// https://www.acmicpc.net/problem/4949
// C11

#include <stdio.h>
#include <string.h>

int main() {
  while (1) {
    char str[102];
    fgets(str, 102, stdin);
    
    int len = strlen(str);
    if (str[len-1] == '\n') {
      str[len-1] = '\0';
      len--;
    }
    
    if (len == 1 && str[0] == '.') break;
    
    int is_error = 1;
    char stack[101];
    int top = -1;
    for (int i=0; i<len; i++) {
      if (str[i] == '[' || str[i] == '(') {
        stack[++top] = str[i];
      } else if (str[i] == ')') {
        if (top == -1 || stack[top] != '(') {
          is_error = 0;
          break;
        }
        top--;
      } else if (str[i] == ']') {
          if (top == -1 || stack[top] != '[') {
            is_error = 0;
            break;
          }
        top--;
      }
    }
    
    if (is_error && top == -1) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  
  return 0;
}

/*
  종료조건 : .
  string으로 들어오는데 공백도 포함되어 있음
  괄호가 여닫히는 순서도 중요

  fgets(str, len, stream): 공백포함 문자열 읽기에 유용 (stdin: 키보드입력)
  \n를 포함하기 때문에 100개의 문자를 받고 싶다면 \n, \0 포함해서 102를 선언해야함
*/
