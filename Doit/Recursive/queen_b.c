/* �� ���� 1���� ���� ��ġ�ϴ� ������ ��������� ���� */
#include <stdio.h>

int pos[8];
int counter;

void print()
{
	int i;
	for (i = 0; i < 8; ++i)
		printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i)
{
	int j;
	// 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 = 16,777,216 ����
	for (j = 0; j < 8; ++j)
	{
		pos[i] = j;
		if (i == 7)
		{
			print();
			++counter;
		}
			
		else
			set(i + 1);
	}
}

int main()
{
	set(0);
	printf("���Ƚ�� : %d\n", counter); // 16,777,216����
	return 0;
}