/* 1000 ÀÌÇÏÀÇ ¼Ò¼ö¸¦ ±¸ÇÑ´Ù. */
#include <stdio.h>

int main()
{
	int i, n;
	int prime[500];
	int ptr = 0;
	unsigned long counter = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (n = 5; n <= 1000; n += 2)
	{
		int flag = 0;
		for (i = 1; ++counter, prime[i] * prime[i] <= n; ++i)
		{
			++counter;
			if (n % prime[i] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			prime[ptr++] = n;
	}
	for (i = 0; i < ptr; ++i)
		printf("%d\n", prime[i]);
	printf("°ö¼À°ú ³ª´°¼ÀÀ» ½ÇÇàÇÑ È½¼ö : %lu\n", counter);
	return 0;
}