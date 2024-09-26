문제 설명

초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

```
제한사항
prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
prices의 길이는 2 이상 100,000 이하입니다.
```

```
입출력 예
prices	        return
[1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]
```

```
입출력 예 설명
1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.
2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.
3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.
5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.
```

***

풀이 과정
===
```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int prices[], size_t prices_len) {
    // 같은 길이를 가진 answer 가 필요하니 prices_len 만큼 동적할당 한다
    // 마지막 번지는 가격이 유지될 수 있는 초가 없기 때문에 calloc으로 동적할당 함
    int* answer = (int*)calloc(prices_len, sizeof(int));
    for (int i=0; i<prices_len; i++) {
        for (int j=i+1; j<prices_len; j++) {
            // prices[0]번지부터 비교하기 때문에
            // j의 시작점은 prices[1]번지 부터 비교해야 한다
            // 가격이 한 번이라도 유지되면 그 시점에서는 이미 1초 동안 유지된 것으로 간주하므로 answer은 반복문을 타는순간 +1 한다
            answer[i]++;
            if (prices[i] > prices[j]) {
                // 가격이 떨어지면 break
                break;;
            }
        }
    }
    
    return answer;
}
```

***

##### 한줄평
* 이렇게 푸는게 맞나싶다.. 일단 돌아는 감
* 시간복잡도가 O(N^2) 인데 왜 풀리지...?
* 스택으로 푸는 방법을 생각해보자