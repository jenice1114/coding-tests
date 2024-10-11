// https://www.acmicpc.net/problem/5397
// C11

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000001

typedef struct Node {
  char data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* head;
Node* tail;
Node* cursor;

Node* createNode(char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
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
}

// 커서 오른쪽으로 이동
void move_right() {
  if (cursor != tail) {
    cursor = cursor->next;
  }
}

// 커서 왼쪽 문자 삭제
void delete_char() {
  if (cursor->prev != NULL) { // 삭제할 문자가 있을 때만 삭제
    Node* to_delete = cursor->prev;
    if (to_delete->prev != NULL) {
      to_delete->prev->next = cursor;
    } else {
      head = cursor; // 첫 번째 노드를 삭제하는 경우 head 갱신
    }
    cursor->prev = to_delete->prev;
    free(to_delete);
  }
}

// 커서 왼쪽에 문자 추가
void insert_char(char c) {
  Node* newNode = createNode(c);
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

int main() {
  int N;
  scanf("%d", &N);
  
  while (N--) {
    char test[MAX_LEN];
    scanf("%s", test);
    
    tail = createNode('\0');
    head = tail;
    cursor = tail;
    
    for (int i=0; test[i]!='\0'; i++) {
      if (test[i] == '<') {
        move_left();
      } else if (test[i] == '>') {
        move_right();
      } else if (test[i] == '-') {
        delete_char();
      } else {
        insert_char(test[i]);   
      }
    }
    
    Node* temp = head;
    while (temp != tail) {
      printf("%c", temp->data);
      temp = temp->next;
    }
    printf("\n");
    
    Node* deinit;
    while (head != NULL) {
      deinit = head;
      head = head->next;
      free(deinit);
    }
  }
  
  return 0;
}
