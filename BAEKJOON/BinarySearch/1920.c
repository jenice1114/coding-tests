// https://www.acmicpc.net/problem/1920
// C11

#include <stdio.h>
#include <stdlib.h>

int bs(int A[], int size, int target) {
  int left = 0;
  int right = size-1;
  
  while (left <= right) {
    int mid = left + (right - left) / 2;
    
    if (A[mid] == target) {
      return 1;
    } else if (A[mid] < target) {
      left = mid+1;
    } else if (A[mid] > target) {
      right = mid-1;
    }
  }
  return 0;
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
  
  int A[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  
  qsort(A, N, sizeof(int), compare);
  
  int M;
  scanf("%d", &M);
  
  int num[M];
  for (int i=0; i<M; i++) {
    scanf("%d", &num[i]);
  }
  
  for (int i=0; i<M; i++) {
    printf("%d\n", bs(A, N, num[i]));
  }
  
  return 0; 
}

/*
  2번 틀린 문제인데
  
  qsort를
  int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);  // 두 정수를 비교하여 차이를 반환
  }
  이런게 구현했다가 2번 틀림(ㅋㅋ)
  위처럼 구현하면 두 값의 차이가 클 경우 오버플로우가 발생 (예: a=INT_MIN, b=INT_MAX 인 경우 32비트를 넘어섬)
  제대로 계산이 안되므로 직접 크기 비교해서 반환하는 걸로 수정
*/
