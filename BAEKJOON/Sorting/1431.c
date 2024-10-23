// https://www.acmicpc.net/problem/1431
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Guitar {
  int len;
  int num;
  char serial[51];
} Guitar;

int compare (const void* a, const void* b) {
  Guitar* A = (Guitar*)a;
  Guitar* B = (Guitar*)b;
  
  if (A->len != B->len) {
    return A->len - B->len;
  }
  
  if (A->num != B->num) {
    return A->num - B->num;
  }
  
  return strcmp(A->serial, B->serial);
}

int main() {
  int N;
  scanf("%d", &N);
  
  Guitar* guitar = (Guitar*)malloc(N * sizeof(Guitar));
  for (int i=0; i<N; i++) {
    scanf("%s", guitar[i].serial);
    guitar[i].len = strlen(guitar[i].serial);
    guitar[i].num = 0;
    for (int j=0; j<guitar[i].len; j++) {
      if (guitar[i].serial[j] >= '0' && guitar[i].serial[j] <= '9') {
        guitar[i].num += guitar[i].serial[j] - '0';
      }
    }
  }
  
  qsort(guitar, N, sizeof(Guitar), compare);
  
  for (int i=0; i<N; i++) {
    printf("%s\n", guitar[i].serial);
  }
  free(guitar);
  
  return 0;
}
