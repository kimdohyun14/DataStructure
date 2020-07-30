/* ���� ���� */
#include <stdio.h>
#include <stdlib.h>

static int* buff; // �߰����� �޸�

static void __mergesort(int a[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;   // �յ� ����
		int p = 0;
		int i;
		int j = 0;
		int k = left;
		__mergesort(a, left, center);      // �պκп� ���� ����
		__mergesort(a, center + 1, right); // �޺κп� ���� ����

		// ���� �迭 a�� �պκ��� buff�� �����Ѵ�.
		for (i = left; i <= center; ++i)
			buff[p++] = a[i];

		// �迭�� �޺κ��̶� �迭�� �պκ�(buff)�� ���ؼ� �迭 a�� �ٽ� ä���.
		// i : �迭�� �޺κ� �ε���
		// j : buff�� �ε���
		// p : buff�� ���� �������� üũ���ִ� �ε���
		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		// buff�� �����ִٸ�, �״�� �Ű��ش�.
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
	puts("���� ����");
	printf("��� ���� : "); scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	mergesort(x, nx);
	puts("������������ ����");
	for (i = 0; i < nx; ++i)
		printf("x[%d] : %d\n", i, x[i]);
	free(x);
	return 0;
}