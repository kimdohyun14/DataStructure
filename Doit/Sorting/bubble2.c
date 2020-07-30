/* 버블 정렬 */
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;}while(0)

int counter;

// 해당 순환에서 요소의 교환 횟수가 0이면 더 이상 정렬할 요소가 없다는 뜻,
// 즉, 정렬을 종료하면 된다.
void bubble(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; ++i)
	{
		int exchg = 0;
		for (j = n - 1; j > i; --j)
		{
			++counter;
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				++exchg;
			}
		}
		if (exchg == 0) break;
	}
}

int main()
{
	int i, nx;
	int* x;

	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬한 결과");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	printf("성능 척도 : %d\n", counter);
	return 0;
}