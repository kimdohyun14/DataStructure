/* 1000 이하의 소수를 나열한다. */
#include <stdio.h>

int main()
{
	int i, n;
	unsigned long counter = 0;
	for (n = 2; n <= 1000; ++n)
	{
		for (i = 2; i < n; ++i)
		{
			++counter;
			if (n % i == 0)
				break;
		}

		if (n == i)
			printf("%d\n", n);
	}
	printf("나눗셈을 실행한 횟수 : %lu\n", counter);
	return 0;
}