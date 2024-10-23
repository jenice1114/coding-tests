// https://www.acmicpc.net/problem/5648
// C11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void* a, const void* b) {
  long long A = *(long long*)a;
  long long B = *(long long*)b;
  
  if (A > B) return 1;
  else if (A < B) return -1;
  else return 0;
}

long long reverse(char str[]) {
  int start = 0;
  int end = strlen(str) - 1;
  
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
  
  int i = 0;
  while (str[i] == '0') {
    i++;
  }
  if (str[i] != '\0') {
    // int 자료형일땐 atoi 가능하나
    // 현재 최대 12자리이므로 long long 일땐 atoll 사용
    return atoll(&str[i]);
  } else {
    return 0;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  long long* num = (long long*)malloc(n * sizeof(long long));
  char str[13];
  for (int i=0; i<n; i++) {
    scanf("%12s", str);
    num[i] = reverse(str);
  }
  
  qsort(num, n, sizeof(long long), compare);
  
  for (int i=0; i<n; i++) {
    printf("%lld\n", num[i]);
  }
  
  free(num);
  
  return 0;
}
