/* 문자열을 비교하는 프로그램(strncmp 함수 사용) */
#include <stdio.h>
#include <string.h>

int main()
{
	char st[128];
	puts("STRING의 처음 3개의 문자와 비교");
	puts("XXXX를 입력하면 종료");
	while (1)
	{
		printf("문자열 st : ");
		scanf_s("%s", st, 128);
		if (strncmp("XXXX", st, 3) == 0)
			break;
		printf("strncmp(\"STRING\",st, 3) = %d\n", strncmp("STRING", st, 3));
	}

	return 0;
}