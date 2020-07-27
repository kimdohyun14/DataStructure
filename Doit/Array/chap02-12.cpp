/* 한 해의 지난 날 수를 구한다. */
#include <stdio.h>

int mdays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

// 윤년인지?
// 4로 나누어 떨어지는 년도는 윤년이다.
// 그 중 100으로 나누어 떨어지는 년도는 윤년이 아니다.
// 400으로 나누어 떨어지는 년도는 무조건 윤년이다.
int isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayofyear(int y, int m, int d)
{
	int i;
	int days = d;
	for (i = 1; i < m; ++i)
		days += mdays[isleap(y)][i - 1];
	return days;
}

int main()
{
	int year, month, day;
	int retry;
	do
	{
		printf("년 : "); scanf_s("%d", &year);
		printf("월 : "); scanf_s("%d", &month);
		printf("일 : "); scanf_s("%d", &day);
		printf("%d년의 %d일째입니다.\n", year, dayofyear(year, month, day));
		printf("다시 할까요?(1... 예/0 ... 아니오) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);
	return 0;
}