// https://www.acmicpc.net/problem/3015
// C11

#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  
  int people[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &people[i]);
  }
  
  int stack[N];
  int top = 0;
  long long result = 0;
  int count[N];
  for (int i=0; i<N; i++) {
    int current_count = 1;
    
    while (top > 0 && people[i] >= people[stack[top - 1]]) {
      result += count[top-1];
      if (people[i] == people[stack[top-1]]) {
        current_count += count[top-1];
      }
      top--;
    }
    stack[top] = i;
    count[top] = current_count;
    top++;
    
    if (top > 1) {
      result++;
    }
  }
  
  printf("%lld", result);
  
  return 0;
}

/*
  서로 볼 수 있으려면 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 함
  동일한 키를 가진 사람이 있다면? 키가 크지 않고 동일하기 때문에 볼 수 있음

  target = 2, 4, 1, 2, 2, 5, 1, stack = [], top = 0, result = 0
  stack 2(0)
  count 1
  top 1

  target = 4, 1, 2, 2, 5, 1, stack = [0], top = 1, result = 0
  result +1
  top 0
  stack 4(1)
  count 1
  top 1

  target = 1, 2, 2, 5, 1, stack = [1], top = 1, result = 1
  stack 4(1) 1(2)
  count 1    1
  top 2
  result +1

  target = 2, 2, 5, 1, stack = [1, 2], top = 2, result = 2
  result +1
  top 1
  stack 4(1) 2(3)
  count 1    1
  top 2
  result +1

  target = 2, 5, 1, stack = [1, 3], top = 2, result = 4
  result +1
  current count 2
  top 1
  stack 4(1) 2(4)
  count 1    2
  top 2
  result +1

  target = 5, 1, stack = [1, 4], top = 2, result = 6
  result +2
  top 1
  result +1
  top 0
  stack 5(5)
  count 1
  top 1

  target = 1, stack = [5], top = 1, result = 9
  stack 5(5) 1(6)
  count 1    1
  top 2
  result +1

  
  result = 10
  - 스택에 넣을 때 2명이상 있다면 자신보다 키 큰 사람과 만나게 된 것이므로 result++ 처리
  - 같은 높이도 처리해야 하기 때문에 그룹화처리 (current count)
*/
