/* ���ڿ��� ���̸� ���غ���. */
#include <stdio.h>

int str_len(const char* s)
{
	const char* p = s;
	while (*s)
		s++;
	return s - p;
}

int main()
{
	char str[256];
	printf("���ڿ� : ");
	scanf_s("%s", str, 256);
	printf("�� ���ڿ��� ���̴� %d�̴�.\n", str_len(str));
	return 0;
}