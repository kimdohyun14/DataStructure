#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}

int PQWeightComp(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
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

	// �켱���� ť �ʱ�ȭ
	PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);     // �������� �Ҵ�� ���� ����Ʈ�� �Ҹ�

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV, int weight) {

	Edge edge = { fromV, toV, weight };  // ������ ����ġ ������ ��´�.


	// ������ ������ �׷����̹Ƿ� ���� ��� �������ش�.
	// ���� fromV�� ���� ����Ʈ�� ���� toV�� ���� �߰�
	LInsert(&(pg->adjList[fromV]), toV);
	// ���� toV�� ���� ����Ʈ�� ���� fromV�� ���� �߰�
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	// ������ ����ġ ������ �켱���� ť�� ����
	PEnqueue(&(pg->pqueue), edge);
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

// ���� ������ ���� �Ҹ�
void RemoveWayEdge(ALGraph* pg, int fromV, int toV) {
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge)) {
		if (edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge)) {
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

// ������ �Ҹ�
void RemoveEdge(ALGraph* pg, int fromV, int toV) {
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
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

// ������ ����ġ ���� ���
void ShowGraphEdgeWeightInfo(ALGraph* pg) {
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ)) {
		edge = PDequeue(&copyPQ);
		printf("(%c-%c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}

// ���ڷ� ���޵� �� ������ ����Ǿ� �ִٸ� TRUE, �ƴϸ� FALSE
int IsConnVertex(ALGraph* pg, int v1, int v2) {
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		int visitFlag = FALSE;

		// ������ ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE��ȯ
		if (nextV == v2) {
			// �Լ��� ��ȯ�ϱ� ���� �ʱ�ȭ�� ����
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				
				if (nextV == v2) {
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;
}

void ConKruskalMST(ALGraph* pg) {  // ũ�罺Į ������ ���� ����
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;
	int i;

	// MST�� ������ ������ �ݺ�
	while (pg->numE + 1 > pg->numV) { // MST ������ �� + 1 == ������ ��

		// �켱���� ť���� ����ġ�� ���� ���� ������ ������ ������.
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2); // �׷������� ������ ����

		// ������ �����ϰ� ������ �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ��
		if (!IsConnVertex(pg, edge.v1, edge.v2)) { // �� ������ ����Ǿ� �ִ��� Ȯ��

			// ��ΰ� ������ ������ ������ �ٽ� ����
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight); // ������ ������ �ٽ� ����

			// ������ ������ ������ ������ �����Ѵ�.
			recvEdge[eidx++] = edge;
		}
	}

	// �켱���� ť���� ������ ������ ������ ȸ��
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}