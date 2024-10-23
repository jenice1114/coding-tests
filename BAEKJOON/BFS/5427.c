// https://www.acmicpc.net/problem/5427
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

typedef struct Que {
  int x;
  int y;
} Que;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int W,H;
char grid[MAX_LEN][MAX_LEN];

int visit[MAX_LEN][MAX_LEN];
Que q[MAX_LEN * MAX_LEN];
int front = 0;
int rear = 0;

int visit_fire[MAX_LEN][MAX_LEN];
Que qf[MAX_LEN * MAX_LEN];
int front_f = 0;
int rear_f = 0;

void enqueue(int x, int y, int isFire) {
  if (isFire) {
    qf[rear_f].x = x;
    qf[rear_f].y = y;
    rear_f++;
  } else {
    q[rear].x = x;
    q[rear].y = y;
    rear++;
  }
}

Que dequeue(int isFire) {
  if (isFire) {
    return qf[front_f++];
  } else {
    return q[front++];
  }
}

void bfs_fire() {
  while (front_f < rear_f) {
    Que q = dequeue(1);

    for (int i=0; i<4; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];

      if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
        if (visit_fire[nx][ny] == 0 && grid[nx][ny] == '.') {
          visit_fire[nx][ny] = visit_fire[q.x][q.y] +1;
          enqueue(nx, ny, 1);
        }
      }
    }
  }
}

int bfs() {
  int distance = 0;
  
  while (front < rear) {
    Que q = dequeue(0);

    for (int i=0; i<4; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];
      
      if (nx < 0 || nx >= H || ny < 0 || ny >= W) return visit[q.x][q.y];

      if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
        if (visit[nx][ny] == 0 && grid[nx][ny] == '.') {
          if (visit_fire[nx][ny] == 0 || visit_fire[nx][ny] > visit[q.x][q.y]+1) {
            visit[nx][ny] = visit[q.x][q.y] + 1;
            enqueue(nx, ny, 0);
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  
  while (tc--) {
    scanf("%d %d", &W, &H);
    
    memset(grid, 0, sizeof(grid));
    memset(visit_fire, 0, sizeof(visit_fire));
    memset(visit, 0, sizeof(visit));
    front = 0;
    rear = 0;
    front_f = 0;
    rear_f = 0;
    
    for (int i=0; i<H; i++) {
      scanf("%s", grid[i]);
    }
    
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        if (grid[i][j] == '@') {
          enqueue(i,j,0);
          visit[i][j] = 1;
        } else if (grid[i][j] == '*') {
          enqueue(i,j,1);
          visit_fire[i][j] = 1;
        }
      }
    }
    
    bfs_fire();
    int result = bfs();
    if (result == -1) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("%d\n", result);
    }
  }
  
  return 0;
}
