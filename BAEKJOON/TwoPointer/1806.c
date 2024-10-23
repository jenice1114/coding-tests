// https://www.acmicpc.net/problem/1806
// C11

#include <stdio.h>

int main() {
  int N,S;
  scanf("%d %d", &N, &S);
  
  int num[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &num[i]);
  }
  
  int left = 0;
  int right = 0;
  int sum = 0;
  int length = N+1;
  while (right < N) {
    sum += num[right];
    right++;
    while (sum >= S) {
      if (right - left < length) {
        length = right - left;
      }
      sum -= num[left];
      left++;
    }
  }
  
  if (length == N+1) {
    printf("0");
  } else {
    printf("%d", length);   
  }
  
  return 0;
}

/*
  더해가면서 S이상인 값일 때의 연속된 수들의 갯수를 세는 문제 (length)
  그래서 5,10 일때 2이기때문에 가장 적은 걸 찾으라는 답이 2로 나온다
  이거를 부분합 중 가장 적은 수로 이해해서 헤맸다 (ㅠㅠ)
 */
