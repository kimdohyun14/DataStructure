/* 하노이의 탑 */
#include <stdio.h>

// no개의 원반을 1 -> 3으로 옮기고 싶을 때
// no-1의 원반을 1 -> 2로 옮기고,
// no의 원반을 1 -> 3으로 옮긴다.
// no-1의 원반을 2 -> 3으로 옮긴다.
void move(int no, int x, int y)
{
	if (no > 1)
		move(no - 1, x, 6 - x - y); // 그룹을 시작 기둥에서 중간 기둥으로

	printf("원반[%d]을 %d기둥에서 %d기둥으로 옮김\n", no, x, y);

	if (no > 1)
		move(no - 1, 6 - x - y, y); // 그룹을 중간 기둥에서 목표 기둥으로
}

int main()
{
	int n;
	printf("하노이의 탑\n원반 개수 : ");
	scanf_s("%d", &n);
	move(n, 1, 3);
	return 0;
}