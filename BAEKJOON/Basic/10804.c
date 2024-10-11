// https://www.acmicpc.net/problem/10804
// C99

#include <stdio.h>

int main() {
  int card[21];
  for (int i=1; i<21; i++) {
    card[i] = i;
  }
  
  for (int i=0; i<10; i++) {
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    
    while (a < b) {
      int temp = card[a];
      card[a] = card[b];
      card[b] = temp;
      a++;
      b--;
    }
  }
  
  for (int i=1; i<21; i++) {
    printf("%d ", card[i]);
  }
  
  return 0;
}
