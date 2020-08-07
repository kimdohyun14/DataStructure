/* �����˻�Ʈ���� ��� */
#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

typedef enum
{
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
}Menu;

Menu SelectMenu()
{
	int ch;
	do
	{
		printf("(1)���� (2)���� (3)�˻� (4)��� (0)���� : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > PRINT);
	return (Menu)ch;
}

int main()
{
	Menu menu;
	BinNode* root = NULL;
	do
	{
		Member x;
		BinNode* temp;
		switch (menu = SelectMenu())
		{
		case ADD:
			x = ScanMember("����", MEMBER_NO | MEMBER_NAME);
			root = Add(root, &x);
			break;
			
		case REMOVE:
			x = ScanMember("����", MEMBER_NO);
			Remove(&root, &x);
			break;

		case SEARCH:
			x = ScanMember("�˻�", MEMBER_NO);
			if ((temp = Search(root, &x)) != NULL)
				PrintLnMember(&temp->data);
			break;

		case PRINT:
			puts("��� ���");
			PrintTree(root);
			break;

		}
	} while (menu != TERMINATE);
	FreeTree(root);
	return 0;
}