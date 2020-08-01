/* 배열에 문자열 저장하기 */
#include <stdio.h>

// 문자열 값을 char형 배열에 저장하면 자유롭게 값을 꺼내고 쓸 수 있다.

int main()
{
	char st[10];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\0'; // 문자열의 끝을 의미하는 널 문자
	st[5] = 'T';
	printf("문자열 st에는 %s가 들어있다.\n", st);
	return 0;
}