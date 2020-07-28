#include <stdio.h>
#include "IntQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("큐의 생성에 실패");
		return 1;
	}
	while (1)
	{
		int m, x;

		printf("현제 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색 (0)종료 : ");
		scanf_s("%d", &m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("오류 : 인큐에 실패");
			else
				printf("디큐한 데이터는 %d\n", x);
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("오류 : 디큐에 실패");
			else
				printf("디큐한 데이터는 %d\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("오류 : 피크에 실패");
			else
				printf("피크한 데이터는 %d\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			printf("검색할 데이터 : ");
			scanf_s("%d", &x);
			if (Search2(&que, x) == -1)
				puts("오류 : 검색 실패");
			else
				printf("찾은 데이터는 front에서 %d만큼 떨어져있다.\n", Search2(&que, x));
			break;
		}
	}
	Terminate(&que);
	return 0;
}