// https://softeer.ai/practice/6268
// C11

#include <stdio.h>
#include <string.h>

// 숫자 0~9의 7세그먼트 디스플레이 비트 패턴 (0~9)
const int segments[10] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x72, 0x7F, 0x7B};

int countFlips(int a, int b) {
  int xor_result;
  if (a == 22 && b == 22) {
    return 0;
  } else if (a == 22 && b != 22) {
    xor_result = 0x00 ^ segments[b];
  } else if (a != 22 && b == 22) {
    xor_result = segments[a] ^ 0x00;
  } else {
    xor_result = segments[a] ^ segments[b];
  }
  
  int flips = 0;
  while (xor_result) {
    flips += xor_result & 1;  // 마지막 비트가 1인지 확인 (바뀐 부분)
    xor_result >>= 1;         // 오른쪽으로 한 비트씩 밀어 바뀐 부분 카운트
  }

  return flips;
}

// 숫자의 길이가 맞지 않으면 0으로 패딩하는 함수
void padWithZeros(char* str, char* paddedStr, int len) {
  int padding = 5 - len;  // 5자리로 맞추기 위해 필요한 패딩 길이
  for (int i = 0; i < padding; i++) {
    paddedStr[i] = 'F';  // 앞부분을 F으로 패딩 F:22 22일때 offset적용
  }
  // 원래 문자열 복사
  for (int i = 0; i < len; i++) {
    paddedStr[padding + i] = str[i];
  }
  paddedStr[5] = '\0';  // 문자열 끝에 null 추가
}

int main() {
  int T;
  scanf("%d", &T);  // 테스트 케이스 개수 입력

  for (int t = 0; t < T; t++) {
    char A[6], B[6];  // 최대 5자리 숫자, '\0' 포함해서 6자리
    char paddedA[6] = {0}, paddedB[6] = {0};  // 패딩된 문자열 저장할 배열
    scanf("%s %s", A, B);

    int lenA = strlen(A);
    int lenB = strlen(B);

    // 문자열 A와 B를 5자리로 패딩
    padWithZeros(A, paddedA, lenA);
    padWithZeros(B, paddedB, lenB);

    int totalFlips = 0;

    // 5자리 숫자 각각을 비교
    for (int i = 0; i < 5; i++) {
      int digitA = paddedA[i] - '0';
      int digitB = paddedB[i] - '0';
      
      totalFlips += countFlips(digitA, digitB);
    }

    // 결과 출력
    printf("%d\n", totalFlips);
  }

  return 0;
}
