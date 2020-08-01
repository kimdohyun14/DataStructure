/* 문자열의 길이를 구해보자. */
#include <stdio.h>

int str_len(const char* s)
{
	int len = 0;

	while (*s++)
		len++;	
	return len;
}

int main()
{
	char str[256];
	printf("문자열 : ");
	scanf_s("%s", str, 256);
	printf("이 문자열의 길이는 %d이다.\n", str_len(str));
	return 0;
}