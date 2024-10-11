// https://www.acmicpc.net/problem/1919
// C99

#include <stdio.h>

int main() {
  char A[1001], B[1001];
  scanf("%s %s", A, B);
  
  int chkA[26] = {0,};
  for (int i=0; A[i]!='\0'; i++) {
    chkA[A[i] - 'a']++;
  }
  int chkB[26] = {0,};
  for (int i=0; B[i]!='\0'; i++) {
    chkB[B[i] - 'a']++;
  }
  
  int result = 0;
  for (int i=0; i<26; i++) {
    if (chkA[i] != chkB[i]) {
      result += abs(chkA[i] - chkB[i]);
    }
  }
  printf("%d", result);
  
  return 0;
}

/*
  문자열 길이가 같아야하고, 빈도수가 같아야 함
  위의 조건이 다를 때 result ++
*/
