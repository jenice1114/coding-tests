#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 101 // 최대맵 2배(50 * 2 + 1)
#define MAX_QUEUE_SIZE 10000 // Queue 사이즈 정의

// 동 서 남 북
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

// 좌표를 담을 구조체 정의
typedef struct {
  int y, x;
} Point;

// 큐 구조체
typedef struct {
  Point data[MAX_QUEUE_SIZE];
  int front, rear;
} Queue;

// 큐 초기화 함수
void init_queue(Queue* q) {
  q->front = 0;
  q->rear = 0;
}

// 큐가 비었는지 확인하는 함수
int is_empty(Queue* q) {
  return q->front == q->rear;
}

// 큐에 요소를 추가하는 함수
void enqueue(Queue* q, int y, int x) {
  q->data[q->rear].y = y;
  q->data[q->rear].x = x;
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

// 큐에서 요소를 꺼내는 함수
Point dequeue(Queue* q) {
  Point p = q->data[q->front];
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return p;
}

int solution(int **rectangle, size_t rectangle_row_len, size_t rectangle_col_len, int characterX, int characterY, int itemX, int itemY) {
  int answer = 0;

  // 1. 캐릭터 좌표, 아이템 좌표 모두 2배로 늘린다.
  characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;

  // board: 직사각형을 표현할 배열이다.
  int** board = (int**)malloc(MAX * sizeof(int*)); // 2차원배열 동적할당
  for (int i = 0; i < MAX; i++) {
    board[i] = (int*)malloc(MAX * sizeof(int));
  }
    
  // 직사각형의 시작점과 끝점
  int x1, y1, x2, y2;
    
  // 2. 직사각형을 board 배열에 모두 입력해준다. 전체구간 = 1
  for (int i = 0; i < rectangle_row_len; i++) {
    for (int j = 0; j < 4; j++) {
      rectangle[i][j] = rectangle[i][j] * 2;
    }

    // 2-2. 0,1 좌측하단 2,3 우측상단 좌표 업데이트
    x1 = rectangle[i][0], y1 = rectangle[i][1];
    x2 = rectangle[i][2], y2 = rectangle[i][3];

    for (int y = y1; y <= y2; y++) {
      for (int x = x1; x <= x2; x++) {
        board[y][x] = 1;
      }
    }
  }

  // 3. 직사각형의 내부는 모두 0으로 채워준다. (테두리는 1로 유지)
  for (int i = 0; i < rectangle_row_len; i++) {
    x1 = rectangle[i][0], y1 = rectangle[i][1];
    x2 = rectangle[i][2], y2 = rectangle[i][3];

    for (int y = y1 + 1; y < y2; y++) {
      for (int x = x1 + 1; x < x2; x++) {
        board[y][x] = 0;
      }
    }
  }

  // 4. Queue init.
  Queue q;
  init_queue(&q);
  
  // 캐릭터의 시작 좌표를 큐에 넣기
  enqueue(&q, characterY, characterX);

  // 5. BFS 시작
  while (!is_empty(&q)) {
    Point current = dequeue(&q);
    int y = current.y;
    int x = current.x;

    if (y == itemY && x == itemX) {
      break; // 아이템 위치에 도달하면 탐색 종료
    }

    // 동서남북 네 방향으로 탐색
    for (int i = 0; i < 4; i++) {
      int nextY = y + dy[i];
      int nextX = x + dx[i];

      // 인덱스 범위 검사 추가
      if (nextY >= 0 && nextY < MAX && nextX >= 0 && nextX < MAX && board[nextY][nextX] == 1) {
        enqueue(&q, nextY, nextX);
        board[nextY][nextX] = board[y][x] + 1;  // 방문 표시 및 거리 저장
      }
    }
  }

  // 6. 최종 결과 계산
  answer = board[itemY][itemX] / 2;

  // 7. 동적 배열 해제
  for (int i = 0; i < MAX; i++) {
    free(board[i]);
  }
  free(board);

  return answer;
}
