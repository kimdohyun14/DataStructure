/* �迭 ����� �ִ��� ���Ѵ�.(���� �Է�) */
#include <stdio.h>
#include <stdlib.h>

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
	printf("%d ����� Ű�� �Է�.\n", number);
	for (i = 0; i < number; ++i)
	{
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}
	printf("�ִ��� %d\n", maxof(height, number));
	free(height);
	return 0;
}