#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc; // 함수 등록
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) {  // 부모 노드의 인덱스 값 반환
	return idx / 2;
}

int GetLChildIDX(int idx) {  // 왼쪽 자식 노드의 인덱스 값 반환
	return idx * 2;
}

int GetRChildIDX(int idx) {  // 오른쪽 자식 노드의 인덱스 값 반환
	return idx * 2 + 1;
}

// 두 개의 자식 노드 중 높은 우선순위 자식 노드 인덱스 값을 반환
int GetHiPriChildIDX(Heap* ph, int idx) {
	// 자식 노드가 존재하지 않는다면,
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	// 자식 노드가 왼쪽 자식 노드 하나만 존재한다면,
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	// 자식 노드가 둘 다 존재한다면,
	else {
		// 오른쪽 자식 노드의 우선순위가 높다면
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

// 힙에 데이터 저장
void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData + 1;

	// 새 노드가 루트 노드의 위치가 아니라면 반복
	while (idx != 1) {
		// 새 노드와 부모 노드의 우선순위 비교
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
			// 새 노드가 부모 노드의 우선순위보다 높다면
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

// 힙에서 데이터 삭제
// 핵심은 마지막 노드가 있어야 할 위치를 parentIdx에 저장된 인덱스 값을
// 갱신해가며 찾는다
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
	} // 반복문 탈출하면 parentIdx에 마지막 노드의 위치정보가 저장

	// 그 위치에 마지막 노드의 정보를 넣는다
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}