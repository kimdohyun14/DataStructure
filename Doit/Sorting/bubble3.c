/* 버블 정렬 */
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;}while(0)

int counter;

// 비교, 교환을 하다가 어떤 시점 이후에 교환이 없다면,
// 그보다 앞쪽의 요소는 이미 정렬을 마친 상태
void bubble(int a[], int n)
{
	int k = 0; // a[k]보다 앞쪽의 요소는 정렬을 마친 상태
	while (k < n - 1)
	{
		++counter;
		int j;
		int last = n - 1; // 마지막으로 교환을 수행한 위치를 저장한다.
		for (j = n - 1; j > k; --j)
		{
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}
		k = last;
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