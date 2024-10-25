// https://www.acmicpc.net/problem/2870
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LEN 101
#define MAX_NUMS 10000

char* ans[MAX_NUMS];  // 동적 메모리로 각 숫자 문자열을 저장할 배열다
int ans_idx = 0;
char s[MAX_LEN];      // 입력 문자열을 저장할 배열

// 알파벳 문자를 건너뛰고 숫자 부분만 추출
void eraseChars() {
  scanf("%s", s);
  int pos = 0, nxt_pos = 0;
  while (1) {
    // 알파벳 건너뛰기
    while (s[nxt_pos] >= 'a' && s[nxt_pos] <= 'z') {
      nxt_pos++;
    }
    pos = nxt_pos;
    if (pos >= strlen(s)) break; // 문자열이 끝났을 경우
    
    // 숫자 부분 찾기
    while (s[nxt_pos] >= '0' && s[nxt_pos] <= '9') {
      nxt_pos++;
    }

    // 숫자 부분을 문자열로 저장
    int len = nxt_pos - pos;
    if (len > 0) {
      char* num_str = (char*)malloc(len + 1);
      strncpy(num_str, s + pos, len); // s 시작 주소 + 숫자가 시작하는 pos, 즉 숫자 시작하는 부분부터 끝나는 부분까지 복사
      num_str[len] = '\0';
      ans[ans_idx++] = num_str;
    }
    pos = nxt_pos;
  }
}

// 앞에 있는 '0'을 제거
void eraseZeros() {
  for (int i = 0; i < ans_idx; i++) {
    int pos = 0;
    while (ans[i][pos] == '0') pos++;
    
    char* new_str = (char*)malloc(strlen(ans[i]) - pos + 1); // pos 이후 부분을 복사 (0이 아닌 부분)
    strcpy(new_str, (pos == strlen(ans[i])) ? "0" : ans[i] + pos); // 전체가 0일 경우 "0", 아니면 나머지 숫자를 복사
    free(ans[i]);
    ans[i] = new_str;
  }
}

// 비교 함수 (문자열 길이와 사전순으로 정렬)
int cmp(const void* a, const void* b) {
  char* str1 = *(char**)a;
  char* str2 = *(char**)b;
  int len_diff = strlen(str1) - strlen(str2);
  if (len_diff == 0) return strcmp(str1, str2);
  return len_diff;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    eraseChars();
  }
  eraseZeros();

  qsort(ans, ans_idx, sizeof(char*), cmp);

  for (int i = 0; i < ans_idx; i++) {
    printf("%s\n", ans[i]);
    free(ans[i]);  // 동적 할당 해제
  }

  return 0;
}

/*
  일단 .. 문제 이해를 못했다 아래는 내가 푼 코드인데
  문제를 보면, "숫자를 모두 찾은 뒤 이 숫자를 비내림차순으로 정리해야 한다" 라고 명시되어 있어서
  아~ 그럼 숫자일때 추출해서 넣고 그거 qsort 돌리면 되겠다 했는데?
  그게아니고 숫자를 찾아서 이 숫자배열을 비내림차순, 즉 문자열의 길이로 비내림차순을 해야 함..
  것도 모르고 그냥 숫자로 뽑아서 정렬해가지고 계속 틀린듯 싶다

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 101
#define MAX_NUMS 10000

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

int main() {
  int N;
  scanf("%d", &N);
  
  int numbers[MAX_NUMS];
  int idx = 0;

  for (int i=0; i<N; i++) {
    char word[MAX_LEN];
    scanf("%s", word);
    
    char temp[MAX_LEN] = {0};
    int cnt = 0;
    
    for (int j=0; word[j]!='\0'; j++) {
      if (word[j] >= '0' && word[j] <= '9') {
        temp[cnt++] = word[j];
      } else {
        if (cnt > 0) {
          temp[cnt] = '\0';
          numbers[idx++] = atoi(temp);
          cnt = 0;
        }
      }
    }
    
    if (cnt > 0) {
      temp[cnt] = '\0';
      numbers[idx++] = atoi(temp);
    }
  }
  qsort(numbers, idx, sizeof(int), compare);
  
  for (int i=0; i<idx; i++) {
    printf("%d\n", numbers[i]);
  }
  
  return 0;
}
 */
