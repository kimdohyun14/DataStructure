/* �� ������ ���� ���� ��ȯ�ϴ� �Լ� */
#include <stdio.h>

// �� �Լ��� s1, s2�� �ּҸ� �޾ƾ� �ϱ� ������ char**������ �޾ƾ� �Ѵ�.
void swap_ptr(char** x, char** y)
{
	char* tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	char* s1 = "ABCD";
	char* s2 = "EFGH";

	printf("������ s1 : %s\n", s1);
	printf("������ s2 : %s\n", s2);

	swap_ptr(&s1, &s2);

	puts("\n������ s1�� s2�� ���� ���� ��ȯ\n");

	printf("������ s1 : %s\n", s1);
	printf("������ s2 : %s\n", s2);
	return 0;
}