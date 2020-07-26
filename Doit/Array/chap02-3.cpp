/* int형 객체를 동적으로 생성하고 해제한다. */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* x;
	x = (int*)calloc(1, sizeof(int));
	if (x == NULL)
		puts("메모리 할당에 실패");
	else
	{
		*x = 57;
		printf("*x = %d\n", *x);

		free(x);
	}

	return 0;
}