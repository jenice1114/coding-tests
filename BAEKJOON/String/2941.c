// https://www.acmicpc.net/problem/2941
// C11

#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

const char* croatia[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
  char word[MAX_LEN];
  scanf("%s", word);
  
  int result = 0;
  for (int i=0; word[i]!='\0'; i++) {
    int flag = 0;
    for (int j=0; j<8; j++) {
      int len = strlen(croatia[j]);
      if (strncmp(&word[i], croatia[j], len) == 0) {
        result++;
        i += len -1;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      result++;
    }
  }
  printf("%d", result);
  
  return 0;
}

/*
  100 이하의 비교 문자기 때문에 strncmp가 가능하지 않았나?
 */
