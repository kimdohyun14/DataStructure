#include <stdio.h>
#include "BinaryTree3.h"

// LLȸ��
BTreeNode* RotateLL(BTreeNode* bst) {
	BTreeNode* pNode;  // parent node
	BTreeNode* cNode;  // child node

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// ���� LLȸ���� ����ϴ� �ڵ�
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LLȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� ���� ��ȯ
	return cNode;
}
// RRȸ��
BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;  // parent node
	BTreeNode* cNode;  // child node

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// ���� RRȸ���� ����ϴ� �ڵ�
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	// RRȸ������ ���ؼ� ����� ��Ʈ ����� �ּ� ���� ��ȯ
	return cNode;
}
// RLȸ��
BTreeNode* RotateRL(BTreeNode* bst) {
	BTreeNode* pNode;  // parent node
	BTreeNode* cNode;  // child node

	pNode = bst;
	cNode = GetRightSubTree(bst);

	// ���� RLȸ���� ����ϴ� �ڵ�
	ChangeRightSubTree(pNode, RotateLL(cNode)); // �κ��� LLȸ��
	return RotateRR(pNode);

}
// LRȸ��
BTreeNode* RotateLR(BTreeNode* bst) {
	BTreeNode* pNode; // parent node
	BTreeNode* cNode; // child node

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	// ���� LRȸ���� ����ϴ� �ڵ�
	ChangeLeftSubTree(pNode, RotateRR(cNode)); // �κ��� RRȸ��
	return RotateLL(pNode);
}
// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight(BTreeNode* bst) {
	int leftH;  // left height
	int rightH; // right height

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));   // ���� ���� Ʈ�� ���� ���
	rightH = GetHeight(GetRightSubTree(bst)); // ������ ���� Ʈ�� ���� ���

	// ū ���� ���̸� ��ȯ�Ѵ�.
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}
// �� ���� Ʈ���� ������ ���� ��ȯ
int GetHeightDiff(BTreeNode* bst) {
	int lsh;  // left sub tree height
	int rsh;  // right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));  // ���� ���� Ʈ���� ����
	rsh = GetHeight(GetRightSubTree(bst)); // ������ ���� Ʈ���� ����
	return lsh - rsh; // ���� �μ� ����� ��ȯ
}
// Ʈ���� ������ ��´�.
BTreeNode* Rebalance(BTreeNode** pRoot) {
	int hDiff = GetHeightDiff(*pRoot); // ���� �μ� ���

	// ���� �μ��� +2 �̻��̸� LL���� �Ǵ� LR�����̴�.
	if (hDiff > 1) { // ���� ���� Ʈ�� �������� ���̰� 2 �̻� ũ�ٸ�
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) {
			*pRoot = RotateLL(*pRoot);
		}
		else {
			*pRoot = RotateLR(*pRoot);
		}
	}

	// ���� �μ��� -2 �����̸� RR���� �Ǵ� RL�����̴�.
	if (hDiff < -1) { // ������ ���� Ʈ�� �������� ���̰� 2 �̻� ũ�ٸ�
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) {
			*pRoot = RotateRR(*pRoot);
		}
		else {
			*pRoot = RotateRL(*pRoot);
		}
	}

	// ȸ�� �������� ��Ʈ ��尡 ����� �� �ֱ� ������, ��Ʈ ����� �ּ� ���� ��ȯ
	return *pRoot;
}