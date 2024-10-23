// https://www.acmicpc.net/problem/7569
// C11

#include <stdio.h>

#define MAX_LEN 101

typedef struct Que {
  int x;  // 세로 (행)
  int y;  // 가로 (열)
  int z;  // 높이 (층)
} Que;

int M, N, H;
int tomato[MAX_LEN][MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN][MAX_LEN];

int dx[6] = {1, -1, 0, 0, 0, 0};  // 세로 방향 이동
int dy[6] = {0, 0, -1, 1, 0, 0};  // 가로 방향 이동
int dz[6] = {0, 0, 0, 0, 1, -1};  // 높이 방향 이동

Que q[MAX_LEN * MAX_LEN * MAX_LEN];
int front = 0;
int rear = 0;

void enqueue(int x, int y, int z) {
  q[rear].x = x;
  q[rear].y = y;
  q[rear].z = z;
  rear++;
}

Que dequeue() {
  return q[front++];
}

int bfs() {
  int day = 0;
  
  while (front < rear) {
    Que cur = dequeue();
    
    for (int i = 0; i < 6; i++) {
      int nx = cur.x + dx[i];  // 세로 (행)
      int ny = cur.y + dy[i];  // 가로 (열)
      int nz = cur.z + dz[i];  // 높이 (층)
      
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H) {
        if (tomato[nz][nx][ny] == 0) {  // 익지 않은 토마토일 경우
          visit[nz][nx][ny] = visit[cur.z][cur.x][cur.y] + 1;  // 날짜 갱신
          tomato[nz][nx][ny] = 1;  // 토마토를 익힘
          enqueue(nx, ny, nz);  // 새로 익은 토마토 좌표를 큐에 추가
          
          if (visit[nz][nx][ny] > day) {
            day = visit[nz][nx][ny];  // 가장 최근에 익은 날을 기록
          }
        }
      }
    }
  }
  return day - 1;  // 첫날이 1부터 시작하므로 1일 빼줌
}

int main() {
  scanf("%d %d %d", &M, &N, &H);
  
  int unripe_tomato_count = 0;
  for (int i = 0; i < H; i++) {  // 높이 (층)
    for (int j = 0; j < N; j++) {  // 세로 (행)
      for (int k = 0; k < M; k++) {  // 가로 (열)
          scanf("%d", &tomato[i][j][k]);
          if (tomato[i][j][k] == 1) {
            enqueue(j, k, i);  // 큐에 넣을 때 세로, 가로, 높이 순서로 저장
            visit[i][j][k] = 1;  // 첫날을 1로 설정
          } else if (tomato[i][j][k] == 0) {
            unripe_tomato_count++;  // 익지 않은 토마토 개수 카운팅
          }
      }
    }
  }
  
  // 모든 토마토가 이미 익은 상태
  if (unripe_tomato_count == 0) {
    printf("0\n");
    return 0;
  }
  
  int day = bfs();  // BFS 실행
  
  // BFS 후에도 익지 않은 토마토가 남아있으면 -1 출력
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (tomato[i][j][k] == 0) {  // 익지 않은 토마토가 있으면 -1 출력
          printf("-1\n");
          return 0;
        }
      }
    }
  }

  printf("%d\n", day);  // 모든 토마토가 익는 데 걸린 최단 일수 출력
  return 0;
}

/*
  간단하면서도 안간단한.... 3차원이라 헷갈려서 머리빠지는 것 같다
*/
