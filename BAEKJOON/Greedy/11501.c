// https://www.acmicpc.net/problem/11501
// C11

#include <stdio.h>

int main() {
  int tc;
  scanf("%d", &tc);
  
  while (tc--) {
    int N;
    scanf("%d", &N);
    
    int stock[N];
    for (int i=0; i<N; i++) {
      scanf("%d", &stock[i]);
    }
    
    long long result = 0;
    int max = stock[N-1];
    for (int i=N-2; i>=0; i--) {
      if (stock[i] > max) {
        max = stock[i];
      } else {
        result += max - stock[i];
      }
    }
    printf("%lld\n", result);
  }
  return 0;
}

/* 틀린코드
#include <stdio.h>

int main() {
  int tc;
  scanf("%d", &tc);
  
  while (tc--) {
    int N;
    scanf("%d", &N);
    
    int stock[N];
    for (int i=0; i<N; i++) {
      scanf("%d", &stock[i]);
    }
    
    long long result = 0;
    long long temp = 0;
    int count = 0;
    for (int i=0; i<N-1; i++) {
      if (stock[i+1] >= stock[i]) {
        temp += stock[i];
        count++;
      } else {
        result += (stock[i] * count) - temp;
        temp = 0;
        count = 0;
      }
    }
    
    if (count > 0) {
      result += (stock[N-1] * count) - temp;
    }
    printf("%lld\n", result);
  }
  return 0;
}

  이렇게 구현했는데, 이렇게되면 미래의 주가변동을 고려하지않고
  현재 시점 기준으로 매도하기때문에 뒤에서부터 탐색하는게 정답이라고 한다...
  띠용...ㅎㅎㅎ..
*/
