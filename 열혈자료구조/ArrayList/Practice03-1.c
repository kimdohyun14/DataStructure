#include <stdio.h>
#include "ArrayList.h"

int main() {
	List list;
	ListInit(&list);
	for (int i = 1; i <= 9; i++) {
		LInsert(&list, i);
	}

	int sum = 0, data;
	if (LFirst(&list, &data)) {
		sum += data;
		
		while (LNext(&list, &data))
			sum += data;
	}
	printf("리스트에 저장된 값의 총 합: %d\n", sum);
	if (LFirst(&list, &data)) {
		if (!(data % 2) || !(data % 3))
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (!(data % 2) || !(data % 3))
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");
	return 0;
}