// https://www.acmicpc.net/problem/1874
// C11

#include <stdio.h>

#define MAX_LEN 100001

int stack[MAX_LEN];
int idx = 0;

void push(int x) {
  stack[idx++] = x;
}

int pop() {
  return stack[--idx];
}

int main() {
  int n;
  scanf("%d", &n);
  
  int sequence[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &sequence[i]);
  }
  
  int current = 1;
  char result[MAX_LEN * 2];
  int result_idx = 0;

  for (int i=0; i<n; i++) {
    int target = sequence[i];
    
    // 현재 스택에 있는 최상단 값이 target보다 작거나 같으면 스택에 더 넣어야 함
    while (target >= current) {
      push(current++);
      result[result_idx++] = '+';
    }
    
    // 스택의 최상단 값이 수열의 target과 같으면 pop
    if (target == stack[idx - 1]) {
      pop();
      result[result_idx++] = '-';
    } else {
      printf("NO\n");
      return 0;
    }
  }
  
  for (int i=0; i<result_idx; i++) {
    printf("%c\n", result[i]);
  }
  
  return 0;
}

/*
  이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.

  target = 4, 3, 6, 8, 7, 5, 2, 1, current = 1, stack
  stack 1, 2, 3, 4 push
  stack 4 pop 3 pop

  target = 6, 8, 7, 5, 2, 1, current = 4, stack 1, 2
  stack 5, 6 push
  stack 6 pop

  target = 8, 7, 5, 2, 1, current = 6, stack 1, 2, 5
  stack 7, 8 push
  stack 8 pop 7 pop

  target = 5, 2, 1, current = 6, stack 1, 2, 5
  stack 5, 2, 1 pop
*/
