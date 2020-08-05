#include "CircDblLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

// 1개의 노드를 동적으로 생성
static Dnode* AllocDnode()
{
    return calloc(1, sizeof(Dnode));
}

static void SetNode(Dnode* n, const Member* x, const Dnode* prev, const Dnode* next)
{
    n->data = *x;
    n->prev = prev;
    n->next = next;
}

static int IsEmpty(const Dlist* list)
{
    return list->head->next == list->head;
}

void Initialize(Dlist* list)
{
    Dnode* dummyNode = AllocDnode(); // 더미 노드 생성
    list->head = list->crnt = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode;
}

void PrintCurrent(const Dlist* list)
{
    if (IsEmpty(list))
        printf("선택한 노드가 없다.");
    else
        PrintMember(&list->crnt->data);
}

void PrintLnCurrent(const Dlist* list)
{
    PrintCurrent(list);
    putchar('\n');
}

Dnode* Search(Dlist* list, const Member* x, int compare(const Member* x, const Member* y))
{
    Dnode* ptr = list->head->next;
    while (ptr != list->head)
    {
        if (compare(&ptr->data, x) == 0)
        {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL;
}

void Print(const Dlist* list)
{
    if (IsEmpty(list))
        puts("노드가 없다.");
    else
    {
        Dnode* ptr = list->head->next;
        puts("모두 보기");
        while (ptr != list->head)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

void PrintReverse(const Dlist* list)
{
    if (IsEmpty(list))
        puts("노드가 없다.");
    else
    {
        Dnode* ptr = list->head->prev;
        puts("모두 보기");
        while (ptr != list->head)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->prev;
        }
    }
}

// 선택한 노드를 다음으로 진행
int Next(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->next == list->head)
        return 0;

    list->crnt = list->crnt->next;
    return 1;
}

int Prev(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0;

    list->crnt = list->crnt->prev;
    return 1;
}

void InsertAfter(Dlist* list, Dnode* p, const Member* x)
{
    Dnode* ptr = AllocDnode();
    Dnode* nxt = p->next;
    p->next = p->next->prev = ptr;
    SetNode(ptr, x, p, nxt);
    list->crnt = ptr;
}

void InsertFront(Dlist* list, const Member* x)
{
    InsertAfter(list, list->head, x);
}

void InsertRear(Dlist* list, const Member* x)
{
    InsertAfter(list, list->head->prev, x);
}

// p가 가리키는 노드를 삭제
void Remove(Dlist* list, Dnode* p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    list->crnt = p->prev;
    free(p);
    if (list->crnt == list->head)
        list->crnt = list->head->next;
}

void RemoveFront(Dlist* list)
{
    // 더미 노드를 삭제하면 안 되기 때문에
    if(!IsEmpty(list))
        Remove(list, list->head->next);
}

void RemoveRear(Dlist* list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

void RemoveCurrent(Dlist* list)
{
    // 더미 노드를 삭제하면 안 되기 때문에
    if (list->crnt != list->head)
        Remove(list, list->crnt);
}

void Clear(Dlist* list)
{
    while (!IsEmpty(list))
        RemoveFront(list);
}

void Terminate(Dlist* list)
{
    Clear(list);      // 모든 노드 삭제
    free(list->head); // 더미 노드 삭제
}
