// https://www.acmicpc.net/problem/15552
// C99

#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  
  int a,b;
  for (int i=0; i<T; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
  }

  return 0;
}

/*
  이 문제 이해하기 힘들었는데...
  그냥 일단 기본으로 풀었는데 풀림 (??)
  C는 scanf로도 충분히 빠른듯 싶다
  다른 언어는 어떻게 푸는지 모르겠다
*/
