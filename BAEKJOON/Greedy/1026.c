// https://www.acmicpc.net/problem/1026
// C11

#include <stdio.h>
#include <stdlib.h>

int* B;

int compare_Bidx(const void* a, const void* b) {
  int idxA = *(int*)a;
  int idxB = *(int*)b;
  return B[idxB] - B[idxA];
}

int compare_asc(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int A[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  
  B = (int*)malloc(N * sizeof(int));
  int Bidx[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &B[i]);
    Bidx[i] = i;
  }
  
  qsort(A, N, sizeof(int), compare_asc);
  qsort(Bidx, N, sizeof(int), compare_Bidx);
  
  int result = 0;
  for (int i=0; i<N; i++) {
    result += A[i] * B[Bidx[i]];
  }
  
  printf("%d\n", result);
  
  free(B);
  return 0;
}

/*
  B 배열 중 가장 큰 값부터 (내림차순)
  A 배열 중 가장 작은 값을 곱하면 (오름차순) 답이 나오는데
  문제에서 B배열을 재배열 하지 말라 라고 해서 idx가지고 배열
  쉬운데 .. 생각 잘못하면 와장창 실패 (ㅠㅠ)... 한 6번 실패했다.......
  생각 못 한 부분은 값이 중복될 때 어떻게 순서(인덱스)를 셀꺼냐 였다.. 결국 정렬을 해야 된다는 것.
*/
