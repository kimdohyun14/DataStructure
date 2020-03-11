#include <stdio.h>
#define NUMBER 7

int a[] = { 7,1,9,5,6,4,1 };
int tree[4 * NUMBER]; // 4�� ���ϸ� ��� ������ Ŀ�� �����ϴ�.

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = a[start]; // ���� ����� ��� �迭�� ���� �״�� ����.
	int mid = (start + end) / 2;
	// ��������� �� �κ����� ���� �ڿ� �� ���� �ڱ� �ڽ����� �Ѵ�. (���� �ڽ� �� + ������ �ڽ� ��)
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start : ����, end : ��
// left, right : ������ ���� ���ϰ��� �ϴ� ����
// node : ��� �ε���
int sum(int start, int end, int node, int left, int right)
{
	// ���� �ۿ� �ִ� ���
	if (left > end || right < start) return 0;
	// ���� �ȿ� �ִ� ���
	if (left <= start && end <= right) return tree[node];
	// �׷��� �ʴٸ� �� �κ����� ������ �� ���ϱ�
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start : ����, end : ��
// index : ���� ���� �����ϰ��� �ϴ� ���
// dif : ������ ��
void update(int start, int end, int node, int index, int dif)
{
	// ���� �ۿ� �ִ� ���
	if (index < start || index > end) return;
	// ���� �ȿ� ������ �������� �ٸ� ���ҵ� ����
	tree[node] += dif;
	// ���� ����̸�
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main()
{
	// ���� �� Ʈ�� �����ϱ�
	init(0, NUMBER - 1, 1);
	// ���� �� ���ϱ�
	printf("0���� 6������ ���� ��: %d\n", sum(0, NUMBER - 1, 1, 0, 6));
	// ���� �� �����ϱ�
	printf("�ε��� 5�� ���Ҹ� +3��ŭ ����\n");
	update(0, NUMBER - 1, 1, 5, 3);
	// ���� �� �ٽ� ���ϱ�
	printf("3���� 6������ ���� ��: %d\n", sum(0, NUMBER - 1, 1, 3, 6));
	printf("0���� 6������ ���� ��: %d\n", sum(0, NUMBER - 1, 1, 0, 6));
	return 0;
}