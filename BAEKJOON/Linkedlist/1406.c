// https://www.acmicpc.net/problem/1406
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100001

struct Node {
  char data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;
struct Node* tail;
struct Node* cursor;

struct Node* createNode(char data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// 커서 왼쪽으로 이동
void move_left() {
  if (cursor->prev != NULL) {
    cursor = cursor->prev;
  }
  // 맨 앞이면 무시
}

// 커서 오른쪽으로 이동
void move_right() {
  if (cursor != tail) {
    cursor = cursor->next;
  }
  // 맨 뒤이면 무시
}

// 커서 왼쪽에 문자 추가
void insert_char(char c) {
  struct Node* newNode = createNode(c);
  newNode->prev = cursor->prev;
  newNode->next = cursor;

  if (cursor->prev != NULL) {
    cursor->prev->next = newNode;
  } else {
    // 삽입한 노드가 첫 번째 노드인 경우 head 갱신
    head = newNode;
  }
  cursor->prev = newNode;
}

// 커서 왼쪽 문자 삭제
void delete_char() {
  if (cursor->prev != NULL) { // 삭제할 문자가 있을 때만 삭제
    struct Node* to_delete = cursor->prev;
    if (to_delete->prev != NULL) {
      to_delete->prev->next = cursor;
    } else {
      head = cursor; // 첫 번째 노드를 삭제하는 경우 head 갱신
    }
    cursor->prev = to_delete->prev;
    free(to_delete);
  }
}

int main() {
  char N[MAX_LEN];
  scanf("%s", N);
  int M;
  scanf("%d", &M);
  
  tail = createNode('\0');
  head = tail;
  cursor = tail;
  
  for (int i=0; N[i]!='\0'; i++) {
    insert_char(N[i]);
  }
  
  while (M--) {
    char cmd;
    scanf(" %c", &cmd);

    if (cmd == 'L') {
      move_left();
    } else if (cmd == 'D') {
      move_right();
    } else if (cmd == 'B') {
      delete_char();
    } else if (cmd == 'P') {
      char str;
      scanf(" %c", &str);
      insert_char(str);
    }
  }
  
  struct Node* temp = head;
  while (temp != tail) {
    printf("%c", temp->data);
    temp = temp->next;
  }
  
  return 0;
}

/*
  명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치
  P 일때 입력할 문자가 한번 더 들어옴
*/
