/* 8퀸 문제 풀이 */
#include <stdio.h>

int flag_a[8];  // 각 행에 퀸을 배치했는지 체크하는 배열
int flag_b[15]; // 대각선 ↗에 퀸을 배치했는지 체크하는 배열
int flag_c[15]; // 대각선 ↘에 퀸을 배치했는지 체크하는 배열
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
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
		{
			pos[i] = j; // i열 j행에 퀸을 배치
			if (i == 7)
			{
				print();
				++counter;
			}
				
			else
			{
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}

int main()
{
	int i;
	for (i = 0; i < 8; ++i)
		flag_a[i] = 0;
	for (i = 0; i < 15; ++i)
		flag_b[i] = flag_c[i] = 0;
	set(0);
	printf("출력횟수 : %d\n", counter); // 92 가지
	return 0;
}