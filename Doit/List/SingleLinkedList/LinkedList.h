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
	Node* head; // �Ӹ� ��忡 ���� ������
	Node* crnt; // ������ ��忡 ���� ������
}List;

void Initialize(List* list);
// �Լ� compare�� x�� ���� ��带 �˻�
Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y));
void InsertFront(List* list, const Member* x);
void InsertRear(List* list, const Member* x);
void RemoveFront(List* list);
void RemoveRear(List* list);
void RemoveCurrent(List* list);
// ��� ��� ����
void Clear(List* list);
// ������ ����� ������ ���
void PrintCurrent(const List* list);
void PrintLnCurrent(const List* list);
// ��� ����� �����͸� ����Ʈ ������� ���
void Print(const List* list);
// ���� ����Ʈ ����
void Terminate(List* list);
#endif