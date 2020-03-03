#pragma once

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

// 배열 기반의 원형 큐 구현
// Circular Queue
typedef struct _cQueue {
	int front;  // front 멤버
	int rear;   // rear 멤버
	Data queArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);