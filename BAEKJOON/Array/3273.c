// https://www.acmicpc.net/problem/3273
// C99

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void *b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int n;
  scanf("%d", &n);
  
  int arr[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), compare);
  
  int x;
  scanf("%d", &x);
  
  int result = 0;
  int left = 0, right = n-1;
  
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == x) {
      result++;
      left++;
      right--;
    } else if (sum < x) {
      left++;
    } else {
      right--;
    }
  }
  
  printf("%d", result);
  
  return 0;
}

/*
  오름차순 정리 후 이중포문으로 찾았더니 시간초과 나옴
  투포인터방법 사용 (i<j 조건)
*/
