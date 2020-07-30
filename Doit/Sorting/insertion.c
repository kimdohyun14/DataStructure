/* 단순 삽입 정렬 */
#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; ++i)
	{
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; --j)
			a[j] = a[j - 1];

		a[j] = tmp;
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

	insertion(x, nx);

	puts("오름차순으로 정렬하면");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
	return 0;
}