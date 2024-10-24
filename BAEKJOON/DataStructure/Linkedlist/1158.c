// https://www.acmicpc.net/problem/1158
// C11

#include <stdio.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  
  int arr[N];
  for (int i=0; i<N; i++) {
    arr[i] = i+1;
  }
  
  int idx = 0;
  int cnt = 0;
  int size = N;
  printf("<");
  while (cnt < N) {
    idx = (idx + (K-1)) % size;
    
    printf("%d", arr[idx]);
    cnt++;
    
    for (int i=idx; i<size-1; i++) {
      arr[i] = arr[i+1];
    }
    size--;
    
    if (cnt < N) {
      printf(", ");
    }
  }
  printf(">");
  
  return 0;
}

/*
  출력방식이 <와 , 포함되어 있음에 유의
  idx는 원형큐 방식이기때문에 mod 연산으로 계산
  25: 하나 pop했으면 배열 재배치
*/
