#ifndef ___IntSet
#define ___IntSet

typedef struct
{
	int max;
	int num;
	int* set;
}IntSet;

int Initialize(IntSet* s, int max);

// 집합 s에 n이 들어 있는지 확인
int IsMember(const IntSet* s, int n);

// 집합 s에 n 추가
void Add(IntSet* s, int n);

// 집합 s에 n을 삭제
void Remove(IntSet* s, int n);

int Capacity(const IntSet* s);

int Size(const IntSet* s);

// 집합 s2를 s1에 대입
void Assign(IntSet* s1, const IntSet* s2);

int Equal(const IntSet* s1, const IntSet* s2);

// 집합 s2와 s3의 합집합을 s1에 대입
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3);

// 집합 s2에서 s3를 뺀 차집합을 s1에 대입
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3);

// 집합 s2에서 s3을 뺀 차집합을 s1에 대입
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s3);

void Print(const IntSet* s);

void PrintLn(const IntSet* s);

void Terminate(IntSet* s);
#endif