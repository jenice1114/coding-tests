// https://www.acmicpc.net/problem/1074
// C11

#include <stdio.h>

int func(int N, int r, int c) {
  if (N == 0) return 0;
  
  int half = 1 << (N-1);
  int size = half * half;
  
  // 좌상단 구역
  if (r<half && c<half) {
    return func(N-1, r, c);
  } else if (r<half && c>=half) {
    // 우상단 구역
    return size + func(N-1, r, c-half);
  } else if (r >= half && c < half) {
    // 좌하단 구역
    return 2 * size + func(N-1, r-half, c);
  } else {
    // 우하단 구역
    return 3 * size + func(N-1, r-half, c-half);
  }
}

int main() {
  int N,r,c;
  scanf("%d %d %d", &N, &r, &c);
  printf("%d", func(N, r, c));
  return 0;
}

/*
  좌상단: r < half && c < half
  우상단: r < half && c >= half
  좌하단: r >= half && c < half
  우하단: r >= half && c >= half
  좌상단: (0, 0) ~ (3, 3)
  우상단: (0, 4) ~ (3, 7)
  좌하단: (4, 0) ~ (7, 3)
  우하단: (4, 4) ~ (7, 7)

  N = 3일 때, r=3 (행), c=1 (열)
  half = 4, (3,1)은 x,y 둘다 half보다 작기 때문에 좌상단 위치
*/
