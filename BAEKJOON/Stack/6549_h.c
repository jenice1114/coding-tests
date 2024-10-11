// https://www.acmicpc.net/problem/6549
// C11

#include <stdio.h>

int main() {
  while(1) {
    int n;
    scanf("%d", &n);
    
    if (n == 0) break;
    
    int heights[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &heights[i]);
    }
    
    int stack[n];
    int top = 0;
    long long max_area = 0;
    for (int i=0; i<n; i++) {
      while (top > 0 && heights[i] <= heights[stack[top-1]]) {
        int height = heights[stack[--top]];
        int width = (top == 0) ? i : (i - stack[top-1] - 1);
        long long area = (long long)height * width;
        if (area > max_area) {
          max_area = area;
        }
      }
      stack[top++] = i;
    }
    
    while (top > 0) {
      int height = heights[stack[--top]];
      int width = (top == 0) ? n : (n - stack[top-1] - 1);
      long long area = (long long)height * width;
      if (area > max_area) {
        max_area = area;
      }
    }

    printf("%lld\n", max_area);
  }
  return 0;
}

/*
  이건 레알이다.. 그냥 chatgpt한테 물어봤다... 못품
*/
