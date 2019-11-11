#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

void GraphInit(ALGraph* pg, int nv) {
	int i;

	// ������ ���� �ش��ϴ� ������ ����Ʈ �迭�� �����Ѵ�.
	pg->adjList = (List*)malloc(sizeof(List) * nv);

	pg->numV = nv;  // ������ ���� nv�� ����� ������ ����
	pg->numE = 0;   // �ʱ��� ���� ���� 0��

	// ������ ����ŭ ������ ����Ʈ���� �ʱ�ȭ�Ѵ�.
	for (i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i])); // ��������Ʈ�� �ε����� ������ 0����
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);     // �������� �Ҵ�� ���� ����Ʈ�� �Ҹ�

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV) {
	// ������ ������ �׷����̹Ƿ� ���� ��� �������ش�.
	// ���� fromV�� ���� ����Ʈ�� ���� toV�� ���� �߰�
	LInsert(&(pg->adjList[fromV]), toV);
	// ���� toV�� ���� ����Ʈ�� ���� fromV�� ���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx)) {
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx)) {
				printf("%c ", vx + 65);
			}
		}
		printf("\n");
	}
}

int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1; // �湮�ߴٰ� üũ
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

void DFShowGraphVertex(ALGraph* pg, int startV) {
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);          // DFS�� ���� ������ �ʱ�ȭ
	VisitVertex(pg, visitV);    // ���� ������ �湮
	SPush(&stack, visitV);      // ���� ������ ������ �������� �ִ´�.

	// visitV�� ��� ������ ����� ������ �湮�� �õ��ϴ� while��
	// visitV�� ������ ���� �߿��� ã�Ƽ� �湮���� �ʾҴٸ� �湮�Ѵ�.
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		
		// visitV�� ����� ������ ������ nextV�� ��� ���¿��� ���ϸ� �����Ѵ�.
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) { // �߰��� �湮�� ������ �����ٸ�
			
			// ������ ��� Ž���� ���������� �ǵ��� �� ���̴�.
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);  // ���� �ǵ��� ����.
		}
	}

	// ������ �ٸ� Ž���� ���ؼ� �湮 �迭�� �ٽ� �ʱ�ȭ ��Ų��.
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}