// https://www.acmicpc.net/problem/4179
// C11

#include <stdio.h>

#define MAX_LEN 1001

typedef struct Que {
  int x;
  int y;
  int minute;
} Que;

int R, C;
char miro[MAX_LEN][MAX_LEN];
int fire_visit[MAX_LEN][MAX_LEN];
int jh_visit[MAX_LEN][MAX_LEN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

Que fire_q[MAX_LEN * MAX_LEN];
int fire_front = 0;
int fire_rear = 0;

Que jh_q[MAX_LEN * MAX_LEN];
int jh_front = 0;
int jh_rear = 0;

void enqueue_fire(int x, int y) {
  fire_q[fire_rear].x = x;
  fire_q[fire_rear].y = y;
  fire_rear++;
}

Que dequeue_fire() {
  return fire_q[fire_front++];
}

void enqueue_jh(int x, int y) {
  jh_q[jh_rear].x = x;
  jh_q[jh_rear].y = y;
  jh_rear++;
}

Que dequeue_jh() {
  return jh_q[jh_front++];
}

int bfs_fire() {
  while (fire_front < fire_rear) {
    Que fq = dequeue_fire();
    
    for (int i=0; i<4; i++) {
      int nx = fq.x + dx[i];
      int ny = fq.y + dy[i];
      
      if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
          miro[nx][ny] == '.' && fire_visit[nx][ny] == -1) {
        fire_visit[nx][ny] = fire_visit[fq.x][fq.y] + 1;
        enqueue_fire(nx, ny);
      }
    }
  }
}

int bfs_jh() {
  while (jh_front < jh_rear) {
    Que jq = dequeue_jh();
    
    if (jq.x == 0 || jq.x == R-1 ||
        jq.y == 0 || jq.y == C-1) {
      return jh_visit[jq.x][jq.y] + 1;
    }
    
    for (int i=0; i<4; i++) {
      int nx = jq.x + dx[i];
      int ny = jq.y + dy[i];
      
      if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
          miro[nx][ny] == '.' && jh_visit[nx][ny] == -1) {
        // 불보다 빨리 갈 수 있는지 확인
        if (fire_visit[nx][ny] == -1 ||
            jh_visit[jq.x][jq.y] + 1 < fire_visit[nx][ny]) {
          jh_visit[nx][ny] = jh_visit[jq.x][jq.y] + 1;
          enqueue_jh(nx, ny);
        }
      }
    }
  }
  
  return -1;
}

int main() {
  scanf("%d %d", &R, &C);
  getchar();
  
  memset(fire_visit, -1, sizeof(fire_visit));
  memset(jh_visit, -1, sizeof(jh_visit));
  
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      scanf(" %c", &miro[i][j]);
      if (miro[i][j] == 'F') { // 불 시작점
        enqueue_fire(i,j);
        fire_visit[i][j] = 0;
      } else if (miro[i][j] == 'J') { // 지훈이 시작점
        enqueue_jh(i,j);
        jh_visit[i][j] = 0;
      }
    }
  }
  
  bfs_fire();
  int result = bfs_jh();
  
  if (result == -1) {
    printf("IMPOSSIBLE");
  } else {
    printf("%d", result);
  }
  
  return 0;
}

/*
  비교 해야 될 조건이 2가지 지훈이와 불
  탈출조건은 가장자리이므로, x나 y가 0이거나 전체에서 마지막 행/열 일 때 탈출가능

  불 번짐 먼저 측정하고
  그 뒤에 지훈이가 탈출할 수 있는 지 판단 (불의 좌표에 찍힌 visit값보다 더 작으면 가능)

  getchar() 는 \n 처리 필요할 때 사용하는 함수로 R*C 값을 입력받고
  두번째줄부터 한 문자씩 가져와야하기 때문에 getchar()로 \n처리하고
  이후부터는 scanf(" %c") 처리로 개행문자를 무시한다
*/
