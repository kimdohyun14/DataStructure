/* ���� Ž��(���ʹ�) */
#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
	int i = 0;
	a[n] = key; // ���ʸ� �߰�
	while (1)
	{
		if (a[i] == key)
			break;
		++i;
	}
	return i == n ? -1 : i;
}

int main()
{
	int i, nx, ky, idx;
	int* x;
	puts("���� �˻�(���ʹ�)");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx + 1, sizeof(int));
	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	printf("�˻���: ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("�˻��� ����");
	else
		printf("%d(��)�� x[%d]�� �ִ�.\n", ky, idx);
	free(x);
	return 0;
}