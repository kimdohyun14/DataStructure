/* 배열 요소의 최댓값을 구한다.(값을 난수로 생성) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	srand(time(NULL)); // 시간으로 난수의 seed를 초기화
	for (i = 0; i < number; ++i)
	{
		height[i] = 100 + rand() % 90; // 100 + 0 ~ 89 => 100 ~ 189
		printf("height[%d] : %d\n", i, height[i]);
	}
	printf("최댓값은 %d\n", maxof(height, number));
	free(height);
	return 0;
}