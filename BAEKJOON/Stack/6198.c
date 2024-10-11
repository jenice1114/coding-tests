// https://www.acmicpc.net/problem/6198
// C11

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  int building[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &building[i]);
  }
  
  int stack[N];
  int top = 0;
  long long result = 0;
  for (int i=0; i<N; i++) {
    // 나보다 크면 스택에서 제거
    while (top > 0 && building[i] >= building[stack[top-1]]) {
      top--;
    }
    
    // 스택 크기만큼 볼 수 있음
    result += top;
    stack[top++] = i; // 현재 빌딩 인덱스 스택에 저장
  }
  
  printf("%lld", result);
  
  return 0;
}
