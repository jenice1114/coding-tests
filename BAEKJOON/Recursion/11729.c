// https://www.acmicpc.net/problem/11729
// C11

#include <stdio.h>

void hanoiTop(int n, int from, int to, int aux) {
  if (n==1) {
    printf("%d %d\n", from, to);
    return;
  }
  
  hanoiTop(n-1, from, aux, to);
  printf("%d %d\n", from, to);
  hanoiTop(n-1, aux, to, from);
}

int main() {
  int N;
  scanf("%d", &N);
  
  printf("%d\n", (1 << N) - 1);
  hanoiTop(N, 1, 3, 2);
  
  return 0;
}

/*
x^N 승을 표현하고자 할때 pow함수를 사용하면 됨
2^N은 1 << N 이 빠르지만,
나머지는 표현할 수 없으므로 pow(x, N) 을 사용하도록 하자

예시코드
#include <math.h>  // pow 함수 사용을 위해 math.h 헤더 포함

int main() {
    int N;
    
    scanf("%d", &N);  // N 입력 받기
    
    // pow(2, N)을 사용하고 결과를 int로 변환하여 출력
    printf("%d\n", (int)pow(2, N));  // pow는 double을 반환하므로 int로 변환
    
    return 0;
}

*/
