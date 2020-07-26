/* 배열 요소의 최댓값을 구한다.(값을 입력) */
#include <stdio.h>
#include <stdlib.h>

// const int a[] = const int* a
// 읽기만 가능하도록
int maxof(const int a[], int n)
{
	int i;
	int max = a[0];
	for (i = 1; i < n; ++i)
		if (a[i] > max) max = a[i];
	return max;
}

int main()
{
	int i;
	int* height;
	int number;
	printf("사람 수 : ");
	scanf_s("%d", &number);
	height = (int*)calloc(number, sizeof(int));
	printf("%d 사람의 키를 입력.\n", number);
	for (i = 0; i < number; ++i)
	{
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}
	printf("최댓값은 %d\n", maxof(height, number));
	free(height);
	return 0;
}