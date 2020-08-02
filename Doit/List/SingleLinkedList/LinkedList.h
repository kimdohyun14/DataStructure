#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

typedef struct
{
	Member data;
	struct __node* next;
}Node;

typedef struct
{
	Node* head; // 머리 노드에 대한 포인터
	Node* crnt; // 선택한 노드에 대한 포인터
}List;

void Initialize(List* list);
// 함수 compare로 x와 같은 노드를 검색
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y));
void InsertFront(List* list, const Member* x);
void InsertRear(List* list, const Member* x);
void RemoveFront(List* list);
void RemoveRear(List* list);
void RemoveCurrent(List* list);
// 모든 노드 삭제
void Clear(List* list);
// 선택한 노드의 데이터 출력
void PrintCurrent(const List* list);
void PrintLnCurrent(const List* list);
// 모든 노드의 데이터를 리스트 순서대로 출력
void Print(const List* list);
// 연결 리스트 종료
void Terminate(List* list);
#endif