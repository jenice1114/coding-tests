// https://www.acmicpc.net/problem/1700
// C11

#include <stdio.h>

#define MAX 101

int n,k;
int check[MAX];

int main() {
  scanf("%d %d", &n, &k);
  for (int i=0; i<k; i++) {
    scanf("%d", &check[i]);
  }
  
  int multi[n];
  int cnt = 0;
  int result = 0;
  for (int i=0; i<k; i++) {
    int cur = check[i];
    int flag = 0;
    
    for (int j=0; j<cnt; j++) {
      if (multi[j] == cur) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) continue;
    
    if (cnt < n) {
      multi[cnt++] = cur;
      continue;
    }
    
    int last_idx = -1;
    int farthest = -1;
    for (int a=0; a<n; a++) {
      int next_use = 0;
      for (int b=i+1; b<k; b++) {
        if (multi[a] == check[b]) {
          next_use = b;
          break;
        }
      }
      if (next_use == 0) {
        last_idx = a;
        break;
      }
      
      if (next_use > farthest) {
        farthest = next_use;
        last_idx = a;
      }
    }
    
    multi[last_idx] = cur;
    result++;
  }
  
  printf("%d", result);
  
  return 0;
}
