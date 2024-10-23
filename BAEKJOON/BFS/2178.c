// https://www.acmicpc.net/problem/2178
// C11

#include <stdio.h>

#define MAX_LEN 101

typedef struct Queue {
  int x;
  int y;
  int distance;
} Que;

int n,m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visit[MAX_LEN][MAX_LEN];
char miro[MAX_LEN][MAX_LEN];

Que queue[MAX_LEN * MAX_LEN];
int front = 0;
int rear = 0;

void enqueue(int x, int y, int distance) {
  queue[rear].x = x;
  queue[rear].y = y;
  queue[rear].distance = distance;
  rear++;
}

Que dequeue() {
  return queue[front++];
}

int bfs(int x, int y) {
  visit[x][y] = 1;
  enqueue(x, y, 1);
  
  while (front < rear) {
    Que q = dequeue();
    
    // (1, 1)에서 출발하여 (N, M)의 위치
    if (q.x == n-1 && q.y == m-1) return q.distance;
    
    for (int i=0; i<4; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];
      
      if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
          miro[nx][ny] == '1' && visit[nx][ny] == 0) {
        visit[nx][ny] = 1;
        enqueue(nx, ny, q.distance+1);
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i=0; i<n; i++) {
    scanf("%s", miro[i]);
  }
  
  printf("%d", bfs(0,0));
  
  return 0;
}
