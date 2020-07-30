/* 힙 정렬 */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

// 1. downheap 사용해서 배열 a를 heap으로 만들어준다.
// 2. 루트에 있는 가장 큰 값을 빼내어 배열 마지막 요소와 바꾸고,
//    배열의 나머지 부분을 다시 힙으로 만들어주는 과정을 반복하여 정렬을 수행한다.

// a, 4, 9
static void downheap(int a[], int left, int right)
{
	int temp = a[left]; // 루트(여기의 값이 그 자리에 있을지, 아니면 자리를 변경해야 하는지 저장하는 값)
	int child;
	int parent;
	// 부모가 될 수 있는 조건은 parent < (right + 1) / 2까지만이다. (자식이 있어야 가능)
	for (parent = left; parent < (right + 1) / 2; parent = child)
	{
		int cl = parent * 2 + 1; // 왼쪽 자식
		int cr = cl + 1;         // 오른쪽 자식
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;  // 왼쪽 vs 오른쪽
		if (temp >= a[child])    // 가장 큰 값과 루트를 비교해서, 루트가 크면 종료
			break;
		a[parent] = a[child];    // 아니라면, 부모에 자식을 넣어주고, 이어간다.
	}
	a[parent] = temp;
}

void heapsort(int a[], int n)
{
	int i;
	// 주어진 배열 a를 heap으로 구성해준다.
	// 아랫부분의 작은 부분트리부터 시작해 올라가는 방식이다.
	for (i = (n - 1) / 2; i >= 0; --i)
		downheap(a, i, n - 1);

	for (i = n - 1; i > 0; --i)
	{
		// 루트를 가장 맨 뒤의 값과 swap해서 정렬해준다.
		swap(int, a[0], a[i]);
		// 루트를 없애고 힙 상태를 유지하기 위해서 downheap을 한다.
		downheap(a, 0, i - 1);
	}
}

int main()
{
	int i, nx;
	int* x;
	puts("힙 정렬");
	printf("요소 개수 : "); scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	heapsort(x, nx);
	puts("오름차순으로 정렬");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);
	return 0;
}