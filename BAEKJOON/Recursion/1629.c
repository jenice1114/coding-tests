// https://www.acmicpc.net/problem/1629
// C11

#include <stdio.h>

long long calcul(long long A, long long B, long long C) {
  if (B == 0) return 1;
  
  long long half = calcul(A, B/2, C);
  
  if (B % 2 == 0) {
    return (half * half) % C;
  } else {
    return ((half * half) % C * A) % C;
  }
}

int main() {
  int A,B,C;
  scanf("%d %d %d", &A, &B, &C);
  printf("%lld", calcul(A, B, C));
  
  return 0;
}

/*
  첨 들어보는데 분할정복 모듈러 연산법을 사용해야 된다고 한다

  B가 짝수일 때,
  A^B = (A^b/2) * (A^b/2)
  B가 홀수일 때
  A^B = A * (A^B-1)
  (A^B-1) 은 결국 짝수이므로 짝수연산하고 A를 곱함

  그리고 나머지 처리하면 쨔란 빠른 재귀함수 탄생
*/
