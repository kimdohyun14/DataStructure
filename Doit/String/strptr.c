/* 문자열을 포인터를 사용해서 출력 */
#include <stdio.h>

int main()
{
	char* pt = "12345"; // 포인터 pt는 문자열 리터널 "12345"의 첫 번째 문자 '1'를 가리킨다.
	printf("포인터 pt는 %s를 가리킨다.\n", pt);
	return 0;
}