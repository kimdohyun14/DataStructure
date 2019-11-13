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

	// 정점의 수에 해당하는 길이의 리스트 배열을 생성한다.
	pg->adjList = (List*)malloc(sizeof(List) * nv);

	pg->numV = nv;  // 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;   // 초기의 간선 수는 0개

	// 정점의 수만큼 생선된 리스트들을 초기화한다.
	for (i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i])); // 인접리스트는 인덱스의 시작이 0부터
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);     // 동적으로 할당된 연결 리스트의 소멸

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV) {
	// 구현은 무방향 그래프이므로 양쪽 모두 연결해준다.
	// 정점 fromV의 연결 리스트에 정점 toV의 정보 추가
	LInsert(&(pg->adjList[fromV]), toV);
	// 정점 toV의 연결 리스트에 정점 fromV의 정보 추가
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c와 연결된 정점: ", i + 65);

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
	VisitVertex(pg, visitV); // 시작 정점을 탐색한다.

	// 아래의 while문에서는 visitV와 연결된 모든 정점에 방문한다.
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		if (VisitVertex(pg, nextV) == TRUE) {
			Enqueue(&queue, nextV); // nextV에 방문했으니 큐에 저장한다.
		}

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
			if (VisitVertex(pg, nextV) == TRUE) {
				Enqueue(&queue, nextV);
			}
		}

		if (QIsEmpty(&queue) == TRUE) // 큐가 비면 BFS 종료
			break;
		else
			visitV = Dequeue(&queue); // 큐에서 하나 꺼내어 while문 다시 시작
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV); // 탐색 정보 초기화
}