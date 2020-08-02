#include "LinkedList.h"
#include "Member.h"
#include <stdio.h>
#include <stdlib.h>

// 노드를 동적으로 생성
static Node* AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

// n이 가리키는 노드의 각 멤버에 값을 설정
static void SetNode(Node* n, const Member* x, const Node* next)
{
    n->data = *x;
    n->next = next;
}

void Initialize(List* list)
{
    list->head = NULL;
    list->crnt = NULL;
}

Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y))
{
    Node* ptr = list->head;
    while (ptr != NULL)
    {
        if (compare(&ptr->data, x) == 0)
        {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next; // 다음 노드를 선택
    }

    return NULL; // 검색 실패
}

void InsertFront(List* list, const Member* x)
{
    Node* ptr = list->head;
    list->head = list->crnt = AllocNode();
    SetNode(list->head, x, ptr);
}

void InsertRear(List* list, const Member* x)
{
    if (list->head == NULL)
        InsertFront(list, x);
    else
    {
        Node* ptr = list->head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}

void RemoveFront(List* list)
{
    if (list->head != NULL)
    {
        Node* ptr = list->head->next;
        free(list->head);
        list->head = list->crnt = ptr;
    }
}

void RemoveRear(List* list)
{
    if (list->head != NULL)
    {
        if ((list->head)->next == NULL)
            RemoveFront(list);
        else
        {
            Node* ptr = list->head;
            Node* pre = NULL;
            while (ptr->next != NULL)
            {
                pre = ptr;
                ptr = ptr->next;
            }

            pre->next = NULL;
            free(ptr);
            list->crnt = pre;
        }
    }
}

void RemoveCurrent(List* list)
{
    if (list->head != NULL)
    {
        if (list->crnt == list->head)
            RemoveFront(list);
        else
        {
            Node* ptr = list->head;
            while (ptr->next != list->crnt)
                ptr = ptr->next;
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        }
    }
}

void Clear(List* list)
{
    while (list->head != NULL)
        RemoveFront(list);
    list->crnt = NULL;
}

void PrintCurrent(const List* list)
{
    if (list->head == NULL)
        puts("선택한 노드가 없다.");
    else
        PrintMember(&list->crnt->data);
}

void PrintLnCurrent(const List* list)
{
    PrintCurrent(list);
    putchar('\n');
}

void Print(const List* list)
{
    if (list->head == NULL)
        puts("노드가 없다.");
    else
    {
        Node* ptr = list->head;
        puts("모두 보기");
        while (ptr != NULL)
        {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

void Terminate(List* list)
{
    Clear(list);
}
