/* Circular Linked List */
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// �� ��带 head���� �߰��ϴ� �Լ�
void LInsertFront(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

// �� ��带 tail�� �߰��ϴ� �Լ�
void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

// ������ ��ȸ ( �Ӹ� �κ��� �������� ����Ų��.)
int LFirst(List* plist, Data* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

// ���� ������ ��ȸ
int LNext(List* plist, Data* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

// ��� ����
Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

// ���� ����� �� ��ȯ
int LCount(List* plist) {
	return plist->numOfData;
}