// https://softeer.ai/practice/6250
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

typedef struct Entry {
  int score;
  int idx;
} Entry;

int compare(const void* a, const void* b) {
  Entry* A = (Entry*)a;
  Entry* B = (Entry*)b;

  return B->score - A->score;
}

int main() {
  int N;
  scanf("%d", &N);

  int score[3][N];
  int rank[4][N];
  Entry person[N];
  for (int i=0; i<3; i++) {
    for (int j=0; j<N; j++) {
      scanf("%d", &score[i][j]);

      person[j].score = score[i][j];
      person[j].idx = j;
    }
    qsort(person, N, sizeof(Entry), compare);
    
    int cnt = 1;
    for (int j=0; j<N; j++) {
      if (j > 0 && person[j].score < person[j-1].score) {
        cnt = j+1;
      }
      rank[i][person[j].idx] = cnt;
    }
  }

  for (int i=0; i<N; i++) {
    person[i].score = score[0][i] + score[1][i] + score[2][i];
    person[i].idx = i;
  }
  qsort(person, N, sizeof(Entry), compare);

  int cnt = 1;
  for (int i=0; i<N; i++) {
    if (i > 0 && person[i].score < person[i-1].score) {
      cnt = i+1;
    }
    rank[3][person[i].idx] = cnt;
  }

  for (int i=0; i<4; i++) {
    for (int j=0; j<N; j++) {
      printf("%d ", rank[i][j]);
    }
    printf("\n");
  }

  return 0;
}

/*
  메모리가 1024MB로 작아서 이차원배열은 못 쓰고 struct를 사용
  문제를 잘~ 보면, 3개의 대회임... 결국 그럼 행이 3으로 정해져있으며 N만큼의 열이 있다는 것(ㅠㅠ)
  이거 몰라서 헤맨 문제

  cnt = j+1;
  이 부분은 같은 점수처리를 하기 위함인데,
  이미 내림차순 정렬이 되어 있기 때문에
  내림차순 조건이 맞을 때만 등수를 증가시키고 아니라면 같은 등수를 넣음
*/
