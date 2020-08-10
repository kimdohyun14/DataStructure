#include "ChainHash.h"
#include "Member.h"
#include <stdio.h>
#include <stdlib.h>

// 해시 함수
static int hash(int key, int size)
{
    return key % size;
}

// Node에 값을 설정하는 함수
static void SetNode(Node* n, const Member* x, const Node* next)
{
    n->data = *x;
    n->next = next;
}

int Initialize(ChainHash* h, int size)
{
    int i;
    if ((h->table = calloc(size, sizeof(Node*))) == NULL)
    {
        h->size = 0;
        return 0;
    }
    h->size = size;
    for (i = 0; i < size; ++i)
        h->table[i] = NULL;
    return 1;
}

Node* Search(const ChainHash* h, const Member* x)
{
    int key = hash(x->no, h->size); // 검색하는 데이터의 해시 값
    Node* p = h->table[key];        // 현재 선택한 노드
    
    while (p != NULL)
    {
        if (p->data.no == x->no)    // 검색 성공
            return p;

        p = p->next;                // 다음 노드를 선택
    }

    return NULL;                    // 검색 실패
}

int Add(ChainHash* h, const Member* x)
{
    int key = hash(x->no, h->size);
    Node* p = h->table[key];
    Node* temp;
    while (p != NULL)
    {
        if (p->data.no == x->no)   // 이 키는 이미 등록되어있으면
            return 1;                // 추가 실패

        p = p->next;
    }
    if ((temp = calloc(1, sizeof(Node))) == NULL)
        return 2;                    // 할당 실패했다면 반환

    SetNode(temp, x, h->table[key]); // 추가하는 노드에 값을 설정
    h->table[key] = temp;
    return 0;                        // 추가 성공
}

int Remove(ChainHash* h, const Member* x)
{
    int key = hash(x->no, h->size);
    Node* p = h->table[key];         // 현재 선택한 노드
    Node** pp = &h->table[key];      // 현재 선택한 노드의 주소값을 저장
    while (p != NULL)
    {
        if (p->data.no == x->no)
        {
            *pp = p->next; // h->table[key] = p->next;
            free(p);       // 현재 노드를 삭제
            return 0;
        }

        pp = &p->next;
        p = p->next;       // 다음 노드를 선택
    }

    return 1;                        // 삭제 실패
}

// 해시 테이블의 내용을 출력하는 함수
void Dump(const ChainHash* h)
{
    int i;
    for (i = 0; i < h->size; ++i)
    {
        Node* p = h->table[i];
        printf("%02d ", i);
        while (p != NULL)
        {
            printf("-> %d :(%s) ", p->data.no, p->data.name);
            p = p->next;
        }
        putchar('\n');
    }
}

void Clear(ChainHash* h)
{
    int i;
    for (i = 0; i < h->size; ++i)
    {
        Node* p = h->table[i];
        while (p != NULL)
        {
            Node* next = p->next;
            free(p);
            p = next;
        }
        h->table[i] = NULL;
    }
}

void Terminate(ChainHash* h)
{
    Clear(h);
    free(h->table);
    h->size = 0;
}
