#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드 생성
	plist->head->next = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	Node* pred = plist->head; // pred는 더미 노드를 가리킨다.

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}

	newNode->next = pred->next; // 새 노드의 오른쪽을 연결
	pred->next = newNode;       // 새 노드의 왼쪽을 연결
	(plist->numOfData)++;
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist) {
	Node* rpos = plist->cur;  // 소멸 대상의 주소 값을 저장
	LData rdata = rpos->data; // 소멸 대상의 데이터를 저장

	plist->before->next = plist->cur->next; // 소멸 대상을 리스트에서 제거
	plist->cur = plist->before; // cur이 가리키는 위치를 재조정

	free(rpos); // 리스트에서 제거된 노드 소멸
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}
