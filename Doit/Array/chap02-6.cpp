/* �迭 ����� �ִ��� ���Ѵ�.(���� ������ ����) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// const int a[] = const int* a
// �б⸸ �����ϵ���
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
	printf("��� �� : ");
	scanf_s("%d", &number);
	height = (int*)calloc(number, sizeof(int));
	srand(time(NULL)); // �ð����� ������ seed�� �ʱ�ȭ
	for (i = 0; i < number; ++i)
	{
		height[i] = 100 + rand() % 90; // 100 + 0 ~ 89 => 100 ~ 189
		printf("height[%d] : %d\n", i, height[i]);
	}
	printf("�ִ��� %d\n", maxof(height, number));
	free(height);
	return 0;
}