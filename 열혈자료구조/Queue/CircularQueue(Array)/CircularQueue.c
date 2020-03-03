#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq) { // 텅 빈 경우 front와 rear은 동일위치를 가리킨다.
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) { 
	if (NextPosIdx(pq->rear) == pq->front) { // 큐가 꽉 찼다면,
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear); // rear을 한 칸 이동
	pq->queArr[pq->rear] = data;     // rear가 가리키는 곳에 데이터를 저장
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front); // front를 한 칸 이동
	return pq->queArr[pq->front];      // front가 가리키는 데이터 반환
}

Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}