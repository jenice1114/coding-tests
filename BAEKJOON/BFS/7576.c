// https://www.acmicpc.net/problem/7576
// C11

#include <stdio.h>

#define MAX_LEN 1001

typedef struct Que {
  int x;
  int y;
  int day;
} Que;

int M,N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int tomato[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];

Que q[MAX_LEN * MAX_LEN];
int front = 0;
int rear = 0;

void enqueue(int x, int y, int day) {
  q[rear].x = x;
  q[rear].y = y;
  q[rear].day = day;
  rear++;
}

Que dequeue() {
  return q[front++];
}

int bfs() {
  int maxDay = 0;
  while (front < rear) {
    Que q = dequeue();
    
    for (int i=0; i<4; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];
      
      if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
          tomato[nx][ny] == 0 && visit[nx][ny] == 0) { // -1은 무시
        visit[nx][ny] = 1;
        tomato[nx][ny] = 1;
        enqueue(nx, ny, q.day+1);
        maxDay = q.day+1;
      }
    }
  }
  
  return maxDay;
}

int main() {
  scanf("%d %d", &M, &N);
  
  int target = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf("%d", &tomato[i][j]);
      if (tomato[i][j] == 1) {
        enqueue(i,j,0);
        visit[i][j] = 1;
      } else if (tomato[i][j] == 0) {
        target++;
      }
    }
  }
  
  if (target == 0) {
    printf("0");
    return 0;
  }
  
  int day = bfs();
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (tomato[i][j] == 0) {
          printf("-1");
          return 0;
      }
    }
  }
  printf("%d", day);
  
  return 0;
}

/*
  익은 토마토 중심으로 확인해야 되기 때문에 q에 넣는 애가 익은 토마토 좌표
  또 나와서는 익지 않은게 있는지 확인하기 위해 포문을 한번 더 돌려야함

  아 너무 어려운데... 조건을 유추하기가 쉽지 않다(ㅠㅠ)
*/
