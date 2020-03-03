#pragma once

#define TRUE 1
#define FALSE 0

// 양방향 연결 리스트의 구현
// double linked list

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _DLinkedList {
	Node* head;
	Node* cur;
	int numOfData;
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);				 // 리스트 초기화
void LInsert(List* plist, Data data);    // 새 노드 추가

int LFirst(List* plist, Data* pdata);    // 데이터 조회 (첫 번째 노드의 데이터 조회)
int LNext(List* plist, Data* pdata);     // 두 번째 이후의 노드 데이터 조회
int LPrevious(List* plist, Data* pdata); // LNext의 반대 방향으로 데이터 조회
int LCount(List* plist);                 // 리스트에 있는 노드의 개수 반환