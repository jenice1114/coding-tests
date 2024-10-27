// https://softeer.ai/practice/9498
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char S[200001];
  scanf("%s", &S);

  int len = strlen(S);
  char* formula = (char*)malloc(500001 * sizeof(char));
  int count = 0;

  for (int i = 0; i < len; i++) {
    // 열린 괄호라면
    if (S[i] == '(') {
      formula[count++] = S[i];
    } else { // 닫힌 괄호라면
      formula[count++] = '1';
      formula[count++] = S[i];
      if (i < len - 1) {
        formula[count++] = '+';
      }
    }
  }

  // 문자열 끝에 NULL 문자 추가
  formula[count] = '\0';
  printf("%s\n", formula);
  
  free(formula); // 동적 메모리 해제
  return 0;
}
