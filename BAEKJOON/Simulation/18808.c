// https://www.acmicpc.net/problem/18808
// C11

#include <stdio.h>

#define MAX 41

int n,m,k,r,c;
int laptop[MAX][MAX];
int sticker[11][11];

void rotate() {
  int tmp[11][11];
  
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      tmp[i][j] = sticker[i][j];
    }
  }
  
  for (int i=0; i<c; i++) {
    for (int j=0; j<r; j++) {
      sticker[i][j] = tmp[r-1-j][i];
    }
  }
  
  int temp = r;
  r = c;
  c = temp;
}

int pastable(int x, int y) {
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      if (laptop[x+i][y+j] == 1 && sticker[i][j] == 1) {
        return 0;
      }
    }
  }
  
  // 스티커 붙히기
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      if (sticker[i][j] == 1) {
        laptop[x+i][y+j] = 1;
      }
    }
  }
  return 1;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  
  while (k--) {
    scanf("%d %d", &r, &c);
    
    for (int i=0; i<r; i++) {
      for (int j=0; j<c; j++) {
        scanf("%d", &sticker[i][j]);
      }
    }
    
    for (int i=0; i<4; i++) {
      int flag = 0;
      for (int x=0; x<=n-r; x++) {
        if (flag == 1) break;
        
        for (int y=0; y<=m-c; y++) {
          if (pastable(x, y)) {
            flag = 1;
            break;
          }
        }
      }
      if (flag == 1) break;
      rotate();
    }
  }
  
  int cnt = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (laptop[i][j] == 1) {
        cnt++;
      }
    }
  }
  printf("%d", cnt);
  
  return 0;
}
