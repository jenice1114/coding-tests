// https://softeer.ai/practice/7703
// C11

#include <stdio.h>
#include <string.h>

int main(void) {
  int num;
  scanf("%d", &num);

  char S[1000001];
  char T[1000001];
  char result[500001];
  int resultIndex = 0;

  for (int i = 0; i < num; i++) {
    scanf("%s %s", S, T);
    
    int len = strlen(S);
    int idx = 0;
    for (int j = 0; j < len; j++) {
      if (S[j] == 'x' || S[j] == 'X') {
        idx = j;
        break;
      }
    }

    char ch = T[idx];
    if (ch >= 'a' && ch <= 'z') {
      // 대문자로 변환
      ch -= 32;
    }
    result[resultIndex++] = ch;
  }
  
  result[resultIndex] = '\0';
  
  printf("%s\n", result);
  
  return 0;
}
