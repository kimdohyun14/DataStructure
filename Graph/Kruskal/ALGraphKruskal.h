#pragma once

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

// 정점의 이름을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual {
	int numV;       // 정점의 수
	int numE;       // 간선의 수
	List* adjList;  // 간선의 정보
	int* visitInfo; // 방문 정보
	PQueue pqueue;  // 간선의 가중치 정보 저장
}ALGraph;

// 그래프 초기화
void GraphInit(ALGraph* pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

// 정점의 정보 출력 : Depth First Search 기반
void DFShowGraphVertex(ALGraph* pg, int startV);

// 최소 비용 신장 트리의 구성
void ConKruskalMST(ALGraph* pg);

// 가중치 정보 출력
void ShowGraphEdgeWeightInfo(ALGraph* pg);