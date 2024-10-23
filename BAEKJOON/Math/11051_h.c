// https://www.acmicpc.net/problem/11051
// C11

#include <stdio.h>

#define MOD 10007

int dp[1001][1001]; // DP 테이블을 정의, 최대 1000x1000 크기

// 이항계수를 동적 계획법으로 계산하는 함수
void compute_binomial_coefficient(int N) {
  // 초기 조건: nC0 = nCn = 1
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 1; // nC0 = 1
    dp[i][i] = 1; // nCn = 1
  }
  
  // 점화식을 이용해 이항계수 계산
  for (int n = 2; n <= N; n++) {
    for (int k = 1; k < n; k++) {
      dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % MOD;
    }
  }
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  
  // 이항계수를 동적 계획법으로 미리 계산
  compute_binomial_coefficient(N);
  
  // 결과 출력
  printf("%d\n", dp[N][K]);
  
  return 0;
}

/*
  못풀었다 ㅎㅎ 공식을 알고 dp로 풀면 되는 문제였다

  이항계수는 파스칼의 삼각형의 성질을 따른다
  이전 두 이항계수를 더한 값으로 구할 수 있음

  초기값 (n 0), (n n) = 1
    n개의 원소 중 하나도 안 고른다면 경우의 수는 1가지
    n개의 원소 중 n개를 다 고른다면 경우의 수는 1가지

  점화식 (n k) = (n-1 k-1) + (n-1 k)


  파스칼의 삼각형 성질

      1             -> \(\binom{0}{0}\)
     1 1            -> \(\binom{1}{0}, \binom{1}{1}\)
    1 2 1           -> \(\binom{2}{0}, \binom{2}{1}, \binom{2}{2}\)
   1 3 3 1          -> \(\binom{3}{0}, \binom{3}{1}, \binom{3}{2}, \binom{3}{3}\)
  1 4 6 4 1         -> \(\binom{4}{0}, \binom{4}{1}, \binom{4}{2}, \binom{4}{3}, \binom{4}{4}\)

  가장자리는 항상 1이다
  안 쪽 숫자는 위 두 숫자의 합이다
*/
