/* 배열 요소를 역순으로 정렬한다. */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

void ary_reverse(int a[], int n)
{
	int i;
	for (i = 0; i < n / 2; ++i)
		swap(int, a[i], a[n - i - 1]); // ;(세미콜론) 전까지 치환된다.
}

int main()
{
	int i;
	int* x;
	int nx;

	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	ary_reverse(x, nx);
	printf("배열의 요소를 역순으로 정렬한다.\n");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);
	return 0;
}