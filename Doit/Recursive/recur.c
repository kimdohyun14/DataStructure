/* 재귀에 대해 깊이 이해하기 위한 재귀 함수 */
#include <stdio.h>

void recur(int n)
{
	if (n > 0)
	{
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

int main()
{
	int x;
	printf("정수를 입력 : ");
	scanf_s("%d", &x);
	recur(x);
	return 0;
}