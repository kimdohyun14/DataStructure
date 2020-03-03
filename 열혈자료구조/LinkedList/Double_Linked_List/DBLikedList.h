#pragma once

#define TRUE 1
#define FALSE 0

// ����� ���� ����Ʈ�� ����
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

void ListInit(List* plist);				 // ����Ʈ �ʱ�ȭ
void LInsert(List* plist, Data data);    // �� ��� �߰�

int LFirst(List* plist, Data* pdata);    // ������ ��ȸ (ù ��° ����� ������ ��ȸ)
int LNext(List* plist, Data* pdata);     // �� ��° ������ ��� ������ ��ȸ
int LPrevious(List* plist, Data* pdata); // LNext�� �ݴ� �������� ������ ��ȸ
int LCount(List* plist);                 // ����Ʈ�� �ִ� ����� ���� ��ȯ