// https://www.acmicpc.net/problem/1012
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 51

int dx[4] = {1, -1, 0 , 0};
int dy[4] = {0, 0, -1, 1};

int M, N, K;
int cabbage[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];

int dfs(int x, int y) {
  visit[x][y] = 1;
  
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
      if (cabbage[nx][ny] == 1 && visit[nx][ny] == 0) {
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  
  while (tc--) {
    scanf("%d %d %d", &M, &N, &K);
    
    memset(cabbage, 0, sizeof(cabbage));
    memset(visit, 0, sizeof(visit));
    
    for (int i=0; i<K; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      cabbage[y][x] = 1;
    }
    
    int earthworm = 0;
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        if (cabbage[i][j] == 1 && visit[i][j] == 0) {
          dfs(i, j);
          earthworm++;
        }
      }
    }
    
    printf("%d\n", earthworm);
  }
  
  return 0;
}

// =========================================================== //

// 스택 구조로 풀기

#include <stdio.h>
#include <string.h>

#define MAX_LEN 51

typedef struct Stack {
  int x;
  int y;
} Stack;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, K;
int map[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];

Stack st[MAX_LEN * MAX_LEN];
int top = -1;

void push(int x, int y) {
  top++;
  st[top].x = x;
  st[top].y = y;
}

Stack pop() {
  return st[top--];
}

int isEmpty() {
  return top == -1;
}

void dfs(int x, int y) {
  push(x,y);
  visit[x][y] = 1;
  
  while (!isEmpty()) {
    Stack st = pop();
    
    for (int i=0; i<4; i++) {
      int nx = st.x + dx[i];
      int ny = st.y + dy[i];
      
      if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
        if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
          // 순서에 유의하자 push->visit
          push(nx, ny);
          visit[nx][ny] = 1;
        }
      }
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    memset(map, 0, sizeof(map));
    memset(visit, 0, sizeof(visit));
    top = -1;
    
    // 가로M(y), 세로N(x), 위치 개수 K
    scanf("%d %d %d", &M, &N, &K);
    for (int i=0; i<K; i++) {
      int x,y;
      scanf("%d %d", &x, &y);
      map[y][x] = 1;
    }
    
    int earthworm = 0;
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        if (map[i][j] == 1 && visit[i][j] == 0) {
          dfs(i,j);
          earthworm++;
        }
      }
    }
    printf("%d\n", earthworm);
  }
  
  return 0;
}
