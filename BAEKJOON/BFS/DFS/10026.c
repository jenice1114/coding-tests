// https://www.acmicpc.net/problem/10026
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N;
char grid[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];

void dfs(int x, int y, char color, int isBlind) {
  visit[x][y] = 1;
  
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == 0) {
      if (isBlind) {
        if ((color == 'R' || color == 'G') &&
            (grid[nx][ny] == 'R' || grid[nx][ny] == 'G')) {
          dfs(nx, ny, color, isBlind);
        } else if (color == 'B' && grid[nx][ny] == 'B') {
          dfs(nx, ny, color, isBlind);
        }
      } else {
        if (grid[nx][ny] == color) {
          dfs(nx, ny, color, isBlind);
        }
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    scanf("%s", grid[i]);
  }
  
  int human = 0;
  memset(visit, 0, sizeof(visit));
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (visit[i][j] == 0) {
        dfs(i, j, grid[i][j], 0);
        human++;
      }
    }
  }
  
  int colorBlind = 0;
  memset(visit, 0, sizeof(visit));
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (visit[i][j] == 0) {
        dfs(i, j, grid[i][j], 1);
        colorBlind++;
      }
    }
  }
  
  printf("%d %d", human, colorBlind);
  
  return 0;
}
