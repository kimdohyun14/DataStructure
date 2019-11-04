#pragma once

#define TRUE 1
#define FALSE 0

// 연결 리스트 기반 스택 구현

typedef int Data;

typedef struct _node {    // 연결 리스트의 노드를 표현한 구조체
	Data data;
	struct _node* next;
}Node;

typedef struct _listStack {  // 연결 리스트 기반 스택을 표현한 구조체
	Node* head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);        // 스택 초기화
int SIsEmpty(Stack* pstack);         // 스택이 비어있는지 확인

void SPush(Stack* pstack, Data data); // 스택 push 연산
Data SPop(Stack* pstack);             // 스택 pop 연산
Data SPeek(Stack* pstack);            // 스택 peek 연산