// https://softeer.ai/practice/6282
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int N;
int map[MAX][MAX];
int visited[MAX][MAX];

// 상하좌우 이동을 위한 배열
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 각 블록의 크기를 저장하는 배열
int block_size[MAX * MAX];
int block_count = 0;

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);  // 오름차순 정렬
}

// DFS 함수 정의
int dfs(int x, int y) {
  visited[x][y] = 1;  // 방문 처리
  int size = 1;  // 블록의 크기 (자기 자신 포함)

  // 상하좌우로 연결된 곳 탐색
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    // 범위를 벗어나지 않고, 방문하지 않았으며, 장애물(1)이 있는 곳만 탐색
    if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
      if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
        size += dfs(nx, ny);  // 재귀적으로 연결된 곳 탐색
      }
    }
  }

  return size;
}

int main() {
  // 입력 받기
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &map[i][j]);  // 한 글자씩 입력받음
    }
  }

  // 지도 탐색
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j] == 1 && visited[i][j] == 0) {  // 방문하지 않은 장애물이 있으면
        block_size[block_count] = dfs(i, j);  // 블록의 크기 계산
        block_count++;  // 블록 수 증가
      }
    }
  }

  // 결과 출력
  printf("%d\n", block_count);  // 총 블록 수 출력

  // 각 블록의 크기를 오름차순으로 정렬
  qsort(block_size, block_count, sizeof(int), compare);

  // 각 블록의 크기를 출력
  for (int i = 0; i < block_count; i++) {
    printf("%d\n", block_size[i]);
  }

  return 0;
}