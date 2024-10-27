// https://softeer.ai/practice/6289
// C11

#include <stdio.h>

#define MAX_LEN 100001

int weight[MAX_LEN];
int great[MAX_LEN];

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  for (int i=1; i<=N; i++) {
    scanf("%d", &weight[i]);
    great[i] = 1;
  }

  for (int i=0; i<M; i++) {
    int x,y;
    scanf("%d %d", &x, &y);

    if (weight[x] > weight[y]) {
      great[y] = 0;
    } else if (weight[y] > weight[x]) {
      great[x] = 0;
    } else {
      great[x] = 0;
      great[y] = 0;
    }
  }

  int result = 0;
  for (int i=1; i<=N; i++) {
    if (great[i] != 0) {
      result++;
    }
  }
  printf("%d", result);
  return 0;
}
