// https://www.acmicpc.net/problem/1929
// C11

#include <stdio.h>
#include <math.h>

#define MAX_LEN 1000001

int main() {
  int M, N;
  scanf("%d %d", &M, &N);
  
  int arr[MAX_LEN] = {0, };
  for (int i=2; i<=N; i++) arr[i] = 1;
  
  for (int i=2; i<=sqrt(N); i++) {
    if (arr[i] == 1) {
      for (int j=i*i; j<=N; j+=i) { // 배수는 다 소수에서 제외
        arr[j] = 0;
      }
    }
  }
  
  for (int i=M; i<=N; i++) {
    if (arr[i] == 1) {
      printf("%d\n", i);
    }
  }
  
  return 0;
}

/*
  에라토스테네스의 체 알고리즘 사용 (소수를 빠르고 효율적으로 찾기 위한 알고리즘)
  1을 제외한 2부터 시작하여 소수를 판별하고 소수의 배수를 모두 지운다
  남은 수들이 소수인 격

  이 때 사용하는 함수로는 sqrt로 제곱근 값을 리턴해줌 (N=36일때, 루트36으로 6까지만 확인)
  N이 소수가 아니면 N = a x b 로 표현되는데 a,b중 하나는 N제곱근 이하로 나타나기때문
*/
