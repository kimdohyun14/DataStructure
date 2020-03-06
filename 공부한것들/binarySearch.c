#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;

int search(int start, int end, int target)
{
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (a[mid] == target) return mid;
	else if (a[mid] > target) return search(start, mid - 1, target);
	else return search(mid + 1, end, target);
}

int main()
{
	int n, target;
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int res = search(0, n - 1, target);
	if (res != -1)
		printf("%d번째 원소입니다.\n", res + 1);
	else
		printf("원소를 찾을 수 없습니다.\n");
	return 0;
}