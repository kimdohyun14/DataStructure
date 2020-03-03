#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL;   // parent node
	BTreeNode* cNode = *pRoot; // current node
	BTreeNode* nNode = NULL;   // new node

	// 새로운 노드가 추가될 위치 탐색
	while (cNode != NULL) {
		if (data == GetData(cNode))
			return;            // 데이터의 중복을 허용x

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode();   // 새 노드의 생성
	SetData(nNode, data);      // 새 노드에 데이터 저장

	// pNode의 자식 노드로 새 노드를 추가
	if (pNode != NULL) {
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else {  // 새 노드가 루트 노드이면, 루트로 지정
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cNode = bst;    // current node
	BSTData cd;                // current data

	while (cNode != NULL) {
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;               // 탐색대상이 저장되어 있지 않음.
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target) {
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 함.
	BTreeNode* pVRoot = MakeBTreeNode();   // 가상 루트 노드
	BTreeNode* pNode = pVRoot;             // parent node
	BTreeNode* cNode = *pRoot;             // current node
	BTreeNode* dNode;                      // delete node

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상인 노드를 탐색
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)  // 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;      // 삭제 대상을 dNode가 가리키게 한다.

	// 첫 번째 경우 : 삭제 대상이 단말 노드인 경우
	// 단말 노드만 삭제하면 된다.
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)  // 부모 노드의 pNode의 왼쪽 자식이 삭제 노드라면
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우
	// 삭제 대상의 부모 노드와 삭제 대상의 자식 노드를 서로 연결해준다.
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode* dcNode;     // 삭제 대상의 자식 노드를 가리킨다.

		// 어느쪽 자식인지 찾는다.
		if (GetLeftSubTree(dNode) != NULL) {
			dcNode = GetLeftSubTree(dNode);   // 왼쪽 자식노드
		}
		else {
			dcNode = GetRightSubTree(dNode);  // 오른쪽 자식노드
		}

		// 마찬가지로 pNode에서 삭제 자식이 어느쪽인지 확인한다.
		// 확인 후 삭제 대상의 부모 노드와 삭제 대상의 찾은 자식 노드를 서로 연결한다.
		if (GetLeftSubTree(pNode) == dNode) {
			ChangeLeftSubTree(pNode, dcNode);
		}
		else {
			ChangeRightSubTree(pNode, dcNode);
		}
	}

	// 세 번째 경우 : 두 개의 자식 노드를 모두 갖는 경우
	// 삭제하려는 노드의 왼쪽 서브 트리에서 가장 큰 것을
	// 또는
	// 삭제하려는 노드의 오른쪽 서브 트리에서 가장 작은 것을
	// 삭제하려는 노드의 자리를 대체해버리면 된다.
	// 이 구현은 오른쪽 서브 트리에서 가장 작은 것으로 대체한다.
	else {
		BTreeNode* mNode = GetRightSubTree(dNode); // 대체 노드 가리킴
		BTreeNode* mpNode = dNode;                 // 대체 노드의 부모 노드 가리킴
		int delData;

		// 1단계 : 삭제 대상의 대체 노드를 찾는다.
		// 가장 작은 것을 찾으려면 계속 왼쪽 서브 트리를 탐색해야 한다.
		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 2단계 : 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);       // 대입 전에 데이터 백업
		SetData(dNode, GetData(mNode)); // 대입

		// 3단계 : 대체 노드의 부모 노드와 자식 노드를 연결한다.
		// 즉, mpNode와 mNode의 자식 노드를 연결해준다. -> 이진 탐색 트리를 만족하기 위해서
		// 둘다 GetRightSubTree인 이유는 
		// 이진 탐색 트리의 특징이 가장 큰 값을 찾을 때는 NULL을 만날 때까지 계속해서 오른쪽 이동,
	    // 가장 작은 값을 찾을 때는 NULL을 만날 때까지 계속해서 왼쪽 이동이기 때문에,
		// 자식 노드는 항상 오른쪽에 있을 수 밖에 없다.
		if (GetLeftSubTree(mpNode) == mNode) { // 왼쪽 자식이라면?
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else { // 오른쪽 자식이라면?
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;           // 삭제 노드로 지정해주고
		SetData(dNode, delData); // 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);  // 루트 노드의 변경을 반영한다.

	free(pVRoot);  // 가상 루트 노드의 소멸
	return dNode;  // 삭제 대상의 반환 (반환을 통해 삭제의 권한을 넘겨준다)
}

void ShowIntData(int data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst) {
	InorderTraverse(bst, ShowIntData);  // 중위 순회
}