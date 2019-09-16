#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
}Node;

// 더미 노드를 추가하면 연결리스트의 구현은 한결 간단해진다.
// 더미 노드 : 의미없는 노드(빈 노드)

int main() {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	head = (Node*)malloc(sizeof(Node)); // 더미 노드 추가
	tail = head;

	// 데이터를 입력 받는 과정
	while (1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		// 노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		/*
		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;
		*/
		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	// 입력 받은 데이터의 출력과정
	printf("입력 받은 데이터의 전체출력 \n");
	if (head == tail)
		printf("저장된 자연수가 존재하지 않습니다. \n");
	else {
		cur = head;
		//printf("%d ", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 메모리 해제과정
	if (head == tail)
		return 0;
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		//printf("%d을(를) 삭제합니다. \n", head->data);
		//free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}