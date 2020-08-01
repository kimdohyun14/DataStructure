/* 브루트-포스법으로 문자열 검색 */
#include <stdio.h>

//int bf_match(const char txt[], const char pat[])
int bf_match(const char* txt, const char* pat)
{
	int pt = 0; // text 인덱스
	int pp = 0; // pattern 인덱스
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			pt++;
			pp++;
		}
		// 중간에 일치하지 않는 부분이 나오면
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
		puts("text에 pattern이 없다.");
	else
		printf("%d번째 문자부터 match하다.\n", idx + 1);

	return 0;
}