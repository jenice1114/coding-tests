// https://softeer.ai/practice/9495
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 200001

typedef struct popularity {
  int p;
  int c;
} popul;

popul pop[MAX_LEN];
int N;

int main() {
  scanf("%d", &N);

  for (int i=0; i<N; i++) {
    scanf("%d %d", &pop[i].p, &pop[i].c);
  }

  int x = 0;
  for (int i=0; i<N; i++) {
    if(abs(pop[i].p - x) <= pop[i].c) {
      x++;
    }
  }
  printf("%d", x);

  return 0;
}

/*
  dp로 풀라다가 개판난 문제(ㅠㅠ)
  그냥 보이는데로 풀자...
 */
