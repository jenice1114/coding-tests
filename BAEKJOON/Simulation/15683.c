// https://www.acmicpc.net/problem/15683
// C11

#include <stdio.h>

#define MAX 10

typedef struct CCTV {
  int x;
  int y;
} CCTV;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N,M;
int board1[MAX][MAX];
int board2[MAX][MAX];
int cctv_cnt;

CCTV cctvs[MAX];
int cctv_count;

int OOB(int a, int b) {
  return a < 0 || a >= N || b < 0 || b >= M;
}

void upd(int x, int y, int dir) {
  dir %= 4;
  while (1) {
    x += dx[dir];
    y += dy[dir];
    if (OOB(x, y) || board2[x][y] == 6) return; // 범위를 벗어났거나 벽을 만나면 함수 종료
    if (board2[x][y] != 0) continue;            // 해당 칸이 빈칸이 아닐 경우 넘어감
    board2[x][y] = 7;                           // 빈칸을 7로 덮음
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  int spot = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &board1[i][j]);
      if (board1[i][j] != 0 && board1[i][j] != 6) {
        cctvs[cctv_count].x = i;
        cctvs[cctv_count].y = j;
        cctv_count++;
      }
      if (board1[i][j] == 0) {
        spot++;
      }
    }
  }
  
  for (int tmp=0; tmp<(1<<2*cctv_count); tmp++) {
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        board2[i][j] = board1[i][j];
      }
    }
    
    int brute = tmp;
    for (int i=0; i<cctv_count; i++) {
      int dir = brute % 4;
      brute /= 4;
      
      int x = cctvs[i].x;
      int y = cctvs[i].y;
      
      if (board1[x][y] == 1) {
        upd(x, y, dir);
      } else if (board1[x][y] == 2) {
        upd(x, y, dir);
        upd(x, y, dir+2);
      } else if (board1[x][y] == 3) {
        upd(x, y, dir);
        upd(x, y, (dir+1) % 4);
      } else if (board1[x][y] == 4) {
        upd(x, y, dir);
        upd(x, y, (dir + 1) % 4);
        upd(x, y, (dir + 2) % 4);
      } else if (board1[x][y] == 5) {
        for (int d = 0; d < 4; d++) {
          upd(x, y, d);
        }
      }
    }
    
    int val = 0;
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        if (board2[i][j] == 0) {
          val++;
        }
      }
    }
    if (val < spot) {
      spot = val;
    }
  }
  
  printf("%d", spot);
  
  return 0;
}

/*
  극악의 난이도다.. 못풀었다
  조건 뽑아내기엔 쉬웠는데 구현하려니까 뇌정지가 와버렸다...
  구현하기 어려웠던 부분은 당연히도 좌표부분(ㅠㅠ)
  진짜 추하게 type에 따라 모두 for문 돌려야 되나 싶었는데
  그냥 정답코드 봤다...
  세상에 어메이징 4진수로 표현하다니 당신은 천재입니까? amazing!
*/
