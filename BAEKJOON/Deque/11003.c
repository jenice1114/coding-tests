// https://www.acmicpc.net/problem/11003
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 5000000

int arr[MAX_LEN];
int dq[MAX_LEN];
int front = 0;
int rear = 0;

int main() {
  int N, L;
  scanf("%d %d", &N, &L);
  
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
    
    if (front != rear && dq[front] <= i - L) {
      front++;
    }
    
    while (front != rear && arr[dq[rear - 1]] >= arr[i]) {
      rear--;
    }
    
    dq[rear++] = i;
    
    printf("%d ", arr[dq[front]]);
  }
  
  return 0;
}

/*
  슬라이딩 윈도우 방법 사용
  L 이 범위, D(i) = A(i-L+1) ~ A(i) 중의 최솟값
*/
