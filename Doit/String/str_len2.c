/* ���ڿ��� ���̸� ���غ���. */
#include <stdio.h>

int str_len(const char* s)
{
	int len = 0;

	while (*s++)
		len++;	
	return len;
}

int main()
{
	char str[256];
	printf("���ڿ� : ");
	scanf_s("%s", str, 256);
	printf("�� ���ڿ��� ���̴� %d�̴�.\n", str_len(str));
	return 0;
}