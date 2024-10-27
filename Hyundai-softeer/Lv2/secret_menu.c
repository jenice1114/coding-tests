// https://softeer.ai/practice/6269
// C11

#include <stdio.h>

int main(void) {
  int M, N, K;
  scanf("%d %d %d", &M, &N, &K);

  int secret[M];
  for (int i = 0; i < M; i++) {
    scanf("%d", &secret[i]);
  }

  int userNum[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &userNum[i]);
  }

  int found = 0;
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++) {
      if (userNum[i + j] != secret[j]) {
        break;
      }
    }
    if (j == M) {
      found = 1;
      break;
    }
  }

  // 결과 출력
  if (found) {
    printf("secret\n");
  } else {
    printf("normal\n");
  }

  return 0;
}