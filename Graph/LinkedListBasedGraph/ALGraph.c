#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

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
}

void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);     // 동적으로 할당된 연결 리스트의 소멸
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