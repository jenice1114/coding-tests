// https://www.acmicpc.net/problem/17298
// C11

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  int seq[N];
  int result[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &seq[i]);
    result[i] = -1;
  }
  
  int stack[N];
  int top = 0;
  for (int i=0; i<N; i++) {
    while (top > 0 && seq[i] > seq[stack[top-1]]) {
      result[stack[top-1]] = seq[i];
      top--;
    }
    stack[top++] = i; // 스텍에 인덱스를 담음
  }
  
  for (int i=0; i<N; i++) {
    printf("%d ", result[i]);
  }
  
  return 0;
}

/*
  target = 3, 5, 2, 7, result = -1, -1, -1, -1, top = 0, stack = []
  stack 3(0), top 1

  target = 5, 2, 7, result = -1, -1, -1, -1, top = 1, stack = [0]
  stack 5(1), top 1
  result 5, -1, -1, -1

  target = 2, 7, result = 5, -1, -1, -1, top = 1, stack = [1]
  stack 5(1) 2(2), top 2
  result 5, -1, -1, -1

  target = 7, result = 5, -1, -1, -1, top = 2, stack = [1, 2]
  stack 5(1) 2(2), top 2
  result 5, -1, 7, -1
  stack 5(1) top 1
  result 5, 7, 7, -1
*/
