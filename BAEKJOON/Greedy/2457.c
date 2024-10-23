// https://www.acmicpc.net/problem/2457
// C11

#include <stdio.h>
#include <stdlib.h>

typedef struct Flower {
  int s_month;
  int s_date;
  int e_month;
  int e_date;
} Flower;

int compare(const void* a, const void* b) {
  Flower* A = (Flower*)a;
  Flower* B = (Flower*)b;
  
  if (A->s_month == B->s_month) {
    return A->s_date - B->s_date;
  }
  return A->s_month - B->s_month;
}

// 3월 30일이면 330 으로 변환
int date_to_int(int month, int date) {
  return month * 100 + date;
}

int main() {
  int N;
  scanf("%d", &N);
  
  Flower fw[N];
  for (int i=0; i<N; i++) {
    scanf("%d %d %d %d", &fw[i].s_month, &fw[i].s_date, &fw[i].e_month, &fw[i].e_date);
  }
  
  qsort(fw, N, sizeof(Flower), compare);
  
  int start = 301;
  int end = 1130;
  
  int current_end = start;
  int next_end = 0;
  int count = 0;
  int i = 0;
  
  while (current_end <= end) {
    int found = 0;
    
    while (i < N && date_to_int(fw[i].s_month, fw[i].s_date) <= current_end) {
      int temp = date_to_int(fw[i].e_month, fw[i].e_date);
      if (temp > next_end) {
        next_end = temp;
        found = 1;
      }
      i++;
    }
    
    if (!found) {
        printf("0");
        return 0;
    }
    
    current_end = next_end;
    count++;
    
    if (current_end > end) break;
  }
  
  printf("%d", count);
  
  return 0;
}

/*
  피는 날을 기준으로 정렬하고, 가장 오래 피는 꽃을 선택하면 됨
  기준은 3월1일-11월30일까지로 최소한 꽃을 선택하므로
*/
