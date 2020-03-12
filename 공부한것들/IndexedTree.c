#include <stdio.h>
#define NUMBER 7

int tree[NUMBER + 1];

// 1 ~ N������ ���� �� ���ϱ�
int sum(int i)
{
	int res = 0;
	while (i > 0)
	{
		res += tree[i];
		// ������ ��Ʈ��ŭ ���鼭 ������ �̵�
		i -= (i & -i);
	}
	return res;
}

// Ư�� �ε��� �����ϱ�
void update(int i, int dif)
{
	while (i <= NUMBER)
	{
		tree[i] += dif;
		// ������ ��Ʈ��ŭ ���ϸ鼭 �ڷ� �̵�
		i += (i & -i);
	}
}

// ���� �� ��� �Լ�
int getSection(int start, int end)
{
	return sum(end) - sum(start - 1);
}

void show()
{
	printf("----------------------\n");
	for (int i = 1; i <= 7; i++)
	{
		printf("%d ", tree[i]);
	}
	printf("\n");
}

int main()
{
	update(1, 7);
	update(2, 1);
	update(3, 9);
	update(4, 5);
	update(5, 6);
	update(6, 4);
	update(7, 1);
	printf("1 ~ 7������ ���� ��: %d\n", getSection(1, 7));
	printf("�ε��� 6�� ���Ҹ� +3��ŭ ����\n");
	update(6, 3);
	printf("1 ~ 7������ ���� ��: %d\n", getSection(4, 7));
	return 0;
}