/* ���ڿ��� ���ϴ� ���α׷� */
#include <stdio.h>

int str_cmp(const char* s1, const char* s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}

	return (unsigned char)*s1 - (unsigned char)*s2;
}

int main()
{
	char st[128];
	puts("\"ABCD\"�� ��");
	puts("\"XXXX\"�� ����");
	while (1)
	{
		printf("���ڿ� st : ");
		scanf_s("%s", st, 128);
		if (str_cmp("XXXX", st) == 0)
			break;
		printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
	}

	return 0;
}