/* int�� �迭�� �������� �����ϰ� �����Ѵ�. */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int* a;
	int na;
	printf("��� ���� : ");
	scanf_s("%d", &na);
	a = (int*)calloc(na, sizeof(int));

	if (a == NULL)
		puts("�޸� �Ҵ翡 ����");
	else
	{
		printf("%d���� ������ �Է�.\n", na);
		for (i = 0; i < na; ++i)
		{
			printf("a[%d] : ", i);
			scanf_s("%d", &a[i]);
		}
		printf("�� ����� ���� ������ ����.\n");
		for (i = 0; i < na; ++i)
			printf("a[%d] = %d\n", i, a[i]);

		free(a);
	}

	return 0;
}

