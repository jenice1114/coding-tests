// https://www.acmicpc.net/problem/7569
// C11

#include <stdio.h>

#define MAX 101

typedef struct Que {
  int x;
  int y;
  int z;
} Q;

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int m,n,h;
int map[MAX][MAX][MAX];
int visit[MAX][MAX][MAX];

Q que[MAX*MAX*MAX];
int front;
int rear;

void enqueue(int x, int y, int z) {
  que[rear].x = x;
  que[rear].y = y;
  que[rear].z = z;
  rear++;
}

Q dequeue() {
  return que[front++];
}

void bfs() {
  while (front < rear) {
    Q cur = dequeue();
    
    for (int i=0; i<6; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      int nz = cur.z + dz[i];
      
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h &&
          map[nx][ny][nz] == 0 && visit[nx][ny][nz] == 0) {
        visit[nx][ny][nz] = visit[cur.x][cur.y][cur.z] + 1;
        enqueue(nx, ny, nz);
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &m, &n, &h);
  
  int flag = 0;
  for (int i=0; i<h; i++) {
    for (int j=0; j<n; j++) {
      for (int k=0; k<m; k++) {
        scanf("%d", &map[j][k][i]);
        
        if (map[j][k][i] == -1) {
          visit[j][k][i] = -1;
        } else if (map[j][k][i] == 1) {
          visit[j][k][i] = 1;
          enqueue(j,k,i);
        }
        
        if (map[j][k][i] == 0) {
          flag = 1;
        }
      }
    }
  }
  if (flag == 0) {
    printf("0");
    return 0;
  }
  
  bfs();
  
  int min = 0;
  for (int i=0; i<h; i++) {
    for (int j=0; j<n; j++) {
      for (int k=0; k<m; k++) {
        if (visit[j][k][i] == 0) {
          printf("-1");
          return 0;
        }
        
        if (visit[j][k][i] > min) {
          min = visit[j][k][i];
        }
      }
    }
  }
  
  printf("%d", min - 1);
  
  return 0;
}
