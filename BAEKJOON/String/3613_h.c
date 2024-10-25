// https://www.acmicpc.net/problem/3613
// C11

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char s[101];

// 입력된 문자열의 형식을 확인하는 함수
int getcode() {
  int len = strlen(s);
  
  // 첫 문자 또는 마지막 문자가 '_' 이거나 첫 문자가 대문자이면 잘못된 형식
  if (s[0] == '_' || s[len - 1] == '_' || isupper(s[0])) return 0;

  int is_ub = 0, is_upper = 0;
  for (int i = 1; i < len; i++) {
    if (s[i] == '_') {
      if (s[i - 1] == '_') return 0;  // 연속된 '_'가 있으면 잘못된 형식
      is_ub = 1;
    }
    if (isupper(s[i])) is_upper = 1;
  }
  
  // '_'와 대문자가 혼합된 경우, 또는 C++ 형식, Java 형식으로 분기
  if (is_ub && is_upper) return 0;
  else if (is_ub) return 1;
  return 2;
}

// C++ 형식 -> Java 형식으로 변환
void ctoj() {
  int is_nxt_upper = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '_') {
      is_nxt_upper = 1;
      continue;
    }
    if (is_nxt_upper) {
      putchar(toupper(s[i]));
    } else {
      putchar(s[i]);
    }
    is_nxt_upper = 0;
  }
}

// Java 형식 -> C++ 형식으로 변환
void jtoc() {
  for (int i = 0; s[i] != '\0'; i++) {
    if (isupper(s[i])) putchar('_');
    putchar(tolower(s[i]));
  }
}

int main() {
  scanf("%100s", s);  // 최대 100자까지 입력받도록 제한

  int code = getcode(); // code = 0: none, 1: C++ 형식, 2: Java 형식

  if (code == 0) {
    printf("Error!");
  } else if (code == 1) {
    ctoj();
  } else {
    jtoc();
  }

  return 0;
}

/*
  일단 못 풀었다...
  변경하는것까진 어찌저찌했는데
  Error일때의 처리가 미흡해서 계속 틀림(ㅠㅠ)
  그래서 chatgpt한테 물어봤다

  Error가 되는 조건은
  1. 첫 문자 또는 마지막 문자가 '_' 이거나, '_'가 연속되면 Error
  2. 첫문자가 대문자면 Error

  그리고 뭔가 변경된 문자열을 result 배열에 담아 출력하려고했는데
  putchar써서 바로 출력하는게 더 편한 것 같다

  putchar: 단일 문자 출력
 */
