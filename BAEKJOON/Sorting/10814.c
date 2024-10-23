// https://www.acmicpc.net/problem/10814
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member {
  int age;
  char name[101];
  int idx;
} Member;

int compare(const void* a, const void* b) {
  Member* A = (Member*)a;
  Member* B = (Member*)b;
  
  if (A->age == B->age) {
    return A->idx - B->idx;
  }
  return A->age - B->age;
}

int main() {
  int N;
  scanf("%d", &N);

  Member* members = (Member*)malloc(N * sizeof(Member));
  for (int i=0; i<N; i++) {
    scanf("%d %s", &members[i].age, &members[i].name);
    members[i].idx = i;
  }
  
  qsort(members, N, sizeof(Member), compare);
  
  for (int i=0; i<N; i++) {
    printf("%d %s\n", members[i].age, members[i].name);
  }
  
  free(members);
  
  return 0;
}
