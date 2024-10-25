// https://www.acmicpc.net/problem/1543
// C11

#include <stdio.h>
#include <string.h>

#define MAX 2501

int main(){
	char arr[MAX];
	char str[51];
	int cnt=0, i=0, pos=0, temp=0;

	gets(arr);
	gets(str);

	while(i < strlen(arr)){
		if(arr[i++] != str[pos++])	{
			pos=0;
			temp++;
			i = temp;
		} else if(pos == strlen(str)){
			cnt++;
			pos = 0;
			temp = i;
		}
	}

	printf("%d", cnt);
	return 0;
}

/*
  못 풀었음.. 내꺼는 시간초과나오고 계속 틀렸다나오는데
  위의 코드는 찾아봄..

  문제에 공백포함이기에 gets(fgets가 더 안전하긴 함)로 받고 arr의 인덱스 길이만큼 반복한다
    1. arr[i] str[pos] 가 다르다면 초기화, 같다면 지나감 (i, pos는 더하기가 된 상태)
    2. pos가 str 길이와 같다면 count를 증가시킴
 */
