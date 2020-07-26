/* ������ 2���� ~ 36������ ��� ��ȯ */
#include <stdio.h>

/* ���� �� x�� n������ ��ȯ�Ͽ� �迭d�� �Ʒ��ڸ����� ���� */
int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else
	{
		while (x)
		{
			d[digits++] = dchar[x % n];
			x /= n;
		}
	}
	return digits;
}

int main()
{
	int i;
	unsigned no;   // ��ȯ�ϴ� ����
	int cd;        // ���
	int dno;       // ��ȯ �� �ڸ���
	char cno[512]; // ��ȯ�� ���� �� �ڸ��� ���ڸ� �����ϴ� ���� �迭
	int retry;
	puts("10������ ��� ��ȯ");
	do
	{
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf_s("%u", &no);
		do
		{
			printf("� ������ ��ȯ�ұ�?(2-36) : ");
			scanf_s("%d", &cd);
			dno = card_convr(no, cd, cno); // no�� cd������ ��ȯ
			printf("%d�����δ�", cd);
			for (i = dno - 1; i >= 0; --i)
				printf("%c", cno[i]);
			printf("�Դϴ�.\n");
			printf("�� �� �� �ұ��?(1 ... ��/0 ... �ƴϿ�) : ");
			scanf_s("%d", &retry);
		} while (cd < 2 || cd > 36);
	} while (retry == 1);
	return 0;
}