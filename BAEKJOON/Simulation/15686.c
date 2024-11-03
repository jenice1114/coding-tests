// https://www.acmicpc.net/problem/15686
// C11

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 50

typedef struct Position {
    int x;
    int y;
} Position;

Position house[MAX * 2];
Position chicken[13];
int selected[13];
int h_cnt = 0;
int c_cnt = 0;

int n,m;
int min_dist = INT_MAX;

int select_city() {
  int total = 0;
  for (int i=0; i<h_cnt; i++) {
    int house_dist = INT_MAX;
    for (int j=0; j<c_cnt; j++) {
      if (selected[j]) {
        int dist = abs(house[i].x - chicken[j].x) + abs(house[i].y - chicken[j].y);
        if (dist < house_dist) {
          house_dist = dist;
        }
      }
    }
    total += house_dist;
  }
  return total;
}

void select_chicken(int idx, int cnt) {
  if (cnt == m) {
    int city_dist = select_city();
    if (city_dist < min_dist) {
      min_dist = city_dist;
    }
    return;
  }
  
  if (idx == c_cnt) return;
  
  selected[idx] = 1;
  select_chicken(idx+1, cnt+1);
  selected[idx] = 0;
  select_chicken(idx+1, cnt);
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      int temp;
      scanf("%d", &temp);
      
      if (temp == 1) {
        house[h_cnt].x = i;
        house[h_cnt].y = j;
        h_cnt++;
      } else if (temp == 2) {
        chicken[c_cnt].x = i;
        chicken[c_cnt].y = j;
        c_cnt++;
      }
    }
  }
  
  select_chicken(0, 0);
  printf("%d\n", min_dist);
  
  return 0;
}
