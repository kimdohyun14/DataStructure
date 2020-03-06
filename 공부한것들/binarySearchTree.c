#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* insertNode(Node* root, int data)
{
	if (root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->data = data;
		root->leftChild = root->rightChild = NULL;
		return root;
	}
	else
	{
		if (root->data > data)
		{
			root->leftChild = insertNode(root->leftChild, data);
		}
		else
		{
			root->rightChild = insertNode(root->rightChild, data);
		}
	}
	return root;
}

Node* searchNode(Node* root, int data)
{
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	else if (root->data > data) return searchNode(root->leftChild, data);
	else return searchNode(root->rightChild, data);
}

void preorder(Node* root)
{
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

// 이진 탐색 트리의 가장 작은 원소 찾기
Node* findMinNode(Node* root)
{
	Node* node = root;
	while (node->leftChild != NULL)
		node = node->leftChild;

	return node;
}

Node* findMaxNode(Node* root)
{
	Node* node = root;
	while (node->rightChild != NULL)
		node = node->rightChild;

	return node;
}

// 이진 탐색 트리의 삭제
Node* deleteNode(Node* root, int data)
{
	Node* node = NULL;
	if (root == NULL) return NULL;
	if (root->data > data)
		root->leftChild = deleteNode(root->leftChild, data);
	else if (root->data < data)
		root->rightChild = deleteNode(root->rightChild, data);
	else // 삭제할 노드를 찾은 경우
	{
		// 자식이 두 개다 존재하는 경우
		if (root->leftChild != NULL && root->rightChild != NULL)
		{
			node = findMinNode(root->rightChild); // root노드 다음으로 큰 노드를 찾는다.
			root->data = node->data;
			root->rightChild = deleteNode(root->rightChild, node->data);
		}
		// 자식이 한 개만 존재하는 경우 혹은 없는 경우
		else
		{
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
			free(root);
			return node;
		}
	}
	return root;
}

int main()
{
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = deleteNode(root, 48);
	//root = deleteNode(root, 30);
	printf("%d\n", root->data);
	preorder(root);
	return 0;
}