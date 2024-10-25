// https://www.acmicpc.net/problem/9536
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 101
#define MAX 10001

int main() {
  int tc;
  scanf("%d", &tc);
  getchar();
  
  while (tc--) {
    char sound[MAX];
    fgets(sound, sizeof(sound), stdin);
    
    char record[MAX_LEN][MAX_LEN];
    int cnt = 0;
    char* token = strtok(sound, " \n");
    while (token != NULL) {
      strcpy(record[cnt++], token);
      token = strtok(NULL, " \n");
    }
    
    char animal[MAX_LEN][MAX_LEN];
    int ani_cnt = 0;
    char ani_sound[MAX];
    while (1) {
      fgets(ani_sound, sizeof(ani_sound), stdin);
      if (strcmp(ani_sound, "what does the fox say?\n") == 0) {
        break;
      }
        
      token = strtok(ani_sound, " ");
      token = strtok(NULL, " ");
      token = strtok(NULL, " \n");
      strcpy(animal[ani_cnt++], token);
    }
    
    for (int i=0; i<cnt; i++) {
      int fox_flag = 1;
      for (int j=0; j<ani_cnt; j++) {
        if (strcmp(record[i], animal[j]) == 0) {
          fox_flag = 0;
          break;
        }
      }
      if (fox_flag) {
        printf("%s ", record[i]);
      }
    }
  }
  return 0;
}

/*
  scanf 입력 받은 후 fgets 사용 시 scanf가 남긴 개행 문자 때문에 fgets가 빈 줄을 읽음
  이를 방지하려면 getchar()를 사용해 버퍼에 남아있는 개행 문자를 제거
  또는 scanf 사용 시 %*c를 붙여 개행문자를 무시하라는 로직을 추가하도록 하자.
 */
