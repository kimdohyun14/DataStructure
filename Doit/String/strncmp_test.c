/* ���ڿ��� ���ϴ� ���α׷�(strncmp �Լ� ���) */
#include <stdio.h>
#include <string.h>

int main()
{
	char st[128];
	puts("STRING�� ó�� 3���� ���ڿ� ��");
	puts("XXXX�� �Է��ϸ� ����");
	while (1)
	{
		printf("���ڿ� st : ");
		scanf_s("%s", st, 128);
		if (strncmp("XXXX", st, 3) == 0)
			break;
		printf("strncmp(\"STRING\",st, 3) = %d\n", strncmp("STRING", st, 3));
	}

	return 0;
}