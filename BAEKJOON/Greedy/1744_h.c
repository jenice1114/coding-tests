// https://www.acmicpc.net/problem/1744
// C11

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int arr[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  
  qsort(arr, N, sizeof(int), compare);
  
  long long result = 0;

  // 양수 처리 (1보다 큰 값만 곱하기)
  int i = 0;
  while (i < N && arr[i] > 1) {
    if (i + 1 < N && arr[i + 1] > 1) {
      result += arr[i] * arr[i + 1];  // 양수 묶기
      i += 2;
    } else {
      result += arr[i];  // 묶지 않고 더하기
      i++;
    }
  }

  // 1 처리 (1은 곱하는 것보다 더하는 것이 이익)
  while (i < N && arr[i] == 1) {
    result += arr[i];
    i++;
  }

  // 음수 처리 (음수는 작은 값끼리 곱하기)
  int j = N - 1;
  while (j >= 0 && arr[j] <= 0) {
    if (j - 1 >= 0 && arr[j - 1] <= 0) {
      result += arr[j] * arr[j - 1];  // 음수 묶기
      j -= 2;
    } else {
      result += arr[j];  // 묶지 않고 더하기 (음수 하나 남았을 때)
      j--;
    }
  }

  printf("%lld\n", result);  // 최종 이익 출력

  return 0;
}

/*
  정렬써서 양/음수 나눠서 계산하는거 까지는 유추했는데
  1은 따로 처리해야된다거나...
  for문이 아닌 while문으로 돌려야한다거나 이부분은 예측못해서 시간초과로 못 푼 문제(ㅠㅠ)
*/
