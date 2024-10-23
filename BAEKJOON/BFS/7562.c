// https://www.acmicpc.net/problem/7562
// C11

#include <stdio.h>

#define MAX_LEN 301

typedef struct Que {
  int x;
  int y;
  int distance;
} Que;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int l;
int visit[MAX_LEN][MAX_LEN];

Que q[MAX_LEN * MAX_LEN];
int front = 0;
int rear = 0;

void enqueue(int x, int y, int distance) {
  q[rear].x = x;
  q[rear].y = y;
  q[rear].distance = distance;
  rear++;
}

Que dequeue() {
  return q[front++];
}

int bfs(int x, int y, int targetX, int targetY) {
  while (front < rear) {
    Que q = dequeue();
    
    if (q.x == targetX && q.y == targetY) return q.distance;
    
    for (int i=0; i<8; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];
      
      if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
        if (visit[nx][ny] == 0) {
          visit[nx][ny] = 1;
          enqueue(nx,ny,q.distance+1);
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
    scanf("%d", &l);
    
    memset(visit, 0, sizeof(visit));
    
    int x,y;
    scanf("%d %d", &x, &y);
    enqueue(x, y, 0);
    visit[x][y] = 1;
    
    int a,b;
    scanf("%d %d", &a, &b);
    
    int result = bfs(x,y,a,b);
    printf("%d\n", result);
    
    front = 0;
    rear = 0;
  }
  
  return 0;
}

/*
  DFS, BFS 너무 헷갈리기 시작한다... 으악~!
*/
