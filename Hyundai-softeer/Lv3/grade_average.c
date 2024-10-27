// https://softeer.ai/practice/6294
// C11

#include <stdio.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int grade[N+1];
  int prefix_sum[N+1];
  prefix_sum[0] = 0;
  for (int i=1; i<=N; i++) {
    scanf("%d", &grade[i]);
    prefix_sum[i] = prefix_sum[i-1] + grade[i];
  }

  for (int i=0; i<K; i++) {
    int A,B;
    scanf("%d %d", &A, &B);

    int sum = prefix_sum[B] - prefix_sum[A-1];
    float average = (float)sum / (B-A+1);

    printf("%.2f\n", average);
  }

  return 0;
}

/*
  누적합으로 최적화가 필요한 문제
  아래는 최적화 전 내 코드

#include <stdio.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int grade[N+1];
  for (int i=1; i<=N; i++) {
    scanf("%d", &grade[i]);
  }

  for (int i=0; i<K; i++) {
    int A,B;
    scanf("%d %d", &A, &B);

    int sum = 0;
    int temp = A;
    while (temp <= B) {
      sum += grade[temp];
      temp++;
    }
    float average = (float)sum / (B-A+1);

    printf("%.2f\n", average);
  }

  return 0;
}

  이해 안 됐던 부분 이해하기
  int sum = prefix_sum[B] - prefix_sum[A-1];
  
  성적이 [10, 20, 30, 40, 50] 일 때,

  prefix_sum 배열:
  prefix_sum[0] = 0
  prefix_sum[1] = 10
  prefix_sum[2] = 10 + 20 = 30
  prefix_sum[3] = 10 + 20 + 30 = 60
  prefix_sum[4] = 10 + 20 + 30 + 40 = 100
  prefix_sum[5] = 10 + 20 + 30 + 40 + 50 = 150

  구간 [2, 4]의 합:
  prefix_sum[4] = 100은 1 ~ 4번까지의 합이므로,
  prefix_sum[1] = 10인 1번을 제외

  따라서, 구간 [2, 4]의 합은 prefix_sum[4] - prefix_sum[1] = 100 - 10 = 90
 */
