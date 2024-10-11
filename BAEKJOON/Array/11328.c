// https://www.acmicpc.net/problem/11328
// C99

#include <stdio.h>
#include <string.h>

int main() {
  int N;
  scanf("%d", &N);

  char A[1001];
  char B[1001];

  for (int i=0; i<N; i++) {
    int checkA[26] = {0};
    int checkB[26] = {0};
    
    scanf("%s %s", A, B);
    
    if (strlen(A) != strlen(B)) {
      printf("Impossible\n");
      continue;
    }
    
    for (int j=0; A[j]!='\0'; j++) {
      checkA[A[j] - 'a']++;
    }
    
    for (int j=0; B[j]!='\0'; j++) {
      checkB[B[j] - 'a']++;
    }
    
    int possible = 1;
    for (int j=0; j<26; j++) {
      if (checkA[j] != checkB[j]) {
        possible = 0;
        break;
      }
    }
  
    if (possible) {
      printf("Possible\n");
    } else {
      printf("Impossible\n");
    }
  }

  return 0;
}

/*
  입력된 문자열 무작위 재배열하여 새로운 문자열을 만들어 내는 것이므로,
  문자열 길이가 같아야하고, 알파벳 빈도수가 같아야 함
*/
