// https://softeer.ai/practice/6246
// C11

#include <stdio.h>
#include <stdlib.h>

typedef struct position {
  int x;
  int y;
} posi;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
int map[5][5];
int visit[5][5];
posi path[16];
int result = 0;

void dfs(int x, int y, int depth) {
  if (x == path[depth].x - 1 && y == path[depth].y - 1) {
    if (depth == m-1) {
      result++;
      return;
    } else {
      depth++;
    }
  }

  visit[x][y] = 1;
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
        visit[nx][ny] == 0 && map[nx][ny] == 0) {
      dfs(nx, ny, depth);
    }
  }
  visit[x][y] = 0;
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  for (int i=0; i<m; i++) {
    scanf("%d %d", &path[i].x, &path[i].y);
  }

  dfs(path[0].x - 1, path[0].y - 1, 0);
  printf("%d", result);

  return 0;
}

/*
  m 구간 제대로 안봐서 5로 선언하고 뺑뺑이쳤다;
 */
