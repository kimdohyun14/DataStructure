// 참고 : https://greatzzo.tistory.com/8?category=662568
#include <stdio.h>
#include <string.h>
// Boyer-Moore 알고리즘의 
// Bad Character Heuristic의 예시

/*
1. 패턴의 현재 비교 문자와 일치하지 않는 텍스트의 문자를 bad character라고 부른다.
   이런 bad character가 등장하면 패턴에서 이 bad character가 마지막으로 등장했던 위치로 패턴을 이동시킨다.

2. 전처리 과정에서 256의 배열을 만들고 패턴에 등장한 모든 문자의 마지막 위치를 저장한다.

3. 만약 전혀 나타나지 않는 어떤 문자를 만난다면 패턴은 패턴의 길이인 m만큼 이동할 수 있다.
   따라서 BM방식의 best case는 O(N/M)이다.
   패턴의 길이만큼 JUMP하므로

4. 하지만 BM의 worst case는 O(NM), 예를 들어서
   txt[] = "AAAAAAAAAAAAAAA"
   pat[] = "AAAAA"라고 하면,
   Bad character가 등장하지 않으니 매번 일일이 다 검사한다.
*/

#define NUM_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

// The preprocessing function for Boyer Moore's bad Character heuristic
int* createBC(char* pat, int M)
{
	int* bc = new int[NUM_OF_CHARS];

	// Initialize all occurrences as -1
	// 처음에는 -1로 초기화
	for (int i = 0; i < NUM_OF_CHARS; ++i)
		bc[i] = -1;

	// Fill the actual value of last occurrence of a character
	// 마지막으로 등장한 문자의 실제 값으로 채운다.
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
	int s = 0; // 패턴의 첫 인덱스 위치
	int j = 0; // 패턴의 현재 비교 위치

	// 0 1 2 3 4 5 6 7 8
	// A B A B B B A C A B A A B  [txt]
	// A B A A B                  [pat]
	//                 A B A A B  [pat]
	// s는 N - M = 8까지만 확인해보면 된다.
	// 이 이상 넘어가면 해당 패턴이 txt에 없다는 뜻
	while (s <= (N - M))
	{
		j = M - 1;

		// txt에 해당 pat을 뒤에서 부터 하나씩 비교해가면서 j를 감소시킨다.
		// 일치한다면 계속해서 j가 감소하지만, 일치하지 않는다면 j를 감소하지 않고
		// 빠져나오게 된다.
		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		// 모든 패턴이 txt와 일치했더라면 j는 0보다 작으므로
		if (j < 0)
		{
			// 해당 패턴이 일치하는 첫 번째 인덱스를 출력
			printf("Pattern found at index %d \n", s);

			// Shift the pattern so that the next character in text
			// aligns with the last occurence of it in pattern.
			// 해당 패턴이 일치한 것만 출력하는 것이 아닌, 또 있을 수 있으므로
			// 계속해서 조사해보기 위해 s의 값을 변경해준다.
			// 여기서는 s + M이 txt의 길이를 넘지 않는다면, s + M의 문자를 확인해서
			// 얼만큼 패턴을 넘길지 조사한다음 s의 값을 수정한다.
			s += (s + M < N) ? M - bc[txt[s + M]] : 1;
		}
		else
		{
			// 일치하지 않는 문자가 있을 때,
			// 이 때 bad character인 bc 배열 값을 보고 패턴을 그 만큼 이동시킨다.
			// 예를 들어 j = 3에서 문자가 일치하지 않는다면,
			// bc[txt[s + j]] = 1이므로,
			// j - 1 = 3 - 1 = 2
			// 따라서 해당 패턴을 2칸 이동시켜서 다시 비교한다.
			// 경우에 따라서 음수가 나올 수 있으므로, 이럴 때는 1칸 이동시켜 다시 비교시킨다.
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