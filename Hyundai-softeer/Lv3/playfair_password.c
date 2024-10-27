// https://softeer.ai/practice/6255
// C11

#include <stdio.h>
#include <string.h>

int main() {
  char msg[1001];
  scanf("%s", msg);
  char key[101];
  scanf("%s", key);

  // 1. Key 중복 제거 및 5x5 표 생성
  int key_len = strlen(key);
  char new_key[101];
  int key_cnt = 0;
  int alphabet[26] = {0,};

  for (int i = 0; i < key_len; i++) {
    if (alphabet[key[i] - 'A'] == 0) {
      alphabet[key[i] - 'A'] = 1;
      new_key[key_cnt++] = key[i];
    }
  }
  new_key[key_cnt] = '\0';

  // 5x5 암호화 표 생성
  char map[5][5];
  key_cnt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (new_key[key_cnt] != '\0') {
        map[i][j] = new_key[key_cnt++];
      } else {
        for (int k = 0; k < 26; k++) {
          if (alphabet[k] == 0 && k != ('J' - 'A')) {  // 'J' 제외
            alphabet[k] = 1;
            map[i][j] = 'A' + k;
            break;
          }
        }
      }
    }
  }

  // 2. 메시지 두 글자씩 쌍으로 나누기
  int msg_len = strlen(msg);
  char new_msg[2002];  // 최대 메시지 크기 두 배
  int msg_cnt = 0;
  for (int i = 0; i < msg_len; i += 2) {
    new_msg[msg_cnt++] = msg[i];
    if (i + 1 < msg_len) {
      if (msg[i] == msg[i + 1]) {  // 같은 글자 쌍 처리
        new_msg[msg_cnt++] = (msg[i] == 'X') ? 'Q' : 'X';
        i--;  // 다음 반복에서 현재 글자와 다시 쌍을 이룸
      } else {
        new_msg[msg_cnt++] = msg[i + 1];
      }
    } else {  // 홀수 길이 처리
      new_msg[msg_cnt++] = 'X';
    }
  }
  new_msg[msg_cnt] = '\0';

  // 3. 암호화 수행
  char result_msg[2002];
  int rs_cnt = 0;

  for (int i = 0; i < msg_cnt; i += 2) {
    char first = new_msg[i];
    char second = new_msg[i + 1];
    int x1, y1, x2, y2;

    // 두 글자의 위치 찾기
    for (int r = 0; r < 5; r++) {
      for (int c = 0; c < 5; c++) {
        if (map[r][c] == first) {
          x1 = r;
          y1 = c;
        }
        if (map[r][c] == second) {
          x2 = r;
          y2 = c;
        }
      }
    }

    // 3-1. 같은 행에 있는 경우 오른쪽 글자 사용
    if (x1 == x2) {
      result_msg[rs_cnt++] = map[x1][(y1 + 1) % 5];
      result_msg[rs_cnt++] = map[x2][(y2 + 1) % 5];
    }
    // 3-2. 같은 열에 있는 경우 아래쪽 글자 사용
    else if (y1 == y2) {
      result_msg[rs_cnt++] = map[(x1 + 1) % 5][y1];
      result_msg[rs_cnt++] = map[(x2 + 1) % 5][y2];
    }
    // 3-3. 행과 열이 다른 경우 열을 서로 교환
    else {
      result_msg[rs_cnt++] = map[x1][y2];
      result_msg[rs_cnt++] = map[x2][y1];
    }
  }
  result_msg[rs_cnt] = '\0';  // 문자열 종료

  // 결과 출력
  printf("%s\n", result_msg);

  return 0;
}

/* 여기까지 구현하다가 포기한 코드;
#include <stdio.h>
#include <string.h>

int main() {
  char msg[1001];
  scanf("%s", msg);
  char key[101];
  scanf("%s", key);

  // 1. Key 중복 제거
  int key_len = strlen(key);
  char new_key[101];
  int key_cnt = 0;
  int alphbet[26] = {0,};
  for (int i=0; i<key_len; i++) {
    if (alphbet[key[i] - 'A'] == 0) {
      alphbet[key[i] - 'A'] = 1;
      new_key[key_cnt++] = key[i];
    }
  }
  new_key[key_cnt] = '\0';

  // 2. Key 5*5에 넣기
  char map[5][5];
  key_cnt = 0;
  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++) {
      if (new_key[key_cnt] != '\0') {
        map[i][j] = new_key[key_cnt++];
      } else {
        for (int k=0; k<26; k++) {
          if (alphbet[k] == 0 && k != 9) {
            alphbet[k] = 1;
            map[i][j] = k + 'A';
            break;
          }
        }
      }
    }
  }

  // 3. Message 나누기
  int msg_len = strlen(msg);
  char new_msg[202];
  int msg_cnt = 0;
  for (int i=0; i<msg_len; i+=2) {
    if (i+1 < msg_len) {
      if (msg[i] == msg[i+1] && msg[i] != 'X') {
        new_msg[msg_cnt++] = msg[i];
        new_msg[msg_cnt++] = 'X';
        new_msg[msg_cnt++] = msg[i+1];
      } else if (msg[i] == msg[i+1] && msg[i] == 'X') {
        new_msg[msg_cnt++] = msg[i];
        new_msg[msg_cnt++] = 'Q';
        new_msg[msg_cnt++] = msg[i+1];
      } else {
        new_msg[msg_cnt++] = msg[i];
        new_msg[msg_cnt++] = msg[i+1];
      }
    }
  }

  if (msg_cnt-1 % 2 != 0) {
    new_msg[msg_cnt++] = 'X';
  }
  new_msg[msg_cnt] = '\0';

  // result 조건 3가지
  char result_msg[202];
  int rs_cnt = 0;
  for (int i=0; i<4; i+=2) {

    char x,y;
    int check = 0;
    int flag_4 = 0;
    // 4. 두글자가 표에서 같은 행에 존재 시, 오른쪽 한칸이동한 칸에 적힌 글자로 암호화
    for (int j=0; j<5; j++) {
      for (int k=0; k<5; k++) {
        if (map[j][k] == new_msg[i]) {
          x = map[j][(k+1) % 5];
          check++;
        } else if (map[j][k] == new_msg[i+1]) {
          y = map[j][(k+1) % 5];
          check++;
        }
      }
      if (check >= 2) {
        result_msg[rs_cnt++] = x;
        result_msg[rs_cnt++] = y;
        flag_4 = 1;
        break;
      }
    }
    if (flag_4) continue;

    check = 0;
    int flag_5 = 0;
    // 5. 두 글자가 표에서 같은 열에 존재 시, 아래쪽으로 한 칸 이동한 칸에 적힌 글자로 암호화
    for (int k=0; k<5; k++) {
      for (int j=0; j<5; j++) {
        if (map[j][k] == new_msg[i]) {
          x = map[(j+1) % 5][k];
          check++;
        } else if (map[j][k] == new_msg[i+1]) {
          y = map[(j+1) % 5][k];
          check++;
        }
      }
      if (check >= 2) {
        result_msg[rs_cnt++] = x;
        result_msg[rs_cnt++] = y;
        flag_5 = 1;
        break;
      }
    }
    if (flag_5) continue;
  }

  printf("%s", result_msg);
  
  return 0;
}
*/
