#include <stdio.h>

int a[1001][1001];
int n, m; //노드, 간선의 개수

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}