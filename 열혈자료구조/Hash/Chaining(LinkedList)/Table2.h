#pragma once

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL  100

typedef int HashFunc(Key k);

typedef struct _table {
	List tbl[MAX_TBL];
	HashFunc* hf;
}Table;

void TBLInit(Table* bt, HashFunc* f);
void TBLInsert(Table* bt, Key k, Value v);
Value TBLDelete(Table* bt, Key k);
Value TBLSearch(Table* bt, Key k);