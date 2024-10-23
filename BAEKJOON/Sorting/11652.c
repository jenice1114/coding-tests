// https://www.acmicpc.net/problem/11652
// C11

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  long long A = *(long long*)a;
  long long B = *(long long*)b;
  
  if (A > B) return 1;
  else if (A < B) return -1;
  else return 0;
}

int main() {
  int N;
  scanf("%d", &N);
  
  long long* card = (long long*)malloc(N * sizeof(long long));
  for (int i=0; i<N; i++) {
    scanf("%lld", &card[i]);
  }
  qsort(card, N, sizeof(long long), compare);
  
  long long num = card[0];
  int cnt = 1;
  int max = 1;
  for (int i=1; i<N; i++) {
    if (card[i] == card[i-1]) {
      cnt++;
    } else {
      if (cnt > max) {
        max = cnt;
        num = card[i-1];
      }
      cnt = 1;
    }
  }
  
  if (cnt > max) {
    num = card[N-1];
  }
  
  printf("%lld", num);
  
  free(card);
  
  return 0;
}

/*
  입력 배열: 1 1 2 2 2 3 3 3 3 일 때
  첫 번째 그룹: 1이 2번 등장 -> most_frequent = 1
  두 번째 그룹: 2가 3번 등장 -> most_frequent = 2로 갱신
  세 번째 그룹: 3이 4번 등장 -> most_frequent = 3로 갱신
  이제, for문이 끝나면서 배열의 끝에 도달하므로, 여기서 마지막 숫자 3은 4번 등장했지만,
  이 값은 새로운 숫자가 나오지 않아서 마지막에 빈도 계산을 업데이트하지 못하고 끝나버림

  그래서 반복문 종료 후 마지막 숫자 그룹의 빈도를 처리하기 위한 추가 작업이 필요
*/
