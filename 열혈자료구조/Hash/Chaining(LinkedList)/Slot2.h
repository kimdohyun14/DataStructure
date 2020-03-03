#pragma once

#include "Person.h"

typedef int Key;
typedef Person* Value;

typedef struct _slot {
	Key key;
	Value val;
}Slot;