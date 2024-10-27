// https://softeer.ai/practice/6280
// C11

#include <stdio.h>
#include <math.h>

int main() {
  int N;
  scanf("%d", &N);
  
  // 점의 개수 계산: (2^N + 1) ^ 2
  int side_length = pow(2, N) + 1;
  int result = side_length * side_length;
  
  printf("%d", result);
  
  return 0;
}
