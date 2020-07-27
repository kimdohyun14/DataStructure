/* 이진 검색 */
#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
	int pl = 0;
	int pr = n - 1;
	int pc;
	do
	{
		pc = (pl + pr) / 2;
		if (a[pc] == key)
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
	} while (pl <= pr);
	return -1;
}

int main()
{
	int i, nx, ky, idx;
	int* x;
	puts("이진 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	printf("오름차순으로 입력하세요\n");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);
	for (i = 1; i < nx; ++i)
	{
		do
		{
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	printf("검색값 : ");
	scanf_s("%d", &ky);
	idx = bin_search(x, nx, ky);
	if (idx == -1)
		puts("검색에 실패");
	else
		printf("%d(은)는 x[%d]에 있다. \n", ky, idx);
	free(x);
	return 0;
}