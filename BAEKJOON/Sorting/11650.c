// https://www.acmicpc.net/problem/11650
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Position {
  int x;
  int y;
} Position;

int compare (const void* a, const void* b) {
  Position* A = (Position*)a;
  Position* B = (Position*)b;
  
  if (A->x == B->x) {
    return A->y - B->y;
  }
  return A->x - B->x;
}

int main() {
  int N;
  scanf("%d", &N);
  
  Position* pos = (Position*)malloc(N*sizeof(Position));
  for (int i=0; i<N; i++) {
    scanf("%d %d", &pos[i].x, &pos[i].y);
  }
  
  qsort(pos, N, sizeof(Position), compare);
  
  for (int i=0; i<N; i++) {
    printf("%d %d\n", pos[i].x, pos[i].y);
  }
  
  free(pos);
  return 0;
}
