// ���� : https://greatzzo.tistory.com/8?category=662568
#include <stdio.h>
#include <string.h>
// Boyer-Moore �˰����� 
// Bad Character Heuristic�� ����

/*
1. ������ ���� �� ���ڿ� ��ġ���� �ʴ� �ؽ�Ʈ�� ���ڸ� bad character��� �θ���.
   �̷� bad character�� �����ϸ� ���Ͽ��� �� bad character�� ���������� �����ߴ� ��ġ�� ������ �̵���Ų��.

2. ��ó�� �������� 256�� �迭�� ����� ���Ͽ� ������ ��� ������ ������ ��ġ�� �����Ѵ�.

3. ���� ���� ��Ÿ���� �ʴ� � ���ڸ� �����ٸ� ������ ������ ������ m��ŭ �̵��� �� �ִ�.
   ���� BM����� best case�� O(N/M)�̴�.
   ������ ���̸�ŭ JUMP�ϹǷ�

4. ������ BM�� worst case�� O(NM), ���� ��
   txt[] = "AAAAAAAAAAAAAAA"
   pat[] = "AAAAA"��� �ϸ�,
   Bad character�� �������� ������ �Ź� ������ �� �˻��Ѵ�.
*/

#define NUM_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

// The preprocessing function for Boyer Moore's bad Character heuristic
int* createBC(char* pat, int M)
{
	int* bc = new int[NUM_OF_CHARS];

	// Initialize all occurrences as -1
	// ó������ -1�� �ʱ�ȭ
	for (int i = 0; i < NUM_OF_CHARS; ++i)
		bc[i] = -1;

	// Fill the actual value of last occurrence of a character
	// ���������� ������ ������ ���� ������ ä���.
	for (int i = 0; i < M - 1; ++i)
		bc[(int)pat[i]] = i;

	for (int i = 65; i < 66; ++i)
		printf("%d\n", bc[i]);

	return bc;
}

void searchBM(char* pat, char* txt)
{
	int N = strlen(txt);
	int M = strlen(pat);
	int* bc = createBC(pat, M);
	int s = 0; // ������ ù �ε��� ��ġ
	int j = 0; // ������ ���� �� ��ġ

	// 0 1 2 3 4 5 6 7 8
	// A B A B B B A C A B A A B  [txt]
	// A B A A B                  [pat]
	//                 A B A A B  [pat]
	// s�� N - M = 8������ Ȯ���غ��� �ȴ�.
	// �� �̻� �Ѿ�� �ش� ������ txt�� ���ٴ� ��
	while (s <= (N - M))
	{
		j = M - 1;

		// txt�� �ش� pat�� �ڿ��� ���� �ϳ��� ���ذ��鼭 j�� ���ҽ�Ų��.
		// ��ġ�Ѵٸ� ����ؼ� j�� ����������, ��ġ���� �ʴ´ٸ� j�� �������� �ʰ�
		// ���������� �ȴ�.
		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		// ��� ������ txt�� ��ġ�ߴ���� j�� 0���� �����Ƿ�
		if (j < 0)
		{
			// �ش� ������ ��ġ�ϴ� ù ��° �ε����� ���
			printf("Pattern found at index %d \n", s);

			// Shift the pattern so that the next character in text
			// aligns with the last occurence of it in pattern.
			// �ش� ������ ��ġ�� �͸� ����ϴ� ���� �ƴ�, �� ���� �� �����Ƿ�
			// ����ؼ� �����غ��� ���� s�� ���� �������ش�.
			// ���⼭�� s + M�� txt�� ���̸� ���� �ʴ´ٸ�, s + M�� ���ڸ� Ȯ���ؼ�
			// ��ŭ ������ �ѱ��� �����Ѵ��� s�� ���� �����Ѵ�.
			s += (s + M < N) ? M - bc[txt[s + M]] : 1;
		}
		else
		{
			// ��ġ���� �ʴ� ���ڰ� ���� ��,
			// �� �� bad character�� bc �迭 ���� ���� ������ �� ��ŭ �̵���Ų��.
			// ���� ��� j = 3���� ���ڰ� ��ġ���� �ʴ´ٸ�,
			// bc[txt[s + j]] = 1�̹Ƿ�,
			// j - 1 = 3 - 1 = 2
			// ���� �ش� ������ 2ĭ �̵����Ѽ� �ٽ� ���Ѵ�.
			// ��쿡 ���� ������ ���� �� �����Ƿ�, �̷� ���� 1ĭ �̵����� �ٽ� �񱳽�Ų��.
			s += max(1, j - bc[txt[s + j]]);
		}
	}

	delete bc;
}

int main()
{
	//            0123456789
	//char txt[] = "ABABBBACABAAB";
	//char pat[] = "ABAAB";
	//            0123456789
	char txt[] = "AAAAAAAAAA";
	char pat[] = "AAAAA";

	searchBM(pat, txt);

	return 0;
}