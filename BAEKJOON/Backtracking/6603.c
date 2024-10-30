// https://www.acmicpc.net/problem/6603
// C11

#include <stdio.h>

#define MAX 13

int k;
int arr[MAX];
int num[MAX];

void func(int cnt, int cur) {
  if (cnt == 6) {
    for (int i=0; i<6; i++) {
      printf("%d ", num[i]);
    }
    printf("\n");
    return;
  }
  
  for (int i=cur; i<k; i++) {
    num[cnt] = arr[i];
    func(cnt+1, i+1);
  }
}

int main() {
  while (1) {
    scanf("%d", &k);
    if (k == 0) break;
    
    for (int i=0; i<k; i++) {
      scanf("%d", &arr[i]);
    }
    
    func(0, 0);
    printf("\n");
  }
  
  return 0;
}
