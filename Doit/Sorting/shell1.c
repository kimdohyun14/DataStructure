/* 셸 정렬 */
#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2) // 몇 칸씩 떨어진 공간을 보는지
	{
		for (i = h; i < n; ++i)
		{
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];
			a[j + h] = tmp;
		}
	}
}
int main()
{
	int i, nx;
	int* x;

	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	shell(x, nx);

	puts("오름차순으로 정렬하면");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
	return 0;
}