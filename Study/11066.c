#include <stdio.h>
#include <string.h>

#define MAX_LEN 501

int arr[MAX_LEN];
int visit[MAX_LEN];
int min = 10000;

void dfs(int x, int target) {
  visit[x] = 1;

  if (x == target) return;

}

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int K;
    scanf("%d", &K);

    memset(arr, K, sizeof(arr));
    memset(visit, K, sizeof(visit));
    min = 10000;
    for (int i=0; i<K; i++) {
      scanf("%d", &arr[i]);
    }
    dfs(0, K);
  }

  return 0;
}

/*
  https://www.acmicpc.net/problem/11066

  막힌이유
    생각이 dfs랑 재귀밖에 들지 않는다
    좀 더 알고리즘에 대해 알아봐야할 것 같음...
    일단 이거는 우선순위 큐로 푸는 문제라고 한다 왜인지도 모르겠음
*/
