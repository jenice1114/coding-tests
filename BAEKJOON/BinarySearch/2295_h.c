// https://www.acmicpc.net/problem/2295
// C11

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int binary_search(int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) return 1;
    else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  qsort(a, n, sizeof(int), compare);

  int two[n * n];
  int two_size = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      two[two_size++] = a[i] + a[j];
    }
  }

  qsort(two, two_size, sizeof(int), compare);

  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      int diff = a[i] - a[j];
      if (binary_search(two, two_size, diff)) {
        printf("%d\n", a[i]);
        return 0;
      }
    }
  }

  return 0;
}

/*
  못풀었다 이진탐색으로 푸는데 시간초과 오지게 걸려가지고 나의 선생님 챗지피티에게 물어봤다 ㅎ
  값을 받아온 다음 두 수의 합을 저장하는 배열을 만들고 이 배열을 또 정렬한다
  마지막으로 이진탐색 사용해서 두수의 차가 합배열에 있는지 확인한다
*/
