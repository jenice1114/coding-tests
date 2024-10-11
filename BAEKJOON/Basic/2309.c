// https://www.acmicpc.net/problem/2309
// C99

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int arr[9];
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  int fake1 = -1;
  int fake2 = -1;
  for (int i=0; i<9; i++) {
    for (int j=i+1; j<9; j++) {
      if (sum - arr[i] - arr[j] == 100) {
        fake1 = i;
        fake2 = j;
        break;
      }
    }
    
    if (fake1 != -1 || fake2 != -1) {
      break;
    }
  }

  int result[7];
  int res_cnt = 0;
  for (int i=0; i<9; i++) {
    if (i != fake1 && i != fake2) {
      result[res_cnt++] = arr[i];
    }
  }

  qsort(result, 7, sizeof(int), compare);

  for (int i=0; i<7; i++) {
    printf("%d\n", result[i]);
  }

  return 0;
}

/*
  효율이 박살난 코드..(ㅠㅠ)
  9명이라고 고정되어 있기 때문에 괜찮은 코드
*/
