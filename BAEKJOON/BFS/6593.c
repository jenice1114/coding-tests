// https://www.acmicpc.net/problem/6593
// C11

#include <stdio.h>

#define MAX 31

typedef struct Que {
  int x;
  int y;
  int z;
} Q;

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int L,R,C;
char map[MAX][MAX][MAX];
int visit[MAX][MAX][MAX];

Q que[MAX*MAX*MAX];
int front;
int rear;

void enqueue(int z, int x, int y) {
  que[rear].z = z;
  que[rear].x = x;
  que[rear].y = y;
  rear++;
}

Q dequeue() {
  return que[front++];
}

int bfs() {
  while (front < rear) {
    Q cur = dequeue();
    
    if (map[cur.z][cur.x][cur.y] == 'E') {
      return visit[cur.z][cur.x][cur.y] - 1;
    }
    
    for (int i=0; i<6; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      int nz = cur.z + dz[i];
      if (nx >= 0 && nx < R && ny >= 0 && ny < C && nz >= 0 && nz < L &&
          (map[nz][nx][ny] == '.' || map[nz][nx][ny] == 'E') && visit[nz][nx][ny] == 0) {
        visit[nz][nx][ny] = visit[cur.z][cur.x][cur.y] + 1;
        enqueue(nz, nx, ny);
      }
    }
  }
  return -1;
}

int main() {
  while (1) {
    scanf("%d %d %d", &L, &R, &C);
    if (L == 0 && R == 0 && C == 0) break;
    
    front = 0;
    rear = 0;
    for (int i=0; i<L; i++) {
      for (int j=0; j<R; j++) {
        for (int k=0; k<C; k++) {
          visit[i][j][k] = 0;
        }
      }
    }
    
    for (int i=0; i<L; i++) {
      for (int j=0; j<R; j++) {
        for (int k=0; k<C; k++) {
          scanf(" %c", &map[i][j][k]);
          if (map[i][j][k] == 'S') {
            enqueue(i, j, k);
            visit[i][j][k] = 1;
          }
        }
      }
    }
    
    int cnt = bfs();
    if (cnt == -1) {
      printf("Trapped!\n");
    } else {
      printf("Escaped in %d minute(s).\n", cnt);
    }
  }
  return 0;
}
