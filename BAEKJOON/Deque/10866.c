// https://www.acmicpc.net/problem/10866
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10001

int dq[MAX_LEN];
int front = 0;
int rear = 0;
int dq_size = 0;

void push_front(int x) {
  front = (front - 1 + MAX_LEN) % MAX_LEN;
  dq[front] = x;
  dq_size++;
}

void push_back(int x) {
  dq[rear] = x;
  rear = (rear + 1) % MAX_LEN;
  dq_size++;
}

int pop_front() {
  if (dq_size == 0) {
    return -1;
  } else {
    int temp = dq[front];
    front = (front + 1) % MAX_LEN;
    dq_size--;
    return temp;
  }
}

int pop_back() {
  if (dq_size == 0) {
    return -1;
  } else {
    rear = (rear - 1 + MAX_LEN) % MAX_LEN;
    int temp = dq[rear];
    dq_size--;
    return temp;
  }
}

int size() {
  return dq_size;
}

int empty() {
  return dq_size == 0 ? 1 : 0;
}

int get_front() {
  if (dq_size == 0) {
    return -1;
  } else {
    return dq[front];
  }
}

int get_back() {
  if (dq_size == 0) {
    return -1;
  } else {
    // rear-1 번지 찾기
    return dq[(rear - 1 + MAX_LEN) % MAX_LEN];
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    char cmd[20];
    scanf("%s", cmd);
    
    if (strcmp(cmd, "push_front") == 0) {
      int x;
      scanf("%d", &x);
      push_front(x);
    } else if (strcmp(cmd, "push_back") == 0) {
      int x;
      scanf("%d", &x);
      push_back(x);
    } else if (strcmp(cmd, "pop_front") == 0) {
      printf("%d\n", pop_front());
    } else if (strcmp(cmd, "pop_back") == 0) {
      printf("%d\n", pop_back());
    } else if (strcmp(cmd, "size") == 0) {
      printf("%d\n", size());
    } else if (strcmp(cmd, "empty") == 0) {
      printf("%d\n", empty());
    } else if (strcmp(cmd, "front") == 0) {
      printf("%d\n", get_front());
    } else if (strcmp(cmd, "back") == 0) {
      printf("%d\n", get_back());
    }
  }
  
  return 0;
}
