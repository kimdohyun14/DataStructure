#pragma once

#include "Person.h"

typedef int Key;   // 주민등록번호(ssn)
typedef Person* Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot {
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;
