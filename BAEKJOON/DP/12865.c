// https://www.acmicpc.net/problem/12865
// C11

#include <stdio.h>

#define MAX 100001

int main() {
  int n,k;
  scanf("%d %d", &n, &k);
  
  int dp[MAX] = {0,};
  for (int i=0; i<n; i++) {
    int w,v;
    scanf("%d %d", &w, &v);
    
    for (int j=k; j>=w; j--) {
      if (dp[j] < dp[j-w]+v) {
        dp[j] = dp[j-w]+v;
      }
    }
  }
  
  printf("%d\n", dp[k]);
  return 0;
}
