// https://www.acmicpc.net/problem/10773
// C11

#include <stdio.h>

int main() {
  int stack[100001]; // 최대치 선언
  int cnt = 0;
  int K;
  scanf("%d", &K);
  
  for (int i=0; i<K; i++) {
    int x;
    scanf("%d", &x);
    
    if (x == 0) {
      cnt--;
    } else {
      stack[cnt++] = x;
    }
  }
  
  int result = 0;
  for (int i=0; i<cnt; i++) {
    result += stack[i];
  }
  printf("%d", result);
  
  return 0;
}
