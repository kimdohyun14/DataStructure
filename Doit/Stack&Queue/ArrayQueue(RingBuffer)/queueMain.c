#include <stdio.h>
#include "IntQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("ť�� ������ ����");
		return 1;
	}
	while (1)
	{
		int m, x;

		printf("���� ������ �� : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)�˻� (0)���� : ");
		scanf_s("%d", &m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("���� : ��ť�� ����");
			else
				printf("��ť�� �����ʹ� %d\n", x);
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("���� : ��ť�� ����");
			else
				printf("��ť�� �����ʹ� %d\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("���� : ��ũ�� ����");
			else
				printf("��ũ�� �����ʹ� %d\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			printf("�˻��� ������ : ");
			scanf_s("%d", &x);
			if (Search2(&que, x) == -1)
				puts("���� : �˻� ����");
			else
				printf("ã�� �����ʹ� front���� %d��ŭ �������ִ�.\n", Search2(&que, x));
			break;
		}
	}
	Terminate(&que);
	return 0;
}