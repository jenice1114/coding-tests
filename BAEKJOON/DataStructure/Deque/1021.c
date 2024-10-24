// https://www.acmicpc.net/problem/1021
// C11

#include <stdio.h>

#define MAX_LEN 51

int dq[MAX_LEN];
int front = 0;
int rear = 0;
int size = 0;

void push_front(int x) {
  front = (front - 1 + MAX_LEN) % MAX_LEN;
  dq[front] = x;
  size++;
}

void push_rear(int x) {
  dq[rear] = x;
  rear = (rear + 1) % MAX_LEN;
  size++;
}

int pop_front() {
  if (size == 0) {
    return -1;
  } else {
    int temp = dq[front];
    front = (front + 1) % MAX_LEN;
    size--;
    return temp;
  }
}

int pop_rear() {
  if (size == 0) {
    return -1;
  } else {
    rear = (rear - 1 + MAX_LEN) % MAX_LEN;
    int temp = dq[rear];
    size--;
    return temp;
  }
}

int find_index(int target) {
  for (int i=0; i<size; i++) {
    if (dq[(front + i) % MAX_LEN] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i=1; i<=N; i++) {
    push_rear(i);
  }
  
  int result = 0;
  for (int i=0; i<M; i++) {
    int pull = 0;
    scanf("%d", &pull);
    
    int idx = find_index(pull);
    
    int left = idx;
    int right = size - idx;
    if (right >= left) {
      for (int j=0; j<left; j++) {
        int temp = pop_front();
        push_rear(temp);
        result++;
      }
    } else {
      for (int j=0; j<right; j++) {
        int temp = pop_rear();
        push_front(temp);
        result++;
      }
    }
    
    pop_front();
  }
  printf("%d", result);
  
  return 0;
}
