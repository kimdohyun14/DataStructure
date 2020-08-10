#ifndef ___ChainHash
#define ___ChainHash

#include "Member.h"

typedef struct __node
{
	Member data;
	struct __node* next;
}Node;

typedef struct
{
	int size;     // 해시 테이블의 크기
	Node** table; // 해시 테이블의 첫 번째 요소에 대한 포인터
}ChainHash;

int Initialize(ChainHash* h, int size);

Node* Search(const ChainHash* h, const Member* x);

int Add(ChainHash* h, const Member* x);

int Remove(ChainHash* h, const Member* x);

void Dump(const ChainHash* h);

void Clear(ChainHash* h);

void Terminate(ChainHash* h);
#endif