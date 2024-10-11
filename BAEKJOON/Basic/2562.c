// https://www.acmicpc.net/problem/2562
// C99

#include <stdio.h>

int main() {
  int arr[10];
  for (int i=1; i<=9; i++) {
    scanf("%d", &arr[i]);
  }
  
  int max = arr[1];
  int idx = 1;
  for (int i=2; i<=9; i++) {
    if (arr[i] > max) {
      max = arr[i];
      idx = i;
    }
  }
  
  printf("%d\n%d", max, idx);
  
  return 0;
}

/*
  최대값이 위치한 인덱스 값을 찾는 문제
  최대값 몇번째수 까지만 보고 무지성 qsort 하려는 나자신 반성하자
*/
