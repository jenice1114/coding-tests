// https://www.acmicpc.net/problem/2667
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX 26

typedef struct Que {
  int x;
  int y;
} Q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N;
char map[MAX][MAX];
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

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int bfs() {
  int area = 1;
  while (front < rear) {
    Q cur = dequeue();
    
    for (int i=0; i<4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
          map[nx][ny] == '1' && visit[nx][ny] == 0) {
        area++;
        enqueue(nx, ny);
        visit[nx][ny] = 1;
      }
    }
  }
  return area;
}

int main() {
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    scanf("%s", map[i]);
  }
  
  int cnt = 0;
  int dist[MAX*MAX] = {0,};
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (map[i][j] == '1' && visit[i][j] == 0) {
        enqueue(i,j);
        visit[i][j] = 1;
        dist[cnt++]= bfs();
      }
    }
  }
  
  printf("%d\n", cnt);
  qsort(dist, cnt, sizeof(int), compare);
  for (int i=0; i<cnt; i++) {
    printf("%d\n", dist[i]);
  }
  
  return 0;
}

/*
  dist도 큐의 크기와 같다는걸 간과했다;
  런타임 에러를 맛보고 맞춘 문제(ㅠㅠ)
*/
