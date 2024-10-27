#include <stdio.h>

void hanoiTop(int n, int from, int to, int aux) {
  if (n==1) {
    printf("%d %d\n", from, to);
    return;
  }
  
  hanoiTop(n-1, from, aux, to);
  printf("%d %d\n", from, to);
  hanoiTop(n-1, aux, to, from);
}

int main() {
  int N;
  scanf("%d", &N);
  
  printf("%d\n", (1 << N) - 1);
  if (N<=20) {
    hanoiTop(N, 1, 3, 2);
  }
  return 0;
}

/*
  https://www.acmicpc.net/problem/1914

  하노이탑의 최소 이동횟수는 2^N-1 (점화식)
    1
    2
    3
    ===================
    2
    3                 1
    ===================
    3        2        1
    ===================
             1
    3        2
    ===================
             1
             2        3
    ===================
    1        2        3
    ===================
                      2
    1                 3
    ===================
                      1
                      2
                      3
    ===================

  그래 여기까지는 알겠지만?? 문제는 2^N-1 을 어떻게 출력할거냐가 문제였다...ㅋ..
  128비트로 출력해야된다고 한다; 실화냐;
*/

/*   정답코드 https://wonsjung.tistory.com/15
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int n;
// Big integer
// 정수형으로 나타낼 수 있는 최대크기보다 더 큰 수를 나타내고자 할 때 사용하는 방법으로 문자열을 이용하여야한다.
void Power(int x, int n, char arr[]) {
	// x의 n승을 arr이라는 문자열 배열에 저장하고자 한다
	int temp = 0, last = 0, cnt = 0;
	arr[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= last; j++) {
			temp = arr[j] * x;
			if (temp >= 10) {
				arr[j] = temp % 10 + cnt;
				cnt = temp / 10;

				if (j == last) {
					arr[++last] = cnt;
					cnt = 0;
					break;
				}
			}
			else {
				arr[j] = temp + cnt;
				cnt = 0;
			}
		}
	}
	arr[0] -= 1;
	for (int i = last; i >= 0; i--) printf("%d", arr[i]);
	printf("\n");
}

void func(int n, int a, int b) {
	if (n == 1) {
		printf("%d %d\n", a, b);
		return;
	}

	func(n - 1, a, 6 - a- b);
	printf("%d %d\n", a, b);
	func(n - 1, 6 - a - b, b);
}

int main() {
	char result[35];

	scanf("%d", &n);
	Power(2, n, result);

	if (n > 20) return 0;
	func(n, 1, 3);

	return 0;
}
*/
