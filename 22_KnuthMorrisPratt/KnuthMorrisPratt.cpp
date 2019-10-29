//#include "KnuthMorrisPratt.h"
//#include <stdlib.h>
//
//void Preprocess(char * Pattern, int PatternSize, int * Border)
//{
//	int i = 0;
//	int j = -1;
//
//	Border[0] = -1;
//
//	while (i < PatternSize)
//	{
//		while (j > -1 && Pattern[i] != Pattern[j])
//			j = Border[j];
//
//		i++;
//		j++;
//
//		Border[i] = j;
//	}
//
//}
//
//int KnuthMorrisPratt(char * Text, int TextSize, int Start, char * Pattern, int PatternSize)
//{
//	int i = Start;
//	int j = 0;
//	int Position = -1;
//
//	int * Border = (int*)calloc(PatternSize + 1, sizeof(int));
//
//	Preprocess(Pattern, PatternSize, Border);
//
//	while (i < TextSize)
//	{
//		while (j >= 0 && Text[i] != Pattern[j])
//			j = Border[j];
//
//		i++;
//		j++;
//
//		if (j == PatternSize)
//		{
//			Position = i - j;
//			break;
//		}
//	}
//
//	free(Border);
//	return Position;
//}

#include "KnuthMorrisPratt.h"
#include <stdlib.h>

// Pattern = "BAABABAA"
// PatternSize = 8;
void Preprocess(char* Pattern, int PatternSize, int* Border)
{
	int i = 0;
	int j = -1;

	Border[0] = -1;

	// PatternSize = 8
	while (i < PatternSize)
	{
		// 초기 j = -1 while 루프로 들어가지 않음.
		// 두번째 루프 j == 0 && Pattern[1] /A != Pattern[0] /B
		// 세번째 루프 j == 0 && Pattern[2] /A != Pattern[0] /B
		// 네번째 루프 j == 0 && Pattern[3] / B == Pattern[0] / B
		// 5번째 루프 j == 1 && Pattern[4]/ A == Pattern[1] /A
		// 6번째 루프 j == 2 && Pattern[5] /B != Pattern[2] /A
		// 7번째 루프 j == 0 && Pattern[5] / B == Pattern[0] /B
		// 8번째 루프 j== 2 && Pattern[7] / A == Pattern[2] / A
		while (j > -1 && Pattern[i] != Pattern[j]) {

			// 두번째 루프 j = Border[0] / -1, j = -1;
			// 세번째 루프 j = Border[0] / -1 , j = -1;
			// 6번째 루프 j = Border[2] / 0, j = 0;

			// -내부 루프 j == 0 && Pattern[5] /B == Pattern[0] / B

			j = Border[j];
		}


		//1. i == 1;
		//2.  i == 2;
		//3. i == 3;
		//4. i == 4;
		//5. i == 5;
		//6. i == 6;
		//7. i == 7;
		//8. i == 8;
		i++;

		//1. j == 0;
		//2. j == 0;
		//3. j == 0;
		//4. j == 1;
		//5. j == 2;
		//6. j == 1;
		//7. j == 2;
		// j == 3;
		j++;

		//1. Border[0] = -1;
		//2. Border[1] = 0;
		//3. Border[2] = 0;
		//4. Border[3] = 0;
		//5.  Border[4] = 1;
		//6.  Border[5] = 2;
		//7. Border[6] = 1;
		//8, Border[7] = 2;
		// Border[8] = 3;
		Border[i] = j;
	}
}

// Text: "HolBAABABAAEy BABible, Authorized (King James) Version, Textfile 930105."
// Pattern = "BAABABAA"
int  KnuthMorrisPratt(char* Text, int TextSize, int Start,
	char* Pattern, int PatternSize)
{
	int i = Start;
	int j = 0;
	int Position = -1;

	int* Border = (int*)calloc(PatternSize + 1, sizeof(int));

	Preprocess(Pattern, PatternSize, Border);

	//1. Border[0] = -1;
//2. Border[1] = 0;
//3. Border[2] = 0;
//4. Border[3] = 0;
//5.  Border[4] = 1;
//6.  Border[5] = 2;
//7. Border[6] = 1;
//8, Border[7] = 2;
// Border[8] = 3;

	//        0123456789
	// Text: "HolBAABABAEy BABible, Authorized (King James) Version, Textfile 930105."
	// Pattern = "BAABABAA"
	// i는 TextSize 만큼
	while (i < TextSize)
	{
		// j >= 0 && Text[i] != Pattern[j]
		// j == 0 && Text[0] / H != Pattern[0] / B
		// j == 0 && Text[1] / o != Pattern[0] / B
		// j == 0 && Text[2] / l != Pattern[0] / B
		// j == 0 && Text[3] / B = Pattern[0] / B
		// j == 1 && Text[4] / A = Pattern[1] / A
		// j == 2 && Text[5] / A = Pattern[2] / A
		// j == 3 && Text[6] / B = Pattern[3] / B
		// j == 4 && Text[7] / A = Pattern[4] / A
		// j == 5 && Text[8] / B = Pattern[5] / B
		// j == 6 && Text[9] / A = Pattern[6] / A
		// j == 7 && Text[10] / E != Pattern[7] / A
		// j == 2 && Text[10] / E != Pattern[2] / A
		// j == 0 && Text[10] / E != Pattern[0] / B
		// j == 0 && Text[11] / y != Pattern[0] / B
		while (j >= 0 && Text[i] != Pattern[j]) {

			// j = Border[0], j = -1;
			// j = Border[0], j = -1;
			// j = Border[0], j = -1;
			// j = Border[7], j = 2;
			// j = Border[2], j = 0;
			// j = Border[0], j = -1;
			j = Border[j];
		}


		// i == 1;
		// i == 2;
		// i == 3;
		// i == 4;
		// i == 5;
		// i == 6;
		// i == 7;
		// i == 8;
		// i == 9;
		// i == 10;
		// i == 11;
		i++;

		// j == 0;
		// j == 0;
		// j == 0;
		// j == 1;
		// j == 2;
		// j == 3;
		// j == 4;
		// j == 5;
		// j == 6;
		// j == 7;
		// j == 0;
		j++;

		if (j == PatternSize)
		{
			Position = i - j;
			break;
		}
	}

	free(Border);
	return Position;
}