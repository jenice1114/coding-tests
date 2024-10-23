// https://www.acmicpc.net/problem/10989
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 10001

int main() {
  int N;
  scanf("%d", &N);
  
  int* count = (int*)calloc(MAX_VALUE, sizeof(int));
  
  int num;
  for (int i=0; i<N; i++) {
    scanf("%d", &num);
    count[num]++;
  }
  
  for (int i=1; i<=MAX_VALUE; i++) {
    for (int j=0; j<count[i]; j++) {
      printf("%d\n", i);
    }
  }
  
  free(count);
  
  return 0;
}

/*
  이 수는 10,000보다 작거나 같은 자연수이다.

  최대 10,000,000번에서 반복적으로 같은 값이 나올 수 있다는 뜻
  그럴 때는 계수정렬을 이용하도록 하자

  적합한 경우:
      숫자의 범위가 상대적으로 작고(수천에서 수만 정도),
      정수 데이터일 때
      예를 들어, 1부터 10,000까지의 자연수들을 정렬해야 할 때.
  
  적합하지 않은 경우:
      숫자의 범위가 너무 크거나(수억 이상),
      데이터가 음수나 실수인 경우
*/
