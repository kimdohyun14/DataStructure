#pragma once

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);                         // 이진 트리 생성 및 주소 값을 반환
BTData GetData(BTreeNode* bt);                          // 노드에 저장된 데이터를 반환
void SetData(BTreeNode* bt, BTData data);               // 노드에 데이터를 저장

BTreeNode* GetLeftSubTree(BTreeNode* bt);               // 왼쪽 서브 트리의 주소 값을 반환
BTreeNode* GetRightSubTree(BTreeNode* bt);              // 오른쪽 서브 트리의 주소 값을 반환

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);  // 왼쪽 서브 트리를 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // 오른쪽 서브 트리를 연결