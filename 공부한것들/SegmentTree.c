#include <stdio.h>
#define NUMBER 7

int a[] = { 7,1,9,5,6,4,1 };
int tree[4 * NUMBER]; // 4를 곱하면 모든 범위가 커버 가능하다.

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = a[start]; // 리프 노드인 경우 배열의 값이 그대로 들어간다.
	int mid = (start + end) / 2;
	// 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 한다. (왼쪽 자식 합 + 오른쪽 자식 합)
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start : 시작, end : 끝
// left, right : 구간의 합을 구하고자 하는 범위
// node : 노드 인덱스
int sum(int start, int end, int node, int left, int right)
{
	// 범위 밖에 있는 경우
	if (left > end || right < start) return 0;
	// 범위 안에 있는 경우
	if (left <= start && end <= right) return tree[node];
	// 그렇지 않다면 두 부분으로 나누어 합 구하기
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start : 시작, end : 끝
// index : 구간 합을 수정하고자 하는 노드
// dif : 수정할 값
void update(int start, int end, int node, int index, int dif)
{
	// 범위 밖에 있는 경우
	if (index < start || index > end) return;
	// 범위 안에 있으면 내려가며 다른 원소도 갱신
	tree[node] += dif;
	// 리프 노드이면
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main()
{
	// 구간 합 트리 생성하기
	init(0, NUMBER - 1, 1);
	// 구간 합 구하기
	printf("0부터 6까지의 구간 합: %d\n", sum(0, NUMBER - 1, 1, 0, 6));
	// 구간 합 갱신하기
	printf("인덱스 5의 원소를 +3만큼 수정\n");
	update(0, NUMBER - 1, 1, 5, 3);
	// 구간 합 다시 구하기
	printf("3부터 6까지의 구간 합: %d\n", sum(0, NUMBER - 1, 1, 3, 6));
	printf("0부터 6까지의 구간 합: %d\n", sum(0, NUMBER - 1, 1, 0, 6));
	return 0;
}