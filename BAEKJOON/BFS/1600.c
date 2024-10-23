// https://www.acmicpc.net/problem/1600
// C11

#include <stdio.h>

#define MAX_LEN 201
#define K_MAX_LEN 31

typedef struct Que {
  int x;
  int y;
  int distance;
  int horse;
} Que;

int dx_h[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy_h[8] = {1, 2, -1, -2, 1, 2, -1, -2};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int K;
int W,H;
int map[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN][K_MAX_LEN];

Que queue[MAX_LEN * MAX_LEN * K_MAX_LEN];
int front = 0;
int rear = 0;

void enqueue(int x, int y, int distance, int horse) {
  queue[rear].x = x;
  queue[rear].y = y;
  queue[rear].distance = distance;
  queue[rear].horse = horse;
  rear++;
}

Que dequeue() {
  return queue[front++];
}

int bfs() {
  while (front < rear) {
    Que q = dequeue();
    
    if (q.x == H-1 && q.y == W-1) return q.distance;
    
    for (int i=0; i<4; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];

      if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
        if (visit[nx][ny][q.horse] == 0 && map[nx][ny] == 0) {
          visit[nx][ny][q.horse] = 1;
          enqueue(nx, ny, q.distance+1, q.horse);
        }
      }
    }
    
    if (q.horse > 0) {
      for (int i=0; i<8; i++) {
        int nx = q.x + dx_h[i];
        int ny = q.y + dy_h[i];
        
        if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
          if (visit[nx][ny][q.horse-1] == 0 && map[nx][ny] == 0) {
            visit[nx][ny][q.horse-1] = 1;
            enqueue(nx, ny, q.distance+1, q.horse-1);
          }
        }
      }
    }
  }
  
  return -1;
}

int main() {
  scanf("%d", &K);
  scanf("%d %d", &W, &H);
  
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  enqueue(0,0,0,K);
  visit[0][0][K] = 1;
  printf("%d", bfs());
  
  return 0;
}

/*
  아직도 조건 빼드는게 힘들다 (ㅠㅠ) .,...
*/
