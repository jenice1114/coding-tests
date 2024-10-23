// https://www.acmicpc.net/problem/2230
// C11

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int N,M;
  scanf("%d %d", &N, &M);
  
  int num[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &num[i]);
  }
  qsort(num, N, sizeof(int), compare);
  
  int min = 2000000001;
  int left = 0;
  int right = 0;
  while (right < N) {
    int temp = num[right] - num[left];
    if (temp >= M) {
      if (temp < min) {
        min = temp;
      }
      left++;
    } else {
      right++;
    }
  }
  
  printf("%d", min);
  return 0;
}

/*
  퀵정렬로 오름차순 정렬했기 때문에 left가 right를 넘을 일은 없음
  차이가 충분히 크다면 더 작은 차이를 찾기 위해 left를 이동
  차이가 M보다 작다면 더 큰 차이를 만들기 위해 right를 이동
 */
