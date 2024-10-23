// https://www.acmicpc.net/problem/13549
// C11

#include <stdio.h>
#include <string.h>

#define LMT 100001

int board[LMT + 2];
int queue[LMT * 3];  // 큐 배열
int front = 0, rear = 0;
int sis, bro;

// 큐에 값을 추가하는 함수
void enqueue(int num) {
  queue[rear++] = num;
}

// 큐에서 값을 꺼내는 함수
int dequeue() {
  return queue[front++];
}

// 순간이동 처리 함수
void teleport(int num) {
  int tmp = num;
  if (tmp == 0) return;  // 0은 순간이동 불가능
  
  while (tmp < LMT && !board[bro]) {
    if (board[tmp] == 0) {  // 아직 방문하지 않은 경우
      board[tmp] = board[num];  // 시간을 그대로 유지
      enqueue(tmp);  // 큐에 추가
      if (tmp == bro) return;  // 목적지에 도달하면 종료
    }
    tmp <<= 1;  // 2배로 순간이동
  }
}

int main(void) {
  // 입력 받기
  scanf("%d %d", &sis, &bro);
  
  memset(board, 0, sizeof(board));  // 방문 배열 초기화
  board[sis] = 1;  // 시작 위치 방문 처리
  enqueue(sis);
  teleport(sis);  // 시작점에서 순간이동 처리
  
  // BFS 탐색
  while (!board[bro]) {
    int v = dequeue();
    int nvLst[2] = { v + 1, v - 1 };  // X+1, X-1 이동
    
    for (int i = 0; i < 2; i++) {
      int nv = nvLst[i];
      if (nv < 0 || nv >= LMT) continue;  // 범위 체크
      if (board[nv] != 0) continue;  // 이미 방문한 경우 건너뜀
      board[nv] = board[v] + 1;  // 시간을 1초 증가
      enqueue(nv);  // 큐에 추가
      teleport(nv);  // 순간 이동 처리
    }
  }
  
  printf("%d\n", board[bro] - 1);  // 결과 출력
  
  return 0;
}

/*
  못풀었따...ㅋ
*/