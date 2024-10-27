// https://softeer.ai/practice/6283
// C11

#include <stdio.h>

int main(void) {
  int DCT[8];
  for (int i = 0; i < 8; i++) {
    scanf("%d", &DCT[i]);
  }

  int ascending = 1, descending = 1;
  for (int i = 0; i < 7; i++) {
    if (DCT[i] < DCT[i + 1]) {
      descending = 0;
    } else if (DCT[i] > DCT[i + 1]) {
      ascending = 0;
    }
  }

  if (ascending == 1) {
    printf("ascending");
  } else if (descending == 1) {
    printf("descending");
  } else {
    printf("mixed");
  }

  return 0;
}
