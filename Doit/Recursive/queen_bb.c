/* �� ��, �� ���� 1���� ���� ��ġ�ϴ� ������ ��������� ���� */
#include <stdio.h>

int flag[8]; // �� �࿡ ���� ��ġ�ߴ��� üũ�ϴ� �迭
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
	for (j = 0; j < 8; ++j)
	{
		if (!flag[j])
		{
			pos[i] = j; // i���� j�࿡ ���� �д�.
			if (i == 7)
			{
				print();
				++counter;
			}
				
			else
			{
				flag[j] = 1;
				set(i + 1);
				flag[j] = 0;
			}
		}
	}
}

int main()
{
	printf("����");
	int i;
	for (i = 0; i < 8; ++i)
		flag[i] = 0;
	set(0);
	printf("���Ƚ�� : %d\n", counter); // 40320 ����
	return 0;
}