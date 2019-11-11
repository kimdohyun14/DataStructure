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
		pg->visitInfo[visitV] = 1; // 방문했다고 체크
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

void DFShowGraphVertex(ALGraph* pg, int startV) {
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);          // DFS을 위한 스택의 초기화
	VisitVertex(pg, visitV);    // 시작 정점을 방문
	SPush(&stack, visitV);      // 시작 정점의 정보를 스택으로 넣는다.

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
	// visitV와 인접한 정점 중에서 찾아서 방문하지 않았다면 방문한다.
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		
		// visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행한다.
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

		if (visitFlag == FALSE) { // 추가로 방문한 정점이 없었다면
			
			// 스택이 비면 탐색의 시작점으로 되돌아 온 것이다.
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);  // 길을 되돌아 간다.
		}
	}

	// 이후의 다른 탐색을 위해서 방문 배열을 다시 초기화 시킨다.
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}