// https://www.acmicpc.net/problem/10828
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[10001]; // 최대치 선언
int cnt = 0;

void push(int x) {
  stack[cnt++] = x;
}

// 정수빼서 출력
int pop() {
  if (!empty()) {
    return stack[--cnt];
  } else {
    return -1;
  }
}

// 스택에 들어있는 정수 갯수 출력
int size() {
  return cnt;
}

// 스택 비어있으면 1, 아니면 0
int empty() {
  return cnt == 0 ? 1 : 0;
}

// 스택의 가장 위에 있는 정수 출력
// 만약 스택에 들어있는 정수가 없는 경우 -1 출력
int top() {
  if (!empty()) {
    return stack[cnt - 1];
  } else {
    return -1;
  }
}


int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    char cmd[6];
    scanf("%s", cmd);
    
    if (strcmp(cmd, "push") == 0) {
      int x;
      scanf("%d", &x);
      push(x);
    } else if (strcmp(cmd, "pop") == 0) {
      printf("%d\n", pop());
    } else if (strcmp(cmd, "size") == 0) {
      printf("%d\n", size());
    } else if (strcmp(cmd, "empty") == 0) {
      printf("%d\n", empty());
    } else if (strcmp(cmd, "top") == 0) {
      printf("%d\n", top());
    }
  }
  
  return 0;
}
