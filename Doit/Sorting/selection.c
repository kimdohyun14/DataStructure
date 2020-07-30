/* 선택 정렬 */
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;}while(0)

void selection(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (j = i + 1; j < n; ++j)
		{
			if (a[j] < a[min])
				min = j;
		}

		swap(int, a[i], a[min]);
	}
}

int main()
{
	int i, nx;
	int* x;

	puts("선택 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	selection(x, nx);

	puts("오름차순으로 정렬한 결과");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);
	return 0;
}