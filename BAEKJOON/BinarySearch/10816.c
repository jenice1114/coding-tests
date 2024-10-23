// https://www.acmicpc.net/problem/10816
// C11

#include <stdio.h>
#include <stdlib.h>

int StartTarget(int card[], int size, int target) {
  int left = 0;
  int right = size;
  
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (card[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int EndTarget(int card[], int size, int target) {
  int left = 0;
  int right = size;
  
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (card[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int compare(const void* a, const void* b) {
  int num1 = *(int*)a;
  int num2 = *(int*)b;
  
  if (num1 < num2) return -1;
  else if (num1 > num2) return 1;
  else return 0;
}

int main() {
  int N;
  scanf("%d", &N);
  
  int card[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &card[i]);
  }
  
  qsort(card, N, sizeof(int), compare);
  
  int M;
  scanf("%d", &M);
  
  int num[M];
  for (int i=0; i<M; i++) {
    scanf("%d", &num[i]);
  }
  
  for (int i=0; i<M; i++) {
    int start = StartTarget(card, N, num[i]);
    int end = EndTarget(card, N, num[i]);
    
    printf("%d ", end - start);
  }
  
  return 0;
}

/*
  유사문제 1920

  마지막 인덱스까지 확인할 경우에는 <= 를 사용해서 right = size-1 닫힌구간 [left, right]
  이 문제는 right가 열린구간이기 때문에 right = size가 되고 반열린구간 [left, right) 가 된다

  while 조건자체가 (==) 같을 때 처리를 하지 않고 탐색범위를 줄이는 방식이기때문에 size 그대로 사용
*/
