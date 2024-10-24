// https://www.acmicpc.net/problem/1620
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003

typedef struct Poketmon {
  int idx;
  char name[21];
  struct Poketmon* next;
} Poket;

Poket* hash_table[TABLE_SIZE];
char* hash_table_num[TABLE_SIZE];

unsigned int hash(const char* str) {
  unsigned int hash = 5381;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % TABLE_SIZE;
}

void insert(const char* name, int num) {
  unsigned int idx = hash(name);
  Poket* new_pk = (Poket*)malloc(sizeof(Poket));
  strcpy(new_pk->name, name);
  new_pk->idx = num;
  new_pk->next = hash_table[idx];
  hash_table[idx] = new_pk;
  
  hash_table_num[num] = (char*)malloc(strlen(name) + 1);
  strcpy(hash_table_num[num], name);
}

int search_str(const char* name) {
  unsigned int idx = hash(name);
  Poket* cur = hash_table[idx];
  while (cur != NULL) {
    if (strcmp(cur->name, name) == 0) {
      return cur->idx;
    }
    cur = cur->next;
  }
  return -1;
}

char* search_num(int idx) {
  return hash_table_num[idx];
}

int main() {
  int N,M;
  scanf("%d %d", &N, &M);
  
  for (int i=0; i<N; i++) {
    char name[21];
    scanf("%s", name);
    insert(name, i+1);
  }
  
  for (int i=0; i<M; i++) {
    char name[21];
    scanf("%s", name);
    if (name[0] >= '0' && name[0] <= '9') {
      int temp = atoi(name);
      printf("%s\n", search_num(temp));
    } else if (name[0] >= 'A' && name[0] <= 'Z') {
      printf("%d\n", search_str(name));
    }
  }
  
  return 0;
}
