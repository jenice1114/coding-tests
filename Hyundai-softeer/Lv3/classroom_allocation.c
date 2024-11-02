// https://softeer.ai/practice/6291
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct Time {
  long long start;
  long long end;
} Time;

int compare(const void* a, const void* b) {
  Time* A = (Time*)a;
  Time* B = (Time*)b;

  if (A->end == B->end) {
    return A->start - B->start;
  }
  return A->end - B->end;
}

int main() {
  int n;
  scanf("%d", &n);

  Time class[MAX];
  for(int i=0; i<n; i++) {
    scanf("%lld %lld", &class[i].start, &class[i].end);
  }
  qsort(class, n, sizeof(Time), compare);

  long long cnt = 0;
  long long comp = 0;
  for (int i=0; i<n; i++) {
    if (class[i].start >= comp) {
      cnt++;
      comp = class[i].end;
    }
  }
  printf("%lld", cnt);

  return 0;
}
