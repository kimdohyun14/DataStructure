#include <stdio.h>

void move(int no, int x, int y)
{
	char *name[] = { "A ���", "B ���", "C ���" };

	if (no > 1)
		move(no - 1, x, 6 - x - y);

	printf("����[%d]�� %s���� %s�� �ű�\n", no, name[x - 1], name[y - 1]);

	if (no > 1)
		move(no - 1, 6 - x - y, y);
}

int main()
{
	int n;
	printf("�ϳ��� ž\n���� ���� : ");
	scanf_s("%d", &n);
	move(n, 1, 3);
	return 0;
}