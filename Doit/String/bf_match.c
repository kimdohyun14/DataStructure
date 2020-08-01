/* ���Ʈ-���������� ���ڿ� �˻� */
#include <stdio.h>

//int bf_match(const char txt[], const char pat[])
int bf_match(const char* txt, const char* pat)
{
	int pt = 0; // text �ε���
	int pp = 0; // pattern �ε���
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			pt++;
			pp++;
		}
		// �߰��� ��ġ���� �ʴ� �κ��� ������
		else
		{
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	if (pat[pp] == '\0')
		return pt - pp;
	return -1;
}

int main()
{
	int idx;
	char s1[256]; // text
	char s2[256]; // pattern
	puts("bruteforce");
	printf("text : "); scanf_s("%s", s1, 256);
	printf("pattern : "); scanf_s("%s", s2, 256);
	idx = bf_match(s1, s2);
	if (idx == -1)
		puts("text�� pattern�� ����.");
	else
		printf("%d��° ���ں��� match�ϴ�.\n", idx + 1);

	return 0;
}