#pragma once

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J }; // 정점의 이름들을 상수화

typedef struct _ual {
	int numV;      // 정점의 수
	int numE;      // 간선의 수
	List* adjList; // 간선의 정보
	int* visitInfo; // 방문 기록
}ALGraph;

// 그래프 초기화
void GraphInit(ALGraph* pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

// 그래프의 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

// BFS 기반 그래프의 정점 정보 출력
void BFShowGraphVertex(ALGraph* pg, int startV);