// https://www.acmicpc.net/problem/7785
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003  // 소수로 설정 (충돌 방지 효과)

typedef struct Entry {
  char name[6];
  struct Entry* next;
} Entry;

// 해시 테이블 초기화
Entry* hash_table[TABLE_SIZE];

// 해시 함수
unsigned int hash(const char* str) {
  unsigned int hash = 5381;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;  // hash * 33 + c
  }
  return hash % TABLE_SIZE;
}

// 해시 테이블에 이름 추가 (enter)
void insert(const char* name) {
  unsigned int index = hash(name);
  Entry* new_entry = (Entry*)malloc(sizeof(Entry));
  strcpy(new_entry->name, name);
  new_entry->next = hash_table[index];
  hash_table[index] = new_entry;
}

// 해시 테이블에서 이름 삭제 (leave)
void delete(const char* name) {
  unsigned int index = hash(name);
  Entry* cur = hash_table[index];
  Entry* prev = NULL;
  
  while (cur != NULL && strcmp(cur->name, name) != 0) {
    prev = cur;
    cur = cur->next;
  }
  
  if (cur == NULL) return;  // 이름을 찾지 못한 경우
  
  if (prev == NULL) {
    // 첫 번째 노드를 삭제해야 하는 경우
    hash_table[index] = cur->next;
  } else {
    // 중간 또는 마지막 노드를 삭제
    prev->next = cur->next;
  }
  free(cur);  // 메모리 해제
}

// 남아있는 이름을 배열로 변환
int collect_names(char* names[], int max_size) {
  int count = 0;
  for (int i = 0; i < TABLE_SIZE; i++) {
    Entry* cur = hash_table[i];
    while (cur != NULL && count < max_size) {
      names[count++] = cur->name;
      cur = cur->next;
    }
  }
  return count;
}

// 이름을 역순으로 정렬하기 위한 비교 함수
int compare(const void* a, const void* b) {
    return strcmp(*(const char**)b, *(const char**)a);
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char name[6];
    char state[6];
    scanf("%s %s", name, state);

    if (strcmp(state, "enter") == 0) {
      insert(name);  // 해시 테이블에 이름 추가
    } else if (strcmp(state, "leave") == 0) {
      delete(name);  // 해시 테이블에서 이름 삭제
    }
  }

  // 남아있는 이름을 배열로 수집
  char* names[n];
  int count = collect_names(names, n);

  // 사전순 역순으로 정렬
  qsort(names, count, sizeof(char*), compare);

  // 정렬된 이름 출력
  for (int i = 0; i < count; i++) {
    printf("%s\n", names[i]);
  }

  return 0;
}

/*
  처음에 연결리스트로 풀었는데 시간초과나옴 (ㅠㅠ)
  이건 해시테이블로 푸는 문제라는데.. 처음 구현해본다
  해결전략은 얼추 맞은듯 이름을 키로하고 leave일 때 키를 삭제, enter일 때 키를 삽입
  그리고 마지막으로 사전순 정렬을 위해 qsort로 정렬

  hash 함수 부연설명 ((http://www.cse.yorku.ca/~oz/hash.html))
  1. 임의의 값으로 초기값을 설정한다 (5381, 실험을 통해 좋은 결과를 얻었다고 함)
  2. 문자열의 각 문자를 순차적으로 가져오면서 해시값으로 계산한다
   2-1. hash = ((hash << 5) + hash) + c;
      hash << 5는 hash를 5비트(즉, 32 * 2^5)만큼 왼쪽으로 시프트하며 새로운 해시 값을 만듬
      hash + hash는 기존 해시 값에 다시 더해주는 작업을 함으로써 해시 충돌을 방지함
      c는 현재 처리 중인 문자의 ASCII 값이며 이 값을 더하여 고유한 해시 값을 만듬
  3. TABLE_SIZE 100003 에 모듈러 연산하여 반환
   3-1. 이거 대체 왜 해시테이블 사이즈가 100003 이여야 하는지는 모르겠는데.. 뭐 근거가 있긴 하나보다 마치 5381,33 과 같은 맥락인듯
      100003 (약 백만 개, 10^6 데이터 처리 시)
      10000019 (약 천만 개, 10^7 데이터를 처리 시)
      100000007 (약 1억 개, 10^8 데이터를 처리 시)
      1000000007 (약 10억 개, 10^9 데이터를 처리 시)



아래는 시간초과 된 나의 코드...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000001

typedef struct Work {
  char name[6];
  struct Work* next;
} Work;

void insert(Work** head, const char* name) {
  Work* new_wk = (Work*)malloc(sizeof(Work));
  strcpy(new_wk->name, name);
  new_wk->next = *head;
  *head = new_wk;
}

void delete(Work** head, const char* name) {
  Work* cur = *head;
  Work* prev = NULL;
  
  if (cur != NULL && strcmp(cur->name, name) == 0) {
    *head = cur->next;
    free(cur);
    return;
  }
  
  while (cur != NULL && strcmp(cur->name, name) != 0) {
    prev = cur;
    cur = cur->next;
  }
  
  if (cur == NULL) return;
  prev->next = cur->next;
  free(cur);
}

int compare(const void* a, const void* b) {
  return strcmp(*(const char**)b, *(const char**)a);
}

int main() {
  int n;
  scanf("%d", &n);
  
  Work* head = NULL;
  for (int i=0; i<n; i++) {
    char name[6];
    char state[6];
    scanf("%s %s", name, state);
    
    if (strcmp(state, "enter") == 0) {
      insert(&head, name);
    } else if (strcmp(state, "leave") == 0) {
      delete(&head, name);
    }
  }
  
  int count = 0;
  Work* temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  char* names[count];
  temp = head;
  for (int i = 0; i < count; i++) {
    names[i] = temp->name;
    temp = temp->next;
  }
  qsort(names, count, sizeof(char*), compare);

  for (int i = 0; i < count; i++) {
    printf("%s\n", names[i]);
  }
  
  return 0;
}
 */
