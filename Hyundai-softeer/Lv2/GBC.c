// https://softeer.ai/practice/6270
// C11

#include <stdio.h>

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);

  // 제한 속도 구간과 속도 저장
  int limit[N][2];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &limit[i][0], &limit[i][1]);
  }

  // 테스트 구간과 속도 저장
  int test[M][2];
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &test[i][0], &test[i][1]);
  }

  int max_exceed = 0;  // 제한 속도 초과 값
  int limit_idx = 0, test_idx = 0;  // 각 구간의 인덱스
  int limit_pos = 0, test_pos = 0;  // 남은 길이 계산을 위한 포지션

  while (limit_idx < N && test_idx < M) {
    // 현재 구간의 제한 속도와 테스트 속도
    int limit_speed = limit[limit_idx][1];
    int test_speed = test[test_idx][1];
    
    // 속도 초과 계산
    int exceed = test_speed - limit_speed;
    if (max_exceed < exceed) {
      // 최대 초과 속도 갱신
      max_exceed = exceed;
    }

    // 겹치는 구간 계산 (현재 남은 길이 중 더 작은 값)
    int limit_length = limit[limit_idx][0] - limit_pos;
    int test_length = test[test_idx][0] - test_pos;
    int min_length = (limit_length < test_length)
                      ? limit_length
                      : test_length;

    // 현재 구간 소모
    limit_pos += min_length;
    test_pos += min_length;

    // 제한 속도 구간이 끝나면 다음 구간으로 이동
    if (limit_pos == limit[limit_idx][0]) {
      limit_idx++;
      limit_pos = 0;
    }

    // 테스트 구간이 끝나면 다음 구간으로 이동
    if (test_pos == test[test_idx][0]) {
      test_idx++;
      test_pos = 0;
    }
  }

  // 최대 속도 초과 출력
  printf("%d", max_exceed);

  return 0;
}
