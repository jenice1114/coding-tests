// https://www.acmicpc.net/problem/2573
// C11

#include <stdio.h>

#define MAX_LEN 301

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N,M;
int iceberg[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];

void melt() {
  int temp[MAX_LEN][MAX_LEN] = {0};  // 녹는 양을 저장하는 임시 배열
  
  // 빙산 녹는 양 계산
  for (int i=1; i<N-1; i++) {
    for (int j=1; j<M-1; j++) {
      if (iceberg[i][j] > 0) {
        int sea_count = 0;
        for (int k=0; k<4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (iceberg[nx][ny] == 0) {
            sea_count++;
          }
        }
        temp[i][j] = sea_count;
      }
    }
  }

  // 녹은 양 적용
  for (int i=1; i<N-1; i++) {
    for (int j=1; j<M-1; j++) {
      iceberg[i][j] -= temp[i][j];
      if (iceberg[i][j] < 0) {
        iceberg[i][j] = 0;
      }
    }
  }
}

void dfs(int x, int y) {
  visit[x][y] = 1;
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
        visit[nx][ny] == 0 && iceberg[nx][ny] > 0) {
      dfs(nx, ny);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &iceberg[i][j]);
    }
  }
  
  int year = 0;
  while (1) {
    int part = 0;
    memset(visit, 0, sizeof(visit));
    for (int i=0; i<N-1; i++) {
      for (int j=0; j<M-1; j++) {
        if (iceberg[i][j] > 0 && visit[i][j] == 0) {
          dfs(i,j);
          part++;
        }
      }
    }
    if (part >= 2) {
      printf("%d\n", year);
      return 0;
    } else if (part == 0) {
      printf("0");
      return 0;
    }
    melt(); // 녹여!
    year++;
  }
  
  return 0;
}
