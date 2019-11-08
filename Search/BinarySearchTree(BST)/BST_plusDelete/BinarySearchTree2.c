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

	// ���ο� ��尡 �߰��� ��ġ Ž��
	while (cNode != NULL) {
		if (data == GetData(cNode))
			return;            // �������� �ߺ��� ���x

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode();   // �� ����� ����
	SetData(nNode, data);      // �� ��忡 ������ ����

	// pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL) {
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else {  // �� ��尡 ��Ʈ ����̸�, ��Ʈ�� ����
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

	return NULL;               // Ž������� ����Ǿ� ���� ����.
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target) {
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� ��.
	BTreeNode* pVRoot = MakeBTreeNode();   // ���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;             // parent node
	BTreeNode* cNode = *pRoot;             // current node
	BTreeNode* dNode;                      // delete node

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	// ���� ����� ��带 Ž��
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)  // ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;      // ���� ����� dNode�� ����Ű�� �Ѵ�.

	// ù ��° ��� : ���� ����� �ܸ� ����� ���
	// �ܸ� ��常 �����ϸ� �ȴ�.
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode)  // �θ� ����� pNode�� ���� �ڽ��� ���� �����
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ��� : ���� ����� �ϳ��� �ڽ� ��带 ���� ���
	// ���� ����� �θ� ���� ���� ����� �ڽ� ��带 ���� �������ش�.
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode* dcNode;     // ���� ����� �ڽ� ��带 ����Ų��.

		// ����� �ڽ����� ã�´�.
		if (GetLeftSubTree(dNode) != NULL) {
			dcNode = GetLeftSubTree(dNode);   // ���� �ڽĳ��
		}
		else {
			dcNode = GetRightSubTree(dNode);  // ������ �ڽĳ��
		}

		// ���������� pNode���� ���� �ڽ��� ��������� Ȯ���Ѵ�.
		// Ȯ�� �� ���� ����� �θ� ���� ���� ����� ã�� �ڽ� ��带 ���� �����Ѵ�.
		if (GetLeftSubTree(pNode) == dNode) {
			ChangeLeftSubTree(pNode, dcNode);
		}
		else {
			ChangeRightSubTree(pNode, dcNode);
		}
	}

	// �� ��° ��� : �� ���� �ڽ� ��带 ��� ���� ���
	// �����Ϸ��� ����� ���� ���� Ʈ������ ���� ū ����
	// �Ǵ�
	// �����Ϸ��� ����� ������ ���� Ʈ������ ���� ���� ����
	// �����Ϸ��� ����� �ڸ��� ��ü�ع����� �ȴ�.
	// �� ������ ������ ���� Ʈ������ ���� ���� ������ ��ü�Ѵ�.
	else {
		BTreeNode* mNode = GetRightSubTree(dNode); // ��ü ��� ����Ŵ
		BTreeNode* mpNode = dNode;                 // ��ü ����� �θ� ��� ����Ŵ
		int delData;

		// 1�ܰ� : ���� ����� ��ü ��带 ã�´�.
		// ���� ���� ���� ã������ ��� ���� ���� Ʈ���� Ž���ؾ� �Ѵ�.
		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 2�ܰ� : ��ü ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);       // ���� ���� ������ ���
		SetData(dNode, GetData(mNode)); // ����

		// 3�ܰ� : ��ü ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		// ��, mpNode�� mNode�� �ڽ� ��带 �������ش�. -> ���� Ž�� Ʈ���� �����ϱ� ���ؼ�
		// �Ѵ� GetRightSubTree�� ������ 
		// ���� Ž�� Ʈ���� Ư¡�� ���� ū ���� ã�� ���� NULL�� ���� ������ ����ؼ� ������ �̵�,
	    // ���� ���� ���� ã�� ���� NULL�� ���� ������ ����ؼ� ���� �̵��̱� ������,
		// �ڽ� ���� �׻� �����ʿ� ���� �� �ۿ� ����.
		if (GetLeftSubTree(mpNode) == mNode) { // ���� �ڽ��̶��?
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else { // ������ �ڽ��̶��?
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;           // ���� ���� �������ְ�
		SetData(dNode, delData); // ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� �߰����� ó��
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);  // ��Ʈ ����� ������ �ݿ��Ѵ�.

	free(pVRoot);  // ���� ��Ʈ ����� �Ҹ�
	return dNode;  // ���� ����� ��ȯ (��ȯ�� ���� ������ ������ �Ѱ��ش�)
}

void ShowIntData(int data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst) {
	InorderTraverse(bst, ShowIntData);  // ���� ��ȸ
}