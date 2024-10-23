// https://www.acmicpc.net/problem/2583
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 101

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int M, N, K;
int map[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];

int dfs(int x, int y) {
  visit[x][y] = 1;
  int size = 1;
  
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
      if (visit[nx][ny] == 0 && map[nx][ny] == 0) {
        size += dfs(nx, ny);
      }
    }
  }
  
  return size;
}

int main() {
  // M(x), N(y)
  scanf("%d %d %d", &M, &N, &K);
  
  memset(map, 0, sizeof(map));
  memset(visit, 0, sizeof(visit));
  
  for (int i=0; i<K; i++) {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    for (int i=y1; i<y2; i++) {
      for (int j=x1; j<x2; j++) {
        map[i][j] = 1;
      }
    }
  }
  
  int size[MAX_LEN * MAX_LEN];
  int group = 0;
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      if (map[i][j] == 0 && visit[i][j] == 0) {
        size[group] = dfs(i,j);
        group++;
      }
    }
  }
  
  printf("%d\n", group);
  qsort(size, group, sizeof(int), compare);
  for (int i=0; i<group; i++) {
    printf("%d ", size[i]);
  }
  
  return 0;
}
