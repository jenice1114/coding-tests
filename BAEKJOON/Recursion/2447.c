// https://www.acmicpc.net/problem/2447
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 2188

char map[MAX_LEN][MAX_LEN];

void Star(int x, int y, int size) {
  if (size == 1) {
    map[x][y] = '*';
    return;
  }
  
  int newSize = size/3;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (i == 1 && j == 1) {
        continue;
      }
      Star(x+newSize*i, y+newSize*j, newSize);
    }
  }
}

int main () {
  int N;
  scanf("%d", &N);
  
  memset(map, ' ', sizeof(map));
  
  Star(0,0,N);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
