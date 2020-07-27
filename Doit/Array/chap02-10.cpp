/* 1000 이하의 소수를 나열한다. */
#include <stdio.h>

int main()
{
	int i, n;
	int prime[500];
	int ptr = 0;
	unsigned long counter = 0;
	prime[ptr++] = 2;
	for (n = 3; n <= 1000; n += 2) // 홀수만 대상으로
	{
		for (i = 1; i < ptr; ++i)
		{
			++counter;
			if (n % prime[i] == 0)
				break;
		}

		if (ptr == i)
			prime[ptr++] = n;
	}
	for (i = 0; i < ptr; ++i)
		printf("%d\n", prime[i]);
	printf("나눗셈ㅇ을 실행한 횟수 : %d\n", counter);
	return 0;
}