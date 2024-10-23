// https://www.acmicpc.net/problem/2448
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 3073
char map[MAX_LEN][MAX_LEN*2];

void Star(int x, int y, int size) {
  if (size==3) {
    map[x][y] = '*';
    map[x + 1][y - 1] = '*';
    map[x + 1][y + 1] = '*';
    map[x + 2][y - 2] = '*';
    map[x + 2][y - 1] = '*';
    map[x + 2][y] = '*';
    map[x + 2][y + 1] = '*';
    map[x + 2][y + 2] = '*';
    return;
  }
  
  int newSize = size/2;
  Star(x, y, newSize);
  Star(x+newSize, y-newSize, newSize);
  Star(x+newSize, y+newSize, newSize);
}

int main() {
  int N;
  scanf("%d", &N);
  
  memset(map, ' ', sizeof(map));
  
  Star(0,N-1,N);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<2*N-1; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

/*
  가운데부터 시작하니까 Y의 좌표가 N-1부터 시작
*/
