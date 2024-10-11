// https://www.acmicpc.net/problem/10808
// C99

#include <stdio.h>

int main() {
  int arr[26] = {0, };
  char word[101];
  scanf("%s", word);
  
  for (int i=0; word[i]!='\0'; i++) {
    arr[word[i] - 'a']++;
  }
  
  for (int i=0; i<26; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}

/*
  알파벳 개수는 26개 (a-z)
*/
