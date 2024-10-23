// https://www.acmicpc.net/problem/1780
// C11

#include <stdio.h>

#define MAX_LEN 2188 // 3^7=2187

int paper[MAX_LEN][MAX_LEN];
int cntA, cntB, cntC;

int check(int x, int y, int size) {
  int target = paper[x][y];
  for (int i=x; i<x+size; i++) {
    for (int j=y; j<y+size; j++) {
      if (paper[i][j] != target) {
        return 0;
      }
    }
  }
  return 1;
}

void sameNum(int x, int y, int size) {
  if (check(x,y,size)) {
    int temp = paper[x][y];
    if (temp == -1) {
      cntA++;
    } else if (temp == 0) {
      cntB++;
    } else if (temp == 1) {
      cntC++;
    }
    return;
  }
  
  int newSize = size/3;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      sameNum(x+i*newSize, y+j*newSize, newSize);
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &paper[i][j]);
    }
  }
  
  sameNum(0,0,N);
  
  printf("%d\n%d\n%d", cntA, cntB, cntC);
  
  return 0;
}
