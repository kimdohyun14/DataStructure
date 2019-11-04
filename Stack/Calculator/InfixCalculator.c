#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // ConvRPNExp �Լ� ȣ���� ����
#include "PostCalculator.h" // EvalRPNExp �Լ� ȣ���� ����

int EvalInfixExp(char exp[]) {
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy); // ���� ǥ��� -> ���� ǥ���
	ret = EvalRPNExp(expcpy); // ���� ǥ��� ���� ���

	free(expcpy);
	return ret;
}