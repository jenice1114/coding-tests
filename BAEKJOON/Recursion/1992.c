// https://www.acmicpc.net/problem/1992
// C11

#include <stdio.h>

#define MAX_LEN 65

int video[MAX_LEN][MAX_LEN];

int Check(int x, int y, int size) {
  int target = video[x][y];
  for (int i=x; i<x+size; i++) {
    for (int j=y; j<y+size; j++) {
      if (video[i][j] != target) {
        return 0;
      }
    }
  }
  
  return 1;
}

void Compress(int x, int y, int size) {
  if (Check(x,y,size)) {
    printf("%d", video[x][y]);
    return;
  }
  
  printf("(");
  int newSize = size/2;
  Compress(x, y, newSize);
  Compress(x, y+newSize, newSize);
  Compress(x+newSize, y, newSize);
  Compress(x+newSize, y+newSize, newSize);
  printf(")");
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%1d", &video[i][j]);
    }
  }
  
  Compress(0,0,N);
  
  return 0;
}
