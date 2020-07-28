#include <stdio.h>
#include "stack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("스택 생성에 실패");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1)
				puts("오류 : 푸시에 실패");
			break;
		case 2:
			if (Pop(&s, &x) == -1)
				puts("오류 : 팝에 실패");
			else
				printf("팝 데이터는 %d\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1)
				puts("오류 : 피크에 실패");
			else
				printf("피크 데이터는 %d\n", x);
			break;
		case 4:
			Print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}