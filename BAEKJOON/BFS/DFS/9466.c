// https://www.acmicpc.net/problem/9466
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100002

int n;
int student[MAX_LEN];
int visit[MAX_LEN];
int team[MAX_LEN];

int teamCnt;

void dfs(int x) {
  visit[x] = 1;
  int next = student[x];
  
  if (visit[next] == 0) {
    dfs(next);
  } else if (team[next] == 0) {
    for (int i=next; i!=x; i=student[i]) {
      teamCnt++;
    }
    teamCnt++;
  }
  team[x] = 1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  
  while (tc--) {
    scanf("%d", &n);
    
    memset(student, 0, sizeof(student));
    memset(visit, 0, sizeof(visit));
    memset(team, 0, sizeof(team));
    teamCnt = 0;
    
    for (int i=1; i<=n; i++) {
      scanf("%d", &student[i]);
    }
    
    for (int i=1; i<=n; i++) {
      if (visit[i] == 0) {
        dfs(i);
      }
    }
    
    printf("%d\n", n - teamCnt);
  }
  
  return 0;
}
