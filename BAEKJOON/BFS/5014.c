// https://www.acmicpc.net/problem/5014
// C11

#include <stdio.h>

#define MAX 1000001

int F, S, G, U, D;
int building[MAX];
int visit[MAX];

int queue[MAX];
int front;
int rear;

void enqueue(int x) {
  queue[rear++] = x;
}

int dequeue() {
  return queue[front++];
}

void bfs() {
  while (front < rear) {
    int cur = dequeue();
    if (cur == G) return;
    
    int nx = cur + U;
    if (nx >= 1 && nx <= F && visit[nx] == 0) {
      enqueue(nx);
      visit[nx] = 1;
      building[nx] = building[cur] + 1;
    }
    
    int ny = cur - D;
    if (ny >= 1 && ny <= F && visit[ny] == 0) {
      enqueue(ny);
      visit[ny] = 1;
      building[ny] = building[cur] + 1;
    }
  }
}

int main() {
  scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
  
  for (int i=1; i<=F; i++) {
    building[i] = -1;
  }
  
  enqueue(S);
  visit[S] = 1;
  building[S] = 0;
  bfs();
  
  if (building[G] == -1) {
    printf("use the stairs");
  } else {
    printf("%d", building[G]);
  }
  return 0;
}
