#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // ConvRPNExp 함수 호출을 위해
#include "PostCalculator.h" // EvalRPNExp 함수 호출을 위해

int EvalInfixExp(char exp[]) {
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy); // 중위 표기법 -> 후위 표기법
	ret = EvalRPNExp(expcpy); // 후위 표기법 수식 계산

	free(expcpy);
	return ret;
}