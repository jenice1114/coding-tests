// https://www.acmicpc.net/problem/2504
// C11

#include <stdio.h>

int main() {
  char ps[51];
  scanf("%s", ps);
  
  char stack[51];
  int top = 0;
  int result = 0;
  int psCnt = 1;
  for (int i=0; ps[i]!='\0'; i++) {
    if (ps[i] == '(') {
      stack[top++] = ps[i];
      psCnt *= 2;
    } else if (ps[i] == '[') {
      stack[top++] = ps[i];
      psCnt *= 3;
    } else if (ps[i] == ')') {
      if (top == 0 || stack[top-1] != '(') {
        result = 0;
        break;
      }
        
      if (ps[i-1] == '(') {
        result += psCnt;
      }
      top--;
      psCnt /= 2;
    } else if (ps[i] == ']') {
      if (top == 0 || stack[top-1] != '[') {
        result = 0;
        break;
      }
        
      if (ps[i-1] == '[') {
        result += psCnt;
      }
      top--;
      psCnt /= 3;
    }
  }
  
  if (top != 0) {
    result = 0;
  }
  printf("%d", result);
  
  return 0;
}

/*
  () = 2, [] = 3, (x) = 2*값, [x] = 3*값
  ([)] 는 올바른 괄호열이 아님, 무조건 한쌍으로 되어야 한다

  ( 가 열리면 *2
  [ 가 열리면 *3 가 베이스 코드

  ) 가 닫히면 stack에 저장해놓은 마지막 열이 ( 가 맞는지 확인 아닐 경우 올바른 괄호열이 아님
  ) 전 문자가 ( 라면, result에 카운팅 해놓은걸 저장
  
  ] 동일

  스택은 괄호가 올바르게 닫히는지 추적하며, 값을 더하는 계산을 위해서는 ps(받은문자열)로 확인
*/
