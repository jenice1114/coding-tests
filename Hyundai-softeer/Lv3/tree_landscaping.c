// https://softeer.ai/practice/7594
// C11

#include <stdio.h>

int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int map[5][5];
int visit[5][5];
int result;

void DFS(int pairs, int total) {
  if (pairs == 4) {
    if (total > result) {
      result = total;
    }
    return;
  }

  for (int x=0; x<n; x++) {
    for (int y=0; y<n; y++) {
      if (visit[x][y] == 0) {
        for (int i=0; i<4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          if (nx >= 0 && nx < n && ny >= 0 && ny < n && visit[nx][ny] == 0) {
            visit[x][y] = 1;
            visit[nx][ny] = 1;
            DFS(pairs+1, total + map[x][y] + map[nx][ny]);
            visit[x][y] = 0;
            visit[nx][ny] = 0;
          }
        }
      }
    }
  }
  if (total > result) {
    result = total;
  }
}

int main() {
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  DFS(0, 0);

  printf("%d", result);
  return 0;
}
