/* int형 배열을 동적으로 생성하고 해제한다. */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int* a;
	int na;
	printf("요소 개수 : ");
	scanf_s("%d", &na);
	a = (int*)calloc(na, sizeof(int));

	if (a == NULL)
		puts("메모리 할당에 실패");
	else
	{
		printf("%d개의 정수를 입력.\n", na);
		for (i = 0; i < na; ++i)
		{
			printf("a[%d] : ", i);
			scanf_s("%d", &a[i]);
		}
		printf("각 요소의 값은 다음과 같다.\n");
		for (i = 0; i < na; ++i)
			printf("a[%d] = %d\n", i, a[i]);

		free(a);
	}

	return 0;
}

