// https://softeer.ai/practice/9496
// C11

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int smax = 0;
  for (int i=0; i<N; i++) {
    int car;
    scanf("%d", &car);

    if (car > smax) {
      smax = car;
    }
  }

  int time = (N-1) + smax;
  printf("%d", time);
  return 0;
}

/*
  예제: N = 4, si = [5, 7, 8, 11]
  단계 수 중 가장 큰 값은 11 (smax)
  가장 시간이 많이 걸리는 작업이 11초이므로, 이 작업이 완료되려면 최소 11초가 필요합니다.
  
  기본적으로 필요한 간격은 N-1 = 3
  작업이 순서대로 들어가면서,
  첫 번째 작업 후,
  두 번째 작업이 들어가는 데 1초,
  세 번째 작업이 들어가는 데 1초,
  네 번째 작업이 들어가는 데 1초가 추가로 필요합니다.
  
  그래서 최소 시간 = 3초 (기본 간격) + 11초 (가장 긴 작업 시간) = 14초
 */
