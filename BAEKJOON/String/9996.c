// https://www.acmicpc.net/problem/9996
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

int main() {
  int N;
  scanf("%d", &N);
  
  char pattern[MAX_LEN];
  scanf("%s", pattern);
  
  int patt_len = strlen(pattern);
  char diff_patt_left[MAX_LEN];
  int left_cnt = 0;
  char diff_patt_right[MAX_LEN];
  int right_cnt = 0;
  
  int flag = 0;
  for (int i=0; i<patt_len; i++) {
    if (pattern[i] != '*' && flag == 0) {
      diff_patt_left[left_cnt++] = pattern[i];
    } else if (pattern[i] == '*') {
      flag = 1;
    } else if (pattern[i] != '*' && flag == 1) {
      diff_patt_right[right_cnt++] = pattern[i];
    }
  }
  
  diff_patt_left[left_cnt] = '\0';
  diff_patt_right[right_cnt] = '\0';
  
  for (int i=0; i<N; i++) {
    char word[MAX_LEN];
    scanf("%s", word);
    
    int len = strlen(word);
    
    if (len < left_cnt + right_cnt) {
      printf("NE\n");
      continue;
    }
    
    if (strncmp(word, diff_patt_left, left_cnt) == 0 &&
        strncmp(&word[len - right_cnt], diff_patt_right, right_cnt) == 0) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }
  
  return 0;
}

/*
  생각 못한 부분은..
  strncmp의 마지막 인덱스 계산에서, word[len - right_cnt] 이 부분이
  혹시라도 right_cnt가 0일 때 인덱스 계산 오류가 발생할 수 있으므로 위에서 미리 거르는 if문을 추가해야 함
  만약 word의 len이 패턴의 합보다 작으면 continue 해줘야 함
 */
