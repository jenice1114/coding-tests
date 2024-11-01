// https://www.acmicpc.net/problem/10942
// C11

#include <stdio.h>

#define MAX 2000

int main() {
  int n;
  scanf("%d", &n);
  
  int arr[n];
  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  int dp[MAX][MAX] = {0,};
  for (int i=0; i<n; i++) {
    dp[i][i] = 1;
    if (i<n-1 && arr[i] == arr[i+1]) {
      dp[i][i+1] = 1;
    }
  }
  
  for (int i=3; i<=n; i++) {
    for (int j=0; j<=n-i; j++) {
      int k = j+i-1;
      if (arr[j] == arr[k] && dp[j+1][k-1] == 1) {
        dp[j][k] =1;
      }
    }
  }
  
  int m;
  scanf("%d", &m);
  for (int i=0; i<m; i++) {
    int x,y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    
    printf("%d\n", dp[x][y]);
  }
  
  return 0;
}
