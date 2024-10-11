// https://www.acmicpc.net/problem/10093
// C99

#include <stdio.h>

int main() {
  long long A, B;
  scanf("%lld %lld", &A, &B);

  if (A > B) {
    long long temp = A;
    A = B;
    B = temp;
  }

  if (A == B) {
    printf("0\n");
  } else {
    printf("%lld\n", B-A-1);

    for (long long i=A+1; i<B; i++) {
      printf("%lld ", i);
    }
  }

  return 0;
}

/*
  두 수 사이의 정수 개수 구하기 B-A-1
  -1 하는이유는 B,A를 제외한 사이값을 구하기 때문
  그래서 출력도 A+1 부터 B-1까지 하는거임
*/
