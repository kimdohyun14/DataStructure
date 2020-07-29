/* 각 열에 1개의 퀸을 배치하는 조합을 재귀적으로 나열 */
#include <stdio.h>

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
	// 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 = 16,777,216 가지
	for (j = 0; j < 8; ++j)
	{
		pos[i] = j;
		if (i == 7)
		{
			print();
			++counter;
		}
			
		else
			set(i + 1);
	}
}

int main()
{
	set(0);
	printf("출력횟수 : %d\n", counter); // 16,777,216가지
	return 0;
}