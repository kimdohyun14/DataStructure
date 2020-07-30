/* ���� ���� */
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;}while(0)

int counter;

// ��, ��ȯ�� �ϴٰ� � ���� ���Ŀ� ��ȯ�� ���ٸ�,
// �׺��� ������ ��Ҵ� �̹� ������ ��ģ ����
void bubble(int a[], int n)
{
	int k = 0; // a[k]���� ������ ��Ҵ� ������ ��ģ ����
	while (k < n - 1)
	{
		++counter;
		int j;
		int last = n - 1; // ���������� ��ȯ�� ������ ��ġ�� �����Ѵ�.
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

	puts("���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ ������ ���");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	printf("���� ô�� : %d\n", counter);
	return 0;
}