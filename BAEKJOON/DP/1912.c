// https://www.acmicpc.net/problem/1912
// C11

#include <stdio.h>

#define MAX_LEN 100001

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int N;
  scanf("%d", &N);
  
  int num[N];
  for (int i=0; i<N; i++) {
    scanf("%d", &num[i]);
  }
  
  int curSum = num[0];
  int maxSum = num[0];
  for (int i=1; i<N; i++) {
    curSum = max(num[i], num[i] + curSum);
    maxSum = max(curSum, maxSum);
  }
  printf("%d", maxSum);
  
  return 0;
}

/*
  Kadane's Algorithm(카데인 알고리즘) 사용
  연속된 부분 배열의 최대 합을 효율적으로 구하는 알고리즘으로 DP의 일종
  배열을 한 번 순회하면서 현재 위치에서의 최대 연속 부분합을 계산하고
  이를 기반으로 전체 배열에서의 최대 연속 부분합을 갱신



  만약 그럼 문제가 인덱스 까지 출력하라는 문제라면?

  int curSum = num[0];
  int maxSum = num[0];
  int start = 0;  // 최대합을 만드는 부분 배열의 시작 인덱스
  int end = 0;    // 최대합을 만드는 부분 배열의 끝 인덱스
  int temp_start = 0; // 임시 시작 인덱스
  for (int i=1; i<N; i++) {
    // 이전 연속합에 현재 값을 더할지, 새로운 부분합을 시작할지 결정
    if (num[i] > curSum + num[i]) {
        curSum = num[i];
        temp_start = i;  // 새로운 시작점 업데이트
    } else {
        curSum += num[i];
    }

    // 현재까지의 최대합을 갱신할 경우
    if (curSum > maxSum) {
      maxSum = curSum;
      start = temp_start;  // 현재 최대합을 만드는 시작 인덱스
      end = i;  // 현재 최대합을 만드는 끝 인덱스
    }
  }
  printf("%d", maxSum);
*/
