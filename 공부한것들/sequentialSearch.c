#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100

char** array; // 2차원 배열
int founded;

int main()
{
	int n;
	char* word;
	word = (char*)malloc(sizeof(char)*LENGTH);
	scanf("%d %s", &n, word);
	array = (char**)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; i++)
	{
		array[i] = malloc(sizeof(char)*LENGTH);
		scanf("%s", array[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (!strcmp(array[i], word))
		{
			printf("%d번째 원소입니다.\n", i + 1);
			founded = 1;
		}
	}

	if (!founded)
		printf("원소를 찾을 수 없습니다.\n");

	return 0;
}