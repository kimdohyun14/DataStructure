#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*"; // 후위 표기법
	BTreeNode* eTree = MakeExpTree(exp); // 수식트리로 변경
	
	printf("전위 표기법의 수식: ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("중위 표기법의 수식: ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("후위 표기법의 수식: ");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("연산의 결과: %d \n", EvaluateExpTree(eTree));

	return 0;
}