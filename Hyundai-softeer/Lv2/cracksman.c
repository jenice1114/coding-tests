// https://softeer.ai/practice/6288
// C11

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int weight;
  int price;
} Metal;

int compare(const void *a, const void *b) {
  return ((Metal*)b)->price - ((Metal*)a)->price;
}

int main() {
  int W, N;
  scanf("%d %d", &W, &N);

  Metal *metals = (Metal*)malloc(N * sizeof(Metal));
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &metals[i].weight, &metals[i].price);
  }

  qsort(metals, N, sizeof(Metal), compare);

  int max = 0;
  for (int i = 0; i < N; i++) {
    if ((W - metals[i].weight) >= 0) {
      max += metals[i].weight * metals[i].price;
    } else {
      max += W * metals[i].price;
      break;
    }

    W -= metals[i].weight;
  }

  printf("%d", max);

  free(metals);
  return 0;
}
