/* 선형 탐색(while loop) */
#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
	int i = 0;
	while (1)
	{
		if (i == n)
			return -1;
		if (a[i] == key)
			return i;

		++i;
	}
}

int main()
{
	int i, nx, ky, idx;
	int* x;
	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	printf("검색값: ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("검색에 실패");
	else
		printf("%d(은)는 x[%d]에 있다.\n", ky, idx);
	free(x);
	return 0;
}