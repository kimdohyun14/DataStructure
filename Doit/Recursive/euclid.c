/* ��Ŭ���� ȣ������ ���� �ִ������� ���Ѵ�. */
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
	puts("�� ������ �ִ������� ���غ���.");
	printf("������ �Է� : ");
	scanf_s("%d", &x);
	printf("������ �Է� : ");
	scanf_s("%d", &y);
	printf("�ִ������� %d\n", gcd(x, y));
	printf("�ִ������� %d\n", gcd(y, x));
	return 0;
}