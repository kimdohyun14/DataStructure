/* strstr �Լ��� ����� ���α׷� */
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[256], s2[256];
	char* p;
	puts("strstr�Լ�");
	printf("�ؽ�Ʈ : "); scanf_s("%s", &s1, 256);
	printf("���� : "); scanf_s("%s", &s2, 256);
	p = strstr(s1, s2); // ���ڿ� s1���� ���ڿ� s2 �˻�
	if (p == NULL)
		printf("�ؽ�Ʈ�� ������ ����.\n");
	else
	{
		int ofs = p - s1;
		printf("\n%s\n", s1);
		printf("%*s|\n", ofs, "", s2);
		printf("%*s%s\n", ofs, "", s2);
	}

	return 0;
}