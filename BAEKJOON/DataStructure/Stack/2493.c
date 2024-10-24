// https://www.acmicpc.net/problem/2493
// C11

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  int top[N];
  int result[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &top[i]);
    result[i] = 0;
  }
  
  int stack[N];
  int idx = 0;
  for (int i=0; i<N; i++) {
    while (idx > 0 && top[i] >= top[stack[idx-1]]) {
      idx--;
    }
    
    if (idx > 0) {
      result[i] = stack[idx-1] +1;
    }
    
    // 탑 idx를 stack에 저장
    stack[idx++] = i;
  }
  
  for (int i=0; i<N; i++) {
    printf("%d ", result[i]);
  }
  
  return 0;
}
