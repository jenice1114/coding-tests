// https://www.acmicpc.net/problem/15312
// C11

#include <stdio.h>
#include <string.h>

int alphabet[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
  char jongmin[2001];
  char her[2001];
  
  scanf("%s", jongmin);
  scanf("%s", her);
  
  int len = strlen(her);
  int love_percent[4002];
  int cnt = 0;
  for (int i=0; i<len; i++) {
    love_percent[cnt++] = alphabet[jongmin[i] - 'A'];
    love_percent[cnt++] = alphabet[her[i] - 'A'];
  }
  
  while (cnt > 2) {
    for (int i=0; i<cnt-1; i++) {
      love_percent[i] = (love_percent[i] + love_percent[i+1]) % 10;
    }
    cnt--;
  }
  
  printf("%d%d", love_percent[0], love_percent[1]);
  
  return 0;
}

/*
  0,1 1,2 2,3 ... 이런식으로 더해야가 되기 때문에 길이가 2가 될때까지 값 갱신
  둘의 길이가 같음이 보장되므로 가능함
 */
