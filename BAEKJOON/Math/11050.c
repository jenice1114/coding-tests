// https://www.acmicpc.net/problem/11050
// C11

#include <stdio.h>

int factorial(int x) {
  if (x == 0) return 1;
  return x * factorial(x-1);
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  
  int result = factorial(N) / (factorial(K) * factorial(N-K));
  printf("%d", result);
  return 0;
}

/*
  이항계수 공식 n개의 항 중 k개를 선택하는 경우의 수를 구하라
  (n k) = n!/k!(n-k)!
*/
