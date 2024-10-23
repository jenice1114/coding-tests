// https://www.acmicpc.net/problem/2206
// C11

#include <stdio.h>

#define MAX_LEN 1001

typedef struct Que {
  int x;
  int y;
  int broken;
} Que;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N,M;
char map[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN][2];

Que queue[MAX_LEN * MAX_LEN * 2];
int front = 0;
int rear = 0;

void enqueue(int x, int y, int broken) {
  queue[rear].x = x;
  queue[rear].y = y;
  queue[rear].broken = broken;
  rear++;
}

Que dequeue() {
  return queue[front++];
}

int bfs() {
  while (front < rear) {
    Que q = dequeue();
    
    if (q.x == N-1 && q.y == M-1) return visit[q.x][q.y][q.broken];
    
    for (int i=0; i<4; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];
      
      if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
        if (map[nx][ny] == '0' && visit[nx][ny][q.broken] == 0) {
          visit[nx][ny][q.broken] = visit[q.x][q.y][q.broken] + 1;
          enqueue(nx, ny, q.broken);
        }
        
        if (map[nx][ny] == '1' && q.broken == 0 && visit[nx][ny][1] == 0) {
          visit[nx][ny][1] = visit[q.x][q.y][q.broken] + 1;
          enqueue(nx, ny, 1);
        }
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i=0; i<N; i++) {
    scanf("%s", map[i]);
  }
  
  enqueue(0,0,0);
  visit[0][0][0] = 1;
  
  int result = bfs();
  printf("%d", result);
  
  return 0;
}
