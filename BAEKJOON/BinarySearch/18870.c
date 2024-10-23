// https://www.acmicpc.net/problem/18870
// C11

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  int A = *(int*)a;
  int B = *(int*)b;
  
  if (A > B) return 1;
  else if (A < B) return -1;
  else return 0;
}

int bs(int copy[], int size, int target) {
  int left = 0;
  int right = size -1;
  
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (copy[mid] == target) return mid;
    else if (copy[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  int N;
  scanf("%d", &N);
  
  int posi[N];
  int temp[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &posi[i]);
    temp[i] = posi[i];
  }
  
  qsort(temp, N, sizeof(int), compare);
  
  int copy[N];
  int cnt = 0;
  
  copy[cnt++] = temp[0];
  
  for (int i=1; i<N; i++) {
    if (temp[i] != temp[i-1]) {
      copy[cnt++] = temp[i];
    }
  }
  
  for (int i=0; i<N; i++) {
    printf("%d ", bs(copy, cnt, posi[i]));
  }
  
  return 0;
}

/*
  중복숫자 지우고 그걸로 이진탐색 하면 됨
*/
