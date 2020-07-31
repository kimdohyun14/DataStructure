#ifndef ___BitSet
#define ___BitSet

typedef unsigned long BitSet;

#define BitSetNull (BitSet)0
#define BitSetBits 32
#define SetOf(no) ((BitSet)1 << (no))

int IsMember(BitSet s, int n);

void Add(BitSet* s, int n);

void Remove(BitSet* s, int n);

int Size(BitSet s);

void Print(BitSet s);

void PrintLn(BitSet s);
#endif