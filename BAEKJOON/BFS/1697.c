// https://www.acmicpc.net/problem/1697
// C11

#include <stdio.h>

#define MAX_LEN 100001

typedef struct Que {
  int x;
  int minute;
} Que;

int N, K;
int visit[MAX_LEN];

Que q[MAX_LEN];
int front = 0;
int rear = 0;

void enqueue(int x, int minute) {
  q[rear].x = x;
  q[rear].minute = minute;
  rear++;
}

Que dequeue() {
  return q[front++];
}

int bfs(int x) {
  visit[x] = 1;
  
  while (front < rear) {
    Que q = dequeue();
    
    if (q.x == K) return q.minute;
    
    int position[3] = {q.x-1, q.x+1, q.x*2};
    
    for (int i=0; i<3; i++) {
      int nx = position[i];
      
      if (nx >= 0 && nx < MAX_LEN && visit[nx] == 0) {
        visit[nx] = 1;
        enqueue(nx, q.minute+1);
      }
    }
  }
  
  return -1;
}

int main() {
  scanf("%d %d", &N, &K);
  
  enqueue(N, 0);
  printf("%d", bfs(N));
  
  return 0;
}
