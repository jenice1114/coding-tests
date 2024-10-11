// https://www.acmicpc.net/problem/10807
// C99

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  int arr[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }
  
  int v;
  scanf("%d", &v);
  
  int result = 0;
  for (int i=0; i<N; i++) {
    if (arr[i] == v) {
      result++;
    }
  }
  
  printf("%d", result);
  
  return 0;
}
