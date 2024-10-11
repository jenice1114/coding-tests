// https://www.acmicpc.net/problem/2164
// C11

#include <stdio.h>

#define MAX_LEN 500001

int queue[MAX_LEN];
int front = 0;
int rear = 0;

void push(int x) {
  queue[rear] = x;
  rear = (rear + 1) % MAX_LEN;
}

int pop() {
  int temp = queue[front];
  front = (front + 1) % MAX_LEN;
  return temp;
}

int size() {
  if (rear >= front) {
    return rear - front;
  } else {
    return MAX_LEN - front + rear;
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=1; i<=N; i++) {
    push(i);
  }
  
  while (size() > 1) {
    pop();
    push(pop());
  }
  
  printf("%d", queue[front]);
  
  return 0;
}

/*
  카드를 뒤로 붙히기때문에 원형큐

  q 사용 시 pop = dequeue, push = enqueue 를 보편적으로 사용한다
*/
