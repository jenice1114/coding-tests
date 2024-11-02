// https://www.acmicpc.net/problem/9251
// C11

#include <stdio.h>
#include <string.h>

#define MAX 1001

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  char str1[MAX];
  char str2[MAX];
  int dp[MAX][MAX];
  
  scanf("%s", str1);
  scanf("%s", str2);
  
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  
  for (int i=1; i<=len1; i++) {
    for (int j=1; j<=len2; j++) {
      if (str1[i-1] == str2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  printf("%d", dp[len1][len2]);
  
  return 0;
}
