// https://softeer.ai/practice/6284
// C11

#include <stdio.h>

long long power(long long base, long long exp, long long mod) {
  long long result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

int main(void) {
  int K, P, N;
  scanf("%d %d %d", &K, &P, &N);

  // P^N을 1000000007로 나눈 값 계산
  long long mod = 1000000007;
  long long totalGrowth = power(P, N, mod);

  // 최종 바이러스 수 계산: K * (P^N) % 1000000007
  long long result = (K * totalGrowth) % mod;

  printf("%lld\n", result);

  return 0;
}