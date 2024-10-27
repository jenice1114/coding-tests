// https://softeer.ai/practice/6266
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_MEETINGS 100

// 회의실 정보를 저장하는 구조체
typedef struct {
  char name[11];      // 회의실 이름
  int time[9];        // 9시~18시의 시간대, 0이면 예약 가능, 1이면 예약됨
} Room;

// 문자열 비교 함수: 회의실 이름을 오름차순으로 정렬하기 위한 함수
int compare_rooms(const void *a, const void *b) {
  return strcmp(((Room*)a)->name, ((Room*)b)->name);
}

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);

  // 회의실 정보를 저장할 배열
  Room rooms[MAX_ROOMS];

  // 회의실 이름 입력
  for (int i = 0; i < N; i++) {
    scanf("%s", rooms[i].name);
    // 모든 시간대를 0으로 초기화 (예약 가능 상태)
    for (int j = 0; j < 9; j++) {
      rooms[i].time[j] = 0;
    }
  }

  // 회의 정보를 입력받아 각 회의실의 예약 시간을 업데이트
  for (int i = 0; i < M; i++) {
    char name[11];
    int st, et;
    scanf("%s %d %d", name, &st, &et);

    // 회의실 이름에 맞는 회의실을 찾아 해당 시간대 업데이트
    for (int j = 0; j < N; j++) {
      if (strcmp(name, rooms[j].name) == 0) {
        for (int k = st; k < et; k++) {
          rooms[j].time[k - 9] = 1;  // 예약된 시간대는 1로 표시
        }
        break;
      }
    }
  }

  // 회의실 이름을 오름차순으로 정렬
  qsort(rooms, N, sizeof(Room), compare_rooms);

  // 각 회의실에 대해 예약 가능한 시간대 출력
  for (int i = 0; i < N; i++) {
    printf("Room %s:\n", rooms[i].name);

    // 예약 가능한 시간대의 개수 카운트
    int available_count = 0;
    int start = -1;
    for (int k = 0; k < 9; k++) {
      if (rooms[i].time[k] == 0) {  // 예약되지 않은 시간대
        if (start == -1) {
          start = k;
        }
      } else {
        if (start != -1) {
          available_count++;
          start = -1;
        }
      }
    }
    if (start != -1) {
      available_count++;
    }

    // 예약 가능한 시간이 있는지 확인
    if (available_count == 0) {
        printf("Not available\n");
    } else {
      printf("%d available:\n", available_count);
      start = -1;
      for (int k = 0; k < 9; k++) {
        if (rooms[i].time[k] == 0) {  // 예약되지 않은 시간대
          if (start == -1) {
            start = k;
          }
        } else {
          if (start != -1) {
            printf("%02d-%02d\n", start + 9, k + 9);
            start = -1;
          }
        }
      }
      if (start != -1) {
        printf("%02d-18\n", start + 9);
      }
    }

    // 구분선 출력
    if (i < N - 1) {
      printf("-----\n");
    }
  }

  return 0;
}
