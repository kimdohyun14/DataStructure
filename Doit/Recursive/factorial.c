#include <stdio.h>

int factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main()
{
	int x;
	printf("정수를 입력 : ");
	scanf_s("%d", &x);
	printf("%d! 값은 %d\n", x, factorial(x));
	return 0;
}