#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct
{
	int data;
	struct Node* next;
}Node;

typedef struct
{
	Node* top;
}Stack;

void push(Stack* stack, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int pop(Stack* stack)
{
	if (stack->top == NULL)
	{
		printf("스택 언더플로우 발생\n");
		return;
	}
	Node* node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack* stack)
{
	Node* cur = stack->top;
	printf("--- 스택의 최상단 --- \n");
	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택의 최하단 --- \n");
}

int main()
{
	Stack s;
	s.top = NULL;
	push(&s, 7);
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 6);
	pop(&s);
	show(&s);
	return 0;
}