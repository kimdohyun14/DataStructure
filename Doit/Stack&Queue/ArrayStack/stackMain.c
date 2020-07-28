#include <stdio.h>
#include "stack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("���� ������ ����");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (0)���� : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1)
				puts("���� : Ǫ�ÿ� ����");
			break;
		case 2:
			if (Pop(&s, &x) == -1)
				puts("���� : �˿� ����");
			else
				printf("�� �����ʹ� %d\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1)
				puts("���� : ��ũ�� ����");
			else
				printf("��ũ �����ʹ� %d\n", x);
			break;
		case 4:
			Print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}