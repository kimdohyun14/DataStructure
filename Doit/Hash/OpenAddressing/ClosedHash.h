// 오픈 주소법으로 구현한 해시
#ifndef ___ClosedHash
#define ___ClosedHash

#include "Member.h"

typedef enum
{
	Occupied, Empty, Deleted
}Status;

typedef struct
{
	Member data; // 데이터
	Status stat; // 요소의 상태
}Bucket;

typedef struct
{
	int size;
	Bucket* table;
}ClosedHash;

int Initialize(ClosedHash* h, int size);

Bucket* Search(const ClosedHash* h, const Member* x);

int Add(ClosedHash* h, const Member* x);

int Remove(ClosedHash* h, const Member* x);

void Dump(const ClosedHash* h);

void Clear(ClosedHash* h);

void Terminate(ClosedHash* h);
#endif