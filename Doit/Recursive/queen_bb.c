/* 각 행, 각 열에 1개의 퀸을 배치하는 조합을 재귀적으로 나열 */
#include <stdio.h>

int flag[8]; // 각 행에 퀸을 배치했는지 체크하는 배열
int pos[8];
int counter;

void print()
{
	int i;
	for (i = 0; i < 8; ++i)
		printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i)
{
	int j;
	for (j = 0; j < 8; ++j)
	{
		if (!flag[j])
		{
			pos[i] = j; // i열에 j행에 퀸을 둔다.
			if (i == 7)
			{
				print();
				++counter;
			}
				
			else
			{
				flag[j] = 1;
				set(i + 1);
				flag[j] = 0;
			}
		}
	}
}

int main()
{
	printf("시작");
	int i;
	for (i = 0; i < 8; ++i)
		flag[i] = 0;
	set(0);
	printf("출력횟수 : %d\n", counter); // 40320 가지
	return 0;
}