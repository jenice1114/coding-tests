// https://www.acmicpc.net/problem/1931
// C11

#include <stdio.h>
#include <stdlib.h>

typedef struct meeting {
  int start;
  int end;
} meeting;

int compare(const void* a, const void* b) {
  meeting* A = (meeting*)a;
  meeting* B = (meeting*)b;
  
  if (A->end == B->end) {
    return A->start - B->start;
  }
  
  return A->end - B->end;
}

int main() {
  int N;
  scanf("%d", &N);
  
  meeting Mt[N];
  
  for (int i=0; i<N; i++) {
    scanf("%d %d", &Mt[i].start, &Mt[i].end);
  }
  
  qsort(Mt, N, sizeof(meeting), compare);
  
  int count = 0;
  int end_time = 0;
  for (int i=0; i<N; i++) {
    if (Mt[i].start >= end_time) {
      count++;
      end_time = Mt[i].end;
    }
  }
  
  printf("%d", count);
  
  return 0;
}
