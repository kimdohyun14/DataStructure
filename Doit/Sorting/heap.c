/* �� ���� */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

// 1. downheap ����ؼ� �迭 a�� heap���� ������ش�.
// 2. ��Ʈ�� �ִ� ���� ū ���� ������ �迭 ������ ��ҿ� �ٲٰ�,
//    �迭�� ������ �κ��� �ٽ� ������ ������ִ� ������ �ݺ��Ͽ� ������ �����Ѵ�.

// a, 4, 9
static void downheap(int a[], int left, int right)
{
	int temp = a[left]; // ��Ʈ(������ ���� �� �ڸ��� ������, �ƴϸ� �ڸ��� �����ؾ� �ϴ��� �����ϴ� ��)
	int child;
	int parent;
	// �θ� �� �� �ִ� ������ parent < (right + 1) / 2�������̴�. (�ڽ��� �־�� ����)
	for (parent = left; parent < (right + 1) / 2; parent = child)
	{
		int cl = parent * 2 + 1; // ���� �ڽ�
		int cr = cl + 1;         // ������ �ڽ�
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;  // ���� vs ������
		if (temp >= a[child])    // ���� ū ���� ��Ʈ�� ���ؼ�, ��Ʈ�� ũ�� ����
			break;
		a[parent] = a[child];    // �ƴ϶��, �θ� �ڽ��� �־��ְ�, �̾��.
	}
	a[parent] = temp;
}

void heapsort(int a[], int n)
{
	int i;
	// �־��� �迭 a�� heap���� �������ش�.
	// �Ʒ��κ��� ���� �κ�Ʈ������ ������ �ö󰡴� ����̴�.
	for (i = (n - 1) / 2; i >= 0; --i)
		downheap(a, i, n - 1);

	for (i = n - 1; i > 0; --i)
	{
		// ��Ʈ�� ���� �� ���� ���� swap�ؼ� �������ش�.
		swap(int, a[0], a[i]);
		// ��Ʈ�� ���ְ� �� ���¸� �����ϱ� ���ؼ� downheap�� �Ѵ�.
		downheap(a, 0, i - 1);
	}
}

int main()
{
	int i, nx;
	int* x;
	puts("�� ����");
	printf("��� ���� : "); scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	heapsort(x, nx);
	puts("������������ ����");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);
	return 0;
}