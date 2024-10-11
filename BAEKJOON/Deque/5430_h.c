// https://www.acmicpc.net/problem/5430
// C11

#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) {int t = a; a = b; b = t;}
int	t, q[100001], n, first, last;
char	p[100001], nums[400001];

int	D()
{
	if (first == last)
	{
		printf("error\n");
		return (1);
	}
	if (last < first)
		first--;
	else
		first++;
	return (0);
}

void R()
{
	swap(last, first);
}

void push(int num)
{
	q[last++] = num;
}

void print()
{
	int	i;
	int	j;

	if (first==last)
	{
		printf("[]\n");
		return ;
	}
	printf("[");
	i = first;
	j = last;
	if (i > j)
	{
		i--;
		for(; i > j; i--)
			printf("%d,", q[i]);
	}
	else
	{
		for(; i < j - 1; i++)
			printf("%d,", q[i]);
	}
	printf("%d]\n", q[i]);
}

int	main(void)
{
	int	err_flag;

	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		first = 0;
		last = 0;
		err_flag = 0;
		scanf("%s %d %s", p, &n, nums);
		for(int j = 1; nums[j]; j++)
		{
			if ('0' <= nums[j] && nums[j] <= '9')
			{
				push(atoi(&nums[j]));
				while ('0' <= nums[j] && nums[j] <= '9')
					j++;
			}
		}
		for (int j = 0; p[j]; j++)
		{
			if (p[j] == 'D')
			{
				if (D())
				{
					err_flag = 1;
					break ;
				}
			}
			else
				R();
		}
		if (!err_flag)
			print();
	}
}

/*
	못품... 남의 코드 일단 박아놨는데 안풀림 내코드는 ㅠㅠ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100001

typedef struct Dque {
    int dq[MAX_LEN];
    int front;
    int rear;
    int size;
    int is_reversed;
} Dque;

Dque* InitDque() {
    Dque* dq = (Dque*)malloc(sizeof(Dque));
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
    dq->is_reversed = 0;
    return dq;
}

void push(Dque* dq, int x) {
    dq->dq[dq->rear] = x;
    dq->rear = (dq->rear + 1) % MAX_LEN;
    dq->size++;
}

int pop_D(Dque* dq) {
    if (dq->size == 0) return 0;
    
    if (dq->is_reversed) {
        dq->rear = (dq->rear-1 + MAX_LEN) % MAX_LEN;
    } else {
        dq->front = (dq->front+1) % MAX_LEN;
    }
    dq->size--;
    return 1;
}

void turn_R(Dque* dq) {
    dq->is_reversed = !dq->is_reversed;
}

void print_result(Dque* dq) {
    if (dq->size == 0) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    if (dq->is_reversed) {
        for (int i=dq->rear-1; i!=(dq->front - 1 + MAX_LEN) % MAX_LEN; i=(i-1+MAX_LEN) % MAX_LEN) {
            printf("%d", dq->dq[i]);
            if (i != (dq->front - 1 + MAX_LEN) % MAX_LEN) {
                printf(",");
            }
        }
    } else {
        for (int i=dq->front; i!=dq->rear; i=(i+1) % MAX_LEN) {
            printf("%d", dq->dq[i]);
            if (i != (dq->rear - 1 + MAX_LEN) % MAX_LEN) {
                printf(",");
            }
        }
    }
    printf("]\n");
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        char func[100001];
        scanf("%s", func);
        
        int len;
        scanf("%d", &len);

        Dque* dq = InitDque();
        
        char input[500001];
        scanf("%s", input);
        
        // 배열 파싱
        int temp = 0;
        int num_start = 0;
        for (int i=0; input[i]!='\0'; i++) {
            if (input[i] >= '0' && input[i] <= '9') {
                temp = temp * 10 + (input[i] - '0');
                num_start = 1;
            } else if (input[i] == ',' || input[i] == ']') {
                if (num_start) {
                    push(dq, temp);
                    temp = 0;
                    num_start = 0;
                }
            }
        }
        
        int is_error = 0;
        for (int i=0; func[i]!='\0'; i++) {
            if (func[i] == 'R') {
                turn_R(dq);
            } else if (func[i] == 'D') {
                if (!pop_D(dq)) {
                    is_error = 1;
                    break;
                }
            }
        }
        
        if (is_error) {
            printf("error\n");
        } else {
            print_result(dq);
        }
        
        free(dq);
    }
    
    return 0;
}
*/
