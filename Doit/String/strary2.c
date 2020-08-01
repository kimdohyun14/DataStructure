/*  문자열을 초기화하며 선언하는 방법 */
#include <stdio.h>

int main()
{
	//char st[10] = { 'A','B','C','D', '\0' };
	char st[10] = "ABCD"; // 가장 많이 쓰이는 방식
	printf("문자열 st에는 %s가 들어있다.\n", st);
	return 0;
}