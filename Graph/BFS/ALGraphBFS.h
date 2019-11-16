#pragma once

#include "DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J }; // ������ �̸����� ���ȭ

typedef struct _ual {
	int numV;      // ������ ��
	int numE;      // ������ ��
	List* adjList; // ������ ����
	int* visitInfo; // �湮 ���
}ALGraph;

// �׷��� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph* pg);

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

// �׷����� ���� ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

// BFS ��� �׷����� ���� ���� ���
void BFShowGraphVertex(ALGraph* pg, int startV);