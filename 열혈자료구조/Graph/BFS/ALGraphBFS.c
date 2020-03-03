#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"
#include "DLinkedList.h"
#include "CircularQueue.h"

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
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

void BFShowGraphVertex(ALGraph* pg, int startV) {
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInit(&queue);
	VisitVertex(pg, visitV); // ���� ������ Ž���Ѵ�.

	// �Ʒ��� while�������� visitV�� ����� ��� ������ �湮�Ѵ�.
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		if (VisitVertex(pg, nextV) == TRUE) {
			Enqueue(&queue, nextV); // nextV�� �湮������ ť�� �����Ѵ�.
		}

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
			if (VisitVertex(pg, nextV) == TRUE) {
				Enqueue(&queue, nextV);
			}
		}

		if (QIsEmpty(&queue) == TRUE) // ť�� ��� BFS ����
			break;
		else
			visitV = Dequeue(&queue); // ť���� �ϳ� ������ while�� �ٽ� ����
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV); // Ž�� ���� �ʱ�ȭ
}