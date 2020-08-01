/* 두 포인터 값을 서로 교환하는 함수 */
#include <stdio.h>

// 이 함수가 s1, s2의 주소를 받아야 하기 때문에 char**형으로 받아야 한다.
void swap_ptr(char** x, char** y)
{
	char* tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	char* s1 = "ABCD";
	char* s2 = "EFGH";

	printf("포인터 s1 : %s\n", s1);
	printf("포인터 s2 : %s\n", s2);

	swap_ptr(&s1, &s2);

	puts("\n포인터 s1과 s2의 값을 서로 교환\n");

	printf("포인터 s1 : %s\n", s1);
	printf("포인터 s2 : %s\n", s2);
	return 0;
}