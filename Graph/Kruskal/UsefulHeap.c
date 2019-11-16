#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc; // �Լ� ���
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) {  // �θ� ����� �ε��� �� ��ȯ
	return idx / 2;
}

int GetLChildIDX(int idx) {  // ���� �ڽ� ����� �ε��� �� ��ȯ
	return idx * 2;
}

int GetRChildIDX(int idx) {  // ������ �ڽ� ����� �ε��� �� ��ȯ
	return idx * 2 + 1;
}

// �� ���� �ڽ� ��� �� ���� �켱���� �ڽ� ��� �ε��� ���� ��ȯ
int GetHiPriChildIDX(Heap* ph, int idx) {
	// �ڽ� ��尡 �������� �ʴ´ٸ�,
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	// �ڽ� ��尡 ���� �ڽ� ��� �ϳ��� �����Ѵٸ�,
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	// �ڽ� ��尡 �� �� �����Ѵٸ�,
	else {
		// ������ �ڽ� ����� �켱������ ���ٸ�
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

// ���� ������ ����
void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData + 1;

	// �� ��尡 ��Ʈ ����� ��ġ�� �ƴ϶�� �ݺ�
	while (idx != 1) {
		// �� ���� �θ� ����� �켱���� ��
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
			// �� ��尡 �θ� ����� �켱�������� ���ٸ�
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

// ������ ������ ����
// �ٽ��� ������ ��尡 �־�� �� ��ġ�� parentIdx�� ����� �ε��� ����
// �����ذ��� ã�´�
HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	} // �ݺ��� Ż���ϸ� parentIdx�� ������ ����� ��ġ������ ����

	// �� ��ġ�� ������ ����� ������ �ִ´�
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}