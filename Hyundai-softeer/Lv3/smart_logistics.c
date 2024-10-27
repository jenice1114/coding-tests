// https://softeer.ai/practice/6279
// C11

#include <stdio.h>

#define MAX_LEN 20001

int N,K;
char map[MAX_LEN];
int visit[MAX_LEN];
int result = 0;

int main() {
  scanf("%d %d", &N, &K);
  scanf("%s", map);

  for (int i=0; i<N; i++) {
    if (map[i] == 'P') {
      for (int j = i-K; j<=i+K; j++) {
        if (j>=0 && j<N && map[j] == 'H' && visit[j] == 0) {
          visit[j] = 1;
          result++;
          break;
        }
      }
    }
  }
  printf("%d", result);

  return 0;
}
