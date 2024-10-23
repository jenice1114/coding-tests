// https://www.acmicpc.net/problem/9663
// C11

#include <stdio.h>

#define MAX_LEN 15

int N;
int result;
int col[MAX_LEN];
int visit_left[MAX_LEN * MAX_LEN];
int visit_right[MAX_LEN * MAX_LEN];

void dfs(int row) {
  if (row == N) {
    result++;
    return;
  }
  
  for (int i=0; i<N; i++) {
    if (col[i] == 0 &&
        visit_left[row+i] == 0 &&
        visit_right[row-i+N-1] == 0) {
      col[i] = 1;
      visit_left[row+i] = 1;
      visit_right[row-i+N-1] = 1;

      dfs(row+1);

      col[i] = 0;
      visit_left[row+i] = 0;
      visit_right[row-i+N-1] = 0;
    }
  }
}

int main() {
  scanf("%d", &N);
  dfs(0);
  printf("%d", result);
  return 0;
}
