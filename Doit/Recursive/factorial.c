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
	printf("������ �Է� : ");
	scanf_s("%d", &x);
	printf("%d! ���� %d\n", x, factorial(x));
	return 0;
}