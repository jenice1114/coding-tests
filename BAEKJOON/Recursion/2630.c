// https://www.acmicpc.net/problem/2630
// C11

#include <stdio.h>

#define MAX_LEN 129

int colorPaper[MAX_LEN][MAX_LEN];
int blue, white;

int CheckArea(int x, int y, int size) {
  int target = colorPaper[x][y];
  for (int i=x; i<x+size; i++) {
    for (int j=y; j<y+size; j++) {
      if (colorPaper[i][j] != target) {
        return 0;
      }
    }
  }
  return 1;
}

void CheckPaper(int x, int y, int size) {
  if (CheckArea(x,y,size)) {
    int temp = colorPaper[x][y];
    if (temp == 0) {
      white++;
    } else if (temp == 1) {
      blue++;
    }
    return;
  }
  
  int newSize = size/2;
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      CheckPaper(x+i*newSize, y+j*newSize, newSize);
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &colorPaper[i][j]);
    }
  }
  
  CheckPaper(0,0,N);
  
  printf("%d\n%d\n", white, blue);
  
  return 0;
}

/*
  1780 유사, 2로 나누기 때문에
  굳이 이중 for문 안만들고

  CheckPaper(x, y, newSize);
  CheckPaper(x, y + newSize, newSize);
  CheckPaper(x + newSize, y, newSize);
  CheckPaper(x + newSize, y + newSize, newSize);

  하는 방안도 있는듯
*/
