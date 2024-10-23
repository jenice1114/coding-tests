// https://www.acmicpc.net/problem/1654
// C11

#include <stdio.h>

int K, N;
long long lan[10000];

int count_lan(long long length) {
  int count = 0;
  for (int i = 0; i < K; i++) {
    count += lan[i] / length;
  }
  return count;
}

int main() {
  scanf("%d %d", &K, &N);
  long long max_len = 0;
  
  for (int i = 0; i < K; i++) {
    scanf("%lld", &lan[i]);
    if (lan[i] > max_len) {
      max_len = lan[i]; // 가장 긴 랜선의 길이 저장
    }
  }

  long long left = 1, right = max_len;
  long long answer = 0;

  // 이진 탐색 시작
  while (left <= right) {
    long long mid = (left + right) / 2;
    int count = count_lan(mid);

    if (count >= N) { // 만들 수 있는 랜선 개수가 충분하면
      answer = mid; // 가능한 길이로 저장
      left = mid + 1; // 더 긴 길이로 시도
    } else {
      right = mid - 1; // 부족하면 더 짧은 길이로 시도
    }
  }

  printf("%lld\n", answer);
  return 0;
}

/*
  이것도 못 풀었다.. 일단 longlong에서 터짐ㅋㅋ
  
  문제 이해로는
  이미 K개의 랜선을 가지고 있으며, 이 랜선들을 잘라서 N개의 랜선을 만드려고 함
  각 랜선의 길이가 다를 수 있으므로, 같은 길이의 랜선들을 만들기 위해서 최대의 길이를 찾아야 함

  1. 이진 탐색의 범위 설정
  랜선의 최대 길이는 802 (가장 긴 랜선의 길이) 최솟값은 1로 설정
  따라서 이진 탐색 범위는 1부터 802까지

  2. 중간 길이를 기준으로 자르기
  이진 탐색을 사용하여 중간 길이로 랜선을 자를 때, 랜선을 몇 개 만들 수 있는지 계산

  최대 길이 mid = (1 + 802) / 2 = 401:
  802을 401로 자르면: 2개
  743을 401로 자르면: 1개
  457을 401로 자르면: 1개
  539를 401로 자르면: 1개
  총 count = 5 (N=11이기 때문에 부족)

  최대 길이 mid = (1 + 400) / 2 = 200:
  802을 200으로 자르면: 4개
  743을 200으로 자르면: 3개
  457을 200으로 자르면: 2개
  539를 200으로 자르면: 2개
  총 count = 11
  
  더 긴 랜선이 가능한지 확인하기 위해 값만 업데이트하고 계속 탐색

  최대 길이 mid = 201:
  802을 201로 자르면: 3개
  743을 201로 자르면: 3개
  457을 201로 자르면: 2개
  539를 201로 자르면: 2개
  총 count = 10

  따라서, 200이 최적의 값
*/
