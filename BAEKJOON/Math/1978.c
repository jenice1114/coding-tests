// https://www.acmicpc.net/problem/1978
// C11

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  int count = 0;
  for (int i=0; i<N; i++) {
    int num;
    scanf("%d", &num);
    
    int flag = 1;
    for (int j=2; j<num; j++) {
      if (num % j == 0) {
        flag = 0;
        break;
      }
    }
    
    if (flag == 1 && num != 1) {
      count++;
    }
  }
  printf("%d", count);
  
  return 0;
}
