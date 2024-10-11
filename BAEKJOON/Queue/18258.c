// https://www.acmicpc.net/problem/18258
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 2000001

int queue[MAX_LEN];
int front = 0;
int rear = 0;

void push(int x) {
  queue[rear++] = x;
}

int pop() {
  if (front == rear) {
    return -1;
  } else {
    return queue[front++];
  }
}

int size() {
  return rear - front;
}

int empty() {
  return front == rear ? 1 : 0;
}

int func_front() {
  if (!empty()) {
    return queue[front];
  } else {
    return -1;
  }
}

int func_back() {
  if (!empty()) {
    return queue[rear-1];
  } else {
    return -1;
  }
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    char cmd[6];
    scanf("%s", cmd);
    
    if (strcmp(cmd, "push") == 0) {
      int x;
      scanf("%d", &x);
      push(x);
    } else if (strcmp(cmd, "pop") == 0) {
      printf("%d\n", pop());
    } else if (strcmp(cmd, "size") == 0) {
      printf("%d\n", size());
    } else if (strcmp(cmd, "empty") == 0) {
      printf("%d\n", empty());
    } else if (strcmp(cmd, "front") == 0) {
      printf("%d\n", func_front());
    } else if (strcmp(cmd, "back") == 0) {
      printf("%d\n", func_back());
    }
  }
  
  return 0;
}
