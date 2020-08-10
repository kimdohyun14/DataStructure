#include <stdio.h>
#include "Member.h"
#include "ChainHash.h"

typedef enum
{
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
}Menu;

Menu SelectMenu()
{
	int ch;
	do
	{
		printf("(1)�߰� (2)���� (3)�˻� (4)��� ���� (5)���� (0)���� : ");
		scanf_s("%d", &ch);
	} while (ch <TERMINATE || ch > DUMP);
	return (Menu)ch;
}

int main()
{
	Menu menu;
	ChainHash hash;
	Initialize(&hash, 13);
	do
	{
		int result;
		Member x;
		Node* temp;
		switch (menu = SelectMenu())
		{
		case ADD:
			x = ScanMember("�߰�", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result)
				printf("���� : �߰��� ����(%s).\n",
					(result == 1) ? "�̹� ��ϵ�" : "�޸� ����");
			break;

		case DELETE:
			x = ScanMember("����", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result == 1)
				printf("���� : �� ��ȣ�� �����Ͱ� �������� ����\n");
			break;

		case SEARCH:
			x = ScanMember("�˻�", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == NULL)
				printf("�˻��� ����\n");
			else
			{
				printf("�˻��� ����\n");
				PrintLnMember(&temp->data);
			}
			break;

		case CLEAR:
			Clear(&hash);
			break;

		case DUMP:
			Dump(&hash);
			break;
		}
		putchar('\n');
	} while (menu != TERMINATE);
	Terminate(&hash);
	return 0;
}