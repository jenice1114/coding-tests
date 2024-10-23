// https://www.acmicpc.net/problem/6064
// C11

#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * (b / gcd(a,b));
}

int main() {
  int tc;
  scanf("%d", &tc);
  
  while (tc--) {
    int M, N, x, y;
    scanf("%d %d %d %d", &M, &N, &x, &y);
    
    int target = lcm(M, N);
    int result = -1;
    for (int i=x; i<=target; i+=M) {
      if ((i-1) % N + 1 == y) {
        result = i;
        break;
      }
    }
    
    printf("%d\n", result);
  }
  
  return 0;
}

/*
  x는 1부터~M까지 반복, y는 1부터~N까지 반복 되므로
  M, N의 최소공배수를 넘지 않는다

  최소 공배수 : LCM(a,b) = a * b / GCD(a,b)
  최대 공약수(유클리드호제법) : GCD(a,b) = GCD(b,r) r = a % b

  M = 10, N = 12, x = 3, y = 9 일때,
  M,N의 최소공배수는 60
  x = 3, 13, 23, 33, ...
  y = 9, 21, 33, ...

  x = 3일때 M 간격으로 증가 하면서 y값이 9인지 확인
  (i-1) % N + 1 == y
  32 % 12 + 1 = 33

  33번째 해가 3,9로 맞춰짐

  (i-1) % N + 1 == y
  i-1 또는 N+1 하는이유
    N = 12, i = 12일 때, 12 % 12 = 0이 나옴
    i - 1 % N + 1로 계산하면,
    (12 - 1) % 12 + 1 = (11 % 12) + 1 = 11 + 1 = 12
    이 방식으로 12번째 해에서 y = 12가 나오게끔 설계
*/
