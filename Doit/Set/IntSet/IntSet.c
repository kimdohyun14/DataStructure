#include "IntSet.h"
#include <stdio.h>
#include <stdlib.h>

int Initialize(IntSet* s, int max)
{
	s->num = 0;
	if ((s->set = (int*)calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}

// 집합 s에 n이 있는지, 있다면 해당 인덱스를 반환
int IsMember(const IntSet* s, int n)
{
	int i;
	for (i = 0; i < s->num; ++i)
		if (s->set[i] == n)
			return i;
	return -1;
}

void Add(IntSet* s, int n)
{
	if (s->num < s->max && IsMember(s, n) == -1)
		s->set[s->num++] = n;
}

void Remove(IntSet* s, int n)
{
	int idx;
	if ((idx = IsMember(s, n)) != -1)
		s->set[idx] = s->set[--s->num]; // 마지막 요소를 삭제 위치로 옮김
}

int Capacity(const IntSet* s)
{
	return s->max;
}

int Size(const IntSet* s)
{
	return s->num;
}

// 집합 s2를 s1에 대입
void Assign(IntSet* s1, const IntSet* s2)
{
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num; // 복사하는 원소의 개수
	for (i = 0; i < n; ++i)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

int Equal(const IntSet* s1, const IntSet* s2)
{
	int i, j;
	if (Size(s1) != Size(s2)) return 0;
	for (i = 0; i < s1->num; ++i)
	{
		for (j = 0; j < s2->num; ++j)
		{
			if (s1->set[i] == s2->set[i])
				break;
		}

		if (j == s2->num)
			return 0;
	}
	return 1;
}

// 집합 s2와 s3의 합집합을 s1에 대입
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i;
	Assign(s1, s2);
	for (i = 0; i < s3->num; ++i)
		Add(s1, s3->set[i]);
	return s1;
}

IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i, j;
	s1->num = 0;
	for (i = 0; i < s2->num; ++i)
	{
		for (j = 0; j < s3->num; ++j)
		{
			if (s2->set[i] == s3->set[j])
				Add(s1, s2->set[i]);
		}
	}
	return s1;
}

// 집합 s2에서 s3를 뺀 차집합을 s1에 대입
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s3)
{
	int i, j;
	s1->num = 0; // s1을 공집합으로 만들고
	for (i = 0; i < s2->num; ++i)
	{
		for (j = 0; j < s3->num; ++j)
		{
			if (s2->set[i] == s3->set[j])
				break;
		}

		if (j == s3->num)
			Add(s1, s2->set[i]);
	}

	return s1;
}

void Print(const IntSet* s)
{
	int i;
	printf("{ ");
	for (i = 0; i < s->num; ++i)
		printf("%d ", s->set[i]);
	printf("}");
}

void PrintLn(const IntSet* s)
{
	Print(s);
	putchar('\n');
}

void Terminate(IntSet* s)
{
	if (s->set != NULL)
	{
		free(s->set);
		s->max = s->num = 0;
	}
}
