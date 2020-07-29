/* 유클리드 호제법에 의해 최대공약수를 구한다. */
#include <stdio.h>

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main()
{
	int x, y;
	puts("두 정수의 최대공약수를 구해보자.");
	printf("정수를 입력 : ");
	scanf_s("%d", &x);
	printf("정수를 입력 : ");
	scanf_s("%d", &y);
	printf("최대공약수는 %d\n", gcd(x, y));
	printf("최대공약수는 %d\n", gcd(y, x));
	return 0;
}