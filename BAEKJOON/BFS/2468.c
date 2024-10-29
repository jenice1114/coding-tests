// https://www.acmicpc.net/problem/2468
// C11

#include <stdio.h>

#define MAX 100

typedef struct Que {
  int x;
  int y;
} Q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N;
int map[MAX][MAX];
int visit[MAX][MAX];

Q que[MAX*MAX];
int front;
int rear;

void enqueue(int x, int y) {
  que[rear].x = x;
  que[rear].y = y;
  rear++;
}

Q dequeue() {
  return que[front++];
}

void bfs(int x, int y, int high) {
  front = 0;
  rear = 0;
  enqueue(x, y);
  visit[x][y] = 1;

  while (front < rear) {
    Q cur = dequeue();
    
    for (int i=0; i<4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
          map[nx][ny] > high && visit[nx][ny] == 0) {
        visit[nx][ny] = 1;
        enqueue(nx, ny);
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  
  int max = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] > max) {
        max = map[i][j];
      }
    }
  }
  
  int max_area = 1;
  for (int high=1; high<=max; high++) {
    int area = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        visit[i][j] = 0;
      }
    }
    
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (map[i][j] > high && visit[i][j] == 0) {
          bfs(i, j, high);
          area++;
        }
      }
    }
    
    if (area > max_area) {
      max_area = area;
    }
  }
  
  printf("%d", max_area);
  
  return 0;
}
