// https://www.acmicpc.net/problem/13549
// C11

#include <stdio.h>

#define MAX 200001

typedef struct Que {
  int x;
  int t;
} Q;

int n, k;
int visit[MAX];

Q que[MAX];
int front;
int rear;

void enqueue(int x, int t) {
  que[rear].x = x;
  que[rear].t = t;
  rear++;
}

Q dequeue() {
  return que[front++];
}

int bfs() {
  while (front < rear) {
    Q cur = dequeue();
    
    if (cur.x == k) return cur.t;
            
    int compare = cur.x*2;
    if (compare < MAX && visit[compare] == 0) {
      visit[compare] = 1;
      enqueue(compare, cur.t);
    }
    
    int dx[2] = {cur.x-1, cur.x+1};
    for (int i=0; i<2; i++) {
      int nx = dx[i];
      
      if (nx >= 0 && nx < MAX && visit[nx] == 0) {
        visit[nx] = 1;
        enqueue(nx, cur.t + 1);
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &k);
  if (n == k) {
    printf("0");
    return 0;
  }
  
  visit[n] = 1;
  enqueue(n, 0);
  int result = bfs();
  printf("%d", result);
  
  return 0;
}
