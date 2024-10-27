// https://softeer.ai/practice/6273
// C11

#include <stdio.h>
#include <limits.h>

int visit[11] = {0};        // 방문 여부를 기록하는 배열
int matrix[11] = {0};       // 현재 순열을 저장하는 배열
int result = INT_MAX;       // 결과값 초기화

// 깊이 우선 탐색(DFS) 함수
void DFS(int count, int N, int M, int K, int rail[]) {
  if (count == N) {
    int idx = 0;
    int bucket = 0;
    int sum = 0;

    // K번의 작업을 수행
    for (int i=0; i<K; i++) {
      while (matrix[idx] + bucket <= M) {
        bucket += matrix[idx];
        idx = (idx + 1) % N;
      }
      sum += bucket;
      bucket = 0;
    }

    // 최소 결과값 갱신
    if (sum < result) {
      result = sum;
    }
    return;
  }

  // 레일 순열을 생성하는 부분
  for (int i=1; i<=N; i++) {
    if (!visit[i]) {
      visit[i] = 1;

      matrix[count] = rail[i];
      DFS(count + 1, N, M, K, rail);
      visit[i] = 0;
    }
  }
}

int main() {
  int N, M, K;
  int rail[11];

  scanf("%d %d %d", &N, &M, &K);
  for (int i=1; i<=N; i++) {
      scanf("%d", &rail[i]);
  }

  // DFS를 호출하여 모든 경우를 탐색
  DFS(0, N, M, K, rail);

  printf("%d\n", result);
  return 0;
}
