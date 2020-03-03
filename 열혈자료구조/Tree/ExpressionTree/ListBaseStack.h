#pragma once

#define TRUE 1
#define FALSE 0
#include "BinaryTree2.h"

// ���� ����Ʈ ��� ���� ����

typedef BTreeNode* Data;

typedef struct _node {    // ���� ����Ʈ�� ��带 ǥ���� ����ü
	Data data;
	struct _node* next;
}Node;

typedef struct _listStack {  // ���� ����Ʈ ��� ������ ǥ���� ����ü
	Node* head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);        // ���� �ʱ�ȭ
int SIsEmpty(Stack* pstack);         // ������ ����ִ��� Ȯ��

void SPush(Stack* pstack, Data data); // ���� push ����
Data SPop(Stack* pstack);             // ���� pop ����
Data SPeek(Stack* pstack);            // ���� peek ����