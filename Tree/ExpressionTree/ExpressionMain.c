#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*"; // ���� ǥ���
	BTreeNode* eTree = MakeExpTree(exp); // ����Ʈ���� ����
	
	printf("���� ǥ����� ����: ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("���� ǥ����� ����: ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("���� ǥ����� ����: ");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("������ ���: %d \n", EvaluateExpTree(eTree));

	return 0;
}