// https://www.acmicpc.net/problem/1926
// C11

#include <stdio.h>

#define MAX_LEN 501

int n, m = 0;
int pic[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];

// 동서남북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
  visit[x][y] = 1;
  int area = 1;
  
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if ((nx >= 0 && nx < n && ny >= 0 && ny < m) && // 테두리 처리 조건 (범위)
      pic[nx][ny] == 1 && visit[nx][ny] == 0) {
      area += dfs(nx, ny);
    }
  }
  return area;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%d", &pic[i][j]);
    }
  }
  
  int cnt = 0;
  int maxArea = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (visit[i][j] == 0 && pic[i][j] == 1) {
        cnt++;
        int area = dfs(i, j);
        if (area > maxArea) {
          maxArea = area;
        }
      }
    }
  }
  
  printf("%d\n%d", cnt, maxArea);
  return 0;
}

/*
  문제자체가 가장 큰 그림 전체 넓이를 출력하는 문제기 때문에
  bfs(큐) 사용보다는 재귀dfs 사용 max len도 500이라서 괜찮을듯
*/
