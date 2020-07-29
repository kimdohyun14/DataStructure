#include <stdio.h>

void move(int no, int x, int y)
{
	char *name[] = { "A 기둥", "B 기둥", "C 기둥" };

	if (no > 1)
		move(no - 1, x, 6 - x - y);

	printf("원반[%d]를 %s에서 %s로 옮김\n", no, name[x - 1], name[y - 1]);

	if (no > 1)
		move(no - 1, 6 - x - y, y);
}

int main()
{
	int n;
	printf("하노의 탑\n원반 개수 : ");
	scanf_s("%d", &n);
	move(n, 1, 3);
	return 0;
}