/* 병합 정렬 */
#include <stdio.h>
#include <stdlib.h>

static int* buff; // 추가적인 메모리

static void __mergesort(int a[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;   // 균등 분할
		int p = 0;
		int i;
		int j = 0;
		int k = left;
		__mergesort(a, left, center);      // 앞부분에 대한 정렬
		__mergesort(a, center + 1, right); // 뒷부분에 대한 정렬

		// 먼저 배열 a의 앞부분을 buff에 복사한다.
		for (i = left; i <= center; ++i)
			buff[p++] = a[i];

		// 배열의 뒷부분이랑 배열의 앞부분(buff)을 비교해서 배열 a를 다시 채운다.
		// i : 배열의 뒷부분 인덱스
		// j : buff의 인덱스
		// p : buff가 먼저 끝났는지 체크해주는 인덱스
		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		// buff가 남아있다면, 그대로 옮겨준다.
		while (j < p)
			a[k++] = buff[j++];
	}
}

int mergesort(int a[], int n)
{
	if ((buff = (int*)calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);
	free(buff);
	return 0;
}

int main()
{
	int i, nx;
	int* x;
	puts("병합 정렬");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	mergesort(x, nx);
	puts("오름차순으로 정렬");
	for (i = 0; i < nx; ++i)
		printf("x[%d] : %d\n", i, x[i]);
	free(x);
	return 0;
}