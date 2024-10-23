// https://www.acmicpc.net/problem/2146
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

typedef struct Que {
  int x;
  int y;
  int distance;
} Que;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N;
int map[MAX_LEN][MAX_LEN];
int visit[MAX_LEN][MAX_LEN];
int group[MAX_LEN][MAX_LEN];

Que queue[MAX_LEN * MAX_LEN];
int front = 0;
int rear = 0;

void enqueue(int x, int y, int distance) {
  queue[rear].x = x;
  queue[rear].y = y;
  queue[rear].distance = distance;
  rear++;
}

Que dequeue() {
  return queue[front++];
}

int bfs_len(int island) {
  front = 0;
  rear = 0;
  memset(visit, 0, sizeof(visit));
  
  // 섬 시작점 설정
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (group[i][j] == island) {
        for (int k=0; k<4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
              map[nx][ny] == 0) {
            enqueue(i,j,0);
            visit[i][j] = 1;
            break;
          }
        }
      }
    }
  }
  
  // bfs 시작
  while (front < rear) {
    Que q = dequeue();
    
    for (int i=0; i<4; i++) {
      int nx = q.x + dx[i];
      int ny = q.y + dy[i];
  
      if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
        // 다른섬에 도착하면 반환
        if (group[nx][ny] != 0 && group[nx][ny] != island) {
          return q.distance;
        }
        
        if (map[nx][ny] == 0 && visit[nx][ny] == 0) {
          visit[nx][ny] = 1;
          enqueue(nx, ny, q.distance+1);
        }
      }
    }
  }
  
  return MAX_LEN * MAX_LEN;
}

void dfs_island(int x, int y, int island) {
  visit[x][y] = 1;
  group[x][y] = island;
  
  for (int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if (nx >= 0 && nx < N && ny >= 0 && ny < N && 
        visit[nx][ny] == 0 && map[nx][ny] == 1) {
      dfs_island(nx, ny, island);
    }
  }
}

int main() {
  scanf("%d", &N);
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  memset(visit, 0, sizeof(visit));
  int island = 1;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      if (map[i][j] == 1 && visit[i][j] == 0) {
        dfs_island(i,j,island);
        island++;
      }
    }
  }
  
  int min = MAX_LEN * MAX_LEN;
  for (int i=1; i<island; i++) {
    int len = bfs_len(i);
    if (len < min) {
      min = len;
    }
  }
  printf("%d", min);
  
  return 0;
}

/*
  DFS: 재귀적 호출, 전체 탐색 필수
  BFS: 큐 사용, 번져가는 모양새나 최단거리

  구분	      DFS	                                BFS
  탐색순서    깊이 우선, 한 경로 끝까지 탐색	      너비 우선, 같은 레벨 우선 탐색
  자료구조	  스택(Stack) or 재귀(Recursion)	     큐(Queue)
  적용 상황	  경로 탐색, 트리 탐색에 유리	          최단 경로 탐색에 유리
  메모리 사용	깊이마다 스택 프레임 저장	            너비마다 큐에 노드를 저장
  실행 시간	  노드가 깊다면 느릴 수 있음	          레벨마다 진행되므로 효율적일 수 있음
  최단 경로	  보장하지 않음	                       항상 최단 경로를 찾음


  DFS:
  경로 찾기 (한 경로를 끝까지 탐색할 때 유리)
  모든 가능한 경로를 찾는 문제 (예: 미로 찾기, 백트래킹)
  트리의 깊이를 우선으로 탐색할 때
  
  BFS:
  최단 경로 탐색 (모든 간선의 가중치가 동일한 경우, 가장 가까운 노드부터 탐색하므로 최단 경로 보장)
  최소 이동이 필요한 문제 (예: 그래프에서 두 노드 간의 최단 거리)
  최단 거리 탐색에 유리한 문제 (예: 미로에서 가장 짧은 경로)


  예시코드
  void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
      int next = adj[node][i];
      if (!visited[next]) {
        dfs(next);
      }
    }
  }

  void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (!visited[next]) {
          visited[next] = 1;
          q.push(next);
        }
      }
    }
  }
*/
