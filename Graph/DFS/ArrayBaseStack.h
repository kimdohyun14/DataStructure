#pragma once

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

// 배열 기반 스택 구현

typedef int Data;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);         // 스택의 초기화
int SIsEmpty(Stack* pstack);           // 스택이 비어있는지 확인

void SPush(Stack* pstack, Data data);  // 스택의 push 연산
Data SPop(Stack* pstack);              // 스택의 pop 연산
Data SPeek(Stack* pstack);             // 스택의 peek 연산
