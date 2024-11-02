// https://softeer.ai/practice/6259
// C11

#include <stdio.h>

#define MAX 3001

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n,m,k;
  scanf("%d %d %d", &n, &m, &k);
  
  int arr1[MAX];
  for (int i=0; i<n; i++) {
    scanf("%d", &arr1[i]);
  }

  int arr2[MAX];
  for (int i=0; i<m; i++) {
    scanf("%d", &arr2[i]);
  }

  int dp[MAX][MAX] = {0};
  int res = 0;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (arr1[i-1] == arr2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        res = max(res, dp[i][j]);
      }
    }
  }

  printf("%d", res);
  
  return 0;
}
